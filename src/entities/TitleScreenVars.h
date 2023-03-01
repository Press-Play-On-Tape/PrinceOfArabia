#pragma once

#include <Arduboy2.h>
#include "../utils/Constants.h"
#include "../../fxdata/fxdata.h"
#include "Level.h"

struct TitleScreenVars {

    public:

        TitleScreenOptions option;

        #ifdef POP_OR_SOS
            uint8_t counter;
        #endif


    #ifdef POP_OR_SOS
    void reset(bool pop) {
    #else
    void reset() {
    #endif

        this->option = TitleScreenOptions::Play;

        #ifdef POP_OR_SOS
            if (pop) {
                FX::setFrame(Title_Intro_PoP_Frame_NoHigh, 0);
            }
            else {
                FX::setFrame(Title_Intro_SoS_Frame_NoHigh, 0);
            }
        #endif

        #ifdef POP_ONLY
            FX::setFrame(Title_Intro_PoP_Frame_NoHigh, 0);
        #endif

        #ifdef SOS_ONLY
            FX::setFrame(Title_Intro_SoS_Frame_NoHigh, 0);
        #endif

    }

};
