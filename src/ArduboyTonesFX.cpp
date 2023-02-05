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

static volatile long durationToggleCount = 0;
//static volatile bool tonesPlaying = false;
static volatile bool toneSilent;
#ifdef TONES_VOLUME_CONTROL
static volatile bool toneHighVol;
static volatile bool forceHighVol = false;
static volatile bool forceNormVol = false;
#endif

//static volatile uint16_t *tonesStart;
//static volatile uint16_t *tonesIndex;
//static volatile uint16_t toneSequence[MAX_TONES * 2 + 1];

//static volatile bool inProgmem;

static volatile uint24_t tonesBufferFX_Start;
static volatile uint24_t tonesBufferFX_Curr;
static volatile uint16_t *tonesBufferFX;
static uint8_t tonesBufferFX_Len;
static uint8_t tonesBufferFX_Head;
static uint8_t tonesBufferFX_Tail;
//static volatile uint8_t toneMode;

ArduboyTonesFX::ArduboyTonesFX(boolean (*outEn)())
{
  outputEnabled = outEn;

  //toneSequence[MAX_TONES * 2] = TONES_END;

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
  tonesBufferFX = tonesArray;
  tonesBufferFX_Len = tonesArrayLen;

  //toneSequence[MAX_TONES * 2] = TONES_END;

  bitClear(TONE_PIN_PORT, TONE_PIN); // set the pin low
  bitSet(TONE_PIN_DDR, TONE_PIN); // set the pin to output mode
#ifdef TONES_2_SPEAKER_PINS
  bitClear(TONE_PIN2_PORT, TONE_PIN2); // set pin 2 low
  bitSet(TONE_PIN2_DDR, TONE_PIN2); // set pin 2 to output mode
#endif
}

//void ArduboyTonesFX::tone(uint16_t freq, uint16_t dur)
//{
//  bitWrite(TIMSK3, OCIE3A, 0); // disable the output compare match interrupt
//  inProgmem = false;
//  tonesStart = tonesIndex = toneSequence; // set to start of sequence array
//  toneSequence[0] = freq;
//  toneSequence[1] = dur;
//  toneSequence[2] = TONES_END; // set end marker
//  toneMode = TONES_MODE_NORMAL;
//  nextTone(); // start playing
//}

//void ArduboyTonesFX::tone(uint16_t freq1, uint16_t dur1,
//                        uint16_t freq2, uint16_t dur2)
//{
//  bitWrite(TIMSK3, OCIE3A, 0); // disable the output compare match interrupt
//  inProgmem = false;
//  tonesStart = tonesIndex = toneSequence; // set to start of sequence array
//  toneSequence[0] = freq1;
//  toneSequence[1] = dur1;
//  toneSequence[2] = freq2;
//  toneSequence[3] = dur2;
//  toneSequence[4] = TONES_END; // set end marker
//  toneMode = TONES_MODE_NORMAL;
//  nextTone(); // start playing
//}

//void ArduboyTonesFX::tone(uint16_t freq1, uint16_t dur1,
//                        uint16_t freq2, uint16_t dur2,
//                        uint16_t freq3, uint16_t dur3)
//{
//  bitWrite(TIMSK3, OCIE3A, 0); // disable the output compare match interrupt
//  inProgmem = false;
//  tonesStart = tonesIndex = toneSequence; // set to start of sequence array
//  toneSequence[0] = freq1;
//  toneSequence[1] = dur1;
//  toneSequence[2] = freq2;
//  toneSequence[3] = dur2;
//  toneSequence[4] = freq3;
//  toneSequence[5] = dur3;
//  toneMode = TONES_MODE_NORMAL;
//  nextTone(); // start playing
//}

//void ArduboyTonesFX::tones(const uint16_t *tones)
//{
//  bitWrite(TIMSK3, OCIE3A, 0); // disable the output compare match interrupt
//  inProgmem = true;
//  tonesStart = tonesIndex = (uint16_t *)tones; // set to start of sequence array
//  toneMode = TONES_MODE_NORMAL;
//  nextTone(); // start playing
//}

//void ArduboyTonesFX::tonesInRAM(uint16_t *tones)
//{
//  bitWrite(TIMSK3, OCIE3A, 0); // disable the output compare match interrupt
//  inProgmem = false;
//  tonesStart = tonesIndex = tones; // set to start of sequence array
//  toneMode = TONES_MODE_NORMAL;
//  nextTone(); // start playing
//}

void ArduboyTonesFX::tonesFromFX(uint24_t tones)
{
  //inProgmem = false;
  tonesBufferFX_Start = tonesBufferFX_Curr = tones; // set to start of sequence array
  //toneMode = TONES_MODE_FX;
  tonesBufferFX_Head = 0;
  tonesBufferFX_Tail = 255; // odd value to signal fill buffer
  //tonesPlaying = true;

  fillBufferFromFX();

  bitWrite(TIMSK3, OCIE3A, 0); // disable the output compare match interrupt
  nextTone(); // start playing
}

void ArduboyTonesFX::fillBufferFromFX()
{
    if (/*tonesPlaying &&*/ tonesBufferFX_Head != tonesBufferFX_Tail) {

      uint8_t head = tonesBufferFX_Head;
      FX::seekData(tonesBufferFX_Curr);

      while (head != tonesBufferFX_Tail) {

        uint16_t t = FX::readPendingUInt16();
        if (t == TONES_REPEAT) {
          tonesBufferFX_Curr = tonesBufferFX_Start;
          FX::readEnd();
          FX::seekData(tonesBufferFX_Curr);
        }
        else {
          tonesBufferFX[head] = t;
          if (++head == tonesBufferFX_Len) head = 0;
          tonesBufferFX_Curr = tonesBufferFX_Curr + 2;
          if (tonesBufferFX_Tail == 255) tonesBufferFX_Tail = 0;
        }
      }

      tonesBufferFX_Head = head;
      FX::readEnd();

    }

}

void ArduboyTonesFX::noTone()
{
  bitWrite(TIMSK3, OCIE3A, 0); // disable the output compare match interrupt
  TCCR3B = 0; // stop the counter
  bitClear(TONE_PIN_PORT, TONE_PIN); // set the pin low
#ifdef TONES_VOLUME_CONTROL
  bitClear(TONE_PIN2_PORT, TONE_PIN2); // set pin 2 low
#endif
  //tonesPlaying = false;
}

void ArduboyTonesFX::volumeMode(uint8_t mode)
{
#ifdef TONES_VOLUME_CONTROL
  forceNormVol = false; // assume volume is tone controlled
  forceHighVol = false;

  if (mode == VOLUME_ALWAYS_NORMAL) {
    forceNormVol = true;
  }
  else if (mode == VOLUME_ALWAYS_HIGH) {
    forceHighVol = true;
  }
#endif
}

bool ArduboyTonesFX::playing()
{
  return TCCR3A;
}

void ArduboyTonesFX::nextTone()
{
  uint16_t freq;
  uint16_t dur;
  long toggleCount;
  uint32_t ocrValue;
#ifdef TONES_ADJUST_PRESCALER
  uint8_t tccrxbValue;
#endif

  freq = getNext(); // get tone frequency

  if (freq == TONES_END) { // if freq is actually an "end of sequence" marker
    noTone(); // stop playing
    return;
  }

  //tonesPlaying = true;

  //if (freq == TONES_REPEAT) { // if frequency is actually a "repeat" marker
  //  tonesIndex = tonesStart; // reset to start of sequence
  //  freq = getNext();
  //}

#ifdef TONES_VOLUME_CONTROL
  if (((freq & TONE_HIGH_VOLUME) || forceHighVol) && !forceNormVol) {
    toneHighVol = true;
  }
  else {
    toneHighVol = false;
  }
#endif

  freq &= ~TONE_HIGH_VOLUME; // strip volume indicator from frequency

#ifdef TONES_ADJUST_PRESCALER
  if (freq >= MIN_NO_PRESCALE_FREQ) {
    tccrxbValue = _BV(WGM32) | _BV(CS30); // CTC mode, no prescaling
    ocrValue = F_CPU / freq / 2 - 1;
    toneSilent = false;
  }
  else {
    tccrxbValue = _BV(WGM32) | _BV(CS31); // CTC mode, prescaler /8
#endif
    if (freq == 0) { // if tone is silent
      ocrValue = F_CPU / 8 / SILENT_FREQ / 2 - 1; // dummy tone for silence
      freq = SILENT_FREQ;
      toneSilent = true;
      bitClear(TONE_PIN_PORT, TONE_PIN); // set the pin low
    }
    else {
      ocrValue = F_CPU / 8 / freq / 2 - 1;
      toneSilent = false;
    }
#ifdef TONES_ADJUST_PRESCALER
  }
#endif

  if (!outputEnabled()) { // if sound has been muted
    toneSilent = true;
  }

#ifdef TONES_VOLUME_CONTROL
  if (toneHighVol && !toneSilent) {
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
    // A right shift is used to divide by 512 for efficency.
    // For durations in milliseconds it should actually be a divide by 500,
    // so durations will by shorter by 2.34% of what is specified.
    toggleCount = ((long)dur * freq) >> 9;
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
  durationToggleCount = toggleCount;
  bitWrite(TIMSK3, OCIE3A, 1); // enable the output compare match interrupt
}

uint16_t ArduboyTonesFX::getNext()
{
  //if (toneMode == TONES_MODE_NORMAL) {
  //
  //  if (inProgmem) {
  //    return pgm_read_word(tonesIndex++);
  //  }
  //  return *tonesIndex++;
  //
  //}
  //else {
   #ifdef ARDUINO_ARCH_AVR
     uint16_t t;
     asm volatile(
       "lds  r24, %[tail]       \n"
       "mov  r0, r24            \n"
       "add  r24, r24           \n"
       "lds  r30, %[buffer]+0   \n"
       "add  r30, r24           \n"
       "lds  r31, %[buffer]+1   \n"
       "adc  r31, r1            \n"
       "ld   r24, Z             \n"
       "ldd  r25, Z+1           \n"
       "inc  r0                 \n"
       "lds  r30, %[len]        \n"
       "cp   r0, r30            \n"
       "brcs .+2                \n"
       "clr  r0                 \n"
       "sts  %[tail], r0        \n"
       :    "=&r" (t)
       : [tail]   "" (&tonesBufferFX_Tail),
         [len]    "" (&tonesBufferFX_Len),
         [buffer] "" (tonesBufferFX)
       :"r30", "r31"
     );
     return t;
   #else
    uint8_t tail = tonesBufferFX_Tail;
    uint16_t t = tonesBufferFX[tail];
    if (++tail >= tonesBufferFX_Len) tail = 0;
    tonesBufferFX_Tail = tail;
    return t;
   #endif
  //}

}

ISR(TIMER3_COMPA_vect)
{
  long toggleCount = durationToggleCount;
  if (toggleCount != 0) {
    if (!toneSilent) {
      bitSet(*(&TONE_PIN_PIN), TONE_PIN); // toggle the pin
#ifdef TONES_VOLUME_CONTROL
      if (toneHighVol) {
        bitSet(*(&TONE_PIN2_PIN), TONE_PIN2); // toggle pin 2
      }
#endif
    }
    if (--toggleCount >= 0) {
      durationToggleCount = toggleCount;
    }
  }
  else {
    ArduboyTonesFX::nextTone();
  }
}
