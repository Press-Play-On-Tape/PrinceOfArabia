#include <Arduboy2.h>   
#include <ArduboyFX.h>  
#include "fxdata/Images.h"  

#include "src/utils/Constants.h"
#include "src/utils/Stack.h"
#include "src/entities/Entities.h"
#include "src/fonts/Font3x5.h"


void render(bool sameLevelAsPrince) {


    // Draw background and collapsed tiles ..

    for (uint8_t y = 0; y < 4; y++) {

        for (int8_t x = 9; x >= 0; x--) {

            int8_t bgTile = level.getTile(Layer::Background, x, y - 1, TILE_NONE);
            int16_t yCoord = (y * Constants::TileHeight) - level.getYOffset() - Constants::TileHeight + Constants::ScreenTopOffset;

            switch (bgTile) {

                case 0 ... 123:
                   FX::drawBitmap(x * Constants::TileWidth, yCoord, Images::Tiles_Dungeon, Images::xTiles_Ref[bgTile], dbmMasked);
                   break;

                case 124:
                case 127:
                   FX::drawBitmap(x * Constants::TileWidth, yCoord, Images::Tiles_Dungeon_Torch, (arduboy.getFrameCount(15, (x + 2)) / 5), dbmMasked);
                   break;

            }
            
            // Draw foreground, collapased tiles ..

            int8_t fgTile = level.getTile(Layer::Foreground, x, y - 1, TILE_NONE);

            if      (fgTile == 29) FX::drawBitmap(x * Constants::TileWidth, yCoord, Images::Tile_Dungeon_97, 0, dbmMasked);
            else if (fgTile == 30) FX::drawBitmap(x * Constants::TileWidth, yCoord, Images::Tile_Dungeon_98, 0, dbmMasked);

        }

    }

    // Draw items ..

    for (uint8_t i = 0; i < Constants::Items_Count; i++) {

        Item &item = level.getItem(i);
        int16_t xLoc = (item.data.location.x - level.getXLocation()) * Constants::TileWidth;
        int16_t yLoc = ((item.data.location.y - level.getYLocation()) * Constants::TileHeight) - level.getYOffset() + Constants::ScreenTopOffset;

        if (item.itemType != ItemType::None) {

            switch (item.itemType) {

                case ItemType::Sword:
                    FX::drawBitmap(xLoc + 1, yLoc + 20, Images::Sword, 0, dbmMasked);
                    break;

                case ItemType::Spikes:

                    if (item.data.spikes.imageType == 1) {
                        FX::drawBitmap(xLoc, yLoc + 14, Images::Spikes_BG_Full, item.data.spikes.position, dbmMasked);
                    }
                    else {
                        FX::drawBitmap(xLoc, yLoc + 14, Images::Spikes_BG_Half, item.data.spikes.position, dbmMasked);
                    }
                    break;

                case ItemType::Blade:

                    if (item.data.blade.position <= 5) {
                        FX::drawBitmap(xLoc, yLoc, Images::Blades, abs(item.data.blade.position), dbmMasked);

                        #ifndef SAVE_MEMORY_SOUND
                            if (xLoc > 0 && xLoc < 128 && yLoc>= 0 && yLoc < 64 && item.data.blade.position == 4) {
                                sound.tonesFromFX(Sounds::ChopChop);
                            }
                        #endif 

                    }
                    break;

                case ItemType::Skeleton:
                    FX::drawBitmap(xLoc + 5, yLoc + 14, Images::Skeleton, 0, dbmMasked);
                    break;

                case ItemType::ExitDoor_SelfOpen:
                case ItemType::ExitDoor_ButtonOpen:
                    FX::drawBitmap(xLoc + 1, yLoc - 14, Images::ExitDoors, item.data.exitDoor.position, dbmNormal);
                    break;

                case ItemType::Gate:
                case ItemType::Gate_StayClosed:
                case ItemType::Gate_StayOpen:
                    FX::drawBitmap(xLoc - 5, yLoc, Images::Gates, item.data.gate.position, dbmMasked);
                    break;

                case ItemType::EntryDoor:
                    FX::drawBitmap(xLoc + 7, yLoc - 14, Images::ExitDoors, 1, dbmNormal);
                    break;

                case ItemType::EntryDoor_Cropped:
                    FX::drawBitmap(xLoc + 1, yLoc - 14, Images::ExitDoors, Images::ExitDoorsFrames - 1, dbmNormal);
                    break;

                case ItemType::EntryDoor_HalfTileLeft:
                    FX::drawBitmap(xLoc + 1, yLoc - 14, Images::ExitDoors, 1, dbmNormal);
                    break;

                case ItemType::CollapsingFloor:
                    FX::drawBitmap(xLoc, yLoc + item.data.collapsingFloor.distanceFallen, Images::CollapsingFloors, item.data.collapsingFloor.frame, dbmMasked);
                    break;

                case ItemType::CollpasedFloor:
                    FX::drawBitmap(xLoc, yLoc + 18, Images::CollapsedFloor, 0, dbmMasked);
                    break;

                case ItemType::Potion_Small:
                    FX::drawBitmap(xLoc + 6, yLoc + 10, Images::Potions_Small, item.data.potion.frame, dbmMasked);
                    break;

                case ItemType::Potion_Large:
                    FX::drawBitmap(xLoc + 6, yLoc + 10, Images::Potions_Large, item.data.potion.frame, dbmMasked);
                    break;

                case ItemType::Potion_Poison:
                    FX::drawBitmap(xLoc + 6, yLoc + 10, Images::Potions_Poison, item.data.potion.frame, dbmMasked);
                    break;

                case ItemType::Potion_Float:
                    FX::drawBitmap(xLoc + 6, yLoc + 10, Images::Potions_Float, item.data.potion.frame, dbmMasked);
                    break;

                case ItemType::Mirror:

                    if (item.data.mirror.status == Status::Active) {

                        bool showShadow = false;

                        uint8_t mirrorX = level.coordToTileIndexX(xLoc) + level.getXLocation();
                        uint8_t mirrorY = level.coordToTileIndexY(yLoc) + level.getYLocation();
                        
                        int8_t princeX = level.coordToTileIndexX(prince.getPosition().x);
                        int8_t princeY = level.coordToTileIndexY(prince.getPosition().y);

                        #ifndef SAVE_MEMORY_ENEMY

                            if ((princeX == mirrorX || princeX == mirrorX + 1) && princeY == mirrorY && enemy.getStatus() == Status::Dormant_ActionReady) {

                                showShadow = true;

                            }

                        #endif

                        FX::drawBitmap(xLoc, yLoc, Images::Mirrors, showShadow, dbmNormal);
                        
                    }
                    break;

                case ItemType::FloorButton1:
                case ItemType::FloorButton3_UpDown:
                case ItemType::FloorButton3_UpOnly:
                case ItemType::ExitDoor_Button:
                case ItemType::Mirror_Button:
                    FX::drawBitmap(xLoc, yLoc + item.data.floorButton.frame - 1, Images::FloorButtons_0and1, item.data.floorButton.frame, dbmMasked);
                    break;

                case ItemType::ExitDoor_Button_Cropped:
                    FX::drawBitmap(xLoc, yLoc + item.data.floorButton.frame - 1, Images::FloorButtons_2, item.data.floorButton.frame, dbmMasked);
                    break;

                case ItemType::FloorButton2:
                case ItemType::FloorButton4:
                case ItemType::FloorButton3_DownOnly:
                    FX::drawBitmap(xLoc - item.data.floorButton.frame, yLoc + item.data.floorButton.frame, Images::FloorButtons_0and1, item.data.floorButton.frame + 2, dbmMasked);
                    break;

                case ItemType::AppearingFloor:
                    if (item.data.appearingFloor.visible) {
                        FX::drawBitmap(xLoc, yLoc, Images::FloorButtons_0and1, 1, dbmMasked);
                    }
                    break;

                case ItemType::DecorativeDoor:
                    FX::drawBitmap(xLoc, yLoc - 21, Images::DecorativeDoor, 0, dbmNormal);
                    break;

                default: break;

            }

        }

    }


    // Draw enemy ..

    #ifndef SAVE_MEMORY_ENEMY

        if (enemy.getStatus() == Status::Active) {
                
            uint16_t stance = enemy.getStance();
            uint8_t imageIndex = getImageIndexFromStance(stance);

            if (imageIndex != 0) {

                #if defined(DEBUG) && defined(DEBUG_PRINCE_RENDERING)
                DEBUG_PRINT(F("Stance: "));
                DEBUG_PRINT(prince.getStance());
                DEBUG_PRINT(F(", ImageIndex: "));
                DEBUG_PRINTLN(imageIndex);
                #endif

                int16_t xCoord = enemy.getXImage() - (level.getXLocation() * Constants::TileWidth);
                int16_t yCoord = enemy.getYImage() - (level.getYLocation() * Constants::TileHeight)- level.getYOffset() + Constants::ScreenTopOffset;
                uint24_t imagePos = 0;

                switch (enemy.getEnemyType()) {

                    case EnemyType::Guard:
                    case EnemyType::Skeleton:
                        imagePos = (enemy.getDirection() == Direction::Left ? Images::Enemy_Left : Images::Enemy_Right);
                        break;

                    case EnemyType::Mirror:
                    case EnemyType::MirrorAttackingL12:
                    case EnemyType::MirrorAfterChallengeL12:
                        imagePos = (enemy.getDirection() == Direction::Left ? Images::Mirror_Left : Images::Mirror_Right);
                        break;

                    default:
                        break;

                }
                    
                FX::drawBitmap(xCoord, yCoord, imagePos, imageIndex - 1, dbmMasked);
                
            }

        }

    #endif


    // Draw prince ..

    uint16_t stance = prince.getStance();
    uint8_t imageIndex = getImageIndexFromStance(stance);

    if (imageIndex != 0) {

        #if defined(DEBUG) && defined(DEBUG_PRINCE_RENDERING)
        DEBUG_PRINT(F("Stance: "));
        DEBUG_PRINT(prince.getStance());
        DEBUG_PRINT(F(", ImageIndex: "));
        DEBUG_PRINTLN(imageIndex);
        #endif

        int16_t yCoord = prince.getYImage() - level.getYOffset() + Constants::ScreenTopOffset;

        //if (prince.getDirection() == Direction::Left) {
        //
        //    FX::drawBitmap(prince.getXImage(), yCoord, Images::Prince_Left, imageIndex - 1, dbmMasked);
        //
        //}
        //else {
        //
        //    FX::drawBitmap(prince.getXImage(), yCoord, Images::Prince_Right, imageIndex - 1, dbmMasked);
        //
        //}
        uint24_t princeImage = Images::Prince_Right;

        if (prince.getDirection() == Direction::Left) {
            
            princeImage = Images::Prince_Left;
            
        }

        FX::drawBitmap(prince.getXImage(), yCoord, princeImage, imageIndex - 1, dbmMasked);
    }



    // Draw items ..

    for (uint8_t i = 0; i < Constants::Items_Count; i++) {

        Item &item = level.getItem(i);
        int16_t xLoc = (item.data.location.x - level.getXLocation()) * Constants::TileWidth;
        int16_t yLoc = ((item.data.location.y - level.getYLocation()) * Constants::TileHeight) - level.getYOffset() + Constants::ScreenTopOffset;

        if (item.itemType != ItemType::None) {

            switch (item.itemType) {

                case ItemType::Spikes:

                    if (item.data.spikes.imageType == 1) {
                        FX::drawBitmap(xLoc, yLoc + 14, Images::Spikes_FG_Full, item.data.spikes.position, dbmMasked);
                    }
                    else {
                        FX::drawBitmap(xLoc, yLoc + 14, Images::Spikes_FG_Half, item.data.spikes.position, dbmMasked);
                    }

                    break;

                case ItemType::Blade:

                    if (item.data.blade.position <= 5) {
                        FX::drawBitmap(xLoc, yLoc, Images::Blades, abs(item.data.blade.position) + 6, dbmMasked);
                    }

                    break;

                default: break;

            }

        }

    }


    // Draw Mouse?

    if (gamePlay.level == 8 && level.getXLocation() == 40 && level.getYLocation() == 3) {

        switch (mouse.counter) {

            case 1 ... 70:
                FX::drawBitmap(120 - (mouse.counter / 2), 14, Images::Mouse, 0, dbmMasked);
                break;

            case 71 ... 80:
                FX::drawBitmap(110 - 24, 14, Images::Mouse, 2, dbmMasked);
                break;

            case 81 ... 141:
                FX::drawBitmap(50 + (mouse.counter / 2), 14, Images::Mouse, 1, dbmMasked);
                break;
                
        }

    }


    // Draw foreground ..

    for (uint8_t y = 0; y < 4; y++) {

        for (uint8_t x = 0; x < 10; x++) {

            int8_t fgTile = level.getTile(Layer::Foreground, x, y - 1, TILE_NONE);
            int16_t yCoord = (y * Constants::TileHeight) - level.getYOffset() - Constants::TileHeight + Constants::ScreenTopOffset;

            if (fgTile >= 0) {

                switch (fgTile) {

                    case 29:
                    case 30:
                        break;

                    default:
                        FX::drawBitmap(x * Constants::TileWidth, yCoord, Images::Tiles_Dungeon, Images::xTiles_Ref[fgTile], dbmMasked);
                        break;

                }

            }

        }

    }


    // Draw flash ..

    {
        Flash &item = level.getFlash();
        int16_t xLoc = (item.x - level.getXLocation()) * Constants::TileWidth;
        int16_t yLoc = ((item.y - level.getYLocation()) * Constants::TileHeight) - level.getYOffset() + Constants::ScreenTopOffset;

        if (item.frame > 0 && item.frame < 5) {

            FX::drawBitmap(xLoc - 3, yLoc + 12, Images::Flashes, item.frame - 1, dbmMasked);

        }
    
    }


    // Render health ..

    FX::drawBitmap(120, 0, Images::HUD_Backgrounds, sameLevelAsPrince, dbmNormal);

    for (uint8_t i = 0; i < prince.getHealthMax(); i++) {

        FX::drawBitmap(123, i * 4, Images::Healths, prince.getHealth() <= i, dbmNormal);
        
    }


    if (!sameLevelAsPrince) {

        uint8_t hudY = 40;

        renderNumber_Small(123, 47, gamePlay.timer_Min);
        renderNumber_Small(123, 57, gamePlay.timer_Sec);

        if (prince.getSword()) {
            FX::drawBitmap(123, hudY, Images::Sword_HUD, 0, dbmNormal);
            hudY = hudY - 7;
        }

        if (prince.getPotionFloat()) {
            FX::drawBitmap(123, hudY, Images::Potion_Float_HUD, 0, dbmNormal);
        }

    }
    else {

        // Render enemy health ..

        #ifndef SAVE_MEMORY_ENEMY

            for (uint8_t i = 0; i < enemy.getHealthMax(); i++) {

                FX::drawBitmap(123, 60 - (i * 4), Images::Healths, enemy.getHealth() <= i, dbmNormal);
                
            }

        #endif

    }


    // Time remaining popup ..

    {

        uint8_t y = 0;

        switch (prince.getY()) {

            case 25:
                y = 48;
                break;

            case 56:
            case 87:
                y = 1;
                break;

        }

        switch (gamePlay.timeRemaining) {

            case 1 ... 80:
                FX::drawBitmap(23, y, Images::TimeRemaining, 0, dbmMasked);
                renderNumber_Upright(29, y + 5, gamePlay.timer_Min);
                break;

        }
    
    }


    // Game over / press A ..

    Sign sign = level.getSign();

    if (sign.counter == 1) {

        //switch (sign.type) {
        //
        //    case SignType::GameOver:
        //        FX::drawBitmap(sign.x, sign.y, Images::GameOver, 0, dbmMasked);
        //        break;
        //
        //    case SignType::PressA:
        //        FX::drawBitmap(sign.x, sign.y, Images::PressA, 0, dbmMasked);
        //        break;
        //
        //}
        uint24_t signImage = Images::PressA;

        if (sign.type == SignType::GameOver) {

            signImage = Images::GameOver;

        }

        FX::drawBitmap(sign.x, sign.y, signImage, 0, dbmMasked);

    }

}


void renderMenu(Prince &prince) {

    uint8_t imageIdx;
    uint8_t cursorY = 22;

    if (!prince.isDead()) {

        if (menu.cursor < 4) {

            imageIdx = !cookie.hasSavedLevel;

        }
        else {

            imageIdx = 2;
            cursorY = 12;

        }

    }
    else {

        imageIdx = cookie.hasSavedLevel ? 3 : 1;

    }

    FX::drawBitmap(menu.x, 0, Images::Menu, imageIdx, dbmNormal);
    FX::drawBitmap(menu.x + 3, cursorY + (menu.cursor * 10), Images::Sword_Cursor, 0, dbmNormal);

    renderNumber(menu.x + 27, 3, gamePlay.level);
    renderNumber(menu.x + 7, 13, gamePlay.timer_Min);
    renderNumber(menu.x + 24, 13, gamePlay.timer_Sec);

}


void renderNumber(uint8_t x, uint8_t y, uint8_t number) {

    FX::drawBitmap(x, y, Images::Numbers, number, dbmNormal);

}

void renderNumber_Small(uint8_t x, uint8_t y, uint8_t number) {

    FX::drawBitmap(x, y, Images::Numbers_Small, number, dbmNormal);

}

void renderNumber_Upright(uint8_t x, uint8_t y, uint8_t number) {

    FX::drawBitmap(x, y, Images::Numbers_Upright, number, dbmNormal);

}

void renderTorches(uint8_t x1, uint8_t x2, uint8_t y) {

    uint8_t frame = arduboy.getFrameCount(15) / 5;
    FX::drawBitmap(x1, y, Images::Torches, frame, dbmMasked);
    FX::drawBitmap(x2, y, Images::Torches, frame, dbmMasked);

}

