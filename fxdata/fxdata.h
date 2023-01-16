#pragma once

/**** FX data header generated by fxdata-build.py tool version 1.12 ****/

using uint24_t = __uint24;

// Initialize FX hardware using  FX::begin(FX_DATA_PAGE); in the setup() function.

constexpr uint16_t FX_DATA_PAGE  = 0xfa51;
constexpr uint24_t FX_DATA_BYTES = 372342;

namespace Levels
{
  constexpr uint24_t Level1_FG = 0x000000;
  constexpr uint24_t Level1_BG = 0x00032A;
  constexpr uint24_t level1_Data = 0x000654;
  constexpr uint24_t Level1_Items = 0x00066F;
  constexpr uint24_t Level2_FG = 0x000739;
  constexpr uint24_t Level2_BG = 0x000D51;
  constexpr uint24_t level2_Data = 0x001369;
  constexpr uint24_t Level2_Items = 0x00139C;
  constexpr uint24_t Level3_FG = 0x001423;
  constexpr uint24_t Level3_BG = 0x001969;
  constexpr uint24_t level3_Data = 0x001EAF;
  constexpr uint24_t Level3_Items = 0x001EC2;
  constexpr uint24_t Level4_FG = 0x001F18;
  constexpr uint24_t Level4_BG = 0x002350;
  constexpr uint24_t level4_Data = 0x002788;
  constexpr uint24_t Level4_Items = 0x0027BB;
  constexpr uint24_t Level5_FG = 0x002889;
  constexpr uint24_t Level5_BG = 0x002DCF;
  constexpr uint24_t level5_Data = 0x003315;
  constexpr uint24_t Level5_Items = 0x003340;
  constexpr uint24_t Level6_FG = 0x0033ED;
  constexpr uint24_t Level6_BG = 0x003663;
  constexpr uint24_t level6_Data = 0x0038D9;
  constexpr uint24_t Level6_Items = 0x0038F4;
  constexpr uint24_t Level7_FG = 0x003933;
  constexpr uint24_t Level7_BG = 0x003D6B;
  constexpr uint24_t level7_Data = 0x0041A3;
  constexpr uint24_t Level7_Items = 0x0041C6;
  constexpr uint24_t Level8_FG = 0x0042AE;
  constexpr uint24_t Level8_BG = 0x0047D6;
  constexpr uint24_t level8_Data = 0x004CFE;
  constexpr uint24_t Level8_Items = 0x004D29;
  constexpr uint24_t Level9_FG = 0x004DDC;
  constexpr uint24_t Level9_BG = 0x00519C;
  constexpr uint24_t level9_Data = 0x00555C;
  constexpr uint24_t Level9_Items = 0x005587;
  constexpr uint24_t Level10_FG = 0x00564F;
  constexpr uint24_t Level10_BG = 0x00591F;
  constexpr uint24_t level10_Data = 0x005BEF;
  constexpr uint24_t Level10_Items = 0x005C1A;
  constexpr uint24_t Level11_FG = 0x005CE7;
  constexpr uint24_t Level11_BG = 0x00611F;
  constexpr uint24_t level11_Data = 0x006557;
  constexpr uint24_t Level11_Items = 0x00657A;
  constexpr uint24_t Level12_FG = 0x006643;
  constexpr uint24_t Level12_BG = 0x006CD3;
  constexpr uint24_t level12_Data = 0x007363;
  constexpr uint24_t Level12_Items = 0x007376;
  constexpr uint24_t level_FG = 0x0073C3;
  constexpr uint24_t Level_BG = 0x0073EA;
  constexpr uint24_t level_Data = 0x007411;
  constexpr uint24_t Level_Items = 0x007438;
}

namespace CutScene
{
  constexpr uint24_t Scene9 = 0x00745F;
}

namespace Sounds
{
  constexpr uint24_t Dead = 0x00765F;
  constexpr uint24_t Grab1 = 0x00767D;
  constexpr uint24_t Grab2 = 0x0076A7;
  constexpr uint24_t Grab3 = 0x0076D1;
  constexpr uint24_t Grab4 = 0x00770B;
  constexpr uint24_t Seque = 0x007761;
  constexpr uint24_t Tada = 0x0077DB;
  constexpr uint24_t Theme = 0x0077F9;
  constexpr uint24_t Triumph = 0x0079C7;
}

namespace Images
{
  constexpr uint24_t PPOT = 0x0079E5;
  constexpr uint16_t PPOT_WIDTH  = 65;
  constexpr uint16_t PPOTHEIGHT  = 31;
  constexpr uint8_t  PPOT_FRAMES = 4;

  constexpr uint24_t Title_PoP = 0x007DF9;
  constexpr uint16_t Title_PoP_width  = 128;
  constexpr uint16_t Title_PoP_height = 33;

  constexpr uint24_t Title_Main = 0x0082FD;
  constexpr uint16_t Title_Main_width  = 128;
  constexpr uint16_t Title_Main_height = 88;

  constexpr uint24_t Title_Cursor = 0x008881;
  constexpr uint16_t Title_Cursor_width  = 5;
  constexpr uint16_t Title_Cursor_height = 5;

  constexpr uint24_t Title_Credits = 0x00888A;
  constexpr uint16_t Title_Credits_width  = 73;
  constexpr uint16_t Title_Credits_height = 136;

  constexpr uint24_t TimeRemaining = 0x008D67;
  constexpr uint16_t TimeRemainingWidth  = 81;
  constexpr uint16_t TimeRemainingHeight = 15;

  constexpr uint24_t LevelNumber = 0x008EAF;
  constexpr uint16_t LevelNumberWidth  = 81;
  constexpr uint16_t LevelNumberHeight = 15;

  constexpr uint24_t GameOver = 0x008FF7;
  constexpr uint16_t GameOverWidth  = 49;
  constexpr uint16_t GameOverHeight = 15;

  constexpr uint24_t PressA = 0x0090BF;
  constexpr uint16_t PressAWidth  = 79;
  constexpr uint16_t PressAHeight = 15;

  constexpr uint24_t IntroGame_1A = 0x0091FF;
  constexpr uint16_t IntroGame_1A_width  = 118;
  constexpr uint16_t IntroGame_1A_height = 96;

  constexpr uint24_t IntroGame_1B = 0x00978B;
  constexpr uint16_t IntroGame_1B_width  = 123;
  constexpr uint16_t IntroGame_1B_height = 96;

  constexpr uint24_t IntroGame_9 = 0x009D53;
  constexpr uint16_t IntroGame_9_width  = 123;
  constexpr uint16_t IntroGame_9_height = 160;

  constexpr uint24_t Chambers_BG = 0x00A6F3;
  constexpr uint16_t Chambers_BG_width  = 128;
  constexpr uint16_t Chambers_BG_height = 64;

  constexpr uint24_t Chambers_FG = 0x00AAF7;
  constexpr uint16_t Chambers_FG_width  = 128;
  constexpr uint16_t Chambers_FG_height = 64;

  constexpr uint24_t Credits_BG = 0x00B2FB;
  constexpr uint16_t Credits_BG_width  = 128;
  constexpr uint16_t Credits_BG_height = 9;

  constexpr uint24_t Mouse = 0x00B3FF;
  constexpr uint16_t MouseWidth  = 16;
  constexpr uint16_t MouseHeight = 16;
  constexpr uint8_t  MouseFrames = 3;

  constexpr uint24_t Numbers_Upright = 0x00B4C3;
  constexpr uint16_t Numbers_Upright_width  = 7;
  constexpr uint16_t Numbers_Upright_height = 5;
  constexpr uint8_t  Numbers_Upright_frames = 60;

  constexpr uint24_t Menu = 0x00B66B;
  constexpr uint16_t MenuWidth  = 42;
  constexpr uint16_t MenuHeight = 64;
  constexpr uint8_t  MenuFrames = 2;

  constexpr uint24_t Sword_Cursor = 0x00B90F;
  constexpr uint16_t Sword_Cursor_width  = 8;
  constexpr uint16_t Sword_Cursor_height = 10;

  constexpr uint24_t HUD_Backgrounds = 0x00B923;
  constexpr uint16_t HUD_Backgrounds_width  = 8;
  constexpr uint16_t HUD_Backgrounds_height = 64;
  constexpr uint8_t  HUD_Backgrounds_frames = 2;

  constexpr uint24_t Numbers = 0x00B9A7;
  constexpr uint16_t NumbersWidth  = 11;
  constexpr uint16_t NumbersHeight = 7;
  constexpr uint8_t  NumbersFrames = 60;

  constexpr uint24_t Numbers_Small = 0x00BC3F;
  constexpr uint16_t Numbers_Small_width  = 5;
  constexpr uint16_t Numbers_Small_height = 7;
  constexpr uint8_t  Numbers_Small_frames = 60;

  constexpr uint24_t Healths = 0x00BD6F;
  constexpr uint16_t HealthsWidth  = 5;
  constexpr uint16_t HealthsHeight = 3;
  constexpr uint8_t  HealthsFrames = 2;

  constexpr uint24_t Sword_HUD = 0x00BD7D;
  constexpr uint16_t Sword_HUD_width  = 5;
  constexpr uint16_t Sword_HUD_height = 5;

  constexpr uint24_t Potion_Float_HUD = 0x00BD86;
  constexpr uint16_t Potion_Float_HUD_width  = 5;
  constexpr uint16_t Potion_Float_HUD_height = 5;

  constexpr uint24_t Sword = 0x00BD8F;
  constexpr uint16_t SwordWidth  = 14;
  constexpr uint16_t SwordHeight = 5;

  constexpr uint24_t Skeleton = 0x00BDAF;
  constexpr uint16_t SkeletonWidth  = 15;
  constexpr uint16_t SkeletonHeight = 12;

  constexpr uint24_t Gates = 0x00BDEF;
  constexpr uint16_t GatesWidth  = 9;
  constexpr uint16_t GatesHeight = 28;
  constexpr uint8_t  GatesFrames = 10;

  constexpr uint24_t Blades = 0x00C0C3;
  constexpr uint16_t BladesWidth  = 9;
  constexpr uint16_t BladesHeight = 28;
  constexpr uint8_t  BladesFrames = 6;

  constexpr uint24_t ExitDoors = 0x00C277;
  constexpr uint16_t ExitDoorsWidth  = 25;
  constexpr uint16_t ExitDoorsHeight = 33;
  constexpr uint8_t  ExitDoorsFrames = 13;

  constexpr uint24_t Potions_Small = 0x00C8D4;
  constexpr uint16_t Potions_Small_width  = 6;
  constexpr uint16_t Potions_Small_height = 15;
  constexpr uint8_t  Potions_Small_frames = 2;

  constexpr uint24_t Potions_Large = 0x00C908;
  constexpr uint16_t Potions_Large_width  = 6;
  constexpr uint16_t Potions_Large_height = 15;
  constexpr uint8_t  Potions_Large_frames = 2;

  constexpr uint24_t Potions_Poison = 0x00C93C;
  constexpr uint16_t Potions_Poison_width  = 6;
  constexpr uint16_t Potions_Poison_height = 15;
  constexpr uint8_t  Potions_Poison_frames = 6;

  constexpr uint24_t Potions_Float = 0x00C9D0;
  constexpr uint16_t Potions_Float_width  = 6;
  constexpr uint16_t Potions_Float_height = 15;
  constexpr uint8_t  Potions_Float_frames = 7;

  constexpr uint24_t CollapsedFloor = 0x00CA7C;
  constexpr uint16_t CollapsedFloorWidth  = 21;
  constexpr uint16_t CollapsedFloorHeight = 13;

  constexpr uint24_t CollapsingFloors = 0x00CAD4;
  constexpr uint16_t CollapsingFloorsWidth  = 21;
  constexpr uint16_t CollapsingFloorsHeight = 31;
  constexpr uint8_t  CollapsingFloorsFrames = 4;

  constexpr uint24_t FloorButtons_0and1 = 0x00CD78;
  constexpr uint16_t FloorButtons_0and1_width  = 21;
  constexpr uint16_t FloorButtons_0and1_height = 32;
  constexpr uint8_t  FloorButtons_0and1_frames = 4;

  constexpr uint24_t FloorButtons_2 = 0x00D01C;
  constexpr uint16_t FloorButtons_2_width  = 12;
  constexpr uint16_t FloorButtons_2_height = 31;
  constexpr uint8_t  FloorButtons_2_frames = 2;

  constexpr uint24_t Torches = 0x00D0E0;
  constexpr uint16_t TorchesWidth  = 3;
  constexpr uint16_t TorchesHeight = 11;
  constexpr uint8_t  TorchesFrames = 5;

  constexpr uint24_t Mirrors = 0x00D120;
  constexpr uint16_t MirrorsWidth  = 12;
  constexpr uint16_t MirrorsHeight = 31;
  constexpr uint8_t  MirrorsFrames = 2;

  constexpr uint24_t Spikes_FG_Full = 0x00D184;
  constexpr uint16_t Spikes_FG_Full_width  = 19;
  constexpr uint16_t Spikes_FG_Full_height = 18;
  constexpr uint8_t  Spikes_FG_Full_frames = 5;

  constexpr uint24_t Spikes_BG_Full = 0x00D3C2;
  constexpr uint16_t Spikes_BG_Full_width  = 19;
  constexpr uint16_t Spikes_BG_Full_height = 18;
  constexpr uint8_t  Spikes_BG_Full_frames = 5;

  constexpr uint24_t Spikes_FG_Half = 0x00D600;
  constexpr uint16_t Spikes_FG_Half_width  = 11;
  constexpr uint16_t Spikes_FG_Half_height = 18;
  constexpr uint8_t  Spikes_FG_Half_frames = 5;

  constexpr uint24_t Spikes_BG_Half = 0x00D74E;
  constexpr uint16_t Spikes_BG_Half_width  = 11;
  constexpr uint16_t Spikes_BG_Half_height = 18;
  constexpr uint8_t  Spikes_BG_Half_frames = 5;

  constexpr uint24_t Flashes = 0x00D89C;
  constexpr uint16_t FlashesWidth  = 22;
  constexpr uint16_t FlashesHeight = 20;
  constexpr uint8_t  FlashesFrames = 4;

  constexpr uint24_t Tiles_Dungeon = 0x00DAB0;
  constexpr uint16_t Tiles_Dungeon_width  = 12;
  constexpr uint16_t Tiles_Dungeon_height = 31;
  constexpr uint8_t  Tiles_Dungeon_frames = 80;

  constexpr uint24_t Tile_Dungeon_97 = 0x00F8B4;
  constexpr uint16_t Tile_Dungeon_97_width  = 21;
  constexpr uint16_t Tile_Dungeon_97_height = 31;

  constexpr uint24_t Tile_Dungeon_98 = 0x00F960;
  constexpr uint16_t Tile_Dungeon_98_width  = 12;
  constexpr uint16_t Tile_Dungeon_98_height = 31;

  constexpr uint24_t Tiles_Dungeon_Torch = 0x00F9C4;
  constexpr uint16_t Tiles_Dungeon_Torch_width  = 12;
  constexpr uint16_t Tiles_Dungeon_Torch_height = 31;
  constexpr uint8_t  Tiles_Dungeon_Torch_frames = 60;

  constexpr uint24_t Princess = 0x011048;
  constexpr uint16_t PrincessWidth  = 32;
  constexpr uint16_t PrincessHeight = 32;
  constexpr uint8_t  PrincessFrames = 40;

  constexpr uint24_t Princess_Bounce = 0x01384C;
  constexpr uint16_t Princess_Bounce_width  = 48;
  constexpr uint16_t Princess_Bounce_height = 32;
  constexpr uint8_t  Princess_Bounce_frames = 20;

  constexpr uint24_t Hearts = 0x015650;
  constexpr uint16_t HeartsWidth  = 7;
  constexpr uint16_t HeartsHeight = 6;
  constexpr uint8_t  HeartsFrames = 4;

  constexpr uint24_t Zaffar = 0x015670;
  constexpr uint16_t ZaffarWidth  = 32;
  constexpr uint16_t ZaffarHeight = 32;
  constexpr uint8_t  ZaffarFrames = 30;

  constexpr uint24_t HourGlasses = 0x017474;
  constexpr uint16_t HourGlassesWidth  = 19;
  constexpr uint16_t HourGlassesHeight = 23;
  constexpr uint8_t  HourGlassesFrames = 7;

  constexpr uint24_t Prince_Left = 0x017796;
  constexpr uint16_t Prince_Left_width  = 36;
  constexpr uint16_t Prince_Left_height = 36;
  constexpr uint8_t  Prince_Left_frames = 225;

  constexpr uint24_t Prince_Right = 0x02B402;
  constexpr uint16_t Prince_Right_width  = 36;
  constexpr uint16_t Prince_Right_height = 36;
  constexpr uint8_t  Prince_Right_frames = 225;

  constexpr uint24_t Mirror_Right = 0x03F06E;
  constexpr uint16_t Mirror_Right_width  = 36;
  constexpr uint16_t Mirror_Right_height = 36;
  constexpr uint8_t  Mirror_Right_frames = 225;

}

namespace Constants
{
  constexpr uint24_t StanceToImageXRefFX = 0x052CDA;
  constexpr uint24_t Stance_XYOffsetsFX = 0x052EBD;
  constexpr uint24_t VertAdjustments = 0x053283;
  constexpr uint24_t Prince_ImageDetails = 0x053319;
}

constexpr uint24_t splashScreen_Frame = 0x053562;
constexpr uint24_t Title_Intro_Frame = 0x053586;
constexpr uint24_t Title_Intro_Last_Frame = 0x053A06;
constexpr uint24_t Title_Main_Frame = 0x053A18;
constexpr uint24_t Title_Main_Last_Frame = 0x053BA4;
constexpr uint24_t Title_Main_Game_Frame = 0x053BB6;
constexpr uint24_t Title_Main_Credits_Frame = 0x053BD1;
constexpr uint24_t Title_Credits_Frame = 0x053BEC;
constexpr uint24_t Title_IntroGame_1A_Frame = 0x056D63;
constexpr uint24_t Title_CutScene_1_Frame = 0x057339;
constexpr uint24_t Title_IntroGame_1B_Frame = 0x05A846;
constexpr uint24_t Chambers_BG_frame = 0x05AE1C;
constexpr uint24_t Chambers_FG_frame = 0x05AE6D;
