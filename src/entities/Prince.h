#pragma once

#include <Arduboy2.h>   
#include "../utils/Constants.h"
#include "../utils/Stack.h"
#include "../entities/Structs.h"
#include "BaseEntity.h"
#include "BaseStack.h"

class Prince : public BaseEntity, public BaseStack {

    private:
        
        uint8_t hangingCounter = 0;
        uint8_t crouchingCounter = 0;

        uint8_t falling = 0;
        bool sword = false;
        bool ignoreWallCollisions = false;

    public:

        bool getSword()                             { return this->sword; }
        bool getIgnoreWallCollisions()              { return this->ignoreWallCollisions; }
        uint8_t getHangingCounter()                 { return this->hangingCounter; }
        uint8_t getCrouchingCounter()               { return this->crouchingCounter; }
        uint8_t getFalling()                        { return this->falling; }

        void setSword(bool val)                     { this->sword = val; }
        void setIgnoreWallCollisions(bool val)      { this->ignoreWallCollisions = val; }
        void setFalling(uint8_t val)                { this->falling = val; }
        void setHangingCounter(uint8_t val)         { this->hangingCounter = val; }
        void setCrouchingCounter(uint8_t val)       { this->crouchingCounter = val; }

        void incFalling()                           { this->falling++; }


        void init(int16_t x, int16_t y, Direction direction, uint16_t stance, uint8_t health, bool clearSword) {

            this->x = x;
            this->y = y;
            this->direction = direction;
            this->stance = stance;
            this->crouchingCounter = 32;
            this->health = health;
            this->healthMax = health;
            if (clearSword) this->sword = false;
            this->ignoreWallCollisions = false;

        }

    	void update(uint8_t xLoc, uint8_t yLoc) {

            // Housekeeping ..

            if (this->hangingCounter > 0) {
                this->hangingCounter--;
            }

            if (this->crouchingCounter > 0) {
                this->crouchingCounter--;
            }

            this->stack->update();

            location.x = (xLoc * Constants::TileWidth) + this->x;
            location.y = (yLoc * Constants::TileHeight) + this->y;

        }

        bool isSwordDrawn() {

            switch (this->stance) {

                case Stance::Sword_Attack_01_Start ... Stance::Sword_Attack_08_End:
                case Stance::Attack_Block_01_Start ... Stance::Attack_Block_03_End:
                case Stance::Draw_Sword_01_Start ... Stance::Draw_Sword_06_End:
                case Stance::Sword_Step_01_Start ... Stance::Sword_Step_03_End:
                case Stance::Sword_Normal:
                    return true;

                default: 
                    return false;

            }

        }

};