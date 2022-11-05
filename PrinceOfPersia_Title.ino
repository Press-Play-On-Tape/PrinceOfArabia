#include <Arduboy2.h>

void title_Init() {

    gamePlay.gameState = GameState::Title;
    titleScreenVars.reset();
}


// ----------------------------------------------------------------------------
//  Handle state updates .. 
//
void title() { 

    auto justPressed = arduboy.justPressedButtons();

    if (justPressed & RIGHT_BUTTON && titleScreenVars.count < Constants::TitleScreenScroll_Max) {

        titleScreenVars.mode = TitleScreenMode::Main;

    }

    if (justPressed & LEFT_BUTTON) {

        titleScreenVars.option = TitleScreenOptions::Play;

    }

    if (justPressed & RIGHT_BUTTON) {

        titleScreenVars.option = TitleScreenOptions::Credits;

    }

    if ((justPressed & A_BUTTON) || (justPressed & B_BUTTON)) {

        switch (titleScreenVars.mode) {

            case TitleScreenMode::Intro:

                titleScreenVars.mode = TitleScreenMode::Main;
                // titleScreenVars.count = Constants::TitleScreenScroll_Max;    

                break;

            case TitleScreenMode::Main:

                switch (titleScreenVars.option) {

                    case TitleScreenOptions::Play:
                        gamePlay.gameState = GameState::Game_Init; 
                        break;

                    case TitleScreenOptions::Credits:
                        titleScreenVars.mode = TitleScreenMode::Credits;
                        titleScreenVars.count = 0;
                        break;

                }        

                break;

            case TitleScreenMode::Credits:

                titleScreenVars.mode = TitleScreenMode::Main;
                titleScreenVars.count = 88;
                break;

        }

    }


    // Render ..

    switch (titleScreenVars.mode) {

        case TitleScreenMode::Intro:
        case TitleScreenMode::Main:

            FX::drawBitmap(0, 64 - titleScreenVars.count, Images::Title_Main, 0, dbmNormal);
            FX::drawBitmap(titleScreenVars.option == TitleScreenOptions::Play ? 32 : 61, 145 - titleScreenVars.count, Images::Title_Cursor, 0, dbmNormal);
            FX::drawBitmap(0, (titleScreenVars.count > 64 ? 0 : -32 + (titleScreenVars.count / 2)), Images::Title_PoP, 0, dbmMasked);
            titleScreenVars.update();

            break;

        case TitleScreenMode::Credits:

            FX::drawBitmap(  7, 39, Images::Torch_00 + ((arduboy.getFrameCount(15) / 5) * 16), 0, dbmMasked);
            FX::drawBitmap( 14, 34, Images::Torch_00 + ((arduboy.getFrameCount(15) / 5) * 16), 0, dbmMasked);
            FX::drawBitmap(119, 39, Images::Torch_00 + ((arduboy.getFrameCount(15) / 5) * 16), 0, dbmMasked);
            FX::drawBitmap(112, 34, Images::Torch_00 + ((arduboy.getFrameCount(15) / 5) * 16), 0, dbmMasked);

            FX::drawBitmap(  0, 54, Images::Tile_Dungeon_12, 0, dbmNormal);
            FX::drawBitmap( 12, 54, Images::Tile_Dungeon_13, 0, dbmNormal);
            FX::drawBitmap(105, 54, Images::Tile_Dungeon_12, 0, dbmNormal);
            FX::drawBitmap(117, 54, Images::Tile_Dungeon_13, 0, dbmNormal);

            FX::drawBitmap(27, -titleScreenVars.count, Images::Title_Credits, 0, dbmNormal);
            FX::drawBitmap(0, 0, Images::Title_PoP, 0, dbmMasked);
            
            if (arduboy.isFrameCount(2)) { titleScreenVars.update(); }

            break;

    }


}
