#pragma once

#include "../utils/Arduboy2Ext.h"
#include "../utils/Constants.h"
#include "GamePlay.h"
#include "Level.h"
#include "Prince.h"
#include "Enemy.h"
#include "TitleScreenVars.h"

struct Cookie {

    bool hasSavedLevel;
    bool hasSavedScore;

    uint8_t highMin;
    uint8_t highSec;

    GamePlay gamePlay;
    Level level;
    Prince prince;

    #ifndef SAVE_MEMORY_ENEMY
    Enemy enemy;
    #endif

};
