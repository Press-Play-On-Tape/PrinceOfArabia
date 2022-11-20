#pragma once

#include "../utils/Arduboy2Ext.h"
#include "../utils/Constants.h"
#include "GamePlay.h"
#include "Level.h"
#include "Prince.h"
#include "TitleScreenVars.h"

struct Cookie {

    GamePlay gamePlay;
    Level level;
    Prince prince;
    TitleScreenVars titleScreenVars;

};
