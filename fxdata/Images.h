#pragma once

#include "fxdata.h"

namespace Images {

    const uint8_t StanceToImageXRef[] PROGMEM  = {
        /* STANCE_NONE */                       0,                        
        /* STANCE_RUN_START */                  1, 2, 3, 4, 5, 6, 
        /* STANCE_RUN_REPEAT */                 7, 8, 9, 10, 11, 12, 13, 14,
        /* STANCE_UPRIGHT */                    15,
        /* STANCE_RUNNING_JUMP */               16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26,
        /* STANCE_STANDING_TURN */              27, 28, 29, 30, 31,
        /* STANCE_RUNNING_TURN */               32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44,
        /* STANCE_STANDING_JUMP */              45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62,
        /* STANCE_STEP_FWD_ONE */               63, 64, 65, 66, 67, 68,
        /* STANCE_STEP_FWD_TWO */               69, 70, 71, 72, 73, 74,
        /* STANCE_SINGLE_STEP */                63, 64, 65, 66, 71, 72, 73, 74,
        /* STANCE_STOPPING */                   5, 4, 3, 2, 1,

        /* STANCE_CLIMBING */                   75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89,                     
        /* STANCE_SMALL_STEP */                 63, 64, 65, 72, 73, 74,                                                         
        /* STANCE_JUMP_UP_A */                  90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103,                     
        /* STANCE_JUMP_DROP_A */                104, 105, 106, 107, 108,   // Drop to position 2                                
        /* STANCE_STEP_CLIMBING */              75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89,                     
        /* STANCE_CROUCH_STAND */               109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120,                     
        /* STANCE_FALLING_A */                  121, 122, 123, 124, 125, 126,   // Used when walking.                           
        /* STANCE_FALLING_B */                  121, 122, 123, 124, 125, 126,   // Used when walking.                           
        /* STANCE_FALLING_C */                  121, 122, 123, 124, 125, 126,   // Used when walking.                                   
        /* STANCE_CROUCHING */                  126, 109, 110,                                                                  
        /* STANCE_CROUCH_HOP */                 110, 111, 112, 113, 112, 111, 110,                                              
        /* STANCE_STEP_CLIMBING_BLOCK */        75, 76, 77, 78, 79, 78, 77, 76, 75,                                             
        /* STANCE_JUMP_UP_B */                  90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103,                     
        /* STANCE_JUMP_DROP_B */                104, 105, 106, 107, 108,   // Drop to position 10                               
        /* STANCE_DRINK_TONIC */                127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141,      
        /* STANCE_JUMP_DROP_C */                104, 105, 106, 107, 108,   // Climb down, drop straight down 31 px              
        /* STANCE_FALLING_D */                  125, 126,   // climb down, drop a level (and crouch)                            
        /* STANCE_FALLING_DEAD */               125, 126, 142,   // climb down, drop a level (and crouch)                       
    };


    constexpr uint24_t PPOT[] = { 
        PPOT_00,
        PPOT_01,
        PPOT_02,
        PPOT_03,
    };

    constexpr uint24_t Tile_Dungeon[] = { 
        Tile_Dungeon_00,
        Tile_Dungeon_01,
        Tile_Dungeon_02,
        Tile_Dungeon_03,
        Tile_Dungeon_04,
        Tile_Dungeon_05,
        Tile_Dungeon_06,
        Tile_Dungeon_07,
        Tile_Dungeon_08,
        Tile_Dungeon_09,
        Tile_Dungeon_10,
        Tile_Dungeon_11,
        Tile_Dungeon_12,
        Tile_Dungeon_13,
        Tile_Dungeon_14,
        Tile_Dungeon_15,
        Tile_Dungeon_16,
        Tile_Dungeon_17,
        Tile_Dungeon_18,
        Tile_Dungeon_19,
        Tile_Dungeon_20,
        Tile_Dungeon_21,
        Tile_Dungeon_22,
        Tile_Dungeon_23,
        Tile_Dungeon_24,
        Tile_Dungeon_25,
        Tile_Dungeon_26,
        Tile_Dungeon_27,
        Tile_Dungeon_28,
        Tile_Dungeon_29,
        Tile_Dungeon_30,
        Tile_Dungeon_31,
        Tile_Dungeon_32,
        Tile_Dungeon_33,
        Tile_Dungeon_34,
        Tile_Dungeon_35,
        Tile_Dungeon_36,
        Tile_Dungeon_37,
        Tile_Dungeon_38,
        Tile_Dungeon_39,
        Tile_Dungeon_40,
        Tile_Dungeon_41,
        Tile_Dungeon_42,
        Tile_Dungeon_43,
        Tile_Dungeon_44,
        Tile_Dungeon_45,
        Tile_Dungeon_46,
        Tile_Dungeon_47,
        Tile_Dungeon_48,
        Tile_Dungeon_49,
    };







































    uint8_t xTiles_Ref[] = {
0,
1,
2,
3,
4,
5,
6,
7,
8,
9,
10,
11,
12,
13,
14,
15,
16,
17,
18,
19,
20,
21,
22,
23,
24,
25,
26,
27,
28,
29,
30,
31,
32,
33,
34,
35,
36,
37,
38,
39,
40,
41,
42,
43,
44,
45,
46,
47,
48,
49,
50,
51,
52,
53,
54,
55,
56,
57,
58,
59,
60,
61,
62,
63,
64,
65,
66,
67,
68,
69,
70,
71,
72,
73,
0, // 74,
1, // 75,
2, // 76,
3, // 77,
4, // 78,
5, // 79,
6, // 80,
7, // 81,
8, // 82,
9, // 83,
10, // 84,
11, // 85,
12, // 86,
13, // 87,
14, // 88,
15, // 89,
16, // 90,
17, // 91,
18, // 92,
19, // 93,
20, // 94,
21, // 95,
22, // 96,
23, // 97,
24, // 98,
25, // 99,
26, // 100,
27, // 101,
28, // 102,
29, // 103,
30, // 104,
31, // 105,
32, // 106,
33, // 107,
34, // 108,
35, // 109,
36, // 110,
37, // 111,
38, // 112,
39, // 113,
40, // 114,
41, // 115,
42, // 116,
43, // 117,
44, // 118,
45, // 119,
46, // 120,
47, // 121,
48, // 122,
49, // 123,
124,
125,
126,
127,
128,
129,
130,


};

































































    uint8_t xTilesRef_IsMasked[] = {
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
false,
true,
true,
true,
true,
false,
true,
false,
false,
false,
false,
false,
true,
true,
false,
false,
false,
false,
false,
true,
false,
false,
false,
false,
false,
false,
false,

};




};