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
        uint8_t drawSwordCounter = 0;

        uint8_t falling = 0;
        bool sword = false;
        bool potionFloat = false;
        bool ignoreWallCollisions = false;

    public:

        bool getSword()                             { return this->sword; }
        bool getPotionFloat()                       { return this->potionFloat; }
        bool getIgnoreWallCollisions()              { return this->ignoreWallCollisions; }
        uint8_t getHangingCounter()                 { return this->hangingCounter; }
        uint8_t getCrouchingCounter()               { return this->crouchingCounter; }
        uint8_t getDrawSwordCounter()               { return this->drawSwordCounter; }
        uint8_t getFalling()                        { return this->falling; }

        void setSword(bool val)                     { this->sword = val; }
        void setPotionFloat(bool val)               { this->potionFloat = val; }
        void setIgnoreWallCollisions(bool val)      { this->ignoreWallCollisions = val; }
        void setFalling(uint8_t val)                { this->falling = val; }
        void setHangingCounter(uint8_t val)         { this->hangingCounter = val; }
        void setCrouchingCounter(uint8_t val)       { this->crouchingCounter = val; }
        void setDrawSwordCounter(uint8_t val)       { this->drawSwordCounter = val; }

        void incFalling()                           { this->falling++; }


        void init(int16_t x, int16_t y, Direction direction, uint16_t stance, bool clearSword) {

            this->x = x;
            this->y = y;
            this->direction = direction;
            this->stance = stance;
            if (clearSword) this->sword = false;
            this->ignoreWallCollisions = false;

            if (this->health < 3) this->health = 3;

            if (stance != Stance::Jump_Up_A_14_End) {

                this->crouchingCounter = 80;
                this->hangingCounter = 0;

            }
            else {

                // Level 7

                this->crouchingCounter = 0;
                this->hangingCounter = 128;

            }

            this->push(stance);

        }

    	void update(uint8_t xLoc, uint8_t yLoc) {

            // Housekeeping ..

            if (this->hangingCounter > 0) {
                this->hangingCounter--;
            }

            if (this->crouchingCounter > 0) {
                this->crouchingCounter--;
            }

            if (this->drawSwordCounter > 0) {
                this->drawSwordCounter--;
            }

            this->stack->update();

            location.x = (xLoc * Constants::TileWidth) + this->x;
            location.y = (yLoc * Constants::TileHeight) + this->y;

        }

        bool isSwordDrawn() {

            switch (this->stance) {

                case Stance::Sword_Attack_1_Start ... Stance::Sword_Attack_8_End:
                case Stance::Attack_Block_1_Start ... Stance::Attack_Block_3_End:
                case Stance::Draw_Sword_1_Start ... Stance::Draw_Sword_6_End:
                case Stance::Sword_Step_1_Start ... Stance::Sword_Step_3_End:
                case Stance::Sword_Normal:
                    return true;

                default: 
                    return false;

            }

        }

        void pushSequence(uint16_t fromStance, uint16_t toStance) {

            this->ignoreWallCollisions = false;
            BaseStack::pushSequence(fromStance, toStance, Stance::None);

        }

        void pushSequence(uint16_t fromStance, uint16_t toStance, uint16_t finalStance) {

            this->ignoreWallCollisions = false;
            BaseStack::pushSequence(fromStance, toStance, finalStance);

        }

};