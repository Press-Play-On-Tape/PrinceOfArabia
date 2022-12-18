#pragma once

#include <Arduboy2.h>   
#include "../utils/Constants.h"
#include "../utils/Stack.h"
#include "../entities/Structs.h"

class BaseEntity {

    protected:

        Stack <int16_t, Constants::StackSize>  *stack;
        
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

        Stack <int16_t, Constants::StackSize>  * getStack()           { return this->stack; }
        Direction getDirection()                    { return this->direction; }

        void setStack(Stack <int16_t, Constants::StackSize>  *val)    { this->stack = val; }
        void setStance(uint16_t val)                { this->stance = val; }
        void setPrevStance(uint16_t val)            { this->prevStance = val; }
        void setX(int16_t val)                      { this->x = val; }
        void setY(int16_t val)                      { this->y = val; }
        void setDirection(Direction val)            { this->direction = val; }
        void setHealth(uint8_t val)                 { this->health = val; }
        void setHealthMax(uint8_t val)              { this->healthMax = val; }

        uint8_t decHealth(uint8_t val)              { this->health >= val ? this->health = this->health - val: 0; return this->health;}
        void incHealth(int8_t val)                  { this->health = this->health + val > this->healthMax ? this->healthMax : this->health + val; } 

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

      	uint8_t getCount(void) {
            return this->stack->getCount();
        }


        int16_t & peek(void) {
            return this->stack->peek();
        }

        const int16_t & peek(void) const {
            return this->stack->peek();
        }

        bool insert(const int16_t & item) {
            return this->stack->insert(item);
        }

        bool push(int16_t item, bool resetFrame) {

            #if defined(DEBUG) && defined(DEBUG_PRINCE_STACK)
            Point offset;
            offset.x = static_cast<int8_t>(pgm_read_byte(&Constants::Prince_XOffset[(item - 1) * 2]));
            DEBUG_PRINT(F("Prince X: "));
            DEBUG_PRINT(this->x % 12);
            DEBUG_PRINT(F(", Item "));
            DEBUG_PRINT(item);
            DEBUG_PRINT(F(", count "));
            DEBUG_PRINT(this->stack->getCount());
            DEBUG_PRINT(F(" ("));  
            DEBUG_PRINT(offset.x);  
            DEBUG_PRINTLN(F(")"));  
            #endif

            return this->stack->push(static_cast<int16_t>(item), resetFrame);
        }

        void pushSequence(uint16_t fromStance, uint16_t toStance, bool resetFrame) {

            this->pushSequence(fromStance, toStance, Stance::None, resetFrame);

        }

        void pushSequence(uint16_t fromStance, uint16_t toStance, uint16_t finalStance, bool resetFrame) {

            #if defined(DEBUG) && defined(DEBUG_PRINCE_STACK)
            int8_t xOffset = 0;
            Point offset;
            DEBUG_PRINT(F("Prince X: "));
            DEBUG_PRINT(this->x % 12);
            #endif

            if (finalStance != Stance::None) {

                #if defined(DEBUG) && defined(DEBUG_PRINCE_STACK)
                offset.x = static_cast<int8_t>(pgm_read_byte(&Constants::Prince_XOffset[(finalStance - 1) * 2]));
                xOffset = offset.x;
                DEBUG_PRINT(F(", Final "));
                DEBUG_PRINT(finalStance);
                #endif

                this->stack->push(static_cast<int16_t>(finalStance), resetFrame);
            }

            #if defined(DEBUG) && defined(DEBUG_PRINCE_STACK)
            DEBUG_PRINT(F(", Seq "));
            DEBUG_PRINT(toStance);
            DEBUG_PRINT(F(" to "));
            DEBUG_PRINT(fromStance);
            DEBUG_PRINT(" - ");  
            #endif
            
            if (fromStance < toStance) {

                for (uint16_t x = toStance; x >= fromStance; x--) {

                    #if defined(DEBUG) && defined(DEBUG_PRINCE_STACK)
                    DEBUG_PRINT(x); 
                    DEBUG_PRINT(" ");        
                    offset.x = static_cast<int8_t>(pgm_read_byte(&Constants::Prince_XOffset[(x - 1) * 2]));
                    xOffset = xOffset + offset.x;
                    #endif

                    this->stack->push(static_cast<int16_t>(x), resetFrame);

                }

            }
            else {


                // this->stack->clear();

                for (uint16_t x = toStance; x <= fromStance; x++) {

                    #if defined(DEBUG) && defined(DEBUG_PRINCE_STACK)
                    DEBUG_PRINT(x); 
                    DEBUG_PRINT(" ");                         
                    offset.x = static_cast<int8_t>(pgm_read_byte(&Constants::Prince_XOffset[(x - 1) * 2]));
                    xOffset = xOffset + offset.x;
                    #endif

                    this->stack->push(static_cast<int16_t>(-x), resetFrame);
                }

            }

            #if defined(DEBUG) && defined(DEBUG_PRINCE_STACK)
            DEBUG_PRINT(F(", count "));
            DEBUG_PRINT(this->stack->getCount());
            DEBUG_PRINT(F(" ("));
            DEBUG_PRINT(xOffset);
            DEBUG_PRINTLN(F(")"));
            #endif

        }

        int16_t pop(void) {
            return this->stack->pop();
        }

        bool isEmpty(void) {
            return this->stack->isEmpty();
        }

    	bool isFull(void) {
            return this->stack->isFull();
        }

    	void clear(void) {
            this->stack->clear();
        }

    	bool contains(const int16_t & item) {
            return this->stack->contains(item);
        }

    	uint8_t getStackFrame() {
            return this->stack->getFrame();
        }

    	void setStackFrame(uint8_t val) {
            return this->stack->setFrame(val);
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
            uint24_t startPos = static_cast<uint24_t>(Constants::Prince_ImageDetails + ((imageIndex - 1) * 3));
            int8_t direction = this->getDirection() == Direction::Left ? -1 : 1;

            FX::seekData(startPos);
            imageDetails.reach = static_cast<int8_t>(FX::readByte() * direction);
            imageDetails.toe = static_cast<int8_t>(FX::readByte() * direction);
            imageDetails.heel = static_cast<int8_t>(FX::readByte() * direction);
            FX::readEnd();

            if (imageDetails.toe == -Constants::InAir)              imageDetails.toe = Constants::InAir;
            if (imageDetails.toe == -Constants::InAir_DoNotFall)    imageDetails.toe = Constants::InAir_DoNotFall;

        }

};