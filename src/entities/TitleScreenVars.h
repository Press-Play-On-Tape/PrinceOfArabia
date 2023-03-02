#pragma once

#include <Arduboy2.h>
#include "../utils/Constants.h"
#include "../../fxdata/fxdata.h"
#include "Level.h"

extern void setTitleFrame(TitleFrameIndex index);

struct TitleScreenVars {

    public:

        TitleScreenOptions option;

        #ifdef POP_OR_POA
            uint8_t counter;
        #endif


    #ifdef POP_OR_POA
    void reset(bool pop) {
    #else
    void reset() {
    #endif

        this->option = TitleScreenOptions::Play;
        setTitleFrame(TitleFrameIndex::Intro_PoP_Frame_NoHigh);

    }

};
