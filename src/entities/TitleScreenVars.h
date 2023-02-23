#pragma once

#include <Arduboy2.h>
#include "../utils/Constants.h"
#include "../../fxdata/fxdata.h"
#include "Level.h"

struct TitleScreenVars {

    private:
        TitleScreenMode mode;

    public:

        //uint8_t prevCount;
        //uint8_t count;

        //Character jaffar;
        //Character princess;
        //Character prince;

        TitleScreenOptions option;

    void reset() {

        //this->count = 0;
        this->option = TitleScreenOptions::Play;
        this->mode = TitleScreenMode::Intro;
        FX::setFrame(Title_Intro_Frame_NoHigh, 0);

    }


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
