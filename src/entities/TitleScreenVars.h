#pragma once

#include <Arduboy2.h>   
#include "../utils/Constants.h"
#include "../../fxdata/fxdata.h"
#include "Level.h"

struct TitleScreenVars {

    private:
        TitleScreenMode mode;

    public:

        uint8_t prevCount;
        uint8_t count;

        Character zaffar;
        Character princess;
        Character prince;

        TitleScreenOptions option;

    void reset() { 

        this->count = 0;
        this->option = TitleScreenOptions::Play;
        this->mode = TitleScreenMode::Intro;

    }


    TitleScreenMode getMode()               { return this->mode; }

    void setMode(TitleScreenMode mode, Level &level) {

        this->mode = mode;

        switch (this->mode) {
            
            case TitleScreenMode::Credits:

                this->count = 88;
                break;
            
            case TitleScreenMode::IntroGame_1A:
            case TitleScreenMode::CutScene_1:
            case TitleScreenMode::IntroGame_1B:

                this->count = 0;
                break;
            
            case TitleScreenMode::CutScene_2:

                this->princess.x = 63;
                break;
            
            case TitleScreenMode::CutScene_4:

                this->princess.x = 67;
                break;
            
            case TitleScreenMode::CutScene_5:

                this->princess.x = 24;
                break;

            case TitleScreenMode::CutScene_9:
                {
                    Item &heart = level.getItem(Constants::Item_LoveHeart);
                    heart.itemType = ItemType::LoveHeart;
                    heart.data.loveHeart.counter = 0;
                    heart.x = 60;
                    heart.y = 25;

                    this->princess.x = 30;
                    this->prince.x = 132;

                }
                break;

            default:
                this->zaffar.x = 142;
                this->prince.x = 132;
                this->princess.x = 34;
                break;

        }

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
                    if (this->count == 190) this->count = 0;
                }

                return false;

            case TitleScreenMode::IntroGame_1A:

                if (triggerFrame) {
                    this->count++;
                    if (this->count == 165) return true;
                }

                return false;

            case TitleScreenMode::CutScene_1:

                if (triggerFrame) {

                    FX::seekData(static_cast<uint24_t>(CutScene::Scene1 + (this->count * 4)));

                    zaffar.image = static_cast<int8_t>(FX::readPendingUInt8());
                    zaffar.x = zaffar.x + static_cast<int8_t>(FX::readPendingUInt8());
                    princess.image = static_cast<uint8_t>(FX::readPendingUInt8());
                    princess.x = princess.x + static_cast<int8_t>(FX::readPendingUInt8());

                    FX::readEnd();

                    this->prevCount = this->count;
                    this->count++;
                    if (this->count == 249) return true;

                }
 
                return false;

            case TitleScreenMode::IntroGame_1B:

                if (triggerFrame) {
                    if (this->count < 165) this->count++;
                    if (this->count == 165) return true;
                }

                return false;
       
            case TitleScreenMode::CutScene_2:
            case TitleScreenMode::CutScene_3:

                if (triggerFrame) {
                    
                    this->count++;
                    if (this->count == 96) return true;

                }
 
                return false;

            case TitleScreenMode::CutScene_4:

                if (triggerFrame) {
                    
                    this->count++;
                    if (this->count == 48) return true;

                }
 
                return false;
                
            case TitleScreenMode::CutScene_9:

                if (triggerFrame) {

                    FX::seekData(static_cast<uint24_t>(CutScene::Scene9 + (this->count * 4)));

                    prince.image = static_cast<int8_t>(FX::readPendingUInt8());
                    prince.x = prince.x + static_cast<int8_t>(FX::readPendingUInt8());
                    princess.image = static_cast<uint8_t>(FX::readPendingUInt8());
                    princess.x = princess.x + static_cast<int8_t>(FX::readPendingUInt8());

                    FX::readEnd();
 
                    this->count++;
                    if (this->count == 128) return true;

                }
 
                return false;

            case TitleScreenMode::IntroGame_9:

                if (triggerFrame) {
                    if (this->count < 224) this->count++;
                    if (this->count == 224) return true;
                }

                return false;                

            default: return false;
        }

        return false;

    }

};
