#pragma once

#include "Arduboy2Ext.h"
#include "../entities/Cookie.h"

#define EEPROM_START                  EEPROM_STORAGE_SPACE_START + 300
#define EEPROM_START_C1               EEPROM_START
#define EEPROM_START_C2               EEPROM_START + 1
#define EEPROM_TOP_START              EEPROM_START + 2

class EEPROM_Utils {

  public: 

    EEPROM_Utils(){};
        
    static void saveGame(Cookie &cookie);
    static void loadGame(Cookie &cookie);
    static bool isSaved();

};


/* ----------------------------------------------------------------------------
 *   Is the EEPROM initialised?
 *
 *   Looks for the characters 'P' and 'P' in the first two bytes of the EEPROM
 *   memory range starting from byte EEPROM_STORAGE_SPACE_START.  If not found,
 *   it resets the settings ..
 */

const uint8_t letter1 = 80; 
const uint8_t letter2 = 80; 

// void EEPROM_Utils::initEEPROM(Cookie &cookie) {

//     byte c1 = EEPROM.read(EEPROM_START_C1);
//     byte c2 = EEPROM.read(EEPROM_START_C2);

//     if (c1 != letter1 || c2 != letter2) { 

//         EEPROM.update(EEPROM_START_C1, letter1);
//         EEPROM.update(EEPROM_START_C2, letter2);
//         EEPROM.put(EEPROM_TOP_START, cookie);

//     }

// }


void EEPROM_Utils::saveGame(Cookie &cookie) {

    EEPROM.update(EEPROM_START_C1, letter1);
    EEPROM.update(EEPROM_START_C2, letter2);
    EEPROM.put(EEPROM_TOP_START, cookie);

}

void EEPROM_Utils::loadGame(Cookie &cookie) {

    EEPROM.get(EEPROM_TOP_START, cookie);

}

bool EEPROM_Utils::isSaved() {

    byte c1 = EEPROM.read(EEPROM_START_C1);
    byte c2 = EEPROM.read(EEPROM_START_C2);

    return (c1 == letter1 && c2 == letter2);

}

