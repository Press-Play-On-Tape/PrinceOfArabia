#include <Arduboy2.h>

void title_Init() {

    gamePlay.gameState = GameState::Title;
    titleScreenVars.reset();


    // titleScreenVars.setMode(TitleScreenMode::CutScene9, level);//SJH remove


}


// ----------------------------------------------------------------------------
//  Handle state updates .. 
//
void title() { 


    auto justPressed = arduboy.justPressedButtons();

    if (justPressed & RIGHT_BUTTON && titleScreenVars.count < Constants::TitleScreenScroll_Max) {

       titleScreenVars.setMode(TitleScreenMode::Main, level);

    }

    if (justPressed & LEFT_BUTTON) {

        titleScreenVars.option = TitleScreenOptions::Play;

    }

    if (justPressed & RIGHT_BUTTON) {

        titleScreenVars.option = TitleScreenOptions::Credits;

    }

    if ((justPressed & A_BUTTON) || (justPressed & B_BUTTON)) {

        switch (titleScreenVars.getMode()) {

            case TitleScreenMode::Intro:

                titleScreenVars.setMode(TitleScreenMode::Main, level);
                break;

            case TitleScreenMode::Main:

                switch (titleScreenVars.option) {

                    #ifdef SAVE_MEMORY_OTHER
                        case TitleScreenOptions::Play:
                            gamePlay.gameState = GameState::Game_Init;
                            break;

                    #else
                    
                        case TitleScreenOptions::Play:
                            titleScreenVars.setMode(TitleScreenMode::IntroGame1, level);
                            titleScreenVars.count = 0;
                            break;
                    
                        case TitleScreenOptions::Credits:
                            titleScreenVars.setMode(TitleScreenMode::Credits, level);
                            titleScreenVars.count = 0;
                            break;
                    
                    #endif

                    default: break;

                }        

                break;

            #ifndef SAVE_MEMORY_OTHER

                case TitleScreenMode::Credits:

                    titleScreenVars.setMode(TitleScreenMode::Main, level);
                    titleScreenVars.count = 88;
                    break;

                case TitleScreenMode::IntroGame1:

                    titleScreenVars.setMode(TitleScreenMode::CutScene1, level);
                    titleScreenVars.count = 0;
                    fadeEffect.reset();
                    break;

                case TitleScreenMode::CutScene1:

                    titleScreenVars.setMode(TitleScreenMode::IntroGame2, level);
                    titleScreenVars.count = 0;
                    break;

                case TitleScreenMode::IntroGame2:

                    gamePlay.gameState = GameState::Game_Init; 
                    break;

            #endif

            default: break;

        }

    }


    // Render ..

    switch (titleScreenVars.getMode()) {

        case TitleScreenMode::Intro:
        case TitleScreenMode::Main:

            FX::drawBitmap(0, 64 - titleScreenVars.count, Images::Title_Main, 0, dbmNormal);
            FX::drawBitmap(titleScreenVars.option == TitleScreenOptions::Play ? 32 : 61, 145 - titleScreenVars.count, Images::Title_Cursor, 0, dbmNormal);
            FX::drawBitmap(0, (titleScreenVars.count > 64 ? 0 : -32 + (titleScreenVars.count / 2)), Images::Title_PoP, 0, dbmMasked);
            titleScreenVars.update(arduboy.isFrameCount(4));

            break;

        #ifndef SAVE_MEMORY_OTHER
            
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

                    titleScreenVars.setMode(TitleScreenMode::CutScene1, level);
                    titleScreenVars.count = 0;
                    fadeEffect.reset();

                }

                break;

            case TitleScreenMode::CutScene1:

                FX::drawBitmap(  0,  0, Images::Chambers_BG, 0, dbmNormal);
                FX::drawBitmap( 10, 37, Images::Torch_00 + ((arduboy.getFrameCount(15) / 5) * 16), 0, dbmMasked);
                FX::drawBitmap(114, 37, Images::Torch_00 + ((arduboy.getFrameCount(15) / 5) * 16), 0, dbmMasked);
                FX::drawBitmap(titleScreenVars.princess.x, 28, Images::Princess_00 + (titleScreenVars.princess.image * 260), 0, dbmMasked);
                FX::drawBitmap(titleScreenVars.zaffar.x, 28, Images::Zaffar_00 + (titleScreenVars.zaffar.image * 260), 0, dbmMasked);
                FX::drawBitmap(0, 0, Images::Chambers_FG, 0, dbmMasked);

                if (titleScreenVars.count >= 169) {
                    FX::drawBitmap(54, 40, Images::HourGlass, 0, dbmMasked);
                }

                if (titleScreenVars.update(arduboy.isFrameCount(3))) {

                    titleScreenVars.setMode(TitleScreenMode::IntroGame2, level);
                    titleScreenVars.count = 0;
                    fadeEffect.complete();


                }

                break;

            case TitleScreenMode::IntroGame2:

                FX::drawBitmap(2, 64 -titleScreenVars.count, Images::IntroGame2, 0, dbmNormal);
                
                if (titleScreenVars.update(arduboy.isFrameCount(4))) {

                    gamePlay.gameState = GameState::Game_Init; 
                    titleScreenVars.count = 0;

                }

                break;

            case TitleScreenMode::CutScene9:
                {
                    uint24_t startPos = Images::Prince_Left_001 + ((static_cast<uint24_t>(titleScreenVars.prince.image) - 1) * static_cast<uint24_t>(364));

                    FX::drawBitmap(0, 0, Images::Chambers_BG, 0, dbmNormal);
                    FX::drawBitmap(10, 37, Images::Torch_00 + ((arduboy.getFrameCount(15) / 5) * 16), 0, dbmMasked);
                    FX::drawBitmap(114, 37, Images::Torch_00 + ((arduboy.getFrameCount(15) / 5) * 16), 0, dbmMasked);
                    FX::drawBitmap(titleScreenVars.prince.x, 29, startPos, 0, dbmMasked);
                    FX::drawBitmap(titleScreenVars.princess.x, 28, Images::Princess_00 + (titleScreenVars.princess.image * 260), 0, dbmMasked);
                    FX::drawBitmap(0, 0, Images::Chambers_FG, 0, dbmMasked);

                    if (titleScreenVars.update(arduboy.isFrameCount(4))) {

                        titleScreenVars.setMode(TitleScreenMode::IntroGame9, level);
                        titleScreenVars.count = 0;

                    }

                    Item &heart = level.getItem(Constants::Item_LoveHeart);

                    if (arduboy.isFrameCount(2)) {
                        heart.data.loveHeart.counter++;
                    }

                    switch (heart.data.loveHeart.counter) {

                        case 0 ... 189:
                            break;

                        case 190 ... 193:
                        case 198 ... 201:
                            FX::drawBitmap(heart.x, heart.y, Images::Heart_02, 0, dbmNormal);
                            break;

                        case 194 ... 197:
                        case 202 ... 205:
                            FX::drawBitmap(heart.x, heart.y, Images::Heart_03, 0, dbmNormal);
                            break;

                        case 206:
                        case 208:
                            heart.y--;
                            FX::drawBitmap(heart.x, heart.y, Images::Heart_01, 0, dbmNormal);
                            break;

                        case 207:
                        case 209:
                            FX::drawBitmap(heart.x, heart.y, Images::Heart_01, 0, dbmNormal);
                            break;

                        case 210:
                        case 212:
                            heart.y--;
                            FX::drawBitmap(heart.x, heart.y, Images::Heart_00, 0, dbmNormal);
                            break;

                        case 211:
                        case 213:
                            FX::drawBitmap(heart.x, heart.y, Images::Heart_00, 0, dbmNormal);
                            break;


                    }
                    
                }

                break;

            case TitleScreenMode::IntroGame9:

                FX::drawBitmap(2, 64 - titleScreenVars.count, Images::IntroGame9, 0, dbmNormal);
                
                if (titleScreenVars.update(arduboy.isFrameCount(4))) {

                    gamePlay.gameState = GameState::Title_Init; 
                    titleScreenVars.count = 0;

                }

                break;

        #endif

        default: break;

    }

}
