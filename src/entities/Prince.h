#pragma once

#include <Arduboy2.h>   
#include "../utils/Constants.h"
#include "../utils/Stack.h"

struct Prince {

    private:

        // Action action = Action::StandingUpright;
        Stack <uint8_t, 15> *stack;
        
        // int16_t index = 0;
        uint8_t actionCounter = 0;
        uint8_t idleFrame = 0;
        uint8_t stance = STANCE_UPRIGHT;
        Direction direction = Direction::Left;
        bool falling = false;



        //                                                                             1                                       2                                       3                                       4                                       5                                       6                                       7                                       8                                       9                                       0                                       1                                       2                                       3                                       4                                       5                                       6                                       7
        //                                     0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9,0,  1,  2,  3,  4,  5,  6,  7,  8,  9,

        // const int8_t xOffset[173] =         {  0,  1,  1,  0,  0,  0,  0, -5, -8,  0, -1, -6, -8,  2,  0, -2,  4, -6, -4, -2, -1, -8,  9, -1, -2,  0,  1, -4,  0,  0,  0,  0,  1,  0,  1,  3,  4,  5,  4,  5,  0, -1,  0,  2,  1, -5,  -1, 2,  0,  0,  0,  0, -3,  1,  0,  3,  4,  4, -3, -7, -5, -1,  0,  0,  0,  0,  0,  0,  0,  0,  0, -1, -2, -9,-11, -6, -3,  0,  2,  2,  6,  0,  0, -2, -2, -9,-10,-10, -2,  2, -5, -4,  0,  0, -7, -7, -8, -9,  0,  0,  1, -2,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, -1, -2, -9,-11, -6, -3,  0,  2,  4,  3,  2,  1,  0,  1,  3,  4,  5,  4,  5,  0, -1, -1, -1,  1,  1,  2,  2,  0,  0, -2, -2, -3, -3, -7, -7,  0,  0,  2, -5, -5, -5, -5, -5,  0, -3, -3,  1,  2,  3, -1, -4, -6, -2, -1, -1, -2, -3, -3, };
        // const int8_t height[173] =          { 40, 40, 40, 40, 39, 38, 39, 39, 40, 39, 38, 39, 40, 38, 39, 40, 39, 39, 38, 39, 39, 38, 40, 43, 42, 41, 40, 40, 32, 48, 54, 60, 59, 61, 63, 67, 69, 72, 75, 78, 88, 40, 39, 38, 37, 37, 39, 40, 40, 40, 40, 40, 29, 23, 19, 21, 23, 25, 29, 32, 35, 39, 25,  9, 7,  -1, -8, -9, 21, 23, 25, 40, 40, 39, 39, 37, 35, 32, 38, 49, 51, 40, 40, 39, 40, 40, 39, 39, 40, 39, 39, 38, 37, 32, 35, 36, 37, 36, 40, 39, 40, 39, 40, 40, 40, 39, 40, 39, 40, 40, 25,  0, 37, 37, 40, 40, 39, 39, 37, 35, 32, 38, 48, 54, 60, 59, 61, 63, 67, 69, 72, 75, 78, 88, 23, 32, 32, 40, 40, 44, 44, 44, 44, 42, 42, 43, 43, 41, 41, 44, 44, 41, 19, 19, 19, 19, 19, 40, 39, 31, 31, 32, 34, 36, 35, 34, 26, 24, 29, 32, 39, 39, };
        // const uint8_t xMovement[173] =      {  0,  0,  1,  2,  3,  4,  5,  6,  6,  6,  6,  6,  6,  6,  5,  4,  3,  2,  1,  0,  0,  6,  7,  8,  9,  9,  9,  8,  7,  0,  0,  0,  0,  0,  0,  2,  2,  2,  2,  2,  1,  0,  0,  1,  1,  1,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  2,  2,  2,  0,  0,  0,  2,  2,  2,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  2,  2,  2,  2,  2,  4,  3,  2,  1,  0,  0,  0,  0,  0,  0,  0,  0,  2,  2,  0,  0,  0,  1,  2,  2,  0,  0,  4,  0,  4,  4,  0,  0,  0,  0,  0,  0,  2,  2,  2,  2,  1,  0,  0,  0,  2,  2,  2,  2,  2,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  5,  6,  6,  6,  5,  0,  0,  0,  0,  1,  4,  7,  8,  8,  7,  5,  3,  2,  0,  0, };
        // const int8_t yMovement[173] =       {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 10,  8,  7,  6,  4,  2,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,-10,-10,-10,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, -8, -9, -9, -8,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 10,  8,  7,  6,  4,  2,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, };
        // const uint8_t footWidthStart[173] = {  2,  0,  1,  1,  1,  6,  4,  3, 19,  9,  4,  3, 19,  3,  4, 20, 10, 31, 17,  5,  0, 30,  3,  4, 99, 99, 99, 99, 17,  6,  4,  4,  1,  3,  3,  3,  8,  4,  7,  3,  1,  2,  4,  1,  1,  0,  9,  3,  1,  0, 13,  9,  8,  6,  5,  4,  3,  3, 10, 10, 11,  2, 11,  2,  9,  3, 12,  7,  4,  3,  3,  2,  3, 10, 12,  7,  4,  2,  3,  3, 99,  0,  0, 99, 99, 99, 99, 99, 20, 10, 31, 17, 10,  6, 25, 26, 25, 23,  2,  4,  1,  9,  3,  1,  2,  4,  1,  9,  3,  1, 11, 11, 11, 11,  2,  3, 10, 12,  7,  4,  2,  3,  6,  4,  4,  1,  3,  3,  3,  8,  4,  7,  3,  1,  4,  3,  3,  0,  0,  0,  0,  3, 99, 99, 99, 99, 99, 99,  9,  3,  3,  0,  5,  5,  5,  5,  5,  1,  4,  4,  1,  0, 99, 99, 99, 99, 16,  9,  2, 13,  9,  5, };
        // const uint8_t footWidthEnd[173] =   {  8,  7,  7,  6,  6, 10,  5, 25, 26, 14,  7, 28, 26,  9,  5, 27, 18, 37, 24, 10,  8, 36,  9,  7, 99, 99, 99, 99, 24,  8,  6,  8,  5,  4,  4,  4, 24, 18, 12,  8,  8,  8,  7, 16, 22, 26, 16, 10,  8,  1, 16, 12, 11,  7, 19, 17,  5,  5, 12, 16, 14,  9, 13, 10, 12, 16, 30, 32, 17,  5,  5,  9, 10, 17, 19, 14, 11,  8,  6,  6, 99,  8,  8, 99, 99, 99, 99, 99, 27, 18, 37, 24, 12, 28, 28, 27, 28, 25,  8,  7,  7, 16, 10,  8, 48 , 7,  6, 16, 10,  8, 13, 13, 13, 13,  9, 10, 17, 19, 14, 11,  8,  6,  8,  6,  8,  5,  4,  4,  4, 24, 18, 12,  8,  9, 13, 12, 12, 10, 10, 10, 10, 12, 99, 99, 99, 99, 99, 99, 19, 12, 12, 10, 19, 19, 19, 19, 19,  9, 12, 12,  7,  5, 99, 99, 99, 99, 22, 17, 20, 20, 15, 12, };


        //                                                                             1                                       2                                       3                                       4                                       5                                       6                                       7                                       8                                       9                                       0                                       1                                       2                                       3                                       4                                       5                                       6                                       7
        //                                     0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9,0,  1,  2,  3,  4,  5,  6,  7,  8,  9,

        const int8_t xOffset[1] =         {  0, };
        const int8_t height[1] =          { 40, };
        const uint8_t xMovement[1] =      {  0, };
        const int8_t yMovement[1] =       {  0, };
        const uint8_t footWidthStart[1] = {  2, };
        const uint8_t footWidthEnd[1] =   {  8, };

    public:

        uint8_t getStance()                         { return this->stance; }
        int8_t getXOffset()                         { return this->xOffset[this->stance]; }
        int8_t getHeight()                          { return this->height[this->stance]; }
        uint8_t getXMovement()                      { return this->getStackFrame() == 0 ? this->xMovement[this->stance] : 0; }
        uint8_t getYMovement()                      { return this->getStackFrame() == 0 ? this->yMovement[this->stance] : 0; }
        uint8_t getWidthStart()                     { return this->footWidthStart[this->stance]; }
        uint8_t getWidthEnd()                       { return this->footWidthEnd[this->stance]; }
        bool isFalling()                            { return this->falling; }

        Stack <uint8_t, 15> * getStack()            { return this->stack; }
        Direction getDirection()                    { return this->direction; }

        void setStack(Stack <uint8_t, 15> *val)     { this->stack = val; }
        void setStance(uint8_t val)                 { this->stance = val; }
        void setDirection(Direction val)            { this->direction = val; }
        void setFalling(bool val)                   { this->falling = val; }


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

            this->idleFrame = 0;

            for (uint8_t x = toStance; x >= fromStance; x--) {
                this->stack->push(static_cast<uint8_t>(x), resetFrame);
            }

        }

        void pushSequence(uint8_t fromStance, uint8_t toStance, uint8_t finalStance, bool resetFrame) {

            this->idleFrame = 0;
            this->push(finalStance, resetFrame);

            for (uint8_t x = toStance; x >= fromStance; x--) {
                this->stack->push(static_cast<uint8_t>(x), resetFrame);
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