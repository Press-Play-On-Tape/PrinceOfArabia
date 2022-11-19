#include <Arduboy2.h>

void title_Init() {

    gamePlay.gameState = GameState::Title;
    titleScreenVars.reset();


    // titleScreenVars.setMode(TitleScreenMode::CutScene_9, level);//SJH remove
    titleScreenVars.setMode(TitleScreenMode::CutScene_3, level);//SJH remove


}

void renderChamberBG() {

    FX::drawBitmap(0, 0, Images::Chambers_BG, 0, dbmNormal);
    FX::drawBitmap(10, 37, Images::Torch_00 + ((arduboy.getFrameCount(15) / 5) * 16), 0, dbmMasked);
    FX::drawBitmap(114, 37, Images::Torch_00 + ((arduboy.getFrameCount(15) / 5) * 16), 0, dbmMasked);

}

void renderChamberFG(uint8_t hourglassX = 0, uint8_t hourglassIdx = 0) {

    FX::drawBitmap(0, 0, Images::Chambers_FG, 0, dbmMasked);
    if (hourglassX > 0) FX::drawBitmap(hourglassX, 40, Images::HourGlass_00 + (hourglassIdx * 118), 0, dbmMasked);

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
                            titleScreenVars.setMode(TitleScreenMode::IntroGame_1A, level);
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
                    // titleScreenVars.count = 88;
                    break;

                case TitleScreenMode::IntroGame_1A:

                    titleScreenVars.setMode(TitleScreenMode::CutScene_1, level);
                    // titleScreenVars.count = 0;
                    fadeEffect.reset();
                    break;

                case TitleScreenMode::CutScene_1:

                    titleScreenVars.setMode(TitleScreenMode::IntroGame_1B, level);
                    // titleScreenVars.count = 0;
                    break;

                case TitleScreenMode::IntroGame_1B:

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

            case TitleScreenMode::IntroGame_1A:

                FX::drawBitmap(5, 64 - titleScreenVars.count, Images::IntroGame_1A, 0, dbmNormal);
                
                if (titleScreenVars.update(arduboy.isFrameCount(4))) {

                    titleScreenVars.setMode(TitleScreenMode::CutScene_1, level);
                    titleScreenVars.count = 0;
                    fadeEffect.reset();

                }

                break;

            case TitleScreenMode::CutScene_1:

                renderChamberBG();
                FX::drawBitmap(titleScreenVars.princess.x, 28, Images::Princess_00 + (titleScreenVars.princess.image * 260), 0, dbmMasked);
                FX::drawBitmap(titleScreenVars.zaffar.x, 28, Images::Zaffar_00 + (titleScreenVars.zaffar.image * 260), 0, dbmMasked);
                renderChamberFG(titleScreenVars.count >= 169 ? 54 : 0);

                if (titleScreenVars.update(arduboy.isFrameCount(3))) {

                    titleScreenVars.setMode(TitleScreenMode::IntroGame_1B, level);
                    titleScreenVars.count = 0;
                    fadeEffect.complete();


                }

                break;

            case TitleScreenMode::IntroGame_1B:

                FX::drawBitmap(2, 64 -titleScreenVars.count, Images::IntroGame_1B, 0, dbmNormal);
                
                if (titleScreenVars.update(arduboy.isFrameCount(4))) {

                    gamePlay.gameState = GameState::Game_Init; 
                    titleScreenVars.count = 0;

                }

                break;

            case TitleScreenMode::CutScene_2:

                renderChamberBG();

                if (arduboy.getFrameCountHalf(24)) {
                    FX::drawBitmap(titleScreenVars.princess.x, 28, Images::Princess_04, 0, dbmMasked);
                }
                else {
                    FX::drawBitmap(titleScreenVars.princess.x, 28, Images::Princess_09, 0, dbmMasked);
                }

                renderChamberFG(53, 1);
                

                if (titleScreenVars.update(arduboy.isFrameCount(3))) {

                    gamePlay.gameState = GameState::Game_Init; 
                    titleScreenVars.count = 0;
                    fadeEffect.reset();

                }

                break;

            case TitleScreenMode::CutScene_3:

                renderChamberBG();

                switch (titleScreenVars.count) {

                    case 0 ... 30:
                    case 37 ... 67:
                    case 74 ... 255:
                        FX::drawBitmap(52, 24, Images::Princess_10, 0, dbmMasked);
                        break;

                    case 31 ... 32:
                    case 35 ... 36:
                    case 68 ... 69:
                    case 72 ... 73:
                        FX::drawBitmap(52, 24, Images::Princess_24, 0, dbmMasked);
                        break;

                    case 33 ... 34:
                    case 70 ... 71:
                        FX::drawBitmap(52, 24, Images::Princess_25, 0, dbmMasked);
                        break;

                }

                renderChamberFG(53, 1);
                
                if (titleScreenVars.update(arduboy.isFrameCount(3))) {

                    gamePlay.gameState = GameState::Game_Init; 
                    titleScreenVars.count = 0;
                    fadeEffect.reset();

                }

                break;

            case TitleScreenMode::CutScene_9:
                {
                    uint24_t startPos = Images::Prince_Left_001 + ((static_cast<uint24_t>(titleScreenVars.prince.image) - 1) * static_cast<uint24_t>(364));

                    renderChamberBG();
                    FX::drawBitmap(titleScreenVars.prince.x, 29, startPos, 0, dbmMasked);
                    FX::drawBitmap(titleScreenVars.princess.x, 28, Images::Princess_00 + (titleScreenVars.princess.image * 260), 0, dbmMasked);
                    renderChamberFG();

                    if (titleScreenVars.update(arduboy.isFrameCount(4))) {

                        titleScreenVars.setMode(TitleScreenMode::IntroGame_9, level);
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

            case TitleScreenMode::IntroGame_9:

                FX::drawBitmap(2, 64 - titleScreenVars.count, Images::IntroGame_9, 0, dbmNormal);
                
                if (titleScreenVars.update(arduboy.isFrameCount(4))) {

                    gamePlay.gameState = GameState::Title_Init; 
                    titleScreenVars.count = 0;

                }

                break;

        #endif

        default: break;

    }

}
