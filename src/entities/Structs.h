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

    bool update(bool evenFrame) {

        switch (this->mode) {

            case TitleScreenMode::Intro:
                if (this->count < 64) this->count = this->count + 1;
                return false;

            case TitleScreenMode::Main:
                if (this->count < Constants::TitleScreenScroll_Max) this->count = this->count + 1;
                return false;

            case TitleScreenMode::Credits:
                if (evenFrame) {
                    if (this->count < 170) this->count++;
                    if (this->count == 170) this->count = 0;
                }
                return false;

            case TitleScreenMode::IntroGame1:
                if (evenFrame) {
                    if (this->count < 170) this->count++;
                    if (this->count == 170) return true;
                }
                return false;

            case TitleScreenMode::CutScene1:
                return false;

            case TitleScreenMode::IntroGame2:
                if (evenFrame) {
                    if (this->count < 170) this->count++;
                    if (this->count == 170) return true;
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
 