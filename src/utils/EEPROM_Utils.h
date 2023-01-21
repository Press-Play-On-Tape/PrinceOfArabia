#pragma once

#include "Arduboy2Ext.h"
#include "../entities/Cookie.h"

#define EEPROM_START                  ((uint8_t *)EEPROM_STORAGE_SPACE_START + 300)
#define EEPROM_START_C1               ((uint8_t *)EEPROM_START)
#define EEPROM_START_C2               ((uint8_t *)EEPROM_START + 1)
#define EEPROM_MIN                    ((uint8_t *)EEPROM_START + 2)
#define EEPROM_SEC                    ((uint8_t *)EEPROM_START + 3)
#define EEPROM_SAVED_LEVEL            ((uint8_t *)EEPROM_START + 4)
#define EEPROM_TOP_START              ((uint8_t *)EEPROM_START + 5)


class EEPROM_Utils {

  public: 

    EEPROM_Utils(){};
        
    static void saveGame(Cookie &cookie);
    static void loadGame(Cookie &cookie);
    static bool isSaved();
    static bool hasHighScore();
    static void saveHighScore(uint8_t min, uint8_t sec);
    static uint8_t getMin();
    static uint8_t getSec();

};


/* ---------------------------------------------------------------------------- */

const uint8_t letter1 = 80; 
const uint8_t letter2 = 80; 
const uint8_t savedGame = 87; 


void EEPROM_Utils::saveGame(Cookie &cookie) {

    byte c1 = eeprom_read_byte(EEPROM_START_C1);
    byte c2 = eeprom_read_byte(EEPROM_START_C2);

    if (c1 != letter1 || c2 != letter2) {

        eeprom_update_byte(EEPROM_MIN, 0);
        eeprom_update_byte(EEPROM_SEC, 0);

    }

    eeprom_update_byte(EEPROM_START_C1, letter1);
    eeprom_update_byte(EEPROM_START_C2, letter2);
    eeprom_update_byte(EEPROM_SAVED_LEVEL, savedGame);
    eeprom_write_block(&cookie, EEPROM_TOP_START, sizeof(cookie));

}

void EEPROM_Utils::loadGame(Cookie &cookie) {

    eeprom_read_block(&cookie, EEPROM_TOP_START, sizeof(cookie));

}

bool EEPROM_Utils::isSaved() {

    if (eeprom_read_byte(EEPROM_START_C1) != letter1) return false;
    if (eeprom_read_byte(EEPROM_START_C2) != letter2) return false;
    if (eeprom_read_byte(EEPROM_SAVED_LEVEL) != savedGame) return false;

}

bool EEPROM_Utils::hasHighScore() {

    byte c1 = eeprom_read_byte(EEPROM_START_C1);
    byte c2 = eeprom_read_byte(EEPROM_START_C2);

    byte min = eeprom_read_byte(EEPROM_MIN);
    byte sec = eeprom_read_byte(EEPROM_SEC);

    return (c1 == letter1 && c2 == letter2 && (min > 0 || sec > 0));

}

uint8_t EEPROM_Utils::getMin() {

    byte min = eeprom_read_byte(EEPROM_MIN);
    
    return (min > 59 ? 0 : min);

}

uint8_t EEPROM_Utils::getSec() {

    byte sec = eeprom_read_byte(EEPROM_SEC);

    return (sec > 59 ? 0 : sec);

}

void EEPROM_Utils::saveHighScore(uint8_t min, uint8_t sec) {

    byte minExist = eeprom_read_byte(EEPROM_MIN);
    byte secExist = eeprom_read_byte(EEPROM_SEC);

    if (!hasHighScore() || (min * 60) + sec > (minExist * 60) + secExist) {

        eeprom_update_byte(EEPROM_START_C1, letter1);
        eeprom_update_byte(EEPROM_START_C2, letter2);
        eeprom_update_byte(EEPROM_MIN, min);
        eeprom_update_byte(EEPROM_SEC, sec);

    }

}
