#pragma once

#include <Arduboy2.h>   
#include "../utils/Constants.h"
#include "../utils/Stack.h"

struct Prince {

    private:

        Stack <int16_t, 30>  *stack;
        
        uint8_t hangingCounter = 0;
        uint8_t stance = STANCE_UPRIGHT;

        Direction direction = Direction::Left;
        bool falling = false;

        int16_t x = 0;
        int16_t y = 0;
        int16_t prevY = 0;

        Point location;

    public:

        uint8_t getStance()                         { return this->stance; }
        int16_t getX()                              { return this->x; }
        int16_t getY()                              { return this->y; }
        int16_t getYPrevious()                      { return this->prevY; }
        int16_t getXImage()                         { return this->x - 18 + 2; }
        int16_t getYImage()                         { return this->y - 31; }
        uint8_t getHangingCounter()                 { return this->hangingCounter; }
        bool isFalling()                            { return this->falling; }
        Point &getPosition()                        { return this->location; }

        Stack <int16_t, 30>  * getStack()           { return this->stack; }
        Direction getDirection()                    { return this->direction; }

        void setStack(Stack <int16_t, 30>  *val)    { this->stack = val; }
        void setStance(uint8_t val)                 { this->stance = val; }
        void setDirection(Direction val)            { this->direction = val; }
        void setFalling(bool val)                   { this->falling = val; }
        void setHangingCounter(uint8_t val)         { this->hangingCounter = val; }


        void init(int16_t x, int16_t y, Direction direction, uint8_t stance) {

            this->x = x;
            this->y = y;
            this->prevY = y;
            this->direction = direction;
            this->stance = stance;

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
            return this->stack->push(static_cast<int16_t>(item), resetFrame);
        }

        bool push(int16_t item1, int16_t item2, bool resetFrame) {
            return this->stack->push(static_cast<int16_t>(item1), static_cast<int16_t>(item2), resetFrame);
        }

        bool push(int16_t item1, int16_t item2, int16_t item3, bool resetFrame) {
            return this->stack->push(static_cast<int16_t>(item1), static_cast<int16_t>(item2), static_cast<int16_t>(item3), resetFrame);
        }

        void pushSequence(uint8_t fromStance, uint8_t toStance, bool resetFrame) {

            pushSequence(fromStance, toStance, STANCE_NONE, resetFrame);

        }

        void pushSequence(uint8_t fromStance, uint8_t toStance, uint8_t finalStance, bool resetFrame) {

            if (finalStance != STANCE_NONE) {
                this->push(finalStance, resetFrame);
            }

            #if defined(DEBUG) && defined(DEBUG_PRINCE_STACK)
            DEBUG_PRINT("Add to Stack ");
            DEBUG_PRINT(toStance);
            DEBUG_PRINT(" to ");
            DEBUG_PRINT(fromStance);
            DEBUG_PRINT(", count ");
            DEBUG_PRINT(this->stack->getCount());
            DEBUG_PRINT(" ");  
            #endif
            
            if (fromStance < toStance) {

                for (uint8_t x = toStance; x >= fromStance; x--) {

                    #if defined(DEBUG) && defined(DEBUG_PRINCE_STACK)
                    DEBUG_PRINT(x); 
                    DEBUG_PRINT(" ");                         
                    #endif

                    this->stack->push(static_cast<int16_t>(x), resetFrame);
                }

            }
            else {


                // this->stack->clear();

                for (uint8_t x = toStance; x <= fromStance; x++) {

                    #if defined(DEBUG) && defined(DEBUG_PRINCE_STACK)
                    DEBUG_PRINT(-x); 
                    DEBUG_PRINT(" ");                         
                    #endif

                    this->stack->push(static_cast<int16_t>(-x), resetFrame);
                }

            }

            #if defined(DEBUG) && defined(DEBUG_PRINCE_STACK)
            DEBUG_PRINT(", count ");
            DEBUG_PRINTLN(this->stack->getCount());
            #endif

        }

        int16_t pop(void) {

            int16_t retValue = this->stack->pop();

            switch (retValue) {

                case STANCE_JUMP_UP_A_14_END:
                case STANCE_JUMP_UP_B_14_END:
                    this->hangingCounter = 40;
                    break;
                    
            }

            return retValue;

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

    	void update(uint8_t xLoc, uint8_t yLoc) {

            // Housekeeping ..

            if (this->hangingCounter > 0) {
                this->hangingCounter--;
            }

            this->stack->update();

            location.x = (xLoc * 12) + this->x;
            location.y = (yLoc * 31) + this->y;

        }

    	uint8_t getStackFrame() {
            return this->stack->getFrame();
        }

    	void setStackFrame(uint8_t val) {
            return this->stack->setFrame(val);
        }


        // ----------------------------------------------------------------------------------------------------------

        void stepForwardOne() {

            this->pushSequence(STANCE_STEP_FWD_ONE_1_START, STANCE_STEP_FWD_ONE_6_END, STANCE_UPRIGHT, true);

        }

        void stepForwardTwo() {

            this->pushSequence(STANCE_STEP_FWD_TWO_1_START, STANCE_STEP_FWD_TWO_6_END, STANCE_UPRIGHT, true);

        }

        void climbUpwards() {

            this->pushSequence(STANCE_CLIMBING_1_START, STANCE_CLIMBING_15_END, STANCE_UPRIGHT_END_CLIMB, true);

        }


};