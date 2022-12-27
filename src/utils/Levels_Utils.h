#pragma once

#include "Arduboy2Ext.h"

class Levels_Utils {

  public: 
        
    static uint24_t getLevel_FG(uint8_t levelNo);
    static uint24_t getLevel_BG(uint8_t levelNo);
    static uint24_t getLevel_Data(uint8_t levelNo);
    static uint24_t getLevel_Items(uint8_t levelNo);

};

uint24_t Levels_Utils::getLevel_FG(uint8_t levelNo) {

    uint24_t level_FG[] = { Levels::Level1_FG, Levels::Level1_FG };
    return level_FG[levelNo];

}

uint24_t Levels_Utils::getLevel_BG(uint8_t levelNo) {

    uint24_t Level_BG[] = { Levels::Level1_BG, Levels::Level1_BG };
    return Level_BG[levelNo];

}

uint24_t Levels_Utils::getLevel_Data(uint8_t levelNo) {

    uint24_t level_Data[] = { Levels::level1_Data, Levels::level1_Data };
    return level_Data[levelNo];

}

uint24_t Levels_Utils::getLevel_Items(uint8_t levelNo) {

    uint24_t Level_Items[] = { Levels::Level1_Items, Levels::Level1_Items };
    return Level_Items[levelNo];

}