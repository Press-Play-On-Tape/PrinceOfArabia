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

    for (uint8_t y = 0; y < 3; y++) {

        for (uint8_t x = 0; x < 11; x++) {

            int8_t bgTile = level.getTile(Layer::Background, x, y);

            if (bgTile >= 0) {
               FX::drawBitmap(x * 12, (y * 31) - level.getYOffset(), Images::Tile_Dungeon[Images::xRef[bgTile]], 0, dbmNormal);
            }

        }

    }


    // Draw items ..

    for (uint8_t i = 0; i < Constants::NumberOfItems; i++) {

        Item &item = level.getItem(i);

        if (item.active) {

            switch (item.itemType) {

                case ItemType::Gate:
                    FX::drawBitmap(((item.x - level.getXLocation()) * 12) - 5, ((item.y - level.getYLocation()) * 31) - level.getYOffset(), Images::Gate_00 + (item.data.gate.position * 76), 0, dbmMasked);
                    break;

                case ItemType::Torch:
                    FX::drawBitmap((item.x - level.getXLocation()) * 12, ((item.y - level.getYLocation()) * 31) - level.getYOffset(), Images::Torch_00 + (item.data.torch.frame * 16), 0, dbmMasked);
                    break;

                case ItemType::CollapsingFloor:
                    FX::drawBitmap((item.x - level.getXLocation()) * 12, ((item.y - level.getYLocation()) * 31) - level.getYOffset() + item.data.collapsingFloor.distanceFallen, Images::CollapsingFloor_01 + (item.data.collapsingFloor.frame * 172), 0, dbmMasked);
                    break;

                case ItemType::CollpasedFloor:
                    FX::drawBitmap((item.x - level.getXLocation()) * 12, ((item.y - level.getYLocation()) * 31) - level.getYOffset() + 19, Images::CollapsedFloor, 0, dbmMasked);
                    break;

                case ItemType::Potion_Small:
                    FX::drawBitmap(((item.x - level.getXLocation()) * 12) + 6, ((item.y - level.getYLocation()) * 31) - level.getYOffset() + 12, Images::Potion_Small_00 + (item.data.potionSmall.frame * 28), 0, dbmMasked);
                    break;

                default: break;

            }

        }

    }


    // Draw prince ..

    uint16_t stance = prince.getStance();
    uint16_t imageIndex = static_cast<uint16_t>(pgm_read_byte(&Images::StanceToImageXRef[stance]));
    uint24_t startPos = Images::Prince_Left_001 + ((imageIndex - 1) * 364);

    if (prince.getDirection() == Direction::Left) {

        FX::drawBitmap(prince.getXImage(), prince.getYImage() - level.getYOffset(), startPos, 0, dbmMasked);

    }
    else {

        FX::drawBitmap(prince.getXImage(), prince.getYImage() - level.getYOffset(), startPos + (Images::Prince_Right_001 - Images::Prince_Left_001), 0, dbmMasked);

    }


    // Draw foreground ..

    for (uint8_t y = 0; y < 3; y++) {

        for (uint8_t x = 0; x < 11; x++) {

            int8_t fgTile = level.getTile(Layer::Foreground, x, y);

            if (fgTile >= 0) {

                if (Images::xRef_IsMasked[fgTile]) {

                    FX::drawBitmap(x * 12, (y * 31) - level.getYOffset(), Images::Tile_Dungeon[Images::xRef[fgTile]], 0, dbmMasked);

                }
                else {

                    FX::drawBitmap(x * 12, (y * 31) - level.getYOffset(), Images::Tile_Dungeon[Images::xRef[fgTile]], 0, dbmNormal);

                }

            }

        }

    }

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
