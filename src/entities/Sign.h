#pragma once

#include <Arduboy2.h>   
#include "../utils/Constants.h"
#include "../utils/Enums.h"

struct Sign {
    SignType type;
    uint8_t counter;
    uint8_t x;
    uint8_t y;
};
 