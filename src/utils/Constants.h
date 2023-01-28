
#pragma once

#define PRODUCTION_SETTINGS

#ifdef PRODUCTION_SETTINGS

    #define SAVE_MEMORY_USB
    #define _SAVE_MEMORY_OTHER
    #define _SAVE_MEMORY_SOUND
    #define _SAVE_MEMORY_ENEMY
    #define _SAVE_MEMORY_TITLE
    #define _ALT_B_BUTTON
    #define _GIVE_SWORD

    #define LEVEL_DATA_FROM_FX
    #define IMAGE_DATA_FROM_FX
    #define _SAVE_TO_FX
    #define STARTING_LEVEL 1

    #define _DEBUG

#else

    #define _SAVE_MEMORY_USB
    #define SAVE_MEMORY_OTHER
    #define SAVE_MEMORY_SOUND
    #define SAVE_MEMORY_ENEMY
    #define SAVE_MEMORY_TITLE
    #define _ALT_B_BUTTON
    #define _GIVE_SWORD

    #define _LEVEL_DATA_FROM_FX
    #define IMAGE_DATA_FROM_FX
    #define _SAVE_TO_FX
    #define STARTING_LEVEL 14

    #define DEBUG

#endif

#define DEBUG_PRINT    Serial.print
#define DEBUG_PRINTLN  Serial.println

#define DEBUG_ONSCREEN_DETAILS
#define _DEBUG_ONSCREEN_DETAILS_MIN

#define _DEBUG_PRINCE_DETAILS
#define _DEBUG_PRINCE_STACK
#define _DEBUG_PRINT_ACTION
#define _DEBUG_LEVEL_LOAD_MAP
#define _DEBUG_GET_TILE
#define _DEBUG_PRINCE_RENDERING
#define _DEBUG_IMAGE_DETAILS

#define _DEBUG_ACTION_CANMOVEFORWARD
#define _DEBUG_ACTION_CANJUMPUP
#define _DEBUG_ACTION_CANJUMPUP_PART2
#define _DEBUG_ACTION_CANCLIMBDOWN
#define _DEBUG_ACTION_CANCLIMBDOWN_PART2
#define _DEBUG_ACTION_CANFALL
#define _DEBUG_ACTION_CANFALLSOMEMORE
#define _DEBUG_ACTION_COLLIDEWITHWALL
#define _DEBUG_ACTION_FALLING
#define DEBUG_ACTION_CANSTANDINGJUMP
#define DEBUG_ACTION_CANSTANDINGJUMP_DETAIL
#define _DEBUG_ACTION_CANRUNNINGJUMP
#define _DEBUG_ACTION_CANRUNNINGJUMP_DETAIL
#define DEBUG_ISGROUNDTILE


//-------------------------------------------------------------------------------------

namespace Stance {

constexpr uint16_t None                                          = 0;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/*                                                               01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define CROUCH_SEQ                                               126,   109,   110,   
#define CROUCH_OFFSETS                                           0,0,   0,0,   0,0, 
constexpr uint16_t Crouch_1_Start                                = Stance::None + 1;
constexpr uint16_t Crouch_2                                      = Stance::Crouch_1_Start + 1;
constexpr uint16_t Crouch_3_End                                  = Stance::Crouch_2 + 1;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/*                                                               01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define RUN_START_SEQ                                            1,     2,     3,     4,     5,     6, 
#define RUN_START_OFFSETS                                        0,0,   1,0,   1,0,   1,0,   2,0,   2,0,
constexpr uint16_t Run_Start_1_Start                             = Stance::Crouch_3_End + 1;
constexpr uint16_t Run_Start_2                                   = Stance::Run_Start_1_Start + 1;
constexpr uint16_t Run_Start_3                                   = Stance::Run_Start_2 + 1;
constexpr uint16_t Run_Start_4                                   = Stance::Run_Start_3 + 1;
constexpr uint16_t Run_Start_5                                   = Stance::Run_Start_4 + 1;
constexpr uint16_t Run_Start_6_End                               = Stance::Run_Start_5 + 1;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/*                                                              01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
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
/*                                                               01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define UPRIGHT_SEQ                                              15,
#define UPRIGHT_OFFSETS                                          0,0,
constexpr uint16_t Upright                                       = Stance::Run_Repeat_8_End + 1;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/*                                                               01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define RUNNING_JUMP_SEQ                                         16,    17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
#define RUNNING_JUMP_OFFSETS                                     2,0,   3,0,   4,0,   4,0,   5,0,   6,0,   6,0,   6,-2,  5,0,   3,1,   2,1,
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
/* 030 - 036                                                     01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define RUNNING_JUMP_SHORT_SEQ                                   20,    21,    22,    23,    24,    25,    26,
#define RUNNING_JUMP_SHORT_OFFSETS                               6,0,   6,0,   6,0,   6,-2,  6,-2,  5,3,   2,1,
constexpr uint16_t Running_Jump_Short_1_Start                    = Stance::Running_Jump_11_End + 1;
constexpr uint16_t Running_Jump_Short_2                          = Stance::Running_Jump_Short_1_Start + 1;
constexpr uint16_t Running_Jump_Short_3                          = Stance::Running_Jump_Short_2 + 1;
constexpr uint16_t Running_Jump_Short_4                          = Stance::Running_Jump_Short_3 + 1;
constexpr uint16_t Running_Jump_Short_5                          = Stance::Running_Jump_Short_4 + 1;
constexpr uint16_t Running_Jump_Short_6                          = Stance::Running_Jump_Short_5 + 1;
constexpr uint16_t Running_Jump_Short_7_End                      = Stance::Running_Jump_Short_6 + 1;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/*                                                               01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define STANDING_TURN_SEQ                                        27,    28,    29,    30,    31,
#define STANDING_TURN_OFFSETS                                    0,0,   -1,0,  -1,0,  2,0,   0,0,
constexpr uint16_t Standing_Turn_1_Start                         = Stance::Running_Jump_Short_7_End + 1; 
constexpr uint16_t Standing_Turn_2                               = Stance::Standing_Turn_1_Start + 1;
constexpr uint16_t Standing_Turn_3                               = Stance::Standing_Turn_2 + 1;
constexpr uint16_t Standing_Turn_4                               = Stance::Standing_Turn_3 + 1; 
constexpr uint16_t Standing_Turn_5_End                           = Stance::Standing_Turn_4 + 1; 


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/*                                                               01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
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
/*                                                               01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
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
/*                                                               01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define STANDING_JUMP_MED_SEQ                                    45,    46,    47,    48,    49,    50,    51,    52,    55,    56,    57,    58,    59,    60,    61,    62,
#define STANDING_JUMP_MED_OFFSETS                                0,0,   0,0,   2,0,   2,0,   2,0,   3,0,   3,0,   3,0,   3,0,   3,0,   3,0,   2,0,   2,0,   0,0,   0,0,   0,0, 
constexpr uint16_t Standing_Jump_Med_1_Start                     = Stance::Standing_Jump_18_End + 1;
constexpr uint16_t Standing_Jump_Med_2                           = Stance::Standing_Jump_Med_1_Start + 1;
constexpr uint16_t Standing_Jump_Med_3                           = Stance::Standing_Jump_Med_2 + 1;
constexpr uint16_t Standing_Jump_Med_4                           = Stance::Standing_Jump_Med_3 + 1;
constexpr uint16_t Standing_Jump_Med_5                           = Stance::Standing_Jump_Med_4 + 1;
constexpr uint16_t Standing_Jump_Med_6                           = Stance::Standing_Jump_Med_5 + 1;
constexpr uint16_t Standing_Jump_Med_7                           = Stance::Standing_Jump_Med_6 + 1;
constexpr uint16_t Standing_Jump_Med_8                           = Stance::Standing_Jump_Med_7 + 1;
constexpr uint16_t Standing_Jump_Med_9                           = Stance::Standing_Jump_Med_8 + 1;
constexpr uint16_t Standing_Jump_Med_10                          = Stance::Standing_Jump_Med_9 + 1;
constexpr uint16_t Standing_Jump_Med_11                          = Stance::Standing_Jump_Med_10 + 1;
constexpr uint16_t Standing_Jump_Med_12                          = Stance::Standing_Jump_Med_11 + 1;
constexpr uint16_t Standing_Jump_Med_13                          = Stance::Standing_Jump_Med_12 + 1;
constexpr uint16_t Standing_Jump_Med_14                          = Stance::Standing_Jump_Med_13 + 1;
constexpr uint16_t Standing_Jump_Med_15                          = Stance::Standing_Jump_Med_14 + 1;
constexpr uint16_t Standing_Jump_Med_16_End                      = Stance::Standing_Jump_Med_15 + 1;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/*                                                               01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define STANDING_JUMP_SHORT_2_SEQ                                45,    46,    47,    48,    49,    50,    51,    52,    55,    56,    57,    58,    59,    60,    61,    62,
#define STANDING_JUMP_SHORT_2_OFFSETS                            0,0,   0,0,   2,0,   2,0,   2,0,   2,0,   1,0,   2,0,   2,0,   3,0,   3,0,   2,0,   1,0,   1,0,   1,0,   0,0, 
constexpr uint16_t Standing_Jump_Short_2_1_Start                 = Stance::Standing_Jump_Med_16_End + 1;
constexpr uint16_t Standing_Jump_Short_2_2                       = Stance::Standing_Jump_Short_2_1_Start + 1;
constexpr uint16_t Standing_Jump_Short_2_3                       = Stance::Standing_Jump_Short_2_2 + 1;
constexpr uint16_t Standing_Jump_Short_2_4                       = Stance::Standing_Jump_Short_2_3 + 1;
constexpr uint16_t Standing_Jump_Short_2_5                       = Stance::Standing_Jump_Short_2_4 + 1;
constexpr uint16_t Standing_Jump_Short_2_6                       = Stance::Standing_Jump_Short_2_5 + 1;
constexpr uint16_t Standing_Jump_Short_2_7                       = Stance::Standing_Jump_Short_2_6 + 1;
constexpr uint16_t Standing_Jump_Short_2_8                       = Stance::Standing_Jump_Short_2_7 + 1;
constexpr uint16_t Standing_Jump_Short_2_9                       = Stance::Standing_Jump_Short_2_8 + 1;
constexpr uint16_t Standing_Jump_Short_2_10                      = Stance::Standing_Jump_Short_2_9 + 1;
constexpr uint16_t Standing_Jump_Short_2_11                      = Stance::Standing_Jump_Short_2_10 + 1;
constexpr uint16_t Standing_Jump_Short_2_12                      = Stance::Standing_Jump_Short_2_11 + 1;
constexpr uint16_t Standing_Jump_Short_2_13                      = Stance::Standing_Jump_Short_2_12 + 1;
constexpr uint16_t Standing_Jump_Short_2_14                      = Stance::Standing_Jump_Short_2_13 + 1;
constexpr uint16_t Standing_Jump_Short_2_15                      = Stance::Standing_Jump_Short_2_14 + 1;
constexpr uint16_t Standing_Jump_Short_2_16_End                  = Stance::Standing_Jump_Short_2_15 + 1;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/*                                                               01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define STANDING_JUMP_DROPLVL_SEQ                                45,    46,    47,    48,    49,    50,    51,    52,    53,    54,    121,   122,   123,   124,   125,   126,
#define STANDING_JUMP_DROPLVL_OFFSETS                            0,0,   0,0,   2,0,   2,0,   2,0,   2,0,   3,0,   3,0,   2,0,   2,0,   6,6,   3,5,   3,5,   3,5,   2,5,   1,5,
constexpr uint16_t Standing_Jump_DropLvl_1_Start                 = Stance::Standing_Jump_Short_2_16_End + 1;
constexpr uint16_t Standing_Jump_DropLvl_2                       = Stance::Standing_Jump_DropLvl_1_Start + 1;
constexpr uint16_t Standing_Jump_DropLvl_3                       = Stance::Standing_Jump_DropLvl_2 + 1;
constexpr uint16_t Standing_Jump_DropLvl_4                       = Stance::Standing_Jump_DropLvl_3 + 1;
constexpr uint16_t Standing_Jump_DropLvl_5                       = Stance::Standing_Jump_DropLvl_4 + 1;
constexpr uint16_t Standing_Jump_DropLvl_6                       = Stance::Standing_Jump_DropLvl_5 + 1;
constexpr uint16_t Standing_Jump_DropLvl_7                       = Stance::Standing_Jump_DropLvl_6 + 1;
constexpr uint16_t Standing_Jump_DropLvl_8                       = Stance::Standing_Jump_DropLvl_7 + 1;
constexpr uint16_t Standing_Jump_DropLvl_9                       = Stance::Standing_Jump_DropLvl_8 + 1;
constexpr uint16_t Standing_Jump_DropLvl_10                      = Stance::Standing_Jump_DropLvl_9 + 1;
constexpr uint16_t Standing_Jump_DropLvl_11                      = Stance::Standing_Jump_DropLvl_10 + 1;
constexpr uint16_t Standing_Jump_DropLvl_12                      = Stance::Standing_Jump_DropLvl_11 + 1;
constexpr uint16_t Standing_Jump_DropLvl_13                      = Stance::Standing_Jump_DropLvl_12 + 1;
constexpr uint16_t Standing_Jump_DropLvl_14                      = Stance::Standing_Jump_DropLvl_13 + 1;
constexpr uint16_t Standing_Jump_DropLvl_15                      = Stance::Standing_Jump_DropLvl_14 + 1;
constexpr uint16_t Standing_Jump_DropLvl_16_End                  = Stance::Standing_Jump_DropLvl_15 + 1;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/*                                                               01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define SINGLE_STEP_SEQ                                          63,    64,    65,    66,    71,    72,    73,    74,
#define SINGLE_STEP_OFFSETS                                      1,0,   1,0,   1,0,   1,0,   1,0,   1,0,   1,0,   1,0, 
constexpr uint16_t Single_Step_1_Start                           = Stance::Standing_Jump_DropLvl_16_End + 1;
constexpr uint16_t Single_Step_2                                 = Stance::Single_Step_1_Start + 1;
constexpr uint16_t Single_Step_3                                 = Stance::Single_Step_2 + 1;
constexpr uint16_t Single_Step_4                                 = Stance::Single_Step_3 + 1;
constexpr uint16_t Single_Step_5                                 = Stance::Single_Step_4 + 1;
constexpr uint16_t Single_Step_6                                 = Stance::Single_Step_5 + 1;
constexpr uint16_t Single_Step_7                                 = Stance::Single_Step_6 + 1;
constexpr uint16_t Single_Step_8_End                             = Stance::Single_Step_7 + 1;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/*                                                               01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define STOPPING_SEQ                                             5,     4,     3,     2,     1, 
#define STOPPING_OFFSETS                                         0,0,   0,0,   0,0,   0,0,   0,0,
constexpr uint16_t Stopping_1_Start                              = Stance::Single_Step_8_End + 1;
constexpr uint16_t Stopping_2                                    = Stance::Stopping_1_Start + 1;
constexpr uint16_t Stopping_3                                    = Stance::Stopping_2 + 1;
constexpr uint16_t Stopping_4                                    = Stance::Stopping_3 + 1;
constexpr uint16_t Stopping_5_End                                = Stance::Stopping_4 + 1;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/*                                                               01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
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
/*                                                               01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define SMALL_STEP_SEQ                                           63,    64,    65,    72,    73,    74,  
#define SMALL_STEP_OFFSETS                                       1,0,   1,0,   1,0,   1,0,   0,0,   0,0, 
constexpr uint16_t Small_Step_1_Start                            = Stance::Climbing_15_End + 1;
constexpr uint16_t Small_Step_2                                  = Stance::Small_Step_1_Start + 1;
constexpr uint16_t Small_Step_3                                  = Stance::Small_Step_2 + 1;
constexpr uint16_t Small_Step_4                                  = Stance::Small_Step_3 + 1;
constexpr uint16_t Small_Step_5                                  = Stance::Small_Step_4 + 1;
constexpr uint16_t Small_Step_6_End                              = Stance::Small_Step_5 + 1;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/*                                                               01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define JUMP_UP_A_SEQ                                            90,    91,    92,    93,    94,    95,    96,    97,    98,    99,    100,   101,   102,   103,
#define JUMP_UP_A_OFFSETS                                        0,0,   0,0,   0,0,   -1,0,  -1,0,  0,0,   0,0,   0,0,   0,0,   1,0,   1,0,   0,0,   0,0,   0,0,                                             
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
/* Used when jumping up from a lower ledge to an upper one, such as in the left handside of platforms in level one.  The offset of x = -4 allows a player to jump 'straight' up to a ledge.              */
/*                                                               01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define JUMP_UP_B_SEQ                                            90,    91,    92,    93,    94,    95,    96,    97,    98,    99,    100,   101,   102,   103,    
#define JUMP_UP_B_OFFSETS                                        0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   -1,0,  -1,0,  -1,0,  -1,0,  0,0,
constexpr uint16_t Jump_Up_B_1_Start                             = Stance::Jump_Up_A_14_End + 1;
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
/*                                                               01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define JUMP_UP_DROP_A_SEQ                                       104,   105,   106,   107,   108,
#define JUMP_UP_DROP_A_OFFSETS                                   0,0,   0,0,   0,0,   0,0,   0,0,
constexpr uint16_t Jump_Up_Drop_A_1_Start                        = Stance::Jump_Up_B_14_End + 1;  // Drop down to Pos 2
constexpr uint16_t Jump_Up_Drop_A_2                              = Stance::Jump_Up_Drop_A_1_Start + 1;
constexpr uint16_t Jump_Up_Drop_A_3                              = Stance::Jump_Up_Drop_A_2 + 1;
constexpr uint16_t Jump_Up_Drop_A_4                              = Stance::Jump_Up_Drop_A_3 + 1;
constexpr uint16_t Jump_Up_Drop_A_5_End                          = Stance::Jump_Up_Drop_A_4 + 1;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* Used when dropping from an upper ledge to one directly below. The offset of x = +4 allows a player to land directly underneath. Paired with / opposite of Jump_Up_B sequence.                         */
/*                                                               01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define JUMP_UP_DROP_B_SEQ                                       104,   105,   106,   107,   108,   // Drop to position 10
#define JUMP_UP_DROP_B_OFFSETS                                   1,0,   1,0,   1,0,   1,0,   0,0, 
constexpr uint16_t Jump_Up_Drop_B_1_Start                        = Stance::Jump_Up_Drop_A_5_End + 1;  // Drop down to Pos 10
constexpr uint16_t Jump_Up_Drop_B_2                              = Stance::Jump_Up_Drop_B_1_Start + 1;
constexpr uint16_t Jump_Up_Drop_B_3                              = Stance::Jump_Up_Drop_B_2 + 1;
constexpr uint16_t Jump_Up_Drop_B_4                              = Stance::Jump_Up_Drop_B_3 + 1;
constexpr uint16_t Jump_Up_Drop_B_5_End                          = Stance::Jump_Up_Drop_B_4 + 1;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/*                                                               01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define JUMP_UP_DROP_C_SEQ                                       104,   105,   106,   107,   108,   // Climb down, drop straight down 31 px 
#define JUMP_UP_DROP_C_OFFSETS                                   0,6,   0,6,   0,6,   0,6,   0,7,
constexpr uint16_t Jump_Up_Drop_C_1_Start                        = Stance::Jump_Up_Drop_B_5_End + 1;  // Drop down to Pos 2 (two levels)
constexpr uint16_t Jump_Up_Drop_C_2                              = Stance::Jump_Up_Drop_C_1_Start + 1;
constexpr uint16_t Jump_Up_Drop_C_3                              = Stance::Jump_Up_Drop_C_2 + 1;
constexpr uint16_t Jump_Up_Drop_C_4                              = Stance::Jump_Up_Drop_C_3 + 1;
constexpr uint16_t Jump_Up_Drop_C_5_End                          = Stance::Jump_Up_Drop_C_4 + 1;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/*                                                               01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define STEP_CLIMBING_SEQ                                        75,    76,    77,    78,    79,    80,    81,    82,    83,    84,    85,    86,    87,    88,    89,  
#define STEP_CLIMBING_OFFSETS                                    0,-4,  0,-4,  0,-2,  0,-3,  0,-3,  0,-3,  0,-4,  0,-4,  0,-1,  1,-1,  1,0,   0,-1,  1,-1,  1,0,   0,0, 
constexpr uint16_t Step_Climbing_1_Start                         = Stance::Jump_Up_Drop_C_5_End + 1;  // Climb up / down from a ledge (second part)
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
/*                                                               01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
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
/*                                                               01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define CROUCH_HOP_SEQ                                           110,   111,   112,   113,   112,   111,   110, 
#define CROUCH_HOP_OFFSETS                                       0,0,   1,0,   1,0,   1,0,   1,0,   0,0,   0,0,
constexpr uint16_t Crouch_HOP_1_Start                            = Stance::Crouch_Stand_12_End + 1;
constexpr uint16_t Crouch_HOP_2                                  = Stance::Crouch_HOP_1_Start + 1;
constexpr uint16_t Crouch_HOP_3                                  = Stance::Crouch_HOP_2 + 1;
constexpr uint16_t Crouch_HOP_4                                  = Stance::Crouch_HOP_3 + 1;
constexpr uint16_t Crouch_HOP_5                                  = Stance::Crouch_HOP_4 + 1;
constexpr uint16_t Crouch_HOP_6                                  = Stance::Crouch_HOP_5 + 1;
constexpr uint16_t Crouch_HOP_7_End                              = Stance::Crouch_HOP_6 + 1;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* Used when climbing up from a hanging position on a ledge where the climb is blocked by a gate or other obstacle                                                                                       */
/*                                                               01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
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
/* Drink the tonic!  Drink_Tonic_Small_14 triggers a health increase.                                                                                                                                          */
/*                                                               01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define DRINK_TONIC_SMALL_SEQ                                    127,   128,   129,   130,   131,   132,   133,   134,   135,   136,   137,   138,   139,   140,   141,  
#define DRINK_TONIC_SMALL_OFFSETS                                0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,
constexpr uint16_t Drink_Tonic_Small_1_Start                     = Stance::Step_Climbing_Block_9_End + 1; 
constexpr uint16_t Drink_Tonic_Small_2                           = Stance::Drink_Tonic_Small_1_Start + 1;
constexpr uint16_t Drink_Tonic_Small_3                           = Stance::Drink_Tonic_Small_2 + 1;
constexpr uint16_t Drink_Tonic_Small_4                           = Stance::Drink_Tonic_Small_3 + 1;
constexpr uint16_t Drink_Tonic_Small_5                           = Stance::Drink_Tonic_Small_4 + 1;
constexpr uint16_t Drink_Tonic_Small_6                           = Stance::Drink_Tonic_Small_5 + 1;
constexpr uint16_t Drink_Tonic_Small_7                           = Stance::Drink_Tonic_Small_6 + 1;
constexpr uint16_t Drink_Tonic_Small_8                           = Stance::Drink_Tonic_Small_7 + 1;
constexpr uint16_t Drink_Tonic_Small_9                           = Stance::Drink_Tonic_Small_8 + 1;
constexpr uint16_t Drink_Tonic_Small_10                          = Stance::Drink_Tonic_Small_9 + 1;
constexpr uint16_t Drink_Tonic_Small_11                          = Stance::Drink_Tonic_Small_10 + 1;
constexpr uint16_t Drink_Tonic_Small_12                          = Stance::Drink_Tonic_Small_11 + 1;
constexpr uint16_t Drink_Tonic_Small_13                          = Stance::Drink_Tonic_Small_12 + 1;
constexpr uint16_t Drink_Tonic_Small_14                          = Stance::Drink_Tonic_Small_13 + 1;
constexpr uint16_t Drink_Tonic_Small_15_End                      = Stance::Drink_Tonic_Small_14 + 1;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* Drink the tonic!  Drink_Tonic_Large_14 triggers a health and max health increase.                                                                                                                                          */
/*                                                               01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define DRINK_TONIC_LARGE_SEQ                                    127,   128,   129,   130,   131,   132,   133,   134,   135,   136,   137,   138,   139,   140,   141,  
#define DRINK_TONIC_LARGE_OFFSETS                                0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,
constexpr uint16_t Drink_Tonic_Large_1_Start                     = Stance::Drink_Tonic_Small_15_End + 1; 
constexpr uint16_t Drink_Tonic_Large_2                           = Stance::Drink_Tonic_Large_1_Start + 1;
constexpr uint16_t Drink_Tonic_Large_3                           = Stance::Drink_Tonic_Large_2 + 1;
constexpr uint16_t Drink_Tonic_Large_4                           = Stance::Drink_Tonic_Large_3 + 1;
constexpr uint16_t Drink_Tonic_Large_5                           = Stance::Drink_Tonic_Large_4 + 1;
constexpr uint16_t Drink_Tonic_Large_6                           = Stance::Drink_Tonic_Large_5 + 1;
constexpr uint16_t Drink_Tonic_Large_7                           = Stance::Drink_Tonic_Large_6 + 1;
constexpr uint16_t Drink_Tonic_Large_8                           = Stance::Drink_Tonic_Large_7 + 1;
constexpr uint16_t Drink_Tonic_Large_9                           = Stance::Drink_Tonic_Large_8 + 1;
constexpr uint16_t Drink_Tonic_Large_10                          = Stance::Drink_Tonic_Large_9 + 1;
constexpr uint16_t Drink_Tonic_Large_11                          = Stance::Drink_Tonic_Large_10 + 1;
constexpr uint16_t Drink_Tonic_Large_12                          = Stance::Drink_Tonic_Large_11 + 1;
constexpr uint16_t Drink_Tonic_Large_13                          = Stance::Drink_Tonic_Large_12 + 1;
constexpr uint16_t Drink_Tonic_Large_14                          = Stance::Drink_Tonic_Large_13 + 1;
constexpr uint16_t Drink_Tonic_Large_15_End                      = Stance::Drink_Tonic_Large_14 + 1;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* Drink the tonic!  Drink_Tonic_Large_14 triggers a health and max health increase.                                                                                                                                          */
/*                                                               01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define DRINK_TONIC_POISON_SEQ                                   127,   128,   129,   130,   131,   132,   133,   134,   135,   136,   137,   138,   139,   140,   141,  
#define DRINK_TONIC_POISON_OFFSETS                               0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,
constexpr uint16_t Drink_Tonic_Poison_1_Start                    = Stance::Drink_Tonic_Large_15_End + 1; 
constexpr uint16_t Drink_Tonic_Poison_2                          = Stance::Drink_Tonic_Poison_1_Start + 1;
constexpr uint16_t Drink_Tonic_Poison_3                          = Stance::Drink_Tonic_Poison_2 + 1;
constexpr uint16_t Drink_Tonic_Poison_4                          = Stance::Drink_Tonic_Poison_3 + 1;
constexpr uint16_t Drink_Tonic_Poison_5                          = Stance::Drink_Tonic_Poison_4 + 1;
constexpr uint16_t Drink_Tonic_Poison_6                          = Stance::Drink_Tonic_Poison_5 + 1;
constexpr uint16_t Drink_Tonic_Poison_7                          = Stance::Drink_Tonic_Poison_6 + 1;
constexpr uint16_t Drink_Tonic_Poison_8                          = Stance::Drink_Tonic_Poison_7 + 1;
constexpr uint16_t Drink_Tonic_Poison_9                          = Stance::Drink_Tonic_Poison_8 + 1;
constexpr uint16_t Drink_Tonic_Poison_10                         = Stance::Drink_Tonic_Poison_9 + 1;
constexpr uint16_t Drink_Tonic_Poison_11                         = Stance::Drink_Tonic_Poison_10 + 1;
constexpr uint16_t Drink_Tonic_Poison_12                         = Stance::Drink_Tonic_Poison_11 + 1;
constexpr uint16_t Drink_Tonic_Poison_13                         = Stance::Drink_Tonic_Poison_12 + 1;
constexpr uint16_t Drink_Tonic_Poison_14                         = Stance::Drink_Tonic_Poison_13 + 1;
constexpr uint16_t Drink_Tonic_Poison_15_End                     = Stance::Drink_Tonic_Poison_14 + 1;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* Drink the tonic!  Drink_Tonic_Small_14 triggers a health increase.                                                                                                                                          */
/*                                                               01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define DRINK_TONIC_FLOAT_SEQ                                    127,   128,   129,   130,   131,   132,   133,   134,   135,   136,   137,   138,   139,   140,   141,  
#define DRINK_TONIC_FLOAT_OFFSETS                                0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,
constexpr uint16_t Drink_Tonic_Float_1_Start                     = Stance::Drink_Tonic_Poison_15_End + 1; 
constexpr uint16_t Drink_Tonic_Float_2                           = Stance::Drink_Tonic_Float_1_Start + 1;
constexpr uint16_t Drink_Tonic_Float_3                           = Stance::Drink_Tonic_Float_2 + 1;
constexpr uint16_t Drink_Tonic_Float_4                           = Stance::Drink_Tonic_Float_3 + 1;
constexpr uint16_t Drink_Tonic_Float_5                           = Stance::Drink_Tonic_Float_4 + 1;
constexpr uint16_t Drink_Tonic_Float_6                           = Stance::Drink_Tonic_Float_5 + 1;
constexpr uint16_t Drink_Tonic_Float_7                           = Stance::Drink_Tonic_Float_6 + 1;
constexpr uint16_t Drink_Tonic_Float_8                           = Stance::Drink_Tonic_Float_7 + 1;
constexpr uint16_t Drink_Tonic_Float_9                           = Stance::Drink_Tonic_Float_8 + 1;
constexpr uint16_t Drink_Tonic_Float_10                          = Stance::Drink_Tonic_Float_9 + 1;
constexpr uint16_t Drink_Tonic_Float_11                          = Stance::Drink_Tonic_Float_10 + 1;
constexpr uint16_t Drink_Tonic_Float_12                          = Stance::Drink_Tonic_Float_11 + 1;
constexpr uint16_t Drink_Tonic_Float_13                          = Stance::Drink_Tonic_Float_12 + 1;
constexpr uint16_t Drink_Tonic_Float_14                          = Stance::Drink_Tonic_Float_13 + 1;
constexpr uint16_t Drink_Tonic_Float_15_End                      = Stance::Drink_Tonic_Float_14 + 1;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/*                                                               01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define FALLING_INJURED_SEQ                                      125,   126, 
#define FALLING_INJURED_OFFSETS                                  0,0,   0,0,
constexpr uint16_t Falling_Injured_1_Start                       = Stance::Drink_Tonic_Float_15_End + 1;  // Climbing down, falling two levels
constexpr uint16_t Falling_Injured_2_End                         = Stance::Falling_Injured_1_Start + 1;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/*                                                               01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define FALLING_DEAD_SEQ                                         125,   126,   142,
#define FALLING_DEAD_OFFSETS                                     0,0,   0,0,   0,0,
constexpr uint16_t Falling_Dead_1_Start                         = Stance::Falling_Injured_2_End + 1;  // Climbing down, fall to death
constexpr uint16_t Falling_Dead_2                               = Stance::Falling_Dead_1_Start + 1;
constexpr uint16_t Falling_Dead_3_End                           = Stance::Falling_Dead_2 + 1;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/*                                                               01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define RUN_REPEAT_8_END_SEQ                                     14, 
#define RUN_REPEAT_8_END_OFFSETS                                 4,0,
constexpr uint16_t Run_Repeat_8_End_Turn                         = Stance::Falling_Dead_3_End + 1;  // Single entry to allow x correction


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/*                                                               01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define PICKUP_SWORD_SEQ                                         143,   144,   145,   145,   145,   146,   147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
#define PICKUP_SWORD_OFFSETS                                     0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,
constexpr uint16_t Pickup_Sword_1_Start                          = Stance::Run_Repeat_8_End_Turn + 1;
constexpr uint16_t Pickup_Sword_2                                = Stance::Pickup_Sword_1_Start + 1;
constexpr uint16_t Pickup_Sword_3                                = Stance::Pickup_Sword_2 + 1;
constexpr uint16_t Pickup_Sword_4                                = Stance::Pickup_Sword_3 + 1;
constexpr uint16_t Pickup_Sword_5                                = Stance::Pickup_Sword_4 + 1;
constexpr uint16_t Pickup_Sword_6                                = Stance::Pickup_Sword_5 + 1;
constexpr uint16_t Pickup_Sword_7_PutAway                        = Stance::Pickup_Sword_6 + 1;
constexpr uint16_t Pickup_Sword_8                                = Stance::Pickup_Sword_7_PutAway + 1;
constexpr uint16_t Pickup_Sword_9                                = Stance::Pickup_Sword_8 + 1;
constexpr uint16_t Pickup_Sword_10                               = Stance::Pickup_Sword_9 + 1;
constexpr uint16_t Pickup_Sword_11                               = Stance::Pickup_Sword_10 + 1;
constexpr uint16_t Pickup_Sword_12                               = Stance::Pickup_Sword_11 + 1;
constexpr uint16_t Pickup_Sword_13                               = Stance::Pickup_Sword_12 + 1;
constexpr uint16_t Pickup_Sword_14                               = Stance::Pickup_Sword_13 + 1;
constexpr uint16_t Pickup_Sword_15                               = Stance::Pickup_Sword_14 + 1;
constexpr uint16_t Pickup_Sword_16_End                           = Stance::Pickup_Sword_15 + 1;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/*                                                               01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define FALLING_STEPWALKRUN_P0_4_8_SEQ                           121,   122,   123,   124,   125,   126,
#define FALLING_STEPWALKRUN_P0_4_8_OFFSETS                       2,6,   2,5,   1,5,   1,5,   0,5,   0,5,  
constexpr uint16_t Falling_StepWalkRun_P0_4_8_1_Start            = Stance::Pickup_Sword_16_End + 1;
constexpr uint16_t Falling_StepWalkRun_P0_4_8_2                  = Stance::Falling_StepWalkRun_P0_4_8_1_Start + 1;
constexpr uint16_t Falling_StepWalkRun_P0_4_8_3                  = Stance::Falling_StepWalkRun_P0_4_8_2 + 1;
constexpr uint16_t Falling_StepWalkRun_P0_4_8_4                  = Stance::Falling_StepWalkRun_P0_4_8_3 + 1;
constexpr uint16_t Falling_StepWalkRun_P0_4_8_5_Check_CanFall    = Stance::Falling_StepWalkRun_P0_4_8_4 + 1;
constexpr uint16_t Falling_StepWalkRun_P0_4_8_6_End              = Stance::Falling_StepWalkRun_P0_4_8_5_Check_CanFall + 1;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/*                                                               01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define FALLING_STEPWALKRUN_P1_5_9_SEQ                           121,   122,   123,   124,   125,   126,
#define FALLING_STEPWALKRUN_P1_5_9_OFFSETS                       2,6,   2,5,   2,5,   1,5,   0,5,   0,5,
constexpr uint16_t Falling_StepWalkRun_P1_5_9_1_Start            = Stance::Falling_StepWalkRun_P0_4_8_6_End + 1;
constexpr uint16_t Falling_StepWalkRun_P1_5_9_2                  = Stance::Falling_StepWalkRun_P1_5_9_1_Start + 1;
constexpr uint16_t Falling_StepWalkRun_P1_5_9_3                  = Stance::Falling_StepWalkRun_P1_5_9_2 + 1;
constexpr uint16_t Falling_StepWalkRun_P1_5_9_4                  = Stance::Falling_StepWalkRun_P1_5_9_3 + 1;
constexpr uint16_t Falling_StepWalkRun_P1_5_9_5_Check_CanFall    = Stance::Falling_StepWalkRun_P1_5_9_4 + 1;
constexpr uint16_t Falling_StepWalkRun_P1_5_9_6_End              = Stance::Falling_StepWalkRun_P1_5_9_5_Check_CanFall + 1;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/*                                                               01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define FALLING_STEPWALKRUN_P2_6_10_SEQ                          121,   122,   123,   124,   125,   126,
#define FALLING_STEPWALKRUN_P2_6_10_OFFSETS                      2,6,   2,5,   2,5,   1,5,   1,5,   0,5, 
constexpr uint16_t Falling_StepWalkRun_P2_6_10_1_Start           = Stance::Falling_StepWalkRun_P1_5_9_6_End + 1;
constexpr uint16_t Falling_StepWalkRun_P2_6_10_2                 = Stance::Falling_StepWalkRun_P2_6_10_1_Start + 1;
constexpr uint16_t Falling_StepWalkRun_P2_6_10_3                 = Stance::Falling_StepWalkRun_P2_6_10_2 + 1;
constexpr uint16_t Falling_StepWalkRun_P2_6_10_4                 = Stance::Falling_StepWalkRun_P2_6_10_3 + 1;
constexpr uint16_t Falling_StepWalkRun_P2_6_10_5_Check_CanFall   = Stance::Falling_StepWalkRun_P2_6_10_4 + 1;
constexpr uint16_t Falling_StepWalkRun_P2_6_10_6_End             = Stance::Falling_StepWalkRun_P2_6_10_5_Check_CanFall + 1;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/*                                                               01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define FALLING_STEPWALKRUN_P3_7_11_SEQ                          121,   122,   123,   124,   125,   126,
#define FALLING_STEPWALKRUN_P3_7_11_OFFSETS                      2,6,   2,5,   2,5,    2,5,   1,5,   0,5, 
constexpr uint16_t Falling_StepWalkRun_P3_7_11_1_Start           = Stance::Falling_StepWalkRun_P2_6_10_6_End + 1;
constexpr uint16_t Falling_StepWalkRun_P3_7_11_2                 = Stance::Falling_StepWalkRun_P3_7_11_1_Start + 1;
constexpr uint16_t Falling_StepWalkRun_P3_7_11_3                 = Stance::Falling_StepWalkRun_P3_7_11_2 + 1;
constexpr uint16_t Falling_StepWalkRun_P3_7_11_4                 = Stance::Falling_StepWalkRun_P3_7_11_3 + 1;
constexpr uint16_t Falling_StepWalkRun_P3_7_11_5_Check_CanFall   = Stance::Falling_StepWalkRun_P3_7_11_4 + 1;
constexpr uint16_t Falling_StepWalkRun_P3_7_11_6_End             = Stance::Falling_StepWalkRun_P3_7_11_5_Check_CanFall + 1;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/*                                                               01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define FALLING_DOWN_P2_SEQ                                      125,   125,   125,   125,   125,   125,
#define FALLING_DOWN_P2_OFFSETS                                  0,6,   1,5,   0,5,   1,5,   0,5,   0,5,
constexpr uint16_t Falling_Down_P2_1_Start                       = Stance::Falling_StepWalkRun_P3_7_11_6_End + 1;
constexpr uint16_t Falling_Down_P2_2                             = Stance::Falling_Down_P2_1_Start + 1;
constexpr uint16_t Falling_Down_P2_3                             = Stance::Falling_Down_P2_2 + 1;
constexpr uint16_t Falling_Down_P2_4                             = Stance::Falling_Down_P2_3 + 1;
constexpr uint16_t Falling_Down_P2_5_Check_CanFall               = Stance::Falling_Down_P2_4 + 1;
constexpr uint16_t Falling_Down_P2_6_End                         = Stance::Falling_Down_P2_5_Check_CanFall + 1;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/*                                                               01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define FALLING_DOWN_P1_SEQ                                      125,   125,   125,   125,   125,   125,
#define FALLING_DOWN_P1_OFFSETS                                  0,6,   0,5,   0,5,   1,5,   0,5,   0,5,
constexpr uint16_t Falling_Down_P1_1_Start                       = Stance::Falling_Down_P2_6_End + 1;
constexpr uint16_t Falling_Down_P1_2                             = Stance::Falling_Down_P1_1_Start + 1;
constexpr uint16_t Falling_Down_P1_3                             = Stance::Falling_Down_P1_2 + 1;
constexpr uint16_t Falling_Down_P1_4                             = Stance::Falling_Down_P1_3 + 1;
constexpr uint16_t Falling_Down_P1_5_Check_CanFall               = Stance::Falling_Down_P1_4 + 1;
constexpr uint16_t Falling_Down_P1_6_End                         = Stance::Falling_Down_P1_5_Check_CanFall + 1;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/*                                                               01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define FALLING_DOWN_P0_SEQ                                      125,   125,   125,   125,   125,   125,
#define FALLING_DOWN_P0_OFFSETS                                  0,6,   0,5,   0,5,   0,5,   0,5,   0,5,
constexpr uint16_t Falling_Down_P0_1_Start                       = Stance::Falling_Down_P1_6_End + 1;
constexpr uint16_t Falling_Down_P0_2                             = Stance::Falling_Down_P0_1_Start + 1;
constexpr uint16_t Falling_Down_P0_3                             = Stance::Falling_Down_P0_2 + 1;
constexpr uint16_t Falling_Down_P0_4                             = Stance::Falling_Down_P0_3 + 1;
constexpr uint16_t Falling_Down_P0_5_Check_CanFall               = Stance::Falling_Down_P0_4 + 1;
constexpr uint16_t Falling_Down_P0_6_End                         = Stance::Falling_Down_P0_5_Check_CanFall + 1;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/*                                                               01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define FALLING_DOWN_M1_SEQ                                      125,   125,   125,   125,   125,   125,
#define FALLING_DOWN_M1_OFFSETS                                  0,6,   0,5,   -1,5,  0,5,   0,5,   0,5,
constexpr uint16_t Falling_Down_M1_1_Start                       = Stance::Falling_Down_P0_6_End + 1;
constexpr uint16_t Falling_Down_M1_2                             = Stance::Falling_Down_M1_1_Start + 1;
constexpr uint16_t Falling_Down_M1_3                             = Stance::Falling_Down_M1_2 + 1;
constexpr uint16_t Falling_Down_M1_4                             = Stance::Falling_Down_M1_3 + 1;
constexpr uint16_t Falling_Down_M1_5_Check_CanFall               = Stance::Falling_Down_M1_4 + 1;
constexpr uint16_t Falling_Down_M1_6_End                         = Stance::Falling_Down_M1_5_Check_CanFall + 1;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/*                                                               01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define FALLING_DOWN_M2_SEQ                                      125,   125,   125,   125,   125,   125,
#define FALLING_DOWN_M2_OFFSETS                                  0,6,   -1,5,  0,5,   -1,5,  0,5,   0,5,
constexpr uint16_t Falling_Down_M2_1_Start                       = Stance::Falling_Down_M1_6_End + 1;
constexpr uint16_t Falling_Down_M2_2                             = Stance::Falling_Down_M2_1_Start + 1;
constexpr uint16_t Falling_Down_M2_3                             = Stance::Falling_Down_M2_2 + 1;
constexpr uint16_t Falling_Down_M2_4                             = Stance::Falling_Down_M2_3 + 1;
constexpr uint16_t Falling_Down_M2_5_Check_CanFall               = Stance::Falling_Down_M2_4 + 1;
constexpr uint16_t Falling_Down_M2_6_End                         = Stance::Falling_Down_M2_5_Check_CanFall + 1;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/*                                                               01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define LEAVE_GATE_SEQ                                           157,   158,   159,   160,   161,   162,   163,   164,   165,   166,   167,   168,   168,   0,
#define LEAVE_GATE_OFFSETS                                       0,0,   1,0,   2,-1,  2,-1,  2,-1,  1,-1,  1,-1,  1,-1,  1,-1,  1,-1,  1,-2,  0,-3,  0,0,   0,0,
constexpr uint16_t Leave_Gate_01_Start                           = Stance::Falling_Down_M2_6_End + 1;
constexpr uint16_t Leave_Gate_02                                 = Stance::Leave_Gate_01_Start + 1;
constexpr uint16_t Leave_Gate_03                                 = Stance::Leave_Gate_02 + 1;
constexpr uint16_t Leave_Gate_04                                 = Stance::Leave_Gate_03 + 1;
constexpr uint16_t Leave_Gate_05                                 = Stance::Leave_Gate_04 + 1;
constexpr uint16_t Leave_Gate_06                                 = Stance::Leave_Gate_05 + 1;
constexpr uint16_t Leave_Gate_07                                 = Stance::Leave_Gate_06 + 1;
constexpr uint16_t Leave_Gate_08                                 = Stance::Leave_Gate_07 + 1;
constexpr uint16_t Leave_Gate_09                                 = Stance::Leave_Gate_08 + 1;
constexpr uint16_t Leave_Gate_10                                 = Stance::Leave_Gate_09 + 1;
constexpr uint16_t Leave_Gate_11                                 = Stance::Leave_Gate_10 + 1;
constexpr uint16_t Leave_Gate_12                                 = Stance::Leave_Gate_11 + 1;
constexpr uint16_t Leave_Gate_13                                 = Stance::Leave_Gate_12 + 1;
constexpr uint16_t Leave_Gate_14_End                             = Stance::Leave_Gate_13 + 1;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/*                                                               01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define COLLIDE_WALL_SEQ                                         126,   126,   126,   126,   126, 
#define COLLIDE_WALL_OFFSETS                                     2,0,   1,0,   0,0,   -1,0,  -2,0,
constexpr uint16_t Collide_Wall_P2_Start_End                     = Stance::Leave_Gate_14_End + 1;
constexpr uint16_t Collide_Wall_P1_Start_End                     = Stance::Collide_Wall_P2_Start_End + 1;
constexpr uint16_t Collide_Wall_P0_Start_End                     = Stance::Collide_Wall_P1_Start_End + 1;
constexpr uint16_t Collide_Wall_M1_Start_End                     = Stance::Collide_Wall_P0_Start_End + 1;
constexpr uint16_t Collide_Wall_M2_Start_End                     = Stance::Collide_Wall_M1_Start_End + 1;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/*                                                               01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define VER_ADJUSTMENTS_SEQ                                      125,   125,   125,   125,   125,   125, 
#define VER_ADJUSTMENTS_OFFSETS                                  0,1,   0,2,   0,3,   0,4,   0,5,   0,6,
constexpr uint16_t Vert_Adjustment_1_Start_End                   = Stance::Collide_Wall_M2_Start_End + 1;
constexpr uint16_t Vert_Adjustment_2_Start_End                   = Stance::Vert_Adjustment_1_Start_End + 1;
constexpr uint16_t Vert_Adjustment_3_Start_End                   = Stance::Vert_Adjustment_2_Start_End + 1;
constexpr uint16_t Vert_Adjustment_4_Start_End                   = Stance::Vert_Adjustment_3_Start_End + 1;
constexpr uint16_t Vert_Adjustment_5_Start_End                   = Stance::Vert_Adjustment_4_Start_End + 1;
constexpr uint16_t Vert_Adjustment_6_Start_End                   = Stance::Vert_Adjustment_5_Start_End + 1;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/*                                                               01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define RUNNING_JUMP_4_DROPLVL_SEQ                               19,    20,    21,    22,    23,    24,    25,    26,    121,   122,   123,   124,   125,   126,
#define RUNNING_JUMP_4_DROPLVL_OFFSETS                           3,0,   3,0,   4,0,   4,0,   5,-2,  5,-1,  6,3,   6,2,   7,5,   4,5,   3,5,   3,5,   3,5,   2,5,
constexpr uint16_t Running_Jump_4_DropLvl_1_Start                = Stance::Vert_Adjustment_6_Start_End + 1;
constexpr uint16_t Running_Jump_4_DropLvl_2                      = Stance::Running_Jump_4_DropLvl_1_Start + 1;
constexpr uint16_t Running_Jump_4_DropLvl_3                      = Stance::Running_Jump_4_DropLvl_2 + 1;
constexpr uint16_t Running_Jump_4_DropLvl_4                      = Stance::Running_Jump_4_DropLvl_3 + 1;
constexpr uint16_t Running_Jump_4_DropLvl_5                      = Stance::Running_Jump_4_DropLvl_4 + 1;
constexpr uint16_t Running_Jump_4_DropLvl_6                      = Stance::Running_Jump_4_DropLvl_5 + 1;
constexpr uint16_t Running_Jump_4_DropLvl_7                      = Stance::Running_Jump_4_DropLvl_6 + 1;
constexpr uint16_t Running_Jump_4_DropLvl_8                      = Stance::Running_Jump_4_DropLvl_7 + 1;
constexpr uint16_t Running_Jump_4_DropLvl_9                      = Stance::Running_Jump_4_DropLvl_8 + 1;
constexpr uint16_t Running_Jump_4_DropLvl_10                     = Stance::Running_Jump_4_DropLvl_9 + 1;
constexpr uint16_t Running_Jump_4_DropLvl_11                     = Stance::Running_Jump_4_DropLvl_10 + 1;
constexpr uint16_t Running_Jump_4_DropLvl_12                     = Stance::Running_Jump_4_DropLvl_11 + 1;
constexpr uint16_t Running_Jump_4_DropLvl_13                     = Stance::Running_Jump_4_DropLvl_12 + 1;
constexpr uint16_t Running_Jump_4_DropLvl_14_End                 = Stance::Running_Jump_4_DropLvl_13 + 1;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/*                                                               01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define RUNNING_JUMP_3_DROPLVL_SEQ                               19,    20,    21,    22,    23,    24,    25,    26,    121,   122,   123,   124,   125,   126,
#define RUNNING_JUMP_3_DROPLVL_OFFSETS                           3,0,   3,0,   3,0,   3,0,   4,-2,  4,-1,  4,3,   4,2,   4,4,   4,5,   3,5,   2,5,   2,5,   2,5,
constexpr uint16_t Running_Jump_3_DropLvl_1_Start                = Stance::Running_Jump_4_DropLvl_14_End + 1;
constexpr uint16_t Running_Jump_3_DropLvl_2                      = Stance::Running_Jump_3_DropLvl_1_Start + 1;
constexpr uint16_t Running_Jump_3_DropLvl_3                      = Stance::Running_Jump_3_DropLvl_2 + 1;
constexpr uint16_t Running_Jump_3_DropLvl_4                      = Stance::Running_Jump_3_DropLvl_3 + 1;
constexpr uint16_t Running_Jump_3_DropLvl_5                      = Stance::Running_Jump_3_DropLvl_4 + 1;
constexpr uint16_t Running_Jump_3_DropLvl_6                      = Stance::Running_Jump_3_DropLvl_5 + 1;
constexpr uint16_t Running_Jump_3_DropLvl_7                      = Stance::Running_Jump_3_DropLvl_6 + 1;
constexpr uint16_t Running_Jump_3_DropLvl_8                      = Stance::Running_Jump_3_DropLvl_7 + 1;
constexpr uint16_t Running_Jump_3_DropLvl_9                      = Stance::Running_Jump_3_DropLvl_8 + 1;
constexpr uint16_t Running_Jump_3_DropLvl_10                     = Stance::Running_Jump_3_DropLvl_9 + 1;
constexpr uint16_t Running_Jump_3_DropLvl_11                     = Stance::Running_Jump_3_DropLvl_10 + 1;
constexpr uint16_t Running_Jump_3_DropLvl_12                     = Stance::Running_Jump_3_DropLvl_11 + 1;
constexpr uint16_t Running_Jump_3_DropLvl_13                     = Stance::Running_Jump_3_DropLvl_12 + 1;
constexpr uint16_t Running_Jump_3_DropLvl_14_End                 = Stance::Running_Jump_3_DropLvl_13 + 1;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/*                                                               01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define RUNNING_JUMP_3_SAMELVL_SEQ                               20,    21,    22,    23,    169,   24,    25,    26,
#define RUNNING_JUMP_3_SAMELVL_OFFSETS                           5,0,   6,0,   6,0,   7,-2,  7,0,   6,-2,  4,3,   2,1,
constexpr uint16_t Running_Jump_3_SameLvl_1_Start                = Stance::Running_Jump_3_DropLvl_14_End + 1;
constexpr uint16_t Running_Jump_3_SameLvl_2                      = Stance::Running_Jump_3_SameLvl_1_Start + 1;
constexpr uint16_t Running_Jump_3_SameLvl_3                      = Stance::Running_Jump_3_SameLvl_2 + 1;
constexpr uint16_t Running_Jump_3_SameLvl_4                      = Stance::Running_Jump_3_SameLvl_3 + 1;
constexpr uint16_t Running_Jump_3_SameLvl_5                      = Stance::Running_Jump_3_SameLvl_4 + 1;
constexpr uint16_t Running_Jump_3_SameLvl_6                      = Stance::Running_Jump_3_SameLvl_5 + 1;
constexpr uint16_t Running_Jump_3_SameLvl_7                      = Stance::Running_Jump_3_SameLvl_6 + 1;
constexpr uint16_t Running_Jump_3_SameLvl_8_End                  = Stance::Running_Jump_3_SameLvl_7 + 1;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/*                                                               01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define RUNNING_JUMP_3_SAMELVL_SHORT_SEQ                         20,    21,    22,    23,    169,   24,    25,    26,
#define RUNNING_JUMP_3_SAMELVL_SHORT_OFFSETS                     5,0,   6,0,   6,0,   7,-2,  6,0,   5,-2,  3,3,   1,1,
constexpr uint16_t Running_Jump_3_SameLvl_Short_1_Start          = Stance::Running_Jump_3_SameLvl_8_End + 1;
constexpr uint16_t Running_Jump_3_SameLvl_Short_2                = Stance::Running_Jump_3_SameLvl_Short_1_Start + 1;
constexpr uint16_t Running_Jump_3_SameLvl_Short_3                = Stance::Running_Jump_3_SameLvl_Short_2 + 1;
constexpr uint16_t Running_Jump_3_SameLvl_Short_4                = Stance::Running_Jump_3_SameLvl_Short_3 + 1;
constexpr uint16_t Running_Jump_3_SameLvl_Short_5                = Stance::Running_Jump_3_SameLvl_Short_4 + 1;
constexpr uint16_t Running_Jump_3_SameLvl_Short_6                = Stance::Running_Jump_3_SameLvl_Short_5 + 1;
constexpr uint16_t Running_Jump_3_SameLvl_Short_7                = Stance::Running_Jump_3_SameLvl_Short_6 + 1;
constexpr uint16_t Running_Jump_3_SameLvl_Short_8_End            = Stance::Running_Jump_3_SameLvl_Short_7 + 1;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/*                                                               01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define SWORD_NORMAL_SEQ                                         174,
#define SWORD_NORMAL_OFFSETS                                     0,0,
constexpr uint16_t Sword_Normal                                  = Stance::Running_Jump_3_SameLvl_Short_8_End + 1;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/*                                                               01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define DRAW_SWORD_SEQ                                           175,   176,   177,   178,   179,   180,
#define DRAW_SWORD_OFFSETS                                       0,0,   0,0,   0,0,   0,0,   0,0,   0,0,
constexpr uint16_t Draw_Sword_1_Start                            = Stance::Sword_Normal + 1;
constexpr uint16_t Draw_Sword_2                                  = Stance::Draw_Sword_1_Start + 1;
constexpr uint16_t Draw_Sword_3                                  = Stance::Draw_Sword_2 + 1;
constexpr uint16_t Draw_Sword_4                                  = Stance::Draw_Sword_3 + 1;
constexpr uint16_t Draw_Sword_5                                  = Stance::Draw_Sword_4 + 1;
constexpr uint16_t Draw_Sword_6_End                              = Stance::Draw_Sword_5 + 1;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/*                                                               01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define SWORD_STEP_SEQ                                           181,   182,   183,   
#define SWORD_STEP_OFFSETS                                       3,0,   1,0,   0,0,  
constexpr uint16_t Sword_Step_1_Start                            = Stance::Draw_Sword_6_End + 1;
constexpr uint16_t Sword_Step_2                                  = Stance::Sword_Step_1_Start + 1;
constexpr uint16_t Sword_Step_3_End                              = Stance::Sword_Step_2 + 1;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/*                                                               01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define SWORD_ATTACK_SEQ                                         186,   187,   188,   189,   190,   191,   192,   193,   
#define SWORD_ATTACK_OFFSETS                                     2,0,   1,0,   2,0,   2,0,   -3,0,  -3,0,  -1,0,  0,0,
constexpr uint16_t Sword_Attack_1_Start                          = Stance::Sword_Step_3_End + 1;
constexpr uint16_t Sword_Attack_2                                = Stance::Sword_Attack_1_Start + 1;
constexpr uint16_t Sword_Attack_3                                = Stance::Sword_Attack_2 + 1;
constexpr uint16_t Sword_Attack_4                                = Stance::Sword_Attack_3 + 1;
constexpr uint16_t Sword_Attack_5                                = Stance::Sword_Attack_4 + 1;
constexpr uint16_t Sword_Attack_6                                = Stance::Sword_Attack_5 + 1;
constexpr uint16_t Sword_Attack_7                                = Stance::Sword_Attack_6 + 1;
constexpr uint16_t Sword_Attack_8_End                            = Stance::Sword_Attack_7 + 1;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/*                                                               01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define ATTACK_BLOCK_SEQ                                         194,   195,   194,   
#define ATTACK_BLOCK_OFFSETS                                     0,0,   1,0,   -1,0,
constexpr uint16_t Attack_Block_1_Start                          = Stance::Sword_Attack_8_End + 1;
constexpr uint16_t Attack_Block_2                                = Stance::Attack_Block_1_Start + 1;
constexpr uint16_t Attack_Block_3_End                            = Stance::Attack_Block_2 + 1;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/*                                                               01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define FALLING_DEAD_BLADE_SEQ                                   126,   142,
#define FALLING_DEAD_BLADE_OFFSETS                               0,0,   0,0,  
constexpr uint16_t Falling_Dead_Blade_1_Start                    = Stance::Attack_Block_3_End + 1;  
constexpr uint16_t Falling_Dead_Blade_2_End                      = Stance::Falling_Dead_Blade_1_Start + 1;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* Used when mirror is closing button                                                                                                                                                                    */
/*                                                               01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define DELAY_SEQ                                                15,    15,    15,    15,    15,    15,    15,    15,    
#define DELAY_OFFSETS                                            0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   0,0,   
constexpr uint16_t Delay_1_Start                                 = Stance::Falling_Dead_Blade_2_End + 1;  
constexpr uint16_t Delay_2                                       = Stance::Delay_1_Start + 1;
constexpr uint16_t Delay_3                                       = Stance::Delay_2 + 1;
constexpr uint16_t Delay_4                                       = Stance::Delay_3 + 1;
constexpr uint16_t Delay_5                                       = Stance::Delay_4 + 1;
constexpr uint16_t Delay_6                                       = Stance::Delay_5 + 1;
constexpr uint16_t Delay_7                                       = Stance::Delay_6 + 1;
constexpr uint16_t Delay_8_End                                   = Stance::Delay_7 + 1;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/*                                                               01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define STRAIGHT_DROP_HANGON_SEQ                                 125,   125,   125,   125,   125,   103,
#define STRAIGHT_DROP_HANGON_OFFSETS                             0,6,   0,6,   0,6,   0,6,   0,7,   0,7,
constexpr uint16_t Straight_Drop_HangOn_1_Start                  = Stance::Delay_8_End + 1;  // Drop down to Pos 2 (two levels)
constexpr uint16_t Straight_Drop_HangOn_2                        = Stance::Straight_Drop_HangOn_1_Start + 1;
constexpr uint16_t Straight_Drop_HangOn_3                        = Stance::Straight_Drop_HangOn_2 + 1;
constexpr uint16_t Straight_Drop_HangOn_4                        = Stance::Straight_Drop_HangOn_3 + 1;
constexpr uint16_t Straight_Drop_HangOn_5                        = Stance::Straight_Drop_HangOn_4 + 1;
constexpr uint16_t Straight_Drop_HangOn_6_End                    = Stance::Straight_Drop_HangOn_5 + 1;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/*                                                               01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define STANDING_JUMP_GL_2_SEQ                                   45,    46,    47,    48,    49,    50,    51,    52,    53,    54,    121,   122,   123,   124,   125,   101,   102,   103,
#define STANDING_JUMP_GL_2_OFFSETS                               0,0,   0,0,   2,0,   2,0,   2,0,   2,0,   2,0,   3,0,   3,1,   3,1,   7,3,   3,4,   2,4,   1,4,   1,4,   1,4,   1,3,   1,3,
constexpr uint16_t Standing_Jump_GL_2_1_Start                    = Stance::Straight_Drop_HangOn_6_End + 1;
constexpr uint16_t Standing_Jump_GL_2_2                          = Stance::Standing_Jump_GL_2_1_Start + 1;
constexpr uint16_t Standing_Jump_GL_2_3                          = Stance::Standing_Jump_GL_2_2 + 1;
constexpr uint16_t Standing_Jump_GL_2_4                          = Stance::Standing_Jump_GL_2_3 + 1;
constexpr uint16_t Standing_Jump_GL_2_5                          = Stance::Standing_Jump_GL_2_4 + 1;
constexpr uint16_t Standing_Jump_GL_2_6                          = Stance::Standing_Jump_GL_2_5 + 1;
constexpr uint16_t Standing_Jump_GL_2_7                          = Stance::Standing_Jump_GL_2_6 + 1;
constexpr uint16_t Standing_Jump_GL_2_8                          = Stance::Standing_Jump_GL_2_7 + 1;
constexpr uint16_t Standing_Jump_GL_2_9                          = Stance::Standing_Jump_GL_2_8 + 1;
constexpr uint16_t Standing_Jump_GL_2_10                         = Stance::Standing_Jump_GL_2_9 + 1;
constexpr uint16_t Standing_Jump_GL_2_11                         = Stance::Standing_Jump_GL_2_10 + 1;
constexpr uint16_t Standing_Jump_GL_2_12                         = Stance::Standing_Jump_GL_2_11 + 1;
constexpr uint16_t Standing_Jump_GL_2_13                         = Stance::Standing_Jump_GL_2_12 + 1;
constexpr uint16_t Standing_Jump_GL_2_14                         = Stance::Standing_Jump_GL_2_13 + 1;
constexpr uint16_t Standing_Jump_GL_2_15                         = Stance::Standing_Jump_GL_2_14 + 1;
constexpr uint16_t Standing_Jump_GL_2_16                         = Stance::Standing_Jump_GL_2_15 + 1;
constexpr uint16_t Standing_Jump_GL_2_17                         = Stance::Standing_Jump_GL_2_16 + 1;
constexpr uint16_t Standing_Jump_GL_2_18_End                     = Stance::Standing_Jump_GL_2_17 + 1;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/*                                                               01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define STANDING_JUMP_GL_6_SEQ                                   45,    46,    47,    48,    49,    50,    51,    52,    53,    54,    121,   122,   123,   124,   125,   101,   102,   103,
#define STANDING_JUMP_GL_6_OFFSETS                               0,0,   0,0,   2,0,   2,0,   2,0,   2,0,   2,0,   3,0,   4,1,   4,1,   8,3,   4,4,   2,4,   1,4,   1,4,   1,4,   1,3,   1,3,
constexpr uint16_t Standing_Jump_GL_6_1_Start                    = Stance::Standing_Jump_GL_2_18_End + 1;
constexpr uint16_t Standing_Jump_GL_6_2                          = Stance::Standing_Jump_GL_6_1_Start + 1;
constexpr uint16_t Standing_Jump_GL_6_3                          = Stance::Standing_Jump_GL_6_2 + 1;
constexpr uint16_t Standing_Jump_GL_6_4                          = Stance::Standing_Jump_GL_6_3 + 1;
constexpr uint16_t Standing_Jump_GL_6_5                          = Stance::Standing_Jump_GL_6_4 + 1;
constexpr uint16_t Standing_Jump_GL_6_6                          = Stance::Standing_Jump_GL_6_5 + 1;
constexpr uint16_t Standing_Jump_GL_6_7                          = Stance::Standing_Jump_GL_6_6 + 1;
constexpr uint16_t Standing_Jump_GL_6_8                          = Stance::Standing_Jump_GL_6_7 + 1;
constexpr uint16_t Standing_Jump_GL_6_9                          = Stance::Standing_Jump_GL_6_8 + 1;
constexpr uint16_t Standing_Jump_GL_6_10                         = Stance::Standing_Jump_GL_6_9 + 1;
constexpr uint16_t Standing_Jump_GL_6_11                         = Stance::Standing_Jump_GL_6_10 + 1;
constexpr uint16_t Standing_Jump_GL_6_12                         = Stance::Standing_Jump_GL_6_11 + 1;
constexpr uint16_t Standing_Jump_GL_6_13                         = Stance::Standing_Jump_GL_6_12 + 1;
constexpr uint16_t Standing_Jump_GL_6_14                         = Stance::Standing_Jump_GL_6_13 + 1;
constexpr uint16_t Standing_Jump_GL_6_15                         = Stance::Standing_Jump_GL_6_14 + 1;
constexpr uint16_t Standing_Jump_GL_6_16                         = Stance::Standing_Jump_GL_6_15 + 1;
constexpr uint16_t Standing_Jump_GL_6_17                         = Stance::Standing_Jump_GL_6_16 + 1;
constexpr uint16_t Standing_Jump_GL_6_18_End                     = Stance::Standing_Jump_GL_6_17 + 1;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/*                                                               01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define STANDING_JUMP_SHORT_6_SEQ                                45,    46,    47,    48,    49,    50,    51,    52,    55,    56,    57,    58,    59,    60,    61,    62,
#define STANDING_JUMP_SHORT_6_OFFSETS                            0,0,   0,0,   2,0,   2,0,   2,0,   3,0,   2,0,   3,0,   3,0,   3,0,   3,0,   2,0,   1,0,   1,0,   1,0,   0,0, 
constexpr uint16_t Standing_Jump_Short_6_1_Start                 = Stance::Standing_Jump_GL_6_18_End + 1;
constexpr uint16_t Standing_Jump_Short_6_2                       = Stance::Standing_Jump_Short_6_1_Start + 1;
constexpr uint16_t Standing_Jump_Short_6_3                       = Stance::Standing_Jump_Short_6_2 + 1;
constexpr uint16_t Standing_Jump_Short_6_4                       = Stance::Standing_Jump_Short_6_3 + 1;
constexpr uint16_t Standing_Jump_Short_6_5                       = Stance::Standing_Jump_Short_6_4 + 1;
constexpr uint16_t Standing_Jump_Short_6_6                       = Stance::Standing_Jump_Short_6_5 + 1;
constexpr uint16_t Standing_Jump_Short_6_7                       = Stance::Standing_Jump_Short_6_6 + 1;
constexpr uint16_t Standing_Jump_Short_6_8                       = Stance::Standing_Jump_Short_6_7 + 1;
constexpr uint16_t Standing_Jump_Short_6_9                       = Stance::Standing_Jump_Short_6_8 + 1;
constexpr uint16_t Standing_Jump_Short_6_10                      = Stance::Standing_Jump_Short_6_9 + 1;
constexpr uint16_t Standing_Jump_Short_6_11                      = Stance::Standing_Jump_Short_6_10 + 1;
constexpr uint16_t Standing_Jump_Short_6_12                      = Stance::Standing_Jump_Short_6_11 + 1;
constexpr uint16_t Standing_Jump_Short_6_13                      = Stance::Standing_Jump_Short_6_12 + 1;
constexpr uint16_t Standing_Jump_Short_6_14                      = Stance::Standing_Jump_Short_6_13 + 1;
constexpr uint16_t Standing_Jump_Short_6_15                      = Stance::Standing_Jump_Short_6_14 + 1;
constexpr uint16_t Standing_Jump_Short_6_16_End                  = Stance::Standing_Jump_Short_6_15 + 1;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/*                                                               01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define STANDING_JUMP_SHORT_10_SEQ                               45,    46,    47,    48,    49,    50,    51,    52,    55,    56,    57,    58,    59,    60,    61,    62,
#define STANDING_JUMP_SHORT_10_OFFSETS                           0,0,   0,0,   2,0,   2,0,   3,0,   4,0,   2,0,   3,0,   3,0,   3,0,   3,0,   3,0,   2,0,   1,0,   1,0,   0,0, 
constexpr uint16_t Standing_Jump_Short_10_1_Start                = Stance::Standing_Jump_Short_6_16_End + 1;
constexpr uint16_t Standing_Jump_Short_10_2                      = Stance::Standing_Jump_Short_10_1_Start + 1;
constexpr uint16_t Standing_Jump_Short_10_3                      = Stance::Standing_Jump_Short_10_2 + 1;
constexpr uint16_t Standing_Jump_Short_10_4                      = Stance::Standing_Jump_Short_10_3 + 1;
constexpr uint16_t Standing_Jump_Short_10_5                      = Stance::Standing_Jump_Short_10_4 + 1;
constexpr uint16_t Standing_Jump_Short_10_6                      = Stance::Standing_Jump_Short_10_5 + 1;
constexpr uint16_t Standing_Jump_Short_10_7                      = Stance::Standing_Jump_Short_10_6 + 1;
constexpr uint16_t Standing_Jump_Short_10_8                      = Stance::Standing_Jump_Short_10_7 + 1;
constexpr uint16_t Standing_Jump_Short_10_9                      = Stance::Standing_Jump_Short_10_8 + 1;
constexpr uint16_t Standing_Jump_Short_10_10                     = Stance::Standing_Jump_Short_10_9 + 1;
constexpr uint16_t Standing_Jump_Short_10_11                     = Stance::Standing_Jump_Short_10_10 + 1;
constexpr uint16_t Standing_Jump_Short_10_12                     = Stance::Standing_Jump_Short_10_11 + 1;
constexpr uint16_t Standing_Jump_Short_10_13                     = Stance::Standing_Jump_Short_10_12 + 1;
constexpr uint16_t Standing_Jump_Short_10_14                     = Stance::Standing_Jump_Short_10_13 + 1;
constexpr uint16_t Standing_Jump_Short_10_15                     = Stance::Standing_Jump_Short_10_14 + 1;
constexpr uint16_t Standing_Jump_Short_10_16_End                 = Stance::Standing_Jump_Short_10_15 + 1;



/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/*                                                               01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define STANDING_JUMP_SHORT_GL_6_SEQ                             45,    46,    47,    48,    49,    50,    51,    52,    53,    54,    121,   122,   123,   124,   125,   101,   102,   103,
#define STANDING_JUMP_SHORT_GL_6_OFFSETS                         0,0,   0,0,   2,0,   2,0,   2,0,   2,0,   2,0,   2,0,   3,1,   3,1,   6,3,   3,4,   1,4,   0,4,   0,4,   0,4,   0,3,   0,3,
constexpr uint16_t Standing_Jump_Short_GL_6_1_Start              = Stance::Standing_Jump_Short_10_16_End + 1;
constexpr uint16_t Standing_Jump_Short_GL_6_2                    = Stance::Standing_Jump_Short_GL_6_1_Start + 1;
constexpr uint16_t Standing_Jump_Short_GL_6_3                    = Stance::Standing_Jump_Short_GL_6_2 + 1;
constexpr uint16_t Standing_Jump_Short_GL_6_4                    = Stance::Standing_Jump_Short_GL_6_3 + 1;
constexpr uint16_t Standing_Jump_Short_GL_6_5                    = Stance::Standing_Jump_Short_GL_6_4 + 1;
constexpr uint16_t Standing_Jump_Short_GL_6_6                    = Stance::Standing_Jump_Short_GL_6_5 + 1;
constexpr uint16_t Standing_Jump_Short_GL_6_7                    = Stance::Standing_Jump_Short_GL_6_6 + 1;
constexpr uint16_t Standing_Jump_Short_GL_6_8                    = Stance::Standing_Jump_Short_GL_6_7 + 1;
constexpr uint16_t Standing_Jump_Short_GL_6_9                    = Stance::Standing_Jump_Short_GL_6_8 + 1;
constexpr uint16_t Standing_Jump_Short_GL_6_10                   = Stance::Standing_Jump_Short_GL_6_9 + 1;
constexpr uint16_t Standing_Jump_Short_GL_6_11                   = Stance::Standing_Jump_Short_GL_6_10 + 1;
constexpr uint16_t Standing_Jump_Short_GL_6_12                   = Stance::Standing_Jump_Short_GL_6_11 + 1;
constexpr uint16_t Standing_Jump_Short_GL_6_13                   = Stance::Standing_Jump_Short_GL_6_12 + 1;
constexpr uint16_t Standing_Jump_Short_GL_6_14                   = Stance::Standing_Jump_Short_GL_6_13 + 1;
constexpr uint16_t Standing_Jump_Short_GL_6_15                   = Stance::Standing_Jump_Short_GL_6_14 + 1;
constexpr uint16_t Standing_Jump_Short_GL_6_16                   = Stance::Standing_Jump_Short_GL_6_15 + 1;
constexpr uint16_t Standing_Jump_Short_GL_6_17                   = Stance::Standing_Jump_Short_GL_6_16 + 1;
constexpr uint16_t Standing_Jump_Short_GL_6_18_End               = Stance::Standing_Jump_Short_GL_6_17 + 1;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/*                                                               01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define STANDING_JUMP_SHORT_GL_10_SEQ                            45,    46,    47,    48,    49,    50,    51,    52,    53,    54,    121,   122,   123,   124,   125,   101,   102,   103,
#define STANDING_JUMP_SHORT_GL_10_OFFSETS                        0,0,   0,0,   2,0,   2,0,   2,0,   2,0,   2,0,   2,0,   3,1,   4,1,   6,3,   3,4,   2,4,   1,4,   1,4,   0,4,   0,3,   0,3,
constexpr uint16_t Standing_Jump_Short_GL_10_1_Start             = Stance::Standing_Jump_Short_GL_6_18_End + 1;
constexpr uint16_t Standing_Jump_Short_GL_10_2                   = Stance::Standing_Jump_Short_GL_10_1_Start + 1;
constexpr uint16_t Standing_Jump_Short_GL_10_3                   = Stance::Standing_Jump_Short_GL_10_2 + 1;
constexpr uint16_t Standing_Jump_Short_GL_10_4                   = Stance::Standing_Jump_Short_GL_10_3 + 1;
constexpr uint16_t Standing_Jump_Short_GL_10_5                   = Stance::Standing_Jump_Short_GL_10_4 + 1;
constexpr uint16_t Standing_Jump_Short_GL_10_6                   = Stance::Standing_Jump_Short_GL_10_5 + 1;
constexpr uint16_t Standing_Jump_Short_GL_10_7                   = Stance::Standing_Jump_Short_GL_10_6 + 1;
constexpr uint16_t Standing_Jump_Short_GL_10_8                   = Stance::Standing_Jump_Short_GL_10_7 + 1;
constexpr uint16_t Standing_Jump_Short_GL_10_9                   = Stance::Standing_Jump_Short_GL_10_8 + 1;
constexpr uint16_t Standing_Jump_Short_GL_10_10                  = Stance::Standing_Jump_Short_GL_10_9 + 1;
constexpr uint16_t Standing_Jump_Short_GL_10_11                  = Stance::Standing_Jump_Short_GL_10_10 + 1;
constexpr uint16_t Standing_Jump_Short_GL_10_12                  = Stance::Standing_Jump_Short_GL_10_11 + 1;
constexpr uint16_t Standing_Jump_Short_GL_10_13                  = Stance::Standing_Jump_Short_GL_10_12 + 1;
constexpr uint16_t Standing_Jump_Short_GL_10_14                  = Stance::Standing_Jump_Short_GL_10_13 + 1;
constexpr uint16_t Standing_Jump_Short_GL_10_15                  = Stance::Standing_Jump_Short_GL_10_14 + 1;
constexpr uint16_t Standing_Jump_Short_GL_10_16                  = Stance::Standing_Jump_Short_GL_10_15 + 1;
constexpr uint16_t Standing_Jump_Short_GL_10_17                  = Stance::Standing_Jump_Short_GL_10_16 + 1;
constexpr uint16_t Standing_Jump_Short_GL_10_18_End              = Stance::Standing_Jump_Short_GL_10_17 + 1;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
// Used when in Pos 2 and jumping 3 tiles.
/*                                                               01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define STANDING_JUMP_DROPLVL_POS2_SEQ                           45,    46,    47,    48,    49,    50,    51,    52,    53,    54,    121,   122,   123,   124,   125,   126,
#define STANDING_JUMP_DROPLVL_POS2_OFFSETS                       0,0,   0,0,   2,0,   2,0,   2,0,   3,0,   4,0,   4,0,   3,0,   2,0,   6,6,   3,5,   3,5,   3,5,   2,5,   1,5,
constexpr uint16_t Standing_Jump_DropLvl_Pos2_1_Start            = Stance::Standing_Jump_Short_GL_10_18_End + 1;
constexpr uint16_t Standing_Jump_DropLvl_Pos2_2                  = Stance::Standing_Jump_DropLvl_Pos2_1_Start + 1;
constexpr uint16_t Standing_Jump_DropLvl_Pos2_3                  = Stance::Standing_Jump_DropLvl_Pos2_2 + 1;
constexpr uint16_t Standing_Jump_DropLvl_Pos2_4                  = Stance::Standing_Jump_DropLvl_Pos2_3 + 1;
constexpr uint16_t Standing_Jump_DropLvl_Pos2_5                  = Stance::Standing_Jump_DropLvl_Pos2_4 + 1;
constexpr uint16_t Standing_Jump_DropLvl_Pos2_6                  = Stance::Standing_Jump_DropLvl_Pos2_5 + 1;
constexpr uint16_t Standing_Jump_DropLvl_Pos2_7                  = Stance::Standing_Jump_DropLvl_Pos2_6 + 1;
constexpr uint16_t Standing_Jump_DropLvl_Pos2_8                  = Stance::Standing_Jump_DropLvl_Pos2_7 + 1;
constexpr uint16_t Standing_Jump_DropLvl_Pos2_9                  = Stance::Standing_Jump_DropLvl_Pos2_8 + 1;
constexpr uint16_t Standing_Jump_DropLvl_Pos2_10                 = Stance::Standing_Jump_DropLvl_Pos2_9 + 1;
constexpr uint16_t Standing_Jump_DropLvl_Pos2_11                 = Stance::Standing_Jump_DropLvl_Pos2_10 + 1;
constexpr uint16_t Standing_Jump_DropLvl_Pos2_12                 = Stance::Standing_Jump_DropLvl_Pos2_11 + 1;
constexpr uint16_t Standing_Jump_DropLvl_Pos2_13                 = Stance::Standing_Jump_DropLvl_Pos2_12 + 1;
constexpr uint16_t Standing_Jump_DropLvl_Pos2_14                 = Stance::Standing_Jump_DropLvl_Pos2_13 + 1;
constexpr uint16_t Standing_Jump_DropLvl_Pos2_15                 = Stance::Standing_Jump_DropLvl_Pos2_14 + 1;
constexpr uint16_t Standing_Jump_DropLvl_Pos2_16_End             = Stance::Standing_Jump_DropLvl_Pos2_15 + 1;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/*                                                               01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define RUNNING_JUMP_4_GL_2_SEQ                                  19,    20,    21,    22,    23,    24,    25,    26,    121,   122,   123,   124,   125,   101,   102,   103,
#define RUNNING_JUMP_4_GL_2_OFFSETS                              3,0,   3,0,   3,0,   4,0,   4,-2,  4,-1,  4,3,   4,2,   7,3,   4,4,   3,4,   1,4,   1,4,   1,4,   1,3,   1,3,
constexpr uint16_t Running_Jump_4_GL_2_1_Start                   = Stance::Standing_Jump_DropLvl_Pos2_16_End + 1;
constexpr uint16_t Running_Jump_4_GL_2_2                         = Stance::Running_Jump_4_GL_2_1_Start + 1;
constexpr uint16_t Running_Jump_4_GL_2_3                         = Stance::Running_Jump_4_GL_2_2 + 1;
constexpr uint16_t Running_Jump_4_GL_2_4                         = Stance::Running_Jump_4_GL_2_3 + 1;
constexpr uint16_t Running_Jump_4_GL_2_5                         = Stance::Running_Jump_4_GL_2_4 + 1;
constexpr uint16_t Running_Jump_4_GL_2_6                         = Stance::Running_Jump_4_GL_2_5 + 1;
constexpr uint16_t Running_Jump_4_GL_2_7                         = Stance::Running_Jump_4_GL_2_6 + 1;
constexpr uint16_t Running_Jump_4_GL_2_8                         = Stance::Running_Jump_4_GL_2_7 + 1;
constexpr uint16_t Running_Jump_4_GL_2_9                         = Stance::Running_Jump_4_GL_2_8 + 1;
constexpr uint16_t Running_Jump_4_GL_2_10                        = Stance::Running_Jump_4_GL_2_9 + 1;
constexpr uint16_t Running_Jump_4_GL_2_11                        = Stance::Running_Jump_4_GL_2_10 + 1;
constexpr uint16_t Running_Jump_4_GL_2_12                        = Stance::Running_Jump_4_GL_2_11 + 1;
constexpr uint16_t Running_Jump_4_GL_2_13                        = Stance::Running_Jump_4_GL_2_12 + 1;
constexpr uint16_t Running_Jump_4_GL_2_14                        = Stance::Running_Jump_4_GL_2_13 + 1;
constexpr uint16_t Running_Jump_4_GL_2_15                        = Stance::Running_Jump_4_GL_2_14 + 1;
constexpr uint16_t Running_Jump_4_GL_2_16_End                    = Stance::Running_Jump_4_GL_2_15 + 1;


/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
/*                                                               01     02     03     04     05     06     07     08     09     10     11     12     13     14     15     16     17     18     19     20 */
#define RUNNING_JUMP_4_GL_6_SEQ                                  19,    20,    21,    22,    23,    24,    25,    26,    121,   122,   123,   124,   125,   101,   102,   103,
#define RUNNING_JUMP_4_GL_6_OFFSETS                              3,0,   3,0,   3,0,   4,0,   5,-2,  5,-1,  5,3,   5,2,   7,3,   4,4,   3,4,   1,4,   1,4,   1,4,   1,3,   1,3,
constexpr uint16_t Running_Jump_4_GL_6_1_Start                   = Stance::Running_Jump_4_GL_2_16_End + 1;
constexpr uint16_t Running_Jump_4_GL_6_2                         = Stance::Running_Jump_4_GL_6_1_Start + 1;
constexpr uint16_t Running_Jump_4_GL_6_3                         = Stance::Running_Jump_4_GL_6_2 + 1;
constexpr uint16_t Running_Jump_4_GL_6_4                         = Stance::Running_Jump_4_GL_6_3 + 1;
constexpr uint16_t Running_Jump_4_GL_6_5                         = Stance::Running_Jump_4_GL_6_4 + 1;
constexpr uint16_t Running_Jump_4_GL_6_6                         = Stance::Running_Jump_4_GL_6_5 + 1;
constexpr uint16_t Running_Jump_4_GL_6_7                         = Stance::Running_Jump_4_GL_6_6 + 1;
constexpr uint16_t Running_Jump_4_GL_6_8                         = Stance::Running_Jump_4_GL_6_7 + 1;
constexpr uint16_t Running_Jump_4_GL_6_9                         = Stance::Running_Jump_4_GL_6_8 + 1;
constexpr uint16_t Running_Jump_4_GL_6_10                        = Stance::Running_Jump_4_GL_6_9 + 1;
constexpr uint16_t Running_Jump_4_GL_6_11                        = Stance::Running_Jump_4_GL_6_10 + 1;
constexpr uint16_t Running_Jump_4_GL_6_12                        = Stance::Running_Jump_4_GL_6_11 + 1;
constexpr uint16_t Running_Jump_4_GL_6_13                        = Stance::Running_Jump_4_GL_6_12 + 1;
constexpr uint16_t Running_Jump_4_GL_6_14                        = Stance::Running_Jump_4_GL_6_13 + 1;
constexpr uint16_t Running_Jump_4_GL_6_15                        = Stance::Running_Jump_4_GL_6_14 + 1;
constexpr uint16_t Running_Jump_4_GL_6_16_End                    = Stance::Running_Jump_4_GL_6_15 + 1;


/* --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */

constexpr uint16_t  Upright_Turn             = 1255;
constexpr uint16_t  Hide_Mirror              = 1256;
};


namespace Constants {

    constexpr uint8_t EnemyCount = 5;
    constexpr uint8_t StackSize = 30;
    constexpr uint8_t StrikeDistance = 20;
    
    constexpr uint8_t Item_ExitDoor = 0;
    constexpr uint8_t Item_LoveHeart = 1;           // Inside dynamic range as only used in cut scenes..
    constexpr uint8_t Items_Count = 48;
   
    constexpr uint8_t FrameRate = 45;
    constexpr uint8_t Animation_NumberOfFrames = 2;
    constexpr uint8_t NoItemFound = 255;

    constexpr uint8_t TileHeight = 31;
    constexpr uint8_t TileWidth = 12;
    constexpr uint8_t ScreenTopOffset = 1;
    constexpr uint8_t ScreenWidthInTiles = 10;
    constexpr uint8_t ScreenHeightInTiles = 3;
   
    constexpr int8_t CoordNone = 127;
    constexpr uint8_t TitleScreenScroll_Max = 87;

    constexpr int8_t InAir = 127;
    constexpr int8_t InAir_DoNotFall = 126;

    constexpr uint8_t SpikeClosingDelay = 32;
    constexpr uint8_t FallingTileAbove = 108;
    constexpr uint8_t FallingTileSteppedOn = 24;
    constexpr uint8_t Button2FaillingTime = 24;
    constexpr uint8_t Button3FaillingTime = 24;

    
    #ifndef IMAGE_DATA_FROM_FX

    const uint8_t StanceToImageXRef[] PROGMEM  = {
        0, 
        CROUCH_SEQ
        RUN_START_SEQ
        RUN_REPEAT_SEQ
        UPRIGHT_SEQ
        RUNNING_JUMP_SEQ
        RUNNING_JUMP_SHORT_SEQ
        STANDING_TURN_SEQ
        RUNNING_TURN_SEQ
        STANDING_JUMP_SEQ
        STANDING_JUMP_MED_SEQ
        STANDING_JUMP_SHORT_2_SEQ
        STANDING_JUMP_DROPLVL_SEQ
        SINGLE_STEP_SEQ
        STOPPING_SEQ
        CLIMBING_SEQ
        SMALL_STEP_SEQ
        JUMP_UP_A_SEQ
        JUMP_UP_B_SEQ
        JUMP_UP_DROP_A_SEQ
        JUMP_UP_DROP_B_SEQ
        JUMP_UP_DROP_C_SEQ
        STEP_CLIMBING_SEQ
        CROUCH_STAND_SEQ
        CROUCH_HOP_SEQ
        STEP_CLIMBINB_BLOCK_SEQ
        DRINK_TONIC_SMALL_SEQ
        DRINK_TONIC_LARGE_SEQ
        DRINK_TONIC_POISON_SEQ
        DRINK_TONIC_FLOAT_SEQ
        FALLING_INJURED_SEQ
        FALLING_DEAD_SEQ
        RUN_REPEAT_8_END_SEQ
        PICKUP_SWORD_SEQ
        FALLING_STEPWALKRUN_P0_4_8_SEQ
        FALLING_STEPWALKRUN_P1_5_9_SEQ
        FALLING_STEPWALKRUN_P2_6_10_SEQ
        FALLING_STEPWALKRUN_P3_7_11_SEQ
        FALLING_DOWN_P2_SEQ    
        FALLING_DOWN_P1_SEQ    
        FALLING_DOWN_P0_SEQ
        FALLING_DOWN_M1_SEQ    
        FALLING_DOWN_M2_SEQ    
        LEAVE_GATE_SEQ
        COLLIDE_WALL_SEQ
        VER_ADJUSTMENTS_SEQ    
        RUNNING_JUMP_4_DROPLVL_SEQ
        RUNNING_JUMP_3_DROPLVL_SEQ
        RUNNING_JUMP_3_SAMELVL_SEQ
        RUNNING_JUMP_3_SAMELVL_SHORT_SEQ
        SWORD_NORMAL_SEQ
        DRAW_SWORD_SEQ
        SWORD_STEP_SEQ
        SWORD_ATTACK_SEQ
        ATTACK_BLOCK_SEQ
        FALLING_DEAD_BLADE_SEQ
        DELAY_SEQ
        STRAIGHT_DROP_HANGON_SEQ
        STANDING_JUMP_GL_2_SEQ
        STANDING_JUMP_GL_6_SEQ
        STANDING_JUMP_SHORT_6_SEQ
        STANDING_JUMP_SHORT_10_SEQ
        STANDING_JUMP_SHORT_GL_6_SEQ
        STANDING_JUMP_SHORT_GL_10_SEQ
        STANDING_JUMP_DROPLVL_POS2_SEQ
        RUNNING_JUMP_4_GL_2_SEQ
        RUNNING_JUMP_4_GL_6_SEQ
    };

    constexpr int8_t Stance_XYOffsets[] PROGMEM = {
        CROUCH_OFFSETS
        RUN_START_OFFSETS
        RUN_REPEAT_OFFSETS
        UPRIGHT_OFFSETS
        RUNNING_JUMP_OFFSETS
        RUNNING_JUMP_SHORT_OFFSETS
        STANDING_TURN_OFFSETS
        RUNNING_TURN_OFFSETS
        STANDING_JUMP_OFFSETS
        STANDING_JUMP_MED_OFFSETS
        STANDING_JUMP_SHORT_2_OFFSETS
        STANDING_JUMP_DROPLVL_OFFSETS
        SINGLE_STEP_OFFSETS
        STOPPING_OFFSETS
        CLIMBING_OFFSETS
        SMALL_STEP_OFFSETS
        JUMP_UP_A_OFFSETS
        JUMP_UP_B_OFFSETS
        JUMP_UP_DROP_A_OFFSETS
        JUMP_UP_DROP_B_OFFSETS
        JUMP_UP_DROP_C_OFFSETS
        STEP_CLIMBING_OFFSETS
        CROUCH_STAND_OFFSETS
        CROUCH_HOP_OFFSETS
        STEP_CLIMBINB_BLOCK_OFFSETS
        DRINK_TONIC_SMALL_OFFSETS
        DRINK_TONIC_LARGE_OFFSETS
        DRINK_TONIC_POISON_OFFSETS
        DRINK_TONIC_FLOAT_OFFSETS
        FALLING_INJURED_OFFSETS
        FALLING_DEAD_OFFSETS
        RUN_REPEAT_8_END_OFFSETS
        PICKUP_SWORD_OFFSETS
        FALLING_STEPWALKRUN_P0_4_8_OFFSETS
        FALLING_STEPWALKRUN_P1_5_9_OFFSETS
        FALLING_STEPWALKRUN_P2_6_10_OFFSETS
        FALLING_STEPWALKRUN_P3_7_11_OFFSETS
        FALLING_DOWN_P2_OFFSETS
        FALLING_DOWN_P1_OFFSETS
        FALLING_DOWN_P0_OFFSETS
        FALLING_DOWN_M1_OFFSETS
        FALLING_DOWN_M2_OFFSETS
        LEAVE_GATE_OFFSETS
        COLLIDE_WALL_OFFSETS
        VER_ADJUSTMENTS_OFFSETS       
        RUNNING_JUMP_4_DROPLVL_OFFSETS
        RUNNING_JUMP_3_DROPLVL_OFFSETS
        RUNNING_JUMP_3_SAMELVL_OFFSETS
        RUNNING_JUMP_3_SAMELVL_SHORT_OFFSETS
        SWORD_NORMAL_OFFSETS
        DRAW_SWORD_OFFSETS
        SWORD_STEP_OFFSETS
        SWORD_ATTACK_OFFSETS
        ATTACK_BLOCK_OFFSETS
        FALLING_DEAD_BLADE_OFFSETS
        DELAY_OFFSETS
        STRAIGHT_DROP_HANGON_OFFSETS
        STANDING_JUMP_GL_2_OFFSETS
        STANDING_JUMP_GL_6_OFFSETS
        STANDING_JUMP_SHORT_6_OFFSETS
        STANDING_JUMP_SHORT_10_OFFSETS
        STANDING_JUMP_SHORT_GL_6_OFFSETS
        STANDING_JUMP_SHORT_GL_10_OFFSETS
        STANDING_JUMP_DROPLVL_POS2_OFFSETS
        RUNNING_JUMP_4_GL_2_OFFSETS
        RUNNING_JUMP_4_GL_6_OFFSETS
    };

    #endif

}
