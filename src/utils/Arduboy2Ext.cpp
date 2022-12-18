#include "Arduboy2Ext.h"

Arduboy2Ext::Arduboy2Ext() : Arduboy2Base() { }

uint8_t Arduboy2Ext::justPressedButtons() const {

  return (~previousButtonState & currentButtonState);

}

uint8_t Arduboy2Ext::pressedButtons() const {

  return currentButtonState;

}

void Arduboy2Ext::clearButtonState() {

  currentButtonState = previousButtonState = 0;

}


void Arduboy2Ext::resetFrameCount() {

  frameCount = 0;

}

uint16_t Arduboy2Ext::getFrameCount() const {

  return frameCount;

}

void Arduboy2Ext::setFrameCount(uint16_t val) const {

  frameCount = val;

}

uint8_t Arduboy2Ext::getFrameCount(uint8_t mod, int8_t offset) const {

  return (frameCount + offset) % mod;

}

bool Arduboy2Ext::getFrameCountHalf(uint8_t mod) const {

	return getFrameCount(mod) > (mod / 2);

}

bool Arduboy2Ext::isFrameCount(uint8_t mod) const {

  return (frameCount % mod) == 0;

}

bool Arduboy2Ext::isFrameCount(uint8_t mod, uint8_t val) const {

  return (frameCount % mod) == val;

}


