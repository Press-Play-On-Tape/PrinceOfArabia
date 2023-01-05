#pragma once

#include <Arduboy2.h>   
#include "../utils/Constants.h"
#include "../utils/Stack.h"
#include "../entities/Structs.h"

class BaseStack {

    protected:

        Stack <int16_t, Constants::StackSize>  *stack;
        
    public:

        Stack <int16_t, Constants::StackSize>  * getStack()           { return this->stack; }

        void setStack(Stack <int16_t, Constants::StackSize>  *val)    { this->stack = val; }


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
            offset.x = static_cast<int8_t>(pgm_read_byte(&Constants::Stance_XYOffsets[(item - 1) * 2]));
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
                offset.x = static_cast<int8_t>(pgm_read_byte(&Constants::Stance_XYOffsets[(finalStance - 1) * 2]));
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
                    offset.x = static_cast<int8_t>(pgm_read_byte(&Constants::Stance_XYOffsets[(x - 1) * 2]));
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
                    offset.x = static_cast<int8_t>(pgm_read_byte(&Constants::Stance_XYOffsets[(x - 1) * 2]));
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

      	uint8_t getCount(void) {
            return this->stack->getCount();
        }

};