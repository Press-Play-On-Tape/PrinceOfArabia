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
               FX::drawBitmap(x * 12, y * 31, Images::Tile_Dungeon[Images::xRef[bgTile]], 0, dbmNormal);
                // FX::drawBitmap(x * 12, y * 31, Images::Tile_Dungeon_00 + (Images::xRef[bgTile] * 52), 0, dbmNormal);
            }

        }

    }


    // Draw items ..

    for (uint8_t i = 0; i < NUMBER_OF_ITEMS; i++) {

        Item &item = level.getItem(i);

        if (item.active) {

            switch (item.itemType) {

                case ItemType::Gate:
                    FX::drawBitmap(((item.x - level.getXLocation()) * 12) - 5, (item.y - level.getYLocation()) * 31, Images::Gate_00 + (item.data.gate.position * 76), 0, dbmMasked);
                    break;

                case ItemType::Torch:
                    FX::drawBitmap((item.x - level.getXLocation()) * 12, (item.y - level.getYLocation()) * 31, Images::Torch_00 + (item.data.torch.frame * 16), 0, dbmMasked);
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

        FX::drawBitmap(prince.getXImage(), prince.getYImage(), startPos, 0, dbmMasked);

    }
    else {

        FX::drawBitmap(prince.getXImage(), prince.getYImage(), startPos + (Images::Prince_Right_001 - Images::Prince_Left_001), 0, dbmMasked);

    }

    // arduboy.drawFastVLine(prince.getX(), prince.getY() - 31, 36, arduboy.frameCount % 2);


    // Draw foreground ..

    for (uint8_t y = 0; y < 3; y++) {

        for (uint8_t x = 0; x < 11; x++) {

            int8_t fgTile = level.getTile(Layer::Foreground, x, y);

            if (fgTile >= 0) {

                if (Images::xRef_IsMasked[fgTile]) {

                    FX::drawBitmap(x * 12, y * 31, Images::Tile_Dungeon[Images::xRef[fgTile]], 0, dbmMasked);

                }
                else {
                    FX::drawBitmap(x * 12, y * 31, Images::Tile_Dungeon[Images::xRef[fgTile]], 0, dbmNormal);

                }

            }

        }

    }

}
