#pragma once

#include "fxdata.h"

namespace Images {

    const uint8_t StanceToImageXRef[] PROGMEM  = {
        /* 000 - 000 None */                       0,                        
        /* 001 - 006 Run_Start */                  1, 2, 3, 4, 5, 6, 
        /* 007 - 014 Run_Repeat */                 7, 8, 9, 10, 11, 12, 13, 14,
        /* 015 - 015 Upright */                    15,
        /* 016 - 026 Running_Jump */               16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26,
        /* 027 - 031 Standing_Turn */              27, 28, 29, 30, 31,
        /* 032 - 044 Running_Turn */               32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44,
        /* 045 - 062 Standing_Jump */              45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62,
        /* 063 - 068 Step_Fwd_One */               63, 64, 65, 66, 67, 68,
        /* 069 - 074 Step_Fwd_Two */               69, 70, 71, 72, 73, 74,
        /* 075 - 082 Single_Step */                63, 64, 65, 66, 71, 72, 73, 74,
        /* 083 - 087 Stopping */                   5, 4, 3, 2, 1, 
        /* 088 - 102 Climbing */                   75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89,                     
        /* 103 - 108 Small_Step */                 63, 64, 65, 72, 73, 74,                                                         
        /* 109 - 122 Jump_Up_A */                  90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103,                     
        /* 123 - 127 Jump_Drop_A */                104, 105, 106, 107, 108,   // Drop to position 2                                
        /* 128 - 142 Step_Climbing */              75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89,                     
        /* 143 - 154 Crouch_Stand */               109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120,                     
        /* 155 - 160 Falling_SmallStep */          121, 122, 123, 124, 125, 126,                  
        /* 161 - 166 Falling_RunningJump */        121, 122, 123, 124, 125, 126,                     
        /* 167 - 172 Falling_C */                  121, 122, 123, 124, 125, 126,                             
        /* 173 - 175 Crouching */                  126, 109, 110,                                                                  
        /* 176 - 182 Crouch_HOP */                 110, 111, 112, 113, 112, 111, 110,                                              
        /* 183 - 191 Step_Climbing_Block */        75, 76, 77, 78, 79, 78, 77, 76, 75,                                             
        /* 192 - 205 Jump_Up_B */                  90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103,                     
        /* 206 - 210 Jump_Drop_B */                104, 105, 106, 107, 108,   // Drop to position 10                               
        /* 211 - 225 Drink_Tonic */                127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141,      
        /* 226 - 230 Jump_Drop_C */                104, 105, 106, 107, 108,   // Climb down, drop straight down 31 px              
        /* 231 - 232 Falling_Injured */            125, 126,   
        /* 233 - 235 Falling_Dead */               125, 126, 142,  
        /* 236 - 236 Run_Repeat_8_End_Turn */      14,   // single entry to allow x correction
        /* 237 - 241 Falling_Down */               125, 125, 125, 125, 125,  // falling straight down.
        /* 242 - 247 Falling_StandingJump */       121, 122, 123, 124, 125, 126,                                   
        /* 248 - 253 Falling_SingleStep */         121, 122, 123, 124, 125, 126,                               
        /* 254 - 269 Pickup_Sword */               143, 144, 145, 145, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 
        /* 270 - 275 Falling_StepWalkRun_P2_6_10 */    121, 122, 123, 124, 125, 126,                               
        /* 276 - 281 Falling_StepWalkRun_P0_4_8 */     121, 122, 123, 124, 125, 126,                               
        /* 282 - 287 Falling_StepWalkRun_P1_5_9 */     121, 122, 123, 124, 125, 126,                               
        /* 288 - 293 Falling_StepWalkRun_P3_7_11 */     121, 122, 123, 124, 125, 126,                               
        255,                   
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