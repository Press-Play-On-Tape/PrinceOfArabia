#include <Arduboy2.h>   
#include <ArduboyFX.h>  
#include "fxdata/Images.h"  
#include "fxdata/Levels.h"  

#include "src/utils/Constants.h"
#include "src/utils/Stack.h"
#include "src/entities/Entities.h"
#include "src/fonts/Font3x5.h"


void render() {


    for (uint8_t y = 0; y < 3; y++) {

        for (uint8_t x = 0; x < 11; x++) {

            int8_t bgTile = level.getTile(Layer::Background, x, y);

            if (bgTile >= 0) {
                FX::drawBitmap(x * 12, y * 31, Images::Tile_Dungeon[Images::xRef[bgTile]], 0, dbmNormal);
            }

        }

    }


    // Draw prince ..

    uint16_t stance = prince.getStance();
    uint24_t startPos = Images::Prince_Left_001 + ((stance - 1) * 364);

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




// FX::drawBitmap(0, -4, Images::Prince_Left_090, 0, dbmMasked);
// FX::drawBitmap(16, -4, Images::Prince_Left_091, 0, dbmMasked);
// FX::drawBitmap(32, -4, Images::Prince_Left_092, 0, dbmMasked);
// FX::drawBitmap(48, -4, Images::Prince_Left_093, 0, dbmMasked);
// uint24_t startPos = (90 - 1) * 364;
// FX::drawBitmap(0, -4, Images::Prince_Left_001 + (startPos), 0, dbmMasked);
// startPos = startPos + 364;
// FX::drawBitmap(16, -4, Images::Prince_Left_001 + (startPos), 0, dbmMasked);
// startPos = startPos + 364;
// FX::drawBitmap(32, -4, Images::Prince_Left_001 + (startPos), 0, dbmMasked);
// startPos = startPos + 364;
// FX::drawBitmap(48, -4, Images::Prince_Left_001 + (startPos), 0, dbmMasked);

    //program code



}
