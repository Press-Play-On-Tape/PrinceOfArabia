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

struct AppearingFloor {
    bool visible;
};

struct ExitDoor_Button {
    uint8_t frame;              
};

struct Blade {
    int8_t position;
};

struct Gate {
    uint8_t position;
    uint8_t closingDelay;
    uint8_t closingDelayMax;
    Direction direction;
    uint8_t defaultClosingDelay;
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
 
struct FloorButton {
    uint8_t frame;              
    uint8_t gate1;
    uint8_t gate2;              
    uint8_t gate3;              
    uint8_t timeToFall;         // How long does gate remain open for.
};
 
struct Potion {
    uint8_t frame;
};

struct LoveHeart {
    uint8_t counter;
};

struct Mirror {
    Status status;
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
        struct FloorButton floorButton;
        struct Spikes spikes;
        struct Blade blade;
        struct ExitDoor_Button exitDoor_Button;
        struct Mirror mirror;
        struct AppearingFloor appearingFloor;
    } data; 
 
};
