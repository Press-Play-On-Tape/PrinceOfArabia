#pragma once

#include "../utils/Arduboy2Ext.h"
#include "Prince.h"   
#include "../utils/Constants.h"
#include "../utils/Stack.h"
#include "Item.h"

#define TILE_NONE -1
#define TILE_FLOOR_NONE 75
#define TILE_FLOOR_NONE_PATTERN 92

#define TILE_FLOOR_NONE_LH_WALL_1 97
#define TILE_FLOOR_NONE_LH_WALL_2 120
#define TILE_FLOOR_NONE_LH_WALL_3 91
#define TILE_FLOOR_NONE_LH_WALL_4 119


#define TILE_FLOOR_BASIC 77
#define TILE_FLOOR_BASIC_TORCH 127
#define TILE_FLOOR_LH_END 76
#define TILE_FLOOR_PATTERN_1 78
#define TILE_FLOOR_PATTERN_2 79
#define TILE_FLOOR_LH_END_PATTERN_1 102
#define TILE_FLOOR_LH_END_PATTERN_2 93
#define TILE_FLOOR_RH_END 99
#define TILE_FLOOR_RH_END_GATE 118
#define TILE_FLOOR_GATE_REAR_TRACK 114
#define TILE_FLOOR_GATE_FRONT_TRACK_1 115
#define TILE_FLOOR_GATE_FRONT_TRACK_2 116
#define TILE_FLOOR_GATE_FRONT_TRACK_3 116

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


#define TILE_COLLAPSING_FLOOR - 2

struct Level {

    private:

        uint8_t level = 0;
        uint8_t xLoc = 60;
        uint8_t yLoc = 0;
        uint8_t yOffset = 0;                        // Ofset when rendering.
        Direction yOffsetDir = Direction::None;     // Ofset movement

        int8_t bg[5][16];
        int8_t fg[5][16];
        Item items[Constants::NumberOfItems];

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

        void init(Prince &prince, uint8_t xLoc, uint8_t yLoc) {

            this->xLoc = xLoc;
            this->yLoc = yLoc;

            this->loadMap();
            this->loadItems();

            if (prince.getY() > 56) {

                this->yOffset = prince.getY() - 56;

            }

        }


        void incYOffset(int8_t inc) {

            this->yOffset = this->yOffset + inc;
        }


        void update(Arduboy2Ext &arduboy) { 


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

            for (uint8_t i = 0; i < Constants::NumberOfItems; i++) {

                Item &item = this->getItem(i);

                if (item.itemType != ItemType::None) {

                    switch (item.itemType) {

                        case ItemType::ExitDoor:

                            if (arduboy.isFrameCount(2)) {
                             
                                if (item.data.exitDoor.direction == Direction::Up && item.data.exitDoor.position < 11) {

                                    item.data.exitDoor.position++;

                                }

                            }

                            break;

                        case ItemType::Flash:

                            if (item.data.flash.frame > 0) {

                                if (arduboy.isFrameCount(2)) {
                                        
                                    item.data.flash.frame--;

                                    if (item.data.flash.frame == 0) {

                                        item.itemType = ItemType::None;

                                    }
                                        
                                }

                            }

                            break;


                        case ItemType::Gate:

                            if (arduboy.isFrameCount(4)) {

                                if (item.data.gate.closingDelay + 9 > item.data.gate.closingDelayMax) {

                                    if (item.data.gate.position < 9) {

                                        item.data.gate.position++;

                                    }

                                }
                                else if (item.data.gate.closingDelay > 0 && item.data.gate.closingDelay <= 9) {

                                    if (item.data.gate.position > 0 ) {

                                        item.data.gate.position--;
                                        
                                    }
                                    
                                    break;

                                }
 
                                if (item.data.gate.closingDelay > 0) {

                                    item.data.gate.closingDelay--;

                                }
                            }
                            break;

                        case ItemType::CollapsingFloor:

                            if (arduboy.isFrameCount(4) && item.data.collapsingFloor.frame > 0) {

                                item.data.collapsingFloor.frame--;

                            }

                            if (item.data.collapsingFloor.timeToFall > 1) {

                                item.data.collapsingFloor.timeToFall--;

                            }

                            if (item.data.collapsingFloor.timeToFall == 1) {

                                item.data.collapsingFloor.distanceFallen = item.data.collapsingFloor.distanceFallen + 2;

                                if (item.data.collapsingFloor.distanceFallen >= item.data.collapsingFloor.distToFall) {

                                    item.y = item.y + ((item.data.collapsingFloor.distToFall / 31) + 1);
                                    item.itemType = ItemType::CollpasedFloor;

                                }

                                return (item.data.collapsingFloor.timeToFall == 1 && item.data.collapsingFloor.distanceFallen == 2);

                            }

                            break;

                        case ItemType::Potion_Small:

                            if (arduboy.isFrameCount(4)) {

                                item.data.potionSmall.frame = !item.data.potionSmall.frame;

                            }
                            break;

                        case ItemType::FloorButton1:

                            if (arduboy.isFrameCount(4)) {

                                if (item.data.floorButton1.timeToFall > 1) {

                                    item.data.floorButton1.timeToFall--;

                                }

                                if (item.data.floorButton1.timeToFall == 1) {
                                
                                    item.data.floorButton1.frame = 0;
                                    item.data.floorButton1.timeToFall = 0;

                                }

                            }
                            break;

                        case ItemType::FloorButton2:

                            if (arduboy.isFrameCount(4)) {

                                if (item.data.floorButton2.timeToFall > 1) {

                                    item.data.floorButton2.timeToFall--;

                                }

                                if (item.data.floorButton2.timeToFall == 1) {
                                
                                    item.data.floorButton2.frame = 0;
                                    item.data.floorButton2.timeToFall = 0;

                                }

                            }
                            break;

                        case ItemType::Spikes:

                            if (arduboy.isFrameCount(4)) {

                                if (item.data.spikes.closingDelay > 0) {

                                    item.data.spikes.closingDelay--;

                                    switch (item.data.spikes.closingDelay) {

                                        case 1 ... 3:
                                            item.data.spikes.position--;
                                            break;
                                        
                                        default: break;
                                        
                                    }

                                }

                            }
                            break;

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

        int8_t getTile(Layer layer, int8_t x, int8_t y, int8_t returnCollapsingTile) { 

            switch (layer) {

                case Layer::Foreground:

                    #if defined(DEBUG) && defined(DEBUG_GET_TILE)
                    DEBUG_PRINT(F("getTile(FG, "));
                    DEBUG_PRINT(x);
                    DEBUG_PRINT(F(","));
                    DEBUG_PRINT(y);
                    DEBUG_PRINT(F(") = "));
                    DEBUG_PRINTLN(fg[y + 1][x + 3]);
                    #endif

                    return fg[y + 1][x + 3];

                case Layer::Background:
                    {
                        int8_t tile = bg[y + 1][x + 3];

                        #if defined(DEBUG) && defined(DEBUG_GET_TILE)
                        DEBUG_PRINT(F("getTile(BG, "));
                        DEBUG_PRINT(x);
                        DEBUG_PRINT(F(","));
                        DEBUG_PRINT(y);
                        DEBUG_PRINT(F(") = "));
                        DEBUG_PRINTLN(tile);
                        #endif


                        // Substitute tiles if needed ..

                        if (returnCollapsingTile != TILE_NONE && this->isCollapsingFloor(this->xLoc + x, this->yLoc + y)) {

                            return returnCollapsingTile;

                        }

                        return tile;

                    }

                    break;


            }

            return TILE_NONE;

        }


        // Locate the itemType at x, y.  Return the index of the specified itemType

        uint8_t getItem(ItemType itemType, int8_t x, int8_t y) {

            for (uint8_t i = 2; i < Constants::NumberOfItems; i++) {
                
                Item &item = this->items[i];

                if (itemType == ItemType::AnyItem) {

                    if (item.itemType != ItemType::None && item.x == x && item.y == y) {
                        return i;
                    }

                }
                else {

                    if (item.itemType != ItemType::None && (item.itemType == itemType) && (item.x == x) && (item.y == y)) {
                        return i;
                    }

                }

            }

            return Constants::NoItemFound;
            
        }


        bool isCollapsingFloor(int8_t x, int8_t y) {

            for (Item &item : this->items) {

                if (item.itemType == ItemType::CollapsingFloor && item.x == x && item.y == y && item.data.collapsingFloor.timeToFall == 0) {
                    return true;
                }

            }

            return false;
            
        }

        void printMap() {

            #if defined(DEBUG) && defined(DEBUG_LEVEL_LOAD_MAP)

            DEBUG_PRINTLN(F("Map ---------------"));
            DEBUG_PRINT(F("xLoc: "));
            DEBUG_PRINT(xLoc);
            DEBUG_PRINT(F(", yLoc: "));
            DEBUG_PRINTLN(yLoc);
            DEBUG_PRINTLN(F("BG ---------------"));

            for (uint8_t y = 0; y < 5; y++) {

                for (uint8_t x = 0; x < 16; x++) {

                    DEBUG_PRINT(bg[y][x]);
                    DEBUG_PRINT(" ");

                    if (x == 2 || x == 12) {
                    DEBUG_PRINT("| ");
                    }

                }

                DEBUG_PRINTLN("");

            }


            DEBUG_PRINTLN(F("FG ---------------"));

            for (uint8_t y = 0; y < 5; y++) {

                for (uint8_t x = 0; x < 16; x++) {

                    DEBUG_PRINT(fg[y][x]);
                    DEBUG_PRINT(" ");

                    if (x == 2 || x == 12) {
                        DEBUG_PRINT("| ");
                    }

                }

                DEBUG_PRINTLN("");

            }

            #endif

        }

        void loadItems() {


            // Deactivate all items ..            

            for (Item &item : items) {
                item.itemType = ItemType::None;
            }


            // Populate first item with explosion ..

            Item &explosion = this->items[0];
            explosion.itemType = ItemType::Flash;

            uint8_t itemIdx = 1;
            FX::seekData(Levels::Level1_Items);
            uint8_t itemType = FX::readPendingUInt8();

            while (itemType != 255) {

                Item &item = this->items[itemIdx];
                item.itemType = static_cast<ItemType>(itemType);
                item.x = FX::readPendingUInt8();
                item.y = FX::readPendingUInt8();

                switch (item.itemType) {

                    case ItemType::ExitDoor:
                        item.data.exitDoor.position = 0;
                        item.data.exitDoor.direction = Direction::None;
                        item.data.exitDoor.left = FX::readPendingUInt8();;
                        item.data.exitDoor.right = FX::readPendingUInt8();;
                        break;

                    case ItemType::Gate:
                        item.data.gate.position = FX::readPendingUInt8();
                        item.data.gate.closingDelay = FX::readPendingUInt8();
                        item.data.gate.closingDelayMax = 255;
                        break;

                    case ItemType::CollapsingFloor:
                        item.data.collapsingFloor.distanceFallen = 0;
                        item.data.collapsingFloor.distToFall = FX::readPendingUInt8();
                        break;

                    case ItemType::FloorButton1:
                        item.data.floorButton1.frame = 0;
                        item.data.floorButton1.gateX = FX::readPendingUInt8();
                        item.data.floorButton1.gateY = FX::readPendingUInt8();
                        item.data.floorButton1.timeToFall = 0;
                        break;

                    case ItemType::FloorButton2:
                        item.data.floorButton2.frame = 0;
                        item.data.floorButton2.gateX = FX::readPendingUInt8();
                        item.data.floorButton2.gateY = FX::readPendingUInt8();
                        item.data.floorButton2.timeToFall = 0;
                        break;
                    
                    case ItemType::Spikes:
                        item.data.spikes.imageType = FX::readPendingUInt8();
                        item.data.spikes.position = 3;
                        break;

                    default:
                        break;

                }

                itemType = FX::readPendingUInt8();
                itemIdx++;

            }

            FX::readEnd();

        }

        void loadMap() {


            // Background ..

            for (int8_t y = this->yLoc - 1; y < yLoc + 4; y++) {

                if (y < 0) {

                    for (uint8_t x = 0; x < 16; x++) {
                        
                        bg[y - this->yLoc + 1][x] = TILE_FG_WALL_1;

                    }

                }
                else {

                    if (y == 0 && this->xLoc == 0) {

                        FX::seekData(static_cast<uint24_t>(Levels::Level1_BG + (y * Levels::Level1_Width) + this->xLoc));

                        for (uint8_t x = 0; x < 16; x++) {

                            if (x < 3) {

                                bg[y - this->yLoc + 1][x] = TILE_FG_WALL_1;

                            }
                            else {

                                int8_t tileId = static_cast<int8_t>(FX::readPendingUInt8());
                                bg[y - this->yLoc + 1][x] = tileId;

                            }

                        }

                        FX::readEnd();

                    }
                    else {

                        FX::seekData(static_cast<uint24_t>(Levels::Level1_BG + (y * Levels::Level1_Width) + this->xLoc - 3));

                        for (uint8_t x = 0; x < 16; x++) {

                            int8_t tileId = static_cast<int8_t>(FX::readPendingUInt8());
                            bg[y - this->yLoc + 1][x] = tileId;

                        }

                        FX::readEnd();

                    }

                }

            }


            // Foreground ..

            for (int8_t y = this->yLoc - 1; y < this->yLoc + 4; y++) {

                if (y < 0) {

                    for (uint8_t x = 0; x < 16; x++) {

                        fg[y - this->yLoc + 1][x] = TILE_FG_WALL_1;

                    }

                }
                else {

                    if (y == 0 && this->xLoc == 0) {

                        FX::seekData(static_cast<uint24_t>(Levels::Level1_FG + (y * Levels::Level1_Width) + this->xLoc));

                        for (uint8_t x = 0; x < 16; x++) {

                            if (x < 3) {

                                bg[y - this->yLoc + 1][x] = TILE_FG_WALL_1;

                            }
                            else {

                                int8_t tileId = static_cast<int8_t>(FX::readPendingUInt8());
                                fg[y - this->yLoc + 1][x] = tileId;

                            }

                        }

                        FX::readEnd();

                    }
                    else {

                        FX::seekData(static_cast<uint24_t>(Levels::Level1_FG + (y * Levels::Level1_Width) + this->xLoc - 3));

                        for (uint8_t x = 0; x < 16; x++) {

                            int8_t tileId = static_cast<int8_t>(FX::readPendingUInt8());
                            fg[y - this->yLoc + 1][x] = tileId;

                        }

                        FX::readEnd();

                    }

                }

            }

            #if defined(DEBUG) && defined(DEBUG_LEVEL_LOAD_MAP)
            printMap();
            #endif

        }


        WallTileResults isWallTile(int8_t bgTile, int8_t fgTile, int8_t x = Constants::CoordNone, int8_t y = Constants::CoordNone) {

// Serial.print("isWallTile ");
// Serial.print(bgTile);
// Serial.print(", ");
// Serial.print(fgTile);
// Serial.print(", ");
// Serial.print(x);
// Serial.print(", ");
// Serial.print(y);
// Serial.println("");

            switch (fgTile) {

                case TILE_FG_WALL_1:
                case TILE_FG_WALL_2:
                case TILE_FG_WALL_3:
                case TILE_FG_WALL_4:
                case TILE_FG_WALL_5:
                case TILE_FG_WALL_6:
                    return WallTileResults::Normal;

                default: 

// Serial.println("Look for gate");

                    uint8_t offset = 0;

                    switch (bgTile) {

                        case TILE_FLOOR_GATE_REAR_TRACK:
                            offset = 1;
                            break;
                    }

                    if (x != Constants::CoordNone && y != Constants::CoordNone) {

                        uint8_t idx = this->getItem(ItemType::Gate, x + this->getXLocation() + offset, y + this->getYLocation());

                        if (idx != Constants::NoItemFound) {

                            Item &item = this->getItem(idx);
// Serial.print("Found gate ");
// Serial.println(item.data.gate.position);

                            if (item.data.gate.position == 0) {

                                return WallTileResults::GateClosed;

                            }

                        }

                    }

                    return WallTileResults::None;

            }

        }


        bool isGroundTile(int8_t bgTile, int8_t fgTile) {

            switch (bgTile) {

                case TILE_FLOOR_BASIC:
                case TILE_FLOOR_BASIC_TORCH:
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
                case TILE_FLOOR_GATE_REAR_TRACK:
                case TILE_FLOOR_GATE_FRONT_TRACK_1:
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

        bool canFall(int8_t bgTile, int8_t fgTile, int8_t x = Constants::CoordNone, int8_t y = Constants::CoordNone) {

            WallTileResults wallTile = this->isWallTile(bgTile, fgTile, x, y);

            if (wallTile != WallTileResults::None) {

                #if defined(DEBUG) && defined(DEBUG_ACTION_CANFALL)
                DEBUG_PRINTLN(" true (a wall tile)");
                #endif                

                return false;
            }

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

                    if (x != Constants::CoordNone && y != Constants::CoordNone) {

                        uint8_t idx = this->getItem(ItemType::CollapsingFloor, x + this->getXLocation(), y + this->getYLocation());

                        if (idx != Constants::NoItemFound) {

                            Item &item = this->getItem(idx);

                            if (item.data.collapsingFloor.distanceFallen == 0) {

                                #if defined(DEBUG) && defined(DEBUG_ACTION_CANFALL)
                                DEBUG_PRINTLN(" false (on collapsing floor");
                                #endif

                                return false;

                            }

                        }

                    }

                    #if defined(DEBUG) && defined(DEBUG_ACTION_CANFALL)
                    DEBUG_PRINTLN(" true");
                    #endif

                    return true;

            }

            #if defined(DEBUG) && defined(DEBUG_ACTION_CANFALL)
            DEBUG_PRINTLN(" false");
            #endif

            return false;

        }

        bool canFall(Prince &prince, int8_t xOffset = 0) {

            bool canFall = false;
            Point newPos = prince.getPosition();
            newPos.x = newPos.x + prince.getDirectionOffset(xOffset);

            uint8_t imageIndex = static_cast<uint8_t>(pgm_read_byte(&Constants::StanceToImageXRef[prince.getStance()]));
            uint16_t pos = (imageIndex - 1) * 3;

            int8_t footToe = static_cast<int8_t>(pgm_read_byte(&Constants::Prince_ImageDetails[pos + 1]));
            int8_t footHeel = static_cast<int8_t>(pgm_read_byte(&Constants::Prince_ImageDetails[pos + 2]));

            int8_t tileXIdx = this->coordToTileIndexX(prince.getDirection(), newPos.x + prince.getDirectionOffset(footToe)) - this->getXLocation();
            int8_t tileYIdx = this->coordToTileIndexY(prince.getDirection(), newPos.y) - this->getYLocation();
            
            int8_t bgTile1 = this->getTile(Layer::Background, tileXIdx, tileYIdx, TILE_FLOOR_BASIC);
            int8_t fgTile1 = this->getTile(Layer::Foreground, tileXIdx, tileYIdx, TILE_FLOOR_BASIC);
            
            #if defined(DEBUG) && defined(DEBUG_ACTION_CANFALL)
            DEBUG_PRINT(F("canFall(toe) stance:"));
            DEBUG_PRINT(prince.getStance());
            DEBUG_PRINT(F(", ii:"));
            DEBUG_PRINT(imageIndex);
            DEBUG_PRINT(F(", r:"));
            DEBUG_PRINT(reach);
            DEBUG_PRINT(F(", ft "));
            DEBUG_PRINT(footToe);
            DEBUG_PRINT(F(", fh "));
            DEBUG_PRINT(footHeel);
            DEBUG_PRINT(F(", bg "));
            DEBUG_PRINT(bgTile1);
            DEBUG_PRINT(F(", fg "));
            DEBUG_PRINT(fgTile1);
            DEBUG_PRINT(" = ");
            #endif

            
            if (footToe != Constants::InAir) {
            
                canFall = this->canFall(bgTile1, fgTile1, tileXIdx, tileYIdx);


                // If we the price cannot fall then return this now.  Ortherwise check the heel position ..

                if (!canFall) {

                    return false;

                }
                else {

                    int8_t tileXIdx = this->coordToTileIndexX(prince.getDirection(), newPos.x + prince.getDirectionOffset(footHeel)) - this->getXLocation();
                    int8_t tileYIdx = this->coordToTileIndexY(prince.getDirection(), newPos.y) - this->getYLocation();
                    
                    int8_t bgTile1 = this->getTile(Layer::Background, tileXIdx, tileYIdx, TILE_FLOOR_BASIC);
                    int8_t fgTile1 = this->getTile(Layer::Foreground, tileXIdx, tileYIdx, TILE_FLOOR_BASIC);
                    
                    #if defined(DEBUG) && defined(DEBUG_ACTION_CANFALL)
                    DEBUG_PRINT(F("canFall(heel) stance:"));
                    DEBUG_PRINT(prince.getStance());
                    DEBUG_PRINT(F(", r:"));
                    DEBUG_PRINT(reach);
                    DEBUG_PRINT(F(", ft "));
                    DEBUG_PRINT(footToe);
                    DEBUG_PRINT(F(", fh "));
                    DEBUG_PRINT(footHeel);
                    DEBUG_PRINT(F(", bg "));
                    DEBUG_PRINT(bgTile1);
                    DEBUG_PRINT(F(", fg "));
                    DEBUG_PRINT(fgTile1);
                    DEBUG_PRINT(" = ");
                    #endif

                    canFall = this->canFall(bgTile1, fgTile1, tileXIdx, tileYIdx);

                    return canFall;

                }

            }
            else {

                #if defined(DEBUG) && defined(DEBUG_ACTION_CANFALL)
                DEBUG_PRINTLN(" footToe=InAir ");
                #endif

            }

            return false;
        
        }

        bool canFallSomeMore(Prince &prince, int8_t xOffset = 0) {

            bool canFall = false;
            Point newPos = prince.getPosition();
            newPos.x = newPos.x + prince.getDirectionOffset(xOffset);

            int8_t tileXIdx = this->coordToTileIndexX(prince.getDirection(), newPos.x) - this->getXLocation();
            int8_t tileYIdx = this->coordToTileIndexY(prince.getDirection(), newPos.y) - this->getYLocation();
            
            int8_t bgTile1 = this->getTile(Layer::Background, tileXIdx, tileYIdx, TILE_FLOOR_BASIC);
            int8_t fgTile1 = this->getTile(Layer::Foreground, tileXIdx, tileYIdx, TILE_FLOOR_BASIC);
                        
            canFall = this->canFall(bgTile1, fgTile1, tileXIdx, tileYIdx);

            #if defined(DEBUG) && defined(DEBUG_ACTION_CANFALLSOMEMORE)
            DEBUG_PRINT(F("canFallSomeMore() stance:"));
            DEBUG_PRINT(prince.getStance());
            DEBUG_PRINT(F(", bg "));
            DEBUG_PRINT(bgTile1);
            DEBUG_PRINT(F(", fg "));
            DEBUG_PRINT(fgTile1);
            DEBUG_PRINT(" = ");
            if (canFall) {
                DEBUG_PRINTLN("true");
            }
            else {
                DEBUG_PRINTLN("false");
            }
            #endif

            return canFall;
        
        }


        // Prince is hanging from upper level.  Test to see if he can fall down one level, down one level and 'back, down twwo levels, three .. etc.

        CanClimbDownPart2Result canClimbDown_Part2(Prince &prince, int8_t xOffset = 0) { 

            Point newPos = prince.getPosition();
            newPos.x = newPos.x + prince.getDirectionOffset(xOffset);

            int8_t tileXIdx = this->coordToTileIndexX(prince.getDirection(), newPos.x) - this->getXLocation();
            int8_t tileYIdx = this->coordToTileIndexY(prince.getDirection(), newPos.y) - this->getYLocation();

            #if defined(DEBUG) && defined(DEBUG_ACTION_CANCLIMBDOWN_PART2)
            printCoordToIndex(newPos, tileXIdx, tileYIdx);
            #endif

            int8_t bgTile = this->getTile(Layer::Background, tileXIdx + (prince.getDirection() == Direction::Left ? 1 : 0), tileYIdx, TILE_FLOOR_BASIC);
            int8_t fgTile = this->getTile(Layer::Foreground, tileXIdx + (prince.getDirection() == Direction::Left ? 1 : 0), tileYIdx, TILE_FLOOR_BASIC);

            #if defined(DEBUG) && defined(DEBUG_ACTION_CANCLIMBDOWN_PART2)
            DEBUG_PRINT(F("canClimbDown_Part2() Test can land 1 level below ("));
            DEBUG_PRINT(tileXIdx + (prince.getDirection() == Direction::Left ? 1 : 0));
            DEBUG_PRINT(F(","));
            DEBUG_PRINT(tileYIdx);
            DEBUG_PRINT(F(") bg "));
            DEBUG_PRINT(bgTile);
            DEBUG_PRINT(F(", fg "));
            DEBUG_PRINT(fgTile);
            DEBUG_PRINT(F(", isGroundTile: "));
            DEBUG_PRINT(this->isGroundTile(bgTile, fgTile));
            #endif

            bool isGroundTile = this->isGroundTile(bgTile, fgTile);

            if (isGroundTile) {

                #if defined(DEBUG) && defined(DEBUG_ACTION_CANCLIMBDOWN_PART2)
                DEBUG_PRINTLN(" return Level_1");
                #endif
                
                return CanClimbDownPart2Result::Level_1;

            }

            bgTile = this->getTile(Layer::Background, tileXIdx + (prince.getDirection() == Direction::Left ? 0 : 1), tileYIdx, TILE_FLOOR_BASIC);
            fgTile = this->getTile(Layer::Foreground, tileXIdx + (prince.getDirection() == Direction::Left ? 0 : 1), tileYIdx, TILE_FLOOR_BASIC);

            #if defined(DEBUG) && defined(DEBUG_ACTION_CANCLIMBDOWN_PART2)
            DEBUG_PRINTLN(" skip");
            DEBUG_PRINT(F("canClimbDown_Part2() Test can land 1 level below and under ("));
            DEBUG_PRINT(tileXIdx + (prince.getDirection() == Direction::Left ? 0 : 1));
            DEBUG_PRINT(F(","));
            DEBUG_PRINT(tileYIdx);
            DEBUG_PRINT(F(") bg "));
            DEBUG_PRINT(bgTile);
            DEBUG_PRINT(F(", fg "));
            DEBUG_PRINT(fgTile);
            DEBUG_PRINT(F(", isGroundTile: "));
            DEBUG_PRINT(this->isGroundTile(bgTile, fgTile));
            #endif

            isGroundTile = this->isGroundTile(bgTile, fgTile);

            if (isGroundTile) {

                #if defined(DEBUG) && defined(DEBUG_ACTION_CANCLIMBDOWN_PART2)
                DEBUG_PRINTLN(" return Level_1_Under");
                #endif
                
                return CanClimbDownPart2Result::Level_1_Under;

            }

            #if defined(DEBUG) && defined(DEBUG_ACTION_CANCLIMBDOWN_PART2)
            DEBUG_PRINTLN(" return Falling");
            #endif

            return CanClimbDownPart2Result::Falling;

        }

        uint8_t canReachItem(Prince &prince, ItemType itemType) {

            int8_t tileXIdx = this->coordToTileIndexX(prince.getDirection(), prince.getPosition().x);
            int8_t tileYIdx = this->coordToTileIndexY(prince.getDirection(), prince.getPosition().y);

            for (uint8_t i = 2; i < Constants::NumberOfItems; i++) {

                Item &item = this->items[i];

                if (item.itemType == itemType && item.x == tileXIdx && item.y == tileYIdx) {

                    return i;

                }

            }

            return Constants::NoItemFound;

        }

        bool canMoveForward(Action action, Prince &prince) {

            int8_t tileXIdx = this->coordToTileIndexX(prince.getDirection(), prince.getPosition().x) - this->getXLocation();
            int8_t tileYIdx = this->coordToTileIndexY(prince.getDirection(), prince.getPosition().y) - this->getYLocation();

            #if defined(DEBUG) && defined(DEBUG_ACTION_CANMOVEFORWARD)
            DEBUG_PRINTLN(F("------------------------------"));
            printAction(action);
            DEBUG_PRINT(F(" coordToTileIndexX "));
            DEBUG_PRINT(prince.getPosition().x);
            DEBUG_PRINT(F(" = "));
            DEBUG_PRINT(tileXIdx);
            DEBUG_PRINT(F(", coordToTileIndexY "));
            DEBUG_PRINT(prince.getPosition().y);
            DEBUG_PRINT(F(" = "));
            DEBUG_PRINTLN(tileYIdx);
            #endif

            switch (prince.getDirection()) {

                case Direction::Left:
                    {
                        int8_t bgTile4 = this->getTile(Layer::Background, tileXIdx - 3, tileYIdx, TILE_FLOOR_BASIC);
                        int8_t fgTile4 = this->getTile(Layer::Foreground, tileXIdx - 3, tileYIdx, TILE_FLOOR_BASIC);
                        int8_t bgTile3 = this->getTile(Layer::Background, tileXIdx - 2, tileYIdx, TILE_FLOOR_BASIC);
                        int8_t fgTile3 = this->getTile(Layer::Foreground, tileXIdx - 2, tileYIdx, TILE_FLOOR_BASIC);
                        int8_t bgTile2 = this->getTile(Layer::Background, tileXIdx - 1, tileYIdx, TILE_FLOOR_BASIC);
                        int8_t fgTile2 = this->getTile(Layer::Foreground, tileXIdx - 1, tileYIdx, TILE_FLOOR_BASIC);
                        int8_t distToEdgeOfCurrentTile = distToEdgeOfTile(prince.getDirection(), prince.getPosition().x);

                        #if defined(DEBUG) && defined(DEBUG_ACTION_CANMOVEFORWARD)
                        int8_t bgTile1 = this->getTile(Layer::Background, tileXIdx, tileYIdx, TILE_FLOOR_BASIC);
                        int8_t fgTile1 = this->getTile(Layer::Foreground, tileXIdx, tileYIdx, TILE_FLOOR_BASIC);
                        DEBUG_PRINT(F(" left dist "));
                        DEBUG_PRINT(distToEdgeOfCurrentTile);
                        DEBUG_PRINT(F(", bg "));
                        DEBUG_PRINT(bgTile2);
                        DEBUG_PRINT(F(" "));
                        DEBUG_PRINT(bgTile1);
                        DEBUG_PRINT(F(", fg "));
                        DEBUG_PRINT(fgTile2);
                        DEBUG_PRINT(F(" "));
                        DEBUG_PRINT(fgTile1);
                        DEBUG_PRINTLN("");
                        #endif

                        switch (action) {

                            case Action::SmallStep:
                            case Action::CrouchHop:

                                switch (distToEdgeOfCurrentTile) {

                                    case 0 ... 5:
                                        {
                                            #if defined(DEBUG) && defined(DEBUG_ACTION_CANMOVEFORWARD)
                                            printTileInfo(bgTile2, fgTile2);
                                            #endif
                                            
                                            WallTileResults wallTile = this->isWallTile(bgTile2, fgTile2, tileXIdx, tileYIdx);
                                            return (wallTile == WallTileResults::None && (this->isGroundTile(bgTile2, fgTile2) || this->canFall(bgTile2, fgTile2)));
                                        }
                                        return false;

                                    default:
                                        return true;

                                }

                                break;

                            case Action::Step:
                            case Action::RunStart:

                                switch (distToEdgeOfCurrentTile) {

                                    case 0 ... 9:
                                        {
                                            #if defined(DEBUG) && defined(DEBUG_ACTION_CANMOVEFORWARD)
                                            printTileInfo(bgTile2, fgTile2);
                                            #endif

                                            WallTileResults wallTile = this->isWallTile(bgTile2, fgTile2, tileXIdx, tileYIdx);
                                            return (wallTile == WallTileResults::None && (this->isGroundTile(bgTile2, fgTile2) || this->canFall(bgTile2, fgTile2)));
                                        }
                                        return false;

                                    default:
                                        return true;

                                }

                                break;

                            case Action::RunRepeat:
                                {
                                    #if defined(DEBUG) && defined(DEBUG_ACTION_CANMOVEFORWARD)
                                    printTileInfo(bgTile2, fgTile2);
                                    #endif
                                    
                                    WallTileResults wallTile = this->isWallTile(bgTile2, fgTile2, tileXIdx, tileYIdx);
                                    return wallTile == WallTileResults::None;

                                }

                                return false;

                            case Action::StandingJump:
                                {
                                    WallTileResults wallTile = this->isWallTile(bgTile2, fgTile2, tileXIdx, tileYIdx);
                                    return wallTile == WallTileResults::None;
                                }

                                return true;

                            case Action::RunJump_3:
                                {
                                    WallTileResults wallTile = this->isWallTile(bgTile4, fgTile4, tileXIdx + 3, tileYIdx);
                                
                                    #if defined(DEBUG) && defined(DEBUG_ACTION_CANMOVEFORWARD)
                                    printTileInfo(bgTile4, fgTile4);
                                    DEBUG_PRINT("isWallTile(");
                                    DEBUG_PRINT(bgTile4);
                                    DEBUG_PRINT(",");
                                    DEBUG_PRINT(fgTile4);
                                    DEBUG_PRINT(",");
                                    DEBUG_PRINT(tileXIdx + 3);
                                    DEBUG_PRINT(",");
                                    DEBUG_PRINT(tileYIdx);
                                    DEBUG_PRINT(") = ");
                                    DEBUG_PRINTLN((uint8_t)wallTile);
                                    #endif

                                    return wallTile == WallTileResults::None;

                                }

                                return true;                                

                            case Action::RunJump_2:
                                {
                                    WallTileResults wallTile = this->isWallTile(bgTile3, fgTile3, tileXIdx + 2, tileYIdx);
                                    
                                    #if defined(DEBUG) && defined(DEBUG_ACTION_CANMOVEFORWARD)
                                    printTileInfo(bgTile3, fgTile3);
                                    DEBUG_PRINT("isWallTile(");
                                    DEBUG_PRINT(bgTile3);
                                    DEBUG_PRINT(",");
                                    DEBUG_PRINT(fgTile3);
                                    DEBUG_PRINT(",");
                                    DEBUG_PRINT(tileXIdx + 2);
                                    DEBUG_PRINT(",");
                                    DEBUG_PRINT(tileYIdx);
                                    DEBUG_PRINT(") = ");
                                    DEBUG_PRINTLN((uint8_t)wallTile);
                                    #endif

                                    return wallTile == WallTileResults::None;

                                }

                                return true;

                            case Action::RunJump_1:
                                {
                                    WallTileResults wallTile = this->isWallTile(bgTile2, fgTile2, tileXIdx + 1, tileYIdx);

                                    #if defined(DEBUG) && defined(DEBUG_ACTION_CANMOVEFORWARD)
                                    printTileInfo(bgTile2, fgTile2);
                                    DEBUG_PRINT("isWallTile(");
                                    DEBUG_PRINT(bgTile2);
                                    DEBUG_PRINT(",");
                                    DEBUG_PRINT(fgTile2);
                                    DEBUG_PRINT(",");
                                    DEBUG_PRINT(tileXIdx + 1);
                                    DEBUG_PRINT(",");
                                    DEBUG_PRINT(tileYIdx);
                                    DEBUG_PRINT(") = ");
                                    DEBUG_PRINTLN((uint8_t)wallTile);
                                    #endif

                                    return wallTile == WallTileResults::None;

                                }

                                return true;

                            default: return false;

                        }

                    }

                    break;

                case Direction::Right:
                    {

                        int8_t bgTile4 = this->getTile(Layer::Background, tileXIdx + 3, tileYIdx, TILE_FLOOR_BASIC);
                        int8_t fgTile4 = this->getTile(Layer::Foreground, tileXIdx + 3, tileYIdx, TILE_FLOOR_BASIC);
                        int8_t bgTile3 = this->getTile(Layer::Background, tileXIdx + 2, tileYIdx, TILE_FLOOR_BASIC);
                        int8_t fgTile3 = this->getTile(Layer::Foreground, tileXIdx + 2, tileYIdx, TILE_FLOOR_BASIC);
                        int8_t bgTile2 = this->getTile(Layer::Background, tileXIdx + 1, tileYIdx, TILE_FLOOR_BASIC);
                        int8_t fgTile2 = this->getTile(Layer::Foreground, tileXIdx + 1, tileYIdx, TILE_FLOOR_BASIC);
                        int8_t distToEdgeOfCurrentTile = distToEdgeOfTile(prince.getDirection(), prince.getPosition().x);

                        #if defined(DEBUG) && defined(DEBUG_ACTION_CANMOVEFORWARD)
                        int8_t bgTile1 = this->getTile(Layer::Background, tileXIdx, tileYIdx, TILE_FLOOR_BASIC);
                        int8_t fgTile1 = this->getTile(Layer::Foreground, tileXIdx, tileYIdx, TILE_FLOOR_BASIC);
                        DEBUG_PRINT(F(" right dist "));
                        DEBUG_PRINT(distToEdgeOfCurrentTile);
                        DEBUG_PRINT(F(", bg "));
                        DEBUG_PRINT(bgTile1);
                        DEBUG_PRINT(F(" "));
                        DEBUG_PRINT(bgTile2);
                        DEBUG_PRINT(F(", fg "));
                        DEBUG_PRINT(fgTile1);
                        DEBUG_PRINT(F(" "));
                        DEBUG_PRINT(fgTile2);
                        DEBUG_PRINTLN("");
                        #endif

                        switch (action) {

                            case Action::SmallStep:
                            case Action::CrouchHop:
                                {
                                    WallTileResults wallTile = this->isWallTile(bgTile2, fgTile2, tileXIdx, tileYIdx);

                                    #if defined(DEBUG) && defined(DEBUG_ACTION_CANMOVEFORWARD)
                                    printTileInfo(bgTile2, fgTile2);
                                    #endif

                                    switch (distToEdgeOfCurrentTile) {

                                        case 0 ... 5:

                                            switch (wallTile) {

                                                case WallTileResults::None:
                                                    return (this->isGroundTile(bgTile2, fgTile2) || this->canFall(bgTile2, fgTile2));

                                                case WallTileResults::Normal:
                                                case WallTileResults::GateClosed:
                                                    return false;
                                                
                                            }

                                            return false;

                                        case 6:

                                            switch (wallTile) {

                                                case WallTileResults::None:
                                                case WallTileResults::Normal:
                                                    return (this->isGroundTile(bgTile2, fgTile2) || this->canFall(bgTile2, fgTile2));

                                                case WallTileResults::GateClosed:
                                                    return false;
                                                
                                            }

                                            return false;

                                        default:

                                            return true;

                                    }

                                }

                                break;

                            case Action::Step:
                            case Action::RunStart:
                                {
                                    WallTileResults wallTile = this->isWallTile(bgTile2, fgTile2, tileXIdx, tileYIdx);

                                    switch (distToEdgeOfCurrentTile) {

                                        case 0 ... 9:

                                            switch (wallTile) {

                                                case WallTileResults::None:
                                                    return (this->isGroundTile(bgTile2, fgTile2) || this->canFall(bgTile2, fgTile2));

                                                case WallTileResults::Normal:
                                                case WallTileResults::GateClosed:
                                                    return false;
                                                
                                            }

                                            return false;

                                        case 10:

                                            switch (wallTile) {

                                                case WallTileResults::None:
                                                case WallTileResults::Normal:
                                                    return (this->isGroundTile(bgTile2, fgTile2) || this->canFall(bgTile2, fgTile2));

                                                case WallTileResults::GateClosed:
                                                    return false;
                                                
                                            }

                                            return false;
                                            
                                        default:
                                            return true;

                                    }

                                }

                                break;

                            case Action::RunRepeat:
                                {
                                    #if defined(DEBUG) && defined(DEBUG_ACTION_CANMOVEFORWARD)
                                    printTileInfo(bgTile2, fgTile2);
                                    #endif
                                    
                                    WallTileResults wallTile = this->isWallTile(bgTile2, fgTile2, tileXIdx + 1, tileYIdx);
                                    return wallTile == WallTileResults::None;

                                }
                                
                                return false;

                            case Action::StandingJump:
                                {
                                    WallTileResults wallTile = this->isWallTile(bgTile2, fgTile2, tileXIdx + 1, tileYIdx);
                                    return wallTile == WallTileResults::None;

                                }

                                return true;

                            case Action::RunJump_3:
                                {
                                    WallTileResults wallTile = this->isWallTile(bgTile4, fgTile4, tileXIdx + 3, tileYIdx);

                                    #if defined(DEBUG) && defined(DEBUG_ACTION_CANMOVEFORWARD)
                                    printTileInfo(bgTile4, fgTile4);
                                    DEBUG_PRINT("isWallTile(");
                                    DEBUG_PRINT(bgTile4);
                                    DEBUG_PRINT(",");
                                    DEBUG_PRINT(fgTile4);
                                    DEBUG_PRINT(",");
                                    DEBUG_PRINT(tileXIdx + 3);
                                    DEBUG_PRINT(",");
                                    DEBUG_PRINT(tileYIdx);
                                    DEBUG_PRINT(") = ");
                                    DEBUG_PRINTLN((uint8_t)wallTile);
                                    #endif

                                    return wallTile == WallTileResults::None;

                                }

                                return true;                                

                            case Action::RunJump_2:
                                {
                                    WallTileResults wallTile = this->isWallTile(bgTile3, fgTile3, tileXIdx + 2, tileYIdx);

                                    #if defined(DEBUG) && defined(DEBUG_ACTION_CANMOVEFORWARD)
                                    printTileInfo(bgTile3, fgTile3);
                                    DEBUG_PRINT("isWallTile(");
                                    DEBUG_PRINT(bgTile3);
                                    DEBUG_PRINT(",");
                                    DEBUG_PRINT(fgTile3);
                                    DEBUG_PRINT(",");
                                    DEBUG_PRINT(tileXIdx + 2);
                                    DEBUG_PRINT(",");
                                    DEBUG_PRINT(tileYIdx);
                                    DEBUG_PRINT(") = ");
                                    DEBUG_PRINTLN((uint8_t)wallTile);
                                    #endif

                                    return wallTile == WallTileResults::None;

                                }

                                return true;

                            case Action::RunJump_1:
                                {
                                    WallTileResults wallTile = this->isWallTile(bgTile2, fgTile2, tileXIdx + 1, tileYIdx);
                                        
                                    #if defined(DEBUG) && defined(DEBUG_ACTION_CANMOVEFORWARD)
                                    printTileInfo(bgTile2, fgTile2);
                                    DEBUG_PRINT("isWallTile(");
                                    DEBUG_PRINT(bgTile2);
                                    DEBUG_PRINT(",");
                                    DEBUG_PRINT(fgTile2);
                                    DEBUG_PRINT(",");
                                    DEBUG_PRINT(tileXIdx + 1);
                                    DEBUG_PRINT(",");
                                    DEBUG_PRINT(tileYIdx);
                                    DEBUG_PRINT(") = ");
                                    DEBUG_PRINTLN((uint8_t)wallTile);
                                    #endif

                                    return wallTile == WallTileResults::None;

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

            #if defined(DEBUG) && defined(DEBUG_ACTION_CANJUMPUP)
            DEBUG_PRINTLN(F("-----------------------------------------------------"));
            #endif

            switch (prince.getDirection()) {

                case Direction::Left:
                    {
                        CanJumpUpResult resultLeft = this->canJumpUp_Test(prince, Direction::Left);

                        switch (resultLeft) {

                            case CanJumpUpResult::Jump:
                            case CanJumpUpResult::StepThenJump:

                                #if defined(DEBUG) && defined(DEBUG_ACTION_CANJUMPUP)
                                DEBUG_PRINT(F("Left Test success, Return "));
                                DEBUG_PRINTLN(static_cast<uint8_t>(resultLeft));
                                #endif
                                                                    
                                return resultLeft;

                            case CanJumpUpResult::JumpThenFall_CollapseFloor:

                                #if defined(DEBUG) && defined(DEBUG_ACTION_CANJUMPUP)
                                DEBUG_PRINTLN(F("Left Test success, Return JumpThenFall_CollapseFloor"));
                                #endif                            

                                return CanJumpUpResult::JumpThenFall_CollapseFloor;

                            case CanJumpUpResult::JumpThenFall_CollapseFloorAbove:

                                #if defined(DEBUG) && defined(DEBUG_ACTION_CANJUMPUP)
                                DEBUG_PRINTLN(F("Left Test success, Return JumpThenFall_CollapseFloorAbove"));
                                #endif                            

                                return CanJumpUpResult::JumpThenFall_CollapseFloorAbove;

                            case CanJumpUpResult::StepThenJumpThenFall_CollapseFloor:

                                #if defined(DEBUG) && defined(DEBUG_ACTION_CANJUMPUP)
                                DEBUG_PRINTLN(F("Left Test success, Return StepThenJumpThenFall_CollapseFloor"));
                                #endif                            

                                return CanJumpUpResult::StepThenJumpThenFall_CollapseFloor;

                            default:
                                {
                                    CanJumpUpResult resultRight = this->canJumpUp_Test(prince, Direction::Right);

                                    switch (resultRight) {

                                        case CanJumpUpResult::Jump:

                                            #if defined(DEBUG) && defined(DEBUG_ACTION_CANJUMPUP)
                                            DEBUG_PRINT(F("Right Test success, Return TurnThenJump"));
                                            #endif

                                            return CanJumpUpResult::TurnThenJump;

                                        default:

                                            #if defined(DEBUG) && defined(DEBUG_ACTION_CANJUMPUP)
                                            DEBUG_PRINT(F("Right Test failed, Return "));
                                            DEBUG_PRINTLN(static_cast<uint8_t>(resultLeft));
                                            #endif

                                            CanJumpUpResult result = this->canJumpUp_Test_Dist10(prince, Direction::Left);

                                            #if defined(DEBUG) && defined(DEBUG_ACTION_CANJUMPUP)
                                            DEBUG_PRINT(F("canJumpUp_Test_Dist10 Return "));
                                            DEBUG_PRINTLN(static_cast<uint8_t>(result));
                                            #endif

                                            return result;

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
                                DEBUG_PRINT(F("Right Test success, Return "));
                                DEBUG_PRINTLN(static_cast<uint8_t>(resultRight));
                                #endif                            

                                return resultRight;

                            case CanJumpUpResult::JumpThenFall_CollapseFloor:

                                #if defined(DEBUG) && defined(DEBUG_ACTION_CANJUMPUP)
                                DEBUG_PRINTLN(F("Right Test success, Return JumpThenFall_CollapseFloor"));
                                #endif                            

                                return CanJumpUpResult::JumpThenFall_CollapseFloor;

                            case CanJumpUpResult::JumpThenFall_CollapseFloorAbove:

                                #if defined(DEBUG) && defined(DEBUG_ACTION_CANJUMPUP)
                                DEBUG_PRINTLN(F("Right Test success, Return JumpThenFall_CollapseFloorAbove"));
                                #endif                            

                                return CanJumpUpResult::JumpThenFall_CollapseFloorAbove;

                            case CanJumpUpResult::StepThenJumpThenFall_CollapseFloor:

                                #if defined(DEBUG) && defined(DEBUG_ACTION_CANJUMPUP)
                                DEBUG_PRINTLN(F("Right Test success, Return StepThenJumpThenFall_CollapseFloor"));
                                #endif                            

                                return CanJumpUpResult::StepThenJumpThenFall_CollapseFloor;

                            default:
                                {
                                    CanJumpUpResult resultLeft = this->canJumpUp_Test(prince, Direction::Left);

                                    switch (resultLeft) {

                                        case CanJumpUpResult::Jump:

                                            #if defined(DEBUG) && defined(DEBUG_ACTION_CANJUMPUP)
                                            DEBUG_PRINT(F("Left Test success, Return TurnThenJump"));
                                            #endif     

                                            return CanJumpUpResult::TurnThenJump;

                                        default:

                                            #if defined(DEBUG) && defined(DEBUG_ACTION_CANJUMPUP)
                                            DEBUG_PRINT(F("Left Test failed, Return "));
                                            DEBUG_PRINTLN(static_cast<uint8_t>(resultRight));
                                            #endif     

                                            CanJumpUpResult result = this->canJumpUp_Test_Dist10(prince, Direction::Right);
                                            
                                            #if defined(DEBUG) && defined(DEBUG_ACTION_CANJUMPUP)
                                            DEBUG_PRINT(F("canJumpUp_Test_Dist10 Return "));
                                            DEBUG_PRINTLN(static_cast<uint8_t>(result));
                                            #endif

                                            return result;

                                    }

                                }

                                break;
                        }
                        
                    }

                    break;

                default:  break;

            }

            #if defined(DEBUG) && defined(DEBUG_ACTION_CANJUMPUP)
            DEBUG_PRINT(F("Return None"));
            #endif

            return CanJumpUpResult::None;            

        }

        CanJumpUpResult canJumpUp_Test(Prince &prince, Direction direction) {

            int8_t inc = (direction == Direction::Left ? -1 : 1);
            int8_t tileXIdx = this->coordToTileIndexX(direction, prince.getPosition().x) - this->getXLocation();
            int8_t tileYIdx = this->coordToTileIndexY(direction, prince.getPosition().y) - this->getYLocation();

            #if defined(DEBUG) && defined(DEBUG_ACTION_CANJUMPUP)
            DEBUG_PRINT(F("canJumpUp_Test: direction "));
            DEBUG_PRINT((direction == Direction::Left ? "Left" : "Right"));
            DEBUG_PRINT(F(", canJumpUp_Test: coordToTileIndexX "));
            DEBUG_PRINT(prince.getPosition().x);
            DEBUG_PRINT(F(" = "));
            DEBUG_PRINT(tileXIdx);
            DEBUG_PRINT(F(", coordToTileIndexY "));
            DEBUG_PRINT(prince.getPosition().y);
            DEBUG_PRINT(F(" = "));
            DEBUG_PRINTLN(tileYIdx);
            #endif

            int8_t bgTile1 = this->getTile(Layer::Background, tileXIdx, tileYIdx - 1, TILE_FLOOR_BASIC);
            int8_t bgTile2 = this->getTile(Layer::Background, tileXIdx + inc, tileYIdx - 1, TILE_COLLAPSING_FLOOR);
            int8_t midTile = this->getTile(Layer::Background, tileXIdx, tileYIdx - 1, TILE_COLLAPSING_FLOOR);
            int8_t distToEdge = distToEdgeOfTile(direction, prince.getPosition().x);

            #if defined(DEBUG) && defined(DEBUG_ACTION_CANJUMPUP)
            DEBUG_PRINT(F("dist "));
            DEBUG_PRINT(distToEdge);
            DEBUG_PRINT(F(", bg "));
            DEBUG_PRINT(bgTile1);
            DEBUG_PRINT(F(" "));
            DEBUG_PRINT(bgTile2);
            DEBUG_PRINT(F(", mid "));
            DEBUG_PRINT(midTile);
            DEBUG_PRINT(F(" ("));
            DEBUG_PRINT(tileXIdx - inc);
            DEBUG_PRINT(F(","));
            DEBUG_PRINT(tileYIdx - 1);
            DEBUG_PRINT(F(")"));
            DEBUG_PRINTLN("");
            #endif

            switch (direction) {

                case Direction::Left:

                    switch (distToEdge) {

                        case 7 ... 12:

                            if (midTile == TILE_COLLAPSING_FLOOR) {
                                return CanJumpUpResult::JumpThenFall_CollapseFloorAbove;
                            }
                            else {
                                return CanJumpUpResult::JumpThenFall;
                            }

                            break;

                        case 3 ... 6:

                            switch (bgTile1) {

                                case TILE_FLOOR_RH_END:
                                case TILE_FLOOR_RH_END_1:
                                case TILE_FLOOR_RH_END_2:
                                case TILE_FLOOR_RH_END_3:
                                case TILE_FLOOR_RH_END_4:
                                case TILE_FLOOR_RH_END_5:
                                case TILE_FLOOR_RH_END_GATE:
                                case TILE_COLUMN_LH_WALL:

                                    if (midTile == TILE_COLLAPSING_FLOOR) {
                                        return CanJumpUpResult::JumpThenFall_CollapseFloorAbove;
                                    }
                                    else {
                                        return CanJumpUpResult::StepThenJump;
                                    }                                

                                    break;

                                default:                                

                                    switch (bgTile2) {

                                        case TILE_COLLAPSING_FLOOR:
                                            return CanJumpUpResult::StepThenJumpThenFall_CollapseFloor;

                                        default:

                                            if (midTile == TILE_COLLAPSING_FLOOR) {
                                                return CanJumpUpResult::JumpThenFall_CollapseFloorAbove;
                                            }
                                            else {
                                                return CanJumpUpResult::JumpThenFall;
                                            }

                                    }
    
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
                                case TILE_COLUMN_LH_WALL:

                                    if (midTile == TILE_COLLAPSING_FLOOR) {
                                        return CanJumpUpResult::JumpThenFall_CollapseFloorAbove;
                                    }
                                    else {
                                        return CanJumpUpResult::Jump;
                                    }

                                    break;

                                default:                                

                                    switch (bgTile2) {

                                        case TILE_COLLAPSING_FLOOR:
                                            return CanJumpUpResult::JumpThenFall_CollapseFloor;

                                        default:

                                            if (midTile == TILE_COLLAPSING_FLOOR) {
                                                return CanJumpUpResult::JumpThenFall_CollapseFloorAbove;
                                            }
                                            else {
                                                return CanJumpUpResult::JumpThenFall;
                                            }

                                    }

                            }

                            break;

                    }

                    break;

                case Direction::Right:

                    switch (distToEdge) {

                        case 7 ... 12:

                            if (midTile == TILE_COLLAPSING_FLOOR) {
                                return CanJumpUpResult::JumpThenFall_CollapseFloorAbove;
                            }
                            else {
                                return CanJumpUpResult::JumpThenFall;
                            }

                            break;

                        case 3 ... 6:

                            switch (bgTile2) {

                                case TILE_FLOOR_LH_END:
                                case TILE_FLOOR_LH_END_PATTERN_1:
                                case TILE_FLOOR_LH_END_PATTERN_2:
                                case TILE_COLUMN_3:

                                    if (midTile == TILE_COLLAPSING_FLOOR) {

                                        return CanJumpUpResult::JumpThenFall_CollapseFloorAbove;
                                    }
                                    else {

                                        return CanJumpUpResult::StepThenJump;
                                    }

                                case TILE_COLLAPSING_FLOOR:

                                    return CanJumpUpResult::StepThenJumpThenFall_CollapseFloor;

                                default:                                

                                    if (midTile == TILE_COLLAPSING_FLOOR) {

                                        return CanJumpUpResult::JumpThenFall_CollapseFloorAbove;
                                    }
                                    else {

                                        return CanJumpUpResult::JumpThenFall;
                                    }

                            }

                            break;

                        case 0 ... 2:

                            switch (bgTile2) {

                                case TILE_FLOOR_LH_END:
                                case TILE_FLOOR_LH_END_PATTERN_1:
                                case TILE_FLOOR_LH_END_PATTERN_2:
                                case TILE_COLUMN_3:

                                    if (midTile == TILE_COLLAPSING_FLOOR) {
                                        return CanJumpUpResult::JumpThenFall_CollapseFloorAbove;
                                    }
                                    else {
                                        return CanJumpUpResult::Jump;
                                    }

                                    break;


                                case TILE_COLLAPSING_FLOOR:
                                    return CanJumpUpResult::JumpThenFall_CollapseFloor;

                                default:

                                    if (midTile == TILE_COLLAPSING_FLOOR) {
                                        return CanJumpUpResult::JumpThenFall_CollapseFloorAbove;
                                    }
                                    else {
                                        return CanJumpUpResult::JumpThenFall;
                                    }

                            }

                            break;

                    }

                    break;

                default: break;

            }

            return CanJumpUpResult::JumpThenFall;

        }

        CanJumpUpResult canJumpUp_Test_Dist10(Prince &prince, Direction direction) {

            int8_t tileXIdx = this->coordToTileIndexX(direction, prince.getPosition().x) - this->getXLocation();
            int8_t tileYIdx = this->coordToTileIndexY(direction, prince.getPosition().y) - this->getYLocation();

            #if defined(DEBUG) && defined(DEBUG_ACTION_CANJUMPUP)
            DEBUG_PRINT(F("canJumpUp_Test_Dist10: direction "));
            DEBUG_PRINT((direction == Direction::Left ? "Left" : "Right"));
            DEBUG_PRINT(F(", coordToTileIndexX "));
            DEBUG_PRINT(prince.getPosition().x);
            DEBUG_PRINT(F(" = "));
            DEBUG_PRINT(tileXIdx);
            DEBUG_PRINT(F(", coordToTileIndexY "));
            DEBUG_PRINT(prince.getPosition().y);
            DEBUG_PRINT(" = ");
            DEBUG_PRINTLN(tileYIdx);
            #endif

            int8_t bgTile1 = this->getTile(Layer::Background, tileXIdx + 1, tileYIdx - 1, TILE_FLOOR_BASIC);
            int8_t bgTile2 = this->getTile(Layer::Background, tileXIdx, tileYIdx - 1, TILE_FLOOR_BASIC);
            int8_t distToEdge = distToEdgeOfTile(direction, prince.getPosition().x);

            #if defined(DEBUG) && defined(DEBUG_ACTION_CANJUMPUP)
            DEBUG_PRINT(F("dist "));
            DEBUG_PRINT(distToEdge);
            DEBUG_PRINT(F(", bg "));
            DEBUG_PRINT(bgTile1);
            DEBUG_PRINT(F(" "));
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
                                case TILE_COLUMN_LH_WALL:
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
                                case TILE_COLUMN_3:
                                    return CanJumpUpResult::JumpDist10;

                                default:                                
                                    return CanJumpUpResult::JumpThenFall;

                            }

                            break;

                    }

                    break;

                default: break;

            }

            return CanJumpUpResult::JumpThenFall;

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
                        printCoordToIndex(prince.getPosition(), tileXIdx, tileYIdx);
                        #endif

                    }

                    break;

                case Direction::Right:
                    {

                        tileXIdx = this->coordToTileIndexX(prince.getDirection(), prince.getPosition().x) - this->getXLocation() + 1;
                        tileYIdx = this->coordToTileIndexY(prince.getDirection(), prince.getPosition().y) - this->getYLocation() - 1;

                        #if defined(DEBUG) && defined(DEBUG_ACTION_CANJUMPUP_PART2)
                        printCoordToIndex(prince.getPosition(), tileXIdx, tileYIdx);
                        #endif

                    }

                    break;

                default: break;

            }



            // Look for closed gate in the same cell as possible ledge ..

            uint8_t gatePosition = 255;

            for (uint8_t i = 2; i < Constants::NumberOfItems; i++) {

                Item &item = this->items[i];

                if (item.itemType == ItemType::Gate) {

                    if (item.x == tileXIdx + this->xLoc && item.y == tileYIdx + this->yLoc) {

                        gatePosition = item.data.gate.position;
                        break;

                    }

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
                                DEBUG_PRINT(F("Return: "));
                                DEBUG_PRINTLN(static_cast<uint8_t>(resultRight));
                                #endif

                                return resultRight;
                                break;

                            default:
                                {
                                    CanClimbDownResult resultLeft = canClimbDown_Test(prince, Direction::Left);

                                    switch (resultLeft) {

                                        case CanClimbDownResult::ClimbDown:

                                            #if defined(DEBUG) && defined(DEBUG_ACTION_CANCLIMBDOWN)
                                            DEBUG_PRINTLN(F("Return: TurnThenClimbDown"));
                                            #endif

                                            return CanClimbDownResult::TurnThenClimbDown;
                                            break;

                                        case CanClimbDownResult::StepThenClimbDown:

                                            #if defined(DEBUG) && defined(DEBUG_ACTION_CANCLIMBDOWN)
                                            DEBUG_PRINTLN(F("Return: StepThenTurnThenClimbDown"));
                                            #endif

                                            return CanClimbDownResult::StepThenTurnThenClimbDown;
                                            break;

                                        default:

                                            #if defined(DEBUG) && defined(DEBUG_ACTION_CANCLIMBDOWN)
                                            DEBUG_PRINT(F("Return: "));
                                            DEBUG_PRINTLN(static_cast<uint8_t>(resultRight));
                                            #endif
                                            
                                            return resultRight;
                                            break;

                                    }

                                }
                                        
                                #if defined(DEBUG) && defined(DEBUG_ACTION_CANCLIMBDOWN)
                                DEBUG_PRINTLN(F("Return: None"));
                                #endif

                                return CanClimbDownResult::None;
                                break;

                        }
                        
                    }

                    #if defined(DEBUG) && defined(DEBUG_ACTION_CANCLIMBDOWN)
                    DEBUG_PRINTLN(F("Return: None"));
                    #endif

                    return CanClimbDownResult::None;
                    break;

                case Direction::Right:
                    {
                        CanClimbDownResult resultLeft = canClimbDown_Test(prince, Direction::Left);

                        #if defined(DEBUG) && defined(DEBUG_ACTION_CANCLIMBDOWN)
                        DEBUG_PRINT(F("canClimbDown: facing right, initial result "));
                        DEBUG_PRINTLN(static_cast<uint8_t>(resultLeft));
                        #endif

                        switch (resultLeft) {

                            case CanClimbDownResult::ClimbDown:
                            case CanClimbDownResult::StepThenClimbDown:

                                #if defined(DEBUG) && defined(DEBUG_ACTION_CANCLIMBDOWN)
                                DEBUG_PRINT(F("1 Return: "));
                                DEBUG_PRINTLN(static_cast<uint8_t>(resultLeft));
                                #endif

                                return resultLeft;
                                break;

                            default:
                                {
                                    CanClimbDownResult resultRight = canClimbDown_Test(prince, Direction::Right);

                                    #if defined(DEBUG) && defined(DEBUG_ACTION_CANCLIMBDOWN)
                                    DEBUG_PRINT(F("canClimbDown: check left, result "));
                                    DEBUG_PRINTLN(static_cast<uint8_t>(resultLeft));
                                    #endif

                                    switch (resultRight) {

                                        case CanClimbDownResult::ClimbDown:

                                            #if defined(DEBUG) && defined(DEBUG_ACTION_CANCLIMBDOWN)
                                            DEBUG_PRINTLN(F("2. Return: TurnThenClimbDown"));
                                            #endif

                                            return CanClimbDownResult::TurnThenClimbDown;
                                            break;

                                        case CanClimbDownResult::StepThenClimbDown:

                                            #if defined(DEBUG) && defined(DEBUG_ACTION_CANCLIMBDOWN)
                                            DEBUG_PRINTLN(F("3. Return: StepThenTurnThenClimbDown"));
                                            #endif

                                            return CanClimbDownResult::StepThenTurnThenClimbDown;
                                            break;

                                        default:

                                            #if defined(DEBUG) && defined(DEBUG_ACTION_CANCLIMBDOWN)
                                            DEBUG_PRINT(F("4. Return: "));
                                            DEBUG_PRINTLN(static_cast<uint8_t>(resultLeft));
                                            #endif
                                            
                                            return resultLeft;
                                            break;

                                    }

                                }

                                return CanClimbDownResult::None;
                                break;

                        }
                        
                    }

                    #if defined(DEBUG) && defined(DEBUG_ACTION_CANCLIMBDOWN)
                    DEBUG_PRINTLN(F("Return: None"));
                    #endif

                    return CanClimbDownResult::None;
                    break;

                default: 

                    #if defined(DEBUG) && defined(DEBUG_ACTION_CANCLIMBDOWN)
                    DEBUG_PRINTLN(F("Return: None"));
                    #endif

                    return CanClimbDownResult::None;
                    break;

            }

        }

        CanClimbDownResult canClimbDown_Test(Prince &prince, Direction direction) {

            int8_t tileXIdx = this->coordToTileIndexX(direction, prince.getPosition().x) - this->getXLocation() + (direction == Direction::Right ? 1 : 0);
            int8_t tileYIdx = this->coordToTileIndexY(direction, prince.getPosition().y) - this->getYLocation();

            #if defined(DEBUG) && defined(DEBUG_ACTION_CANCLIMBDOWN)
            printCoordToIndex(prince.getPosition(), tileXIdx, tileYIdx);
            #endif

            int8_t bgTile1 = this->getTile(Layer::Background, tileXIdx, tileYIdx, TILE_FLOOR_BASIC);
            int8_t distToEdge = distToEdgeOfTile(direction, prince.getPosition().x);

            #if defined(DEBUG) && defined(DEBUG_ACTION_CANCLIMBDOWN)
            if(direction == Direction::Left) {
                DEBUG_PRINT(F("Left "));
            }
            else {
                DEBUG_PRINT(F("Right "));
            }
            DEBUG_PRINT(F("dist "));
            DEBUG_PRINT(distToEdge);
            DEBUG_PRINT(F(", bg "));
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
                                case TILE_COLUMN_3:
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
                                case TILE_COLUMN_3:
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

                                // case TILE_FLOOR_RH_END:
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

                                // case TILE_FLOOR_RH_END:
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




        bool collideWithWall(Prince &prince) {

            Direction direction = prince.getDirection();

            uint8_t imageIndex = static_cast<uint8_t>(pgm_read_byte(&Constants::StanceToImageXRef[prince.getStance()]));
            uint16_t pos = (imageIndex - 1) * 3;
            int8_t reach = static_cast<int8_t>(pgm_read_byte(&Constants::Prince_ImageDetails[pos]));
            // int8_t footToe = static_cast<int8_t>(pgm_read_byte(&Constants::Prince_ImageDetails[pos + 1]));
            // int8_t footHeel = static_cast<int8_t>(pgm_read_byte(&Constants::Prince_ImageDetails[pos + 2]));

            #if defined(DEBUG) && defined(DEBUG_ACTION_COLLIDEWITHWALL)
            DEBUG_PRINT("collideWithWall() Stance: ");
            DEBUG_PRINT(prince.getStance());
            DEBUG_PRINT(", reach: ");
            DEBUG_PRINTLN(reach);
            #endif

            int8_t tileXIdx = this->coordToTileIndexX(direction, prince.getPosition(-reach).x) - this->getXLocation() + (direction == Direction::Right ? 1 : 0);
            int8_t tileYIdx = this->coordToTileIndexY(direction, prince.getPosition().y) - this->getYLocation();

            #if defined(DEBUG) && defined(DEBUG_ACTION_COLLIDEWITHWALL)
            printCoordToIndex(prince.getPosition(), tileXIdx, tileYIdx);
            #endif

            int8_t bgTile = this->getTile(Layer::Background, tileXIdx, tileYIdx, TILE_FLOOR_BASIC);
            int8_t fgTile = this->getTile(Layer::Foreground, tileXIdx, tileYIdx, TILE_FLOOR_BASIC);

            #if defined(DEBUG) && defined(DEBUG_ACTION_COLLIDEWITHWALL)
            DEBUG_PRINT(F(", direction "));
            if(direction == Direction::Left) {
                DEBUG_PRINT(F("Left "));
            }
            else {
                DEBUG_PRINT(F("Right "));
            }
            DEBUG_PRINT(F(", bg "));
            DEBUG_PRINT(bgTile);
            DEBUG_PRINT(F(", fg "));
            DEBUG_PRINT(fgTile);
            DEBUG_PRINT(F(", isWall() "));
            DEBUG_PRINT((uint8_t)isWallTile(bgTile, fgTile));
            DEBUG_PRINTLN("");
            #endif

            return (isWallTile(bgTile, fgTile) != WallTileResults::None);

        }

        #if defined(DEBUG)
        void printAction(Action action) {

            switch (action) {

                case Action::SmallStep:
                    DEBUG_PRINT(F("SmallStep"));
                    break;

                case Action::CrouchHop:
                    DEBUG_PRINT(F("CrouchHop"));
                    break;

                case Action::Step:
                    DEBUG_PRINT(F("Step"));
                    break;

                case Action::RunStart:
                    DEBUG_PRINT(F("RunStart"));
                    break;

                case Action::RunRepeat:
                    DEBUG_PRINT(F("RunRepeat"));
                    break;

                case Action::RunJump_3:
                    DEBUG_PRINT(F("RunJump_3"));
                    break;

                case Action::RunJump_2:
                    DEBUG_PRINT(F("RunJump_2"));
                    break;

                case Action::RunJump_1:
                    DEBUG_PRINT(F("RunJump_1"));
                    break;

                case Action::StandingJump:
                    DEBUG_PRINT(F("StandingJump"));
                    break;

            }

        }

        void printTileInfo(int8_t bgTile, int8_t fgTile) {

            DEBUG_PRINT(F("isWallTile("));
            DEBUG_PRINT(bgTile);
            DEBUG_PRINT(F(","));
            DEBUG_PRINT(fgTile);
            DEBUG_PRINT(F(") "));
            DEBUG_PRINT((uint8_t)this->isWallTile(bgTile, fgTile));
            DEBUG_PRINT(F(", isGroundTile() "));
            DEBUG_PRINT(this->isGroundTile(bgTile, fgTile));
            DEBUG_PRINT(F(", canFall() "));
            DEBUG_PRINTLN(this->canFall(bgTile, fgTile));
        
        }

        void printCoordToIndex(Point point, int tileXIdx, int8_t tileYIdx) {

            DEBUG_PRINT(F("coordToTileIndexX "));
            DEBUG_PRINT(point.x);
            DEBUG_PRINT(F(" = "));
            DEBUG_PRINT(tileXIdx);
            DEBUG_PRINT(F(", coordToTileIndexY "));
            DEBUG_PRINT(point.y);
            DEBUG_PRINT(F(" = "));
            DEBUG_PRINTLN(tileYIdx);

        }
        #endif


};