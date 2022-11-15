#pragma once

#include <Arduboy2.h>   
#include "../utils/Constants.h"

struct TitleScreenVars {

    uint8_t prevCount;
    uint8_t count;
    uint8_t zaffar_x;
    uint8_t zaffar_Image;
    TitleScreenOptions option;
    TitleScreenMode mode;

    void reset() { 

        this->count = 0;
        this->option = TitleScreenOptions::Play;
        this->mode = TitleScreenMode::Intro;
        this->zaffar_x = 138;

    }

    bool update(bool triggerFrame) {

        switch (this->mode) {

            case TitleScreenMode::Intro:

                if (this->count < 64) this->count = this->count + 1;
                return false;

            case TitleScreenMode::Main:

                if (this->count < Constants::TitleScreenScroll_Max) this->count = this->count + 1;
                return false;

            case TitleScreenMode::Credits:

                if (triggerFrame) {
                    if (this->count < 170) this->count++;
                    if (this->count == 170) this->count = 0;
                }

                return false;

            case TitleScreenMode::IntroGame1:

                if (triggerFrame) {
                    if (this->count < 165) this->count++;
                    if (this->count == 165) return true;
                }

                return false;

            case TitleScreenMode::CutScene1:

                if (triggerFrame) {
                    zaffar_Image = static_cast<uint8_t>(pgm_read_byte(&Zaffar_CutScene1[this->count * 2]));
                    zaffar_x = zaffar_x + static_cast<int8_t>(pgm_read_byte(&Zaffar_CutScene1[(this->count * 2) + 1]));
                    this->prevCount = this->count;
                    if (this->count < 198) this->count++;
                    if (this->count == 198) return true;
                }
 
                return false;

            case TitleScreenMode::IntroGame2:

                if (triggerFrame) {
                    if (this->count < 165) this->count++;
                    if (this->count == 165) return true;
                }

                return false;
                
        }

    }

};

struct ImageDetails {

    int8_t reach;
    int8_t toe;
    int8_t heel;

};
 