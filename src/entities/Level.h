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

        int8_t bg[3][14];
        int8_t fg[3][14];

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
                    return (x / 12);

                default:
                    return 255;
                    
            }

        }

        int8_t coordToTileIndexY(Direction direction, int16_t y) {

            switch (direction) {

                case Direction::Left:
                    return (y / 31);                

                case Direction::Right:
                    return (y / 31);

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
                    return ((tile + 1) * 12) - x;

                default:
                    return 255;
                    
            }

        }

        int8_t getTile(Layer layer, int8_t x, int8_t y) { 

            return getTile(layer, x, y, false);

        }

        int8_t getTile(Layer layer, int8_t x, int8_t y, bool print) { 

            // if (x < 0)      return 255;         // SJH
            // if (x >= 100)   return 255;         // SJH

            // if (y < 0)      return 255;         // SJH
            // if (y >= 100)   return 255;         // SJH

            switch (layer) {

                case Layer::Foreground:
                    // if (print) {
                    //     Serial.print("getTile(FG, ");
                    //     Serial.print(x);
                    //     Serial.print(",");
                    //     Serial.print(y);
                    //     Serial.print(") = ");
                    //     Serial.println(fg[y][x + 2]);
                    // }
                    return fg[y][x + 2];

                case Layer::Background:
                    // if (print) {
                    //     Serial.print("getTile(BG, ");
                    //     Serial.print(x);
                    //     Serial.print(",");
                    //     Serial.print(y);
                    //     Serial.print(") = ");
                    //     Serial.println(bg[y][x + 2]);
                    // }
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

                for (uint8_t x = 0; x < 14; x++) {

                    Serial.print(bg[y][x]);
                    Serial.print(" ");

                    if (x == 1 || x == 11) {
                        Serial.print("| ");
                    }

                }

                Serial.println("");

            }


            Serial.println("FG ---------------");

            for (uint8_t y = 0; y < 3; y++) {

                for (uint8_t x = 0; x < 14; x++) {

                    Serial.print(fg[y][x]);
                    Serial.print(" ");

                    if (x == 1 || x == 11) {
                        Serial.print("| ");
                    }

                }

                Serial.println("");

            }

        }


        void loadMap() {


            // Background ..

            for (uint8_t y = this->yLoc; y < yLoc + 3; y++) {

                FX::seekData(static_cast<uint24_t>(Levels::Level1_BG + (y * Levels::Level1_Width) + this->xLoc - 2));

                for (uint8_t x = 0; x < 14; x++) {

                    int8_t tileId = static_cast<int8_t>(FX::readPendingUInt8());
                    bg[y - this->yLoc][x] = tileId;

                }

                FX::readEnd();

            }


            // Foreground ..

            for (uint8_t y = this->yLoc; y < this->yLoc + 3; y++) {

                FX::seekData(static_cast<uint24_t>(Levels::Level1_FG + (y * Levels::Level1_Width) + this->xLoc - 2));

                for (uint8_t x = 0; x < 14; x++) {

                    int8_t tileId = static_cast<int8_t>(FX::readPendingUInt8());
                    fg[y - this->yLoc][x] = tileId;

                }

                FX::readEnd();

            }

            printMap();

        }

        #define TILE_FLOOR_BASIC 77
        #define TILE_FLOOR_LH_END 76
        #define TILE_FLOOR_PATTERN 78
        #define TILE_FLOOR_LH_END_PATTERN_1 102
        #define TILE_FLOOR_LH_END_PATTERN_2 93
        #define TILE_FLOOR_RH_END 99

        #define TILE_FLOOR_LH_WALL_1 83
        #define TILE_FLOOR_LH_WALL_2 109
        #define TILE_FLOOR_LH_WALL_3 113

        #define TILE_FG_WALL_1 80
        #define TILE_FG_WALL_2 81
        #define TILE_FG_WALL_3 82
        #define TILE_FG_WALL_4 86
        #define TILE_FG_WALL_5 87
        #define TILE_FG_WALL_6 88

        #define TILE_COLUMN_LH_WALL 100
        #define TILE_COLUMN_1 84
        #define TILE_COLUMN_2 112
        #define TILE_COLUMN_3 96
        #define TILE_COLUMN_4 89
        #define TILE_COLUMN_5 101

        #define TILE_COLUMN_REAR_1 104
        #define TILE_COLUMN_REAR_2 90


        bool isWallTile(uint8_t bgTile, uint8_t fgTile) {

            switch (bgTile) {

                case TILE_FG_WALL_1:
                case TILE_FG_WALL_2:
                case TILE_FG_WALL_3:
                case TILE_FG_WALL_4:
                case TILE_FG_WALL_5:
                case TILE_FG_WALL_6:
                    return true;


                default: return false;

            }

        }

        bool isGroundTile(uint8_t bgTile, uint8_t fgTile) {

// Serial.print("isGroundTile(");
// Serial.print(bgTile);
// Serial.print(",");
// Serial.print(fgTile);
// Serial.print(") ");

            switch (bgTile) {

                case TILE_FLOOR_BASIC:
                case TILE_FLOOR_LH_END:
                case TILE_FLOOR_PATTERN:
                case TILE_FLOOR_LH_END_PATTERN_1:
                case TILE_FLOOR_LH_END_PATTERN_2:
                case TILE_FLOOR_RH_END:
                case TILE_FLOOR_LH_WALL_1:
                case TILE_FLOOR_LH_WALL_2:
                case TILE_FLOOR_LH_WALL_3:
                case TILE_COLUMN_LH_WALL:
                case TILE_COLUMN_1:
                case TILE_COLUMN_2:
                case TILE_COLUMN_3:
                case TILE_COLUMN_4:
                case TILE_COLUMN_5:
                case TILE_COLUMN_REAR_1:
                case TILE_COLUMN_REAR_2:
                // Serial.println(" true (1)");
                    return true;

            }

            switch (fgTile) {

                case TILE_FG_WALL_1:
                case TILE_FG_WALL_2:
                case TILE_FG_WALL_3:
                case TILE_FG_WALL_4:
                case TILE_FG_WALL_5:
                case TILE_FG_WALL_6:
                // Serial.println(" false (2)");
                    return false;

            }

            return false;

        }



        bool canMoveForward(Action action, Prince prince) {

            Point player;

            player.x = (this->xLoc * 12) + prince.getX();
            player.y = (this->yLoc * 31) + prince.getY();

            switch (prince.getDirection()) {

                case Direction::Left:
                    {

                        int8_t tileXIdx = this->coordToTileIndexX(prince.getDirection(), player.x) - this->getXLocation();
                        int8_t tileYIdx = this->coordToTileIndexY(prince.getDirection(), player.y) - this->getYLocation();
Serial.print("coordToTileIndexX ");
Serial.print(player.x);
Serial.print(" = ");
Serial.print(tileXIdx);
Serial.print(", coordToTileIndexY ");
Serial.print(player.y);
Serial.print(" = ");
Serial.println(tileYIdx);

                        int8_t bgTile1 = this->getTile(Layer::Background, tileXIdx, tileYIdx, true);
                        int8_t bgTile2 = this->getTile(Layer::Background, tileXIdx - 1, tileYIdx, true);
                        int8_t bgTile3 = this->getTile(Layer::Background, tileXIdx - 2, tileYIdx, true);
                        int8_t bgTile4 = this->getTile(Layer::Background, tileXIdx - 3, tileYIdx, true);

                        int8_t fgTile1 = this->getTile(Layer::Foreground, tileXIdx, tileYIdx, true);
                        int8_t fgTile2 = this->getTile(Layer::Foreground, tileXIdx - 1, tileYIdx, true);
                        int8_t fgTile3 = this->getTile(Layer::Foreground, tileXIdx - 2, tileYIdx, true);
                        int8_t fgTile4 = this->getTile(Layer::Foreground, tileXIdx - 3, tileYIdx, true);
                        
                        int8_t distToEdgeOfCurrentTile = distToEdgeOfTile(prince.getDirection(), player.x);

Serial.print("dist ");
Serial.print(distToEdgeOfCurrentTile);
Serial.print(", bg ");
Serial.print(bgTile4);
Serial.print(" ");
Serial.print(bgTile3);
Serial.print(" ");
Serial.print(bgTile2);
Serial.print(" ");
Serial.print(bgTile1);
Serial.print(", fg ");
Serial.print(fgTile4);
Serial.print(" ");
Serial.print(fgTile3);
Serial.print(" ");
Serial.print(fgTile2);
Serial.print(" ");
Serial.print(fgTile1);
Serial.println("");
                        switch (action) {

                            case Action::SmallStep:

                                switch (distToEdgeOfCurrentTile) {

                                    case 0 ... 5:
                                         return this->isGroundTile(bgTile2, fgTile2);

                                    default:
                                        return true;

                                }

                                break;

                            case Action::Step:
                            case Action::RunStart:

                                switch (distToEdgeOfCurrentTile) {

                                    case 0 ... 9:
                                         return this->isGroundTile(bgTile2, fgTile2);

                                    default:
                                        return true;

                                }

                                break;

                            case Action::RunRepeat:

                                return this->isGroundTile(bgTile2, fgTile2);

                            case Action::StandingJump:

                                switch (distToEdgeOfCurrentTile) {

                                    case  2 ... 12:

                                        if (this->isGroundTile(bgTile2, fgTile2) && this->isGroundTile(bgTile3, fgTile3) && this->isGroundTile(bgTile4, fgTile4)) {
                                            return true;                                            
                                        }

                                        return false;

                                    default:

                                        if (this->isGroundTile(bgTile2, fgTile2) && this->isGroundTile(bgTile3, fgTile3)) {
                                            return true;                                            
                                        }

                                        return false;

                                }

                                return true;

                            default: return false;

                        }

                    }

                    break;

                case Direction::Right:
                    {

                        int8_t tileXIdx = this->coordToTileIndexX(prince.getDirection(), player.x) - this->getXLocation();
                        int8_t tileYIdx = this->coordToTileIndexY(prince.getDirection(), player.y) - this->getYLocation();
Serial.print("coordToTileIndexX ");
Serial.print(player.x);
Serial.print(" = ");
Serial.print(tileXIdx);
Serial.print(", coordToTileIndexY ");
Serial.print(player.y);
Serial.print(" = ");
Serial.println(tileYIdx);

                        int8_t bgTile1 = this->getTile(Layer::Background, tileXIdx, tileYIdx, true);
                        int8_t bgTile2 = this->getTile(Layer::Background, tileXIdx + 1, tileYIdx, true);
                        int8_t bgTile3 = this->getTile(Layer::Background, tileXIdx + 2, tileYIdx, true);

                        int8_t fgTile1 = this->getTile(Layer::Foreground, tileXIdx, tileYIdx, true);
                        int8_t fgTile2 = this->getTile(Layer::Foreground, tileXIdx + 1, tileYIdx, true);
                        int8_t fgTile3 = this->getTile(Layer::Foreground, tileXIdx + 2, tileYIdx, true);
                        
                        int8_t dist = distToEdgeOfTile(prince.getDirection(), player.x);

Serial.print("dist ");
Serial.print(dist);
Serial.print(", bg ");
Serial.print(bgTile1);
Serial.print(" ");
Serial.print(bgTile2);
Serial.print(" ");
Serial.print(bgTile3);
Serial.print(", fg ");
Serial.print(fgTile1);
Serial.print(" ");
Serial.print(fgTile2);
Serial.print(" ");
Serial.print(fgTile3);
Serial.println("");
                        switch (action) {

                            case Action::SmallStep:
Serial.println("SmallStep R");
                                switch (dist) {

                                    case 0 ... 5:

                                         return this->isGroundTile(bgTile2, fgTile2);

                                    default:
Serial.println("3");

                                        return true;

                                }

                                break;

                            case Action::Step:
                            case Action::RunStart:

                                switch (dist) {

                                    case 0 ... 9:
                                         return this->isGroundTile(bgTile2, fgTile2);

                                    default:
                                        return true;

                                }

                                break;

                            case Action::RunRepeat:

                                return this->isGroundTile(bgTile2, fgTile2);

                            default: return false;

                        }


                    }


                    break;

                default: break;

            }

            return true;

        }


        CanJumpResult canJumpUp(Prince prince) {

            Point player;

            player.x = (this->xLoc * 12) + prince.getX();
            player.y = (this->yLoc * 31) + prince.getY();

            switch (prince.getDirection()) {

                case Direction::Left:
                    {
                        CanJumpResult jumpResultRight = canJumpUp_Test(prince, Direction::Left);

                        switch (jumpResultRight) {

                            case CanJumpResult::Jump:
                            case CanJumpResult::StepThenJump:
                                return jumpResultRight;

                            default:
                                {
                                    CanJumpResult jumpResultLeft = canJumpUp_Test(prince, Direction::Right);

                                    switch (jumpResultLeft) {

                                        case CanJumpResult::Jump:
                                            return CanJumpResult::TurnThenJump;

                                        default:
                                            return jumpResultRight;

                                    }

                                }

                                return CanJumpResult::None;

                        }
                        
                    }
                    return CanJumpResult::None;

                case Direction::Right:
                    {
                        CanJumpResult jumpResultRight = canJumpUp_Test(prince, Direction::Right);

                        switch (jumpResultRight) {

                            case CanJumpResult::Jump:
                            case CanJumpResult::StepThenJump:
                                return jumpResultRight;

                            default:
                                {
                                    CanJumpResult jumpResultLeft = canJumpUp_Test(prince, Direction::Left);

                                    switch (jumpResultLeft) {

                                        case CanJumpResult::Jump:
                                            return CanJumpResult::TurnThenJump;

                                        default:
                                            return jumpResultRight;

                                    }

                                }

                                return CanJumpResult::None;

                        }
                        
                    }
                    return CanJumpResult::None;

                default: 
                    return CanJumpResult::None;

            }

        }

        CanJumpResult canJumpUp_Test(Prince prince, Direction direction) {

            Point player;

            player.x = (this->xLoc * 12) + prince.getX();
            player.y = (this->yLoc * 31) + prince.getY();

            uint8_t inc = (direction == Direction::Left ? -1 : 1);
            int8_t tileXIdx = this->coordToTileIndexX(direction, player.x) - this->getXLocation();
            int8_t tileYIdx = this->coordToTileIndexY(direction, player.y) - this->getYLocation();
Serial.print("coordToTileIndexX ");
Serial.print(player.x);
Serial.print(" = ");
Serial.print(tileXIdx);
Serial.print(", coordToTileIndexY ");
Serial.print(player.y);
Serial.print(" = ");
Serial.println(tileYIdx);

            int8_t bgTile1 = this->getTile(Layer::Background, tileXIdx, tileYIdx - 1, true);
            int8_t bgTile2 = this->getTile(Layer::Background, tileXIdx + inc, tileYIdx - 1, true);
            
            int8_t distToEdge = distToEdgeOfTile(direction, player.x);

Serial.print("dist ");
Serial.print(distToEdge);
Serial.print(", bg ");
Serial.print(bgTile1);
Serial.print(" ");
Serial.print(bgTile2);
Serial.println("");

            switch (distToEdge) {

                case 7 ... 12:
                    return CanJumpResult::JumpThenFall;

                case 3 ... 6:

                    switch (bgTile2) {

                        case TILE_FLOOR_LH_END:
                        case TILE_FLOOR_LH_END_PATTERN_1:
                        case TILE_FLOOR_LH_END_PATTERN_2:
                            return CanJumpResult::StepThenJump;

                        default:                                
                            return CanJumpResult::JumpThenFall;

                    }

                    break;

                case 0 ... 2:

                    switch (bgTile2) {

                        case TILE_FLOOR_LH_END:
                        case TILE_FLOOR_LH_END_PATTERN_1:
                        case TILE_FLOOR_LH_END_PATTERN_2:
                            return CanJumpResult::Jump;

                        default:
                            return CanJumpResult::JumpThenFall;

                    }

                    break;

            }

            return CanJumpResult::None;

        }
        
};