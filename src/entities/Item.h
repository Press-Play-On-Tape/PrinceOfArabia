#pragma once

#include <Arduboy2.h>   
#include "../utils/Constants.h"
#include "../utils/Stack.h"

struct Flash {
    uint8_t frame;
};
 
struct Door {
};

struct Gate {
    uint8_t position;
    uint8_t closingDelay;
    uint8_t closingDelayMax;
};
 
struct Sword {
    bool onGround;
};
 
// struct Torch {
//     uint8_t frame;
// };
 
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
 
struct CollapsedFloor {
};
 
struct PotionSmall {
    uint8_t frame;
};

struct Item {

    ItemType itemType;
    uint8_t x;
    uint8_t y;
    bool active;

    union {
        struct Flash flash;
        struct Gate gate;
        struct Door door;
        struct Sword sword;
        struct CollapsingFloor collapsingFloor;
        struct CollapsedFloor collapsedFloor;
        struct PotionSmall potionSmall;
        struct FloorButton1 floorButton1;
        struct FloorButton1 floorButton2;
    } data; 
 
};
