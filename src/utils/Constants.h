
#pragma once

#define DEBUG_PRINT    Serial.print
#define DEBUG_PRINTLN  Serial.println

#define _DEBUG
#define DEBUG_ONSCREEN_DETAILS

#define _DEBUG_PRINCE_DETAILS
#define _DEBUG_PRINCE_STACK
#define _DEBUG_PRINT_ACTION
#define _DEBUG_LEVEL_LOAD_MAP
#define _DEBUG_PRINCE_RENDERING

#define _DEBUG_ACTION_CANMOVEFORWARD
#define _DEBUG_ACTION_CANJUMPUP
#define _DEBUG_ACTION_CANJUMPUP_PART2
#define _DEBUG_ACTION_CANCLIMBDOWN
#define _DEBUG_ACTION_CANCLIMBDOWN_PART2
#define _DEBUG_ACTION_CANFALL
#define DEBUG_ACTION_COLLIDEWITHWALL

//-------------------------------------------------------------------------------------

#define STANCE_NONE                             0
#define STANCE_RUN_START_1_START                1 
#define STANCE_RUN_START_2                      2 
#define STANCE_RUN_START_3                      3 
#define STANCE_RUN_START_4                      4 
#define STANCE_RUN_START_5                      5 
#define STANCE_RUN_START_6_END                  6 
#define STANCE_RUN_REPEAT_1_START               7 
#define STANCE_RUN_REPEAT_2                     8 
#define STANCE_RUN_REPEAT_3                     9 
#define STANCE_RUN_REPEAT_4                     10 
#define STANCE_RUN_REPEAT_5_MID                 11 
#define STANCE_RUN_REPEAT_6                     12 
#define STANCE_RUN_REPEAT_7                     13 
#define STANCE_RUN_REPEAT_8_END                 14 
#define STANCE_UPRIGHT                          15
#define STANCE_RUNNING_JUMP_1_START             16
#define STANCE_RUNNING_JUMP_2                   17
#define STANCE_RUNNING_JUMP_3                   18
#define STANCE_RUNNING_JUMP_4                   19
#define STANCE_RUNNING_JUMP_5                   20
#define STANCE_RUNNING_JUMP_6                   21
#define STANCE_RUNNING_JUMP_7                   22
#define STANCE_RUNNING_JUMP_8                   23
#define STANCE_RUNNING_JUMP_9                   24
#define STANCE_RUNNING_JUMP_10                  25
#define STANCE_RUNNING_JUMP_11_END              26
#define STANCE_STANDING_TURN_1_START            27 
#define STANCE_STANDING_TURN_2                  28 
#define STANCE_STANDING_TURN_3                  29 
#define STANCE_STANDING_TURN_4                  30 
#define STANCE_STANDING_TURN_5_END              31 
#define STANCE_RUNNING_TURN_1_START             32   // 15 STANCE_STOPPING_1_START         
#define STANCE_RUNNING_TURN_2                   33   // 16 STANCE_STANDING_2
#define STANCE_RUNNING_TURN_3                   34   // 17 STANCE_STANDING_3
#define STANCE_RUNNING_TURN_4                   35   // 18 STANCE_STANDING_4
#define STANCE_RUNNING_TURN_5                   36   
#define STANCE_RUNNING_TURN_6                   37 
#define STANCE_RUNNING_TURN_7                   38 
#define STANCE_RUNNING_TURN_8                   39 
#define STANCE_RUNNING_TURN_9                   40 
#define STANCE_RUNNING_TURN_10                  41 
#define STANCE_RUNNING_TURN_11                  42 
#define STANCE_RUNNING_TURN_12                  43 
#define STANCE_RUNNING_TURN_13_END              44 
#define STANCE_STANDING_JUMP_1_START            45
#define STANCE_STANDING_JUMP_2                  46
#define STANCE_STANDING_JUMP_3                  47
#define STANCE_STANDING_JUMP_4                  48
#define STANCE_STANDING_JUMP_5                  49
#define STANCE_STANDING_JUMP_6                  50
#define STANCE_STANDING_JUMP_7                  51
#define STANCE_STANDING_JUMP_8                  52
#define STANCE_STANDING_JUMP_9                  53
#define STANCE_STANDING_JUMP_10                 54
#define STANCE_STANDING_JUMP_11                 55
#define STANCE_STANDING_JUMP_12                 56
#define STANCE_STANDING_JUMP_13                 57
#define STANCE_STANDING_JUMP_14                 58
#define STANCE_STANDING_JUMP_15                 59
#define STANCE_STANDING_JUMP_16                 60
#define STANCE_STANDING_JUMP_17                 61
#define STANCE_STANDING_JUMP_18_END             62
#define STANCE_STEP_FWD_ONE_1_START             63
#define STANCE_STEP_FWD_ONE_2                   64
#define STANCE_STEP_FWD_ONE_3                   65
#define STANCE_STEP_FWD_ONE_4                   66    
#define STANCE_STEP_FWD_ONE_5                   67    
#define STANCE_STEP_FWD_ONE_6_END               68    
#define STANCE_STEP_FWD_TWO_1_START             69
#define STANCE_STEP_FWD_TWO_2                   70
#define STANCE_STEP_FWD_TWO_3                   71
#define STANCE_STEP_FWD_TWO_4                   72    
#define STANCE_STEP_FWD_TWO_5                   73    
#define STANCE_STEP_FWD_TWO_6_END               74
#define STANCE_SINGLE_STEP_1_START              75
#define STANCE_SINGLE_STEP_2                    76
#define STANCE_SINGLE_STEP_3                    77
#define STANCE_SINGLE_STEP_4                    78
#define STANCE_SINGLE_STEP_5                    79
#define STANCE_SINGLE_STEP_6                    80
#define STANCE_SINGLE_STEP_7                    81
#define STANCE_SINGLE_STEP_8_END                82

// Not sure about this set      
#define STANCE_STOPPING_1_START                 83
#define STANCE_STOPPING_2                       84
#define STANCE_STOPPING_3                       85
#define STANCE_STOPPING_4                       86
#define STANCE_STOPPING_5_END                   87
// Not sure about this set      

#define STANCE_CLIMBING_1_START                 88
#define STANCE_CLIMBING_2                       89
#define STANCE_CLIMBING_3                       90
#define STANCE_CLIMBING_4                       91
#define STANCE_CLIMBING_5                       92
#define STANCE_CLIMBING_6                       93
#define STANCE_CLIMBING_7                       94
#define STANCE_CLIMBING_8                       95
#define STANCE_CLIMBING_9                       96
#define STANCE_CLIMBING_10                      97
#define STANCE_CLIMBING_11                      98
#define STANCE_CLIMBING_12                      99
#define STANCE_CLIMBING_13                      100
#define STANCE_CLIMBING_14                      101
#define STANCE_CLIMBING_15_END                  102
#define STANCE_SMALL_STEP_1_START               103
#define STANCE_SMALL_STEP_2                     104
#define STANCE_SMALL_STEP_3                     105
#define STANCE_SMALL_STEP_4                     106
#define STANCE_SMALL_STEP_5                     107
#define STANCE_SMALL_STEP_6_END                 108
#define STANCE_JUMP_UP_A_1_START                109     /* Dist 2 */
#define STANCE_JUMP_UP_A_2                      110
#define STANCE_JUMP_UP_A_3                      111
#define STANCE_JUMP_UP_A_4                      112
#define STANCE_JUMP_UP_A_5                      113
#define STANCE_JUMP_UP_A_6                      114
#define STANCE_JUMP_UP_A_7                      115
#define STANCE_JUMP_UP_A_8                      116
#define STANCE_JUMP_UP_A_9                      117
#define STANCE_JUMP_UP_A_10                     118
#define STANCE_JUMP_UP_A_11                     119
#define STANCE_JUMP_UP_A_12                     120
#define STANCE_JUMP_UP_A_13                     121
#define STANCE_JUMP_UP_A_14_END                 122
#define STANCE_JUMP_UP_DROP_A_1_START           123  // Drop down to Pos 2
#define STANCE_JUMP_UP_DROP_A_2                 124
#define STANCE_JUMP_UP_DROP_A_3                 125
#define STANCE_JUMP_UP_DROP_A_4                 126
#define STANCE_JUMP_UP_DROP_A_5_END             127
#define STANCE_STEP_CLIMBING_1_START            128  // Climb up / down from a ledge (second part)
#define STANCE_STEP_CLIMBING_2                  129
#define STANCE_STEP_CLIMBING_3                  130
#define STANCE_STEP_CLIMBING_4                  131
#define STANCE_STEP_CLIMBING_5                  132
#define STANCE_STEP_CLIMBING_6                  133
#define STANCE_STEP_CLIMBING_7                  134
#define STANCE_STEP_CLIMBING_8                  135
#define STANCE_STEP_CLIMBING_9                  136
#define STANCE_STEP_CLIMBING_10                 137
#define STANCE_STEP_CLIMBING_11                 138
#define STANCE_STEP_CLIMBING_12                 139
#define STANCE_STEP_CLIMBING_13                 140
#define STANCE_STEP_CLIMBING_14                 141
#define STANCE_STEP_CLIMBING_15_END             142
#define STANCE_CROUCH_STAND_1_START             143
#define STANCE_CROUCH_STAND_2                   144
#define STANCE_CROUCH_STAND_3                   145
#define STANCE_CROUCH_STAND_4                   146
#define STANCE_CROUCH_STAND_5                   147
#define STANCE_CROUCH_STAND_6                   148
#define STANCE_CROUCH_STAND_7                   149
#define STANCE_CROUCH_STAND_8                   150
#define STANCE_CROUCH_STAND_9                   151
#define STANCE_CROUCH_STAND_10                  152
#define STANCE_CROUCH_STAND_11                  153
#define STANCE_CROUCH_STAND_12_END              154
#define STANCE_FALLING_A_1_START                155     /* While walking */
#define STANCE_FALLING_A_2                      156
#define STANCE_FALLING_A_3                      157
#define STANCE_FALLING_A_4                      158
#define STANCE_FALLING_A_5                      159
#define STANCE_FALLING_A_6_END                  160
#define STANCE_FALLING_B_1_START                161     /* If dst = 0, 4, 8 */
#define STANCE_FALLING_B_2                      162
#define STANCE_FALLING_B_3                      163
#define STANCE_FALLING_B_4                      164
#define STANCE_FALLING_B_5                      165
#define STANCE_FALLING_B_6_END                  166
#define STANCE_FALLING_C_1_START                167     /* If dst = 0, 4, 8 */
#define STANCE_FALLING_C_2                      168
#define STANCE_FALLING_C_3                      169
#define STANCE_FALLING_C_4                      170
#define STANCE_FALLING_C_5                      171
#define STANCE_FALLING_C_6_END                  172
#define STANCE_CROUCH_1_START                   173
#define STANCE_CROUCH_2                         174
#define STANCE_CROUCH_3_END                     175
#define STANCE_CROUCH_HOP_1_START               176
#define STANCE_CROUCH_HOP_2                     177
#define STANCE_CROUCH_HOP_3                     178
#define STANCE_CROUCH_HOP_4                     179
#define STANCE_CROUCH_HOP_5                     180
#define STANCE_CROUCH_HOP_6                     181
#define STANCE_CROUCH_HOP_7_END                 182
#define STANCE_STEP_CLIMBING_BLOCK_1_START      183
#define STANCE_STEP_CLIMBING_BLOCK_2            184
#define STANCE_STEP_CLIMBING_BLOCK_3            185
#define STANCE_STEP_CLIMBING_BLOCK_4            186
#define STANCE_STEP_CLIMBING_BLOCK_5            187
#define STANCE_STEP_CLIMBING_BLOCK_6            188
#define STANCE_STEP_CLIMBING_BLOCK_7            189
#define STANCE_STEP_CLIMBING_BLOCK_8            190
#define STANCE_STEP_CLIMBING_BLOCK_9_END        191
#define STANCE_JUMP_UP_B_1_START                192
#define STANCE_JUMP_UP_B_2                      193
#define STANCE_JUMP_UP_B_3                      194
#define STANCE_JUMP_UP_B_4                      195
#define STANCE_JUMP_UP_B_5                      196
#define STANCE_JUMP_UP_B_6                      197
#define STANCE_JUMP_UP_B_7                      198
#define STANCE_JUMP_UP_B_8                      199
#define STANCE_JUMP_UP_B_9                      200
#define STANCE_JUMP_UP_B_10                     201
#define STANCE_JUMP_UP_B_11                     202
#define STANCE_JUMP_UP_B_12                     203
#define STANCE_JUMP_UP_B_13                     204
#define STANCE_JUMP_UP_B_14_END                 205
#define STANCE_JUMP_UP_DROP_B_1_START           206  // Drop down to Pos 10
#define STANCE_JUMP_UP_DROP_B_2                 207
#define STANCE_JUMP_UP_DROP_B_3                 208
#define STANCE_JUMP_UP_DROP_B_4                 209
#define STANCE_JUMP_UP_DROP_B_5_END             210
#define STANCE_DRINK_TONIC_1_START              211 
#define STANCE_DRINK_TONIC_2                    212
#define STANCE_DRINK_TONIC_3                    213
#define STANCE_DRINK_TONIC_4                    214
#define STANCE_DRINK_TONIC_5                    215
#define STANCE_DRINK_TONIC_6                    216
#define STANCE_DRINK_TONIC_7                    217
#define STANCE_DRINK_TONIC_8                    218
#define STANCE_DRINK_TONIC_9                    219
#define STANCE_DRINK_TONIC_10                   220
#define STANCE_DRINK_TONIC_11                   221
#define STANCE_DRINK_TONIC_12                   222
#define STANCE_DRINK_TONIC_13                   223
#define STANCE_DRINK_TONIC_14                   224
#define STANCE_DRINK_TONIC_15_END               225
#define STANCE_JUMP_UP_DROP_C_1_START           226  // Drop down to Pos 2 (two levels)
#define STANCE_JUMP_UP_DROP_C_2                 227
#define STANCE_JUMP_UP_DROP_C_3                 228
#define STANCE_JUMP_UP_DROP_C_4                 229
#define STANCE_JUMP_UP_DROP_C_5_END             230
#define STANCE_FALLING_D_1_START                231  // Climbing down, falling two levels
#define STANCE_FALLING_D_2_END                  232
#define STANCE_FALLING_DEAD_1_START             233  // Climbing down, fall to death
#define STANCE_FALLING_DEAD_2                   234
#define STANCE_FALLING_DEAD_3_END               235
#define STANCE_RUN_REPEAT_8_END_TURN            236  // Single entry to allow x correction

#define STANCE_JUMP_DOWN_1_START        240
#define STANCE_JUMP_DOWN_2              240
#define STANCE_JUMP_DOWN_3              240
#define STANCE_SQUAT_1_START            240
#define STANCE_SQUAT_2                  240
#define STANCE_SQUAT_3_LOW_POINT        240
#define STANCE_SQUAT_4                  240
#define STANCE_SQUAT_5                  240
#define STANCE_SQUAT_6                  240
#define STANCE_SQUAT_7                  240
#define STANCE_SQUAT_8                  240
#define STANCE_SQUAT_9                  240
#define STANCE_SQUAT_10_END             240
#define STANCE_DYING_1_START            240
#define STANCE_DYING_2                  240
#define STANCE_DYING_3                  240
#define STANCE_DYING_4                  240
#define STANCE_DYING_5                  240
#define STANCE_DYING_6_END              240
#define STANCE_SQUAT_MOVE_1_START       240 // 55 STANCE_SQUAT_4
#define STANCE_SQUAT_MOVE_2             240 // 56 STANCE_SQUAT_5
#define STANCE_SQUAT_MOVE_3_END         240 // 57 STANCE_SQUAT_4
#define STANCE_SWINGING_1_START         240
#define STANCE_SWINGING_2               240
#define STANCE_SWINGING_3               240
#define STANCE_SWINGING_4               240
#define STANCE_SWINGING_5               240
#define STANCE_SWINGING_6               240
#define STANCE_SWINGING_7               240
#define STANCE_SWINGING_8               240
#define STANCE_SWINGING_9               240
#define STANCE_SWINGING_10              240
#define STANCE_SWINGING_11              240
#define STANCE_SWINGING_12_END          240

#define STANCE_SQUAT_ROTATE_01_START    240 //54
#define STANCE_SQUAT_ROTATE_02          240 //54
#define STANCE_SQUAT_ROTATE_03          240 //54
#define STANCE_SQUAT_ROTATE_04          240 //54
#define STANCE_SQUAT_ROTATE_05_END      240 //54

#define STANCE_UPRIGHT_END_CLIMB        253
#define STANCE_UPRIGHT_TURN             255

namespace Constants {

    constexpr uint8_t FrameRate = 30;
    constexpr uint8_t NumberOfItems = 20;
    constexpr uint8_t Animation_NumberOfFrames = 2;
    constexpr uint8_t NoItemFound = 255;

    constexpr uint8_t TileHeight = 31;
    constexpr uint8_t TileWidth = 12;
    constexpr uint8_t ScreenTopOffset = 1;
    constexpr uint8_t ScreenWidthInTiles = 10;


    constexpr int8_t Prince_XOffset[] PROGMEM = {
   
   //          001,      002,      003,      004,      005,      006,      007,      008,      009,      010,
   //         X    Y    X    Y    X    Y    X    Y    X    Y    X    Y    X    Y    X    Y    X    Y    X    Y  
   //         ------    ------    ------    ------    ------    ------    ------    ------    ------    ------
              0,   0,   1,   0,   1,   0,   1,   0,   2,   0,   2,   0,   3,   0,   3,   0,   3,   0,   3,   0,    //  001 - 010
              3,   0,   3,   0,   3,   0,   3,   0,   0,   0,   2,   0,   3,   0,   4,   0,   4,   0,   5,   0,    //  011 - 020
              6,   0,   6,   0,   6,   0,   5,   0,   3,   0,   2,   0,   0,   0,  -1,   0,  -1,   0,   2,   0,    //  021 - 030
              
              0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,    //  031 - 040
              0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   2,   0,   2,   0,   2,   0,   2,   0,    //  041 - 050
              2,   0,   3,   0,   3,   0,   3,   0,   3,   0,   4,   0,   2,   0,   2,   0,   2,   0,   2,   0,    //  051 - 060

              1,   0,   1,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,    //  061 - 070
              0,   0,   0,   0,   0,   0,   0,   0,   1,   0,   1,   0,   1,   0,   1,   0,   1,   0,   1,   0,    //  071 - 080
              1,   0,   1,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,    //  081 - 090

              0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,    //  091 - 100
              0,   0,   0,   0,   1,   0,   1,   0,   1,   0,   1,   0,   0,   0,   0,   0,   0,   0,   0,   0,    //  101 - 110
              0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,    //  111 - 120

              0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  -4,   0,  -4,   0,  -2,    //  121 - 130
              0,  -3,   0,  -2,   0,  -2,   0,  -3,   0,  -3,   0,  -1,   1,  -3,   1,  -2,   0,  -1,   1,  -1,    //  131 - 140
              1,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,    //  141 - 150

              0,   0,   0,   0,   0,   0,   0,   0,   3,   6,   2,   5,   2,   5,   0,   5,   0,   5,   0,   5,    //  151 - 160
              5,   6,   5,   5,   4,   5,   0,   5,   0,   5,   0,   5,   5,   6,   4,   3,   4,   5,   0,   5,    //  161 - 170
              0,   5,   0,   5,   0,   0,   0,   0,   0,   0,   0,   0,   1,   0,   1,   0,   1,   0,   1,   0,    //  171 - 180

              0,   0,   0,   0,   0,  -4,   0,  -4,   0,  -2,   0,  -3,   0,   0,   0,   3,   0,   2,   0,   4,    //  181 - 190
              0,   4,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,    //  191 - 200
             -1,   0,  -1,   0,  -1,   0,  -1,   0,   0,   0,   1,   0,   1,   0,   1,   0,   1,   0,   0,   0,    //  201 - 210

              0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,    //  211 - 220
              0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   6,   0,   6,   0,   6,   0,   6,   0,   7,    //  221 - 230
              0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   4,   0,   0,   0,   0,   0,   0,   0,   0,   0,    //  231 - 240

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
/* 015 */  3, 1, -3,
/* 016 */  9, 8, 2,
/* 017 */  7, 0, -4,
/* 018 */  9, -5, -9,
/* 019 */  10, 10, 6,
/* 020 */  5, 1, -3,
/* 021 */  9, -5, -6,
/* 022 */  10, -12, -12,
/* 023 */  13, -6, -14,
/* 024 */  11, 9, 8,
/* 025 */  11, 10, 7,
/* 026 */  7, 5, 0,
/* 027 */  5, 2, -3,
/* 028 */  5, 1, -2,
/* 029 */  6, 3, -4,
/* 030 */  6, 3, -1,
/* 031 */  6, 5, 1,
/* 032 */  8, 8, 3,
/* 033 */  6, 4, -2,
/* 034 */  10, 10, 5,
/* 035 */  8, 6, 1,
/* 036 */  7, -4, -6,
/* 037 */  8, -3, -4,
/* 038 */  9, 1, 4,
/* 039 */  8, 3, 6,
/* 040 */  9, 0, -4,
/* 041 */  9, 8, 7,
/* 042 */  11, 10, 7,
/* 043 */  8, 7, 5,
/* 044 */  8, 7, 5,
/* 045 */  3, 2, -4,
/* 046 */  3, 1, -4,
/* 047 */  5, 2, -3,
/* 048 */  6, 0, -5,
/* 049 */  7, -1, -5,
/* 050 */  7, -2, -8,
/* 051 */  9, -5, -7,
/* 052 */  11, -8, -10,
/* 053 */  14, -11, -14,
/* 054 */  14, -12, -13,
/* 055 */  12, 10, 8,
/* 056 */  8, 5, 1,
/* 057 */  5, 3, -1,
/* 058 */  7, 5, 4,
/* 059 */  6, 6, 1,
/* 060 */  0, 0, 0,
/* 061 */  0, 0, 0,
/* 062 */  0, 0, 0,
/* 063 */  0, 0, 0,
/* 064 */  0, 0, 0,
/* 065 */  0, 0, 0,
/* 066 */  0, 0, 0,
/* 067 */  0, 0, 0,
/* 068 */  0, 0, 0,
/* 069 */  0, 0, 0,
/* 070 */  0, 0, 0,
/* 071 */  0, 0, 0,
/* 072 */  0, 0, 0,
/* 073 */  0, 0, 0,
/* 074 */  0, 0, 0,
/* 075 */  0, 0, 0,
/* 076 */  0, 0, 0,
/* 077 */  0, 0, 0,
/* 078 */  0, 0, 0,
/* 079 */  0, 0, 0,
/* 080 */  0, 0, 0,
/* 081 */  0, 0, 0,
/* 082 */  0, 0, 0,
/* 083 */  0, 0, 0,
/* 084 */  0, 0, 0,
/* 085 */  0, 0, 0,
/* 086 */  0, 0, 0,
/* 087 */  0, 0, 0,
/* 088 */  0, 0, 0,
/* 089 */  0, 0, 0,
/* 090 */  0, 0, 0,
/* 091 */  0, 0, 0,
/* 092 */  0, 0, 0,
/* 093 */  0, 0, 0,
/* 094 */  0, 0, 0,
/* 095 */  0, 0, 0,
/* 096 */  0, 0, 0,
/* 097 */  0, 0, 0,
/* 098 */  0, 0, 0,
/* 099 */  0, 0, 0,
/* 100 */  0, 0, 0,
/* 101 */  0, 0, 0,
/* 102 */  0, 0, 0,
/* 103 */  0, 0, 0,
/* 104 */  0, 0, 0,
/* 105 */  0, 0, 0,
/* 106 */  0, 0, 0,
/* 107 */  0, 0, 0,
/* 108 */  0, 0, 0,
/* 109 */  0, 0, 0,
/* 110 */  0, 0, 0,
/* 111 */  0, 0, 0,
/* 112 */  0, 0, 0,
/* 113 */  0, 0, 0,
/* 114 */  0, 0, 0,
/* 115 */  0, 0, 0,
/* 116 */  0, 0, 0,
/* 117 */  0, 0, 0,
/* 118 */  0, 0, 0,
/* 119 */  0, 0, 0,
/* 120 */  0, 0, 0,
/* 121 */  0, 0, 0,
/* 122 */  0, 0, 0,
/* 123 */  0, 0, 0,
/* 124 */  0, 0, 0,
/* 125 */  0, 0, 0,
/* 126 */  0, 0, 0,
/* 127 */  0, 0, 0,
/* 128 */  0, 0, 0,
/* 129 */  0, 0, 0,
/* 130 */  0, 0, 0,
/* 131 */  0, 0, 0,
/* 132 */  0, 0, 0,
/* 133 */  0, 0, 0,
/* 134 */  0, 0, 0,
/* 135 */  0, 0, 0,
/* 136 */  0, 0, 0,
/* 137 */  0, 0, 0,
/* 138 */  0, 0, 0,
/* 139 */  0, 0, 0,
/* 140 */  0, 0, 0,
/* 141 */  0, 0, 0,
/* 142 */  0, 0, 0,

};


}

enum GameState : uint8_t {
	SplashScreen_Init,
	SplashScreen,
	Title_Init,
	Title,
	Game_Init,
	Game,
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
    /* 00 */ Gate,               
    /* 01 */ Torch,
    /* 02 */ Door,
    /* 03 */ Sword,
    /* 04 */ CollapsingFloor,
    /* 05 */ CollpasedFloor,
    /* 06 */ Potion_Small,
};

enum class MenuOption : uint8_t {
    Resume,
    Save,
    Load,
    MainMenu,
};