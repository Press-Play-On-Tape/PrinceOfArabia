
#pragma once

#define DEBUG_PRINT    Serial.print
#define DEBUG_PRINTLN  Serial.println

#define DEBUG
#define DEBUG_ONSCREEN_DETAILS

#define _DEBUG_PRINCE_DETAILS
#define _DEBUG_PRINCE_STACK
#define _DEBUG_PRINT_ACTION
#define DEBUG_LEVEL_LOAD_MAP
#define _DEBUG_PRINCE_RENDERING

#define _DEBUG_ACTION_CANMOVEFORWARD
#define _DEBUG_ACTION_CANJUMPUP
#define _DEBUG_ACTION_CANJUMPUP_PART2
#define _DEBUG_ACTION_CANCLIMBDOWN
#define DEBUG_ACTION_CANCLIMBDOWN_PART2
#define _DEBUG_ACTION_CANFALL

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
#define STANCE_RUN_REPEAT_8_END_TURN    254
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