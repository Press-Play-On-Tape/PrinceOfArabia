
#pragma once


#define DEBUG_PRINT    Serial.print
#define DEBUG_PRINTLN  Serial.println

#define DEBUG
#define DEBUG_PRINCE_DETAILS
#define _DEBUG_PRINCE_STACK
#define _DEBUG_PRINT_ACTION
#define _DEBUG_LEVEL_LOAD_MAP

#define DEBUG_ACTION_CANMOVEFORWARD
#define _DEBUG_ACTION_CANJUMPUP
#define _DEBUG_ACTION_CANCLIMBDOWN
#define DEBUG_ONSCREEN_DETAILS

//-------------------------------------------------------------------------------------

#define ANIMATION_NUMBER_OF_FRAMES      2
#define NUMBER_OF_ITEMS                 20

#define STANCE_NONE                     0
#define STANCE_RUN_START_1_START        1 
#define STANCE_RUN_START_2              2 
#define STANCE_RUN_START_3              3 
#define STANCE_RUN_START_4              4 
#define STANCE_RUN_START_5              5 
#define STANCE_RUN_START_6_END          6 
#define STANCE_RUN_REPEAT_1_START       7 
#define STANCE_RUN_REPEAT_2             8 
#define STANCE_RUN_REPEAT_3             9 
#define STANCE_RUN_REPEAT_4             10 
#define STANCE_RUN_REPEAT_5_MID         11 
#define STANCE_RUN_REPEAT_6             12 
#define STANCE_RUN_REPEAT_7             13 
#define STANCE_RUN_REPEAT_8_END         14 
#define STANCE_UPRIGHT                  15
#define STANCE_RUNNING_JUMP_1_START     16
#define STANCE_RUNNING_JUMP_2           17
#define STANCE_RUNNING_JUMP_3           18
#define STANCE_RUNNING_JUMP_4           19
#define STANCE_RUNNING_JUMP_5           20
#define STANCE_RUNNING_JUMP_6           21
#define STANCE_RUNNING_JUMP_7           22
#define STANCE_RUNNING_JUMP_8           23
#define STANCE_RUNNING_JUMP_9           24
#define STANCE_RUNNING_JUMP_10          25
#define STANCE_RUNNING_JUMP_11_END      26
#define STANCE_STANDING_TURN_1_START    27 
#define STANCE_STANDING_TURN_2          28 
#define STANCE_STANDING_TURN_3          29 
#define STANCE_STANDING_TURN_4          30 
#define STANCE_STANDING_TURN_5_END      31 
#define STANCE_RUNNING_TURN_1_START     32   // 15 STANCE_STOPPING_1_START         
#define STANCE_RUNNING_TURN_2           33   // 16 STANCE_STANDING_2
#define STANCE_RUNNING_TURN_3           34   // 17 STANCE_STANDING_3
#define STANCE_RUNNING_TURN_4           35   // 18 STANCE_STANDING_4
#define STANCE_RUNNING_TURN_5           36   
#define STANCE_RUNNING_TURN_6           37 
#define STANCE_RUNNING_TURN_7           38 
#define STANCE_RUNNING_TURN_8           39 
#define STANCE_RUNNING_TURN_9           40 
#define STANCE_RUNNING_TURN_10          41 
#define STANCE_RUNNING_TURN_11          42 
#define STANCE_RUNNING_TURN_12          43 
#define STANCE_RUNNING_TURN_13_END      44 
#define STANCE_STANDING_JUMP_1_START    45
#define STANCE_STANDING_JUMP_2          46
#define STANCE_STANDING_JUMP_3          47
#define STANCE_STANDING_JUMP_4          48
#define STANCE_STANDING_JUMP_5          49
#define STANCE_STANDING_JUMP_6          50
#define STANCE_STANDING_JUMP_7          51
#define STANCE_STANDING_JUMP_8          52
#define STANCE_STANDING_JUMP_9          53
#define STANCE_STANDING_JUMP_10         54
#define STANCE_STANDING_JUMP_11         55
#define STANCE_STANDING_JUMP_12         56
#define STANCE_STANDING_JUMP_13         57
#define STANCE_STANDING_JUMP_14         58
#define STANCE_STANDING_JUMP_15         59
#define STANCE_STANDING_JUMP_16         60
#define STANCE_STANDING_JUMP_17         61
#define STANCE_STANDING_JUMP_18_END     62
#define STANCE_STEP_FWD_ONE_1_START     63
#define STANCE_STEP_FWD_ONE_2           64
#define STANCE_STEP_FWD_ONE_3           65
#define STANCE_STEP_FWD_ONE_4           66    
#define STANCE_STEP_FWD_ONE_5           67    
#define STANCE_STEP_FWD_ONE_6_END       68    
#define STANCE_STEP_FWD_TWO_1_START     69
#define STANCE_STEP_FWD_TWO_2           70
#define STANCE_STEP_FWD_TWO_3           71
#define STANCE_STEP_FWD_TWO_4           72    
#define STANCE_STEP_FWD_TWO_5           73    
#define STANCE_STEP_FWD_TWO_6_END       74
#define STANCE_SINGLE_STEP_1_START      75
#define STANCE_SINGLE_STEP_2            76
#define STANCE_SINGLE_STEP_3            77
#define STANCE_SINGLE_STEP_4            78
#define STANCE_SINGLE_STEP_5            79
#define STANCE_SINGLE_STEP_6            80
#define STANCE_SINGLE_STEP_7            81
#define STANCE_SINGLE_STEP_8_END        82

// Not sure about this set
#define STANCE_STOPPING_1_START         83
#define STANCE_STOPPING_2               84
#define STANCE_STOPPING_3               85
#define STANCE_STOPPING_4               86
#define STANCE_STOPPING_5_END           87
// Not sure about this set

#define STANCE_CLIMBING_1_START         88
#define STANCE_CLIMBING_2               89
#define STANCE_CLIMBING_3               90
#define STANCE_CLIMBING_4               91
#define STANCE_CLIMBING_5               92
#define STANCE_CLIMBING_6               93
#define STANCE_CLIMBING_7               94
#define STANCE_CLIMBING_8               95
#define STANCE_CLIMBING_9               96
#define STANCE_CLIMBING_10              97
#define STANCE_CLIMBING_11              98
#define STANCE_CLIMBING_12              99
#define STANCE_CLIMBING_13              100
#define STANCE_CLIMBING_14              101
#define STANCE_CLIMBING_15_END          102
#define STANCE_SMALL_STEP_1_START       103
#define STANCE_SMALL_STEP_2             104
#define STANCE_SMALL_STEP_3             105
#define STANCE_SMALL_STEP_4             106
#define STANCE_SMALL_STEP_5             107
#define STANCE_SMALL_STEP_6_END         108
#define STANCE_JUMP_UP_1_START          109
#define STANCE_JUMP_UP_2                110
#define STANCE_JUMP_UP_3                111
#define STANCE_JUMP_UP_4                112
#define STANCE_JUMP_UP_5                113
#define STANCE_JUMP_UP_6                114
#define STANCE_JUMP_UP_7                115
#define STANCE_JUMP_UP_8                116
#define STANCE_JUMP_UP_9                117
#define STANCE_JUMP_UP_10               118
#define STANCE_JUMP_UP_11               119
#define STANCE_JUMP_UP_12               120
#define STANCE_JUMP_UP_13               121
#define STANCE_JUMP_UP_14_END           122
#define STANCE_JUMP_UP_DROP_1_START     123
#define STANCE_JUMP_UP_DROP_2           124
#define STANCE_JUMP_UP_DROP_3           125
#define STANCE_JUMP_UP_DROP_4           126
#define STANCE_JUMP_UP_DROP_5_END       127
#define STANCE_STEP_CLIMBING_1_START    128
#define STANCE_STEP_CLIMBING_2          129
#define STANCE_STEP_CLIMBING_3          130
#define STANCE_STEP_CLIMBING_4          131
#define STANCE_STEP_CLIMBING_5          132
#define STANCE_STEP_CLIMBING_6          133
#define STANCE_STEP_CLIMBING_7          134
#define STANCE_STEP_CLIMBING_8          135
#define STANCE_STEP_CLIMBING_9          136
#define STANCE_STEP_CLIMBING_10         137
#define STANCE_STEP_CLIMBING_11         138
#define STANCE_STEP_CLIMBING_12         139
#define STANCE_STEP_CLIMBING_13         140
#define STANCE_STEP_CLIMBING_14         141
#define STANCE_STEP_CLIMBING_15_END     142
#define STANCE_CROUCH_STAND_1_START     143
#define STANCE_CROUCH_STAND_2           144
#define STANCE_CROUCH_STAND_3           145
#define STANCE_CROUCH_STAND_4           146
#define STANCE_CROUCH_STAND_5           147
#define STANCE_CROUCH_STAND_6           148
#define STANCE_CROUCH_STAND_7           149
#define STANCE_CROUCH_STAND_8           150
#define STANCE_CROUCH_STAND_9           151
#define STANCE_CROUCH_STAND_10          152
#define STANCE_CROUCH_STAND_11          153
#define STANCE_CROUCH_STAND_12_END      154
#define STANCE_FALLING_A_1_START        155     /* While walking */
#define STANCE_FALLING_A_2              156
#define STANCE_FALLING_A_3              157
#define STANCE_FALLING_A_4              158
#define STANCE_FALLING_A_5              159
#define STANCE_FALLING_A_6_END          160
#define STANCE_FALLING_B_1_START        161     /* If dst = 0, 4, 8 */
#define STANCE_FALLING_B_2              162
#define STANCE_FALLING_B_3              163
#define STANCE_FALLING_B_4              164
#define STANCE_FALLING_B_5              165
#define STANCE_FALLING_B_6_END          166
#define STANCE_FALLING_C_1_START        167     /* If dst = 0, 4, 8 */
#define STANCE_FALLING_C_2              168
#define STANCE_FALLING_C_3              169
#define STANCE_FALLING_C_4              170
#define STANCE_FALLING_C_5              171
#define STANCE_FALLING_C_6_END          172
#define STANCE_CROUCH_1_START           173
#define STANCE_CROUCH_2                 174
#define STANCE_CROUCH_3_END             175
#define STANCE_CROUCH_HOP_1_START       176
#define STANCE_CROUCH_HOP_2             177
#define STANCE_CROUCH_HOP_3             178
#define STANCE_CROUCH_HOP_4             179
#define STANCE_CROUCH_HOP_5             180
#define STANCE_CROUCH_HOP_6             181
#define STANCE_CROUCH_HOP_7_END         182




#define STANCE_JUMP_DOWN_1_START        220
#define STANCE_JUMP_DOWN_2              220
#define STANCE_JUMP_DOWN_3              220
#define STANCE_SQUAT_1_START            220
#define STANCE_SQUAT_2                  220
#define STANCE_SQUAT_3_LOW_POINT        220
#define STANCE_SQUAT_4                  220
#define STANCE_SQUAT_5                  220
#define STANCE_SQUAT_6                  220
#define STANCE_SQUAT_7                  220
#define STANCE_SQUAT_8                  220
#define STANCE_SQUAT_9                  220
#define STANCE_SQUAT_10_END             220
#define STANCE_DYING_1_START            220
#define STANCE_DYING_2                  220
#define STANCE_DYING_3                  220
#define STANCE_DYING_4                  220
#define STANCE_DYING_5                  220
#define STANCE_DYING_6_END              220
#define STANCE_SQUAT_MOVE_1_START       220 // 55 STANCE_SQUAT_4
#define STANCE_SQUAT_MOVE_2             220 // 56 STANCE_SQUAT_5
#define STANCE_SQUAT_MOVE_3_END         220 // 57 STANCE_SQUAT_4
#define STANCE_SWINGING_1_START         220
#define STANCE_SWINGING_2               220
#define STANCE_SWINGING_3               220
#define STANCE_SWINGING_4               220
#define STANCE_SWINGING_5               220
#define STANCE_SWINGING_6               220
#define STANCE_SWINGING_7               220
#define STANCE_SWINGING_8               220
#define STANCE_SWINGING_9               220
#define STANCE_SWINGING_10              220
#define STANCE_SWINGING_11              220
#define STANCE_SWINGING_12_END          220
// #define STANCE_FALLING_A_1_START          220 // 62 STANCE_DYING_1_START   
// #define STANCE_FALLING_2                220 // 62 STANCE_DYING_1_START   
// #define STANCE_FALLING_3_END            220 // 62 STANCE_DYING_1_START   
// #define STANCE_FALLING_3_ADJ            220 // 62 STANCE_DYING_1_START   
#define STANCE_DRINK_TONIC_1_START      220 
#define STANCE_DRINK_TONIC_2            220
#define STANCE_DRINK_TONIC_3            220
#define STANCE_DRINK_TONIC_4            220
#define STANCE_DRINK_TONIC_5            220
#define STANCE_DRINK_TONIC_6            220
#define STANCE_DRINK_TONIC_7            220
#define STANCE_DRINK_TONIC_8            220
#define STANCE_DRINK_TONIC_9            220
#define STANCE_DRINK_TONIC_10           220
#define STANCE_DRINK_TONIC_11           220
#define STANCE_DRINK_TONIC_12           220
#define STANCE_DRINK_TONIC_13           220
#define STANCE_DRINK_TONIC_14           220
#define STANCE_DRINK_TONIC_15           220
#define STANCE_DRINK_TONIC_16           220
#define STANCE_DRINK_TONIC_17           220
#define STANCE_DRINK_TONIC_18_END       220
#define STANCE_SQUAT_ROTATE_01_START    220 //54
#define STANCE_SQUAT_ROTATE_02          220 //54
#define STANCE_SQUAT_ROTATE_03          220 //54
#define STANCE_SQUAT_ROTATE_04          220 //54
#define STANCE_SQUAT_ROTATE_05_END      220 //54

#define STANCE_UPRIGHT_END_CLIMB        253
#define STANCE_RUN_REPEAT_8_END_TURN    254
#define STANCE_UPRIGHT_TURN             255

enum GameState : uint8_t {
	SplashScreen_Init,
	SplashScreen,
	Title_Init,
	Title,
	Game_Init,
	Game,
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

enum class CanJumpResult : uint8_t {
    None,
    Jump,
    StepThenJump,
    JumpThenFall,
    TurnThenJump,
};

enum class CanClimbDownResult : uint8_t {
    None,
    ClimbDown,
    StepThenClimbDown,
    TurnThenClimbDown,
    StepThenTurnThenClimbDown,
};

enum class ItemType : uint8_t {
    Gate,
    Torch,
    Door,
    Sword,
};