#include <Arduboy2.h>   
#include <ArduboyFX.h>  
#include "fxdata/Images.h"  
#include "fxdata/Levels.h"  

#include "src/utils/Constants.h"
#include "src/utils/Stack.h"
#include "src/entities/Entities.h"
#include "src/fonts/Font3x5.h"


void render(bool enemyIsVisible) {


    // Draw background ..

    for (uint8_t y = 0; y < 4; y++) {

        for (uint8_t x = 0; x < 10; x++) {

            int8_t bgTile = level.getTile(Layer::Background, x, y - 1, TILE_NONE);

            switch (bgTile) {

                case 0 ... 126:
                   FX::drawBitmap(x * Constants::TileWidth, (y * Constants::TileHeight) - level.getYOffset() - Constants::TileHeight + Constants::ScreenTopOffset, Images::Tile_Dungeon[Images::xTiles_Ref[bgTile]], 0, dbmMasked);
                   break;

                case 127:
                   FX::drawBitmap(x * Constants::TileWidth, (y * Constants::TileHeight) - level.getYOffset() - Constants::TileHeight + Constants::ScreenTopOffset, Images::Tile_Dungeon_50_00 + ((arduboy.getFrameCount(15, (x + 2)) / 5) * 100), 0, dbmMasked);
                   break;

            }

        }

    }


    // Draw items ..

    for (uint8_t i = 0; i < Constants::Items_Count; i++) {

        Item &item = level.getItem(i);
        int16_t xLoc = (item.x - level.getXLocation()) * Constants::TileWidth;
        int16_t yLoc = ((item.y - level.getYLocation()) * Constants::TileHeight) - level.getYOffset() + Constants::ScreenTopOffset;

        if (item.itemType != ItemType::None) {

            switch (item.itemType) {

                case ItemType::Flash:
                    break;

                case ItemType::Sword:
                    FX::drawBitmap(xLoc + 1, yLoc + 20, Images::Sword, 0, dbmMasked);
                    break;

                case ItemType::Spikes:

                    if (item.data.spikes.imageType == 1) {
                        FX::drawBitmap(xLoc, yLoc + 14, Images::Spikes_BG_00 + (item.data.spikes.position * 118), 0, dbmMasked);
                    }
                    else {
                        FX::drawBitmap(xLoc, yLoc + 14, Images::Spikes_BG_05 + (item.data.spikes.position * 70), 0, dbmMasked);
                    }
                    break;

                case ItemType::Skeleton:
                    FX::drawBitmap(xLoc + 5, yLoc + 14, Images::Skeleton, 0, dbmMasked);
                    break;

                case ItemType::ExitDoor:
                    FX::drawBitmap(xLoc + 1, yLoc - 14, Images::ExitDoor_00 + (item.data.exitDoor.position * 129), 0, dbmNormal);
                    break;

                case ItemType::Gate:
                    FX::drawBitmap(xLoc - 5, yLoc, Images::Gate_00 + (item.data.gate.position * 76), 0, dbmMasked);
                    break;

                case ItemType::CollapsingFloor:
                    FX::drawBitmap(xLoc, yLoc + item.data.collapsingFloor.distanceFallen, Images::CollapsingFloor_01 + (item.data.collapsingFloor.frame * 172), 0, dbmMasked);
                    break;

                case ItemType::CollpasedFloor:
                    FX::drawBitmap(xLoc, yLoc + 18, Images::CollapsedFloor, 0, dbmMasked);
                    break;

                case ItemType::Potion_Small:
                    FX::drawBitmap(xLoc + 6, yLoc + 10, Images::Potion_Small_00 + (item.data.potion.frame * 28), 0, dbmMasked);
                    break;

                case ItemType::Potion_Large:
                    FX::drawBitmap(xLoc + 6, yLoc + 10, Images::Potion_Large_00 + (item.data.potion.frame * 28), 0, dbmMasked);
                    break;

                case ItemType::Potion_Poison:
                    FX::drawBitmap(xLoc + 6, yLoc + 10, Images::Potion_Poison_00 + (item.data.potion.frame * 28), 0, dbmMasked);
                    break;

                case ItemType::FloorButton1:
                    FX::drawBitmap(xLoc, yLoc + item.data.floorButton1.frame - 1, Images::FloorButton_0_00 + (item.data.floorButton1.frame * (Images::FloorButton_0_01 - Images::FloorButton_0_00)), 0, dbmMasked);
                    break;

                case ItemType::FloorButton2:
                    FX::drawBitmap(xLoc - item.data.floorButton2.frame, yLoc + item.data.floorButton2.frame, Images::FloorButton_1_00 + (item.data.floorButton2.frame * (Images::FloorButton_1_01 - Images::FloorButton_1_00)), 0, dbmMasked);
                    break;

                default: break;

            }

        }

    }


    // Draw prince ..

    uint16_t stance = prince.getStance();
    uint16_t imageIndex = static_cast<uint16_t>(pgm_read_byte(&Constants::StanceToImageXRef[stance]));
    uint24_t startPos = 0;

    if (imageIndex != 0) {

        startPos = Images::Prince_Left_001 + ((imageIndex - 1) * static_cast<uint24_t>(364));

        #if defined(DEBUG) && defined(DEBUG_PRINCE_RENDERING)
        DEBUG_PRINT(F("Stance: "));
        DEBUG_PRINT(prince.getStance());
        DEBUG_PRINT(F(", ImageIndex: "));
        DEBUG_PRINTLN(imageIndex);
        #endif

        if (prince.getDirection() != Direction::Left) {
            
            startPos = startPos + Constants::LeftRightOffset;

        }

        FX::drawBitmap(prince.getXImage(), prince.getYImage() - level.getYOffset() + Constants::ScreenTopOffset, startPos, 0, dbmMasked);

    }


    // Draw enemy ..

    stance = enemy.getStance();
    imageIndex = static_cast<uint16_t>(pgm_read_byte(&Constants::StanceToImageXRef[stance]));

    if (imageIndex != 0) {

        startPos = Images::Prince_Left_001 + ((imageIndex - 1) * static_cast<uint24_t>(364));

        #if defined(DEBUG) && defined(DEBUG_PRINCE_RENDERING)
        DEBUG_PRINT(F("Stance: "));
        DEBUG_PRINT(prince.getStance());
        DEBUG_PRINT(F(", ImageIndex: "));
        DEBUG_PRINTLN(imageIndex);
        #endif

        if (enemy.getDirection() != Direction::Left) {
            
            startPos = startPos + Constants::LeftRightOffset;

        }

        FX::drawBitmap(enemy.getXImage() - (level.getXLocation() * Constants::TileWidth), enemy.getYImage() - (level.getYLocation() * Constants::TileHeight)- level.getYOffset() + Constants::ScreenTopOffset, startPos, 0, dbmMasked);
    }


    // Draw items ..

    for (uint8_t i = 0; i < Constants::Items_Count; i++) {

        Item &item = level.getItem(i);
        int16_t xLoc = (item.x - level.getXLocation()) * Constants::TileWidth;
        int16_t yLoc = ((item.y - level.getYLocation()) * Constants::TileHeight) - level.getYOffset() + Constants::ScreenTopOffset;

        if (item.itemType != ItemType::None) {

            switch (item.itemType) {

                case ItemType::Spikes:
                    if (item.data.spikes.imageType == 1) {
                        FX::drawBitmap(xLoc, yLoc + 14, Images::Spikes_FG_00 + (item.data.spikes.position * 118), 0, dbmMasked);
                    }
                    else {
                        FX::drawBitmap(xLoc, yLoc + 14, Images::Spikes_FG_05 + (item.data.spikes.position * 70), 0, dbmMasked);
                    }
                    break;

                default: break;

            }

        }

    }


    // Draw foreground ..

    for (uint8_t y = 0; y < 4; y++) {

        for (uint8_t x = 0; x < 10; x++) {

            int8_t fgTile = level.getTile(Layer::Foreground, x, y - 1, TILE_NONE);

            if (fgTile >= 0) {

                FX::drawBitmap(x * Constants::TileWidth, (y * Constants::TileHeight) - level.getYOffset() - Constants::TileHeight + Constants::ScreenTopOffset, Images::Tile_Dungeon[Images::xTiles_Ref[fgTile]], 0, dbmMasked);

            }

        }

    }


    // Draw flash ..

    {
        Flash &item = level.getFlash();
        int16_t xLoc = (item.x - level.getXLocation()) * Constants::TileWidth;
        int16_t yLoc = ((item.y - level.getYLocation()) * Constants::TileHeight) - level.getYOffset() + Constants::ScreenTopOffset;

        if (item.frame > 0 && item.frame < 5) {

            FX::drawBitmap(xLoc - 3, yLoc + 12, Images::Flash_00 + ((item.frame - 1) * 136), 0, dbmMasked);

        }
    
    }


    // Render health ..

    arduboy.fillRect(120, 0, WIDTH, HEIGHT, BLACK);
    arduboy.drawFastVLine(121, 0, HEIGHT, WHITE);

    for (uint8_t i = 0; i < prince.getHealthMax(); i++) {

        if (prince.getHealth() > i) {

            FX::drawBitmap(123, i * 4, Images::Health_00, 0, dbmNormal);

        }
        else {

            FX::drawBitmap(123, i * 4, Images::Health_01, 0, dbmNormal);

        }
        
    }
// Serial.println(enemyIsVisible);    

    if (!enemyIsVisible) {

        renderNumber_Small(123, 47, gamePlay.timer_Min);
        renderNumber_Small(123, 57, gamePlay.timer_Sec);

        if (prince.getSword()) {
            FX::drawBitmap(123, 40, Images::Sword_HUD, 0, dbmNormal);
        }

        arduboy.drawPixel(124, 55);
        arduboy.drawPixel(126, 55);

    }
    else {

        // Render enemy health ..

        for (uint8_t i = 0; i < enemy.getHealthMax(); i++) {

            if (enemy.getHealth() > i) {

                FX::drawBitmap(123, 60 - (i * 4), Images::Health_00, 0, dbmNormal);

            }
            else {

                FX::drawBitmap(123, 60 - (i * 4), Images::Health_01, 0, dbmNormal);

            }
            
        }

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

        switch (sign.type) {

            case SignType::GameOver:
                FX::drawBitmap(sign.x, sign.y, Images::GameOver, 0, dbmMasked);
                break;

            case SignType::PressA:
                FX::drawBitmap(sign.x, sign.y, Images::PressA, 0, dbmMasked);
                break;

        }
    }

}

void renderMenu() {

    FX::drawBitmap(menu.x, 0, Images::Menu, 0, dbmNormal);
    FX::drawBitmap(menu.x + 3, 22 + (menu.cursor * 10), Images::Sword_Cursor, 0, dbmNormal);

    renderNumber(menu.x + 27, 3, gamePlay.level);
    renderNumber(menu.x + 7, 13, gamePlay.timer_Min);
    renderNumber(menu.x + 24, 13, gamePlay.timer_Sec);

}

void renderNumber(uint8_t x, uint8_t y, uint8_t number) {

    FX::drawBitmap(x, y, Images::Number_00 + ((number / 10) * 9), 0, dbmNormal);
    FX::drawBitmap(x + 6, y, Images::Number_00 + ((number % 10) * 9), 0, dbmNormal);

}

void renderNumber_Small(uint8_t x, uint8_t y, uint8_t number) {

    FX::drawBitmap(x, y, Images::Number_Small_00 + ((number / 10) * 9), 0, dbmNormal);
    FX::drawBitmap(x, y + 4, Images::Number_Small_00 + ((number % 10) * 9), 0, dbmNormal);

}

void renderNumber_Upright(uint8_t x, uint8_t y, uint8_t number) {

    FX::drawBitmap(x, y, Images::Number_Upright_00 + ((number / 10) * 7), 0, dbmNormal);
    FX::drawBitmap(x + 4, y, Images::Number_Upright_00 + ((number % 10) * 7), 0, dbmNormal);

}

void renderTorches(uint8_t x1, uint8_t x2, uint8_t y) {

    FX::drawBitmap(x1, y, Images::Torch_00 + ((arduboy.getFrameCount(15) / 5) * 16), 0, dbmMasked);
    FX::drawBitmap(x2, y, Images::Torch_00 + ((arduboy.getFrameCount(15) / 5) * 16), 0, dbmMasked);

}