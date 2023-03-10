#pragma once

#include "../utils/Arduboy2Ext.h"
#include "../utils/Constants.h"
#include "GamePlay.h"
#include "Level.h"
#include "Prince.h"
#include "Enemy.h"
#include "TitleScreenVars.h"

extern void setTitleFrame(TitleFrameIndex index);

struct Cookie {

    bool hasSavedLevel;
    bool hasSavedScore;

    #ifdef POP_OR_POA
    bool pop = false;
    #endif

    uint8_t highMin;
    uint8_t highSec;
    uint8_t highSaves;

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

                 //FX::setFrame(Title_CutScene_2_Frame, 4 - 1);
                 setTitleFrame(TitleFrameIndex::CutScene_2_Frame);
                 break;

            case TitleScreenMode::CutScene_3:

                 //FX::setFrame(Title_CutScene_3_Frame, 4 - 1);
                 setTitleFrame(TitleFrameIndex::CutScene_3_Frame);
                 break;

            case TitleScreenMode::CutScene_4:

                //FX::setFrame(Title_CutScene_4_Frame, 6 - 1);
                setTitleFrame(TitleFrameIndex::CutScene_4_Frame);
                break;

            case TitleScreenMode::CutScene_5:

                //FX::setFrame(Title_CutScene_5_Frame, 3 - 1);
                setTitleFrame(TitleFrameIndex::CutScene_5_Frame);
                break;

            case TitleScreenMode::CutScene_6:

                //FX::setFrame(Title_CutScene_6_Frame, 2 - 1);
                setTitleFrame(TitleFrameIndex::CutScene_6_Frame);
                break;

            case TitleScreenMode::CutScene_7_Transition:

                //FX::setFrame(Title_CutScene_7_Frame, 1 - 1);
                setTitleFrame(TitleFrameIndex::CutScene_7_Frame);
                break;

            case TitleScreenMode::CutScene_End:

                //FX::setFrame(Title_CutScene_End_Frame, 4 - 1);
                setTitleFrame(TitleFrameIndex::CutScene_End_Frame);
                break;

            default:
                break;

        }

    }


};
