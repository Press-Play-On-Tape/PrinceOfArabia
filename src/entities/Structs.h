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
        this->mode = TitleScreenMode::Main;

    }

    void update() {

        switch (this->mode) {

            case TitleScreenMode::Main:
                if (this->count < 88) this->count++;
                break;

            case TitleScreenMode::Credits:
                if (this->count < 170) this->count++;
                if (this->count == 170) this->count = 0;
                break;
                
        }

    }

};
 