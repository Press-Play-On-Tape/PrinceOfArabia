#pragma once

/**** FX data header generated by fxdata-build.py tool version 1.10 ****/

using uint24_t = __uint24;

// Initialize FX hardware using  FX::begin(FX_DATA_PAGE); in the setup() function.

constexpr uint16_t FX_DATA_PAGE  = 0xfc58;
constexpr uint24_t FX_DATA_BYTES = 239460;

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
}

namespace CutScene
{
  constexpr uint24_t Scene1 = 0x0027F2;
  constexpr uint24_t Scene9 = 0x002BD6;
}

namespace Sounds
{
  constexpr uint24_t Dead = 0x002DD6;
  constexpr uint24_t Grab1 = 0x002DF4;
  constexpr uint24_t Grab2 = 0x002E1E;
  constexpr uint24_t Grab3 = 0x002E48;
  constexpr uint24_t Grab4 = 0x002E82;
  constexpr uint24_t Seque = 0x002ED8;
  constexpr uint24_t Tada = 0x002F52;
  constexpr uint24_t Theme = 0x002F70;
  constexpr uint24_t Triumph = 0x00313E;
}

namespace Images
{
  constexpr uint24_t PPOT = 0x00315C;
  constexpr uint16_t PPOT_WIDTH  = 65;
  constexpr uint16_t PPOTHEIGHT  = 31;
  constexpr uint8_t  PPOT_FRAMES = 4;

  constexpr uint24_t Title_PoP = 0x003570;
  constexpr uint16_t Title_PoP_width  = 128;
  constexpr uint16_t Title_PoP_height = 33;

  constexpr uint24_t Title_Main = 0x003A74;
  constexpr uint16_t Title_Main_width  = 128;
  constexpr uint16_t Title_Main_height = 88;

  constexpr uint24_t Title_Cursor = 0x003FF8;
  constexpr uint16_t Title_Cursor_width  = 5;
  constexpr uint16_t Title_Cursor_height = 5;

  constexpr uint24_t Title_Credits = 0x004001;
  constexpr uint16_t Title_Credits_width  = 73;
  constexpr uint16_t Title_Credits_height = 240;

  constexpr uint24_t TimeRemaining = 0x004893;
  constexpr uint16_t TimeRemainingWidth  = 81;
  constexpr uint16_t TimeRemainingHeight = 15;

  constexpr uint24_t LevelNumber = 0x0049DB;
  constexpr uint16_t LevelNumberWidth  = 81;
  constexpr uint16_t LevelNumberHeight = 15;

  constexpr uint24_t GameOver = 0x004B23;
  constexpr uint16_t GameOverWidth  = 49;
  constexpr uint16_t GameOverHeight = 15;

  constexpr uint24_t PressA = 0x004BEB;
  constexpr uint16_t PressAWidth  = 79;
  constexpr uint16_t PressAHeight = 15;

  constexpr uint24_t IntroGame_1A = 0x004D2B;
  constexpr uint16_t IntroGame_1A_width  = 118;
  constexpr uint16_t IntroGame_1A_height = 96;

  constexpr uint24_t IntroGame_1B = 0x0052B7;
  constexpr uint16_t IntroGame_1B_width  = 123;
  constexpr uint16_t IntroGame_1B_height = 96;

  constexpr uint24_t IntroGame_9 = 0x00587F;
  constexpr uint16_t IntroGame_9_width  = 123;
  constexpr uint16_t IntroGame_9_height = 160;

  constexpr uint24_t Chambers_BG = 0x00621F;
  constexpr uint16_t Chambers_BG_width  = 128;
  constexpr uint16_t Chambers_BG_height = 64;

  constexpr uint24_t Chambers_FG = 0x006623;
  constexpr uint16_t Chambers_FG_width  = 128;
  constexpr uint16_t Chambers_FG_height = 64;

  constexpr uint24_t Numbers_Upright = 0x006E27;
  constexpr uint16_t Numbers_Upright_width  = 7;
  constexpr uint16_t Numbers_Upright_height = 5;
  constexpr uint8_t  Numbers_Upright_frames = 60;

  constexpr uint24_t Menu = 0x006FCF;
  constexpr uint16_t MenuWidth  = 42;
  constexpr uint16_t MenuHeight = 64;

  constexpr uint24_t Sword_Cursor = 0x007123;
  constexpr uint16_t Sword_Cursor_width  = 8;
  constexpr uint16_t Sword_Cursor_height = 10;

  constexpr uint24_t HUD_Backgrounds = 0x007137;
  constexpr uint16_t HUD_Backgrounds_width  = 8;
  constexpr uint16_t HUD_Backgrounds_height = 64;
  constexpr uint8_t  HUD_Backgrounds_frames = 2;

  constexpr uint24_t Numbers = 0x0071BB;
  constexpr uint16_t NumbersWidth  = 11;
  constexpr uint16_t NumbersHeight = 7;
  constexpr uint8_t  NumbersFrames = 60;

  constexpr uint24_t Numbers_Small = 0x007453;
  constexpr uint16_t Numbers_Small_width  = 5;
  constexpr uint16_t Numbers_Small_height = 7;
  constexpr uint8_t  Numbers_Small_frames = 60;

  constexpr uint24_t Healths = 0x007583;
  constexpr uint16_t HealthsWidth  = 5;
  constexpr uint16_t HealthsHeight = 3;
  constexpr uint8_t  HealthsFrames = 2;

  constexpr uint24_t Sword_HUD = 0x007591;
  constexpr uint16_t Sword_HUD_width  = 5;
  constexpr uint16_t Sword_HUD_height = 5;

  constexpr uint24_t Sword = 0x00759A;
  constexpr uint16_t SwordWidth  = 14;
  constexpr uint16_t SwordHeight = 5;

  constexpr uint24_t Skeleton = 0x0075BA;
  constexpr uint16_t SkeletonWidth  = 15;
  constexpr uint16_t SkeletonHeight = 12;

  constexpr uint24_t Gates = 0x0075FA;
  constexpr uint16_t GatesWidth  = 9;
  constexpr uint16_t GatesHeight = 28;
  constexpr uint8_t  GatesFrames = 10;

  constexpr uint24_t Blades = 0x0078CE;
  constexpr uint16_t BladesWidth  = 9;
  constexpr uint16_t BladesHeight = 28;
  constexpr uint8_t  BladesFrames = 6;

  constexpr uint24_t ExitDoors = 0x007A82;
  constexpr uint16_t ExitDoorsWidth  = 25;
  constexpr uint16_t ExitDoorsHeight = 33;
  constexpr uint8_t  ExitDoorsFrames = 13;

  constexpr uint24_t Potions_Small = 0x0080DF;
  constexpr uint16_t Potions_Small_width  = 6;
  constexpr uint16_t Potions_Small_height = 15;
  constexpr uint8_t  Potions_Small_frames = 2;

  constexpr uint24_t Potions_Large = 0x008113;
  constexpr uint16_t Potions_Large_width  = 6;
  constexpr uint16_t Potions_Large_height = 15;
  constexpr uint8_t  Potions_Large_frames = 2;

  constexpr uint24_t Potions_Poison = 0x008147;
  constexpr uint16_t Potions_Poison_width  = 6;
  constexpr uint16_t Potions_Poison_height = 15;
  constexpr uint8_t  Potions_Poison_frames = 6;

  constexpr uint24_t Potion_Poison_Skull = 0x0081DB;
  constexpr uint16_t Potion_Poison_Skull_width  = 25;
  constexpr uint16_t Potion_Poison_Skull_height = 26;

  constexpr uint24_t CollapsedFloor = 0x0082A7;
  constexpr uint16_t CollapsedFloorWidth  = 21;
  constexpr uint16_t CollapsedFloorHeight = 13;

  constexpr uint24_t CollapsingFloors = 0x0082FF;
  constexpr uint16_t CollapsingFloorsWidth  = 21;
  constexpr uint16_t CollapsingFloorsHeight = 31;
  constexpr uint8_t  CollapsingFloorsFrames = 4;

  constexpr uint24_t FloorButton_0_00 = 0x0085A3;
  constexpr uint16_t FloorButton_0_00_width  = 21;
  constexpr uint16_t FloorButton_0_00_height = 32;

  constexpr uint24_t FloorButton_0_01 = 0x00864F;
  constexpr uint16_t FloorButton_0_01_width  = 21;
  constexpr uint16_t FloorButton_0_01_height = 32;

  constexpr uint24_t FloorButton_1_00 = 0x0086FB;
  constexpr uint16_t FloorButton_1_00_width  = 21;
  constexpr uint16_t FloorButton_1_00_height = 32;

  constexpr uint24_t FloorButton_1_01 = 0x0087A7;
  constexpr uint16_t FloorButton_1_01_width  = 21;
  constexpr uint16_t FloorButton_1_01_height = 32;

  constexpr uint24_t FloorButton_2_00 = 0x008853;
  constexpr uint16_t FloorButton_2_00_width  = 12;
  constexpr uint16_t FloorButton_2_00_height = 32;

  constexpr uint24_t FloorButton_2_01 = 0x0088B7;
  constexpr uint16_t FloorButton_2_01_width  = 12;
  constexpr uint16_t FloorButton_2_01_height = 32;

  constexpr uint24_t Torches = 0x00891B;
  constexpr uint16_t TorchesWidth  = 3;
  constexpr uint16_t TorchesHeight = 11;
  constexpr uint8_t  TorchesFrames = 5;

  constexpr uint24_t Spikes_FG_Full = 0x00895B;
  constexpr uint16_t Spikes_FG_Full_width  = 19;
  constexpr uint16_t Spikes_FG_Full_height = 18;
  constexpr uint8_t  Spikes_FG_Full_frames = 5;

  constexpr uint24_t Spikes_BG_Full = 0x008B99;
  constexpr uint16_t Spikes_BG_Full_width  = 19;
  constexpr uint16_t Spikes_BG_Full_height = 18;
  constexpr uint8_t  Spikes_BG_Full_frames = 5;

  constexpr uint24_t Spikes_FG_Half = 0x008DD7;
  constexpr uint16_t Spikes_FG_Half_width  = 11;
  constexpr uint16_t Spikes_FG_Half_height = 18;
  constexpr uint8_t  Spikes_FG_Half_frames = 5;

  constexpr uint24_t Spikes_BG_Half = 0x008F25;
  constexpr uint16_t Spikes_BG_Half_width  = 11;
  constexpr uint16_t Spikes_BG_Half_height = 18;
  constexpr uint8_t  Spikes_BG_Half_frames = 5;

  constexpr uint24_t Flashes = 0x009073;
  constexpr uint16_t FlashesWidth  = 22;
  constexpr uint16_t FlashesHeight = 20;
  constexpr uint8_t  FlashesFrames = 4;

  constexpr uint24_t Tiles_Dungeon = 0x009287;
  constexpr uint16_t Tiles_Dungeon_width  = 12;
  constexpr uint16_t Tiles_Dungeon_height = 31;
  constexpr uint8_t  Tiles_Dungeon_frames = 70;

  constexpr uint24_t Tile_Dungeon_97 = 0x00ACCB;
  constexpr uint16_t Tile_Dungeon_97_width  = 21;
  constexpr uint16_t Tile_Dungeon_97_height = 31;

  constexpr uint24_t Tile_Dungeon_98 = 0x00AD77;
  constexpr uint16_t Tile_Dungeon_98_width  = 12;
  constexpr uint16_t Tile_Dungeon_98_height = 31;

  constexpr uint24_t Tiles_Dungeon_Torch = 0x00ADDB;
  constexpr uint16_t Tiles_Dungeon_Torch_width  = 12;
  constexpr uint16_t Tiles_Dungeon_Torch_height = 31;
  constexpr uint8_t  Tiles_Dungeon_Torch_frames = 60;

  constexpr uint24_t Princess = 0x00C45F;
  constexpr uint16_t PrincessWidth  = 32;
  constexpr uint16_t PrincessHeight = 32;
  constexpr uint8_t  PrincessFrames = 40;

  constexpr uint24_t Princess_Bounce = 0x00EC63;
  constexpr uint16_t Princess_Bounce_width  = 48;
  constexpr uint16_t Princess_Bounce_height = 32;
  constexpr uint8_t  Princess_Bounce_frames = 20;

  constexpr uint24_t Hearts = 0x010A67;
  constexpr uint16_t HeartsWidth  = 7;
  constexpr uint16_t HeartsHeight = 6;
  constexpr uint8_t  HeartsFrames = 4;

  constexpr uint24_t Zaffar = 0x010A87;
  constexpr uint16_t ZaffarWidth  = 32;
  constexpr uint16_t ZaffarHeight = 32;
  constexpr uint8_t  ZaffarFrames = 30;

  constexpr uint24_t HourGlasses = 0x01288B;
  constexpr uint16_t HourGlassesWidth  = 19;
  constexpr uint16_t HourGlassesHeight = 23;
  constexpr uint8_t  HourGlassesFrames = 7;

  constexpr uint24_t Prince_Left = 0x012BAD;
  constexpr uint16_t Prince_Left_width  = 36;
  constexpr uint16_t Prince_Left_height = 36;
  constexpr uint8_t  Prince_Left_frames = 225;

  constexpr uint24_t Prince_Right = 0x026819;
  constexpr uint16_t Prince_Right_width  = 36;
  constexpr uint16_t Prince_Right_height = 36;
  constexpr uint8_t  Prince_Right_frames = 225;

}

namespace Constants
{
  constexpr uint24_t VertAdjustments = 0x03A485;
  constexpr uint24_t Prince_ImageDetails = 0x03A51B;
}

