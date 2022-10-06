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

        int8_t bg[3][15];
        int8_t fg[3][15];

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

        int8_t coordToTileIndexX(Direction direction, int16_t x) {

            switch (direction) {

                case Direction::Left:
                    return (x / 12);                

                case Direction::Right:
                    return (x / 12) + 1;

                default:
                    return 255;
                    
            }

        }

        int8_t coordToTileIndexY(Direction direction, int16_t y) {

            switch (direction) {

                case Direction::Left:
                    return (y / 31);                

                case Direction::Right:
                    return (y / 31) + 1;

                default:
                    return 255;
                    
            }

        }

        int8_t distToEdgeOfTile(Direction direction, int16_t x) {

            int8_t tile = coordToTileIndexX(direction, x);

            switch (direction) {

                case Direction::Left:
                    return x - (tile * 12);         

                case Direction::Right:
                    return (tile * 12) - x;

                default:
                    return 255;
                    
            }

        }

        int8_t getTile(Layer layer, int8_t x, int8_t y) { 

            if (x < 0)      return 255;         // SJH
            if (x >= 100)   return 255;         // SJH

            if (y < 0)      return 255;         // SJH
            if (y >= 100)   return 255;         // SJH

            switch (layer) {

                case Layer::Foreground:
                    return fg[y][x + 2];

                case Layer::Background:
                    return bg[y][x + 2];


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

                for (uint8_t x = 0; x < 15; x++) {

                    Serial.print(bg[y][x]);
                    Serial.print(" ");

                }

                Serial.println("");

            }


            Serial.println("FG ---------------");

            for (uint8_t y = 0; y < 3; y++) {

                for (uint8_t x = 0; x < 15; x++) {

                    Serial.print(fg[y][x]);
                    Serial.print(" ");

                }

                Serial.println("");

            }

        }


        void loadMap() {


            // Background ..

            for (uint8_t y = this->yLoc; y < yLoc + 3; y++) {

                FX::seekData(static_cast<uint24_t>(Levels::Level1_BG + (y * Levels::Level1_Width) + this->xLoc - 2));

                for (uint8_t x = 0; x < 15; x++) {

                    int8_t tileId = static_cast<int8_t>(FX::readPendingUInt8());
                    bg[y - this->yLoc][x] = tileId;

                }

                FX::readEnd();

            }


            // Foreground ..

            for (uint8_t y = this->yLoc; y < this->yLoc + 3; y++) {

                FX::seekData(static_cast<uint24_t>(Levels::Level1_FG + (y * Levels::Level1_Width) + this->xLoc - 2));

                for (uint8_t x = 0; x < 15; x++) {

                    int8_t tileId = static_cast<int8_t>(FX::readPendingUInt8());
                    fg[y - this->yLoc][x] = tileId;

                }

                FX::readEnd();

            }

            //printMap();

        }



        bool canMoveForward(Action action, Prince prince) {

            Point player;

            player.x = (this->xLoc * 12) + prince.getX();
            player.y = (this->yLoc * 31) + prince.getY();

            switch (prince.getDirection()) {

                case Direction::Left:
                    {

                        int8_t tileXIdx = this->coordToTileIndexX(prince.getDirection(), player.x);
                        int8_t tileYIdx = this->coordToTileIndexY(prince.getDirection(), player.y);

                        uint8_t bgTile1 = this->getTile(Layer::Background, tileXIdx, tileYIdx);
                        uint8_t bgTile2 = this->getTile(Layer::Background, tileXIdx - 1, tileYIdx);

                        uint8_t fgTile1 = this->getTile(Layer::Foreground, tileXIdx, tileYIdx);
                        uint8_t fgTile2 = this->getTile(Layer::Foreground, tileXIdx - 1, tileYIdx);


                        switch (action) {

                            case Action::SmallStep:

                                // if (this->isSolid(bgTile1, fgTile1)) {


                                // }

                                break;


                        }


                    }


                    break;


            }





            return true;
        }

};