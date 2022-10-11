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
        /* STANCE_SINGLE_STEP */                75, 76, 77, 78, 79, 80, 81, 82,
        /* STANCE_STOPPING */                   83, 84, 85, 86, 87,
        /* STANCE_CLIMBING */                   88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 
        /* STANCE_SMALL_STEP */                 103, 104, 105, 106, 107, 108,
        /* STANCE_JUMP_UP_A */                  109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122,
        /* STANCE_JUMP_DROP */                  123, 124, 125, 126, 127, 
        /* STANCE_STEP_CLIMBING */              128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 
        /* STANCE_CROUCH_STAND */               143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154,
        /* STANCE_FALLING_A */                  155, 156, 157, 158, 159, 160,   // Used when walking.
        /* STANCE_FALLING_B */                  155, 156, 157, 158, 159, 160,   // Used when walking.
        /* STANCE_FALLING_C */                  155, 156, 157, 158, 159, 160,   // Used when walking.
        /* STANCE_CROUCHING */                  160, 143, 144,
        /* STANCE_CROUCH_HOP */                 144, 145, 146, 147, 146, 145, 144,
        /* STANCE_STEP_CLIMBING_BLOCK */        128, 129, 130, 131, 132, 131, 130, 129, 128,
        /* STANCE_JUMP_UP_B */                  109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122,
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







































    uint8_t xRef[] = {
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

































































    uint8_t xRef_IsMasked[] = {
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







    // constexpr uint24_t Prince[] = { 

    //     Prince_Left_01, // Junk entry
    //     Prince_Left_01,
    //     Prince_Left_02,
    //     Prince_Left_03,
    //     Prince_Left_04,
    //     Prince_Left_05,
    //     Prince_Left_06,
    //     Prince_Left_07,
    //     Prince_Left_08,
    //     Prince_Left_09,
    //     Prince_Left_10,
    //     Prince_Left_11,
    //     Prince_Left_12,
    //     Prince_Left_13,
    //     Prince_Left_14,
    //     Prince_Left_15,
    //     Prince_Left_16,
    //     Prince_Left_17,
    //     Prince_Left_18,
    //     Prince_Left_19,
    //     Prince_Left_20,
    //     Prince_Left_21,
    //     Prince_Left_22,
    //     Prince_Left_23,
    //     Prince_Left_24,
    //     Prince_Left_25,
    //     Prince_Left_26,
    //     Prince_Left_27,
    //     Prince_Left_28,
    //     Prince_Left_29,
    //     Prince_Left_30,
    //     Prince_Left_31,
    //     Prince_Left_32,
    //     Prince_Left_33,
    //     Prince_Left_34,
    //     Prince_Left_35,
    //     Prince_Left_36,
    //     Prince_Left_37,
    //     Prince_Left_38,
    //     Prince_Left_39,
    //     Prince_Left_40,
    //     Prince_Left_41,
    //     Prince_Left_42,
    //     Prince_Left_43,
    //     Prince_Left_44,
    //     Prince_Left_45,
    //     Prince_Left_46,
    //     Prince_Left_47,
    //     Prince_Left_48,
    //     Prince_Left_49,
    //     Prince_Left_50,
    //     Prince_Left_51,
    //     Prince_Left_52,
    //     Prince_Left_53,
    //     Prince_Left_54,
    //     Prince_Left_55,
    //     Prince_Left_56,
    //     Prince_Left_57,
    //     Prince_Left_58,
    //     Prince_Left_59,
    //     Prince_Left_60,
    //     Prince_Left_61,
    //     Prince_Left_62,
    //     Prince_Left_63,
    //     Prince_Left_64,
    //     Prince_Left_65,
    //     Prince_Left_66,
    //     Prince_Left_67,
    //     Prince_Left_68,
    //     Prince_Left_69,
    //     Prince_Left_70,
    //     Prince_Left_71,
    //     Prince_Left_72,
    //     Prince_Left_73,
    //     Prince_Left_74,
    //     Prince_Left_75,
    //     Prince_Left_76,
    //     Prince_Left_77,
    //     Prince_Left_78,
    //     Prince_Left_79,
    //     Prince_Left_80,
    //     Prince_Left_81,
    //     Prince_Left_82,
    //     Prince_Left_83,
    //     Prince_Left_84,
    //     Prince_Left_85,
    //     Prince_Left_86,
    //     Prince_Left_87,
    //     Prince_Left_88,
    //     Prince_Left_89,

    // };


};