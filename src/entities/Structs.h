#pragma once

#include <Arduboy2.h>   
#include "../utils/Constants.h"

struct TitleScreenVars {

    uint8_t count;
    TitleScreenOptions option;
    TitleScreenMode mode;

    void reset() { 

        this->count = 0;
        this->option = TitleScreenOptions::Play;
        this->mode = TitleScreenMode::Intro;

    }

    void update() {

        switch (this->mode) {

            case TitleScreenMode::Intro:
                if (this->count < 64) this->count = this->count + 2;
                break;

            case TitleScreenMode::Main:
                if (this->count < Constants::TitleScreenScroll_Max) this->count = this->count + 2;
                break;

            case TitleScreenMode::Credits:
                if (this->count < 170) this->count++;
                if (this->count == 170) this->count = 0;
                break;
                
        }

    }

};
 