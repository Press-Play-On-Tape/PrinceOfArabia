#pragma once

#include <Arduboy2.h>   
#include "../utils/Constants.h"
#include "../utils/Stack.h"

struct Gate {
    uint8_t position;
    uint8_t closingDelay;
};
 
struct Door {
    uint8_t position;
};
 
struct Sword {
    bool onGround;
};
 
struct Torch {
    uint8_t frame;
};

struct Item {

    ItemType itemType; // set accordingly
    uint8_t x;
    uint8_t y;
    bool active;

    union {
        struct Gate gate;
        struct Door door;
        struct Sword sword;
        struct Torch torch;
    } data; // access with some_info_object.data.a or some_info_object.data.b
 
};
