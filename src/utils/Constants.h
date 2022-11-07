
#pragma once

#define DEBUG_PRINT    Serial.print
#define DEBUG_PRINTLN  Serial.println

#define _DEBUG
#define DEBUG_ONSCREEN_DETAILS
#define _DEBUG_ONSCREEN_DETAILS_MIN

#define _DEBUG_PRINCE_DETAILS
#define _DEBUG_PRINCE_STACK
#define _DEBUG_PRINT_ACTION
#define _DEBUG_LEVEL_LOAD_MAP
#define _DEBUG_GET_TILE
#define _DEBUG_PRINCE_RENDERING

#define _DEBUG_ACTION_CANMOVEFORWARD
#define _DEBUG_ACTION_CANJUMPUP
#define _DEBUG_ACTION_CANJUMPUP_PART2
#define _DEBUG_ACTION_CANCLIMBDOWN
#define _DEBUG_ACTION_CANCLIMBDOWN_PART2
#define _DEBUG_ACTION_CANFALL
#define _DEBUG_ACTION_CANFALLSOMEMORE
#define _DEBUG_ACTION_COLLIDEWITHWALL
#define _DEBUG_ACTION_RUNJUMP

#define _TIME_AND_LEVEL
#define TIME_ONLY

//-------------------------------------------------------------------------------------

namespace Stance {

constexpr uint16_t None                                          = 0;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* 001 - 006                                                     01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define RUN_START_SEQ                                            1,     2,     3,     4,     5,     6, 
#define RUN_START_OFFSETS                                        0,0,   1,0,   1,0,   1,0,   2,0,   2,0,
constexpr uint16_t Run_Start_1_Start                             = Stance::None + 1;
constexpr uint16_t Run_Start_2                                   = Stance::Run_Start_1_Start + 1;
constexpr uint16_t Run_Start_3                                   = Stance::Run_Start_2 + 1;
constexpr uint16_t Run_Start_4                                   = Stance::Run_Start_3 + 1;
constexpr uint16_t Run_Start_5                                   = Stance::Run_Start_4 + 1;
constexpr uint16_t Run_Start_6_End                               = Stance::Run_Start_5 + 1;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* 007 - 014                                                     01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define RUN_REPEAT_SEQ                                           7,     8,     9,     10,    11,    12,    13,    14,
#define RUN_REPEAT_OFFSETS                                       3,0,   3,0,   3,0,   3,0,   3,0,   3,0,   3,0,   3,0,
constexpr uint16_t Run_Repeat_1_Start                            = Stance::Run_Start_6_End + 1;
constexpr uint16_t Run_Repeat_2                                  = Stance::Run_Repeat_1_Start + 1;
constexpr uint16_t Run_Repeat_3                                  = Stance::Run_Repeat_2 + 1;
constexpr uint16_t Run_Repeat_4                                  = Stance::Run_Repeat_3 + 1;
constexpr uint16_t Run_Repeat_5_Mid                              = Stance::Run_Repeat_4 + 1; 
constexpr uint16_t Run_Repeat_6                                  = Stance::Run_Repeat_5_Mid + 1; 
constexpr uint16_t Run_Repeat_7                                  = Stance::Run_Repeat_6 + 1; 
constexpr uint16_t Run_Repeat_8_End                              = Stance::Run_Repeat_7 + 1; 


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* 015 - 015                                                     01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define UPRIGHT_SEQ                                              15,
#define UPRIGHT_OFFSETS                                          0,0,
constexpr uint16_t Upright                                       = Stance::Run_Repeat_8_End + 1;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* 016 - 026                                                     01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define RUNNING_JUMP_SEQ                                         16,    17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
#define RUNNING_JUMP_OFFSETS                                     2,0,   3,0,   4,0,   4,0,   5,0,   6,0,   6,0,   6,0,   5,0,   3,0,   2,0,
constexpr uint16_t Running_Jump_1_Start                          = Stance::Upright + 1;
constexpr uint16_t Running_Jump_2                                = Stance::Running_Jump_1_Start + 1;
constexpr uint16_t Running_Jump_3                                = Stance::Running_Jump_2 + 1;
constexpr uint16_t Running_Jump_4                                = Stance::Running_Jump_3 + 1;
constexpr uint16_t Running_Jump_5                                = Stance::Running_Jump_4 + 1;
constexpr uint16_t Running_Jump_6                                = Stance::Running_Jump_5 + 1;
constexpr uint16_t Running_Jump_7                                = Stance::Running_Jump_6 + 1;
constexpr uint16_t Running_Jump_8                                = Stance::Running_Jump_7 + 1;
constexpr uint16_t Running_Jump_9                                = Stance::Running_Jump_8 + 1;
constexpr uint16_t Running_Jump_10                               = Stance::Running_Jump_9 + 1;
constexpr uint16_t Running_Jump_11_End                           = Stance::Running_Jump_10 + 1;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* 027 - 031                                                     01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define STANDING_TURN_SEQ                                        27,    28,    29,    30,    31,
#define STANDING_TURN_OFFSETS                                    0,0,   -1,0,  -1,0,  2,0,   0,0,
constexpr uint16_t Standing_Turn_1_Start                         = Stance::Running_Jump_11_End + 1; 
constexpr uint16_t Standing_Turn_2                               = Stance::Standing_Turn_1_Start + 1;
constexpr uint16_t Standing_Turn_3                               = Stance::Standing_Turn_2 + 1;
constexpr uint16_t Standing_Turn_4                               = Stance::Standing_Turn_3 + 1; 
constexpr uint16_t Standing_Turn_5_End                           = Stance::Standing_Turn_4 + 1; 


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* 032 - 044                                                     01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define RUNNING_TURN_SEQ                                         32,    33,    34,    35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
#define RUNNING_TURN_OFFSETS                                     0,0,   3,0,   -3,0,  -1,0,  1,0,   0,0,   0,0,   0,0,   0,0,   0,0,   -1,0,  1,0,   0,0,
constexpr uint16_t Running_Turn_1_Start                          = Stance::Standing_Turn_5_End + 1;
constexpr uint16_t Running_Turn_2                                = Stance::Running_Turn_1_Start + 1;
constexpr uint16_t Running_Turn_3                                = Stance::Running_Turn_2 + 1;
constexpr uint16_t Running_Turn_4                                = Stance::Running_Turn_3 + 1;
constexpr uint16_t Running_Turn_5                                = Stance::Running_Turn_4 + 1;
constexpr uint16_t Running_Turn_6                                = Stance::Running_Turn_5 + 1;
constexpr uint16_t Running_Turn_7                                = Stance::Running_Turn_6 + 1;
constexpr uint16_t Running_Turn_8                                = Stance::Running_Turn_7 + 1;
constexpr uint16_t Running_Turn_9                                = Stance::Running_Turn_8 + 1;
constexpr uint16_t Running_Turn_10                               = Stance::Running_Turn_9 + 1;
constexpr uint16_t Running_Turn_11                               = Stance::Running_Turn_10 + 1;
constexpr uint16_t Running_Turn_12                               = Stance::Running_Turn_11 + 1;
constexpr uint16_t Running_Turn_13_End                           = Stance::Running_Turn_12 + 1;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* 045 - 062                                                     01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define STANDING_JUMP_SEQ                                        45,    46,    47,    48,    49,    50,    51,    52,    53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
#define STANDING_JUMP_OFFSETS                                    0,0,   0,0,   2,0,   2,0,   2,0,   2,0,   2,0,   3,0,   3,0,   3,0,   3,0,   4,0,   2,0,   2,0,   2,0,   2,0,   1,0,   1,0, 
constexpr uint16_t Standing_Jump_1_Start                         = Stance::Running_Turn_13_End + 1;
constexpr uint16_t Standing_Jump_2                               = Stance::Standing_Jump_1_Start + 1;
constexpr uint16_t Standing_Jump_3                               = Stance::Standing_Jump_2 + 1;
constexpr uint16_t Standing_Jump_4                               = Stance::Standing_Jump_3 + 1;
constexpr uint16_t Standing_Jump_5                               = Stance::Standing_Jump_4 + 1;
constexpr uint16_t Standing_Jump_6                               = Stance::Standing_Jump_5 + 1;
constexpr uint16_t Standing_Jump_7                               = Stance::Standing_Jump_6 + 1;
constexpr uint16_t Standing_Jump_8                               = Stance::Standing_Jump_7 + 1;
constexpr uint16_t Standing_Jump_9                               = Stance::Standing_Jump_8 + 1;
constexpr uint16_t Standing_Jump_10                              = Stance::Standing_Jump_9 + 1;
constexpr uint16_t Standing_Jump_11_Land_Point                   = Stance::Standing_Jump_10 + 1;
constexpr uint16_t Standing_Jump_12                              = Stance::Standing_Jump_11_Land_Point + 1;
constexpr uint16_t Standing_Jump_13                              = Stance::Standing_Jump_12 + 1;
constexpr uint16_t Standing_Jump_14                              = Stance::Standing_Jump_13 + 1;
constexpr uint16_t Standing_Jump_15                              = Stance::Standing_Jump_14 + 1;
constexpr uint16_t Standing_Jump_16                              = Stance::Standing_Jump_15 + 1;
constexpr uint16_t Standing_Jump_17                              = Stance::Standing_Jump_16 + 1;
constexpr uint16_t Standing_Jump_18_End                          = Stance::Standing_Jump_17 + 1;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* 063 - 068                                                     01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define STEP_FWD_ONE_SEQ                                         63,    64,    65,    66,    67,    68,
#define STEP_FWD_ONE_OFFSETS                                     0,0,   0,0,   0,0,   0,0,   0,0,   0,0,
constexpr uint16_t Step_Fwd_One_1_Start                          = Stance::Standing_Jump_18_End + 1;
constexpr uint16_t Step_Fwd_One_2                                = Stance::Step_Fwd_One_1_Start + 1;
constexpr uint16_t Step_Fwd_One_3                                = Stance::Step_Fwd_One_2 + 1;
constexpr uint16_t Step_Fwd_One_4                                = Stance::Step_Fwd_One_3 + 1;    
constexpr uint16_t Step_Fwd_One_5                                = Stance::Step_Fwd_One_4 + 1;    
constexpr uint16_t Step_Fwd_One_6_End                            = Stance::Step_Fwd_One_5 + 1;    


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* 069 - 074                                                     01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define STEP_FWD_TWO_SEQ                                         69,    70,    71,    72,    73,    74,
#define STEP_FWD_TWO_OFFSETS                                     0,0,   0,0,   0,0,   0,0,   0,0,   0,0,
constexpr uint16_t Step_Fwd_Two_1_Start                          = Stance::Step_Fwd_One_6_End + 1;
constexpr uint16_t Step_Fwd_Two_2                                = Stance::Step_Fwd_Two_1_Start + 1;
constexpr uint16_t Step_Fwd_Two_3                                = Stance::Step_Fwd_Two_2 + 1;
constexpr uint16_t Step_Fwd_Two_4                                = Stance::Step_Fwd_Two_3 + 1;    
constexpr uint16_t Step_Fwd_Two_5                                = Stance::Step_Fwd_Two_4 + 1;    
constexpr uint16_t Step_Fwd_Two_6_End                            = Stance::Step_Fwd_Two_5 + 1;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* 075 - 082                                                     01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define SINGLE_STEP_SEQ                                          63,    64,    65,    66,    71,    72,    73,    74,
#define SINGLE_STEP_OFFSETS                                      1,0,   1,0,   1,0,   1,0,   1,0,   1,0,   1,0,   1,0, 
constexpr uint16_t Single_Step_1_Start                           = Stance::Step_Fwd_Two_6_End + 1;
constexpr uint16_t Single_Step_2                                 = Stance::Single_Step_1_Start + 1;
constexpr uint16_t Single_Step_3                                 = Stance::Single_Step_2 + 1;
constexpr uint16_t Single_Step_4                                 = Stance::Single_Step_3 + 1;
constexpr uint16_t Single_Step_5                                 = Stance::Single_Step_4 + 1;
constexpr uint16_t Single_Step_6                                 = Stance::Single_Step_5 + 1;
constexpr uint16_t Single_Step_7                                 = Stance::Single_Step_6 + 1;
constexpr uint16_t Single_Step_8_End                             = Stance::Single_Step_7 + 1;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* 083 - 087                                                     01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define STOPPING_SEQ                                             5,     4,     3,     2,     1, 
#define STOPPING_OFFSETS                                         0,0,   0,0,   0,0,   0,0,   0,0,
constexpr uint16_t Stopping_1_Start                              = Stance::Single_Step_8_End + 1;
constexpr uint16_t Stopping_2                                    = Stance::Stopping_1_Start + 1;
constexpr uint16_t Stopping_3                                    = Stance::Stopping_2 + 1;
constexpr uint16_t Stopping_4                                    = Stance::Stopping_3 + 1;
constexpr uint16_t Stopping_5_End                                = Stance::Stopping_4 + 1;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* 088 - 102                                                     01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define CLIMBING_SEQ                                             75,    76,    77,    78,    79,    80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
#define CLIMBING_OFFSETS                                         0,0,   0,0,   0,0,   -1,-1, 0,0,   0,0,   0,0,   0,0,   1,0,   0,0,   1,0,   0,0,   0,0,   0,0,   0,0, 
constexpr uint16_t Climbing_1_Start                              = Stance::Stopping_5_End + 1;
constexpr uint16_t Climbing_2                                    = Stance::Climbing_1_Start + 1;
constexpr uint16_t Climbing_3                                    = Stance::Climbing_2 + 1;
constexpr uint16_t Climbing_4                                    = Stance::Climbing_3 + 1;
constexpr uint16_t Climbing_5                                    = Stance::Climbing_4 + 1;
constexpr uint16_t Climbing_6                                    = Stance::Climbing_5 + 1;
constexpr uint16_t Climbing_7                                    = Stance::Climbing_6 + 1;
constexpr uint16_t Climbing_8                                    = Stance::Climbing_7 + 1;
constexpr uint16_t Climbing_9                                    = Stance::Climbing_8 + 1;
constexpr uint16_t Climbing_10                                   = Stance::Climbing_9 + 1;
constexpr uint16_t Climbing_11                                   = Stance::Climbing_10 + 1;
constexpr uint16_t Climbing_12                                   = Stance::Climbing_11 + 1;
constexpr uint16_t Climbing_13                                   = Stance::Climbing_12 + 1;
constexpr uint16_t Climbing_14                                   = Stance::Climbing_13 + 1;
constexpr uint16_t Climbing_15_End                               = Stance::Climbing_14 + 1;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* 103 - 108                                                     01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define SMALL_STEP_SEQ                                           63,    64,    65,    72,    73,    74,  
#define SMALL_STEP_OFFSETS                                       1,0,   1,0,   1,0,   1,0,   0,0,   0,0, 
constexpr uint16_t Small_Step_1_Start                            = Stance::Climbing_15_End + 1;
constexpr uint16_t Small_Step_2                                  = Stance::Small_Step_1_Start + 1;
constexpr uint16_t Small_Step_3                                  = Stance::Small_Step_2 + 1;
constexpr uint16_t Small_Step_4                                  = Stance::Small_Step_3 + 1;
constexpr uint16_t Small_Step_5                                  = Stance::Small_Step_4 + 1;
constexpr uint16_t Small_Step_6_End                              = Stance::Small_Step_5 + 1;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* 109 - 122                                                     01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define JUMP_UP_A_SEQ                                            90,    91,    92,    93,    94,    95,    96,    97,    98,    99,    100,   101,   102,   103,
#define JUMP_UP_A_OFFSETS                                        0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,                                             
constexpr uint16_t Jump_Up_A_1_Start                             = Stance::Small_Step_6_End + 1; 
constexpr uint16_t Jump_Up_A_2                                   = Stance::Jump_Up_A_1_Start + 1;
constexpr uint16_t Jump_Up_A_3                                   = Stance::Jump_Up_A_2 + 1;
constexpr uint16_t Jump_Up_A_4                                   = Stance::Jump_Up_A_3 + 1;
constexpr uint16_t Jump_Up_A_5                                   = Stance::Jump_Up_A_4 + 1;
constexpr uint16_t Jump_Up_A_6                                   = Stance::Jump_Up_A_5 + 1;
constexpr uint16_t Jump_Up_A_7                                   = Stance::Jump_Up_A_6 + 1;
constexpr uint16_t Jump_Up_A_8                                   = Stance::Jump_Up_A_7 + 1;
constexpr uint16_t Jump_Up_A_9                                   = Stance::Jump_Up_A_8 + 1;
constexpr uint16_t Jump_Up_A_10                                  = Stance::Jump_Up_A_9 + 1;
constexpr uint16_t Jump_Up_A_11                                  = Stance::Jump_Up_A_10 + 1;
constexpr uint16_t Jump_Up_A_12                                  = Stance::Jump_Up_A_11 + 1;
constexpr uint16_t Jump_Up_A_13                                  = Stance::Jump_Up_A_12 + 1;
constexpr uint16_t Jump_Up_A_14_End                              = Stance::Jump_Up_A_13 + 1;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* 123 - 127                                                     01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define JUMP_UP_DROP_A_SEQ                                       104,   105,   106,   107,   108,
#define JUMP_UP_DROP_A_OFFSETS                                   0,0,   0,0,   0,0,   0,0,   0,0,
constexpr uint16_t Jump_Up_Drop_A_1_Start                        = Stance::Jump_Up_A_14_End + 1;  // Drop down to Pos 2
constexpr uint16_t Jump_Up_Drop_A_2                              = Stance::Jump_Up_Drop_A_1_Start + 1;
constexpr uint16_t Jump_Up_Drop_A_3                              = Stance::Jump_Up_Drop_A_2 + 1;
constexpr uint16_t Jump_Up_Drop_A_4                              = Stance::Jump_Up_Drop_A_3 + 1;
constexpr uint16_t Jump_Up_Drop_A_5_End                          = Stance::Jump_Up_Drop_A_4 + 1;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* 128 - 142                                                     01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define STEP_CLIMBING_SEQ                                        75,    76,    77,    78,    79,    80,    81,    82,    83,    84,    85,    86,    87,    88,    89,  
#define STEP_CLIMBING_OFFSETS                                    0,-4,  0,-4,  0,-2,  0,-3,  0,-2,  0,-2,  0,-3,  0,-3,  0,-1,  1,-3,  1,-2,  0,-1,  1,-1,  1,0,   0,0, 
constexpr uint16_t Step_Climbing_1_Start                         = Stance::Jump_Up_Drop_A_5_End + 1;  // Climb up / down from a ledge (second part)
constexpr uint16_t Step_Climbing_2                               = Stance::Step_Climbing_1_Start + 1;
constexpr uint16_t Step_Climbing_3                               = Stance::Step_Climbing_2 + 1;
constexpr uint16_t Step_Climbing_4                               = Stance::Step_Climbing_3 + 1;
constexpr uint16_t Step_Climbing_5                               = Stance::Step_Climbing_4 + 1;
constexpr uint16_t Step_Climbing_6                               = Stance::Step_Climbing_5 + 1;
constexpr uint16_t Step_Climbing_7                               = Stance::Step_Climbing_6 + 1;
constexpr uint16_t Step_Climbing_8                               = Stance::Step_Climbing_7 + 1;
constexpr uint16_t Step_Climbing_9                               = Stance::Step_Climbing_8 + 1;
constexpr uint16_t Step_Climbing_10                              = Stance::Step_Climbing_9 + 1;
constexpr uint16_t Step_Climbing_11                              = Stance::Step_Climbing_10 + 1;
constexpr uint16_t Step_Climbing_12                              = Stance::Step_Climbing_11 + 1;
constexpr uint16_t Step_Climbing_13                              = Stance::Step_Climbing_12 + 1;
constexpr uint16_t Step_Climbing_14                              = Stance::Step_Climbing_13 + 1;
constexpr uint16_t Step_Climbing_15_End                          = Stance::Step_Climbing_14 + 1;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* 143 - 154                                                     01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define CROUCH_STAND_SEQ                                         109,   110,   111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
#define CROUCH_STAND_OFFSETS                                     0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,
constexpr uint16_t Crouch_Stand_1_Start                          = Stance::Step_Climbing_15_End + 1;
constexpr uint16_t Crouch_Stand_2                                = Stance::Crouch_Stand_1_Start + 1;
constexpr uint16_t Crouch_Stand_3                                = Stance::Crouch_Stand_2 + 1;
constexpr uint16_t Crouch_Stand_4                                = Stance::Crouch_Stand_3 + 1;
constexpr uint16_t Crouch_Stand_5                                = Stance::Crouch_Stand_4 + 1;
constexpr uint16_t Crouch_Stand_6                                = Stance::Crouch_Stand_5 + 1;
constexpr uint16_t Crouch_Stand_7                                = Stance::Crouch_Stand_6 + 1;
constexpr uint16_t Crouch_Stand_8                                = Stance::Crouch_Stand_7 + 1;
constexpr uint16_t Crouch_Stand_9                                = Stance::Crouch_Stand_8 + 1;
constexpr uint16_t Crouch_Stand_10                               = Stance::Crouch_Stand_9 + 1;
constexpr uint16_t Crouch_Stand_11                               = Stance::Crouch_Stand_10 + 1;
constexpr uint16_t Crouch_Stand_12_End                           = Stance::Crouch_Stand_11 + 1;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* 155 - 157                                                     01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define CROUCH_SEQ                                               126,   109,   110,   
#define CROUCH_OFFSETS                                           0,0,   0,0,   0,0, 
//constexpr uint16_t Crouch_1_Start                                = Stance::Falling_C_6_End + 1;
constexpr uint16_t Crouch_1_Start                                = Stance::Crouch_Stand_12_End + 1;
constexpr uint16_t Crouch_2                                      = Stance::Crouch_1_Start + 1;
constexpr uint16_t Crouch_3_End                                  = Stance::Crouch_2 + 1;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* 158 - 164                                                     01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define CROUCH_HOP_SEQ                                           110,   111,   112,   113,   112,   111,   110, 
#define CROUCH_HOP_OFFSETS                                       0,0,   1,0,   1,0,   1,0,   1,0,   0,0,   0,0,
constexpr uint16_t Crouch_HOP_1_Start                            = Stance::Crouch_3_End + 1;
constexpr uint16_t Crouch_HOP_2                                  = Stance::Crouch_HOP_1_Start + 1;
constexpr uint16_t Crouch_HOP_3                                  = Stance::Crouch_HOP_2 + 1;
constexpr uint16_t Crouch_HOP_4                                  = Stance::Crouch_HOP_3 + 1;
constexpr uint16_t Crouch_HOP_5                                  = Stance::Crouch_HOP_4 + 1;
constexpr uint16_t Crouch_HOP_6                                  = Stance::Crouch_HOP_5 + 1;
constexpr uint16_t Crouch_HOP_7_End                              = Stance::Crouch_HOP_6 + 1;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* 165 - 173                                                     01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define STEP_CLIMBINB_BLOCK_SEQ                                  75,    76,    77,    78,    79,    78,    77,    76,    75, 
#define STEP_CLIMBINB_BLOCK_OFFSETS                              0,-4,  0,-4,  0,-2,  0,-3,  0,0,   0,3,   0,2,   0,4,   0,4,
constexpr uint16_t Step_Climbing_Block_1_Start                   = Stance::Crouch_HOP_7_End + 1;
constexpr uint16_t Step_Climbing_Block_2                         = Stance::Step_Climbing_Block_1_Start + 1;
constexpr uint16_t Step_Climbing_Block_3                         = Stance::Step_Climbing_Block_2 + 1;
constexpr uint16_t Step_Climbing_Block_4                         = Stance::Step_Climbing_Block_3 + 1;
constexpr uint16_t Step_Climbing_Block_5                         = Stance::Step_Climbing_Block_4 + 1;
constexpr uint16_t Step_Climbing_Block_6                         = Stance::Step_Climbing_Block_5 + 1;
constexpr uint16_t Step_Climbing_Block_7                         = Stance::Step_Climbing_Block_6 + 1;
constexpr uint16_t Step_Climbing_Block_8                         = Stance::Step_Climbing_Block_7 + 1;
constexpr uint16_t Step_Climbing_Block_9_End                     = Stance::Step_Climbing_Block_8 + 1;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* 174 - 187                                                     01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define JUMP_UP_B_SEQ                                            90,    91,    92,    93,    94,    95,    96,    97,    98,    99,    100,   101,   102,   103,    
#define JUMP_UP_B_OFFSETS                                        0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   -1,0,  -1,0,  -1,0,  -1,0,  0,0,
constexpr uint16_t Jump_Up_B_1_Start                             = Stance::Step_Climbing_Block_9_End + 1;
constexpr uint16_t Jump_Up_B_2                                   = Stance::Jump_Up_B_1_Start + 1;
constexpr uint16_t Jump_Up_B_3                                   = Stance::Jump_Up_B_2 + 1;
constexpr uint16_t Jump_Up_B_4                                   = Stance::Jump_Up_B_3 + 1;
constexpr uint16_t Jump_Up_B_5                                   = Stance::Jump_Up_B_4 + 1;
constexpr uint16_t Jump_Up_B_6                                   = Stance::Jump_Up_B_5 + 1;
constexpr uint16_t Jump_Up_B_7                                   = Stance::Jump_Up_B_6 + 1;
constexpr uint16_t Jump_Up_B_8                                   = Stance::Jump_Up_B_7 + 1;
constexpr uint16_t Jump_Up_B_9                                   = Stance::Jump_Up_B_8 + 1;
constexpr uint16_t Jump_Up_B_10                                  = Stance::Jump_Up_B_9 + 1;
constexpr uint16_t Jump_Up_B_11                                  = Stance::Jump_Up_B_10 + 1;
constexpr uint16_t Jump_Up_B_12                                  = Stance::Jump_Up_B_11 + 1;
constexpr uint16_t Jump_Up_B_13                                  = Stance::Jump_Up_B_12 + 1;
constexpr uint16_t Jump_Up_B_14_End                              = Stance::Jump_Up_B_13 + 1;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* 188 - 192                                                     01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define JUMP_UP_DROP_B_SEQ                                       104,   105,   106,   107,   108,   // Drop to position 10
#define JUMP_UP_DROP_B_OFFSETS                                   1,0,   1,0,   1,0,   1,0,   0,0, 
constexpr uint16_t Jump_Up_Drop_B_1_Start                        = Stance::Jump_Up_B_14_End + 1;  // Drop down to Pos 10
constexpr uint16_t Jump_Up_Drop_B_2                              = Stance::Jump_Up_Drop_B_1_Start + 1;
constexpr uint16_t Jump_Up_Drop_B_3                              = Stance::Jump_Up_Drop_B_2 + 1;
constexpr uint16_t Jump_Up_Drop_B_4                              = Stance::Jump_Up_Drop_B_3 + 1;
constexpr uint16_t Jump_Up_Drop_B_5_End                          = Stance::Jump_Up_Drop_B_4 + 1;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* 193 - 207                                                     01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define DRINK_TONIC_SEQ                                          127,   128,   129,   130,   131,   132,   133,   134,   135,   136,   137,   138,   139,   140,   141,  
#define DRINK_TONIC_OFFSETS                                      0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,
constexpr uint16_t Drink_Tonic_1_Start                           = Stance::Jump_Up_Drop_B_5_End + 1; 
constexpr uint16_t Drink_Tonic_2                                 = Stance::Drink_Tonic_1_Start + 1;
constexpr uint16_t Drink_Tonic_3                                 = Stance::Drink_Tonic_2 + 1;
constexpr uint16_t Drink_Tonic_4                                 = Stance::Drink_Tonic_3 + 1;
constexpr uint16_t Drink_Tonic_5                                 = Stance::Drink_Tonic_4 + 1;
constexpr uint16_t Drink_Tonic_6                                 = Stance::Drink_Tonic_5 + 1;
constexpr uint16_t Drink_Tonic_7                                 = Stance::Drink_Tonic_6 + 1;
constexpr uint16_t Drink_Tonic_8                                 = Stance::Drink_Tonic_7 + 1;
constexpr uint16_t Drink_Tonic_9                                 = Stance::Drink_Tonic_8 + 1;
constexpr uint16_t Drink_Tonic_10                                = Stance::Drink_Tonic_9 + 1;
constexpr uint16_t Drink_Tonic_11                                = Stance::Drink_Tonic_10 + 1;
constexpr uint16_t Drink_Tonic_12                                = Stance::Drink_Tonic_11 + 1;
constexpr uint16_t Drink_Tonic_13                                = Stance::Drink_Tonic_12 + 1;
constexpr uint16_t Drink_Tonic_14                                = Stance::Drink_Tonic_13 + 1;
constexpr uint16_t Drink_Tonic_15_End                            = Stance::Drink_Tonic_14 + 1;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* 208 - 212                                                     01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define JUMP_UP_DROP_C_SEQ                                       104,   105,   106,   107,   108,   // Climb down, drop straight down 31 px 
#define JUMP_UP_DROP_C_OFFSETS                                   0,6,   0,6,   0,6,   0,6,   0,7,
constexpr uint16_t Jump_Up_Drop_C_1_Start                        = Stance::Drink_Tonic_15_End + 1;  // Drop down to Pos 2 (two levels)
constexpr uint16_t Jump_Up_Drop_C_2                              = Stance::Jump_Up_Drop_C_1_Start + 1;
constexpr uint16_t Jump_Up_Drop_C_3                              = Stance::Jump_Up_Drop_C_2 + 1;
constexpr uint16_t Jump_Up_Drop_C_4                              = Stance::Jump_Up_Drop_C_3 + 1;
constexpr uint16_t Jump_Up_Drop_C_5_End                          = Stance::Jump_Up_Drop_C_4 + 1;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* 213 - 214                                                     01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define FALLING_INJURED_SEQ                                      125,   126, 
#define FALLING_INJURED_OFFSETS                                  0,0,   0,0,
constexpr uint16_t Falling_Injured_1_Start                       = Stance::Jump_Up_Drop_C_5_End + 1;  // Climbing down, falling two levels
constexpr uint16_t Falling_Injured_2_End                         = Stance::Falling_Injured_1_Start + 1;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* 215 - 217                                                     01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define FALLING_DEAD_SEQ                                         125,   126,   142,
#define FALLING_DEAD_OFFSETS                                     0,0,   0,0,   0,0,
constexpr uint16_t Falling_Dead_1_Start                          = Stance::Falling_Injured_2_End + 1;  // Climbing down, fall to death
constexpr uint16_t Falling_Dead_2                                = Stance::Falling_Dead_1_Start + 1;
constexpr uint16_t Falling_Dead_3_End                            = Stance::Falling_Dead_2 + 1;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* 218 - 218                                                     01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define RUN_REPEAT_8_END_SEQ                                     14, 
#define RUN_REPEAT_8_END_OFFSETS                                 4,0,
constexpr uint16_t Run_Repeat_8_End_Turn                         = Stance::Falling_Dead_3_End + 1;  // Single entry to allow x correction


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* 219 - 223                                                     01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define FALLING_DOWN_SEQ                                         125,   125,   125,   125,   125,
#define FALLING_DOWN_OFFSETS                                     0,6,   0,6,   0,6,   0,6,   0,7,
constexpr uint16_t Falling_Down_1_Start                          = Stance::Run_Repeat_8_End_Turn + 1;
constexpr uint16_t Falling_Down_2                                = Stance::Falling_Down_1_Start + 1;
constexpr uint16_t Falling_Down_3                                = Stance::Falling_Down_2 + 1;
constexpr uint16_t Falling_Down_4                                = Stance::Falling_Down_3 + 1;
constexpr uint16_t Falling_Down_5_End                            = Stance::Falling_Down_4 + 1;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* 224 - 239                                                     01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define PICKUP_SWORD_SEQ                                         143,   144,   145,   145,   145,   146,   147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
#define PICKUP_SWORD_OFFSETS                                     0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,
constexpr uint16_t Pickup_Sword_1_Start                          = Stance::Falling_Down_5_End + 1;
constexpr uint16_t Pickup_Sword_2                                = Stance::Pickup_Sword_1_Start + 1;
constexpr uint16_t Pickup_Sword_3                                = Stance::Pickup_Sword_2 + 1;
constexpr uint16_t Pickup_Sword_4                                = Stance::Pickup_Sword_3 + 1;
constexpr uint16_t Pickup_Sword_5                                = Stance::Pickup_Sword_4 + 1;
constexpr uint16_t Pickup_Sword_6                                = Stance::Pickup_Sword_5 + 1;
constexpr uint16_t Pickup_Sword_7                                = Stance::Pickup_Sword_6 + 1;
constexpr uint16_t Pickup_Sword_8                                = Stance::Pickup_Sword_7 + 1;
constexpr uint16_t Pickup_Sword_9                                = Stance::Pickup_Sword_8 + 1;
constexpr uint16_t Pickup_Sword_10                               = Stance::Pickup_Sword_9 + 1;
constexpr uint16_t Pickup_Sword_11                               = Stance::Pickup_Sword_10 + 1;
constexpr uint16_t Pickup_Sword_12                               = Stance::Pickup_Sword_11 + 1;
constexpr uint16_t Pickup_Sword_13                               = Stance::Pickup_Sword_12 + 1;
constexpr uint16_t Pickup_Sword_14                               = Stance::Pickup_Sword_13 + 1;
constexpr uint16_t Pickup_Sword_15                               = Stance::Pickup_Sword_14 + 1;
constexpr uint16_t Pickup_Sword_16_End                           = Stance::Pickup_Sword_15 + 1;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* 240 - 245                                                     01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define FALLING_STEPWALKRUN_P2_6_10_SEQ                          121,   122,   123,   124,   125,   126,
#define FALLING_STEPWALKRUN_P2_6_10_OFFSETS                      2,6,   2,5,   2,5,   1,5,   1,5,   0,5,
constexpr uint16_t Falling_StepWalkRun_P2_6_10_1_Start           = Stance::Pickup_Sword_16_End + 1;
constexpr uint16_t Falling_StepWalkRun_P2_6_10_2                 = Stance::Falling_StepWalkRun_P2_6_10_1_Start + 1;
constexpr uint16_t Falling_StepWalkRun_P2_6_10_3                 = Stance::Falling_StepWalkRun_P2_6_10_2 + 1;
constexpr uint16_t Falling_StepWalkRun_P2_6_10_4                 = Stance::Falling_StepWalkRun_P2_6_10_3 + 1;
constexpr uint16_t Falling_StepWalkRun_P2_6_10_5_Check_CanFall   = Stance::Falling_StepWalkRun_P2_6_10_4 + 1;
constexpr uint16_t Falling_StepWalkRun_P2_6_10_6_End             = Stance::Falling_StepWalkRun_P2_6_10_5_Check_CanFall + 1;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* 246 - 251                                                     01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define FALLING_STEPWALKRUN_P0_4_8_SEQ                           121,   122,   123,   124,   125,   126,
#define FALLING_STEPWALKRUN_P0_4_8_OFFSETS                       2,6,   2,5,   1,5,   1,5,   0,5,   0,5,
constexpr uint16_t Falling_StepWalkRun_P0_4_8_1_Start            = Stance::Falling_StepWalkRun_P2_6_10_6_End + 1;
constexpr uint16_t Falling_StepWalkRun_P0_4_8_2                  = Stance::Falling_StepWalkRun_P0_4_8_1_Start + 1;
constexpr uint16_t Falling_StepWalkRun_P0_4_8_3                  = Stance::Falling_StepWalkRun_P0_4_8_2 + 1;
constexpr uint16_t Falling_StepWalkRun_P0_4_8_4                  = Stance::Falling_StepWalkRun_P0_4_8_3 + 1;
constexpr uint16_t Falling_StepWalkRun_P0_4_8_5_Check_CanFall    = Stance::Falling_StepWalkRun_P0_4_8_4 + 1;
constexpr uint16_t Falling_StepWalkRun_P0_4_8_6_End              = Stance::Falling_StepWalkRun_P0_4_8_5_Check_CanFall + 1;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* 252 - 257                                                     01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define FALLING_STEPWALKRUN_P1_5_9_SEQ                           121,   122,   123,   124,   125,   126,
#define FALLING_STEPWALKRUN_P1_5_9_OFFSETS                       2,6,   2,5,   2,5,   1,5,   0,5,   0,5,
constexpr uint16_t Falling_StepWalkRun_P1_5_9_1_Start            = Stance::Falling_StepWalkRun_P0_4_8_6_End + 1;
constexpr uint16_t Falling_StepWalkRun_P1_5_9_2                  = Stance::Falling_StepWalkRun_P1_5_9_1_Start + 1;
constexpr uint16_t Falling_StepWalkRun_P1_5_9_3                  = Stance::Falling_StepWalkRun_P1_5_9_2 + 1;
constexpr uint16_t Falling_StepWalkRun_P1_5_9_4                  = Stance::Falling_StepWalkRun_P1_5_9_3 + 1;
constexpr uint16_t Falling_StepWalkRun_P1_5_9_5_Check_CanFall    = Stance::Falling_StepWalkRun_P1_5_9_4 + 1;
constexpr uint16_t Falling_StepWalkRun_P1_5_9_6_End              = Stance::Falling_StepWalkRun_P1_5_9_5_Check_CanFall + 1;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* 258 - 263                                                     01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define FALLING_STEPWALKRUN_P3_7_11_SEQ                          121,   122,   123,   124,   125,   126,
#define FALLING_STEPWALKRUN_P3_7_11_OFFSETS                      2,6,   2,5,   2,5,    2,5,   1,5,   0,5,
constexpr uint16_t Falling_StepWalkRun_P3_7_11_1_Start           = Stance::Falling_StepWalkRun_P1_5_9_6_End + 1;
constexpr uint16_t Falling_StepWalkRun_P3_7_11_2                 = Stance::Falling_StepWalkRun_P3_7_11_1_Start + 1;
constexpr uint16_t Falling_StepWalkRun_P3_7_11_3                 = Stance::Falling_StepWalkRun_P3_7_11_2 + 1;
constexpr uint16_t Falling_StepWalkRun_P3_7_11_4                 = Stance::Falling_StepWalkRun_P3_7_11_3 + 1;
constexpr uint16_t Falling_StepWalkRun_P3_7_11_5_Check_CanFall   = Stance::Falling_StepWalkRun_P3_7_11_4 + 1;
constexpr uint16_t Falling_StepWalkRun_P3_7_11_6_End             = Stance::Falling_StepWalkRun_P3_7_11_5_Check_CanFall + 1;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* 264 - 277                                                     01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define LEAVE_GATE_SEQ                                           157,   158,   159,   160,   161,   162,   163,   164,   165,   166,   167,   168,   168,   0,
#define LEAVE_GATE_OFFSETS                                       0,0,   1,0,   2,-1,  2,-1,  2,-1,  1,-1,  1,-1,  1,-1,  1,-1,  1,-1,  1,-2,  0,-3,  0,0,   0,0,
constexpr uint16_t Leave_Gate_1_Start                            = Stance::Falling_StepWalkRun_P3_7_11_6_End + 1;
constexpr uint16_t Leave_Gate_2                                  = Stance::Leave_Gate_1_Start + 1;
constexpr uint16_t Leave_Gate_3                                  = Stance::Leave_Gate_2 + 1;
constexpr uint16_t Leave_Gate_4                                  = Stance::Leave_Gate_3 + 1;
constexpr uint16_t Leave_Gate_5                                  = Stance::Leave_Gate_4 + 1;
constexpr uint16_t Leave_Gate_6                                  = Stance::Leave_Gate_5 + 1;
constexpr uint16_t Leave_Gate_7                                  = Stance::Leave_Gate_6 + 1;
constexpr uint16_t Leave_Gate_8                                  = Stance::Leave_Gate_7 + 1;
constexpr uint16_t Leave_Gate_9                                  = Stance::Leave_Gate_8 + 1;
constexpr uint16_t Leave_Gate_10                                 = Stance::Leave_Gate_9 + 1;
constexpr uint16_t Leave_Gate_11                                 = Stance::Leave_Gate_10 + 1;
constexpr uint16_t Leave_Gate_12                                 = Stance::Leave_Gate_11 + 1;
constexpr uint16_t Leave_Gate_13                                 = Stance::Leave_Gate_12 + 1;
constexpr uint16_t Leave_Gate_14_End                             = Stance::Leave_Gate_13 + 1;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* 278 - 282                                                     01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define COLLIDE_WALL_SEQ                                         126,   126,   126,   126,   126, 
#define COLLIDE_WALL_OFFSETS                                     2,0,   1,0,   0,0,   -1,0,  -2,0,
constexpr uint16_t Collide_Wall_P2_Start_End                     = Stance::Leave_Gate_14_End + 1;
constexpr uint16_t Collide_Wall_P1_Start_End                     = Stance::Collide_Wall_P2_Start_End + 1;
constexpr uint16_t Collide_Wall_P0_Start_End                     = Stance::Collide_Wall_P1_Start_End + 1;
constexpr uint16_t Collide_Wall_M1_Start_End                     = Stance::Collide_Wall_P0_Start_End + 1;
constexpr uint16_t Collide_Wall_M2_Start_End                     = Stance::Collide_Wall_M1_Start_End + 1;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* 283 - 288                                                     01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define VER_ADJUSTMENTS_SEQ                                      125,   125,   125,   125,   125,   125, 
#define VER_ADJUSTMENTS_OFFSETS                                  0,1,   0,2,   0,3,   0,4,   0,5,   0,6,
constexpr uint16_t Vert_Adjustment_1_Start_End                   = Stance::Collide_Wall_M2_Start_End + 1;
constexpr uint16_t Vert_Adjustment_2_Start_End                   = Stance::Vert_Adjustment_1_Start_End + 1;
constexpr uint16_t Vert_Adjustment_3_Start_End                   = Stance::Vert_Adjustment_2_Start_End + 1;
constexpr uint16_t Vert_Adjustment_4_Start_End                   = Stance::Vert_Adjustment_3_Start_End + 1;
constexpr uint16_t Vert_Adjustment_5_Start_End                   = Stance::Vert_Adjustment_4_Start_End + 1;
constexpr uint16_t Vert_Adjustment_6_Start_End                   = Stance::Vert_Adjustment_5_Start_End + 1;

constexpr uint16_t  Upright_End_Climb        = 1253;
constexpr uint16_t  Upright_Turn             = 1255;
};


namespace Constants {

    constexpr uint8_t Item_Flash = 0;
    constexpr uint8_t Item_Sign = 1;
    constexpr uint8_t Item_ExitDoor = 2;
    constexpr uint8_t Items_DynamicRange = 2;
    constexpr uint8_t Items_Count = 40;
   

    constexpr uint8_t FrameRate = 45;
    constexpr uint8_t Animation_NumberOfFrames = 2;
    constexpr uint8_t NoItemFound = 255;

    constexpr uint8_t TileHeight = 31;
    constexpr uint8_t TileWidth = 12;
    constexpr uint8_t ScreenTopOffset = 1;
    constexpr uint8_t ScreenWidthInTiles = 10;
    constexpr int8_t CoordNone = 127;
    constexpr uint8_t TitleScreenScroll_Max = 87;

    constexpr int8_t InAir = 127;
    constexpr int8_t InAir_DoNotFall = 126;

    const uint8_t StanceToImageXRef[] PROGMEM  = {
        0, 
        RUN_START_SEQ
        RUN_REPEAT_SEQ
        UPRIGHT_SEQ
        RUNNING_JUMP_SEQ
        STANDING_TURN_SEQ
        RUNNING_TURN_SEQ
        STANDING_JUMP_SEQ
        STEP_FWD_ONE_SEQ
        STEP_FWD_TWO_SEQ
        SINGLE_STEP_SEQ
        STOPPING_SEQ
        CLIMBING_SEQ
        SMALL_STEP_SEQ
        JUMP_UP_A_SEQ
        JUMP_UP_DROP_A_SEQ
        STEP_CLIMBING_SEQ
        CROUCH_STAND_SEQ
        CROUCH_SEQ
        CROUCH_HOP_SEQ
        STEP_CLIMBINB_BLOCK_SEQ
        JUMP_UP_B_SEQ
        JUMP_UP_DROP_B_SEQ
        DRINK_TONIC_SEQ
        JUMP_UP_DROP_C_SEQ
        FALLING_INJURED_SEQ
        FALLING_DEAD_SEQ
        RUN_REPEAT_8_END_SEQ
        FALLING_DOWN_SEQ
        PICKUP_SWORD_SEQ
        FALLING_STEPWALKRUN_P2_6_10_SEQ
        FALLING_STEPWALKRUN_P0_4_8_SEQ
        FALLING_STEPWALKRUN_P1_5_9_SEQ
        FALLING_STEPWALKRUN_P3_7_11_SEQ
        LEAVE_GATE_SEQ
        COLLIDE_WALL_SEQ
        VER_ADJUSTMENTS_SEQ        
    };

    constexpr int8_t Prince_XOffset[] PROGMEM = {
        RUN_START_OFFSETS
        RUN_REPEAT_OFFSETS
        UPRIGHT_OFFSETS
        RUNNING_JUMP_OFFSETS
        STANDING_TURN_OFFSETS
        RUNNING_TURN_OFFSETS
        STANDING_JUMP_OFFSETS
        STEP_FWD_ONE_OFFSETS
        STEP_FWD_TWO_OFFSETS
        SINGLE_STEP_OFFSETS
        STOPPING_OFFSETS
        CLIMBING_OFFSETS
        SMALL_STEP_OFFSETS
        JUMP_UP_A_OFFSETS
        JUMP_UP_DROP_A_OFFSETS
        STEP_CLIMBING_OFFSETS
        CROUCH_STAND_OFFSETS
        CROUCH_OFFSETS
        CROUCH_HOP_OFFSETS
        STEP_CLIMBINB_BLOCK_OFFSETS
        JUMP_UP_B_OFFSETS
        JUMP_UP_DROP_B_OFFSETS
        DRINK_TONIC_OFFSETS
        JUMP_UP_DROP_C_OFFSETS
        FALLING_INJURED_OFFSETS
        FALLING_DEAD_OFFSETS
        RUN_REPEAT_8_END_OFFSETS
        FALLING_DOWN_OFFSETS
        PICKUP_SWORD_OFFSETS
        FALLING_STEPWALKRUN_P2_6_10_OFFSETS
        FALLING_STEPWALKRUN_P0_4_8_OFFSETS
        FALLING_STEPWALKRUN_P1_5_9_OFFSETS
        FALLING_STEPWALKRUN_P3_7_11_OFFSETS
        LEAVE_GATE_OFFSETS
        COLLIDE_WALL_OFFSETS
        VER_ADJUSTMENTS_OFFSETS       
    };

constexpr int8_t Prince_ImageDetails[] PROGMEM = {

/* 001 */  3, 2, -4,
/* 002 */  4, -1, -5,
/* 003 */  4, 0, -5,
/* 004 */  5, -4, -5,
/* 005 */  6, -3, -6,
/* 006 */  6, -2, -6,
/* 007 */  7, -4, -6,
/* 008 */  9, 6, 1,
/* 009 */  8, 5, 0,
/* 010 */  6, 2, -3,
/* 011 */  7, -2, -6,
/* 012 */  9, 7, 3,
/* 013 */  7, 6, 1,
/* 014 */  7, 2, -4,
/* 015 */  3, 1, -2,
/* 016 */  9, 8, 2,
/* 017 */  7, 0, -4,
/* 018 */  9, -5, -9,
/* 019 */  10, 10, 6,
/* 020 */  5, 1, -3,
/* 021 */  9, 127, 127,
/* 022 */  10, 127, 127,
/* 023 */  13, 127, 127,
/* 024 */  11, 127, 127,
/* 025 */  11, 127, 127,
/* 026 */  7, 127, 127,
/* 027 */  5, 2, -3,
/* 028 */  5, 1, -2,
/* 029 */  6, 3, -4,
/* 030 */  6, 3, -1,
/* 031 */  6, 5, 1,
/* 032 */  8, 8, 3,
/* 033 */  6, 4, -2,
/* 034 */  10, 10, 5,
/* 035 */  8, 6, 1,
/* 036 */  126, 126, 126,
/* 037 */  126, 126, 126,
/* 038 */  126, 126, 126,
/* 039 */  126, 126, 126,
/* 040 */  126, 126, 126,
/* 041 */  126, 126, 126,
/* 042 */  11, 10, 7,
/* 043 */  8, 7, 5,
/* 044 */  8, 7, 5,
/* 045 */  3, 2, -4,
/* 046 */  3, 1, -4,
/* 047 */  5, 2, -3,
/* 048 */  6, 0, -5,
/* 049 */  7, -1, -5,
/* 050 */  7, -2, -8,
/* 051 */  9, 127, 127,
/* 052 */  11, 127, 127,
/* 053 */  14, 127, 127,
/* 054 */  14, 127, 127,
/* 055 */  12, 127, 127,
/* 056 */  8, 5, 1,
/* 057 */  5, 3, -1,
/* 058 */  7, 5, 4,
/* 059 */  6, 6, 1,
/* 060 */  5, 5, 0,
/* 061 */  4, 4, -1,
/* 062 */  4, 4, -1,
/* 063 */  3, 2, -4,
/* 064 */  3, 2, -3,
/* 065 */  3, 2, -4,
/* 066 */  5, 5, 0,
/* 067 */  7, -4, -7,
/* 068 */  7, 6, 4,
/* 069 */  7, 7, 3,
/* 070 */  7, 7, 3,
/* 071 */  6, 6, 2,
/* 072 */  4, 4, 0,
/* 073 */  3, 2, -2,
/* 074 */  3, 2, -3,
/* 075 */  126, 126, 126,
/* 076 */  126, 126, 126,
/* 077 */  126, 126, 126,
/* 078 */  126, 126, 126,
/* 079 */  126, 126, 126,
/* 080 */  126, 126, 126,
/* 081 */  126, 126, 126,
/* 082 */  126, 126, 126,
/* 083 */  126, 126, 126,
/* 084 */  126, 126, 126,
/* 085 */  126, 126, 126,
/* 086 */  126, 126, 126,
/* 087 */  126, 126, 126,
/* 088 */  126, 126, 126,
/* 089 */  126, 126, 126,
/* 090 */  3, 2, -2,
/* 091 */  3, 3, -2,
/* 092 */  4, 3, -2,
/* 093 */  5, 3, -2,
/* 094 */  6, 4, 0,
/* 095 */  7, 4, 0,
/* 096 */  7, 4, 0,
/* 097 */  7, 3, -2,
/* 098 */  126, 126, 126,
/* 099 */  126, 126, 126,
/* 100 */  126, 126, 126,
/* 101 */  126, 126, 126,
/* 102 */  126, 126, 126,
/* 103 */  126, 126, 126,
/* 104 */  126, 126, 126,
/* 105 */  126, 126, 126,
/* 106 */  4, 2, -3,
/* 107 */  4, 1, -4,
/* 108 */  5, 1, -4,
/* 109 */  5, -1, -4,
/* 110 */  5, -2, -3,
/* 111 */  5, -2, -4,
/* 112 */  5, -2, -5,
/* 113 */  6, -5, -5,
/* 114 */  6, -3, -6,
/* 115 */  7, 1, -2,
/* 116 */  7, 3, -1,
/* 117 */  6, 3, -1,
/* 118 */  5, 2, -2,
/* 119 */  4, 2, -3,
/* 120 */  3, 3, -2,
/* 121 */  127, 127, 127,
/* 122 */  127, 127, 127,
/* 123 */  127, 127, 127,
/* 124 */  127, 127, 127,
/* 125 */  127, 127, 127,
/* 126 */  6, 1, -3,
/* 127 */  8, -1, -5,
/* 128 */  7, -1, -5,
/* 129 */  6, -2, -6,
/* 130 */  6, -2, -6,
/* 131 */  6, -2, -5,
/* 132 */  6, -2, -6,
/* 133 */  6, -2, -5,
/* 134 */  5, -1, -4,
/* 135 */  5, 1, -4,
/* 136 */  5, 2, -2,
/* 137 */  5, 1, -3,
/* 138 */  5, 2, -3,
/* 139 */  6, 3, -2,
/* 140 */  6, 4, -1,
/* 141 */  6, 4, -2,
/* 142 */  127, 127, 127,
/* 143 */  127, 127, 127,
/* 144 */  127, 127, 127,
/* 145 */  127, 127, 127,
/* 146 */  127, 127, 127,
/* 147 */  127, 127, 127,
/* 148 */  127, 127, 127,
/* 149 */  127, 127, 127,
/* 150 */  127, 127, 127,
/* 151 */  127, 127, 127,
/* 152 */  127, 127, 127,
/* 153 */  127, 127, 127,
/* 154 */  127, 127, 127,
/* 155 */  127, 127, 127,
/* 156 */  127, 127, 127,
/* 157 */  126, 126, 126,
/* 158 */  126, 126, 126,
/* 159 */  126, 126, 126,
/* 160 */  126, 126, 126,
/* 161 */  126, 126, 126,
/* 162 */  126, 126, 126,
/* 163 */  126, 126, 126,
/* 164 */  126, 126, 126,
/* 165 */  126, 126, 126,
/* 166 */  126, 126, 126,
/* 167 */  126, 126, 126,
/* 168 */  126, 126, 126,

};

constexpr int8_t VertAdjustments[] PROGMEM = {
/* 01 */ 1, 0, 0, 0, 0,
/* 02 */ 2, 0, 0, 0, 0,
/* 03 */ 3, 0, 0, 0, 0,
/* 04 */ 4, 0, 0, 0, 0,
/* 05 */ 5, 0, 0, 0, 0,
/* 06 */ 6, 0, 0, 0, 0,
/* 07 */ 3, 4, 0, 0, 0,
/* 08 */ 4, 4, 0, 0, 0,
/* 09 */ 4, 5, 0, 0, 0,
/* 10 */ 5, 5, 0, 0, 0,
/* 11 */ 5, 6, 0, 0, 0,
/* 12 */ 6, 6, 0, 0, 0,
/* 13 */ 4, 5, 4, 0, 0,
/* 14 */ 5, 4, 5, 0, 0,
/* 15 */ 5, 5, 5, 0, 0,
/* 16 */ 5, 6, 5, 0, 0,
/* 17 */ 6, 5, 6, 0, 0,
/* 18 */ 6, 6, 6, 0, 0,
/* 19 */ 5, 5, 5, 4, 0,
/* 20 */ 5, 5, 5, 5, 0,
/* 21 */ 6, 5, 5, 5, 0,
/* 22 */ 6, 5, 6, 5, 0,
/* 23 */ 6, 5, 6, 6, 0,
/* 24 */ 6, 6, 6, 6, 0,
/* 25 */ 5, 5, 5, 5, 5,
/* 26 */ 6, 5, 5, 5, 5,
/* 27 */ 5, 6, 5, 6, 5,
/* 28 */ 6, 5, 6, 5, 6,
/* 29 */ 6, 6, 5, 6, 6,
/* 30 */ 6, 6, 6, 6, 6,
};

}

enum GameState : uint8_t {
	SplashScreen_Init,
	SplashScreen,
	Title_Init,
	Title,
	Game_Init,
	Game,
    Game_StartLevel,
    Game_Over,
    Menu,
};

enum class Direction : uint8_t {
    None,
    Left,
    Right,
    Up,
    Down,
};

enum class Layer : uint8_t {
    Background,
    Foreground,
};

enum class Action : uint8_t {
    Step,
    SmallStep,
    RunStart,
    RunRepeat,
    RunJump_3,
    RunJump_2,
    RunJump_1,
    StandingJump,
    CrouchHop,
};

enum class CanJumpUpResult : uint8_t {
    None,
    Jump,
    StepThenJump,
    JumpThenFall,
    TurnThenJump,
    JumpDist10,
    JumpThenFall_CollapseFloor,             // Take this as gospel!
    StepThenJumpThenFall_CollapseFloor,     // This too!
    JumpThenFall_CollapseFloorAbove,             // Take this as gospel!
};

enum class CanClimbDownResult : uint8_t {
    None,
    ClimbDown,
    StepThenClimbDown,
    TurnThenClimbDown,
    StepThenTurnThenClimbDown,
};

enum class CanClimbDownPart2Result : uint8_t {
    None,
    Level_1,
    Falling,
    Level_1_Under,
};

enum class ItemType : uint8_t {
    /* 00 */ AnyItem,
    /* 01 */ ExitDoor,
    /* 02 */ Gate,               
    /* 03 */ Sword,
    /* 04 */ CollapsingFloor,
    /* 05 */ CollpasedFloor,
    /* 06 */ Potion_Small,
    /* 07 */ FloorButton1,
    /* 08 */ FloorButton2,
    /* 09 */ Skeleton,
    /* 10 */ Spikes,
    /* 97 */ None = 97,
    /* 98 */ Sign = 98,
    /* 99 */ Flash = 99,
};

enum class MenuOption : uint8_t {
    Resume,
    Save,
    Load,
    MainMenu,
};

enum class TitleScreenOptions : uint8_t {
    Play,
    Credits, 
};

enum class TitleScreenMode : uint8_t {
    Intro,
    Main,
    Credits, 
};

enum class WallTileResults : uint8_t {
    None,
    Normal,
    GateClosed, 
};

enum class SignType : uint8_t {
    PressA,
    GameOver,
};

