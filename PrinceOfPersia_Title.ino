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
                break;

            case TitleScreenMode::Main:

                switch (titleScreenVars.option) {

                    case TitleScreenOptions::Play:
                        titleScreenVars.mode = TitleScreenMode::IntroGame1;
                        titleScreenVars.count = 0;
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

            case TitleScreenMode::IntroGame1:

                titleScreenVars.mode = TitleScreenMode::CutScene1;
                titleScreenVars.count = 0;
                fadeInEffect.reset();
                break;

            case TitleScreenMode::CutScene1:

                titleScreenVars.mode = TitleScreenMode::IntroGame2;
                titleScreenVars.count = 0;
                break;

            case TitleScreenMode::IntroGame2:

                gamePlay.gameState = GameState::Game_Init; 
                break;

            default: break;

        }

    }


    // Render ..
// Serial.print((uint8_t)titleScreenVars.mode);
// Serial.print(" ");
// Serial.println((uint8_t)gamePlay.gameState);

    switch (titleScreenVars.mode) {

        case TitleScreenMode::Intro:
        case TitleScreenMode::Main:

            FX::drawBitmap(0, 64 - titleScreenVars.count, Images::Title_Main, 0, dbmNormal);
            FX::drawBitmap(titleScreenVars.option == TitleScreenOptions::Play ? 32 : 61, 145 - titleScreenVars.count, Images::Title_Cursor, 0, dbmNormal);
            FX::drawBitmap(0, (titleScreenVars.count > 64 ? 0 : -32 + (titleScreenVars.count / 2)), Images::Title_PoP, 0, dbmMasked);
            titleScreenVars.update(arduboy.isFrameCount(4));

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
            
            titleScreenVars.update(arduboy.isFrameCount(4));

            break;

        case TitleScreenMode::IntroGame1:

            FX::drawBitmap(5, 64 - titleScreenVars.count, Images::IntroGame1, 0, dbmNormal);
            
            if (titleScreenVars.update(arduboy.isFrameCount(4))) {

                titleScreenVars.mode = TitleScreenMode::CutScene1;
                titleScreenVars.count = 0;
                fadeInEffect.reset();

            }

            break;

        case TitleScreenMode::CutScene1:

            FX::drawBitmap(0, 0, Images::Chambers_BG, 0, dbmNormal);
            FX::drawBitmap(10, 37, Images::Torch_00 + ((arduboy.getFrameCount(15) / 5) * 16), 0, dbmMasked);
            FX::drawBitmap(114, 37, Images::Torch_00 + ((arduboy.getFrameCount(15) / 5) * 16), 0, dbmMasked);
            FX::drawBitmap(titleScreenVars.zaffar_x, 28, Images::Zaffar_00 + (titleScreenVars.zaffar_Image * 260), 0, dbmMasked);
            FX::drawBitmap(0, 0, Images::Chambers_FG, 0, dbmMasked);

            if (titleScreenVars.update(arduboy.isFrameCount(3))) {

                titleScreenVars.mode = TitleScreenMode::IntroGame2;
                titleScreenVars.count = 0;
                fadeInEffect.complete();


            }

            break;

        case TitleScreenMode::IntroGame2:

            FX::drawBitmap(2, 64 -titleScreenVars.count, Images::IntroGame2, 0, dbmNormal);
            
            if (titleScreenVars.update(arduboy.isFrameCount(4))) {

                gamePlay.gameState = GameState::Game_Init; 
                titleScreenVars.count = 0;

            }

            break;


    }


}
