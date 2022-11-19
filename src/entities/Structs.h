#pragma once

#include <Arduboy2.h>   
#include "../utils/Constants.h"
#include "../../fxdata/fxdata.h"


struct Character {

    uint8_t x;
    uint8_t image;

};

struct TitleScreenVars {

    uint8_t prevCount;
    uint8_t count;

    Character zaffar;
    Character princess;
    Character prince;

    TitleScreenOptions option;
    TitleScreenMode mode;

    void reset() { 

        this->count = 0;
        this->option = TitleScreenOptions::Play;
        this->mode = TitleScreenMode::Intro;
        this->zaffar.x = 142;
        this->prince.x = 132;
        this->princess.x = 34;

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
                    this->count++;
                    if (this->count == 170) this->count = 0;
                }

                return false;

            case TitleScreenMode::IntroGame1:

                if (triggerFrame) {
                    this->count++;
                    if (this->count == 165) return true;
                }

                return false;

            case TitleScreenMode::CutScene1:

                if (triggerFrame) {

                    FX::seekData(static_cast<uint24_t>(CutScene::Scene1 + (this->count * 4)));

                    zaffar.image = static_cast<int8_t>(FX::readPendingUInt8());
                    zaffar.x = zaffar.x + static_cast<int8_t>(FX::readPendingUInt8());
                    princess.image = static_cast<uint8_t>(FX::readPendingUInt8());
                    princess.x = princess.x + static_cast<int8_t>(FX::readPendingUInt8());

                    this->prevCount = this->count;
                    this->count++;
                    if (this->count == 249) return true;

                    FX::readEnd();

                }
 
                return false;

            case TitleScreenMode::IntroGame2:

                if (triggerFrame) {
                    if (this->count < 165) this->count++;
                    if (this->count == 165) return true;
                }

                return false;
                
            case TitleScreenMode::CutScene9:

                if (triggerFrame) {

                    // FX::seekData(static_cast<uint24_t>(CutScene::SceneFinal + (this->count * 4)));

                    // zaffar.image = static_cast<int8_t>(FX::readPendingUInt8());
                    // zaffar.x = zaffar.x + static_cast<int8_t>(FX::readPendingUInt8());
                    // princess.image = static_cast<uint8_t>(FX::readPendingUInt8());
                    // princess.x = princess.x + static_cast<int8_t>(FX::readPendingUInt8());

                    // this->prevCount = this->count;
                    // this->count++;
                    // if (this->count == 249) return true;

                    // FX::readEnd();
 
                    prince.image = static_cast<uint8_t>(pgm_read_byte(&Constants::SceneFinal[(this->count * 4)]));
                    prince.x = prince.x + static_cast<int8_t>(pgm_read_byte(&Constants::SceneFinal[(this->count * 4) + 1]));
                    princess.image = static_cast<uint8_t>(pgm_read_byte(&Constants::SceneFinal[(this->count * 4) + 2]));
                    princess.x = princess.x + static_cast<int8_t>(pgm_read_byte(&Constants::SceneFinal[(this->count * 4) + 3]));

                    this->prevCount = this->count;
                    this->count++;
                    if (this->count == 128) return true;

                }
 
                return false;

            case TitleScreenMode::IntroGame9:

                if (triggerFrame) {
                    if (this->count < 224) this->count++;
                    if (this->count == 224) return true;
                }

                return false;                
        }

        return false;

    }

};

struct ImageDetails {

    int8_t reach;
    int8_t toe;
    int8_t heel;

};
 