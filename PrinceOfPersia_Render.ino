#include <Arduboy2.h>   
#include <ArduboyFX.h>  
#include "fxdata/Images.h"  
#include "fxdata/Levels.h"  

#include "src/utils/Constants.h"
#include "src/utils/Stack.h"
#include "src/entities/Entities.h"
#include "src/fonts/Font3x5.h"


void render() {


    // Draw background ..

    for (uint8_t y = 0; y < 4; y++) {

        for (uint8_t x = 0; x < 10; x++) {

            int8_t bgTile = level.getTile(Layer::Background, x, y - 1, TILE_NONE);

            if (bgTile >= 0) {
               FX::drawBitmap(x * Constants::TileWidth, (y * Constants::TileHeight) - level.getYOffset() - Constants::TileHeight + Constants::ScreenTopOffset, Images::Tile_Dungeon[Images::xRef[bgTile]], 0, dbmNormal);
            }

        }

    }


    // Draw items ..

    for (uint8_t i = 0; i < Constants::NumberOfItems; i++) {

        Item &item = level.getItem(i);
        int16_t xLoc = (item.x - level.getXLocation()) * Constants::TileWidth;
        int16_t yLoc = ((item.y - level.getYLocation()) * Constants::TileHeight) - level.getYOffset() + Constants::ScreenTopOffset;

        if (item.active) {

            switch (item.itemType) {

                case ItemType::Gate:
                    FX::drawBitmap(xLoc - 5, yLoc, Images::Gate_00 + (item.data.gate.position * 76), 0, dbmMasked);
                    break;

                case ItemType::Torch:
                    FX::drawBitmap(xLoc, yLoc, Images::Torch_00 + (item.data.torch.frame * 16), 0, dbmMasked);
                    break;

                case ItemType::CollapsingFloor:
                    FX::drawBitmap(xLoc, yLoc + item.data.collapsingFloor.distanceFallen, Images::CollapsingFloor_01 + (item.data.collapsingFloor.frame * 172), 0, dbmMasked);
                    break;

                case ItemType::CollpasedFloor:
                    FX::drawBitmap(xLoc, yLoc + 18, Images::CollapsedFloor, 0, dbmMasked);
                    break;

                case ItemType::Potion_Small:
                    FX::drawBitmap(xLoc + 6, yLoc + 12, Images::Potion_Small_00 + (item.data.potionSmall.frame * 28), 0, dbmMasked);
                    break;

                default: break;

            }

        }

    }


    // Draw prince ..

    uint16_t stance = prince.getStance();
    uint16_t imageIndex = static_cast<uint16_t>(pgm_read_byte(&Images::StanceToImageXRef[stance]));
    uint24_t startPos = Images::Prince_Left_001 + ((imageIndex - 1) * 364);

    #if defined(DEBUG) && defined(DEBUG_PRINCE_RENDERING)
    DEBUG_PRINT(F("Stance: "));
    DEBUG_PRINT(prince.getStance());
    DEBUG_PRINT(F(", ImageIndex: "));
    DEBUG_PRINTLN(imageIndex);
    #endif

    if (prince.getDirection() == Direction::Left) {

        FX::drawBitmap(prince.getXImage(), prince.getYImage() - level.getYOffset() + Constants::ScreenTopOffset, startPos, 0, dbmMasked);

    }
    else {

        FX::drawBitmap(prince.getXImage(), prince.getYImage() - level.getYOffset() + Constants::ScreenTopOffset, startPos + (Images::Prince_Right_001 - Images::Prince_Left_001), 0, dbmMasked);

    }


    // Draw foreground ..

    for (uint8_t y = 0; y < 4; y++) {

        for (uint8_t x = 0; x < 10; x++) {

            int8_t fgTile = level.getTile(Layer::Foreground, x, y - 1, TILE_NONE);

            if (fgTile >= 0) {

                if (Images::xRef_IsMasked[fgTile]) {

                    FX::drawBitmap(x * Constants::TileWidth, (y * Constants::TileHeight) - level.getYOffset() - Constants::TileHeight + Constants::ScreenTopOffset, Images::Tile_Dungeon[Images::xRef[fgTile]], 0, dbmMasked);

                }
                else {

                    FX::drawBitmap(x * Constants::TileWidth, (y * Constants::TileHeight) - level.getYOffset() - Constants::TileHeight + Constants::ScreenTopOffset, Images::Tile_Dungeon[Images::xRef[fgTile]], 0, dbmNormal);

                }

            }

        }

    }


    // Render health ..

    // arduboy.setTextColor(WHITE);
    arduboy.fillRect(120, 0, WIDTH, HEIGHT, BLACK);
    arduboy.drawFastVLine(121, 0, HEIGHT, WHITE);

    for (uint8_t i = 0; i < prince.getHealthMax(); i++) {

        if (prince.getHealth() > i) {

            FX::drawBitmap(123, 1 + (i * 4), Images::Health_00, 0, dbmNormal);

        }
        else {

            FX::drawBitmap(123, 1 + (i * 4), Images::Health_01, 0, dbmNormal);

        }
        
    }

    FX::drawBitmap(124, 39, Images::Number_Small_00 + ((gamePlay.timer_Min / 10) * 7), 0, dbmNormal);
    FX::drawBitmap(124, 45, Images::Number_Small_00 + ((gamePlay.timer_Min % 10) * 7), 0, dbmNormal);
    FX::drawBitmap(124, 53, Images::Number_Small_00 + ((gamePlay.timer_Sec / 10) * 7), 0, dbmNormal);
    FX::drawBitmap(124, 59, Images::Number_Small_00 + ((gamePlay.timer_Sec % 10) * 7), 0, dbmNormal);

    arduboy.drawPixel(124, 51);
    arduboy.drawPixel(126, 51);

}

void renderMenu() {

    FX::drawBitmap(menu.x, 0, Images::Menu, 0, dbmNormal);
    FX::drawBitmap(menu.x + 3, 22 + (menu.cursor * 10), Images::Sword, 0, dbmNormal);

    FX::drawBitmap(menu.x + 27, 3, Images::Number_00 + ((gamePlay.level / 10) * 9), 0, dbmNormal);
    FX::drawBitmap(menu.x + 33, 3, Images::Number_00 + ((gamePlay.level % 10) * 9), 0, dbmNormal);

    FX::drawBitmap(menu.x + 07, 13, Images::Number_00 + ((gamePlay.timer_Min / 10) * 9), 0, dbmNormal);
    FX::drawBitmap(menu.x + 13, 13, Images::Number_00 + ((gamePlay.timer_Min % 10) * 9), 0, dbmNormal);
    FX::drawBitmap(menu.x + 24, 13, Images::Number_00 + ((gamePlay.timer_Sec / 10) * 9), 0, dbmNormal);
    FX::drawBitmap(menu.x + 30, 13, Images::Number_00 + ((gamePlay.timer_Sec % 10) * 9), 0, dbmNormal);

}
