#pragma once

#include <Arduboy2.h>   
#include "../utils/Constants.h"
#include "../utils/Stack.h"
 
struct ExitDoor {
    uint8_t position;
    Direction direction;
    uint8_t left;
    uint8_t right;
};

struct Blade {
    uint8_t position;
    Direction direction;
    uint8_t left;
    uint8_t right;
};

struct Gate {
    uint8_t position;
    uint8_t closingDelay;
    uint8_t closingDelayMax;
};
 
struct Sword {
};

struct Skeleton {
};

struct Spikes {
    uint8_t position;
    uint8_t openningDelay;
    uint8_t closingDelay;
    uint8_t imageType;
};
 
struct CollapsingFloor {
    uint8_t frame;
    uint8_t distToFall;
    uint8_t distanceFallen;     // 255 not falling. Or 0 to distToFall when falling.  Turns into a CollapsedFloor when fallen.
    uint8_t timeToFall;         // 255 if not counting down.
};
 
struct FloorButton1 {
    uint8_t frame;              
    uint8_t gateX;
    uint8_t gateY;              
    uint8_t timeToFall;         // How long does gate remain open for.
};
 
struct FloorButton2 {
    uint8_t frame;              
    uint8_t gateX;
    uint8_t gateY;              
    uint8_t timeToFall;         // How long does gate remain open for.
};
 
struct Potion {
    uint8_t frame;
};

struct LoveHeart {
    uint8_t counter;
};

struct Item {

    ItemType itemType;
    uint8_t x;
    uint8_t y;

    union {
        struct LoveHeart loveHeart;
        struct Gate gate;
        struct ExitDoor exitDoor;
        struct Sword sword;
        struct Sword skeleton;
        struct CollapsingFloor collapsingFloor;
        struct Potion potion;
        struct FloorButton1 floorButton1;
        struct FloorButton1 floorButton2;
        struct Spikes spikes;
    } data; 
 
};
