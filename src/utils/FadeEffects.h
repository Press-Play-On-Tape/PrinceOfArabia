#pragma once

#include "Arduboy2Ext.h"

class FadeEffects {

    private:
        uint8_t fadeWidth = WIDTH;

    public:	

        void complete(void) {
            this->fadeWidth = 0;
        }

        void reset(void) {
            this->fadeWidth = WIDTH;
        }

        bool isComplete(void) const {
            return (this->fadeWidth == 0);
        }

        void update(void) {

            if (this->fadeWidth >= 3){
                this->fadeWidth = this->fadeWidth - 3;
            }
            else {
                this->fadeWidth = 0;
            }

        }

        void draw(Arduboy2Ext & arduboy) const {

            for(uint8_t i = 0; i < (HEIGHT / 2); ++i) {

                arduboy.drawFastHLine(0, (i * 2), this->fadeWidth, BLACK);
                arduboy.drawFastHLine((WIDTH - this->fadeWidth), (i * 2) + 1, this->fadeWidth, BLACK);

            }

        }

};
