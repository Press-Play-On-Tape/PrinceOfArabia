
#pragma once

#define DEBUG_PRINT    Serial.print
#define DEBUG_PRINTLN  Serial.println

#define DEBUG
#define DEBUG_ONSCREEN_DETAILS
#define _DEBUG_ONSCREEN_DETAILS_MIN

#define _DEBUG_PRINCE_DETAILS
#define DEBUG_PRINCE_STACK
#define _DEBUG_PRINT_ACTION
#define _DEBUG_LEVEL_LOAD_MAP
#define _DEBUG_PRINCE_RENDERING

#define _DEBUG_ACTION_CANMOVEFORWARD
#define _DEBUG_ACTION_CANJUMPUP
#define _DEBUG_ACTION_CANJUMPUP_PART2
#define _DEBUG_ACTION_CANCLIMBDOWN
#define _DEBUG_ACTION_CANCLIMBDOWN_PART2
#define _DEBUG_ACTION_CANFALL
#define _DEBUG_ACTION_COLLIDEWITHWALL

//-------------------------------------------------------------------------------------

namespace Stance {

constexpr uint16_t None                                          = 0;
constexpr uint16_t Run_Start_1_Start                             = 1;
constexpr uint16_t Run_Start_2                                   = 2;
constexpr uint16_t Run_Start_3                                   = 3;
constexpr uint16_t Run_Start_4                                   = 4;
constexpr uint16_t Run_Start_5                                   = 5;
constexpr uint16_t Run_Start_6_End                               = 6;
constexpr uint16_t Run_Repeat_1_Start                            = 7;
constexpr uint16_t Run_Repeat_2                                  = 8;
constexpr uint16_t Run_Repeat_3                                  = 9;
constexpr uint16_t Run_Repeat_4                                  = 10; 
constexpr uint16_t Run_Repeat_5_Mid                              = 11; 
constexpr uint16_t Run_Repeat_6                                  = 12; 
constexpr uint16_t Run_Repeat_7                                  = 13; 
constexpr uint16_t Run_Repeat_8_End                              = 14; 
constexpr uint16_t Upright                                       = 15;
constexpr uint16_t Running_Jump_1_Start                          = 16;
constexpr uint16_t Running_Jump_2                                = 17;
constexpr uint16_t Running_Jump_3                                = 18;
constexpr uint16_t Running_Jump_4                                = 19;
constexpr uint16_t Running_Jump_5                                = 20;
constexpr uint16_t Running_Jump_6                                = 21;
constexpr uint16_t Running_Jump_7                                = 22;
constexpr uint16_t Running_Jump_8                                = 23;
constexpr uint16_t Running_Jump_9                                = 24;
constexpr uint16_t Running_Jump_10                               = 25;
constexpr uint16_t Running_Jump_11_End                           = 26;
constexpr uint16_t Standing_Turn_1_Start                         = 27; 
constexpr uint16_t Standing_Turn_2                               = 28; 
constexpr uint16_t Standing_Turn_3                               = 29; 
constexpr uint16_t Standing_Turn_4                               = 30; 
constexpr uint16_t Standing_Turn_5_End                           = 31; 
constexpr uint16_t Running_Turn_1_Start                          = 32;   // 15 Stopping_1_Start         
constexpr uint16_t Running_Turn_2                                = 33;   // 16 STANCE_STANDING_2
constexpr uint16_t Running_Turn_3                                = 34;   // 17 STANCE_STANDING_3
constexpr uint16_t Running_Turn_4                                = 35;   // 18 STANCE_STANDING_4
constexpr uint16_t Running_Turn_5                                = 36;   
constexpr uint16_t Running_Turn_6                                = 37; 
constexpr uint16_t Running_Turn_7                                = 38; 
constexpr uint16_t Running_Turn_8                                = 39; 
constexpr uint16_t Running_Turn_9                                = 40; 
constexpr uint16_t Running_Turn_10                               = 41; 
constexpr uint16_t Running_Turn_11                               = 42; 
constexpr uint16_t Running_Turn_12                               = 43; 
constexpr uint16_t Running_Turn_13_End                           = 44; 
constexpr uint16_t Standing_Jump_1_Start                         = 45;
constexpr uint16_t Standing_Jump_2                               = 46;
constexpr uint16_t Standing_Jump_3                               = 47;
constexpr uint16_t Standing_Jump_4                               = 48;
constexpr uint16_t Standing_Jump_5                               = 49;
constexpr uint16_t Standing_Jump_6                               = 50;
constexpr uint16_t Standing_Jump_7                               = 51;
constexpr uint16_t Standing_Jump_8                               = 52;
constexpr uint16_t Standing_Jump_9                               = 53;
constexpr uint16_t Standing_Jump_10                              = 54;
constexpr uint16_t Standing_Jump_11_Land_Point                   = 55;
constexpr uint16_t Standing_Jump_12                              = 56;
constexpr uint16_t Standing_Jump_13                              = 57;
constexpr uint16_t Standing_Jump_14                              = 58;
constexpr uint16_t Standing_Jump_15                              = 59;
constexpr uint16_t Standing_Jump_16                              = 60;
constexpr uint16_t Standing_Jump_17                              = 61;
constexpr uint16_t Standing_Jump_18_End                          = 62;
constexpr uint16_t Step_Fwd_One_1_Start                          = 63;
constexpr uint16_t Step_Fwd_One_2                                = 64;
constexpr uint16_t Step_Fwd_One_3                                = 65;
constexpr uint16_t Step_Fwd_One_4                                = 66;    
constexpr uint16_t Step_Fwd_One_5                                = 67;    
constexpr uint16_t Step_Fwd_One_6_End                            = 68;    
constexpr uint16_t Step_Fwd_Two_1_Start                          = 69;
constexpr uint16_t Step_Fwd_Two_2                                = 70;
constexpr uint16_t Step_Fwd_Two_3                                = 71;
constexpr uint16_t Step_Fwd_Two_4                                = 72;    
constexpr uint16_t Step_Fwd_Two_5                                = 73;    
constexpr uint16_t Step_Fwd_Two_6_End                            = 74;
constexpr uint16_t Single_Step_1_Start                           = 75;
constexpr uint16_t Single_Step_2                                 = 76;
constexpr uint16_t Single_Step_3                                 = 77;
constexpr uint16_t Single_Step_4                                 = 78;
constexpr uint16_t Single_Step_5                                 = 79;
constexpr uint16_t Single_Step_6                                 = 80;
constexpr uint16_t Single_Step_7                                 = 81;
constexpr uint16_t Single_Step_8_End                             = 82;

// Not sure about this set              
constexpr uint16_t Stopping_1_Start                              = 83;
constexpr uint16_t Stopping_2                                    = 84;
constexpr uint16_t Stopping_3                                    = 85;
constexpr uint16_t Stopping_4                                    = 86;
constexpr uint16_t Stopping_5_End                                = 87;
// Not sure about this set              

constexpr uint16_t Climbing_1_Start                              = 88;
constexpr uint16_t Climbing_2                                    = 89;
constexpr uint16_t Climbing_3                                    = 90;
constexpr uint16_t Climbing_4                                    = 91;
constexpr uint16_t Climbing_5                                    = 92;
constexpr uint16_t Climbing_6                                    = 93;
constexpr uint16_t Climbing_7                                    = 94;
constexpr uint16_t Climbing_8                                    = 95;
constexpr uint16_t Climbing_9                                    = 96;
constexpr uint16_t Climbing_10                                   = 97;
constexpr uint16_t Climbing_11                                   = 98;
constexpr uint16_t Climbing_12                                   = 99;
constexpr uint16_t Climbing_13                                   = 100;
constexpr uint16_t Climbing_14                                   = 101;
constexpr uint16_t Climbing_15_End                               = 102;
constexpr uint16_t Small_Step_1_Start                            = 103;
constexpr uint16_t Small_Step_2                                  = 104;
constexpr uint16_t Small_Step_3                                  = 105;
constexpr uint16_t Small_Step_4                                  = 106;
constexpr uint16_t Small_Step_5                                  = 107;
constexpr uint16_t Small_Step_6_End                              = 108;
constexpr uint16_t Jump_Up_A_1_Start                             = 109;     /* Dist 2 */
constexpr uint16_t Jump_Up_A_2                                   = 110;
constexpr uint16_t Jump_Up_A_3                                   = 111;
constexpr uint16_t Jump_Up_A_4                                   = 112;
constexpr uint16_t Jump_Up_A_5                                   = 113;
constexpr uint16_t Jump_Up_A_6                                   = 114;
constexpr uint16_t Jump_Up_A_7                                   = 115;
constexpr uint16_t Jump_Up_A_8                                   = 116;
constexpr uint16_t Jump_Up_A_9                                   = 117;
constexpr uint16_t Jump_Up_A_10                                  = 118;
constexpr uint16_t Jump_Up_A_11                                  = 119;
constexpr uint16_t Jump_Up_A_12                                  = 120;
constexpr uint16_t Jump_Up_A_13                                  = 121;
constexpr uint16_t Jump_Up_A_14_End                              = 122;
constexpr uint16_t Jump_Up_Drop_A_1_Start                        = 123;  // Drop down to Pos 2
constexpr uint16_t Jump_Up_Drop_A_2                              = 124;
constexpr uint16_t Jump_Up_Drop_A_3                              = 125;
constexpr uint16_t Jump_Up_Drop_A_4                              = 126;
constexpr uint16_t Jump_Up_Drop_A_5_End                          = 127;
constexpr uint16_t Step_Climbing_1_Start                         = 128;  // Climb up / down from a ledge (second part)
constexpr uint16_t Step_Climbing_2                               = 129;
constexpr uint16_t Step_Climbing_3                               = 130;
constexpr uint16_t Step_Climbing_4                               = 131;
constexpr uint16_t Step_Climbing_5                               = 132;
constexpr uint16_t Step_Climbing_6                               = 133;
constexpr uint16_t Step_Climbing_7                               = 134;
constexpr uint16_t Step_Climbing_8                               = 135;
constexpr uint16_t Step_Climbing_9                               = 136;
constexpr uint16_t Step_Climbing_10                              = 137;
constexpr uint16_t Step_Climbing_11                              = 138;
constexpr uint16_t Step_Climbing_12                              = 139;
constexpr uint16_t Step_Climbing_13                              = 140;
constexpr uint16_t Step_Climbing_14                              = 141;
constexpr uint16_t Step_Climbing_15_End                          = 142;
constexpr uint16_t Crouch_Stand_1_Start                          = 143;
constexpr uint16_t Crouch_Stand_2                                = 144;
constexpr uint16_t Crouch_Stand_3                                = 145;
constexpr uint16_t Crouch_Stand_4                                = 146;
constexpr uint16_t Crouch_Stand_5                                = 147;
constexpr uint16_t Crouch_Stand_6                                = 148;
constexpr uint16_t Crouch_Stand_7                                = 149;
constexpr uint16_t Crouch_Stand_8                                = 150;
constexpr uint16_t Crouch_Stand_9                                = 151;
constexpr uint16_t Crouch_Stand_10                               = 152;
constexpr uint16_t Crouch_Stand_11                               = 153;
constexpr uint16_t Crouch_Stand_12_End                           = 154;
constexpr uint16_t Falling_SmallStep_1_Start                     = 155;
constexpr uint16_t Falling_SmallStep_2                           = 156;
constexpr uint16_t Falling_SmallStep_3                           = 157;
constexpr uint16_t Falling_SmallStep_4                           = 158;
constexpr uint16_t Falling_SmallStep_5_Check_CanFall             = 159;
constexpr uint16_t Falling_SmallStep_6_End                       = 160;
constexpr uint16_t Falling_RunningJump_1_Start                   = 161;     /* If dst = 0, 4, 8 */
constexpr uint16_t Falling_RunningJump_2                         = 162;
constexpr uint16_t Falling_RunningJump_3                         = 163;
constexpr uint16_t Falling_RunningJump_4                         = 164;
constexpr uint16_t Falling_RunningJump_5_Check_CanFall           = 165;
constexpr uint16_t Falling_RunningJump_6_End                     = 166;
constexpr uint16_t Falling_C_1_Start                             = 167;     /* If dst = 0, 4, 8 */
constexpr uint16_t Falling_C_2                                   = 168;
constexpr uint16_t Falling_C_3                                   = 169;
constexpr uint16_t Falling_C_4                                   = 170;
constexpr uint16_t Falling_C_5_Check_CanFall                     = 171;
constexpr uint16_t Falling_C_6_End                               = 172;
constexpr uint16_t Crouch_1_Start                                = 173;
constexpr uint16_t Crouch_2                                      = 174;
constexpr uint16_t Crouch_3_End                                  = 175;
constexpr uint16_t Crouch_HOP_1_Start                            = 176;
constexpr uint16_t Crouch_HOP_2                                  = 177;
constexpr uint16_t Crouch_HOP_3                                  = 178;
constexpr uint16_t Crouch_HOP_4                                  = 179;
constexpr uint16_t Crouch_HOP_5                                  = 180;
constexpr uint16_t Crouch_HOP_6                                  = 181;
constexpr uint16_t Crouch_HOP_7_End                              = 182;
constexpr uint16_t Step_Climbing_Block_1_Start                   = 183;
constexpr uint16_t Step_Climbing_Block_2                         = 184;
constexpr uint16_t Step_Climbing_Block_3                         = 185;
constexpr uint16_t Step_Climbing_Block_4                         = 186;
constexpr uint16_t Step_Climbing_Block_5                         = 187;
constexpr uint16_t Step_Climbing_Block_6                         = 188;
constexpr uint16_t Step_Climbing_Block_7                         = 189;
constexpr uint16_t Step_Climbing_Block_8                         = 190;
constexpr uint16_t Step_Climbing_Block_9_End                     = 191;
constexpr uint16_t Jump_Up_B_1_Start                             = 192;
constexpr uint16_t Jump_Up_B_2                                   = 193;
constexpr uint16_t Jump_Up_B_3                                   = 194;
constexpr uint16_t Jump_Up_B_4                                   = 195;
constexpr uint16_t Jump_Up_B_5                                   = 196;
constexpr uint16_t Jump_Up_B_6                                   = 197;
constexpr uint16_t Jump_Up_B_7                                   = 198;
constexpr uint16_t Jump_Up_B_8                                   = 199;
constexpr uint16_t Jump_Up_B_9                                   = 200;
constexpr uint16_t Jump_Up_B_10                                  = 201;
constexpr uint16_t Jump_Up_B_11                                  = 202;
constexpr uint16_t Jump_Up_B_12                                  = 203;
constexpr uint16_t Jump_Up_B_13                                  = 204;
constexpr uint16_t Jump_Up_B_14_End                              = 205;
constexpr uint16_t Jump_Up_Drop_B_1_Start                        = 206;  // Drop down to Pos 10
constexpr uint16_t Jump_Up_Drop_B_2                              = 207;
constexpr uint16_t Jump_Up_Drop_B_3                              = 208;
constexpr uint16_t Jump_Up_Drop_B_4                              = 209;
constexpr uint16_t Jump_Up_Drop_B_5_End                          = 210;
constexpr uint16_t Drink_Tonic_1_Start                           = 211; 
constexpr uint16_t Drink_Tonic_2                                 = 212;
constexpr uint16_t Drink_Tonic_3                                 = 213;
constexpr uint16_t Drink_Tonic_4                                 = 214;
constexpr uint16_t Drink_Tonic_5                                 = 215;
constexpr uint16_t Drink_Tonic_6                                 = 216;
constexpr uint16_t Drink_Tonic_7                                 = 217;
constexpr uint16_t Drink_Tonic_8                                 = 218;
constexpr uint16_t Drink_Tonic_9                                 = 219;
constexpr uint16_t Drink_Tonic_10                                = 220;
constexpr uint16_t Drink_Tonic_11                                = 221;
constexpr uint16_t Drink_Tonic_12                                = 222;
constexpr uint16_t Drink_Tonic_13                                = 223;
constexpr uint16_t Drink_Tonic_14                                = 224;
constexpr uint16_t Drink_Tonic_15_End                            = 225;
constexpr uint16_t Jump_Up_Drop_C_1_Start                        = 226;  // Drop down to Pos 2 (two levels)
constexpr uint16_t Jump_Up_Drop_C_2                              = 227;
constexpr uint16_t Jump_Up_Drop_C_3                              = 228;
constexpr uint16_t Jump_Up_Drop_C_4                              = 229;
constexpr uint16_t Jump_Up_Drop_C_5_End                          = 230;
constexpr uint16_t Falling_Injured_1_Start                       = 231;  // Climbing down, falling two levels
constexpr uint16_t Falling_Injured_2_End                         = 232;
constexpr uint16_t Falling_Dead_1_Start                          = 233;  // Climbing down, fall to death
constexpr uint16_t Falling_Dead_2                                = 234;
constexpr uint16_t Falling_Dead_3_End                            = 235;
constexpr uint16_t Run_Repeat_8_End_Turn                         = 236;  // Single entry to allow x correction
constexpr uint16_t Falling_Down_1_Start                          = 237;
constexpr uint16_t Falling_Down_2                                = 238;
constexpr uint16_t Falling_Down_3                                = 239;
constexpr uint16_t Falling_Down_4                                = 240;
constexpr uint16_t Falling_Down_5_End                            = 241;
constexpr uint16_t Falling_StandingJump_1_Start                  = 242;
constexpr uint16_t Falling_StandingJump_2                        = 243;
constexpr uint16_t Falling_StandingJump_3                        = 244;
constexpr uint16_t Falling_StandingJump_4                        = 245;
constexpr uint16_t Falling_StandingJump_5_Check_CanFall          = 246;
constexpr uint16_t Falling_StandingJump_6_End                    = 247;
constexpr uint16_t Falling_SingleStep_1_Start                    = 248;
constexpr uint16_t Falling_SingleStep_2                          = 249;
constexpr uint16_t Falling_SingleStep_3                          = 250;
constexpr uint16_t Falling_SingleStep_4                          = 251;
constexpr uint16_t Falling_SingleStep_5_Check_CanFall            = 252;
constexpr uint16_t Falling_SingleStep_6_End                      = 253;
constexpr uint16_t Pickup_Sword_1_Start                          = 254;
constexpr uint16_t Pickup_Sword_2                                = 255;
constexpr uint16_t Pickup_Sword_3                                = 256;
constexpr uint16_t Pickup_Sword_4                                = 257;
constexpr uint16_t Pickup_Sword_5                                = 258;
constexpr uint16_t Pickup_Sword_6                                = 259;
constexpr uint16_t Pickup_Sword_7                                = 260;
constexpr uint16_t Pickup_Sword_8                                = 261;
constexpr uint16_t Pickup_Sword_9                                = 262;
constexpr uint16_t Pickup_Sword_10                               = 263;
constexpr uint16_t Pickup_Sword_11                               = 264;
constexpr uint16_t Pickup_Sword_12                               = 265;
constexpr uint16_t Pickup_Sword_13                               = 266;
constexpr uint16_t Pickup_Sword_14                               = 267;
constexpr uint16_t Pickup_Sword_15                               = 268;
constexpr uint16_t Pickup_Sword_16_End                           = 269;
constexpr uint16_t Falling_StepWalkRun_P2_6_10_1_Start           = 270;
constexpr uint16_t Falling_StepWalkRun_P2_6_10_2                 = 271;
constexpr uint16_t Falling_StepWalkRun_P2_6_10_3                 = 272;
constexpr uint16_t Falling_StepWalkRun_P2_6_10_4                 = 273;
constexpr uint16_t Falling_StepWalkRun_P2_6_10_5_Check_CanFall   = 274;
constexpr uint16_t Falling_StepWalkRun_P2_6_10_6_End             = 275;
constexpr uint16_t Falling_StepWalkRun_P0_4_8_1_Start            = 276;
constexpr uint16_t Falling_StepWalkRun_P0_4_8_2                  = 277;
constexpr uint16_t Falling_StepWalkRun_P0_4_8_3                  = 278;
constexpr uint16_t Falling_StepWalkRun_P0_4_8_4                  = 279;
constexpr uint16_t Falling_StepWalkRun_P0_4_8_5_Check_CanFall    = 280;
constexpr uint16_t Falling_StepWalkRun_P0_4_8_6_End              = 281;
constexpr uint16_t Falling_StepWalkRun_P1_5_9_1_Start            = 282;
constexpr uint16_t Falling_StepWalkRun_P1_5_9_2                  = 283;
constexpr uint16_t Falling_StepWalkRun_P1_5_9_3                  = 284;
constexpr uint16_t Falling_StepWalkRun_P1_5_9_4                  = 285;
constexpr uint16_t Falling_StepWalkRun_P1_5_9_5_Check_CanFall    = 286;
constexpr uint16_t Falling_StepWalkRun_P1_5_9_6_End              = 287;
constexpr uint16_t Falling_StepWalkRun_P3_7_11_1_Start           = 288;
constexpr uint16_t Falling_StepWalkRun_P3_7_11_2                 = 289;
constexpr uint16_t Falling_StepWalkRun_P3_7_11_3                 = 290;
constexpr uint16_t Falling_StepWalkRun_P3_7_11_4                 = 291;
constexpr uint16_t Falling_StepWalkRun_P3_7_11_5_Check_CanFall   = 292;
constexpr uint16_t Falling_StepWalkRun_P3_7_11_6_End             = 293;
constexpr uint16_t Leave_Gate_1_Start                            = 294;
constexpr uint16_t Leave_Gate_2                                  = 295;
constexpr uint16_t Leave_Gate_3                                  = 296;
constexpr uint16_t Leave_Gate_4                                  = 297;
constexpr uint16_t Leave_Gate_5                                  = 298;
constexpr uint16_t Leave_Gate_6                                  = 299;
constexpr uint16_t Leave_Gate_7                                  = 300;
constexpr uint16_t Leave_Gate_8                                  = 301;
constexpr uint16_t Leave_Gate_9                                  = 302;
constexpr uint16_t Leave_Gate_10                                 = 303;
constexpr uint16_t Leave_Gate_11                                 = 304;
constexpr uint16_t Leave_Gate_12                                 = 305;
constexpr uint16_t Leave_Gate_13                                 = 306;
constexpr uint16_t Leave_Gate_14_End                             = 307;

constexpr uint16_t  Upright_End_Climb        = 1253;
constexpr uint16_t  Upright_Turn             = 1255;
};


namespace Constants {

    constexpr uint8_t FrameRate = 45;
    constexpr uint8_t NumberOfItems = 30;
    constexpr uint8_t Animation_NumberOfFrames = 2;
    constexpr uint8_t NoItemFound = 255;

    constexpr uint8_t TileHeight = 31;
    constexpr uint8_t TileWidth = 12;
    constexpr uint8_t ScreenTopOffset = 1;
    constexpr uint8_t ScreenWidthInTiles = 10;
    constexpr int8_t CoordNone = 127;
    constexpr uint8_t TitleScreenScroll_Max = 87;

    const uint8_t StanceToImageXRef[] PROGMEM  = {
        /* 000 - 000 None */                            0,                        
        /* 001 - 006 Run_Start */                       1, 2, 3, 4, 5, 6, 
        /* 007 - 014 Run_Repeat */                      7, 8, 9, 10, 11, 12, 13, 14,
        /* 015 - 015 Upright */                         15,
        /* 016 - 026 Running_Jump */                    16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26,
        /* 027 - 031 Standing_Turn */                   27, 28, 29, 30, 31,
        /* 032 - 044 Running_Turn */                    32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44,
        /* 045 - 062 Standing_Jump */                   45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62,
        /* 063 - 068 Step_Fwd_One */                    63, 64, 65, 66, 67, 68,
        /* 069 - 074 Step_Fwd_Two */                    69, 70, 71, 72, 73, 74,
        /* 075 - 082 Single_Step */                     63, 64, 65, 66, 71, 72, 73, 74,
        /* 083 - 087 Stopping */                        5, 4, 3, 2, 1, 
        /* 088 - 102 Climbing */                        75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89,                     
        /* 103 - 108 Small_Step */                      63, 64, 65, 72, 73, 74,                                                         
        /* 109 - 122 Jump_Up_A */                       90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103,                     
        /* 123 - 127 Jump_Drop_A */                     104, 105, 106, 107, 108,   // Drop to position 2                                
        /* 128 - 142 Step_Climbing */                   75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89,                     
        /* 143 - 154 Crouch_Stand */                    109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120,                     
        /* 155 - 160 Falling_SmallStep */               121, 122, 123, 124, 125, 126,                  
        /* 161 - 166 Falling_RunningJump */             121, 122, 123, 124, 125, 126,                     
        /* 167 - 172 Falling_C */                       121, 122, 123, 124, 125, 126,                             
        /* 173 - 175 Crouching */                       126, 109, 110,                                                                  
        /* 176 - 182 Crouch_HOP */                      110, 111, 112, 113, 112, 111, 110,                                              
        /* 183 - 191 Step_Climbing_Block */             75, 76, 77, 78, 79, 78, 77, 76, 75,                                             
        /* 192 - 205 Jump_Up_B */                       90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103,                     
        /* 206 - 210 Jump_Drop_B */                     104, 105, 106, 107, 108,   // Drop to position 10                               
        /* 211 - 225 Drink_Tonic */                     127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141,      
        /* 226 - 230 Jump_Drop_C */                     104, 105, 106, 107, 108,   // Climb down, drop straight down 31 px              
        /* 231 - 232 Falling_Injured */                 125, 126,   
        /* 233 - 235 Falling_Dead */                    125, 126, 142,  
        /* 236 - 236 Run_Repeat_8_End_Turn */           14,   // single entry to allow x correction
        /* 237 - 241 Falling_Down */                    125, 125, 125, 125, 125,  // falling straight down.
        /* 242 - 247 Falling_StandingJump */            121, 122, 123, 124, 125, 126,                                   
        /* 248 - 253 Falling_SingleStep */              121, 122, 123, 124, 125, 126,                               
        /* 254 - 269 Pickup_Sword */                    143, 144, 145, 145, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 
        /* 270 - 275 Falling_StepWalkRun_P2_6_10 */     121, 122, 123, 124, 125, 126,                               
        /* 276 - 281 Falling_StepWalkRun_P0_4_8 */      121, 122, 123, 124, 125, 126,                               
        /* 282 - 287 Falling_StepWalkRun_P1_5_9 */      121, 122, 123, 124, 125, 126,                               
        /* 288 - 293 Falling_StepWalkRun_P3_7_11 */     121, 122, 123, 124, 125, 126,                               
        /* 294 - 307 Exit Sequence */                   157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 168, 0,
        255,                   
    };

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

             -1,  -1,   0,   0,   0,   0,   0,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   0,   0,    //  091 - 100
              0,   0,   0,   0,   1,   0,   1,   0,   1,   0,   1,   0,   0,   0,   0,   0,   0,   0,   0,   0,    //  101 - 110
              0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,    //  111 - 120

              0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  -4,   0,  -4,   0,  -2,    //  121 - 130
              0,  -3,   0,  -2,   0,  -2,   0,  -3,   0,  -3,   0,  -1,   1,  -3,   1,  -2,   0,  -1,   1,  -1,    //  131 - 140
              1,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,    //  141 - 150

              0,   0,   0,   0,   0,   0,   0,   0,   3,   6,   2,   5,   2,   5,   1,   5,   0,   5,   0,   5,    //  151 - 160
              6,   6,   5,   5,   4,   5,   0,   5,   0,   5,   1,   5,   5,   6,   4,   3,   4,   5,   1,   5,    //  161 - 170
              0,   5,   0,   5,   0,   0,   0,   0,   0,   0,   0,   0,   1,   0,   1,   0,   1,   0,   1,   0,    //  171 - 180

              0,   0,   0,   0,   0,  -4,   0,  -4,   0,  -2,   0,  -3,   0,   0,   0,   3,   0,   2,   0,   4,    //  181 - 190
              0,   4,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,    //  191 - 200
             -1,   0,  -1,   0,  -1,   0,  -1,   0,   0,   0,   1,   0,   1,   0,   1,   0,   1,   0,   0,   0,    //  201 - 210

              0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,    //  211 - 220
              0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   6,   0,   6,   0,   6,   0,   6,   0,   7,    //  221 - 230
              0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   4,   0,   0,   6,   0,   6,   0,   6,   0,   6,    //  231 - 240

              0,   7,   4,   6,   2,   5,   2,   5,   1,   5,   0,   5,   0,   5,   2,   6,   2,   5,   2,   5,    //  241 - 250
              1,   5,   0,   5,   0,   5,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,    //  251 - 260
              0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   2,   6,    //  261 - 270

              2,   5,   2,   5,   1,   5,   1,   5,   0,   5,   2,   6,   2,   5,   1,   5,   1,   5,   0,   5,    //  271 - 280
              0,   5,   2,   6,   2,   5,   2,   5,   1,   5,   0,   5,   0,   5,   2,   6,   2,   5,   2,   5,    //  281 - 290
              2,   5,   1,   5,   0,   5,   0,   0,   1,   0,   2,  -1,   2,  -1,   2,  -1,   1,  -1,   1,  -1,    //  291 - 300

              1,  -1,   1,  -1,   1,  -1,   1,  -2,   0,  -3,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,    //  301 - 310
              0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,    //  311 - 320
              0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,    //  321 - 330

    };
//    2,   6,   2,   5,   2,   5,  1,   5,   0,   5,   0,   5, 
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
/* 075 */  127, 127, 127,
/* 076 */  127, 127, 127,
/* 077 */  127, 127, 127,
/* 078 */  127, 127, 127,
/* 079 */  127, 127, 127,
/* 080 */  127, 127, 127,
/* 081 */  127, 127, 127,
/* 082 */  127, 127, 127,
/* 083 */  127, 127, 127,
/* 084 */  127, 127, 127,
/* 085 */  127, 127, 127,
/* 086 */  127, 127, 127,
/* 087 */  127, 127, 127,
/* 088 */  127, 127, 127,
/* 089 */  127, 127, 127,
/* 090 */  3, 2, -2,
/* 091 */  3, 3, -2,
/* 092 */  4, 3, -2,
/* 093 */  5, 3, -2,
/* 094 */  6, 4, 0,
/* 095 */  7, 4, 0,
/* 096 */  7, 4, 0,
/* 097 */  7, 3, -2,
/* 098 */  5, 1, -4,
/* 099 */  5, -1, -5,
/* 100 */  5, -1, -3,
/* 101 */  127, 127, 127,
/* 102 */  127, 127, 127,
/* 103 */  127, 127, 127,
/* 104 */  127, 127, 127,
/* 105 */  127, 127, 127,
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

