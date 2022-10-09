#pragma once

#include <Arduboy2.h>   
#include "../utils/Constants.h"
#include "../utils/Stack.h"

struct Prince {

    private:

        // Action action = Action::StandingUpright;
        Stack <uint8_t, 20> *stack;
        
        // int16_t index = 0;
        // uint8_t actionCounter = 0;
        uint8_t idleFrame = 0;
        uint8_t stance = STANCE_UPRIGHT;
        Direction direction = Direction::Left;
        bool falling = false;

        int16_t x = 0;
        int16_t y = 0;

    public:

        uint8_t getStance()                         { return this->stance; }
        int16_t getX()                              { return this->x; }
        int16_t getY()                              { return this->y; }
        int16_t getXImage()                         { return this->x - 18 + 2; }
        int16_t getYImage()                         { return this->y - 31; }
        bool isFalling()                            { return this->falling; }

        Stack <uint8_t, 20> * getStack()            { return this->stack; }
        Direction getDirection()                    { return this->direction; }

        void setStack(Stack <uint8_t, 20> *val)     { this->stack = val; }
        void setStance(uint8_t val)                 { this->stance = val; }
        void setDirection(Direction val)            { this->direction = val; }
        void setFalling(bool val)                   { this->falling = val; }


        void init(int16_t x, int16_t y) {

            this->x = x;
            this->y = y;

        }

        void incX(int8_t x) {

            this->x = this->x + x;
            
        }

        void incY(int8_t y) {

            this->y = this->y + y;
            
        }

        void changeDirection() {

            // switch (this->direction) {

            //     case Direction::Left:

            //     case Direction::Right:
            // }

            this->direction = (this->direction == Direction::Left ? Direction::Right : Direction::Left);

        }


      	uint8_t getCount(void) {
            return this->stack->getCount();
        }


        uint8_t & peek(void) {
            return this->stack->peek();
        }

        const uint8_t & peek(void) const {
            return this->stack->peek();
        }

        bool insert(const uint8_t & item) {
            this->idleFrame = 0;
            return this->stack->insert(item);
        }

        bool push(uint8_t item, bool resetFrame) {
            this->idleFrame = 0;
            return this->stack->push(static_cast<uint8_t>(item), resetFrame);
        }

        bool push(uint8_t item1, uint8_t item2, bool resetFrame) {
            this->idleFrame = 0;
            return this->stack->push(static_cast<uint8_t>(item1), static_cast<uint8_t>(item2), resetFrame);
        }

        bool push(uint8_t item1, uint8_t item2, uint8_t item3, bool resetFrame) {
            this->idleFrame = 0;
            return this->stack->push(static_cast<uint8_t>(item1), static_cast<uint8_t>(item2), static_cast<uint8_t>(item3), resetFrame);
        }

        void pushSequence(uint8_t fromStance, uint8_t toStance, bool resetFrame) {

            // this->idleFrame = 0;

            // for (uint8_t x = toStance; x >= fromStance; x--) {
            //     this->stack->push(static_cast<uint8_t>(x), resetFrame);
            // }

            pushSequence(fromStance, toStance, STANCE_NONE, resetFrame);

        }

        void pushSequence(uint8_t fromStance, uint8_t toStance, uint8_t finalStance, bool resetFrame) {

            this->idleFrame = 0;

            if (finalStance != STANCE_NONE) {
                this->push(finalStance, resetFrame);
            }

            if (fromStance < toStance) {

                for (uint8_t x = toStance; x >= fromStance; x--) {
                    this->stack->push(static_cast<uint8_t>(x), resetFrame);
                }

            }
            else {

                for (uint8_t x = fromStance; x >= toStance; x--) {

Serial.println(x);
                    this->stack->push(static_cast<uint8_t>(x), resetFrame);
                }

            }

        }

        uint8_t & pop(void) {
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

    	bool contains(const uint8_t & item) {
            return this->stack->contains(item);
        }

    	void update() {
            this->stack->update();
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