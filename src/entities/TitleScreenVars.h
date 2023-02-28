#pragma once

#include <Arduboy2.h>
#include "../utils/Constants.h"
#include "../../fxdata/fxdata.h"
#include "Level.h"

struct TitleScreenVars {

    public:

        TitleScreenOptions option;

    void reset() {

        this->option = TitleScreenOptions::Play;
        FX::setFrame(Title_Intro_Frame_NoHigh, 0);

    }

};
