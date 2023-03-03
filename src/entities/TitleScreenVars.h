#pragma once

#include <Arduboy2.h>
#include "../utils/Constants.h"
#include "../../fxdata/fxdata.h"
#include "Level.h"

extern void setTitleFrame(TitleFrameIndex index);

struct TitleScreenVars {
    
    #ifdef POP_OR_POA
        uint8_t counter;
    #endif
    
    public:

        TitleScreenOptions option;

    void reset() {

        this->option = TitleScreenOptions::Play;
        setTitleFrame(TitleFrameIndex::Intro_PoP_Frame_NoHigh);

    }

};
