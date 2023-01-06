#pragma once

#include "../utils/Arduboy2Ext.h"
#include "GamePlay.h"   
#include "Prince.h"   
#include "Enemy.h"   
#include "../utils/Constants.h"
#include "../utils/Stack.h"
#include "Item.h"

#define TILE_NONE -1
#define TILE_FLOOR_NONE 75
#define TILE_FLOOR_NONE_PATTERN 92
#define TILE_WINDOW_LH 37
#define TILE_WINDOW_RH 38
#define TILE_RUG_1 40
#define TILE_RUG_2 41

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
#define TILE_FLOOR_RH_END_GATE_1 118
#define TILE_FLOOR_RH_END_GATE_2 55
#define TILE_FLOOR_RH_END_GATE_RUG 50
#define TILE_FLOOR_GATE_REAR_TRACK_1 114    // Missing top pixels
#define TILE_FLOOR_GATE_REAR_TRACK_2 49     // Full height
#define TILE_FLOOR_GATE_FRONT_TRACK_1 115
#define TILE_FLOOR_GATE_FRONT_TRACK_2 116
#define TILE_FLOOR_GATE_FRONT_TRACK_3 117
#define TILE_FLOOR_GATE_FRONT_TRACK_4 39 // Used on rug

#define TILE_FLOOR_RH_END_1 98
#define TILE_FLOOR_RH_END_2 85
#define TILE_FLOOR_RH_END_3 103
#define TILE_FLOOR_RH_END_4 94
#define TILE_FLOOR_RH_END_5 111
#define TILE_FLOOR_RH_PILLAR_END 52

#define TILE_FLOOR_LH_WALL_1 83
#define TILE_FLOOR_LH_WALL_2 109
#define TILE_FLOOR_LH_WALL_3 113
#define TILE_FLOOR_LH_RUG_1 42

#define TILE_FG_WALL_1 80
#define TILE_FG_WALL_2 81
#define TILE_FG_WALL_3 82
#define TILE_FG_WALL_4 86
#define TILE_FG_WALL_5 87
#define TILE_FG_WALL_6 88
#define TILE_FG_WALL_7 121
#define TILE_FG_WALL_8 122

#define TILE_COLUMN_LH_WALL 100
#define TILE_COLUMN_1 84
#define TILE_COLUMN_2 112
#define TILE_COLUMN_3 96
#define TILE_COLUMN_4 89
#define TILE_COLUMN_5 101
#define TILE_PILLAR_1 31
#define TILE_PILLAR_2 51

#define TILE_COLUMN_REAR_1 104
#define TILE_COLUMN_REAR_2 90
#define TILE_PILLAR_REAR_1 32


#define TILE_COLLAPSING_FLOOR - 2

struct Level {

    private:

        //uint8_t level = 0;
        uint8_t width = 60;
        uint8_t height = 0;
        uint8_t xLoc = 60;
        uint8_t yLoc = 0;
        uint8_t yOffset = 0;                        // Ofset when rendering.
        Direction yOffsetDir = Direction::None;     // Ofset movement

        int8_t bg[5][16];
        int8_t fg[5][16];
        Flash flash;
        Sign sign;
        Item items[Constants::Items_Count];

    public:

        //uint8_t getLevel()                      { return this->level; }
        uint8_t getWidth()                      { return this->width; }
        uint8_t getHeight()                     { return this->height; }
        uint8_t getXLocation()                  { return this->xLoc; }
        uint8_t getYLocation()                  { return this->yLoc; }
        uint8_t getYOffset()                    { return this->yOffset; }
        Flash &getFlash()                       { return this->flash; }
        Sign &getSign()                         { return this->sign; }
        Item &getItem(uint8_t idx)              { return this->items[idx]; }
        Direction getYDirection()               { return this->yOffsetDir; }

        //void setLevel(uint8_t val)              { this->level = val; }
        void setWidth(uint8_t val)              { this->width = val; }
        void setHeight(uint8_t val)             { this->height = val; }
        void setXLocation(uint8_t val)          { this->xLoc = val; }
        void setYLocation(uint8_t val)          { this->yLoc = val; }
        void setYOffset(uint8_t val)            { this->yOffset = val; }
        void setYOffsetDir(Direction val)       { this->yOffsetDir = val; }


    public:

        #ifndef LEVEL_DATA_FROM_FX

            void init(GamePlay &gamePlay, Prince &prince, uint8_t width, uint8_t height, uint8_t xLoc, uint8_t yLoc) {

                this->width = width;
                this->height = height;

                this->xLoc = xLoc;
                this->yLoc = yLoc;

                this->loadMap(gamePlay);
                this->loadItems(gamePlay);

                if (prince.getY() > 56) {

                    this->yOffset = prince.getY() - 56;

                }
                else {

                    this->yOffset = 0;

                }

            }

        #endif

        #ifndef SAVE_MEMORY_ENEMY
        void init_PositionChars(GamePlay &gamePlay, Prince &prince, Enemy &enemy, bool clearSword) {

            enemy.init();
        #else
        void init_PositionChars(GamePlay &gamePlay, Prince &prince, bool clearSword) {

        #endif

            #ifdef LEVEL_DATA_FROM_FX
                
                FX::seekData(FX::readIndexedUInt24(Levels::level_Data, gamePlay.level));

                {
                    uint8_t xPixel = FX::readPendingUInt8();
                    uint8_t yPixel = FX::readPendingUInt8();
                    Direction direction = static_cast<Direction>(FX::readPendingUInt8());
                    uint16_t stance = static_cast<uint16_t>(FX::readPendingUInt8());
                    uint8_t health = FX::readPendingUInt8();

                    prince.init(xPixel, yPixel, direction, stance, health, clearSword);
                    
                }

                {
                    this->width = FX::readPendingUInt8();
                    this->height = FX::readPendingUInt8();
                    this->xLoc = FX::readPendingUInt8();
                    this->yLoc = FX::readPendingUInt8();
                    FX::readEnd();

                    this->loadMap(gamePlay);
                    this->loadItems(gamePlay);

                    if (prince.getY() > 56) {

                        this->yOffset = prince.getY() - 56;

                    }
                    else {

                        this->yOffset = 0;

                    }

                }

                FX::seekData(FX::readIndexedUInt24(Levels::level_Data, gamePlay.level) + 9);

                {
                    EnemyType enemyType = static_cast<EnemyType>(FX::readPendingUInt8());

                    while (enemyType != EnemyType::None) {

                        uint8_t xTile = FX::readPendingUInt8();
                        uint8_t yTile = FX::readPendingUInt8();
                        uint8_t xPixel = FX::readPendingUInt8();
                        uint8_t yPixel = FX::readPendingUInt8();

                        Direction direction = static_cast<Direction>(FX::readPendingUInt8());
                        uint8_t health = FX::readPendingUInt8();
                        Status status = static_cast<Status>(FX::readPendingUInt8());

                        #ifndef SAVE_MEMORY_ENEMY
                            enemy.init(enemyType, (xTile * Constants::TileWidth) + xPixel, (yTile * Constants::TileHeight) + yPixel, direction, Stance::Upright, health, status);
                        #endif

                        enemyType = static_cast<EnemyType>(FX::readPendingUInt8());

                    }
                    
                }
                
                FX::readEnd();

            #else

                // Level 1

                if (gamePlay.level == 1) {

                    #ifndef SAVE_MEMORY_ENEMY
                        enemy.init(EnemyType::Guard, 104 - 12 + (70 * Constants::TileWidth), 25+31 + (3 * Constants::TileHeight), Direction::Left, Stance::Upright, 3, Status::Active);          // Sword fight from Left
                        enemy.init(EnemyType::Guard, 80 + (40 * Constants::TileWidth), 25 + (0 * Constants::TileHeight), Direction::Left, Stance::Upright, 3, Status::Active);          // Sword fight from Left
                    #endif

                    prince.init(38-28+12+4, 56, Direction::Right, Stance::Crouch_3_End, 3, clearSword);          // Normal starting pos
                    this->init(gamePlay, prince, 90, 9, 60, 0);  // Normal starting posa

                    // prince.init(38-24, 25, Direction::Right, Stance::Crouch_3_End, 3, clearSword);          // Gate Issue
                    // this->init(gamePlay, prince, 90, 9,  37, 3);  // gate issuee

                    // prince.init(38-24, 56, Direction::Right, Stance::Crouch_3_End, 3, clearSword);          // Sword Fight from Left
                    // this->init(gamePlay, prince, 90, 9,  60, 3);  // Fight from Left

                    // prince.init(104, 56, Direction::Left, Stance::Crouch_3_End, 3, clearSword);          // Sword Fight from Right
                    // this->init(gamePlay, prince, 90, 9,  70, 3);  // Fight from Right

                    // prince.init(8+78+24, 25, Direction::Left, Stance::Crouch_3_End, 3, clearSword);     // Double collapisble
                    // this->init(gamePlay, prince, 90, 9,  10, 3);   // Double collapisble

                    // prince.init(78 + 24 + 12, 25 + 31 + 31, Direction::Left, Stance:: Crouch_3_End, 3, clearSword);          // Spikes Upper
                    // this->init(gamePlay, prince, 90, 9,  10, 0);   // Spikes Upper

                    // prince.init(12, 25 + 31, Direction::Left, Stance:: Crouch_3_End, 3, clearSword);          // Spikes Lower
                    // this->init(gamePlay, prince, 90, 9,  10, 6);   // Spikes Lower

                    // prince.init(78 + 24, 25, Direction::Left, Stance:: Crouch_3_End, 3, clearSword);          // Jump 2
                    // this->init(gamePlay, prince, 90, 9,  30, 3);  // Jump 2

                    // prince.init(18, 25+31, Direction::Right,Stance:: Crouch_3_End, 3, clearSword);          // Sword fight
                    // this->init(gamePlay, prince, 90, 9,  70, 3);  // Sword fight

                    // prince.init(58, 25+31+31, Direction::Right, Stance::Crouch_3_End, 3, clearSword);          // Second drink tonic
                    // this->init(gamePlay, prince, 90, 9,  50, 0);  // Second drink tonic

                    // prince.init(66, 25, Direction::Right, Stance::Crouch_3_End, 3, clearSword);          // Upper gate
                    // this->init(gamePlay, prince, 90, 9,  50, 0);  // Upper Gate

                    // prince.init(70, 25 + 31, Direction::Right, Stance::Crouch_3_End, 3, clearSword);          // 2 leap
                    // this->init(gamePlay, prince, 90, 9,  40, 3);  // 2 leap

                    // prince.init(14, 56, Direction::Right, Stance::Crouch_3_End, 3, clearSword);          // Exit Seq
                    // this->init(gamePlay, prince, 90, 9,  80, 3);  // Exit Seq

                    // prince.init(104, 56, Direction::Left, Stance::Crouch_3_End, 3, clearSword);          // Both floor types
                    // this->init(gamePlay, prince, 90, 9,  20, 3);  // Both floor types

                    // prince.init(86, 87, Direction::Right, Stance::Crouch_3_End, 3, clearSword);          // Normal starting pos but next to drop floor 3rd floor
                    // this->init(gamePlay, prince, 90, 9,  60, 0);  //Normal starting pos but next to drop floor 3rd floor

                    // prince.init(78, 25, Direction::Left, Stance::Crouch_3_End, 3, clearSword);          // Under collapsible floor
                    // this->init(gamePlay, prince, 90, 9,  50, 3);  // Under collapsible floor

                    // prince.init(66, 56, Direction::Right, Stance::Crouch_3_End, 3, clearSword);        // Get tonic
                    // this->init(gamePlay, prince, 90, 9,  Constants::TileHeight, 0);   // Get tonic

                    // prince.init(18, 25+31+31, Direction::Left, Stance::Upright, 3, clearSword);     // Column of climbs
                    // this->init(gamePlay, prince, 90, 9,  0, 3);   // Column of climbs

                    // prince.init(78, 25, Direction::Left, Stance::Upright, 3, clearSword);     // Below column of climbs
                    // this->init(gamePlay, prince, 90, 9,  0, 6);   // Below Column of climbs

                    // prince.init(80, 25, Direction::Right, Stance::Crouch_3_End, 3, clearSword);     // Top Left
                    // this->init(gamePlay, prince, 90, 9,  0, 0);   // Top left

                    // prince.init(18, 25, Direction::Right,Stance:: Crouch_3_End, 3, clearSword);          // Long Fall
                    // this->init(gamePlay, prince, 90, 9,  40, 4);  // Long Fall

                    // prince.init(18, 56, Direction::Right, Stance::Crouch_3_End, 3, clearSword);          // problem
                    // this->init(gamePlay, prince, 90, 9,  60, 3);  // problem

                    // prince.init(98, 87, Direction::Left, Stance::Crouch_3_End, 3, clearSword);          // At bottom of tthree level drop.
                    // this->init(gamePlay, prince, 90, 9,  30, 6); // At bottom of tthree level drop.

                    // prince.init(18, 25, Direction::Right, Stance::Crouch_3_End, 3, clearSword);          // Long Run
                    // this->init(gamePlay, prince, 90, 9,  40, 0);  // Long run

                    // prince.init(78 - 10, 25, Direction::Left, Stance::Crouch_3_End, 3, clearSword);          // Fall Error Stading Jump
                    // this->init(gamePlay, prince, 90, 9,  50, 3);  // Fall Error Stading Jump

                    // prince.init(78 - 4, 25, Direction::Left, Stance::Crouch_3_End, 3, clearSword);          // Fall Error running Jump
                    // this->init(gamePlay, prince, 90, 9,  50, 3);  // Fall Error running Jump

                }

                // Level 2

                if (gamePlay.level == 2) {

                    #ifndef SAVE_MEMORY_ENEMY
                        // enemy.init(EnemyType::Guard, 104 - 12 + (70 * Constants::TileWidth), 25+31 + (3 * Constants::TileHeight), Direction::Left, Stance::Upright, 3, Status::Active);          // Sword fight from Left
                        // enemy.init(EnemyType::Guard, 80 + (40 * Constants::TileWidth), 25 + (0 * Constants::TileHeight), Direction::Left, Stance::Upright, 3, Status::Active);          // Sword fight from Left
                    #endif

                    // Normal starting pos
                    prince.init(40, 56, Direction::Left, Stance::Crouch_3_End, 3, clearSword);     
                    this->init(gamePlay, prince, 130, 12, 120, 6); 

                    // Top of climbm down showing 10 error.
                    // prince.init(10, 56, Direction::Left, Stance::Upright, 3, clearSword);  
                    // this->init(gamePlay, prince, 130, 12, 100, 3);  

                    // Jump error
                    // prince.init(70-24, 56 + 31, Direction::Left, Stance::Upright, 3, clearSword);  
                    // this->init(gamePlay, prince, 130, 12, 100, 3);  

                    // Enemy 2 Fight.
                    // prince.init(10, 56, Direction::Left, Stance::Crouch_3_End, 3, clearSword);  
                    // this->init(gamePlay, prince, 130, 12, 80, 3);  

                    // Jump Up
                    // prince.init(22 + 84, 25, Direction::Left, Stance::Upright, 3, clearSword);  
                    // this->init(gamePlay, prince, 130, 12, 90, 6);  

                    // Double door button
                    // prince.init(22+(12*6), 56, Direction::Left, Stance::Upright, 3, clearSword);  
                    // this->init(gamePlay, prince, 130, 12, 80, 3);  

                    // Enemy 3
                    // prince.init(22+(12*6), 25, Direction::Left, Stance::Upright, 3, clearSword);  
                    // this->init(gamePlay, prince, 130, 12, 60, 3);  

                    // Enemy 3
                    // prince.init(22+(12*6), 56, Direction::Left, Stance::Upright, 3, clearSword);  
                    // this->init(gamePlay, prince, 130, 12, 20, 3);  

                }

                // Level 3

                if (gamePlay.level == 3) {

                    #ifndef SAVE_MEMORY_ENEMY
                        enemy.init(EnemyType::Guard, 70 + (10 * Constants::TileWidth), 56 + (3 * Constants::TileHeight), Direction::Left, Stance::Upright, 3, Status::Dormant);          // Sword fight from Left
                    #endif

                    // Normal starting pos
                    prince.init(46, 87, Direction::Left, Stance::Crouch_3_End, 3, clearSword);     
                    this->init(gamePlay, prince, 90, 15, 40, 6); 

                    // Three blades
                    // prince.init(10, 87, Direction::Right, Stance::Crouch_3_End, 3, clearSword);     
                    // this->init(gamePlay, prince, 90, 15, 80, 0); 

                    // Three blades
                    // prince.init(10, 25, Direction::Left, Stance::Crouch_3_End, 3, clearSword);     
                    // this->init(gamePlay, prince, 90, 15, 60, 3); 

                    // Top Left
                    // prince.init(10, 25, Direction::Left, Stance::Crouch_3_End, 3, clearSword);     
                    // this->init(gamePlay, prince, 90, 15, 20, 3); 

                    // // Biggest jump
                    // prince.init(10 + (8*12), 25, Direction::Left, Stance::Crouch_3_End, 3, clearSword);     
                    // this->init(gamePlay, prince, 90, 15, 20, 3); 

                    // Exit Button
                    // prince.init(10 + (4*12), 25, Direction::Left, Stance::Crouch_3_End, 3, clearSword);     
                    // this->init(gamePlay, prince, 90, 15, 0, 6); 

                    // Skeleton
                    // prince.init(10, 25, Direction::Right, Stance::Crouch_3_End, 3, clearSword);     
                    // this->init(gamePlay, prince, 90, 15, 10, 3); 

                }

                // Level 4

                if (gamePlay.level == 4) {

                    #ifndef SAVE_MEMORY_ENEMY
                        enemy.init(EnemyType::Mirror, 52 + (100 * Constants::TileWidth), 25 + (0 * Constants::TileHeight), Direction::Right, Stance::Upright, 3, Status::Dormant);         // Sword fight from Left
                        // enemy.init(EnemyType::Guard, 80 + (40 * Constants::TileWidth), 25 + (0 * Constants::TileHeight), Direction::Left, Stance::Upright, 3, Status::Active);          // Sword fight from Left
                    #endif

                    // Normal starting pos
                    // prince.init(46, 56, Direction::Left, Stance::Crouch_3_End, 3, clearSword);     
                    // this->init(gamePlay, prince, 120, 9, 40, 0); 

                    // Exit Sequence
                    // prince.init(10 + (4*12), 25, Direction::Left, Stance::Crouch_3_End, 3, clearSword);     
                    // this->init(gamePlay, prince, 120, 15, 70, 0); 

                    // Enable mirror
                    prince.init(10 + (6*12), 56, Direction::Right, Stance::Crouch_3_End, 3, clearSword);     
                    this->init(gamePlay, prince, 120, 9, 100, 0); 

                }

                // Level 5

                if (gamePlay.level == 5) {

                    #ifndef SAVE_MEMORY_ENEMY
                        enemy.init(EnemyType::Guard, 68 + (20 * Constants::TileWidth), 56 + (6 * Constants::TileHeight), Direction::Left, Stance::Upright, 3, Status::Active); 
                        enemy.init(EnemyType::Guard, 50 + (40 * Constants::TileWidth), 56 + (6 * Constants::TileHeight), Direction::Left, Stance::Upright, 3, Status::Active); 
                        enemy.init(EnemyType::Guard, 98 + (50 * Constants::TileWidth), 25 + (6 * Constants::TileHeight), Direction::Left, Stance::Upright, 3, Status::Active); 
                        enemy.init(EnemyType::Guard, 62 + (70 * Constants::TileWidth), 56 + (6 * Constants::TileHeight), Direction::Left, Stance::Upright, 3, Status::Active); 
                    #endif

                    // Normal starting pos
                    // prince.init(56, 87, Direction::Left, Stance::Crouch_3_End, 3, clearSword);     
                    // this->init(gamePlay, prince, 90, 15, 60, 6); 

                    
                    prince.init(10, 56, Direction::Right, Stance::Crouch_3_End, 3, clearSword);     
                    this->init(gamePlay, prince, 90, 15, 10, 6); 

                }

                // Level 6

                if (gamePlay.level == 6) {

                    #ifndef SAVE_MEMORY_ENEMY
                        enemy.init(EnemyType::Mirror, 10 + (0 * Constants::TileWidth), 56 + (0 * Constants::TileHeight), Direction::Right, Stance::Upright, 3, Status::Active);      
                    #endif

                    // Normal starting pos
                    // prince.init(32, 56, Direction::Left, Stance::Crouch_3_End, 3, clearSword);     
                    // this->init(gamePlay, prince, 70, 9, 50, 0); 

                    // Mirror
                    prince.init(110, 56, Direction::Left, Stance::Crouch_3_End, 3, clearSword);     
                    this->init(gamePlay, prince, 70, 9, 0, 0); 

                }

                // Level 7

                if (gamePlay.level == 7) {

                    #ifndef SAVE_MEMORY_ENEMY
                        // enemy.init(EnemyType::Mirror, 10 + (0 * Constants::TileWidth), 56 + (0 * Constants::TileHeight), Direction::Right, Stance::Upright, 3, Status::Active);      
                    #endif

                    // Normal starting pos
                    prince.init(32, 25, Direction::Right, Stance::Crouch_3_End, 3, clearSword);     
                    this->init(gamePlay, prince, 90, 12, 60, 3); 

                }


            #endif

        }

        void incYOffset(int8_t inc) {

            this->yOffset = this->yOffset + inc;
        }


        LevelUpdate update(Arduboy2Ext &arduboy, Prince &prince) { 

            LevelUpdate levelUpdate = LevelUpdate::NoAction;


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

            for (uint8_t i = 0; i < Constants::Items_Count; i++) {

                Item &item = this->getItem(i);

                if (item.itemType != ItemType::None) {

                    switch (item.itemType) {

                        case ItemType::Blade:
                             
                            item.data.blade.position++;
                            
                            if (item.data.blade.position == 40) {

                                item.data.blade.position = -5;

                            }

                            break;

                        case ItemType::ExitDoor_SelfOpen:
                        case ItemType::ExitDoor_ButtonOpen:

                            if (arduboy.isFrameCount(2)) {
                             
                                if (item.data.exitDoor.direction == Direction::Up && item.data.exitDoor.position < 11) {

                                    item.data.exitDoor.position++;

                                }

                            }

                            break;

                        case ItemType::Gate:
                        case ItemType::Gate_StayClosed:

                            if (arduboy.isFrameCount(4)) {

                                if (item.data.gate.closingDelay + 9 > item.data.gate.closingDelayMax) {

                                    if (item.data.gate.position < 9) {

                                        item.data.gate.position++;

                                    }

                                }
                                else if (item.data.gate.closingDelay > 0 && item.data.gate.closingDelay <= 9) {

                                    if (item.data.gate.position >= 3 ) {

                                        item.data.gate.position = item.data.gate.position - 3;
                                        
                                    }
                                    else if (item.data.gate.position < 3) {

                                        item.data.gate.position = 0;
                                        
                                    }
                                    
                                    break;

                                }
 
                                if (item.data.gate.closingDelay > 0) {

                                    item.data.gate.closingDelay--;

                                }

                            }
                            break;

                        // case ItemType::Gate_StayOpen:

                        //     if (arduboy.isFrameCount(4)) {

                        //         if (item.data.gate.direction == Direction::Up && item.data.gate.position < 9) {

                        //             item.data.gate.position++;
                                    
                        //         }
                        //         else if (item.data.gate.direction == Direction::Down && item.data.gate.position > 0) {

                        //             item.data.gate.position--;

                        //         }

                        //         if (item.data.gate.closingDelay > 0) {

                        //             item.data.gate.closingDelay--;

                        //         }

                        //     }
                        //     break;

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

                                    Point newPos = prince.getPosition();
                                    int8_t tileXIdx = this->coordToTileIndexX(newPos.x);
                                    int8_t tileYIdx = this->coordToTileIndexY(newPos.y);

                                    if (tileXIdx == item.x && tileYIdx == item.y) {

                                        levelUpdate = LevelUpdate::FloorCollapsedOnPrince;

                                    }

                                }

                            }

                            break;

                        case ItemType::Potion_Small:
                        case ItemType::Potion_Large:

                            if (arduboy.isFrameCount(6)) {

                                item.data.potion.frame = !item.data.potion.frame;

                            }
                            break;

                        case ItemType::Potion_Poison:

                            if (arduboy.isFrameCount(6)) {

                                item.data.potion.frame++;
                                if (item.data.potion.frame == 6) item.data.potion.frame = 0;

                            }
                            break;

                        case ItemType::FloorButton1:

                            // if (arduboy.isFrameCount(4)) {

                            //     if (item.data.floorButton.timeToFall > 1) {

                            //         item.data.floorButton.timeToFall--;

                            //     }

                            //     if (item.data.floorButton.timeToFall == 1) {
                                
                            //         item.data.floorButton.frame = 0;
                            //         item.data.floorButton.timeToFall = 0;

                            //     }

                            // }
                            // break;

                        case ItemType::FloorButton2:
                        case ItemType::FloorButton3_UpDown:
                        case ItemType::FloorButton3_UpOnly:
                        case ItemType::FloorButton3_DownOnly:
                        case ItemType::FloorButton4:

                            if (arduboy.isFrameCount(4)) {

                                if (item.data.floorButton.timeToFall > 1) {

                                    item.data.floorButton.timeToFall--;

                                }

                                if (item.data.floorButton.timeToFall == 1) {
                                
                                    item.data.floorButton.frame = 0;
                                    item.data.floorButton.timeToFall = 0;

                                }

                            }
                            break;

                        case ItemType::Spikes:

                            if (arduboy.isFrameCount(4)) {

                                switch (item.data.spikes.closingDelay) {

                                    case Constants::SpikeClosingDelay - 2 ... Constants::SpikeClosingDelay:
                                        item.data.spikes.closingDelay--;
                                        if (item.data.spikes.position < 3) {
                                            item.data.spikes.position++;
                                        }
                                        break;

                                    case 1 ... 3:
                                        item.data.spikes.closingDelay--;
                                        if (item.data.spikes.position > 0) {
                                            item.data.spikes.position--;
                                        }
                                        break; 

                                    case 0: 
                                        break;

                                    default:
                                        item.data.spikes.closingDelay--;
                                        break;

                                }

                            }

                            break;

                        default: break;

                    }

                }

            }

            if (flash.frame > 0) {

                if (arduboy.isFrameCount(2)) {

                    if (flash.frame > 0) {
                        
                        flash.frame--;

                    }
                        
                }

            }

            if (arduboy.isFrameCount(4)) {

                if (sign.counter > 1) {

                    sign.counter--;

                }

            }

            return levelUpdate;

        }

        int8_t coordToTileIndexX(int16_t x) {

            return (x / 12);                

        }

        int8_t coordToTileIndexY(int16_t y) {

            return (y / 31);                

        }

        int8_t distToEdgeOfTile(Direction direction, int16_t x) {

            int8_t tile = coordToTileIndexX(x);

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

            if (x <= -3 || x > 12) return TILE_NONE;

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

        uint8_t getItem(ItemType itemType, int8_t x, int8_t y) {

            return getItem(itemType, itemType, x, y);

        }


        // Locate the itemType at x, y.  Return the index of the specified itemType

        uint8_t getItem(ItemType itemType_Start, ItemType itemType_End, int8_t x, int8_t y) {

            for (uint8_t i = 0; i < Constants::Items_Count; i++) {
                
                Item &item = this->items[i];

                if (item.itemType >= itemType_Start && item.itemType <= itemType_End) {

                    if (item.itemType != ItemType::None && item.x == x && item.y == y) {
                        return i;
                    }

                }

            }

            return Constants::NoItemFound;
            
        }


        // Get the nth Gate (these are 1based)

        Item &getItemByIndex(ItemType itemType, uint8_t idx) {

            uint8_t count = 0;

            for (uint8_t i = 0; i < Constants::Items_Count; i++) {
                
                Item &item = this->items[i];

                // if (item.itemType == ItemType::Gate || item.itemType == ItemType::Gate_StayOpen) {
                if (item.itemType == itemType) {
                    
                    count++;

                    if (count == idx) {

                        return this->items[i];

                    }

                }

            }

            return this->items[0];
            
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

        void loadItems(GamePlay &gamePlay) {


            // Deactivate all items ..            

            for (Item &item : items) {
                item.itemType = ItemType::None;
            }

            this->sign.counter = 0;

            uint8_t itemIdx = 0;
            FX::seekData(FX::readIndexedUInt24(Levels::Level_Items, gamePlay.level));
            uint8_t itemType = FX::readPendingUInt8();

            while (itemType != 255) {

                Item &item = this->items[itemIdx];
                item.itemType = static_cast<ItemType>(itemType);
                item.x = FX::readPendingUInt8();
                item.y = FX::readPendingUInt8();

                switch (item.itemType) {

                    case ItemType::ExitDoor_SelfOpen:
                    case ItemType::ExitDoor_ButtonOpen:
                        item.data.exitDoor.position = 0;
                        item.data.exitDoor.direction = Direction::None;
                        item.data.exitDoor.left = FX::readPendingUInt8();
                        item.data.exitDoor.right = FX::readPendingUInt8();
                        break;

                    case ItemType::Gate:
                        {
                            uint8_t position = FX::readPendingUInt8();
                            uint8_t closingDelay = FX::readPendingUInt8();

                            if (!(gamePlay.level == 6 && itemIdx == 7 && item.data.gate.position == 9)) {
                                item.data.gate.position = position;
                                item.data.gate.closingDelay = closingDelay;
                                item.data.gate.defaultClosingDelay = item.data.gate.closingDelay;
                                item.data.gate.closingDelayMax = 255;
                            }

                        }
                        break;

                    // case ItemType::Gate_StayOpen:
                    //     item.data.gate.position = FX::readPendingUInt8();
                    //     item.data.gate.direction = static_cast<Direction>(FX::readPendingUInt8());
                    //     item.data.gate.closingDelay = 0;
                    //     break;

                    case ItemType::CollapsingFloor:
                        item.data.collapsingFloor.timeToFall = 0;
                        item.data.collapsingFloor.frame = 0;
                        item.data.collapsingFloor.distanceFallen = 0;
                        item.data.collapsingFloor.distToFall = FX::readPendingUInt8();
                        break;

                    case ItemType::FloorButton1:
                    case ItemType::FloorButton2:
                    case ItemType::FloorButton4:
                    case ItemType::FloorButton3_UpDown:
                    case ItemType::FloorButton3_UpOnly:
                    case ItemType::FloorButton3_DownOnly:
                        item.data.floorButton.frame = 0;
                        item.data.floorButton.gate1 = FX::readPendingUInt8();
                        item.data.floorButton.gate2 = FX::readPendingUInt8();
                        item.data.floorButton.timeToFall = 0;
                        break;
                    
                    case ItemType::Spikes:
                        item.data.spikes.imageType = FX::readPendingUInt8();
                        item.data.spikes.position = FX::readPendingUInt8();
                        break;
                    
                    case ItemType::Mirror:
                        item.data.mirror.status = Status::Dormant;
                        break;

                    default:
                        break;

                }

                itemType = FX::readPendingUInt8();
                itemIdx++;

            }

            FX::readEnd();

        }

        void loadMap(GamePlay &gamePlay) {


            uint8_t offset = 0;
            if (this->xLoc) {
                offset = this->xLoc - 3;
            }

            // Background ..

            for (uint8_t x = 0; x < 5 * 16; x++) {

                *(&bg[0][0] + x) = TILE_NONE;
            }

            for (int8_t y = this->yLoc - 1; y < (int8_t)(this->yLoc + 4); y++) {

                if (y >= 0) {
                    FX::seekDataArray(FX::readIndexedUInt24(Levels::Level_BG, gamePlay.level), y, offset, this->width);

                    for (uint8_t x = 0; x < 16; x++) {

                        if (x >= 3 || offset) {
                            bg[y - this->yLoc + 1][x] = static_cast<int8_t>(FX::readPendingUInt8());
                        }

                    }

                    FX::readEnd();
                }

            }


            // Foreground ..

                for (uint8_t x = 0; x < 5 * 16; x++) {

                    *(&fg[0][0] + x) = TILE_FG_WALL_1;

                }

            for (int8_t y = this->yLoc - 1; y < (int8_t)(this->yLoc + 4); y++) {

                if (y >= 0) {

                    FX::seekDataArray(FX::readIndexedUInt24(Levels::level_FG, gamePlay.level), y, offset, this->width);

                    for (uint8_t x = 0; x < 16; x++) {

                        if (x >= 3 || offset) {
                            fg[y - this->yLoc + 1][x] = static_cast<int8_t>(FX::readPendingUInt8());
                        }
                    }

                    FX::readEnd();
                }

            }

            #if defined(DEBUG) && defined(DEBUG_LEVEL_LOAD_MAP)
            printMap();
            #endif

        }


        WallTileResults isWallTile(int8_t fgTile, int8_t x = Constants::CoordNone, int8_t y = Constants::CoordNone, Direction direction = Direction::Left) {

            switch (fgTile) {

                case TILE_FG_WALL_1:
                case TILE_FG_WALL_2:
                case TILE_FG_WALL_3:
                case TILE_FG_WALL_4:
                case TILE_FG_WALL_5:
                case TILE_FG_WALL_6:
                case TILE_FG_WALL_7:
                case TILE_FG_WALL_8:
                case TILE_FLOOR_GATE_FRONT_TRACK_4:
                    return WallTileResults::SolidWall;

                default: 

                    int8_t offset = 0;

                    if (direction == Direction::Right) {
                        offset = 2;
                    }

                    if (x != Constants::CoordNone && y != Constants::CoordNone) {

                        // uint8_t idx = this->getItem(ItemType::Gate, ItemType::Gate_StayOpen, x + this->getXLocation() + offset, y + this->getYLocation());
                        uint8_t idx = this->getItem(ItemType::Gate, x + this->getXLocation() + offset, y + this->getYLocation());

                        if (idx != Constants::NoItemFound) {

                            Item &item = this->getItem(idx);

                            if (item.data.gate.position < 5) {

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
                // case TILE_FLOOR_RH_END_GATE:
                case TILE_FLOOR_LH_WALL_1:
                case TILE_FLOOR_LH_WALL_2:
                case TILE_FLOOR_LH_WALL_3:
                case TILE_FLOOR_LH_RUG_1:
                case TILE_COLUMN_LH_WALL:
                case TILE_COLUMN_1:
                case TILE_COLUMN_2:
                case TILE_COLUMN_3:
                case TILE_COLUMN_4:
                case TILE_COLUMN_5:
                case TILE_PILLAR_1:
                case TILE_PILLAR_2:
                case TILE_COLUMN_REAR_1:
                case TILE_COLUMN_REAR_2:
                case TILE_PILLAR_REAR_1:
                case TILE_FLOOR_GATE_REAR_TRACK_1:
                case TILE_FLOOR_GATE_REAR_TRACK_2:
                case TILE_FLOOR_GATE_FRONT_TRACK_1:
                    return true;

                default: break;

            }

            switch (fgTile) {

                case TILE_FG_WALL_1:
                case TILE_FG_WALL_2:
                case TILE_FG_WALL_3:
                case TILE_FG_WALL_4:
                case TILE_FG_WALL_5:
                case TILE_FG_WALL_6:
                case TILE_FG_WALL_7:
                case TILE_FG_WALL_8:
                    return false;

                // default:                     << Uncomment adds +32 bytes!
                //     return true;

            }

            return false;

        }



        bool isEdgeTile(int8_t bgTile, int8_t fgTile) {

            (void)fgTile;
            
            switch (bgTile) {

                case TILE_FLOOR_RH_END_1:
                case TILE_FLOOR_RH_END_2:
                case TILE_FLOOR_RH_END_3:        
                case TILE_FLOOR_RH_END_4:
                case TILE_FLOOR_RH_END_5:
                case TILE_FLOOR_RH_PILLAR_END:
                    return true;

            }

            return false;

        }

        bool canFall(int8_t bgTile, int8_t fgTile, int8_t x = Constants::CoordNone, int8_t y = Constants::CoordNone) {

            WallTileResults wallTile = this->isWallTile(fgTile, x, y);

            if (wallTile != WallTileResults::None) {

                #if defined(DEBUG) && defined(DEBUG_ACTION_CANFALL)
                DEBUG_PRINTLN(" true (a wall tile)");
                #endif                

                return false;
            }

            switch (bgTile) {

                case TILE_NONE:
                case TILE_WINDOW_LH:
                case TILE_WINDOW_RH:
                case TILE_RUG_1:
                case TILE_RUG_2:
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
                case TILE_FLOOR_RH_PILLAR_END:

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

                default:

                    #if defined(DEBUG) && defined(DEBUG_ACTION_CANFALL)
                    DEBUG_PRINTLN(" false");
                    #endif
                    return false;

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

            ImageDetails imageDetails;
            prince.getImageDetails(imageDetails);

            int8_t tileXIdx = this->coordToTileIndexX(newPos.x + imageDetails.toe) - this->getXLocation();
            int8_t tileYIdx = this->coordToTileIndexY(newPos.y) - this->getYLocation();
            
            int8_t bgTile1 = this->getTile(Layer::Background, tileXIdx, tileYIdx, TILE_FLOOR_BASIC);
            int8_t fgTile1 = this->getTile(Layer::Foreground, tileXIdx, tileYIdx, TILE_FLOOR_BASIC);
            
            #if defined(DEBUG) && defined(DEBUG_ACTION_CANFALL)
            DEBUG_PRINT(F("canFall(toe) stance:"));
            DEBUG_PRINT(prince.getStance());
            DEBUG_PRINT(F(", r:"));
            DEBUG_PRINT(imageDetails.reach);
            DEBUG_PRINT(F(", ft "));
            DEBUG_PRINT(imageDetails.toe);
            DEBUG_PRINT(F(", fh "));
            DEBUG_PRINT(imageDetails.heel);
            DEBUG_PRINT(F(", tileXIdx:"));
            DEBUG_PRINT(tileXIdx);
            DEBUG_PRINT(F(", tileYIdx:"));
            DEBUG_PRINT(tileYIdx);
            DEBUG_PRINT(F(", bg "));
            DEBUG_PRINT(bgTile1);
            DEBUG_PRINT(F(", fg "));
            DEBUG_PRINT(fgTile1);
            DEBUG_PRINT(" = ");
            #endif

            
            if (imageDetails.toe != Constants::InAir) {
            
                canFall = this->canFall(bgTile1, fgTile1, tileXIdx, tileYIdx);


                // If we the price cannot fall then return this now.  Ortherwise check the heel position ..

                if (!canFall) {

                    return false;

                }
                else {

                    int8_t tileXIdx = this->coordToTileIndexX(newPos.x + imageDetails.heel) - this->getXLocation();
                    int8_t tileYIdx = this->coordToTileIndexY(newPos.y) - this->getYLocation();
                    
                    int8_t bgTile1 = this->getTile(Layer::Background, tileXIdx, tileYIdx, TILE_FLOOR_BASIC);
                    int8_t fgTile1 = this->getTile(Layer::Foreground, tileXIdx, tileYIdx, TILE_FLOOR_BASIC);
                    
                    #if defined(DEBUG) && defined(DEBUG_ACTION_CANFALL)
                    DEBUG_PRINT(F("canFall(heel) stance:"));
                    DEBUG_PRINT(prince.getStance());
                    DEBUG_PRINT(F(", r:"));
                    DEBUG_PRINT(imageDetails.reach);
                    DEBUG_PRINT(F(", ft "));
                    DEBUG_PRINT(imageDetails.toe);
                    DEBUG_PRINT(F(", fh "));
                    DEBUG_PRINT(imageDetails.heel);
                    DEBUG_PRINT(F(", tileXIdx:"));
                    DEBUG_PRINT(tileXIdx);
                    DEBUG_PRINT(F(", tileYIdx:"));
                    DEBUG_PRINT(tileYIdx);
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

            int8_t tileXIdx = this->coordToTileIndexX(newPos.x) - this->getXLocation();
            int8_t tileYIdx = this->coordToTileIndexY(newPos.y) - this->getYLocation();
            
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

            int8_t tileXIdx = this->coordToTileIndexX(newPos.x) - this->getXLocation();
            int8_t tileYIdx = this->coordToTileIndexY(newPos.y) - this->getYLocation();

            #if defined(DEBUG) && defined(DEBUG_ACTION_CANCLIMBDOWN_PART2)
            DEBUG_PRINT(F("canClimbDown_Part2() "));
            DEBUG_PRINT(tileXIdx);
            DEBUG_PRINT(F(","));
            DEBUG_PRINTLN(tileYIdx);
            #endif

            #if defined(DEBUG) && defined(DEBUG_ACTION_CANCLIMBDOWN_PART2)
            printCoordToIndex(newPos, tileXIdx, tileYIdx);
            #endif

            // int8_t bgTile = this->getTile(Layer::Background, tileXIdx + (prince.getDirection() == Direction::Left ? 1 : 0), tileYIdx, TILE_FLOOR_BASIC);
            // int8_t fgTile = this->getTile(Layer::Foreground, tileXIdx + (prince.getDirection() == Direction::Left ? 1 : 0), tileYIdx, TILE_FLOOR_BASIC);
            int8_t bgTile = this->getTile(Layer::Background, tileXIdx + (prince.getDirection() == Direction::Left ? 0 : 0), tileYIdx, TILE_FLOOR_BASIC);
            int8_t fgTile = this->getTile(Layer::Foreground, tileXIdx + (prince.getDirection() == Direction::Left ? 0 : 0), tileYIdx, TILE_FLOOR_BASIC);

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

            isGroundTile = this->isGroundTile(bgTile, fgTile);
            bool isEdgeTile = this->isEdgeTile(bgTile, fgTile);

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
            DEBUG_PRINT(isGroundTile);
            DEBUG_PRINT(F(", isEdgeTile: "));
            DEBUG_PRINT(isEdgeTile);
            #endif

            if (isGroundTile || isEdgeTile) {

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

        uint8_t canReachItem(Prince &prince, ItemType itemTypeStart, ItemType itemTypeEnd = ItemType::None) {

            if (itemTypeEnd == ItemType::None) itemTypeEnd = itemTypeStart;

            int8_t tileXIdx = this->coordToTileIndexX(prince.getPosition().x);
            int8_t tileYIdx = this->coordToTileIndexY(prince.getPosition().y);

            for (uint8_t i = 0; i < Constants::Items_Count; i++) {

                Item &item = this->items[i];

                if ((item.itemType >= itemTypeStart && item.itemType <= itemTypeEnd) && item.x == tileXIdx && item.y == tileYIdx) {

                    return i;

                }

            }

            return Constants::NoItemFound;

        }

        bool canMoveForward(BaseEntity &entity, Action action, Direction direction = Direction::None) {

            int8_t tileXIdx = this->coordToTileIndexX(entity.getPosition().x) - this->getXLocation();
            int8_t tileYIdx = this->coordToTileIndexY(entity.getPosition().y) - this->getYLocation();

            if (direction == Direction::None) {
                direction = entity.getDirection();
            }

            #if defined(DEBUG) && defined(DEBUG_ACTION_CANMOVEFORWARD)
            DEBUG_PRINTLN(F("------------------------------"));
            printAction(action);
            DEBUG_PRINT(F(" coordToTileIndexX "));
            DEBUG_PRINT(entity.getPosition().x);
            DEBUG_PRINT(F(" = "));
            DEBUG_PRINT(tileXIdx);
            DEBUG_PRINT(F(", coordToTileIndexY "));
            DEBUG_PRINT(entity.getPosition().y);
            DEBUG_PRINT(F(" = "));
            DEBUG_PRINTLN(tileYIdx);
            #endif

            switch (direction) {

                case Direction::Left:
                    {
                        #if defined(DEBUG) && defined(DEBUG_ACTION_CANMOVEFORWARD)
                        int8_t bgTile2 = this->getTile(Layer::Background, tileXIdx - 1, tileYIdx, TILE_FLOOR_BASIC);
                        #endif

                        int8_t fgTile2 = this->getTile(Layer::Foreground, tileXIdx - 1, tileYIdx, TILE_FLOOR_BASIC);
                        int8_t distToEdgeOfCurrentTile = distToEdgeOfTile(direction, entity.getPosition().x);

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
                                            
                                            WallTileResults wallTile = this->isWallTile(fgTile2, tileXIdx, tileYIdx, Direction::Left);
                                            return (wallTile == WallTileResults::None);
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

                                            WallTileResults wallTile = this->isWallTile(fgTile2, tileXIdx, tileYIdx, Direction::Left);
                                            return (wallTile == WallTileResults::None);
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
                                    
                                    WallTileResults wallTile = this->isWallTile(fgTile2, tileXIdx, tileYIdx, Direction::Left);
                                    return wallTile == WallTileResults::None;

                                }

                                return false;

                            default: return false;

                        }

                    }

                    break;

                case Direction::Right:
                    {
                        #if defined(DEBUG) && defined(DEBUG_ACTION_CANMOVEFORWARD)
                        int8_t bgTile2 = this->getTile(Layer::Background, tileXIdx + 1, tileYIdx, TILE_FLOOR_BASIC);
                        #endif

                        int8_t fgTile2 = this->getTile(Layer::Foreground, tileXIdx + 1, tileYIdx, TILE_FLOOR_BASIC);
                        int8_t distToEdgeOfCurrentTile = distToEdgeOfTile(direction, entity.getPosition().x);

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
                                    WallTileResults wallTile = this->isWallTile(fgTile2, tileXIdx, tileYIdx, Direction::Right);

                                    #if defined(DEBUG) && defined(DEBUG_ACTION_CANMOVEFORWARD)
                                    printTileInfo(bgTile2, fgTile2);
                                    #endif

                                    switch (distToEdgeOfCurrentTile) {

                                        case 0 ... 6:

                                            return wallTile == WallTileResults::None;
                                            
                                        default:

                                            return true;

                                    }

                                }

                                break;

                            case Action::Step:
                            case Action::RunStart:
                                {
                                    WallTileResults wallTile = this->isWallTile(fgTile2, tileXIdx, tileYIdx, Direction::Right);

                                    #if defined(DEBUG) && defined(DEBUG_ACTION_CANMOVEFORWARD)
                                    printTileInfo(bgTile2, fgTile2);
                                    #endif

                                    switch (distToEdgeOfCurrentTile) {

                                        case 0 ... 9:

                                            return wallTile == WallTileResults::None;

                                        case 10:

                                            return wallTile != WallTileResults::GateClosed;
                                            
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
                                    
                                    WallTileResults wallTile = this->isWallTile(fgTile2, tileXIdx, tileYIdx, Direction::Right);
                                    return wallTile == WallTileResults::None;

                                }
                                
                                return false;

                            default: return false;

                        }

                    }

                    break;

                default: break;

            }

            return true;

        }


        RunningJumpResult canRunningJump(Prince &prince, Action action) {

            int8_t tileXIdx = this->coordToTileIndexX(prince.getPosition().x) - this->getXLocation();
            int8_t tileYIdx = this->coordToTileIndexY(prince.getPosition().y) - this->getYLocation();

            #if defined(DEBUG) && defined(DEBUG_ACTION_CANRUNNINGJUMP)
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

                        #if defined(DEBUG) && defined(DEBUG_ACTION_CANRUNNINGJUMP)
                        int8_t bgTile1 = this->getTile(Layer::Background, tileXIdx, tileYIdx, TILE_FLOOR_BASIC);
                        int8_t fgTile1 = this->getTile(Layer::Foreground, tileXIdx, tileYIdx, TILE_FLOOR_BASIC);
                        int8_t distToEdgeOfCurrentTile = distToEdgeOfTile(prince.getDirection(), prince.getPosition().x);

                        // DEBUG_PRINT(F(" left dist "));
                        // DEBUG_PRINT(distToEdgeOfCurrentTile);
                        // DEBUG_PRINT(F(", bg "));
                        // DEBUG_PRINT(bgTile2);
                        DEBUG_PRINT(F(" "));
                        DEBUG_PRINT(bgTile1);
                        DEBUG_PRINT(F(", fg "));
                        // DEBUG_PRINT(fgTile2);
                        // DEBUG_PRINT(F(" "));
                        DEBUG_PRINT(fgTile1);
                        DEBUG_PRINTLN("");
                        #endif

                        switch (action) {

                            case Action::RunJump_3:
                                {
                                    int8_t bgTile5_CurrLvl = this->getTile(Layer::Background, tileXIdx - 4, tileYIdx, TILE_FLOOR_BASIC);
                                    int8_t fgTile5_CurrLvl = this->getTile(Layer::Foreground, tileXIdx - 4, tileYIdx, TILE_FLOOR_BASIC);
                                    int8_t bgTile4_CurrLvl = this->getTile(Layer::Background, tileXIdx - 3, tileYIdx, TILE_FLOOR_BASIC);
                                    int8_t fgTile4_CurrLvl = this->getTile(Layer::Foreground, tileXIdx - 3, tileYIdx, TILE_FLOOR_BASIC);
                                    int8_t bgTile3_CurrLvl = this->getTile(Layer::Background, tileXIdx - 2, tileYIdx, TILE_FLOOR_BASIC);
                                    int8_t fgTile3_CurrLvl = this->getTile(Layer::Foreground, tileXIdx - 2, tileYIdx, TILE_FLOOR_BASIC);
                                    int8_t bgTile2_CurrLvl = this->getTile(Layer::Background, tileXIdx - 1, tileYIdx, TILE_FLOOR_BASIC);
                                    int8_t fgTile2_CurrLvl = this->getTile(Layer::Foreground, tileXIdx - 1, tileYIdx, TILE_FLOOR_BASIC);

                                    int8_t bgTile6_NextLvl = this->getTile(Layer::Background, tileXIdx - 5, tileYIdx + 1, TILE_FLOOR_BASIC);
                                    int8_t fgTile6_NextLvl = this->getTile(Layer::Foreground, tileXIdx - 5, tileYIdx + 1, TILE_FLOOR_BASIC);
                                    int8_t bgTile5_NextLvl = this->getTile(Layer::Background, tileXIdx - 4, tileYIdx + 1, TILE_FLOOR_BASIC);
                                    int8_t fgTile5_NextLvl = this->getTile(Layer::Foreground, tileXIdx - 4, tileYIdx + 1, TILE_FLOOR_BASIC);
                                    int8_t bgTile4_NextLvl = this->getTile(Layer::Background, tileXIdx - 3, tileYIdx + 1, TILE_FLOOR_BASIC);
                                    int8_t fgTile4_NextLvl = this->getTile(Layer::Foreground, tileXIdx - 3, tileYIdx + 1, TILE_FLOOR_BASIC);
                                    int8_t bgTile3_NextLvl = this->getTile(Layer::Background, tileXIdx - 2, tileYIdx + 1, TILE_FLOOR_BASIC);
                                    int8_t fgTile3_NextLvl = this->getTile(Layer::Foreground, tileXIdx - 2, tileYIdx + 1, TILE_FLOOR_BASIC);
                                    int8_t bgTile2_NextLvl = this->getTile(Layer::Background, tileXIdx - 1, tileYIdx + 1, TILE_FLOOR_BASIC);
                                    int8_t fgTile2_NextLvl = this->getTile(Layer::Foreground, tileXIdx - 1, tileYIdx + 1, TILE_FLOOR_BASIC);

                                    int8_t distToEdgeOfCurrentTile = distToEdgeOfTile(prince.getDirection(), prince.getPosition().x);

                                    WallTileResults wallTile2_CurrLvl = this->isWallTile(fgTile2_CurrLvl - 1, tileXIdx, tileYIdx, Direction::Left);
                                    WallTileResults wallTile3_CurrLvl = this->isWallTile(fgTile3_CurrLvl - 2, tileXIdx, tileYIdx, Direction::Left);
                                    WallTileResults wallTile4_CurrLvl = this->isWallTile(fgTile4_CurrLvl - 3, tileXIdx, tileYIdx, Direction::Left);
                                    WallTileResults wallTile5_CurrLvl = this->isWallTile(fgTile5_CurrLvl - 4, tileXIdx, tileYIdx, Direction::Left);

                                    WallTileResults wallTile2_NextLvl = this->isWallTile(fgTile2_NextLvl - 1, tileXIdx, tileYIdx + 1, Direction::Left);
                                    WallTileResults wallTile3_NextLvl = this->isWallTile(fgTile3_NextLvl - 2, tileXIdx, tileYIdx + 1, Direction::Left);
                                    WallTileResults wallTile4_NextLvl = this->isWallTile(fgTile4_NextLvl - 3, tileXIdx, tileYIdx + 1, Direction::Left);
                                    WallTileResults wallTile5_NextLvl = this->isWallTile(fgTile5_NextLvl - 4, tileXIdx, tileYIdx + 1, Direction::Left);
                                    WallTileResults wallTile6_NextLvl = this->isWallTile(fgTile6_NextLvl - 5, tileXIdx, tileYIdx + 1, Direction::Left);
                                    
                                    bool isGroundTile2_CurrLvl = this->isGroundTile(bgTile2_CurrLvl, fgTile2_CurrLvl);
                                    bool isGroundTile3_CurrLvl = this->isGroundTile(bgTile3_CurrLvl, fgTile3_CurrLvl);
                                    bool isGroundTile4_CurrLvl = this->isGroundTile(bgTile4_CurrLvl, fgTile4_CurrLvl);
                                    bool isGroundTile5_CurrLvl = this->isGroundTile(bgTile5_CurrLvl, fgTile5_CurrLvl);

                                    bool isGroundTile2_NextLvl = this->isGroundTile(bgTile2_NextLvl, fgTile2_NextLvl);
                                    bool isGroundTile3_NextLvl = this->isGroundTile(bgTile3_NextLvl, fgTile3_NextLvl);
                                    bool isGroundTile4_NextLvl = this->isGroundTile(bgTile4_NextLvl, fgTile4_NextLvl);
                                    bool isGroundTile5_NextLvl = this->isGroundTile(bgTile5_NextLvl, fgTile5_NextLvl);
                                    bool isGroundTile6_NextLvl = this->isGroundTile(bgTile6_NextLvl, fgTile6_NextLvl);


                                    // Can we jump four blanks to a lower level?  This occurs on the first level, top left corner.

                                    if (wallTile2_CurrLvl == WallTileResults::None && 
                                        wallTile3_CurrLvl == WallTileResults::None && 
                                        wallTile4_CurrLvl == WallTileResults::None && 
                                        wallTile5_CurrLvl == WallTileResults::None && 
                                        wallTile2_NextLvl == WallTileResults::None && 
                                        wallTile3_NextLvl == WallTileResults::None && 
                                        wallTile4_NextLvl == WallTileResults::None && 
                                        wallTile5_NextLvl == WallTileResults::None && 
                                        wallTile6_NextLvl == WallTileResults::None && 
                                        !isGroundTile2_CurrLvl &&
                                        !isGroundTile3_CurrLvl &&
                                        !isGroundTile4_CurrLvl &&
                                        !isGroundTile5_CurrLvl &&
                                        !isGroundTile2_NextLvl &&
                                        !isGroundTile3_NextLvl &&
                                        !isGroundTile4_NextLvl &&
                                        !isGroundTile5_NextLvl &&
                                        isGroundTile6_NextLvl) {

                                        switch (distToEdgeOfCurrentTile) {

                                            case 0 ... 8:
                                         
                                                return RunningJumpResult::Jump4_DropLevel;
                                            
                                        }

                                    }


                                    // Can we jump three blanks to the same level?

                                    if (wallTile2_CurrLvl == WallTileResults::None && 
                                        wallTile3_CurrLvl == WallTileResults::None && 
                                        wallTile4_CurrLvl == WallTileResults::None && 
                                        wallTile5_CurrLvl == WallTileResults::None && 
                                        !isGroundTile2_CurrLvl &&
                                        !isGroundTile3_CurrLvl &&
                                        !isGroundTile4_CurrLvl &&
                                        isGroundTile5_CurrLvl) {

                                        switch (distToEdgeOfCurrentTile) {

                                            case 2:
                                                return RunningJumpResult::Jump3_KeepLevel_Short;

                                            default:
                                                return RunningJumpResult::Jump3_KeepLevel;

                                        }

                                    }


                                    // Can we jump three blanks to a lower level?  This occurs on the first level, top left corner.

                                    if (wallTile2_CurrLvl == WallTileResults::None && 
                                        wallTile3_CurrLvl == WallTileResults::None && 
                                        wallTile4_CurrLvl == WallTileResults::None && 
                                        wallTile5_CurrLvl != WallTileResults::None && 
                                        wallTile2_NextLvl == WallTileResults::None && 
                                        wallTile3_NextLvl == WallTileResults::None && 
                                        wallTile4_NextLvl == WallTileResults::None && 
                                        wallTile5_NextLvl == WallTileResults::None && 
                                        !isGroundTile2_CurrLvl &&
                                        !isGroundTile3_CurrLvl &&
                                        !isGroundTile4_CurrLvl &&
                                        !isGroundTile2_NextLvl &&
                                        !isGroundTile3_NextLvl &&
                                        !isGroundTile4_NextLvl &&
                                        isGroundTile5_NextLvl) {

                                        return RunningJumpResult::Jump3_DropLevel;

                                    }


                                    WallTileResults wallTile = this->isWallTile(fgTile4_CurrLvl, tileXIdx - 3, tileYIdx, Direction::Left); //SJH -3?
                                
                                    #if defined(DEBUG) && defined(DEBUG_ACTION_CANRUNNINGJUMP)
                                    // printTileInfo(bgTile4, fgTile4);
                                    DEBUG_PRINT("isWallTile(");
                                    // DEBUG_PRINT(bgTile4);
                                    // DEBUG_PRINT(",");
                                    // DEBUG_PRINT(fgTile4);
                                    // DEBUG_PRINT(",");
                                    DEBUG_PRINT(tileXIdx + 3);
                                    DEBUG_PRINT(",");
                                    DEBUG_PRINT(tileYIdx);
                                    DEBUG_PRINT(") = ");
                                    DEBUG_PRINTLN((uint8_t)wallTile);
                                    #endif
    
                                    return (wallTile == WallTileResults::None ? RunningJumpResult::Normal : RunningJumpResult::None);

                                }

                                return RunningJumpResult::Normal;                                

                            case Action::RunJump_2:
                                {
                                    #if defined(DEBUG) && defined(DEBUG_ACTION_CANRUNNINGJUMP)
                                    int8_t bgTile = this->getTile(Layer::Background, tileXIdx - 2, tileYIdx, TILE_FLOOR_BASIC);
                                    #endif

                                    int8_t fgTile = this->getTile(Layer::Foreground, tileXIdx - 2, tileYIdx, TILE_FLOOR_BASIC);
                                    WallTileResults wallTile = this->isWallTile(fgTile, tileXIdx - 2, tileYIdx, Direction::Left); //SJH -2?
                                    
                                    #if defined(DEBUG) && defined(DEBUG_ACTION_CANRUNNINGJUMP)
                                    // printTileInfo(bgTile3, fgTile3);
                                    DEBUG_PRINT("isWallTile(");
                                    DEBUG_PRINT(bgTile);
                                    DEBUG_PRINT(",");
                                    DEBUG_PRINT(fgTile);
                                    DEBUG_PRINT(",");
                                    DEBUG_PRINT(tileXIdx + 2);
                                    DEBUG_PRINT(",");
                                    DEBUG_PRINT(tileYIdx);
                                    DEBUG_PRINT(") = ");
                                    DEBUG_PRINTLN((uint8_t)wallTile);
                                    #endif

                                    return (wallTile == WallTileResults::None ? RunningJumpResult::Normal : RunningJumpResult::None);

                                }

                                return RunningJumpResult::Normal;

                            case Action::RunJump_1:
                                {
                                    #if defined(DEBUG) && defined(DEBUG_ACTION_CANRUNNINGJUMP)
                                    int8_t bgTile = this->getTile(Layer::Background, tileXIdx - 1, tileYIdx, TILE_FLOOR_BASIC);
                                    #endif

                                    int8_t fgTile = this->getTile(Layer::Foreground, tileXIdx - 1, tileYIdx, TILE_FLOOR_BASIC);
                                    WallTileResults wallTile = this->isWallTile(fgTile, tileXIdx - 1, tileYIdx, Direction::Left); //SJH -1?

                                    #if defined(DEBUG) && defined(DEBUG_ACTION_CANRUNNINGJUMP)
                                    // printTileInfo(bgTile2, fgTile2);
                                    DEBUG_PRINT("isWallTile(");
                                    DEBUG_PRINT(bgTile);
                                    DEBUG_PRINT(",");
                                    DEBUG_PRINT(fgTile);
                                    DEBUG_PRINT(",");
                                    DEBUG_PRINT(tileXIdx + 1);
                                    DEBUG_PRINT(",");
                                    DEBUG_PRINT(tileYIdx);
                                    DEBUG_PRINT(") = ");
                                    DEBUG_PRINTLN((uint8_t)wallTile);
                                    #endif

                                    return (wallTile == WallTileResults::None ? RunningJumpResult::Normal : RunningJumpResult::None);

                                }

                                return RunningJumpResult::Normal;

                            default: return RunningJumpResult::None;

                        }

                    }

                    break;

                case Direction::Right:
                    {

                        #if defined(DEBUG) && defined(DEBUG_ACTION_CANRUNNINGJUMP)
                        int8_t bgTile1 = this->getTile(Layer::Background, tileXIdx, tileYIdx, TILE_FLOOR_BASIC);
                        int8_t fgTile1 = this->getTile(Layer::Foreground, tileXIdx, tileYIdx, TILE_FLOOR_BASIC);
                        // DEBUG_PRINT(F(" right dist "));
                        // DEBUG_PRINT(distToEdgeOfCurrentTile);
                        // DEBUG_PRINT(F(", bg "));
                        // DEBUG_PRINT(bgTile1);
                        // DEBUG_PRINT(F(" "));
                        // DEBUG_PRINT(bgTile2);
                        // DEBUG_PRINT(F(", fg "));
                        // DEBUG_PRINT(fgTile1);
                        // DEBUG_PRINT(F(" "));
                        // DEBUG_PRINT(fgTile2);
                        // DEBUG_PRINTLN("");
                        #endif

                        switch (action) {

                            case Action::RunJump_3:
                                {
                                    int8_t bgTile5_CurrLvl = this->getTile(Layer::Background, tileXIdx + 4, tileYIdx, TILE_FLOOR_BASIC);
                                    int8_t fgTile5_CurrLvl = this->getTile(Layer::Foreground, tileXIdx + 4, tileYIdx, TILE_FLOOR_BASIC);
                                    int8_t bgTile4_CurrLvl = this->getTile(Layer::Background, tileXIdx + 3, tileYIdx, TILE_FLOOR_BASIC);
                                    int8_t fgTile4_CurrLvl = this->getTile(Layer::Foreground, tileXIdx + 3, tileYIdx, TILE_FLOOR_BASIC);
                                    int8_t bgTile3_CurrLvl = this->getTile(Layer::Background, tileXIdx + 2, tileYIdx, TILE_FLOOR_BASIC);
                                    int8_t fgTile3_CurrLvl = this->getTile(Layer::Foreground, tileXIdx + 2, tileYIdx, TILE_FLOOR_BASIC);
                                    int8_t bgTile2_CurrLvl = this->getTile(Layer::Background, tileXIdx + 1, tileYIdx, TILE_FLOOR_BASIC);
                                    int8_t fgTile2_CurrLvl = this->getTile(Layer::Foreground, tileXIdx + 1, tileYIdx, TILE_FLOOR_BASIC);

                                    int8_t bgTile6_NextLvl = this->getTile(Layer::Background, tileXIdx + 5, tileYIdx + 1, TILE_FLOOR_BASIC);
                                    int8_t fgTile6_NextLvl = this->getTile(Layer::Foreground, tileXIdx + 5, tileYIdx + 1, TILE_FLOOR_BASIC);
                                    int8_t bgTile5_NextLvl = this->getTile(Layer::Background, tileXIdx + 4, tileYIdx + 1, TILE_FLOOR_BASIC);
                                    int8_t fgTile5_NextLvl = this->getTile(Layer::Foreground, tileXIdx + 4, tileYIdx + 1, TILE_FLOOR_BASIC);
                                    int8_t bgTile4_NextLvl = this->getTile(Layer::Background, tileXIdx + 3, tileYIdx + 1, TILE_FLOOR_BASIC);
                                    int8_t fgTile4_NextLvl = this->getTile(Layer::Foreground, tileXIdx + 3, tileYIdx + 1, TILE_FLOOR_BASIC);
                                    int8_t bgTile3_NextLvl = this->getTile(Layer::Background, tileXIdx + 2, tileYIdx + 1, TILE_FLOOR_BASIC);
                                    int8_t fgTile3_NextLvl = this->getTile(Layer::Foreground, tileXIdx + 2, tileYIdx + 1, TILE_FLOOR_BASIC);
                                    int8_t bgTile2_NextLvl = this->getTile(Layer::Background, tileXIdx + 1, tileYIdx + 1, TILE_FLOOR_BASIC);
                                    int8_t fgTile2_NextLvl = this->getTile(Layer::Foreground, tileXIdx + 1, tileYIdx + 1, TILE_FLOOR_BASIC);

                                    int8_t distToEdgeOfCurrentTile = distToEdgeOfTile(prince.getDirection(), prince.getPosition().x);

                                    WallTileResults wallTile2_CurrLvl = this->isWallTile(fgTile2_CurrLvl, tileXIdx + 1, tileYIdx, Direction::Right);
                                    WallTileResults wallTile3_CurrLvl = this->isWallTile(fgTile3_CurrLvl, tileXIdx + 2, tileYIdx, Direction::Right);
                                    WallTileResults wallTile4_CurrLvl = this->isWallTile(fgTile4_CurrLvl, tileXIdx + 3, tileYIdx, Direction::Right);
                                    WallTileResults wallTile5_CurrLvl = this->isWallTile(fgTile5_CurrLvl, tileXIdx + 4, tileYIdx, Direction::Right);

                                    WallTileResults wallTile2_NextLvl = this->isWallTile(fgTile2_NextLvl, tileXIdx + 1, tileYIdx + 1, Direction::Right);
                                    WallTileResults wallTile3_NextLvl = this->isWallTile(fgTile3_NextLvl, tileXIdx + 2, tileYIdx + 1, Direction::Right);
                                    WallTileResults wallTile4_NextLvl = this->isWallTile(fgTile4_NextLvl, tileXIdx + 3, tileYIdx + 1, Direction::Right);
                                    WallTileResults wallTile5_NextLvl = this->isWallTile(fgTile5_NextLvl, tileXIdx + 4, tileYIdx + 1, Direction::Right);
                                    WallTileResults wallTile6_NextLvl = this->isWallTile(fgTile6_NextLvl, tileXIdx + 5, tileYIdx + 1, Direction::Right);
                                    
                                    bool isGroundTile2_CurrLvl = this->isGroundTile(bgTile2_CurrLvl, fgTile2_CurrLvl);
                                    bool isGroundTile3_CurrLvl = this->isGroundTile(bgTile3_CurrLvl, fgTile3_CurrLvl);
                                    bool isGroundTile4_CurrLvl = this->isGroundTile(bgTile4_CurrLvl, fgTile4_CurrLvl);
                                    bool isGroundTile5_CurrLvl = this->isGroundTile(bgTile5_CurrLvl, fgTile5_CurrLvl);

                                    bool isGroundTile2_NextLvl = this->isGroundTile(bgTile2_NextLvl, fgTile2_NextLvl);
                                    bool isGroundTile3_NextLvl = this->isGroundTile(bgTile3_NextLvl, fgTile3_NextLvl);
                                    bool isGroundTile4_NextLvl = this->isGroundTile(bgTile4_NextLvl, fgTile4_NextLvl);
                                    bool isGroundTile5_NextLvl = this->isGroundTile(bgTile5_NextLvl, fgTile5_NextLvl);
                                    bool isGroundTile6_NextLvl = this->isGroundTile(bgTile6_NextLvl, fgTile6_NextLvl);


                                    // Can we jump four blanks to a lower level?  This occurs on the first level, top left corner.

                                    if (wallTile2_CurrLvl == WallTileResults::None && 
                                        wallTile3_CurrLvl == WallTileResults::None && 
                                        wallTile4_CurrLvl == WallTileResults::None && 
                                        wallTile5_CurrLvl == WallTileResults::None && 
                                        wallTile2_NextLvl == WallTileResults::None && 
                                        wallTile3_NextLvl == WallTileResults::None && 
                                        wallTile4_NextLvl == WallTileResults::None && 
                                        wallTile5_NextLvl == WallTileResults::None && 
                                        wallTile6_NextLvl == WallTileResults::None && 
                                        !isGroundTile2_CurrLvl &&
                                        !isGroundTile3_CurrLvl &&
                                        !isGroundTile4_CurrLvl &&
                                        !isGroundTile5_CurrLvl &&
                                        !isGroundTile2_NextLvl &&
                                        !isGroundTile3_NextLvl &&
                                        !isGroundTile4_NextLvl &&
                                        !isGroundTile5_NextLvl &&
                                        isGroundTile6_NextLvl) {

                                        switch (distToEdgeOfCurrentTile) {

                                            case 0 ... 8:

                                                return RunningJumpResult::Jump4_DropLevel;
                                            
                                        }

                                    }


                                    // Can we jump three blanks to the same level?

                                    if (wallTile2_CurrLvl == WallTileResults::None && 
                                        wallTile3_CurrLvl == WallTileResults::None && 
                                        wallTile4_CurrLvl == WallTileResults::None && 
                                        wallTile5_CurrLvl == WallTileResults::None && 
                                        !isGroundTile2_CurrLvl &&
                                        !isGroundTile3_CurrLvl &&
                                        !isGroundTile4_CurrLvl &&
                                        isGroundTile5_CurrLvl) {

                                        return RunningJumpResult::Jump3_KeepLevel;

                                    }


                                    // Can we jump three blanks to a lower level?  This occurs on the first level, top left corner.

                                    if (wallTile2_CurrLvl == WallTileResults::None && 
                                        wallTile3_CurrLvl == WallTileResults::None && 
                                        wallTile4_CurrLvl == WallTileResults::None && 
                                        wallTile5_CurrLvl != WallTileResults::None && 
                                        wallTile2_NextLvl == WallTileResults::None && 
                                        wallTile3_NextLvl == WallTileResults::None && 
                                        wallTile4_NextLvl == WallTileResults::None && 
                                        wallTile5_NextLvl == WallTileResults::None && 
                                        !isGroundTile2_CurrLvl &&
                                        !isGroundTile3_CurrLvl &&
                                        !isGroundTile4_CurrLvl &&
                                        !isGroundTile2_NextLvl &&
                                        !isGroundTile3_NextLvl &&
                                        !isGroundTile4_NextLvl &&
                                        isGroundTile5_NextLvl) {

                                        return RunningJumpResult::Jump3_DropLevel;

                                    }


                                    WallTileResults wallTile = this->isWallTile(fgTile4_CurrLvl, tileXIdx + 3, tileYIdx, Direction::Right);
                                
                                    #if defined(DEBUG) && defined(DEBUG_ACTION_CANRUNNINGJUMP)
                                    // printTileInfo(bgTile4, fgTile4);
                                    // DEBUG_PRINT("isWallTile(");
                                    // DEBUG_PRINT(bgTile4);
                                    // DEBUG_PRINT(",");
                                    // DEBUG_PRINT(fgTile4);
                                    // DEBUG_PRINT(",");
                                    // DEBUG_PRINT(tileXIdx + 3);
                                    // DEBUG_PRINT(",");
                                    // DEBUG_PRINT(tileYIdx);
                                    // DEBUG_PRINT(") = ");
                                    // DEBUG_PRINTLN((uint8_t)wallTile);
                                    #endif
    
                                    return (wallTile == WallTileResults::None ? RunningJumpResult::Normal : RunningJumpResult::None);                              

                                }

                                return RunningJumpResult::Normal;  

                            case Action::RunJump_2:
                                {
                                    #if defined(DEBUG) && defined(DEBUG_ACTION_CANRUNNINGJUMP)
                                    int8_t bgTile = this->getTile(Layer::Background, tileXIdx + 2, tileYIdx, TILE_FLOOR_BASIC);
                                    #endif

                                    int8_t fgTile = this->getTile(Layer::Foreground, tileXIdx + 2, tileYIdx, TILE_FLOOR_BASIC);

                                    WallTileResults wallTile = this->isWallTile(fgTile, tileXIdx + 2, tileYIdx, Direction::Right);

                                    #if defined(DEBUG) && defined(DEBUG_ACTION_CANRUNNINGJUMP)
                                    // printTileInfo(bgTile3, fgTile3);
                                    // DEBUG_PRINT("isWallTile(");
                                    // DEBUG_PRINT(bgTile);
                                    // DEBUG_PRINT(",");
                                    // DEBUG_PRINT(fgTile);
                                    // DEBUG_PRINT(",");
                                    // DEBUG_PRINT(tileXIdx + 2);
                                    // DEBUG_PRINT(",");
                                    // DEBUG_PRINT(tileYIdx);
                                    // DEBUG_PRINT(") = ");
                                    // DEBUG_PRINTLN((uint8_t)wallTile);
                                    #endif

                                    return (wallTile == WallTileResults::None ? RunningJumpResult::Normal : RunningJumpResult::None);

                                }

                                return RunningJumpResult::Normal;

                            case Action::RunJump_1:
                                {
                                    #if defined(DEBUG) && defined(DEBUG_ACTION_CANRUNNINGJUMP)
                                    int8_t bgTile = this->getTile(Layer::Background, tileXIdx + 1, tileYIdx, TILE_FLOOR_BASIC);
                                    #endif

                                    int8_t fgTile = this->getTile(Layer::Foreground, tileXIdx + 1, tileYIdx, TILE_FLOOR_BASIC);

                                    WallTileResults wallTile = this->isWallTile(fgTile, tileXIdx + 1, tileYIdx, Direction::Right);
                                        
                                    #if defined(DEBUG) && defined(DEBUG_ACTION_CANRUNNINGJUMP)
                                    // printTileInfo(bgTile2, fgTile2);
                                    // DEBUG_PRINT("isWallTile(");
                                    // DEBUG_PRINT(bgTile);
                                    // DEBUG_PRINT(",");
                                    // DEBUG_PRINT(fgTile);
                                    // DEBUG_PRINT(",");
                                    // DEBUG_PRINT(tileXIdx + 1);
                                    // DEBUG_PRINT(",");
                                    // DEBUG_PRINT(tileYIdx);
                                    // DEBUG_PRINT(") = ");
                                    // DEBUG_PRINTLN((uint8_t)wallTile);
                                    #endif

                                    return (wallTile == WallTileResults::None ? RunningJumpResult::Normal : RunningJumpResult::None);

                                }

                                return RunningJumpResult::Normal;

                            default: return RunningJumpResult::None;

                        }

                    }

                    break;

                default: break;

            }

            return RunningJumpResult::Normal;

        }

        StandingJumpResult canStandingJump(Prince &prince) {

            int8_t tileXIdx = this->coordToTileIndexX(prince.getPosition().x) - this->getXLocation();
            int8_t tileYIdx = this->coordToTileIndexY(prince.getPosition().y) - this->getYLocation();
            int8_t distToEdgeOfCurrentTile = distToEdgeOfTile(prince.getDirection(), prince.getPosition().x);

            #if defined(DEBUG) && defined(DEBUG_ACTION_CANSTANDINGJUMP)
            DEBUG_PRINTLN(F("------------------------------"));
            DEBUG_PRINT(F("StandingJump coordToTileIndexX "));
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
                        int8_t bgTile4_NextLvl = this->getTile(Layer::Background, tileXIdx - 3, tileYIdx + 1, TILE_FLOOR_BASIC);
                        int8_t fgTile4_NextLvl = this->getTile(Layer::Foreground, tileXIdx - 3, tileYIdx + 1, TILE_FLOOR_BASIC);
                        int8_t bgTile3_NextLvl = this->getTile(Layer::Background, tileXIdx - 2, tileYIdx + 1, TILE_FLOOR_BASIC);
                        int8_t fgTile3_NextLvl = this->getTile(Layer::Foreground, tileXIdx - 2, tileYIdx + 1, TILE_FLOOR_BASIC);
                        int8_t bgTile2_NextLvl = this->getTile(Layer::Background, tileXIdx - 1, tileYIdx + 1, TILE_FLOOR_BASIC);
                        int8_t fgTile2_NextLvl = this->getTile(Layer::Foreground, tileXIdx - 1, tileYIdx + 1, TILE_FLOOR_BASIC);

                        int8_t bgTile4_CurrLvl = this->getTile(Layer::Background, tileXIdx - 3, tileYIdx, TILE_FLOOR_BASIC);
                        int8_t fgTile4_CurrLvl = this->getTile(Layer::Foreground, tileXIdx - 3, tileYIdx, TILE_FLOOR_BASIC);
                        int8_t bgTile3_CurrLvl = this->getTile(Layer::Background, tileXIdx - 2, tileYIdx, TILE_FLOOR_BASIC);
                        int8_t fgTile3_CurrLvl = this->getTile(Layer::Foreground, tileXIdx - 2, tileYIdx, TILE_FLOOR_BASIC);
                        int8_t bgTile2_CurrLvl = this->getTile(Layer::Background, tileXIdx - 1, tileYIdx, TILE_FLOOR_BASIC);
                        int8_t fgTile2_CurrLvl = this->getTile(Layer::Foreground, tileXIdx - 1, tileYIdx, TILE_FLOOR_BASIC);
                        int8_t fgTile1_CurrLvl = this->getTile(Layer::Foreground, tileXIdx, tileYIdx, TILE_FLOOR_BASIC);

                        WallTileResults wallTile1_CurrLvl = this->isWallTile(fgTile1_CurrLvl, tileXIdx, tileYIdx, Direction::Left);
                        WallTileResults wallTile2_CurrLvl = this->isWallTile(fgTile2_CurrLvl, tileXIdx - 1, tileYIdx, Direction::Left);
                        WallTileResults wallTile3_CurrLvl = this->isWallTile(fgTile3_CurrLvl, tileXIdx - 2, tileYIdx, Direction::Left);
                        WallTileResults wallTile4_CurrLvl = this->isWallTile(fgTile4_CurrLvl, tileXIdx - 3, tileYIdx, Direction::Left);
                        WallTileResults wallTile2_NextLvl = this->isWallTile(fgTile2_NextLvl, tileXIdx - 1, tileYIdx, Direction::Left);
                        WallTileResults wallTile3_NextLvl = this->isWallTile(fgTile3_NextLvl, tileXIdx - 2, tileYIdx, Direction::Left);
                        WallTileResults wallTile4_NextLvl = this->isWallTile(fgTile4_NextLvl, tileXIdx - 3, tileYIdx, Direction::Left);

// Serial.print((uint8_t)wallTile4_CurrLvl);
// Serial.print(" ");
// Serial.print((uint8_t)wallTile3_CurrLvl);
// Serial.print(" ");
// Serial.print((uint8_t)wallTile2_CurrLvl);
// Serial.print(" ");
// Serial.print((uint8_t)wallTile1_CurrLvl);
// Serial.println(" ");
// Serial.print((uint8_t)wallTile4_NextLvl);
// Serial.print(" ");
// Serial.print((uint8_t)wallTile3_NextLvl);
// Serial.print(" ");
// Serial.print((uint8_t)wallTile2_NextLvl);
// Serial.println(" 0");
// Serial.print("Dist ");
// Serial.println(distToEdgeOfCurrentTile);
   
                        // WallTileResults, 0 None, 1 Normal, 2 GateClosed
                   
                        bool isGroundTile2_CurrLvl = this->isGroundTile(bgTile2_CurrLvl, fgTile2_CurrLvl);
                        bool isGroundTile3_CurrLvl = this->isGroundTile(bgTile3_CurrLvl, fgTile3_CurrLvl);
                        bool isGroundTile2_NextLvl = this->isGroundTile(bgTile2_NextLvl, fgTile2_NextLvl);
                        bool isGroundTile3_NextLvl = this->isGroundTile(bgTile3_NextLvl, fgTile3_NextLvl);
                        bool isGroundTile4_NextLvl = this->isGroundTile(bgTile4_NextLvl, fgTile4_NextLvl);

                        if (wallTile1_CurrLvl == WallTileResults::None && 
                            wallTile2_CurrLvl == WallTileResults::None && 
                            wallTile3_CurrLvl == WallTileResults::None && 
                            wallTile2_NextLvl == WallTileResults::None && 
                            wallTile3_NextLvl == WallTileResults::None && 
                            wallTile4_NextLvl == WallTileResults::None && 
                            !isGroundTile2_CurrLvl &&
                            !isGroundTile3_CurrLvl &&
                            !isGroundTile2_NextLvl &&
                            !isGroundTile3_NextLvl &&
                            isGroundTile4_NextLvl) {

                                switch (distToEdgeOfCurrentTile) {

                                    case 6:
                                    case 10:
// Serial.println("dl");                                    
                                        return StandingJumpResult::DropLevel;

                                    default:
// Serial.println("default");                                    
                                        return (wallTile1_CurrLvl == WallTileResults::None && wallTile2_CurrLvl == WallTileResults::None ? StandingJumpResult::Normal : StandingJumpResult::None);
                                    
                                }

                        }
                        else {
// Serial.println("else");                                    
                           
                            if (wallTile1_CurrLvl == WallTileResults::None && wallTile2_CurrLvl == WallTileResults::None) {

                                switch (wallTile3_CurrLvl) {

                                    case WallTileResults::None:

                                        if (wallTile4_CurrLvl != WallTileResults::None) {

                                            switch (distToEdgeOfCurrentTile) {
                                                
                                                case 2:
// Serial.println("Short");                                    
                                                    return StandingJumpResult::Short;
                                                
                                                case 6:
                                                case 10:
// Serial.println("Short");                                    
                                                    return StandingJumpResult::Medium;

                                                default:
// Serial.println("Normal"); 
                                                    return StandingJumpResult::Normal;

                                            }

                                        }

// Serial.println("Normal");                                    
                                        return StandingJumpResult::Normal;

                                    case WallTileResults::SolidWall:
                                    case WallTileResults::GateClosed:
// Serial.println("Short");                                    
                                        return StandingJumpResult::Short;

                                }

                            }
                            else {

// Serial.println("None");                                    
                                return StandingJumpResult::None;

                            }
                             
                        }

                    }

                    break;

                case Direction::Right:
                    {
                        int8_t bgTile4_NextLvl = this->getTile(Layer::Background, tileXIdx + 3, tileYIdx + 1, TILE_FLOOR_BASIC);
                        int8_t fgTile4_NextLvl = this->getTile(Layer::Foreground, tileXIdx + 3, tileYIdx + 1, TILE_FLOOR_BASIC);
                        int8_t bgTile3_NextLvl = this->getTile(Layer::Background, tileXIdx + 2, tileYIdx + 1, TILE_FLOOR_BASIC);
                        int8_t fgTile3_NextLvl = this->getTile(Layer::Foreground, tileXIdx + 2, tileYIdx + 1, TILE_FLOOR_BASIC);
                        int8_t bgTile2_NextLvl = this->getTile(Layer::Background, tileXIdx + 1, tileYIdx + 1, TILE_FLOOR_BASIC);
                        int8_t fgTile2_NextLvl = this->getTile(Layer::Foreground, tileXIdx + 1, tileYIdx + 1, TILE_FLOOR_BASIC);

                        int8_t bgTile3_CurrLvl = this->getTile(Layer::Background, tileXIdx + 2, tileYIdx, TILE_FLOOR_BASIC);
                        int8_t fgTile3_CurrLvl = this->getTile(Layer::Foreground, tileXIdx + 2, tileYIdx, TILE_FLOOR_BASIC);
                        int8_t bgTile2_CurrLvl = this->getTile(Layer::Background, tileXIdx + 1, tileYIdx, TILE_FLOOR_BASIC);
                        int8_t fgTile2_CurrLvl = this->getTile(Layer::Foreground, tileXIdx + 1, tileYIdx, TILE_FLOOR_BASIC);
                        int8_t fgTile1_CurrLvl = this->getTile(Layer::Foreground, tileXIdx, tileYIdx, TILE_FLOOR_BASIC);

                        WallTileResults wallTile1_CurrLvl = this->isWallTile(fgTile1_CurrLvl, tileXIdx, tileYIdx, Direction::Right);
                        WallTileResults wallTile2_CurrLvl = this->isWallTile(fgTile2_CurrLvl, tileXIdx + 1, tileYIdx, Direction::Right);
                        WallTileResults wallTile3_CurrLvl = this->isWallTile(fgTile3_CurrLvl, tileXIdx + 2, tileYIdx, Direction::Right);
                        WallTileResults wallTile2_NextLvl = this->isWallTile(fgTile2_NextLvl, tileXIdx + 1, tileYIdx + 1, Direction::Right);
                        WallTileResults wallTile3_NextLvl = this->isWallTile(fgTile3_NextLvl, tileXIdx + 2, tileYIdx + 1, Direction::Right);
                        WallTileResults wallTile4_NextLvl = this->isWallTile(fgTile4_NextLvl, tileXIdx + 3, tileYIdx + 1, Direction::Right);

                        // WallTileResults, 0 None, 1 Normal, 2 GateClosed

                        bool isGroundTile2_CurrLvl = this->isGroundTile(bgTile2_CurrLvl, fgTile2_CurrLvl);
                        bool isGroundTile3_CurrLvl = this->isGroundTile(bgTile3_CurrLvl, fgTile3_CurrLvl);
                        bool isGroundTile2_NextLvl = this->isGroundTile(bgTile2_NextLvl, fgTile2_NextLvl);
                        bool isGroundTile3_NextLvl = this->isGroundTile(bgTile3_NextLvl, fgTile3_NextLvl);
                        bool isGroundTile4_NextLvl = this->isGroundTile(bgTile4_NextLvl, fgTile4_NextLvl);

                        if (wallTile1_CurrLvl == WallTileResults::None && 
                            wallTile2_CurrLvl == WallTileResults::None && 
                            wallTile3_CurrLvl == WallTileResults::None && 
                            wallTile2_NextLvl == WallTileResults::None && 
                            wallTile3_NextLvl == WallTileResults::None && 
                            wallTile4_NextLvl == WallTileResults::None && 
                            !isGroundTile2_CurrLvl &&
                            !isGroundTile3_CurrLvl &&
                            !isGroundTile2_NextLvl &&
                            !isGroundTile3_NextLvl &&
                            isGroundTile4_NextLvl) {

                                switch (distToEdgeOfCurrentTile) {

                                    case 6:
                                    case 10:
                                        return StandingJumpResult::DropLevel;

                                    default:
                                        return (wallTile1_CurrLvl == WallTileResults::None && wallTile2_CurrLvl == WallTileResults::None ? StandingJumpResult::Normal : StandingJumpResult::None);
                                    
                                }

                        }
                        else {

                            if (wallTile1_CurrLvl == WallTileResults::None && wallTile2_CurrLvl == WallTileResults::None) {

                                switch (wallTile3_CurrLvl) {

                                    case WallTileResults::None:
                                    case WallTileResults::SolidWall:
                                        return StandingJumpResult::Normal;

                                    case WallTileResults::GateClosed:
                                        return StandingJumpResult::Short;

                                }

                            }
                            else {

                                return StandingJumpResult::None;

                            }
                            
                        }

                    }
                    break;

                default: break;

            }

            return StandingJumpResult::Normal;

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
                                DEBUG_PRINT(F("L1 Test success, Return "));
                                DEBUG_PRINTLN(static_cast<uint8_t>(resultLeft));
                                #endif
                                                                    
                                return resultLeft;

                            case CanJumpUpResult::JumpThenFall_CollapseFloor:

                                #if defined(DEBUG) && defined(DEBUG_ACTION_CANJUMPUP)
                                DEBUG_PRINTLN(F("L2 Test success, Return JumpThenFall_CollapseFloor"));
                                #endif                            

                                return CanJumpUpResult::JumpThenFall_CollapseFloor;

                            case CanJumpUpResult::JumpThenFall_CollapseFloorAbove:

                                #if defined(DEBUG) && defined(DEBUG_ACTION_CANJUMPUP)
                                DEBUG_PRINTLN(F("L3 Test success, Return JumpThenFall_CollapseFloorAbove"));
                                #endif                            

                                return CanJumpUpResult::JumpThenFall_CollapseFloorAbove;

                            case CanJumpUpResult::StepThenJumpThenFall_CollapseFloor:

                                #if defined(DEBUG) && defined(DEBUG_ACTION_CANJUMPUP)
                                DEBUG_PRINTLN(F("L4 Test success, Return StepThenJumpThenFall_CollapseFloor"));
                                #endif                            

                                return CanJumpUpResult::StepThenJumpThenFall_CollapseFloor;

                            default:
                                {
                                    CanJumpUpResult resultRight = this->canJumpUp_Test(prince, Direction::Right);

                                    switch (resultRight) {

                                        case CanJumpUpResult::Jump:

                                            #if defined(DEBUG) && defined(DEBUG_ACTION_CANJUMPUP)
                                            DEBUG_PRINT(F("R1 Test success, Return TurnThenJump"));
                                            #endif

                                            return CanJumpUpResult::TurnThenJump;

                                        default:

                                            #if defined(DEBUG) && defined(DEBUG_ACTION_CANJUMPUP)
                                            DEBUG_PRINT(F("R2 Test failed, Return "));
                                            DEBUG_PRINTLN(static_cast<uint8_t>(resultLeft));
                                            #endif

                                            CanJumpUpResult result = this->canJumpUp_Test_Dist10(prince, Direction::Left);

                                            #if defined(DEBUG) && defined(DEBUG_ACTION_CANJUMPUP)
                                            DEBUG_PRINT(F("R3 canJumpUp_Test_Dist10 Return "));
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
                                DEBUG_PRINT(F("R1 Test success, Return "));
                                DEBUG_PRINTLN(static_cast<uint8_t>(resultRight));
                                #endif                            

                                return resultRight;

                            case CanJumpUpResult::JumpThenFall_CollapseFloor:

                                #if defined(DEBUG) && defined(DEBUG_ACTION_CANJUMPUP)
                                DEBUG_PRINTLN(F("R2 Test success, Return JumpThenFall_CollapseFloor"));
                                #endif                            

                                return CanJumpUpResult::JumpThenFall_CollapseFloor;

                            case CanJumpUpResult::JumpThenFall_CollapseFloorAbove:

                                #if defined(DEBUG) && defined(DEBUG_ACTION_CANJUMPUP)
                                DEBUG_PRINTLN(F("R3 Test success, Return JumpThenFall_CollapseFloorAbove"));
                                #endif                            

                                return CanJumpUpResult::JumpThenFall_CollapseFloorAbove;

                            case CanJumpUpResult::StepThenJumpThenFall_CollapseFloor:

                                #if defined(DEBUG) && defined(DEBUG_ACTION_CANJUMPUP)
                                DEBUG_PRINTLN(F("R4 Test success, Return StepThenJumpThenFall_CollapseFloor"));
                                #endif                            

                                return CanJumpUpResult::StepThenJumpThenFall_CollapseFloor;

                            default:
                                {
                                    CanJumpUpResult resultLeft = this->canJumpUp_Test(prince, Direction::Left);

                                    switch (resultLeft) {

                                        case CanJumpUpResult::Jump:

                                            #if defined(DEBUG) && defined(DEBUG_ACTION_CANJUMPUP)
                                            DEBUG_PRINT(F("L1 Test success, Return TurnThenJump"));
                                            #endif     

                                            return CanJumpUpResult::TurnThenJump;

                                        default:

                                            #if defined(DEBUG) && defined(DEBUG_ACTION_CANJUMPUP)
                                            DEBUG_PRINT(F("L2 Test failed, Return "));
                                            DEBUG_PRINTLN(static_cast<uint8_t>(resultRight));
                                            #endif     

                                            CanJumpUpResult result = this->canJumpUp_Test_Dist10(prince, Direction::Right);
                                            
                                            #if defined(DEBUG) && defined(DEBUG_ACTION_CANJUMPUP)
                                            DEBUG_PRINT(F("L3 canJumpUp_Test_Dist10 Return "));
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
            int8_t tileXIdx = this->coordToTileIndexX(prince.getPosition().x) - this->getXLocation();
            int8_t tileYIdx = this->coordToTileIndexY(prince.getPosition().y) - this->getYLocation();

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
                                case TILE_FLOOR_RH_END_GATE_1:
                                case TILE_FLOOR_RH_END_GATE_2:
                                case TILE_FLOOR_RH_END_GATE_RUG:
                                case TILE_COLUMN_LH_WALL:
                                case TILE_FLOOR_RH_PILLAR_END:

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
                                case TILE_FLOOR_RH_END_GATE_1:
                                case TILE_FLOOR_RH_END_GATE_2:
                                case TILE_FLOOR_RH_END_GATE_RUG:
                                case TILE_FLOOR_RH_PILLAR_END:
                                // case TILE_COLUMN_LH_WALL:                << SJH removed 29/12

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
                                case TILE_PILLAR_2:

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
                                case TILE_PILLAR_2:

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

            int8_t tileXIdx = this->coordToTileIndexX(prince.getPosition().x) - this->getXLocation();
            int8_t tileYIdx = this->coordToTileIndexY(prince.getPosition().y) - this->getYLocation();

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
                                case TILE_FLOOR_RH_END_GATE_1:
                                case TILE_FLOOR_RH_END_GATE_2:
                                case TILE_FLOOR_RH_END_GATE_RUG:
                                case TILE_COLUMN_LH_WALL:
                                case TILE_FLOOR_RH_PILLAR_END:
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
                                case TILE_PILLAR_2:
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

                        tileXIdx = this->coordToTileIndexX(prince.getPosition().x) - this->getXLocation();
                        tileYIdx = this->coordToTileIndexY(prince.getPosition().y) - this->getYLocation() - 1;

                        #if defined(DEBUG) && defined(DEBUG_ACTION_CANJUMPUP_PART2)
                        printCoordToIndex(prince.getPosition(), tileXIdx, tileYIdx);
                        #endif

                    }

                    break;

                case Direction::Right:
                    {

                        tileXIdx = this->coordToTileIndexX(prince.getPosition().x) - this->getXLocation() + 1;
                        tileYIdx = this->coordToTileIndexY(prince.getPosition().y) - this->getYLocation() - 1;

                        #if defined(DEBUG) && defined(DEBUG_ACTION_CANJUMPUP_PART2)
                        printCoordToIndex(prince.getPosition(), tileXIdx, tileYIdx);
                        #endif

                    }

                    break;

                default: break;

            }



            // Look for closed gate in the same cell as possible ledge ..

            uint8_t gatePosition = 255;

            for (uint8_t i = 0; i < Constants::Items_Count; i++) {

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
// enum class CanClimbDownResult : uint8_t {
//   0  None,
//   1  ClimbDown,
//   2  StepThenClimbDown,
//   3  TurnThenClimbDown,
//   4  StepThenTurnThenClimbDown,
// };
            switch (prince.getDirection()) {

                case Direction::Left:
                    {
                        CanClimbDownResult resultRight = canClimbDown_Test(prince, Direction::Right);

                        switch (resultRight) {

                            case CanClimbDownResult::ClimbDown:
                            case CanClimbDownResult::StepThenClimbDown:

                                #if defined(DEBUG) && defined(DEBUG_ACTION_CANCLIMBDOWN)
                                DEBUG_PRINT(F("L1 Return: "));
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
                                            DEBUG_PRINTLN(F("L2 Return: TurnThenClimbDown"));
                                            #endif

                                            return CanClimbDownResult::TurnThenClimbDown;
                                            break;

                                        case CanClimbDownResult::StepThenClimbDown:

                                            #if defined(DEBUG) && defined(DEBUG_ACTION_CANCLIMBDOWN)
                                            DEBUG_PRINTLN(F("L3 Return: StepThenTurnThenClimbDown"));
                                            #endif

                                            return CanClimbDownResult::StepThenTurnThenClimbDown;
                                            break;

                                        default:

                                            #if defined(DEBUG) && defined(DEBUG_ACTION_CANCLIMBDOWN)
                                            DEBUG_PRINT(F("L4 Return: "));
                                            DEBUG_PRINTLN(static_cast<uint8_t>(resultRight));
                                            #endif
                                            
                                            return resultRight;
                                            break;

                                    }

                                }
                                        
                                #if defined(DEBUG) && defined(DEBUG_ACTION_CANCLIMBDOWN)
                                DEBUG_PRINTLN(F("L5 Return: None"));
                                #endif

                                return CanClimbDownResult::None;
                                break;

                        }
                        
                    }

                    #if defined(DEBUG) && defined(DEBUG_ACTION_CANCLIMBDOWN)
                    DEBUG_PRINTLN(F("L6 Return: None"));
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
                                DEBUG_PRINT(F("R1 Return: "));
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
                                            DEBUG_PRINTLN(F("R2 Return: TurnThenClimbDown"));
                                            #endif

                                            return CanClimbDownResult::TurnThenClimbDown;
                                            break;

                                        case CanClimbDownResult::StepThenClimbDown:

                                            #if defined(DEBUG) && defined(DEBUG_ACTION_CANCLIMBDOWN)
                                            DEBUG_PRINTLN(F("R3 Return: StepThenTurnThenClimbDown"));
                                            #endif

                                            return CanClimbDownResult::StepThenTurnThenClimbDown;
                                            break;

                                        default:

                                            #if defined(DEBUG) && defined(DEBUG_ACTION_CANCLIMBDOWN)
                                            DEBUG_PRINT(F("R4 Return: "));
                                            DEBUG_PRINTLN(static_cast<uint8_t>(resultLeft));
                                            #endif
                                            
                                            return resultLeft;
                                            break;

                                    }

                                }
                                
                                #if defined(DEBUG) && defined(DEBUG_ACTION_CANCLIMBDOWN)
                                DEBUG_PRINTLN(F("R5 Return: None"));
                                #endif

                                return CanClimbDownResult::None;
                                break;

                        }
                        
                    }

                    #if defined(DEBUG) && defined(DEBUG_ACTION_CANCLIMBDOWN)
                    DEBUG_PRINTLN(F("R^ Return: None"));
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

            return CanClimbDownResult::None;
            
        }

        CanClimbDownResult canClimbDown_Test(Prince &prince, Direction direction) {

            int8_t tileXIdx = this->coordToTileIndexX(prince.getPosition().x) - this->getXLocation() + (direction == Direction::Right ? 1 : 0);
            int8_t tileYIdx = this->coordToTileIndexY(prince.getPosition().y) - this->getYLocation();

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
                                case TILE_PILLAR_2:
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
                                case TILE_PILLAR_2:
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
                                case TILE_FLOOR_RH_END_GATE_1:
                                case TILE_FLOOR_RH_END_GATE_2:
                                case TILE_FLOOR_RH_END_GATE_RUG:
                                case TILE_FLOOR_RH_PILLAR_END:
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
                                case TILE_FLOOR_RH_END_GATE_1:
                                case TILE_FLOOR_RH_END_GATE_2:
                                case TILE_FLOOR_RH_END_GATE_RUG:
                                case TILE_FLOOR_RH_PILLAR_END:
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

            ImageDetails imageDetails;
            // Direction direction = prince.getDirection();
            prince.getImageDetails(imageDetails);

            #if defined(DEBUG) && defined(DEBUG_ACTION_COLLIDEWITHWALL)
            DEBUG_PRINT("collideWithWall() Stance: ");
            DEBUG_PRINT(prince.getStance());
            DEBUG_PRINT(", reach: ");
            DEBUG_PRINTLN(imageDetails.reach);
            #endif

            int8_t tileXIdx = this->coordToTileIndexX(prince.getPosition(imageDetails.reach).x) - this->getXLocation();// + (direction == Direction::Right ? 1 : 0);
            int8_t tileYIdx = this->coordToTileIndexY(prince.getPosition().y) - this->getYLocation();

            #if defined(DEBUG) && defined(DEBUG_ACTION_COLLIDEWITHWALL)
            printCoordToIndex(prince.getPosition(), tileXIdx, tileYIdx);
            #endif

            int8_t fgTile = this->getTile(Layer::Foreground, tileXIdx, tileYIdx, TILE_FLOOR_BASIC);

            #if defined(DEBUG) && defined(DEBUG_ACTION_COLLIDEWITHWALL)
            int8_t bgTile = this->getTile(Layer::Background, tileXIdx, tileYIdx, TILE_FLOOR_BASIC);
            DEBUG_PRINT(F(", direction "));
            if(prince.getDirection() == Direction::Left) {
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
            DEBUG_PRINT((uint8_t)isWallTile(fgTile));
            DEBUG_PRINTLN("");
            #endif

            return (isWallTile(fgTile) != WallTileResults::None);

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
            DEBUG_PRINT((uint8_t)this->isWallTile(fgTile));
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
