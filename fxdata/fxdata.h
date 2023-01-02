#pragma once

/**** FX data header generated by fxdata-build.py tool version 1.10 ****/

using uint24_t = __uint24;

// Initialize FX hardware using  FX::begin(FX_DATA_PAGE); in the setup() function.

constexpr uint16_t FX_DATA_PAGE  = 0xfc49;
constexpr uint24_t FX_DATA_BYTES = 243455;

namespace Levels
{
  constexpr uint24_t Level1_FG = 0x000000;
  constexpr uint24_t Level1_BG = 0x00032A;
  constexpr uint24_t level1_Data = 0x000654;
  constexpr uint24_t Level1_Items = 0x00066A;
  constexpr uint24_t Level2_FG = 0x00072A;
  constexpr uint24_t Level2_BG = 0x000D42;
  constexpr uint24_t level2_Data = 0x00135A;
  constexpr uint24_t Level2_Items = 0x001382;
  constexpr uint24_t Level3_FG = 0x001400;
  constexpr uint24_t Level3_BG = 0x001946;
  constexpr uint24_t level3_Data = 0x001E8C;
  constexpr uint24_t Level3_Items = 0x001E96;
  constexpr uint24_t Level4_FG = 0x001EE9;
  constexpr uint24_t Level4_BG = 0x002321;
  constexpr uint24_t level4_Data = 0x002759;
  constexpr uint24_t Level4_Items = 0x002763;
  constexpr uint24_t Level5_FG = 0x0027F2;
  constexpr uint24_t Level5_BG = 0x002D38;
  constexpr uint24_t level5_Data = 0x00327E;
  constexpr uint24_t Level5_Items = 0x003288;
  constexpr uint24_t level_FG = 0x003291;
  constexpr uint24_t Level_BG = 0x0032A3;
  constexpr uint24_t level_Data = 0x0032B5;
  constexpr uint24_t Level_Items = 0x0032C7;
}

namespace CutScene
{
  constexpr uint24_t Scene1 = 0x0032D9;
  constexpr uint24_t Scene9 = 0x0036BD;
}

namespace Sounds
{
  constexpr uint24_t Dead = 0x0038BD;
  constexpr uint24_t Grab1 = 0x0038DB;
  constexpr uint24_t Grab2 = 0x003905;
  constexpr uint24_t Grab3 = 0x00392F;
  constexpr uint24_t Grab4 = 0x003969;
  constexpr uint24_t Seque = 0x0039BF;
  constexpr uint24_t Tada = 0x003A39;
  constexpr uint24_t Theme = 0x003A57;
  constexpr uint24_t Triumph = 0x003C25;
}

namespace Images
{
  constexpr uint24_t PPOT = 0x003C43;
  constexpr uint16_t PPOT_WIDTH  = 65;
  constexpr uint16_t PPOTHEIGHT  = 31;
  constexpr uint8_t  PPOT_FRAMES = 4;

  constexpr uint24_t Title_PoP = 0x004057;
  constexpr uint16_t Title_PoP_width  = 128;
  constexpr uint16_t Title_PoP_height = 33;

  constexpr uint24_t Title_Main = 0x00455B;
  constexpr uint16_t Title_Main_width  = 128;
  constexpr uint16_t Title_Main_height = 88;

  constexpr uint24_t Title_Cursor = 0x004ADF;
  constexpr uint16_t Title_Cursor_width  = 5;
  constexpr uint16_t Title_Cursor_height = 5;

  constexpr uint24_t Title_Credits = 0x004AE8;
  constexpr uint16_t Title_Credits_width  = 73;
  constexpr uint16_t Title_Credits_height = 240;

  constexpr uint24_t TimeRemaining = 0x00537A;
  constexpr uint16_t TimeRemainingWidth  = 81;
  constexpr uint16_t TimeRemainingHeight = 15;

  constexpr uint24_t LevelNumber = 0x0054C2;
  constexpr uint16_t LevelNumberWidth  = 81;
  constexpr uint16_t LevelNumberHeight = 15;

  constexpr uint24_t GameOver = 0x00560A;
  constexpr uint16_t GameOverWidth  = 49;
  constexpr uint16_t GameOverHeight = 15;

  constexpr uint24_t PressA = 0x0056D2;
  constexpr uint16_t PressAWidth  = 79;
  constexpr uint16_t PressAHeight = 15;

  constexpr uint24_t IntroGame_1A = 0x005812;
  constexpr uint16_t IntroGame_1A_width  = 118;
  constexpr uint16_t IntroGame_1A_height = 96;

  constexpr uint24_t IntroGame_1B = 0x005D9E;
  constexpr uint16_t IntroGame_1B_width  = 123;
  constexpr uint16_t IntroGame_1B_height = 96;

  constexpr uint24_t IntroGame_9 = 0x006366;
  constexpr uint16_t IntroGame_9_width  = 123;
  constexpr uint16_t IntroGame_9_height = 160;

  constexpr uint24_t Chambers_BG = 0x006D06;
  constexpr uint16_t Chambers_BG_width  = 128;
  constexpr uint16_t Chambers_BG_height = 64;

  constexpr uint24_t Chambers_FG = 0x00710A;
  constexpr uint16_t Chambers_FG_width  = 128;
  constexpr uint16_t Chambers_FG_height = 64;

  constexpr uint24_t Credits_BG = 0x00790E;
  constexpr uint16_t Credits_BG_width  = 128;
  constexpr uint16_t Credits_BG_height = 9;

  constexpr uint24_t Numbers_Upright = 0x007A12;
  constexpr uint16_t Numbers_Upright_width  = 7;
  constexpr uint16_t Numbers_Upright_height = 5;
  constexpr uint8_t  Numbers_Upright_frames = 60;

  constexpr uint24_t Menu = 0x007BBA;
  constexpr uint16_t MenuWidth  = 42;
  constexpr uint16_t MenuHeight = 64;

  constexpr uint24_t Sword_Cursor = 0x007D0E;
  constexpr uint16_t Sword_Cursor_width  = 8;
  constexpr uint16_t Sword_Cursor_height = 10;

  constexpr uint24_t HUD_Backgrounds = 0x007D22;
  constexpr uint16_t HUD_Backgrounds_width  = 8;
  constexpr uint16_t HUD_Backgrounds_height = 64;
  constexpr uint8_t  HUD_Backgrounds_frames = 2;

  constexpr uint24_t Numbers = 0x007DA6;
  constexpr uint16_t NumbersWidth  = 11;
  constexpr uint16_t NumbersHeight = 7;
  constexpr uint8_t  NumbersFrames = 60;

  constexpr uint24_t Numbers_Small = 0x00803E;
  constexpr uint16_t Numbers_Small_width  = 5;
  constexpr uint16_t Numbers_Small_height = 7;
  constexpr uint8_t  Numbers_Small_frames = 60;

  constexpr uint24_t Healths = 0x00816E;
  constexpr uint16_t HealthsWidth  = 5;
  constexpr uint16_t HealthsHeight = 3;
  constexpr uint8_t  HealthsFrames = 2;

  constexpr uint24_t Sword_HUD = 0x00817C;
  constexpr uint16_t Sword_HUD_width  = 5;
  constexpr uint16_t Sword_HUD_height = 5;

  constexpr uint24_t Sword = 0x008185;
  constexpr uint16_t SwordWidth  = 14;
  constexpr uint16_t SwordHeight = 5;

  constexpr uint24_t Skeleton = 0x0081A5;
  constexpr uint16_t SkeletonWidth  = 15;
  constexpr uint16_t SkeletonHeight = 12;

  constexpr uint24_t Gates = 0x0081E5;
  constexpr uint16_t GatesWidth  = 9;
  constexpr uint16_t GatesHeight = 28;
  constexpr uint8_t  GatesFrames = 10;

  constexpr uint24_t Blades = 0x0084B9;
  constexpr uint16_t BladesWidth  = 9;
  constexpr uint16_t BladesHeight = 28;
  constexpr uint8_t  BladesFrames = 6;

  constexpr uint24_t ExitDoors = 0x00866D;
  constexpr uint16_t ExitDoorsWidth  = 25;
  constexpr uint16_t ExitDoorsHeight = 33;
  constexpr uint8_t  ExitDoorsFrames = 13;

  constexpr uint24_t Potions_Small = 0x008CCA;
  constexpr uint16_t Potions_Small_width  = 6;
  constexpr uint16_t Potions_Small_height = 15;
  constexpr uint8_t  Potions_Small_frames = 2;

  constexpr uint24_t Potions_Large = 0x008CFE;
  constexpr uint16_t Potions_Large_width  = 6;
  constexpr uint16_t Potions_Large_height = 15;
  constexpr uint8_t  Potions_Large_frames = 2;

  constexpr uint24_t Potions_Poison = 0x008D32;
  constexpr uint16_t Potions_Poison_width  = 6;
  constexpr uint16_t Potions_Poison_height = 15;
  constexpr uint8_t  Potions_Poison_frames = 6;

  constexpr uint24_t Potion_Poison_Skull = 0x008DC6;
  constexpr uint16_t Potion_Poison_Skull_width  = 25;
  constexpr uint16_t Potion_Poison_Skull_height = 26;

  constexpr uint24_t CollapsedFloor = 0x008E92;
  constexpr uint16_t CollapsedFloorWidth  = 21;
  constexpr uint16_t CollapsedFloorHeight = 13;

  constexpr uint24_t CollapsingFloors = 0x008EEA;
  constexpr uint16_t CollapsingFloorsWidth  = 21;
  constexpr uint16_t CollapsingFloorsHeight = 31;
  constexpr uint8_t  CollapsingFloorsFrames = 4;

  constexpr uint24_t FloorButtons_0and1 = 0x00918E;
  constexpr uint16_t FloorButtons_0and1_width  = 21;
  constexpr uint16_t FloorButtons_0and1_height = 32;
  constexpr uint8_t  FloorButtons_0and1_frames = 4;

  constexpr uint24_t FloorButtons_2 = 0x009432;
  constexpr uint16_t FloorButtons_2_width  = 12;
  constexpr uint16_t FloorButtons_2_height = 31;
  constexpr uint8_t  FloorButtons_2_frames = 2;

  constexpr uint24_t Torches = 0x0094F6;
  constexpr uint16_t TorchesWidth  = 3;
  constexpr uint16_t TorchesHeight = 11;
  constexpr uint8_t  TorchesFrames = 5;

  constexpr uint24_t Spikes_FG_Full = 0x009536;
  constexpr uint16_t Spikes_FG_Full_width  = 19;
  constexpr uint16_t Spikes_FG_Full_height = 18;
  constexpr uint8_t  Spikes_FG_Full_frames = 5;

  constexpr uint24_t Spikes_BG_Full = 0x009774;
  constexpr uint16_t Spikes_BG_Full_width  = 19;
  constexpr uint16_t Spikes_BG_Full_height = 18;
  constexpr uint8_t  Spikes_BG_Full_frames = 5;

  constexpr uint24_t Spikes_FG_Half = 0x0099B2;
  constexpr uint16_t Spikes_FG_Half_width  = 11;
  constexpr uint16_t Spikes_FG_Half_height = 18;
  constexpr uint8_t  Spikes_FG_Half_frames = 5;

  constexpr uint24_t Spikes_BG_Half = 0x009B00;
  constexpr uint16_t Spikes_BG_Half_width  = 11;
  constexpr uint16_t Spikes_BG_Half_height = 18;
  constexpr uint8_t  Spikes_BG_Half_frames = 5;

  constexpr uint24_t Flashes = 0x009C4E;
  constexpr uint16_t FlashesWidth  = 22;
  constexpr uint16_t FlashesHeight = 20;
  constexpr uint8_t  FlashesFrames = 4;

  constexpr uint24_t Tiles_Dungeon = 0x009E62;
  constexpr uint16_t Tiles_Dungeon_width  = 12;
  constexpr uint16_t Tiles_Dungeon_height = 31;
  constexpr uint8_t  Tiles_Dungeon_frames = 80;

  constexpr uint24_t Tile_Dungeon_97 = 0x00BC66;
  constexpr uint16_t Tile_Dungeon_97_width  = 21;
  constexpr uint16_t Tile_Dungeon_97_height = 31;

  constexpr uint24_t Tile_Dungeon_98 = 0x00BD12;
  constexpr uint16_t Tile_Dungeon_98_width  = 12;
  constexpr uint16_t Tile_Dungeon_98_height = 31;

  constexpr uint24_t Tiles_Dungeon_Torch = 0x00BD76;
  constexpr uint16_t Tiles_Dungeon_Torch_width  = 12;
  constexpr uint16_t Tiles_Dungeon_Torch_height = 31;
  constexpr uint8_t  Tiles_Dungeon_Torch_frames = 60;

  constexpr uint24_t Princess = 0x00D3FA;
  constexpr uint16_t PrincessWidth  = 32;
  constexpr uint16_t PrincessHeight = 32;
  constexpr uint8_t  PrincessFrames = 40;

  constexpr uint24_t Princess_Bounce = 0x00FBFE;
  constexpr uint16_t Princess_Bounce_width  = 48;
  constexpr uint16_t Princess_Bounce_height = 32;
  constexpr uint8_t  Princess_Bounce_frames = 20;

  constexpr uint24_t Hearts = 0x011A02;
  constexpr uint16_t HeartsWidth  = 7;
  constexpr uint16_t HeartsHeight = 6;
  constexpr uint8_t  HeartsFrames = 4;

  constexpr uint24_t Zaffar = 0x011A22;
  constexpr uint16_t ZaffarWidth  = 32;
  constexpr uint16_t ZaffarHeight = 32;
  constexpr uint8_t  ZaffarFrames = 30;

  constexpr uint24_t HourGlasses = 0x013826;
  constexpr uint16_t HourGlassesWidth  = 19;
  constexpr uint16_t HourGlassesHeight = 23;
  constexpr uint8_t  HourGlassesFrames = 7;

  constexpr uint24_t Prince_Left = 0x013B48;
  constexpr uint16_t Prince_Left_width  = 36;
  constexpr uint16_t Prince_Left_height = 36;
  constexpr uint8_t  Prince_Left_frames = 225;

  constexpr uint24_t Prince_Right = 0x0277B4;
  constexpr uint16_t Prince_Right_width  = 36;
  constexpr uint16_t Prince_Right_height = 36;
  constexpr uint8_t  Prince_Right_frames = 225;

}

namespace Constants
{
  constexpr uint24_t VertAdjustments = 0x03B420;
  constexpr uint24_t Prince_ImageDetails = 0x03B4B6;
}

