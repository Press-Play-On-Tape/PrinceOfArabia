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

    TitleScreenMode mode;


    TitleScreenMode getMode()               { return this->mode; }

    void setMode(TitleScreenMode mode) {

        this->mode = mode;

        switch (this->mode) {

            case TitleScreenMode::CutScene_2:

                 FX::setFrame(Title_CutScene_2_Frame, 4 - 1);
                 break;

            case TitleScreenMode::CutScene_3:

                 FX::setFrame(Title_CutScene_3_Frame, 4 - 1);
                 break;

            case TitleScreenMode::CutScene_4:

                FX::setFrame(Title_CutScene_4_Frame, 6 - 1);
                break;

            case TitleScreenMode::CutScene_5:

                FX::setFrame(Title_CutScene_5_Frame, 3 - 1);
                break;

            case TitleScreenMode::CutScene_6:

                FX::setFrame(Title_CutScene_6_Frame, 2 - 1);
                break;

            case TitleScreenMode::CutScene_7_Transition:

                FX::setFrame(Title_CutScene_7_Frame, 1 - 1);
                break;

            case TitleScreenMode::CutScene_End:

                FX::setFrame(Title_CutScene_End_Frame, 4 - 1);
                break;

            default:
                break;

        }

    }


};
