#pragma once

#include "../utils/Arduboy2Ext.h"
#include "Prince.h"   
#include "../utils/Constants.h"
#include "../utils/Stack.h"
#include "Item.h"

struct Level {

    private:

        uint8_t level = 0;
        uint8_t xLoc = 60;
        uint8_t yLoc = 0;
        uint8_t yOffset = 0;                        // Ofset when rendering.
        Direction yOffsetDir = Direction::None;     // Ofset movement

        int8_t bg[3][14];
        int8_t fg[3][14];
        Item items[NUMBER_OF_ITEMS];

    public:

        uint8_t getLevel()                      { return this->level; }
        uint8_t getXLocation()                  { return this->xLoc; }
        uint8_t getYLocation()                  { return this->yLoc; }
        uint8_t getYOffset()                    { return this->yOffset; }
        Item &getItem(uint8_t idx)              { return this->items[idx]; }
        Direction getYDirection()               { return this->yOffsetDir; }

        void setLevel(uint8_t val)              { this->level = val; }
        void setXLocation(uint8_t val)          { this->xLoc = val; }
        void setYLocation(uint8_t val)          { this->yLoc = val; }
        void setYOffset(uint8_t val)            { this->yOffset = val; }
        void setYOffsetDir(Direction val)       { this->yOffsetDir = val; }


    public:

        void init(uint8_t xLoc, uint8_t yLoc) {

            this->xLoc = xLoc;
            this->yLoc = yLoc;

            this->loadMap();
        }

        void incYOffset(int8_t inc) {

            this->yOffset = this->yOffset + inc;
        }

        void update(Arduboy2Ext &arduboy, Prince &prince) {


            // Update level offset ..

            switch (this->yOffsetDir) {

                case Direction::Down:
                    
                    if (this->yOffset < 31) {
                    
                        this->yOffset++;
                    
                        if (this->yOffset == 31) {
                            this->yOffsetDir = Direction::None;
                        }
                    
                    }
                    break;

                case Direction::Up:
                    
                    if (this->yOffset > 0) {
                    
                        this->yOffset--;
                    
                        if (this->yOffset == 0) {
                            this->yOffsetDir = Direction::None;
                        }
                    
                    }
                    break;

                default: break;

            }


            // uint8_t tileXIdx = this->coordToTileIndexX(prince.getDirection(), prince.getPosition().x) - this->getXLocation();
            // uint8_t tileYIdx = this->coordToTileIndexY(prince.getDirection(), prince.getPosition().y) - this->getYLocation() - 1;

            for (uint8_t i = 0; i < NUMBER_OF_ITEMS; i++) {

                Item &item = this->getItem(i);

                if (item.active) {

                    switch (item.itemType) {

                        case ItemType::Gate:

                            if (item.data.gate.closingDelay > 0) {
                                item.data.gate.closingDelay--;
                            }
                            else {

                                if (item.data.gate.position > 0 && arduboy.getFrameCount(3)) {

                                    item.data.gate.position--;
                                }

                            }
                            break;

                        case ItemType::Torch:

                            if (arduboy.getFrameCount(3)) {

                                item.data.torch.frame++;
                                item.data.torch.frame = (item.data.torch.frame) % 5;

                            }
                            break;

                        case ItemType::CollapsingFloor:

                            if (arduboy.isFrameCount(4) && item.data.collapsingFloor.frame > 0) {

                                item.data.collapsingFloor.frame--;

                            }
                            break;

                        // case ItemType::CollpasedFloor:

                        //     if (arduboy.getFrameCount(3)) {

                        //         item.data.torch.frame++;
                        //         item.data.torch.frame = (item.data.torch.frame) % 5;

                        //     }
                        //     break;

                        default: break;

                    }

                }

            }

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
                item.itemType = static_cast<ItemType>(itemType);
                item.active = true;
                item.x = FX::readPendingUInt8();
                item.y = FX::readPendingUInt8();

                switch (item.itemType) {

                    case ItemType::Gate:
                        item.data.gate.position = FX::readPendingUInt8();
                        item.data.gate.closingDelay = FX::readPendingUInt8();
                        break;

                    // case ItemType::Torch:
                    //     break;

                    // case ItemType::CollapsingFloor:
                    //     break;

                    // case ItemType::CollpasedFloor:
                    //     break;
                
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
        #define TILE_FLOOR_PATTERN_1 78
        #define TILE_FLOOR_PATTERN_2 79
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


        bool isWallTile(int8_t bgTile, int8_t fgTile) {

            switch (fgTile) {

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

        bool isGroundTile(int8_t bgTile, int8_t fgTile) {

            switch (bgTile) {

                case TILE_FLOOR_BASIC:
                case TILE_FLOOR_LH_END:
                case TILE_FLOOR_PATTERN_1:
                case TILE_FLOOR_PATTERN_2:
                case TILE_FLOOR_LH_END_PATTERN_1:
                case TILE_FLOOR_LH_END_PATTERN_2:
                case TILE_FLOOR_RH_END:
                case TILE_FLOOR_RH_END_1:
                case TILE_FLOOR_RH_END_2:
                case TILE_FLOOR_RH_END_3:
                case TILE_FLOOR_RH_END_4:
                case TILE_FLOOR_RH_END_5:
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

        bool canFall(int8_t bgTile, int8_t fgTile) {

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

        bool canFall(Prince &prince, int8_t xOffset = 0) {

            Point newPos = prince.getPosition();
            newPos.x = newPos.x + (prince.getDirection() == Direction::Left ? xOffset * -1 : xOffset);

            int8_t tileXIdx = this->coordToTileIndexX(prince.getDirection(), newPos.x) - this->getXLocation();
            int8_t tileYIdx = this->coordToTileIndexY(prince.getDirection(), newPos.y) - this->getYLocation();

            #if defined(DEBUG) && defined(DEBUG_ACTION_CANFALL)
            DEBUG_PRINT("coordToTileIndexX ");
            DEBUG_PRINT(newPos.x);
            DEBUG_PRINT(" = ");
            DEBUG_PRINT(tileXIdx);
            DEBUG_PRINT(", coordToTileIndexY ");
            DEBUG_PRINT(newPos.y);
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

        bool canMoveForward(Action action, Prince &prince) {

            int8_t tileXIdx = this->coordToTileIndexX(prince.getDirection(), prince.getPosition().x) - this->getXLocation();
            int8_t tileYIdx = this->coordToTileIndexY(prince.getDirection(), prince.getPosition().y) - this->getYLocation();

            #if defined(DEBUG) && defined(DEBUG_ACTION_CANMOVEFORWARD)
            printAction(action);
            DEBUG_PRINT(" coordToTileIndexX ");
            DEBUG_PRINT(prince.getPosition().x);
            DEBUG_PRINT(" = ");
            DEBUG_PRINT(tileXIdx);
            DEBUG_PRINT(", coordToTileIndexY ");
            DEBUG_PRINT(prince.getPosition().y);
            DEBUG_PRINT(" = ");
            DEBUG_PRINTLN(tileYIdx);
            #endif

            switch (prince.getDirection()) {

                case Direction::Left:
                    {

                        #if defined(DEBUG) && defined(DEBUG_ACTION_CANMOVEFORWARD)
                        int8_t bgTile1 = this->getTile(Layer::Background, tileXIdx, tileYIdx, true);
                        #endif

                        int8_t bgTile2 = this->getTile(Layer::Background, tileXIdx - 1, tileYIdx, true);
                        int8_t bgTile3 = this->getTile(Layer::Background, tileXIdx - 2, tileYIdx, true);
                        int8_t bgTile4 = this->getTile(Layer::Background, tileXIdx - 3, tileYIdx, true);

                        #if defined(DEBUG) && defined(DEBUG_ACTION_CANMOVEFORWARD)
                        int8_t fgTile1 = this->getTile(Layer::Foreground, tileXIdx, tileYIdx, true);
                        #endif

                        int8_t fgTile2 = this->getTile(Layer::Foreground, tileXIdx - 1, tileYIdx, true);
                        int8_t fgTile3 = this->getTile(Layer::Foreground, tileXIdx - 2, tileYIdx, true);
                        int8_t fgTile4 = this->getTile(Layer::Foreground, tileXIdx - 3, tileYIdx, true);
                        
                        int8_t distToEdgeOfCurrentTile = distToEdgeOfTile(prince.getDirection(), prince.getPosition().x);

                        #if defined(DEBUG) && defined(DEBUG_ACTION_CANMOVEFORWARD)
                        DEBUG_PRINT(" dist ");
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

                                        #if defined(DEBUG) && defined(DEBUG_ACTION_CANMOVEFORWARD)
                                        printTileInfo(bgTile2, fgTile2);
                                        #endif

                                        return (!this->isWallTile(bgTile2, fgTile2) && (this->isGroundTile(bgTile2, fgTile2) || this->canFall(bgTile2, fgTile2)));

                                    default:
                                        return true;

                                }

                                break;

                            case Action::Step:
                            case Action::RunStart:

                                switch (distToEdgeOfCurrentTile) {

                                    case 0 ... 9:

                                        #if defined(DEBUG) && defined(DEBUG_ACTION_CANMOVEFORWARD)
                                        printTileInfo(bgTile2, fgTile2);
                                        #endif

                                        return (!this->isWallTile(bgTile2, fgTile2) && (this->isGroundTile(bgTile2, fgTile2) || this->canFall(bgTile2, fgTile2)));

                                    default:
                                        return true;

                                }

                                break;

                            case Action::RunRepeat:

                                return (this->isGroundTile(bgTile2, fgTile2) || this->canFall(bgTile2, fgTile2));

                            case Action::StandingJump:

                                switch (distToEdgeOfCurrentTile) {

                                    case  2 ... 12:

//                                        if (this->isGroundTile(bgTile2, fgTile2) && this->isGroundTile(bgTile3, fgTile3) && this->isGroundTile(bgTile4, fgTile4)) {
                                        if (!this->isWallTile(bgTile2, fgTile2)) {
                                            return true;                                            
                                        }

                                        return false;

                                    default:

//                                        if (this->isGroundTile(bgTile2, fgTile2) && this->isGroundTile(bgTile3, fgTile3)) {
                                        if (!this->isWallTile(bgTile2, fgTile2)) {
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

                        #if defined(DEBUG) && defined(DEBUG_ACTION_CANMOVEFORWARD)
                        int8_t bgTile1 = this->getTile(Layer::Background, tileXIdx, tileYIdx, true);
                        #endif
                        
                        int8_t bgTile2 = this->getTile(Layer::Background, tileXIdx + 1, tileYIdx, true);
                        int8_t bgTile3 = this->getTile(Layer::Background, tileXIdx + 2, tileYIdx, true);
                        int8_t bgTile4 = this->getTile(Layer::Background, tileXIdx + 3, tileYIdx, true);

                        #if defined(DEBUG) && defined(DEBUG_ACTION_CANMOVEFORWARD)
                        int8_t fgTile1 = this->getTile(Layer::Foreground, tileXIdx, tileYIdx, true);
                        #endif

                        int8_t fgTile2 = this->getTile(Layer::Foreground, tileXIdx + 1, tileYIdx, true);
                        int8_t fgTile3 = this->getTile(Layer::Foreground, tileXIdx + 2, tileYIdx, true);
                        int8_t fgTile4 = this->getTile(Layer::Foreground, tileXIdx + 3, tileYIdx, true);
                        
                        int8_t distToEdgeOfCurrentTile = distToEdgeOfTile(prince.getDirection(), prince.getPosition().x);

                        #if defined(DEBUG) && defined(DEBUG_ACTION_CANMOVEFORWARD)
                        printAction(action);
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

                                        #if defined(DEBUG) && defined(DEBUG_ACTION_CANMOVEFORWARD)
                                        printTileInfo(bgTile2, fgTile2);
                                        #endif

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

                                        // if (this->isGroundTile(bgTile2, fgTile2) && this->isGroundTile(bgTile3, fgTile3) && this->isGroundTile(bgTile4, fgTile4)) {
                                        if (!this->isWallTile(bgTile2, fgTile2)) {
                                            return true;                                            
                                        }

                                        return false;

                                    default:

                                        // if (this->isGroundTile(bgTile2, fgTile2) && this->isGroundTile(bgTile3, fgTile3)) {
                                        if (!this->isWallTile(bgTile2, fgTile2)) {
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

        CanJumpUpResult canJumpUp(Prince &prince) {

            switch (prince.getDirection()) {

                case Direction::Left:
                    {
                        CanJumpUpResult resultLeft = this->canJumpUp_Test(prince, Direction::Left);

                        switch (resultLeft) {

                            case CanJumpUpResult::Jump:
                            case CanJumpUpResult::StepThenJump:

                                #if defined(DEBUG) && defined(DEBUG_ACTION_CANJUMPUP)
                                DEBUG_PRINT("Left Test success, Return ");
                                DEBUG_PRINTLN(static_cast<uint8_t>(resultLeft));
                                #endif
                                                                    
                                return resultLeft;

                            default:
                                {
                                    CanJumpUpResult resultRight = this->canJumpUp_Test(prince, Direction::Right);

                                    switch (resultRight) {

                                        case CanJumpUpResult::Jump:

                                            #if defined(DEBUG) && defined(DEBUG_ACTION_CANJUMPUP)
                                            DEBUG_PRINT("Right Test success, Return TurnThenJump");
                                            #endif

                                            return CanJumpUpResult::TurnThenJump;

                                        default:

                                            #if defined(DEBUG) && defined(DEBUG_ACTION_CANJUMPUP)
                                            DEBUG_PRINT("Right Test failed, Return ");
                                            DEBUG_PRINTLN(static_cast<uint8_t>(resultLeft));
                                            #endif

                                            return this->canJumpUp_Test_Dist10(prince, Direction::Left);

                                    }

                                }

                                break;

                        }
                        
                    }

                    break;

                case Direction::Right:
                    {
                        CanJumpUpResult resultRight = this->canJumpUp_Test(prince, Direction::Right);

                        switch (resultRight) {

                            case CanJumpUpResult::Jump:
                            case CanJumpUpResult::StepThenJump:

                                #if defined(DEBUG) && defined(DEBUG_ACTION_CANJUMPUP)
                                DEBUG_PRINT("Right Test success, Return ");
                                DEBUG_PRINTLN(static_cast<uint8_t>(resultRight));
                                #endif                            

                                return resultRight;

                            default:
                                {
                                    CanJumpUpResult resultLeft = this->canJumpUp_Test(prince, Direction::Left);

                                    switch (resultLeft) {

                                        case CanJumpUpResult::Jump:

                                            #if defined(DEBUG) && defined(DEBUG_ACTION_CANJUMPUP)
                                            DEBUG_PRINT("Left Test success, Return TurnThenJump");
                                            #endif     

                                            return CanJumpUpResult::TurnThenJump;

                                        default:

                                            #if defined(DEBUG) && defined(DEBUG_ACTION_CANJUMPUP)
                                            DEBUG_PRINT("Left Test failed, Return ");
                                            DEBUG_PRINTLN(static_cast<uint8_t>(resultRight));
                                            #endif     

                                            return this->canJumpUp_Test_Dist10(prince, Direction::Right);

                                    }

                                }

                                break;
                        }
                        
                    }

                    break;

                default:  break;

            }

            #if defined(DEBUG) && defined(DEBUG_ACTION_CANJUMPUP)
            DEBUG_PRINT("Return None");
            #endif

            return CanJumpUpResult::None;            

        }

        CanJumpUpResult canJumpUp_Test(Prince &prince, Direction direction) {

            uint8_t inc = (direction == Direction::Left ? -1 : 1);
            int8_t tileXIdx = this->coordToTileIndexX(direction, prince.getPosition().x) - this->getXLocation();
            int8_t tileYIdx = this->coordToTileIndexY(direction, prince.getPosition().y) - this->getYLocation();

            #if defined(DEBUG) && defined(DEBUG_ACTION_CANJUMPUP)
            DEBUG_PRINT("canJumpUp_Test: coordToTileIndexX ");
            DEBUG_PRINT(prince.getPosition().x);
            DEBUG_PRINT(" = ");
            DEBUG_PRINT(tileXIdx);
            DEBUG_PRINT(", coordToTileIndexY ");
            DEBUG_PRINT(prince.getPosition().y);
            DEBUG_PRINT(" = ");
            DEBUG_PRINTLN(tileYIdx);
            #endif

            int8_t bgTile1 = this->getTile(Layer::Background, tileXIdx, tileYIdx - 1, true);
            int8_t bgTile2 = this->getTile(Layer::Background, tileXIdx + inc, tileYIdx - 1, true);
            int8_t distToEdge = distToEdgeOfTile(direction, prince.getPosition().x);

            #if defined(DEBUG) && defined(DEBUG_ACTION_CANJUMPUP)
            DEBUG_PRINT("dist ");
            DEBUG_PRINT(distToEdge);
            DEBUG_PRINT(", bg ");
            DEBUG_PRINT(bgTile1);
            DEBUG_PRINT(" ");
            DEBUG_PRINT(bgTile2);
            DEBUG_PRINTLN("");
            #endif

            switch (direction) {

                case Direction::Left:

                    switch (distToEdge) {

                        case 7 ... 12:
                            return CanJumpUpResult::JumpThenFall;

                        case 3 ... 6:

                            switch (bgTile1) {

                                case TILE_FLOOR_RH_END:
                                case TILE_FLOOR_RH_END_1:
                                case TILE_FLOOR_RH_END_2:
                                case TILE_FLOOR_RH_END_3:
                                case TILE_FLOOR_RH_END_4:
                                case TILE_FLOOR_RH_END_5:
                                case TILE_FLOOR_RH_END_GATE:
                                    return CanJumpUpResult::StepThenJump;

                                default:                                
                                    return CanJumpUpResult::JumpThenFall;

                            }

                            break;

                        case 0 ... 2:

                            switch (bgTile1) {

                                case TILE_FLOOR_RH_END:
                                case TILE_FLOOR_RH_END_1:
                                case TILE_FLOOR_RH_END_2:
                                case TILE_FLOOR_RH_END_3:
                                case TILE_FLOOR_RH_END_4:
                                case TILE_FLOOR_RH_END_5:
                                case TILE_FLOOR_RH_END_GATE:
                                    return CanJumpUpResult::Jump;

                                default:
                                    return CanJumpUpResult::JumpThenFall;

                            }

                            break;

                    }

                    break;

                case Direction::Right:

                    switch (distToEdge) {

                        case 7 ... 12:
                            return CanJumpUpResult::JumpThenFall;

                        case 3 ... 6:

                            switch (bgTile2) {

                                case TILE_FLOOR_LH_END:
                                case TILE_FLOOR_LH_END_PATTERN_1:
                                case TILE_FLOOR_LH_END_PATTERN_2:
                                    return CanJumpUpResult::StepThenJump;

                                default:                                
                                    return CanJumpUpResult::JumpThenFall;

                            }

                            break;

                        case 0 ... 2:

                            switch (bgTile2) {

                                case TILE_FLOOR_LH_END:
                                case TILE_FLOOR_LH_END_PATTERN_1:
                                case TILE_FLOOR_LH_END_PATTERN_2:
                                    return CanJumpUpResult::Jump;

                                default:
                                    return CanJumpUpResult::JumpThenFall;

                            }

                            break;

                    }

                    break;

                default: break;

            }

            return CanJumpUpResult::None;

        }

        CanJumpUpResult canJumpUp_Test_Dist10(Prince &prince, Direction direction) {

            int8_t tileXIdx = this->coordToTileIndexX(direction, prince.getPosition().x) - this->getXLocation();
            int8_t tileYIdx = this->coordToTileIndexY(direction, prince.getPosition().y) - this->getYLocation();

            #if defined(DEBUG) && defined(DEBUG_ACTION_CANJUMPUP)
            DEBUG_PRINT("canJumpUp_Test_Dist10: coordToTileIndexX ");
            DEBUG_PRINT(prince.getPosition().x);
            DEBUG_PRINT(" = ");
            DEBUG_PRINT(tileXIdx);
            DEBUG_PRINT(", coordToTileIndexY ");
            DEBUG_PRINT(prince.getPosition().y);
            DEBUG_PRINT(" = ");
            DEBUG_PRINTLN(tileYIdx);
            #endif

            int8_t bgTile1 = this->getTile(Layer::Background, tileXIdx, tileYIdx - 1, true);
            int8_t bgTile2 = this->getTile(Layer::Background, tileXIdx, tileYIdx - 1, true);
            int8_t distToEdge = distToEdgeOfTile(direction, prince.getPosition().x);

            #if defined(DEBUG) && defined(DEBUG_ACTION_CANJUMPUP)
            DEBUG_PRINT("dist ");
            DEBUG_PRINT(distToEdge);
            DEBUG_PRINT(", bg ");
            DEBUG_PRINT(bgTile1);
            DEBUG_PRINT(" ");
            DEBUG_PRINT(bgTile2);
            DEBUG_PRINTLN("");
            #endif

            switch (direction) {

                case Direction::Left:

                    switch (distToEdge) {

                        case 10:

                            switch (bgTile1) {

                                case TILE_FLOOR_RH_END:
                                case TILE_FLOOR_RH_END_1:
                                case TILE_FLOOR_RH_END_2:
                                case TILE_FLOOR_RH_END_3:
                                case TILE_FLOOR_RH_END_4:
                                case TILE_FLOOR_RH_END_5:
                                case TILE_FLOOR_RH_END_GATE:
                                    return CanJumpUpResult::JumpDist10;

                                default:                                
                                    return CanJumpUpResult::JumpThenFall;

                            }

                            break;

                    }

                    break;

                case Direction::Right:

                    switch (distToEdge) {

                        case 10:

                            switch (bgTile2) {

                                case TILE_FLOOR_LH_END:
                                case TILE_FLOOR_LH_END_PATTERN_1:
                                case TILE_FLOOR_LH_END_PATTERN_2:
                                    return CanJumpUpResult::JumpDist10;

                                default:                                
                                    return CanJumpUpResult::JumpThenFall;

                            }

                            break;

                    }

                    break;

                default: break;

            }

            return CanJumpUpResult::None;

        }

        bool canJumpUp_Part2(Prince &prince) {

            int8_t tileXIdx = 0;
            int8_t tileYIdx = 0;

            switch (prince.getDirection()) {

                case Direction::Left:
                    {

                        tileXIdx = this->coordToTileIndexX(prince.getDirection(), prince.getPosition().x) - this->getXLocation();
                        tileYIdx = this->coordToTileIndexY(prince.getDirection(), prince.getPosition().y) - this->getYLocation() - 1;

                        #if defined(DEBUG) && defined(DEBUG_ACTION_CANJUMPUP_PART2)
                        DEBUG_PRINT("coordToTileIndexX ");
                        DEBUG_PRINT(prince.getPosition().x);
                        DEBUG_PRINT(" = ");
                        DEBUG_PRINT(tileXIdx);
                        DEBUG_PRINT(", coordToTileIndexY ");
                        DEBUG_PRINT(prince.getPosition().y);
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

                        tileXIdx = this->coordToTileIndexX(prince.getDirection(), prince.getPosition().x) - this->getXLocation() + 1;
                        tileYIdx = this->coordToTileIndexY(prince.getDirection(), prince.getPosition().y) - this->getYLocation() - 1;

                        #if defined(DEBUG) && defined(DEBUG_ACTION_CANJUMPUP_PART2)
                        DEBUG_PRINT("coordToTileIndexX ");
                        DEBUG_PRINT(prince.getPosition().x);
                        DEBUG_PRINT(" = ");
                        DEBUG_PRINT(tileXIdx);
                        DEBUG_PRINT(", coordToTileIndexY ");
                        DEBUG_PRINT(prince.getPosition().y);
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

        CanClimbDownResult canClimbDown(Prince &prince) {

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

        CanClimbDownResult canClimbDown_Test(Prince &prince, Direction direction) {

            int8_t tileXIdx = this->coordToTileIndexX(direction, prince.getPosition().x) - this->getXLocation() + (direction == Direction::Right ? 1 : 0);
            int8_t tileYIdx = this->coordToTileIndexY(direction, prince.getPosition().y) - this->getYLocation();

            #if defined(DEBUG) && defined(DEBUG_ACTION_CANCLIMBDOWN)
            DEBUG_PRINT("coordToTileIndexX ");
            DEBUG_PRINT(prince.getPosition().x);
            DEBUG_PRINT(" = ");
            DEBUG_PRINT(tileXIdx);
            DEBUG_PRINT(", coordToTileIndexY ");
            DEBUG_PRINT(prince.getPosition().y);
            DEBUG_PRINT(" = ");
            DEBUG_PRINTLN(tileYIdx);
            #endif

            int8_t bgTile1 = this->getTile(Layer::Background, tileXIdx, tileYIdx, true);
            int8_t distToEdge = distToEdgeOfTile(direction, prince.getPosition().x);

            #if defined(DEBUG) && defined(DEBUG_ACTION_CANCLIMBDOWN)
            DEBUG_PRINT("dist ");
            DEBUG_PRINT(distToEdge);
            DEBUG_PRINT(", bg ");
            DEBUG_PRINT(bgTile1);
            DEBUG_PRINTLN("");
            #endif

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
                                case TILE_FLOOR_RH_END_1:
                                case TILE_FLOOR_RH_END_2:
                                case TILE_FLOOR_RH_END_3:
                                case TILE_FLOOR_RH_END_4:
                                case TILE_FLOOR_RH_END_5:
                                case TILE_FLOOR_RH_END_GATE:
                                    return CanClimbDownResult::StepThenClimbDown;

                                default:                                
                                    return CanClimbDownResult::None;

                            }

                            break;

                        case 0 ... 2:

                            switch (bgTile1) {

                                case TILE_FLOOR_RH_END:
                                case TILE_FLOOR_RH_END_1:
                                case TILE_FLOOR_RH_END_2:
                                case TILE_FLOOR_RH_END_3:
                                case TILE_FLOOR_RH_END_4:
                                case TILE_FLOOR_RH_END_5:
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


        #if defined(DEBUG)
        void printAction(Action action) {

            switch (action) {

                case Action::SmallStep:
                    DEBUG_PRINT("SmallStep");
                    break;

                case Action::CrouchHop:
                    DEBUG_PRINT("CrouchHop");
                    break;

                case Action::Step:
                    DEBUG_PRINT("Step");
                    break;

                case Action::RunStart:
                    DEBUG_PRINT("RunStart");
                    break;

                case Action::RunRepeat:
                    DEBUG_PRINT("RunRepeat");
                    break;

                case Action::StandingJump:
                    DEBUG_PRINT("StandingJump");
                    break;

            }

        }

        void printTileInfo(int8_t bgTile, int8_t fgTile) {

            DEBUG_PRINT("isWallTile(");
            DEBUG_PRINT(bgTile);
            DEBUG_PRINT(",");
            DEBUG_PRINT(fgTile);
            DEBUG_PRINT(") ");
            DEBUG_PRINT(this->isWallTile(bgTile, fgTile));
            DEBUG_PRINT(", isGroundTile() ");
            DEBUG_PRINT(this->isGroundTile(bgTile, fgTile));
            DEBUG_PRINT(", canFall() ");
            DEBUG_PRINTLN(this->canFall(bgTile, fgTile));
        
        }
        #endif


};