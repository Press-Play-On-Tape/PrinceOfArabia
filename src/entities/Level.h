#pragma once

#include <Arduboy2.h>   
#include "Prince.h"   
#include "../utils/Constants.h"
#include "../utils/Stack.h"
#include "Item.h"

struct Level {

    private:

        uint8_t level = 0;
        uint8_t xLoc = 60;
        uint8_t yLoc = 0;

        int8_t bg[3][14];
        int8_t fg[3][14];
        Item items[NUMBER_OF_ITEMS];

    public:

        uint8_t getLevel()                      { return this->level; }
        uint8_t getXLocation()                  { return this->xLoc; }
        uint8_t getYLocation()                  { return this->yLoc; }
        Item &getItem(uint8_t idx)              { return this->items[idx]; }

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

                    if (print) {

                        #if defined(DEBUG) && defined(DEBUG_LEVEL_PROCESSING)
                        DEBUG_PRINT("getTile(FG, ");
                        DEBUG_PRINT(x);
                        DEBUG_PRINT(",");
                        DEBUG_PRINT(y);
                        DEBUG_PRINT(") = ");
                        DEBUG_PRINTLN(fg[y][x + 2]);
                        #endif

                    }
                    return fg[y][x + 2];

                case Layer::Background:

                    if (print) {

                        #if defined(DEBUG) && defined(DEBUG_LEVEL_PROCESSING)
                        DEBUG_PRINT("getTile(BG, ");
                        DEBUG_PRINT(x);
                        DEBUG_PRINT(",");
                        DEBUG_PRINT(y);
                        DEBUG_PRINT(") = ");
                        DEBUG_PRINTLN(bg[y][x + 2]);
                        #endif

                    }
                    return bg[y][x + 2];


            }

            return 0;

        }

        void printMap() {

            #if defined(DEBUG) && defined(DEBUG_LEVEL_LOAD_MAP)

            DEBUG_PRINTLN("Map ---------------");
            DEBUG_PRINT("xLoc: ");
            DEBUG_PRINT(xLoc);
            DEBUG_PRINT(", yLoc: ");
            DEBUG_PRINTLN(yLoc);
            DEBUG_PRINTLN("BG ---------------");

            for (uint8_t y = 0; y < 3; y++) {

                for (uint8_t x = 0; x < 14; x++) {

                    DEBUG_PRINT(bg[y][x]);
                    DEBUG_PRINT(" ");

                    if (x == 1 || x == 11) {
                    DEBUG_PRINT("| ");
                    }

                }

                DEBUG_PRINTLN("");

            }


            DEBUG_PRINTLN("FG ---------------");

            for (uint8_t y = 0; y < 3; y++) {

                for (uint8_t x = 0; x < 14; x++) {

                    DEBUG_PRINT(fg[y][x]);
                    DEBUG_PRINT(" ");

                    if (x == 1 || x == 11) {
                        DEBUG_PRINT("| ");
                    }

                }

                DEBUG_PRINTLN("");

            }

            #endif

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


            // Items
            

            for (Item &item : items) {
                item.active = false;
            }

            uint8_t itemIdx = 0;
            FX::seekData(Levels::Level1_Items);
            uint8_t itemType = FX::readPendingUInt8();

            while (itemType != 255) {

                Item &item = this->items[itemIdx];

                switch (static_cast<ItemType>(itemType)) {

                    case ItemType::Gate:
                        item.itemType = ItemType::Gate;
                        item.active = true;
                        item.x = FX::readPendingUInt8();
                        item.y = FX::readPendingUInt8();
                        item.data.gate.position = FX::readPendingUInt8();
                        item.data.gate.closingDelay = FX::readPendingUInt8();
                        break;

                    case ItemType::Torch:
                        item.itemType = ItemType::Torch;
                        item.active = true;
                        item.x = FX::readPendingUInt8();
                        item.y = FX::readPendingUInt8();
                        break;
                
                    default:
                        break;

                }

                itemType = FX::readPendingUInt8();
                itemIdx++;

            }


            FX::readEnd();



            #if defined(DEBUG) && defined(DEBUG_LEVEL_LOAD_MAP)
            printMap();
            #endif

        }

        #define TILE_NONE -1
        #define TILE_FLOOR_NONE 75
        #define TILE_FLOOR_NONE_PATTERN 92

        #define TILE_FLOOR_NONE_LH_WALL_1 97
        #define TILE_FLOOR_NONE_LH_WALL_2 120
        #define TILE_FLOOR_NONE_LH_WALL_3 91
        #define TILE_FLOOR_NONE_LH_WALL_4 119


        #define TILE_FLOOR_BASIC 77
        #define TILE_FLOOR_LH_END 76
        #define TILE_FLOOR_PATTERN 78
        #define TILE_FLOOR_LH_END_PATTERN_1 102
        #define TILE_FLOOR_LH_END_PATTERN_2 93
        #define TILE_FLOOR_RH_END 99
        #define TILE_FLOOR_RH_END_GATE 118

        #define TILE_FLOOR_RH_END_1 98
        #define TILE_FLOOR_RH_END_2 85
        #define TILE_FLOOR_RH_END_3 103
        #define TILE_FLOOR_RH_END_4 94
        #define TILE_FLOOR_RH_END_5 111

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

            switch (bgTile) {

                case TILE_FLOOR_BASIC:
                case TILE_FLOOR_LH_END:
                case TILE_FLOOR_PATTERN:
                case TILE_FLOOR_LH_END_PATTERN_1:
                case TILE_FLOOR_LH_END_PATTERN_2:
                case TILE_FLOOR_RH_END:
                case TILE_FLOOR_RH_END_GATE:
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
                    return true;

            }

            switch (fgTile) {

                case TILE_FG_WALL_1:
                case TILE_FG_WALL_2:
                case TILE_FG_WALL_3:
                case TILE_FG_WALL_4:
                case TILE_FG_WALL_5:
                case TILE_FG_WALL_6:
                    return false;

            }

            return false;

        }

        bool canFall(uint8_t bgTile, uint8_t fgTile) {

            switch (bgTile) {

                case TILE_NONE:
                case TILE_FLOOR_NONE:
                case TILE_FLOOR_NONE_PATTERN:
                case TILE_FLOOR_NONE_LH_WALL_1:
                case TILE_FLOOR_NONE_LH_WALL_2:
                case TILE_FLOOR_NONE_LH_WALL_3:
                case TILE_FLOOR_NONE_LH_WALL_4:
                case TILE_FLOOR_RH_END_1:
                case TILE_FLOOR_RH_END_2:
                case TILE_FLOOR_RH_END_3:
                case TILE_FLOOR_RH_END_4:
                case TILE_FLOOR_RH_END_5:

                    return true;

            }

            // switch (fgTile) {

            //     case :
            //         return false;

            // }

            return false;

        }

        bool canFall(Prince prince, int8_t xOffset = 0) {

            Point player;

            player.x = (this->xLoc * 12) + prince.getX() + (prince.getDirection() == Direction::Left ? xOffset * -1 : xOffset);
            player.y = (this->yLoc * 31) + prince.getY();

            switch (prince.getDirection()) {

                case Direction::Left:
                    {

                        int8_t tileXIdx = this->coordToTileIndexX(prince.getDirection(), player.x) - this->getXLocation();
                        int8_t tileYIdx = this->coordToTileIndexY(prince.getDirection(), player.y) - this->getYLocation();

                        #if defined(DEBUG) && defined(DEBUG_ACTION_CANFALL)
                        DEBUG_PRINT("coordToTileIndexX ");
                        DEBUG_PRINT(player.x);
                        DEBUG_PRINT(" = ");
                        DEBUG_PRINT(tileXIdx);
                        DEBUG_PRINT(", coordToTileIndexY ");
                        DEBUG_PRINT(player.y);
                        DEBUG_PRINT(" = ");
                        DEBUG_PRINTLN(tileYIdx);
                        #endif

                        int8_t bgTile1 = this->getTile(Layer::Background, tileXIdx, tileYIdx, true);
                        int8_t fgTile1 = this->getTile(Layer::Foreground, tileXIdx, tileYIdx, true);

                        #if defined(DEBUG) && defined(DEBUG_ACTION_CANMOVEFORWARD)
                        DEBUG_PRINT("bg ");
                        DEBUG_PRINT(bgTile1);
                        DEBUG_PRINT(", fg ");
                        DEBUG_PRINT(fgTile1);
                        DEBUG_PRINTLN("");
                        #endif

                        return this->canFall(bgTile1, fgTile1);

                    }

                    break;

                case Direction::Right:
                    {

                        int8_t tileXIdx = this->coordToTileIndexX(prince.getDirection(), player.x) - this->getXLocation();
                        int8_t tileYIdx = this->coordToTileIndexY(prince.getDirection(), player.y) - this->getYLocation();

                        #if defined(DEBUG) && defined(DEBUG_ACTION_CANFALL)
                        DEBUG_PRINT("coordToTileIndexX ");
                        DEBUG_PRINT(player.x);
                        DEBUG_PRINT(" = ");
                        DEBUG_PRINT(tileXIdx);
                        DEBUG_PRINT(", coordToTileIndexY ");
                        DEBUG_PRINT(player.y);
                        DEBUG_PRINT(" = ");
                        DEBUG_PRINTLN(tileYIdx);
                        #endif

                        int8_t bgTile1 = this->getTile(Layer::Background, tileXIdx, tileYIdx, true);
                        int8_t fgTile1 = this->getTile(Layer::Foreground, tileXIdx, tileYIdx, true);

                        #if defined(DEBUG) && defined(DEBUG_ACTION_CANMOVEFORWARD)
                        DEBUG_PRINT("bg ");
                        DEBUG_PRINT(bgTile1);
                        DEBUG_PRINT(", fg ");
                        DEBUG_PRINT(fgTile1);
                        DEBUG_PRINTLN("");
                        #endif

                        return this->canFall(bgTile1, fgTile1);

                    }

                    break;

                default: break;

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

                        #if defined(DEBUG) && defined(DEBUG_ACTION_CANMOVEFORWARD)
                        DEBUG_PRINT("coordToTileIndexX ");
                        DEBUG_PRINT(player.x);
                        DEBUG_PRINT(" = ");
                        DEBUG_PRINT(tileXIdx);
                        DEBUG_PRINT(", coordToTileIndexY ");
                        DEBUG_PRINT(player.y);
                        DEBUG_PRINT(" = ");
                        DEBUG_PRINTLN(tileYIdx);
                        #endif

                        int8_t bgTile1 = this->getTile(Layer::Background, tileXIdx, tileYIdx, true);
                        int8_t bgTile2 = this->getTile(Layer::Background, tileXIdx - 1, tileYIdx, true);
                        int8_t bgTile3 = this->getTile(Layer::Background, tileXIdx - 2, tileYIdx, true);
                        int8_t bgTile4 = this->getTile(Layer::Background, tileXIdx - 3, tileYIdx, true);

                        int8_t fgTile1 = this->getTile(Layer::Foreground, tileXIdx, tileYIdx, true);
                        int8_t fgTile2 = this->getTile(Layer::Foreground, tileXIdx - 1, tileYIdx, true);
                        int8_t fgTile3 = this->getTile(Layer::Foreground, tileXIdx - 2, tileYIdx, true);
                        int8_t fgTile4 = this->getTile(Layer::Foreground, tileXIdx - 3, tileYIdx, true);
                        
                        int8_t distToEdgeOfCurrentTile = distToEdgeOfTile(prince.getDirection(), player.x);

                        #if defined(DEBUG) && defined(DEBUG_ACTION_CANMOVEFORWARD)
                        DEBUG_PRINT("dist ");
                        DEBUG_PRINT(distToEdgeOfCurrentTile);
                        DEBUG_PRINT(", bg ");
                        DEBUG_PRINT(bgTile4);
                        DEBUG_PRINT(" ");
                        DEBUG_PRINT(bgTile3);
                        DEBUG_PRINT(" ");
                        DEBUG_PRINT(bgTile2);
                        DEBUG_PRINT(" ");
                        DEBUG_PRINT(bgTile1);
                        DEBUG_PRINT(", fg ");
                        DEBUG_PRINT(fgTile4);
                        DEBUG_PRINT(" ");
                        DEBUG_PRINT(fgTile3);
                        DEBUG_PRINT(" ");
                        DEBUG_PRINT(fgTile2);
                        DEBUG_PRINT(" ");
                        DEBUG_PRINT(fgTile1);
                        DEBUG_PRINTLN("");
                        #endif

                        switch (action) {

                            case Action::SmallStep:
                            case Action::CrouchHop:

                                switch (distToEdgeOfCurrentTile) {

                                    case 0 ... 5:
                                         return (this->isGroundTile(bgTile2, fgTile2) || this->canFall(bgTile2, fgTile2));

                                    default:
                                        return true;

                                }

                                break;

                            case Action::Step:
                            case Action::RunStart:

                                switch (distToEdgeOfCurrentTile) {

                                    case 0 ... 9:
                                         return (this->isGroundTile(bgTile2, fgTile2) || this->canFall(bgTile2, fgTile2));

                                    default:
                                        return true;

                                }

                                break;

                            case Action::RunRepeat:

                                return (this->isGroundTile(bgTile2, fgTile2) || this->canFall(bgTile2, fgTile2));

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

                        #if defined(DEBUG) && defined(DEBUG_ACTION_CANMOVEFORWARD)
                        DEBUG_PRINT("coordToTileIndexX ");
                        DEBUG_PRINT(player.x);
                        DEBUG_PRINT(" = ");
                        DEBUG_PRINT(tileXIdx);
                        DEBUG_PRINT(", coordToTileIndexY ");
                        DEBUG_PRINT(player.y);
                        DEBUG_PRINT(" = ");
                        DEBUG_PRINTLN(tileYIdx);
                        #endif

                        int8_t bgTile1 = this->getTile(Layer::Background, tileXIdx, tileYIdx, true);
                        int8_t bgTile2 = this->getTile(Layer::Background, tileXIdx + 1, tileYIdx, true);
                        int8_t bgTile3 = this->getTile(Layer::Background, tileXIdx + 2, tileYIdx, true);
                        int8_t bgTile4 = this->getTile(Layer::Background, tileXIdx + 3, tileYIdx, true);

                        int8_t fgTile1 = this->getTile(Layer::Foreground, tileXIdx, tileYIdx, true);
                        int8_t fgTile2 = this->getTile(Layer::Foreground, tileXIdx + 1, tileYIdx, true);
                        int8_t fgTile3 = this->getTile(Layer::Foreground, tileXIdx + 2, tileYIdx, true);
                        int8_t fgTile4 = this->getTile(Layer::Foreground, tileXIdx + 3, tileYIdx, true);
                        
                        int8_t distToEdgeOfCurrentTile = distToEdgeOfTile(prince.getDirection(), player.x);

                        #if defined(DEBUG) && defined(DEBUG_ACTION_CANMOVEFORWARD)
                        DEBUG_PRINT("dist ");
                        DEBUG_PRINT(distToEdgeOfCurrentTile);
                        DEBUG_PRINT(", bg ");
                        DEBUG_PRINT(bgTile1);
                        DEBUG_PRINT(" ");
                        DEBUG_PRINT(bgTile2);
                        DEBUG_PRINT(" ");
                        DEBUG_PRINT(bgTile3);
                        DEBUG_PRINT(", fg ");
                        DEBUG_PRINT(fgTile1);
                        DEBUG_PRINT(" ");
                        DEBUG_PRINT(fgTile2);
                        DEBUG_PRINT(" ");
                        DEBUG_PRINT(fgTile3);
                        DEBUG_PRINTLN("");
                        #endif

                        switch (action) {

                            case Action::SmallStep:
                            case Action::CrouchHop:

                                switch (distToEdgeOfCurrentTile) {

                                    case 0 ... 5:

                                         return (this->isGroundTile(bgTile2, fgTile2) || this->canFall(bgTile2, fgTile2));

                                    default:

                                        return true;

                                }

                                break;

                            case Action::Step:
                            case Action::RunStart:

                                switch (distToEdgeOfCurrentTile) {

                                    case 0 ... 9:
                                         return (this->isGroundTile(bgTile2, fgTile2) || this->canFall(bgTile2, fgTile2));

                                    default:
                                        return true;

                                }

                                break;

                            case Action::RunRepeat:

                                return (this->isGroundTile(bgTile2, fgTile2) || this->canFall(bgTile2, fgTile2));

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
                        CanJumpResult resultLeft = canJumpUp_Test(prince, Direction::Left);

                        switch (resultLeft) {

                            case CanJumpResult::Jump:
                            case CanJumpResult::StepThenJump:

                                #if defined(DEBUG) && defined(DEBUG_ACTION_CANJUMPUP)
                                DEBUG_PRINT("Left Test success, Return ");
                                DEBUG_PRINTLN(static_cast<uint8_t>(resultLeft));
                                #endif
                                                                    
                                return resultLeft;

                            default:
                                {
                                    CanJumpResult resultRight = canJumpUp_Test(prince, Direction::Right);

                                    switch (resultRight) {

                                        case CanJumpResult::Jump:

                                            #if defined(DEBUG) && defined(DEBUG_ACTION_CANJUMPUP)
                                            DEBUG_PRINT("Right Test success, Return TurnThenJump");
                                            #endif

                                            return CanJumpResult::TurnThenJump;

                                        default:

                                            #if defined(DEBUG) && defined(DEBUG_ACTION_CANJUMPUP)
                                            DEBUG_PRINT("Right Test failed, Return ");
                                            DEBUG_PRINTLN(static_cast<uint8_t>(resultLeft));
                                            #endif

                                            return resultLeft;

                                    }

                                }

                                #if defined(DEBUG) && defined(DEBUG_ACTION_CANJUMPUP)
                                DEBUG_PRINT("Return None");
                                #endif

                                return CanJumpResult::None;

                        }
                        
                    }

                    #if defined(DEBUG) && defined(DEBUG_ACTION_CANJUMPUP)
                    DEBUG_PRINT("Return None");
                    #endif

                    return CanJumpResult::None;

                case Direction::Right:
                    {
                        CanJumpResult resultRight = canJumpUp_Test(prince, Direction::Right);

                        switch (resultRight) {

                            case CanJumpResult::Jump:
                            case CanJumpResult::StepThenJump:

                                #if defined(DEBUG) && defined(DEBUG_ACTION_CANJUMPUP)
                                DEBUG_PRINT("Right Test success, Return ");
                                DEBUG_PRINTLN(static_cast<uint8_t>(resultRight));
                                #endif                            

                                return resultRight;

                            default:
                                {
                                    CanJumpResult resultLeft = canJumpUp_Test(prince, Direction::Left);

                                    switch (resultLeft) {

                                        case CanJumpResult::Jump:

                                            #if defined(DEBUG) && defined(DEBUG_ACTION_CANJUMPUP)
                                            DEBUG_PRINT("Left Test success, Return TurnThenJump");
                                            #endif     

                                            return CanJumpResult::TurnThenJump;

                                        default:

                                            #if defined(DEBUG) && defined(DEBUG_ACTION_CANJUMPUP)
                                            DEBUG_PRINT("Left Test failed, Return ");
                                            DEBUG_PRINTLN(static_cast<uint8_t>(resultRight));
                                            #endif     

                                            return resultRight;

                                    }

                                }

                                #if defined(DEBUG) && defined(DEBUG_ACTION_CANJUMPUP)
                                DEBUG_PRINT("Return None");
                                #endif     

                                return CanJumpResult::None;

                        }
                        
                    }

                    #if defined(DEBUG) && defined(DEBUG_ACTION_CANJUMPUP)
                    DEBUG_PRINT("Return None");
                    #endif     

                    return CanJumpResult::None;

                default: 

                    #if defined(DEBUG) && defined(DEBUG_ACTION_CANJUMPUP)
                    DEBUG_PRINT("Return None");
                    #endif     

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

            #if defined(DEBUG) && defined(DEBUG_ACTION_CANJUMPUP)
            DEBUG_PRINT("coordToTileIndexX ");
            DEBUG_PRINT(player.x);
            DEBUG_PRINT(" = ");
            DEBUG_PRINT(tileXIdx);
            DEBUG_PRINT(", coordToTileIndexY ");
            DEBUG_PRINT(player.y);
            DEBUG_PRINT(" = ");
            DEBUG_PRINTLN(tileYIdx);
            #endif

            int8_t bgTile1 = this->getTile(Layer::Background, tileXIdx, tileYIdx - 1, true);
            int8_t bgTile2 = this->getTile(Layer::Background, tileXIdx + inc, tileYIdx - 1, true);
            int8_t distToEdge = distToEdgeOfTile(direction, player.x);

            #if defined(DEBUG) && defined(DEBUG_ACTION_CANJUMPUP)
            DEBUG_PRINT("dist ");
            DEBUG_PRINT(distToEdge);
            DEBUG_PRINT(", bg ");
            DEBUG_PRINT(bgTile);
            DEBUG_PRINT(" ");
            DEBUG_PRINT(bgTile2);
            DEBUG_PRINTLN("");
            #endif


            switch (direction) {

                case Direction::Left:

                    switch (distToEdge) {

                        case 7 ... 12:
                            return CanJumpResult::JumpThenFall;

                        case 3 ... 6:

                            switch (bgTile1) {

                                case TILE_FLOOR_RH_END:
                                case TILE_FLOOR_RH_END_GATE:
                                    return CanJumpResult::StepThenJump;

                                default:                                
                                    return CanJumpResult::JumpThenFall;

                            }

                            break;

                        case 0 ... 2:

                            switch (bgTile1) {

                                case TILE_FLOOR_RH_END:
                                case TILE_FLOOR_RH_END_GATE:
                                    return CanJumpResult::Jump;

                                default:
                                    return CanJumpResult::JumpThenFall;

                            }

                            break;

                    }

                    return CanJumpResult::None;

                case Direction::Right:

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

            return CanJumpResult::None;

        }


        bool canJumpUp_Part2(Prince prince) {

            int8_t tileXIdx;
            int8_t tileYIdx;

            Point player;

            player.x = (this->xLoc * 12) + prince.getX();
            player.y = (this->yLoc * 31) + prince.getY();

            switch (prince.getDirection()) {

                case Direction::Left:
                    {

                        tileXIdx = this->coordToTileIndexX(prince.getDirection(), player.x) - this->getXLocation();
                        tileYIdx = this->coordToTileIndexY(prince.getDirection(), player.y) - this->getYLocation() - 1;

                        #if defined(DEBUG) && defined(DEBUG_ACTION_CANJUMPUP_PART2)
                        DEBUG_PRINT("coordToTileIndexX ");
                        DEBUG_PRINT(player.x);
                        DEBUG_PRINT(" = ");
                        DEBUG_PRINT(tileXIdx);
                        DEBUG_PRINT(", coordToTileIndexY ");
                        DEBUG_PRINT(player.y);
                        DEBUG_PRINT(" = ");
                        DEBUG_PRINTLN(tileYIdx);
                        #endif

                        // int8_t bgTile1 = this->getTile(Layer::Background, tileXIdx, tileYIdx, true);
                        // int8_t fgTile1 = this->getTile(Layer::Foreground, tileXIdx, tileYIdx, true);

                        // #if defined(DEBUG) && defined(DEBUG_ACTION_CANJUMPUP_PART2)
                        // DEBUG_PRINT("bg ");
                        // DEBUG_PRINT(bgTile1);
                        // DEBUG_PRINT(", fg ");
                        // DEBUG_PRINT(fgTile1);
                        // DEBUG_PRINTLN("");
                        // #endif

                    }

                    break;

                case Direction::Right:
                    {

                        tileXIdx = this->coordToTileIndexX(prince.getDirection(), player.x) - this->getXLocation() + 1;
                        tileYIdx = this->coordToTileIndexY(prince.getDirection(), player.y) - this->getYLocation() - 1;

                        #if defined(DEBUG) && defined(DEBUG_ACTION_CANJUMPUP_PART2)
                        DEBUG_PRINT("coordToTileIndexX ");
                        DEBUG_PRINT(player.x);
                        DEBUG_PRINT(" = ");
                        DEBUG_PRINT(tileXIdx);
                        DEBUG_PRINT(", coordToTileIndexY ");
                        DEBUG_PRINT(player.y);
                        DEBUG_PRINT(" = ");
                        DEBUG_PRINTLN(tileYIdx);
                        #endif

                        // int8_t bgTile1 = this->getTile(Layer::Background, tileXIdx, tileYIdx, true);
                        // int8_t fgTile1 = this->getTile(Layer::Foreground, tileXIdx, tileYIdx, true);

                        // #if defined(DEBUG) && defined(DEBUG_ACTION_CANJUMPUP_PART2)
                        // DEBUG_PRINT("bg ");
                        // DEBUG_PRINT(bgTile1);
                        // DEBUG_PRINT(", fg ");
                        // DEBUG_PRINT(fgTile1);
                        // DEBUG_PRINTLN("");
                        // #endif

                    }

                    break;

                default: break;

            }



            // Look for closed gate in the same cell as possible ledge ..

            uint8_t gatePosition = 255;
            uint8_t inc = (prince.getDirection() == Direction::Left ? 0 : 1);

            for (uint8_t i = 0; i < NUMBER_OF_ITEMS; i++) {

                Item &item = this->items[i];

                if (item.itemType == ItemType::Gate && item.active) {

                    // switch (prince.getDirection()) {

                    //     case Direction::Left:

                            if (item.x == tileXIdx + this->xLoc && item.y == tileYIdx + this->yLoc) {

                                gatePosition = item.data.gate.position;
                                break;

                            }

                    //         break;

                    //     case Direction::Right:

                    //         if (item.x == tileXIdx + this->xLoc + inc && item.y == tileYIdx + this->yLoc) {

                    //             gatePosition = item.data.gate.position;
                    //             break;

                    //         }

                    //         break;

                    // }

                }

            }


            // Was a gate found?

            return (gatePosition == 9 || gatePosition == 255);

        }        


        CanClimbDownResult canClimbDown(Prince prince) {

            Point player;

            player.x = (this->xLoc * 12) + prince.getX();
            player.y = (this->yLoc * 31) + prince.getY();

            switch (prince.getDirection()) {

                case Direction::Left:
                    {
                        CanClimbDownResult resultRight = canClimbDown_Test(prince, Direction::Right);

                        switch (resultRight) {

                            case CanClimbDownResult::ClimbDown:
                            case CanClimbDownResult::StepThenClimbDown:

                                #if defined(DEBUG) && defined(DEBUG_ACTION_CANCLIMBDOWN)
                                DEBUG_PRINT("Return: ");
                                DEBUG_PRINTLN(static_cast<uint8_t>(resultRight));
                                #endif

                                return resultRight;

                            default:
                                {
                                    CanClimbDownResult resultLeft = canClimbDown_Test(prince, Direction::Left);

                                    switch (resultLeft) {

                                        case CanClimbDownResult::ClimbDown:

                                            #if defined(DEBUG) && defined(DEBUG_ACTION_CANCLIMBDOWN)
                                            DEBUG_PRINTLN("Return: TurnThenClimbDown");
                                            #endif

                                            return CanClimbDownResult::TurnThenClimbDown;

                                        case CanClimbDownResult::StepThenClimbDown:

                                            #if defined(DEBUG) && defined(DEBUG_ACTION_CANCLIMBDOWN)
                                            DEBUG_PRINTLN("Return: StepThenTurnThenClimbDown");
                                            #endif

                                            return CanClimbDownResult::StepThenTurnThenClimbDown;

                                        default:

                                            #if defined(DEBUG) && defined(DEBUG_ACTION_CANCLIMBDOWN)
                                            DEBUG_PRINT("Return: ");
                                            DEBUG_PRINTLN(static_cast<uint8_t>(resultRight));
                                            #endif
                                            
                                            return resultRight;

                                    }

                                }
                                        
                                #if defined(DEBUG) && defined(DEBUG_ACTION_CANCLIMBDOWN)
                                DEBUG_PRINTLN("Return: None");
                                #endif

                                return CanClimbDownResult::None;

                        }
                        
                    }

                    #if defined(DEBUG) && defined(DEBUG_ACTION_CANCLIMBDOWN)
                    DEBUG_PRINTLN("Return: None");
                    #endif

                    return CanClimbDownResult::None;

                case Direction::Right:
                    {
                        CanClimbDownResult resultLeft = canClimbDown_Test(prince, Direction::Left);

                        switch (resultLeft) {

                            case CanClimbDownResult::ClimbDown:
                            case CanClimbDownResult::StepThenClimbDown:

                                #if defined(DEBUG) && defined(DEBUG_ACTION_CANCLIMBDOWN)
                                DEBUG_PRINT("Return: ");
                                DEBUG_PRINTLN(static_cast<uint8_t>(resultLeft));
                                #endif

                                return resultLeft;

                            default:
                                {
                                    CanClimbDownResult resultRight = canClimbDown_Test(prince, Direction::Right);

                                    switch (resultRight) {

                                        case CanClimbDownResult::ClimbDown:

                                            #if defined(DEBUG) && defined(DEBUG_ACTION_CANCLIMBDOWN)
                                            DEBUG_PRINTLN("Return: TurnThenClimbDown");
                                            #endif

                                            return CanClimbDownResult::TurnThenClimbDown;

                                        case CanClimbDownResult::StepThenClimbDown:

                                            #if defined(DEBUG) && defined(DEBUG_ACTION_CANCLIMBDOWN)
                                            DEBUG_PRINTLN("Return: StepThenTurnThenClimbDown");
                                            #endif

                                            return CanClimbDownResult::StepThenTurnThenClimbDown;

                                        default:

                                            #if defined(DEBUG) && defined(DEBUG_ACTION_CANCLIMBDOWN)
                                            DEBUG_PRINT("Return: ");
                                            DEBUG_PRINTLN(static_cast<uint8_t>(resultLeft));
                                            #endif
                                            
                                            return resultLeft;

                                    }

                                }

                                return CanClimbDownResult::None;

                        }
                        
                    }

                    #if defined(DEBUG) && defined(DEBUG_ACTION_CANCLIMBDOWN)
                    DEBUG_PRINTLN("Return: None");
                    #endif

                    return CanClimbDownResult::None;

                default: 

                    #if defined(DEBUG) && defined(DEBUG_ACTION_CANCLIMBDOWN)
                    DEBUG_PRINTLN("Return: None");
                    #endif

                    return CanClimbDownResult::None;

            }

        }

        CanClimbDownResult canClimbDown_Test(Prince prince, Direction direction) {

            Point player;

            player.x = (this->xLoc * 12) + prince.getX();
            player.y = (this->yLoc * 31) + prince.getY();

            int8_t tileXIdx = this->coordToTileIndexX(direction, player.x) - this->getXLocation() + (direction == Direction::Right ? 1 : 0);
            int8_t tileYIdx = this->coordToTileIndexY(direction, player.y) - this->getYLocation();

            #if defined(DEBUG) && defined(DEBUG_ACTION_CANCLIMBDOWN)
            DEBUG_PRINT("coordToTileIndexX ");
            DEBUG_PRINT(player.x);
            DEBUG_PRINT(" = ");
            DEBUG_PRINT(tileXIdx);
            DEBUG_PRINT(", coordToTileIndexY ");
            DEBUG_PRINT(player.y);
            DEBUG_PRINT(" = ");
            DEBUG_PRINTLN(tileYIdx);
            #endif

            int8_t bgTile1 = this->getTile(Layer::Background, tileXIdx, tileYIdx, true);
            int8_t distToEdge = distToEdgeOfTile(direction, player.x);

            #if defined(DEBUG) && defined(DEBUG_ACTION_CANCLIMBDOWN)
            DEBUG_PRINT("dist ");
            DEBUG_PRINT(distToEdge);
            DEBUG_PRINT(", bg ");
            DEBUG_PRINT(bgTile1);
            DEBUG_PRINTLN("");
            #endif

            // switch (distToEdge) {

            //     case 7 ... 12:
            //         return CanClimbDownResult::None;

            //     case 3 ... 6:

            //         switch (direction) {

            //             case Direction::Left:

            //                 switch (bgTile1) {

            //                     case TILE_FLOOR_LH_END:
            //                     case TILE_FLOOR_LH_END_PATTERN_1:
            //                     case TILE_FLOOR_LH_END_PATTERN_2:
            //                         return CanClimbDownResult::StepThenClimbDown;

            //                     default:                                
            //                         return CanClimbDownResult::None;

            //                 }

            //                 break;

            //             case Direction::Right:

            //                 switch (bgTile1) {

            //                     case TILE_FLOOR_RH_END:
            //                     case TILE_FLOOR_RH_END_GATE:
            //                         return CanClimbDownResult::StepThenClimbDown;

            //                     default:                                
            //                         return CanClimbDownResult::None;

            //                 }

            //                 break;

            //         }
                    
            //         break;

            //     case 0 ... 2:

            //         switch (direction) {

            //             case Direction::Left:

            //                 switch (bgTile1) {

            //                     case TILE_FLOOR_LH_END:
            //                     case TILE_FLOOR_LH_END_PATTERN_1:
            //                     case TILE_FLOOR_LH_END_PATTERN_2:
            //                         return CanClimbDownResult::ClimbDown;

            //                     default:
            //                         return CanClimbDownResult::None;

            //                 }

            //                 break;

            //             case Direction::Right:

            //                 switch (bgTile1) {

            //                     case TILE_FLOOR_RH_END:
            //                     case TILE_FLOOR_RH_END_GATE:
            //                         return CanClimbDownResult::ClimbDown;

            //                     default:
            //                         return CanClimbDownResult::None;

            //                 }

            //                 break;

            //         }
            // }

            // return CanClimbDownResult::None;

            switch (direction) {

                case Direction::Left:

                    switch (distToEdge) {

                        case 7 ... 12:
                            return CanClimbDownResult::None;

                        case 3 ... 6:

                            switch (bgTile1) {

                                case TILE_FLOOR_LH_END:
                                case TILE_FLOOR_LH_END_PATTERN_1:
                                case TILE_FLOOR_LH_END_PATTERN_2:
                                    return CanClimbDownResult::StepThenClimbDown;

                                default:                                
                                    return CanClimbDownResult::None;

                            }

                            break;

                        case 0 ... 2:

                            switch (bgTile1) {

                                case TILE_FLOOR_LH_END:
                                case TILE_FLOOR_LH_END_PATTERN_1:
                                case TILE_FLOOR_LH_END_PATTERN_2:
                                    return CanClimbDownResult::ClimbDown;

                                default:
                                    return CanClimbDownResult::None;

                            }

                            break;

                    }

                    return CanClimbDownResult::None;


                case Direction::Right:

                    switch (distToEdge) {

                        case 7 ... 12:
                            return CanClimbDownResult::None;

                        case 3 ... 6:

                            switch (bgTile1) {

                                case TILE_FLOOR_RH_END:
                                case TILE_FLOOR_RH_END_GATE:
                                    return CanClimbDownResult::StepThenClimbDown;

                                default:                                
                                    return CanClimbDownResult::None;

                            }

                            break;

                        case 0 ... 2:

                            switch (bgTile1) {

                                case TILE_FLOOR_RH_END:
                                case TILE_FLOOR_RH_END_GATE:
                                    return CanClimbDownResult::ClimbDown;

                                default:
                                    return CanClimbDownResult::None;

                            }

                            break;

                    }

                    return CanClimbDownResult::None;

                default:

                    return CanClimbDownResult::None;

            }

        }



};