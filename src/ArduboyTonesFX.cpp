/**
 * @file ArduboyTonesFX.cpp
 * \brief An Arduino library for playing tones and tone sequences,
 * intended for the Arduboy game system.
 */

/*****************************************************************************
  ArduboyTones

An Arduino library to play tones and tone sequences.

Specifically written for use by the Arduboy miniature game system
https://www.arduboy.com/
but could work with other Arduino AVR boards that have 16 bit timer 3
available, by changing the port and bit definintions for the pin(s)
if necessary.

Copyright (c) 2017 Scott Allen

Modified 2022 Simon Holmes

optimized for FX only 2023 Mr.Blinky

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*****************************************************************************/

#include "ArduboyTonesFX.h"

// pointer to a function that indicates if sound is enabled
static bool (*outputEnabled)();

struct TonesFX {
 long durationToggleCount;
 bool toneSilent;
#ifdef TONES_VOLUME_CONTROL
 bool toneHighVol;
 bool forceHighVol;
 bool forceNormVol;
#endif
};

static volatile TonesFX tonesFX;

struct TonesBufferFX {
  uint24_t Start;
  uint24_t Curr;
  uint16_t *FX;
  uint8_t Len;
  uint8_t Head;
  uint8_t Tail;
};

static TonesBufferFX tonesBufferFX;

ArduboyTonesFX::ArduboyTonesFX(boolean (*outEn)())
{
  outputEnabled = outEn;
  bitClear(TONE_PIN_PORT, TONE_PIN); // set the pin low
  bitSet(TONE_PIN_DDR, TONE_PIN); // set the pin to output mode
#ifdef TONES_2_SPEAKER_PINS
  bitClear(TONE_PIN2_PORT, TONE_PIN2); // set pin 2 low
  bitSet(TONE_PIN2_DDR, TONE_PIN2); // set pin 2 to output mode
#endif
}

ArduboyTonesFX::ArduboyTonesFX(boolean (*outEn)(), uint16_t *tonesArray, uint8_t tonesArrayLen)
{
  outputEnabled = outEn;
  tonesBufferFX.FX = tonesArray;
  tonesBufferFX.Len = tonesArrayLen;
  bitClear(TONE_PIN_PORT, TONE_PIN); // set the pin low
  bitSet(TONE_PIN_DDR, TONE_PIN); // set the pin to output mode
#ifdef TONES_2_SPEAKER_PINS
  bitClear(TONE_PIN2_PORT, TONE_PIN2); // set pin 2 low
  bitSet(TONE_PIN2_DDR, TONE_PIN2); // set pin 2 to output mode
#endif
}

void ArduboyTonesFX::tonesFromFX(uint24_t tones)
{
  tonesBufferFX.Start = tonesBufferFX.Curr = tones; // set to start of sequence array
  tonesBufferFX.Head = 0;
  tonesBufferFX.Tail = 255; // odd value to signal fill buffer
  fillBufferFromFX();

  bitWrite(TIMSK3, OCIE3A, 0); // disable the output compare match interrupt
  nextTone(); // start playing
}

void ArduboyTonesFX::fillBufferFromFX()
{
   #ifdef ARDUINO_ARCH_AVR
    asm volatile(
      " ldd  r18, Z+%[head]     \n"
      " ldd  r19, Z+%[tail]     \n"
      " cp   r18, r19           \n"
      " breq 5f                 \n" // head == tail
      "1:                       \n"
      " ldd  r22, Z+%[curr]+0   \n"
      " ldd  r23, Z+%[curr]+1   \n"
      " ldd  r24, Z+%[curr]+2   \n"
      " call %x0                \n" // seekData(Curr)
      "2:                       \n"
      " cp   r18, r19           \n"
      " breq 4f                 \n" // head == tail
      " call %x1                \n" // t = FX::readPendingUInt16()
      " cpi  r24, lo8(%[repeat])\n"
      " ldi  r22, hi8(%[repeat])\n"
      " cpc  r25, r22           \n"
      " brne 3f                 \n" // t != TONES_REPEAT
      "                         \n"
      " ldd  r24, Z+%[start]+0  \n" // Curr = Start
      " ldd  r25, Z+%[start]+1  \n"
      " ldd  r26, Z+%[start]+2  \n"
      " std  Z+%[curr]+0, r24   \n"
      " std  Z+%[curr]+1, r25   \n"
      " std  Z+%[curr]+2, r26   \n"
      " rcall 4f                \n" // readEnd
      " rjmp  1b                \n" // seekData(Curr)
      "3:                       \n"
      " ldd  r26, Z+%[buffer]   \n" // tonesBufferFX.FX[head] = t;
      " ldd  r27, Z+%[buffer]+1 \n"
      " add  r26, r18           \n"
      " adc  r27, r1            \n"
      " add  r26, r18           \n"
      " adc  r27, r1            \n"
      " st   X+, r24            \n"
      " st   X, r25             \n"
      " inc  r18                \n" // if (++head == len) head = 0;
      " ldd  r22, Z+%[len]      \n"
      " cp   r18, r22           \n"
      " brne .+2                \n"
      " ldi  r18, 0             \n"
      " std  Z+%[head], r18     \n" // Head = head
      " ldd  r24, Z+%[curr]+0   \n" // Curr += 2
      " ldd  r25, Z+%[curr]+1   \n"
      " ldd  r26, Z+%[curr]+2   \n"
      " adiw r24, 2             \n"
      " adc  r26, r1            \n"
      " std  Z+%[curr]+0, r24   \n"
      " std  Z+%[curr]+1, r25   \n"
      " std  Z+%[curr]+2, r26   \n"
      " cpi  r19, 0xFF          \n" // if(Tail == 255) Tail = 0;
      " brne 2b                 \n"
      "                         \n"
      " ldi  r19, 0             \n"
      " std  Z+%[tail], r19     \n"
      " rjmp 2b                 \n"
      "4:                       \n"
      " jmp  %x2                \n" //readEnd
      "5:                       \n"
      :
      :         ""  (FX::seekData),
                ""  (FX::readPendingUInt16),
                ""  (FX::readEnd),
                "z" (&tonesBufferFX),
       [repeat] ""  (TONES_REPEAT),
       [start]  "i" (offsetof(TonesBufferFX, Start)),
       [curr]   "i" (offsetof(TonesBufferFX, Curr)),
       [buffer] "i" (offsetof(TonesBufferFX, FX)),
       [len]    "i" (offsetof(TonesBufferFX, Len)),
       [head]   "i" (offsetof(TonesBufferFX, Head)),
       [tail]   "i" (offsetof(TonesBufferFX, Tail))
      : "r18", "r19", "r20", "r21", "r22", "r23", "r24", "r25", "r26", "r27"
    );
   #else
    uint8_t head = tonesBufferFX.Head;
    if (head == tonesBufferFX.Tail) return;

    FX::seekData(tonesBufferFX.Curr);
    while (head != tonesBufferFX.Tail) {
      uint16_t t = FX::readPendingUInt16();
      if (t == TONES_REPEAT) {
        tonesBufferFX.Curr = tonesBufferFX.Start;
        FX::readEnd();
        FX::seekData(tonesBufferFX.Curr);
      }
      else {
        tonesBufferFX.FX[head] = t;
        if (++head == tonesBufferFX.Len) head = 0;
        tonesBufferFX.Head = head;
        tonesBufferFX.Curr += 2;
        if (tonesBufferFX.Tail == 255) tonesBufferFX.Tail = 0;
      }
    }
    FX::readEnd();
   #endif
}

void ArduboyTonesFX::noTone()
{
  bitWrite(TIMSK3, OCIE3A, 0); // disable the output compare match interrupt
  TCCR3B = 0; // stop the counter
  bitClear(TONE_PIN_PORT, TONE_PIN); // set the pin low
#ifdef TONES_VOLUME_CONTROL
  bitClear(TONE_PIN2_PORT, TONE_PIN2); // set pin 2 low
#endif
}

void ArduboyTonesFX::volumeMode(uint8_t mode)
{
#ifdef TONES_VOLUME_CONTROL
  tonesFX.forceNormVol = false; // assume volume is tone controlled
  tonesFX.forceHighVol = false;

  if (mode == VOLUME_ALWAYS_NORMAL) {
    tonesFX.forceNormVol = true;
  }
  else if (mode == VOLUME_ALWAYS_HIGH) {
    tonesFX.forceHighVol = true;
  }
#endif
}

bool ArduboyTonesFX::playing()
{
  return TCCR3B;
}

void ArduboyTonesFX::nextTone()
{
  uint16_t freq;
  uint16_t dur;
  long toggleCount;
  uint16_t ocrValue;
#ifdef TONES_ADJUST_PRESCALER
  uint8_t tccrxbValue;
#endif

  freq = getNext(); // get tone frequency

  if (freq == TONES_END) { // if freq is actually an "end of sequence" marker
    noTone(); // stop playing
    return;
  }

#ifdef TONES_VOLUME_CONTROL
  if (((freq & TONE_HIGH_VOLUME) || tonesFX.forceHighVol) && !tonesFX.forceNormVol) {
    tonesFX.toneHighVol = true;
  }
  else {
    tonesFX.toneHighVol = false;
  }
#endif

  freq &= ~TONE_HIGH_VOLUME; // strip volume indicator from frequency

#ifdef TONES_ADJUST_PRESCALER
  if (freq >= MIN_NO_PRESCALE_FREQ) {
    tccrxbValue = _BV(WGM32) | _BV(CS30); // CTC mode, no prescaling
    ocrValue = F_CPU / freq / 2 - 1;
    tonesFX.toneSilent = false;
  }
  else {
    tccrxbValue = _BV(WGM32) | _BV(CS31); // CTC mode, prescaler /8
#endif
    if (freq == 0) { // if tone is silent
      ocrValue = F_CPU / 8 / SILENT_FREQ / 2 - 1; // dummy tone for silence
      freq = SILENT_FREQ;
      tonesFX.toneSilent = true;
      bitClear(TONE_PIN_PORT, TONE_PIN); // set the pin low
    }
    else {
      ocrValue = F_CPU / 8 / freq / 2 - 1;
      tonesFX.toneSilent = false;
    }
#ifdef TONES_ADJUST_PRESCALER
  }
#endif

  if (!outputEnabled()) { // if sound has been muted
    tonesFX.toneSilent = true;
  }

#ifdef TONES_VOLUME_CONTROL
  if (tonesFX.toneHighVol && !tonesFX.toneSilent) {
    // set pin 2 to the compliment of pin 1
    if (bitRead(TONE_PIN_PORT, TONE_PIN)) {
      bitClear(TONE_PIN2_PORT, TONE_PIN2);
    }
    else {
      bitSet(TONE_PIN2_PORT, TONE_PIN2);
    }
  }
  else {
    bitClear(TONE_PIN2_PORT, TONE_PIN2); // set pin 2 low for normal volume
  }
#endif

  dur = getNext(); // get tone duration
  if (dur != 0) {
    toggleCount = ((uint32_t)dur * freq) / 500; //dividing by 500 is optimized better
  }
  else {
    toggleCount = -1; // indicate infinite duration
  }

  TCCR3A = 0;
#ifdef TONES_ADJUST_PRESCALER
  TCCR3B = tccrxbValue;
#else
  TCCR3B = _BV(WGM32) | _BV(CS31); // CTC mode, prescaler /8
#endif
  OCR3A = ocrValue;
  tonesFX.durationToggleCount = toggleCount;
  bitWrite(TIMSK3, OCIE3A, 1); // enable the output compare match interrupt
}

uint16_t ArduboyTonesFX::getNext()
{
   #ifdef ARDUINO_ARCH_AVR
     uint16_t t;
     asm volatile(
       "ldd  %[t], Z+%[tail]    \n"
       "mov  r0, %[t]           \n"
       "add  %[t], %[t]         \n"
       "ldd  r26, Z+%[buffer]   \n"
       "add  r26, %[t]          \n"
       "ldd  r27, Z+%[buffer]+1 \n"
       "adc  r27, r1            \n"
       "ld   %A[t], X+          \n"
       "ld   %B[t], X           \n"
       "inc  r0                 \n"
       "ldd  r26, Z+%[len]      \n"
       "cp   r0, r26            \n"
       "brcs .+2                \n"
       "clr  r0                 \n"
       "std  Z+%[tail], r0      \n"
       : [t]     "=&r" (t)
       :          "z" (&tonesBufferFX),
         [tail]   "i" (offsetof(TonesBufferFX, Tail)),
         [buffer] "i" (offsetof(TonesBufferFX, FX)),
         [len]    "i" (offsetof(TonesBufferFX, Len))
       : "r26", "r27" // Also uses "r24", "r25" for t and r30, r31 for tonesBufferFX
     );
     return t;
   #else
    uint8_t tail = tonesBufferFX.Tail;
    uint16_t t = tonesBuffer.FX[tail];
    if (++tail >= tonesBufferFX.Len) tail = 0;
    tonesBufferFX.Tail = tail;
    return t;
   #endif
}

ISR(TIMER3_COMPA_vect)
{
 #ifdef ARDUINO_ARCH_AVR
  asm volatile
  (
    "ldd  r24, z+%[count]+0         \n"
    "ldd  r25, z+%[count]+1         \n"
    "ldd  r26, z+%[count]+2         \n"
    "ldd  r27, z+%[count]+3         \n"
    "sbiw r24, 1                    \n"
    "sbc  r26, r1                   \n"
    "sbc  r27, r1                   \n"
    "brcc 1f                        \n"
    "                               \n"
    "call %x0                       \n"
    "rjmp 2f                        \n"
    "1:                             \n"
    "std  z+%[count]+0, r24         \n"
    "std  z+%[count]+1, r25         \n"
    "std  z+%[count]+2, r26         \n"
    "std  z+%[count]+3, r27         \n"
    "ldd  r24, z+%[silent]          \n"
    "and  r24, r24                  \n"
    "brne 2f                        \n"
    "                               \n"
    "sbi  %[tonepin1], %[tonebit1]  \n"
   #ifdef TONES_VOLUME_CONTROL
    "ldd  r24, z+%[highvol]         \n"
    "cpse r24, r1                   \n"
    "sbi  %[tonepin2], %[tonebit2]  \n"
   #endif
    "2:                             \n"
    :
    :            ""  (ArduboyTonesFX::nextTone),
      [tonepin1] "i" (_SFR_IO_ADDR(TONE_PIN_PIN)),
      [tonebit1] "i" (TONE_PIN),
   #ifdef TONES_VOLUME_CONTROL
      [tonepin2] "i" (_SFR_IO_ADDR(TONE_PIN2_PIN)),
      [tonebit2] "i" (TONE_PIN2),
   #endif
                 "z" (&tonesFX),
      [count]    "i" (offsetof(TonesFX, durationToggleCount)),
      [silent]   "i" (offsetof(TonesFX, toneSilent)),
      [highvol]  "i" (offsetof(TonesFX, toneHighVol))
    : "r18", "r19", "r20", "r21", "r22", "r23", "r24", "r25", "r26", "r27" // and "r30", "r31" for Z
  );
 #else
  long toggleCount = tonesFX.durationToggleCount;
  if (--toggleCount >= 0) {
    if (!tonesFX.toneSilent) {
      bitSet(*(&TONE_PIN_PIN), TONE_PIN); // toggle the pin
#ifdef TONES_VOLUME_CONTROL
      if (tonesFX.toneHighVol) {
        bitSet(*(&TONE_PIN2_PIN), TONE_PIN2); // toggle pin 2
      }
#endif
    }
    tonesFX.durationToggleCount = toggleCount;
  }
  else {
    ArduboyTonesFX::nextTone();
  }
 #endif
}