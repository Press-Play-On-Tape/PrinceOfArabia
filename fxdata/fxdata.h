#pragma once

/**** FX data header generated by fxdata-build.py tool version 1.12 ****/

using uint24_t = __uint24;

// Initialize FX hardware using  FX::begin(FX_DATA_PAGE); in the setup() function.

constexpr uint16_t FX_DATA_PAGE  = 0xfacb;
constexpr uint24_t FX_DATA_BYTES = 341057;

namespace Levels
{
  constexpr uint24_t Level1_FG = 0x000000;
  constexpr uint24_t Level1_BG = 0x00032A;
  constexpr uint24_t level1_Data = 0x000654;
  constexpr uint24_t Level1_Items = 0x00066E;
  constexpr uint24_t Level2_FG = 0x00072E;
  constexpr uint24_t Level2_BG = 0x000D46;
  constexpr uint24_t level2_Data = 0x00135E;
  constexpr uint24_t Level2_Items = 0x001390;
  constexpr uint24_t Level3_FG = 0x001413;
  constexpr uint24_t Level3_BG = 0x001959;
  constexpr uint24_t level3_Data = 0x001E9F;
  constexpr uint24_t Level3_Items = 0x001EB1;
  constexpr uint24_t Level4_FG = 0x001F04;
  constexpr uint24_t Level4_BG = 0x00233C;
  constexpr uint24_t level4_Data = 0x002774;
  constexpr uint24_t Level4_Items = 0x0027A6;
  constexpr uint24_t Level5_FG = 0x002867;
  constexpr uint24_t Level5_BG = 0x002DAD;
  constexpr uint24_t level5_Data = 0x0032F3;
  constexpr uint24_t Level5_Items = 0x00331D;
  constexpr uint24_t Level6_FG = 0x0033BF;
  constexpr uint24_t Level6_BG = 0x003635;
  constexpr uint24_t level6_Data = 0x0038AB;
  constexpr uint24_t Level6_Items = 0x0038C5;
  constexpr uint24_t level_FG = 0x0038FF;
  constexpr uint24_t Level_BG = 0x003914;
  constexpr uint24_t level_Data = 0x003929;
  constexpr uint24_t Level_Items = 0x00393E;
}

namespace CutScene
{
  constexpr uint24_t Scene1 = 0x003953;
  constexpr uint24_t Scene9 = 0x003D37;
}

namespace Sounds
{
  constexpr uint24_t Dead = 0x003F37;
  constexpr uint24_t Grab1 = 0x003F55;
  constexpr uint24_t Grab2 = 0x003F7F;
  constexpr uint24_t Grab3 = 0x003FA9;
  constexpr uint24_t Grab4 = 0x003FE3;
  constexpr uint24_t Seque = 0x004039;
  constexpr uint24_t Tada = 0x0040B3;
  constexpr uint24_t Theme = 0x0040D1;
  constexpr uint24_t Triumph = 0x00429F;
}

namespace Images
{
  constexpr uint24_t PPOT = 0x0042BD;
  constexpr uint16_t PPOT_WIDTH  = 65;
  constexpr uint16_t PPOTHEIGHT  = 31;
  constexpr uint8_t  PPOT_FRAMES = 4;

  constexpr uint24_t Title_PoP = 0x0046D1;
  constexpr uint16_t Title_PoP_width  = 128;
  constexpr uint16_t Title_PoP_height = 33;

  constexpr uint24_t Title_Main = 0x004BD5;
  constexpr uint16_t Title_Main_width  = 128;
  constexpr uint16_t Title_Main_height = 88;

  constexpr uint24_t Title_Cursor = 0x005159;
  constexpr uint16_t Title_Cursor_width  = 5;
  constexpr uint16_t Title_Cursor_height = 5;

  constexpr uint24_t Title_Credits = 0x005162;
  constexpr uint16_t Title_Credits_width  = 73;
  constexpr uint16_t Title_Credits_height = 136;

  constexpr uint24_t TimeRemaining = 0x00563F;
  constexpr uint16_t TimeRemainingWidth  = 81;
  constexpr uint16_t TimeRemainingHeight = 15;

  constexpr uint24_t LevelNumber = 0x005787;
  constexpr uint16_t LevelNumberWidth  = 81;
  constexpr uint16_t LevelNumberHeight = 15;

  constexpr uint24_t GameOver = 0x0058CF;
  constexpr uint16_t GameOverWidth  = 49;
  constexpr uint16_t GameOverHeight = 15;

  constexpr uint24_t PressA = 0x005997;
  constexpr uint16_t PressAWidth  = 79;
  constexpr uint16_t PressAHeight = 15;

  constexpr uint24_t IntroGame_1A = 0x005AD7;
  constexpr uint16_t IntroGame_1A_width  = 118;
  constexpr uint16_t IntroGame_1A_height = 96;

  constexpr uint24_t IntroGame_1B = 0x006063;
  constexpr uint16_t IntroGame_1B_width  = 123;
  constexpr uint16_t IntroGame_1B_height = 96;

  constexpr uint24_t IntroGame_9 = 0x00662B;
  constexpr uint16_t IntroGame_9_width  = 123;
  constexpr uint16_t IntroGame_9_height = 160;

  constexpr uint24_t Chambers_BG = 0x006FCB;
  constexpr uint16_t Chambers_BG_width  = 128;
  constexpr uint16_t Chambers_BG_height = 64;

  constexpr uint24_t Chambers_FG = 0x0073CF;
  constexpr uint16_t Chambers_FG_width  = 128;
  constexpr uint16_t Chambers_FG_height = 64;

  constexpr uint24_t Credits_BG = 0x007BD3;
  constexpr uint16_t Credits_BG_width  = 128;
  constexpr uint16_t Credits_BG_height = 9;

  constexpr uint24_t Numbers_Upright = 0x007CD7;
  constexpr uint16_t Numbers_Upright_width  = 7;
  constexpr uint16_t Numbers_Upright_height = 5;
  constexpr uint8_t  Numbers_Upright_frames = 60;

  constexpr uint24_t Menu = 0x007E7F;
  constexpr uint16_t MenuWidth  = 42;
  constexpr uint16_t MenuHeight = 64;

  constexpr uint24_t Sword_Cursor = 0x007FD3;
  constexpr uint16_t Sword_Cursor_width  = 8;
  constexpr uint16_t Sword_Cursor_height = 10;

  constexpr uint24_t HUD_Backgrounds = 0x007FE7;
  constexpr uint16_t HUD_Backgrounds_width  = 8;
  constexpr uint16_t HUD_Backgrounds_height = 64;
  constexpr uint8_t  HUD_Backgrounds_frames = 2;

  constexpr uint24_t Numbers = 0x00806B;
  constexpr uint16_t NumbersWidth  = 11;
  constexpr uint16_t NumbersHeight = 7;
  constexpr uint8_t  NumbersFrames = 60;

  constexpr uint24_t Numbers_Small = 0x008303;
  constexpr uint16_t Numbers_Small_width  = 5;
  constexpr uint16_t Numbers_Small_height = 7;
  constexpr uint8_t  Numbers_Small_frames = 60;

  constexpr uint24_t Healths = 0x008433;
  constexpr uint16_t HealthsWidth  = 5;
  constexpr uint16_t HealthsHeight = 3;
  constexpr uint8_t  HealthsFrames = 2;

  constexpr uint24_t Sword_HUD = 0x008441;
  constexpr uint16_t Sword_HUD_width  = 5;
  constexpr uint16_t Sword_HUD_height = 5;

  constexpr uint24_t Sword = 0x00844A;
  constexpr uint16_t SwordWidth  = 14;
  constexpr uint16_t SwordHeight = 5;

  constexpr uint24_t Skeleton = 0x00846A;
  constexpr uint16_t SkeletonWidth  = 15;
  constexpr uint16_t SkeletonHeight = 12;

  constexpr uint24_t Gates = 0x0084AA;
  constexpr uint16_t GatesWidth  = 9;
  constexpr uint16_t GatesHeight = 28;
  constexpr uint8_t  GatesFrames = 10;

  constexpr uint24_t Blades = 0x00877E;
  constexpr uint16_t BladesWidth  = 9;
  constexpr uint16_t BladesHeight = 28;
  constexpr uint8_t  BladesFrames = 6;

  constexpr uint24_t ExitDoors = 0x008932;
  constexpr uint16_t ExitDoorsWidth  = 25;
  constexpr uint16_t ExitDoorsHeight = 33;
  constexpr uint8_t  ExitDoorsFrames = 13;

  constexpr uint24_t Potions_Small = 0x008F8F;
  constexpr uint16_t Potions_Small_width  = 6;
  constexpr uint16_t Potions_Small_height = 15;
  constexpr uint8_t  Potions_Small_frames = 2;

  constexpr uint24_t Potions_Large = 0x008FC3;
  constexpr uint16_t Potions_Large_width  = 6;
  constexpr uint16_t Potions_Large_height = 15;
  constexpr uint8_t  Potions_Large_frames = 2;

  constexpr uint24_t Potions_Poison = 0x008FF7;
  constexpr uint16_t Potions_Poison_width  = 6;
  constexpr uint16_t Potions_Poison_height = 15;
  constexpr uint8_t  Potions_Poison_frames = 6;

  constexpr uint24_t Potion_Poison_Skull = 0x00908B;
  constexpr uint16_t Potion_Poison_Skull_width  = 25;
  constexpr uint16_t Potion_Poison_Skull_height = 26;

  constexpr uint24_t CollapsedFloor = 0x009157;
  constexpr uint16_t CollapsedFloorWidth  = 21;
  constexpr uint16_t CollapsedFloorHeight = 13;

  constexpr uint24_t CollapsingFloors = 0x0091AF;
  constexpr uint16_t CollapsingFloorsWidth  = 21;
  constexpr uint16_t CollapsingFloorsHeight = 31;
  constexpr uint8_t  CollapsingFloorsFrames = 4;

  constexpr uint24_t FloorButtons_0and1 = 0x009453;
  constexpr uint16_t FloorButtons_0and1_width  = 21;
  constexpr uint16_t FloorButtons_0and1_height = 32;
  constexpr uint8_t  FloorButtons_0and1_frames = 4;

  constexpr uint24_t FloorButtons_2 = 0x0096F7;
  constexpr uint16_t FloorButtons_2_width  = 12;
  constexpr uint16_t FloorButtons_2_height = 31;
  constexpr uint8_t  FloorButtons_2_frames = 2;

  constexpr uint24_t Torches = 0x0097BB;
  constexpr uint16_t TorchesWidth  = 3;
  constexpr uint16_t TorchesHeight = 11;
  constexpr uint8_t  TorchesFrames = 5;

  constexpr uint24_t Mirrors = 0x0097FB;
  constexpr uint16_t MirrorsWidth  = 12;
  constexpr uint16_t MirrorsHeight = 31;
  constexpr uint8_t  MirrorsFrames = 2;

  constexpr uint24_t Spikes_FG_Full = 0x00985F;
  constexpr uint16_t Spikes_FG_Full_width  = 19;
  constexpr uint16_t Spikes_FG_Full_height = 18;
  constexpr uint8_t  Spikes_FG_Full_frames = 5;

  constexpr uint24_t Spikes_BG_Full = 0x009A9D;
  constexpr uint16_t Spikes_BG_Full_width  = 19;
  constexpr uint16_t Spikes_BG_Full_height = 18;
  constexpr uint8_t  Spikes_BG_Full_frames = 5;

  constexpr uint24_t Spikes_FG_Half = 0x009CDB;
  constexpr uint16_t Spikes_FG_Half_width  = 11;
  constexpr uint16_t Spikes_FG_Half_height = 18;
  constexpr uint8_t  Spikes_FG_Half_frames = 5;

  constexpr uint24_t Spikes_BG_Half = 0x009E29;
  constexpr uint16_t Spikes_BG_Half_width  = 11;
  constexpr uint16_t Spikes_BG_Half_height = 18;
  constexpr uint8_t  Spikes_BG_Half_frames = 5;

  constexpr uint24_t Flashes = 0x009F77;
  constexpr uint16_t FlashesWidth  = 22;
  constexpr uint16_t FlashesHeight = 20;
  constexpr uint8_t  FlashesFrames = 4;

  constexpr uint24_t Tiles_Dungeon = 0x00A18B;
  constexpr uint16_t Tiles_Dungeon_width  = 12;
  constexpr uint16_t Tiles_Dungeon_height = 31;
  constexpr uint8_t  Tiles_Dungeon_frames = 80;

  constexpr uint24_t Tile_Dungeon_97 = 0x00BF8F;
  constexpr uint16_t Tile_Dungeon_97_width  = 21;
  constexpr uint16_t Tile_Dungeon_97_height = 31;

  constexpr uint24_t Tile_Dungeon_98 = 0x00C03B;
  constexpr uint16_t Tile_Dungeon_98_width  = 12;
  constexpr uint16_t Tile_Dungeon_98_height = 31;

  constexpr uint24_t Tiles_Dungeon_Torch = 0x00C09F;
  constexpr uint16_t Tiles_Dungeon_Torch_width  = 12;
  constexpr uint16_t Tiles_Dungeon_Torch_height = 31;
  constexpr uint8_t  Tiles_Dungeon_Torch_frames = 60;

  constexpr uint24_t Princess = 0x00D723;
  constexpr uint16_t PrincessWidth  = 32;
  constexpr uint16_t PrincessHeight = 32;
  constexpr uint8_t  PrincessFrames = 40;

  constexpr uint24_t Princess_Bounce = 0x00FF27;
  constexpr uint16_t Princess_Bounce_width  = 48;
  constexpr uint16_t Princess_Bounce_height = 32;
  constexpr uint8_t  Princess_Bounce_frames = 20;

  constexpr uint24_t Hearts = 0x011D2B;
  constexpr uint16_t HeartsWidth  = 7;
  constexpr uint16_t HeartsHeight = 6;
  constexpr uint8_t  HeartsFrames = 4;

  constexpr uint24_t Zaffar = 0x011D4B;
  constexpr uint16_t ZaffarWidth  = 32;
  constexpr uint16_t ZaffarHeight = 32;
  constexpr uint8_t  ZaffarFrames = 30;

  constexpr uint24_t HourGlasses = 0x013B4F;
  constexpr uint16_t HourGlassesWidth  = 19;
  constexpr uint16_t HourGlassesHeight = 23;
  constexpr uint8_t  HourGlassesFrames = 7;

  constexpr uint24_t Prince_Left = 0x013E71;
  constexpr uint16_t Prince_Left_width  = 36;
  constexpr uint16_t Prince_Left_height = 36;
  constexpr uint8_t  Prince_Left_frames = 225;

  constexpr uint24_t Prince_Right = 0x027ADD;
  constexpr uint16_t Prince_Right_width  = 36;
  constexpr uint16_t Prince_Right_height = 36;
  constexpr uint8_t  Prince_Right_frames = 225;

  constexpr uint24_t Mirror_Right = 0x03B749;
  constexpr uint16_t Mirror_Right_width  = 36;
  constexpr uint16_t Mirror_Right_height = 36;
  constexpr uint8_t  Mirror_Right_frames = 225;

}

namespace Constants
{
  constexpr uint24_t StanceToImageXRefFX = 0x04F3B5;
  constexpr uint24_t Stance_XYOffsetsFX = 0x04F57B;
  constexpr uint24_t VertAdjustments = 0x04F907;
  constexpr uint24_t Prince_ImageDetails = 0x04F99D;
}

constexpr uint24_t splashScreen_Frame = 0x04FBE6;
constexpr uint24_t Title_Intro_Frame = 0x04FC0A;
constexpr uint24_t Title_Intro_Last_Frame = 0x05008A;
constexpr uint24_t Title_Main_Frame = 0x05009C;
constexpr uint24_t Title_Main_Last_Frame = 0x050228;
constexpr uint24_t Title_Main_Game_Frame = 0x05023A;
constexpr uint24_t Title_Main_Credits_Frame = 0x050255;
constexpr uint24_t Title_Credits_Frame = 0x050270;
constexpr uint24_t Chambers_BG_frame = 0x0533E7;
constexpr uint24_t Chambers_FG_frame = 0x053438;
