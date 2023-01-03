#pragma once

#include <Arduboy2.h>   
#include "../utils/Constants.h"
#include "../utils/Stack.h"
#include "../entities/Structs.h"

class BaseEntity {

    protected:
        
        uint16_t stance = Stance::Upright;
        uint16_t prevStance = Stance::Upright;
        Direction direction = Direction::Left;

        int16_t x = 0;
        int16_t y = 0;
        int16_t prevY = 0;

        uint8_t health = 0;
        uint8_t healthMax = 0;

        Point location;

    public:

        uint16_t getStance()                        { return this->stance; }
        uint16_t getPrevStance()                    { return this->prevStance; }
        int16_t getX()                              { return this->x; }
        int16_t getY()                              { return this->y; }
        int16_t getYPrevious()                      { return this->prevY; }
        int16_t getXImage()                         { return this->x - 18 + 3; }                // Image is 36 x 36 hence - 18, the plus 3 is due to the orthagonal tiles offset.
        int16_t getYImage()                         { return this->y - 31; }                    // -31 moves the player up 5 pixels on the orthagonal tiles ?
        uint8_t getHealth()                         { return this->health; }
        uint8_t getHealthMax()                      { return this->healthMax; }

        Direction getDirection()                    { return this->direction; }

        void setStance(uint16_t val)                { this->stance = val; }
        void setPrevStance(uint16_t val)            { this->prevStance = val; }
        void setX(int16_t val)                      { this->x = val; }
        void setY(int16_t val)                      { this->y = val; }
        void setYPrevious(int16_t val)              { this->prevY = val; }
        void setDirection(Direction val)            { this->direction = val; }
        void setHealth(uint8_t val)                 { this->health = val; }
        void setHealthMax(uint8_t val)              { this->healthMax = val; }

        uint8_t decHealth(uint8_t val)              { this->health >= val ? this->health = this->health - val: 0; return this->health;}
        void incHealth(int8_t val)                  { this->health = this->health + val > this->healthMax ? this->healthMax : this->health + val; } 
        void incHealthMax(int8_t val)               { this->healthMax = this->healthMax + val; } 

        Point &getPosition()                        { return this->location; }

        Point getPosition(int8_t x, int8_t y = 0)   { 
            
            Point newPoint;

            newPoint.x = this->location.x + x;
            newPoint.y = this->location.y + y;
            return newPoint; 
            
        }

        Direction getOppositeDirection() {

            switch (this->direction) {

                case Direction::Left:       return Direction::Right;
                case Direction::Right:      return Direction::Left;
                default:                    return this->direction;
                
            }
            
        }

        int8_t getDirectionOffset(int8_t val) {

            if (this->direction == Direction::Left) {
                return -val;
            }
            else {
                return val;
            }
            
        }

        void incX(int8_t inc) {

            this->x = this->x + inc;
            
        }

        void incY(int8_t inc) {

            this->prevY = y;
            this->y = this->y + inc;
            
        }

        void changeDirection() {

            this->direction = (this->direction == Direction::Left ? Direction::Right : Direction::Left);

        }


        // ----------------------------------------------------------------------------------------------------------

        bool isFootDown() {

            ImageDetails imageDetails;
            this->getImageDetails(imageDetails);
            return (imageDetails.toe != Constants::InAir && imageDetails.toe != Constants::InAir_DoNotFall);

        }

        bool inAir() {

            ImageDetails imageDetails;
            this->getImageDetails(imageDetails);
            return (imageDetails.toe == Constants::InAir);

        }

        void getImageDetails(ImageDetails &imageDetails) {

            uint8_t imageIndex = static_cast<uint8_t>(pgm_read_byte(&Constants::StanceToImageXRef[this->stance]));
            uint24_t startPos = static_cast<uint24_t>(Constants::Prince_ImageDetails + ((imageIndex - 1) * 3)) - 1;
            int8_t direction = this->getDirection() == Direction::Left ? -1 : 1;

            FX::seekData(startPos);
            imageDetails.reach = static_cast<int8_t>(FX::readPendingUInt8() * direction);
            imageDetails.toe = static_cast<int8_t>(FX::readPendingUInt8() * direction);
            imageDetails.heel = static_cast<int8_t>(FX::readPendingUInt8() * direction);
            FX::readEnd();

            if (imageDetails.toe == -Constants::InAir)              imageDetails.toe = Constants::InAir;
            if (imageDetails.toe == -Constants::InAir_DoNotFall)    imageDetails.toe = Constants::InAir_DoNotFall;

        }

};