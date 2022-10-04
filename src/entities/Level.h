#pragma once

#include <Arduboy2.h>   
#include "Prince.h"   
#include "../utils/Constants.h"
#include "../utils/Stack.h"

struct Level {

    private:

        uint8_t level = 0;
        uint8_t xLoc = 60;
        uint8_t yLoc = 0;

        int8_t bg[3][11];
        int8_t fg[3][11];

    public:

        uint8_t getLevel()                      { return this->level; }
        uint8_t getXLocation()                  { return this->xLoc; }
        uint8_t getYLocation()                  { return this->yLoc; }

        void setLevel(uint8_t val)              { this->level = val; }
        void setXLocation(uint8_t val)          { this->xLoc = val; }
        void setYLocation(uint8_t val)          { this->yLoc = val; }


    public:

        void init(uint8_t xLoc, uint8_t yLoc) {

            this->xLoc = xLoc;
            this->yLoc = yLoc;

            this->loadMap();
        }

        int8_t getTile(Layer layer, uint8_t x, uint8_t y) { 
            
            switch (layer) {

                case Layer::Foreground:
                    return fg[y][x];

                case Layer::Background:
                    return bg[y][x];


            }

        }

        void printMap() {

            Serial.println("Map ---------------");
            Serial.print("xLoc: ");
            Serial.print(xLoc);
            Serial.print(", yLoc: ");
            Serial.println(yLoc);

            Serial.println("BG ---------------");

            for (uint8_t y = 0; y < 3; y++) {

                for (uint8_t x = 0; x < 11; x++) {

                    Serial.print(bg[y][x]);
                    Serial.print(" ");

                }

                Serial.println("");

            }


            Serial.println("FG ---------------");

            for (uint8_t y = 0; y < 3; y++) {

                for (uint8_t x = 0; x < 11; x++) {

                    Serial.print(fg[y][x]);
                    Serial.print(" ");

                }

                Serial.println("");

            }

        }


        void loadMap() {


            // Background ..

            for (uint8_t y = this->yLoc; y < yLoc + 3; y++) {

                FX::seekData(static_cast<uint24_t>(Levels::Level1_BG + (y * Levels::Level1_Width) + this->xLoc));

                for (uint8_t x = 0; x < 11; x++) {

                    int8_t tileId = static_cast<int8_t>(FX::readPendingUInt8());
                    bg[y - this->yLoc][x] = tileId;

                }

                FX::readEnd();

            }


            // Foreground ..

            for (uint8_t y = this->yLoc; y < this->yLoc + 3; y++) {

                FX::seekData(static_cast<uint24_t>(Levels::Level1_FG + (y * Levels::Level1_Width) + this->xLoc));

                for (uint8_t x = 0; x < 11; x++) {

                    int8_t tileId = static_cast<int8_t>(FX::readPendingUInt8());
                    fg[y - this->yLoc][x] = tileId;

                }

                FX::readEnd();

            }

            //printMap();

        }



        bool canMoveForward(Action action, Prince prince) {
            return true;
        }

};