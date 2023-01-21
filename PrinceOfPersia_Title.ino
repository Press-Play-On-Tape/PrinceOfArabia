#include <Arduboy2.h>

void title_Init() {

    gamePlay.gameState = GameState::Title;
    titleScreenVars.reset();

}

void setRenderChamberBG() {

    FX::setFrame(Chambers_BG_frame, 5 - 1);

}

void renderChamberBG() {

    FX::drawFrame();

}

void renderChamberFG(uint8_t hourglassX = 0, uint8_t hourglassIdx = 0) {

    FX::drawFrame(Chambers_FG_frame);
    if (hourglassX > 0) FX::drawBitmap(hourglassX, 40, Images::HourGlasses, hourglassIdx, dbmMasked);

}


// ----------------------------------------------------------------------------
//  Handle state updates .. 
//
void title() { 

    auto justPressed = arduboy.justPressedButtons();

    if (titleScreenVars.getMode() == TitleScreenMode::Main) {

        if (justPressed & LEFT_BUTTON) {

            if (titleScreenVars.option != TitleScreenOptions::Play) {
                titleScreenVars.option = static_cast<TitleScreenOptions>(static_cast<uint8_t>(titleScreenVars.option) - 1);
            }

        }

        if (justPressed & RIGHT_BUTTON) {

        #ifndef SAVE_MEMORY_TITLE

            if ((titleScreenVars.option == TitleScreenOptions::Play) || cookie.hasSavedScore) {

                titleScreenVars.option = static_cast<TitleScreenOptions>(static_cast<uint8_t>(titleScreenVars.option) + 1);
            }

        #else

            if ((titleScreenVars.option != TitleScreenOptions::High)) {

                titleScreenVars.option = static_cast<TitleScreenOptions>(static_cast<uint8_t>(titleScreenVars.option) + 1);
            }

        #endif

        }
    }

    if (justPressed & (A_BUTTON | B_BUTTON)) {

        switch (titleScreenVars.getMode()) {

        case TitleScreenMode::Main:

            {

                switch (titleScreenVars.option) {

                    #ifdef SAVE_MEMORY_OTHER
                        case TitleScreenOptions::Play:

                            gamePlay.gameState = GameState::Game_Init;

                            break;

                    #else

                        case TitleScreenOptions::Play:

                            #ifndef SAVE_MEMORY_SOUND
                                sound.tonesFromFX(Sounds::Seque);
                            #endif

                            titleScreenVars.setMode(TitleScreenMode::IntroGame_1A, level);
                            FX::setFrame(Title_IntroGame_1A_Frame, 4 - 1);

                            break;

                        case TitleScreenOptions::Credits:

                            titleScreenVars.setMode(TitleScreenMode::Credits, level);
                            FX::setFrame(Title_Credits_Frame, 5 - 1);

                            break;

                        case TitleScreenOptions::High:

                            titleScreenVars.setMode(TitleScreenMode::High, level);
                            FX::setFrame(Title_High_Frame, 5 - 1);
                            break;

                    #endif

                    default: break;

                }
            }

            break;

        #ifndef SAVE_MEMORY_OTHER

            case TitleScreenMode::Credits:
            case TitleScreenMode::High:

                {

                    titleScreenVars.setMode(TitleScreenMode::Main, level);

                    #ifndef SAVE_MEMORY_TITLE

                        if (cookie.hasSavedScore) {
                            FX::setFrame(Title_Main_Frame_WithHigh, 2 - 1);
                        }
                        else {
                            FX::setFrame(Title_Main_Frame_NoHigh, 2 - 1);
                        }

                    #else

                        FX::setFrame(Title_Main_Frame_WithHigh, 2 - 1);

                    #endif

                }

                break;

            case TitleScreenMode::IntroGame_1A:

                {

                    #ifndef SAVE_MEMORY_SOUND
                        sound.tonesFromFX(Sounds::Seque);
                    #endif

                    titleScreenVars.setMode(TitleScreenMode::IntroGame_1B, level);
                    gamePlay.gameState = GameState::Game_Init; 
                    fadeEffect.reset();
                }

                break;

            case TitleScreenMode::CutScene_1:

                {
                    titleScreenVars.setMode(TitleScreenMode::IntroGame_1B, level);
                    gamePlay.gameState = GameState::Game_Init; 
                    fadeEffect.reset();
                }

                break;

            case TitleScreenMode::IntroGame_1B:

                {
                    gamePlay.gameState = GameState::Game_Init; 
                }

                break;

            case TitleScreenMode::CutScene_2:
            case TitleScreenMode::CutScene_3:
            case TitleScreenMode::CutScene_4:
            case TitleScreenMode::CutScene_5:

                {
                    gamePlay.gameState = GameState::Game_StartLevel; 
                }

                break;

            case TitleScreenMode::CutScene_9:

                {
                    gamePlay.gameState = GameState::Title_Init; 
                }

                break;

        #endif

        default: break;

    }
    }



    // Render ..

    switch (titleScreenVars.getMode()) {

        case TitleScreenMode::Intro:

            if (!FX::drawFrame()) {

                #ifndef SAVE_MEMORY_TITLE

                    if (cookie.hasSavedScore) {
                        FX::setFrame(Title_Intro_Last_Frame_WithHigh, 2 - 1);
                    }
                    else {
                        FX::setFrame(Title_Intro_Last_Frame_NoHigh, 2 - 1);
                    }

                #else

                    FX::setFrame(Title_Intro_Last_Frame_WithHigh, 2 - 1);

                #endif

                if (justPressed) {
                    
                    titleScreenVars.setMode(TitleScreenMode::Main, level);

                    #ifndef SAVE_MEMORY_TITLE

                        if (cookie.hasSavedScore) {
                            FX::setFrame(Title_Main_Frame_WithHigh, 2 - 1);
                        }
                        else {
                            FX::setFrame(Title_Main_Frame_NoHigh, 2 - 1);
                        }

                    #else

                        FX::setFrame(Title_Main_Frame_WithHigh, 2 - 1);

                    #endif

                }

            }
            break;

        case TitleScreenMode::Main:

            if (!FX::drawFrame()) {

                switch (titleScreenVars.option) {

                    case TitleScreenOptions::Play:

                        #ifndef SAVE_MEMORY_TITLE                        

                            if (cookie.hasSavedScore) {
                                FX::setFrame(Title_Main_Game_Frame_WithHigh, 2 - 1);
                            }
                            else {
                                FX::setFrame(Title_Main_Game_Frame_NoHigh, 2 - 1);
                            }

                        #else

                            FX::setFrame(Title_Main_Game_Frame_WithHigh, 2 - 1);

                        #endif

                        break;

                    case TitleScreenOptions::Credits:

                        #ifndef SAVE_MEMORY_TITLE                        

                            if (cookie.hasSavedScore) {
                                FX::setFrame(Title_Main_Credits_Frame_WithHigh, 2 - 1);
                            }
                            else {
                                FX::setFrame(Title_Main_Credits_Frame_NoHigh, 2 - 1);
                            }

                        #else

                            FX::setFrame(Title_Main_Credits_Frame_WithHigh, 2 - 1);

                        #endif

                        break;

                    case TitleScreenOptions::High:

                        FX::setFrame(Title_Main_High_Frame_WithHigh, 2 - 1);
                        break;
                        
                }

            }

            break;

        #ifndef SAVE_MEMORY_OTHER
            
            case TitleScreenMode::Credits:

                FX::drawFrame();

                break;
            
            case TitleScreenMode::High:
                
                //FX::drawBitmap(0, 0, Images::Title_PoP, 0, dbmMasked);
                //FX::drawBitmap(38, 32, Images::HighScore, 0, dbmNormal);
                FX::drawFrame();
                FX::drawBitmap(38, 40, Images::Numbers_Large, cookie.highMin, dbmNormal);
                //FX::drawBitmap(62, 42, Images::Numbers_Divider, 0, dbmNormal);
                FX::drawBitmap(68, 40, Images::Numbers_Large, cookie.highSec, dbmNormal);

                //renderTorches(10, 114, 40);

                break;

            case TitleScreenMode::IntroGame_1A:

                if (!FX::drawFrame()) {

                    titleScreenVars.setMode(TitleScreenMode::CutScene_1, level);
                    FX::setFrame(Title_CutScene_1_Frame, 3 - 1);

                }

                break;

            case TitleScreenMode::CutScene_1:

                if (!FX::drawFrame()) {

                    titleScreenVars.setMode(TitleScreenMode::IntroGame_1B, level);
                    FX::setFrame(Title_IntroGame_1B_Frame, 4 - 1);

                }

                break;

            case TitleScreenMode::IntroGame_1B:

                if (!FX::drawFrame()) {

                    gamePlay.gameState = GameState::Game_Init; 

                }

                break;

            case TitleScreenMode::CutScene_2:

                renderChamberBG();

                if (arduboy.getFrameCountHalf(24)) {
                    FX::drawBitmap(titleScreenVars.princess.x, 28, Images::Princess, 4, dbmMasked);
                }
                else {
                    FX::drawBitmap(titleScreenVars.princess.x, 28, Images::Princess, 9, dbmMasked);
                }

                renderChamberFG(53, 1);
                

                if (titleScreenVars.update(arduboy.isFrameCount(3))) {

                    gamePlay.gameState = GameState::Game_StartLevel; 
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
                        FX::drawBitmap(52, 24, Images::Princess, 10, dbmMasked);
                        break;

                    case 31 ... 32:
                    case 35 ... 36:
                    case 68 ... 69:
                    case 72 ... 73:
                        FX::drawBitmap(52, 24, Images::Princess, 24, dbmMasked);
                        break;

                    case 33 ... 34:
                    case 70 ... 71:
                        FX::drawBitmap(52, 24, Images::Princess, 25, dbmMasked);
                        break;

                }

                renderChamberFG(53, 1);
                
                if (titleScreenVars.update(arduboy.isFrameCount(3))) {

                    gamePlay.gameState = GameState::Game_StartLevel; 
                    titleScreenVars.count = 0;
                    fadeEffect.reset();

                }

                break;

            case TitleScreenMode::CutScene_4:

                renderChamberBG();
                FX::drawBitmap(titleScreenVars.princess.x, 28, Images::Princess, 26 + (titleScreenVars.count % 7), dbmMasked);
                renderChamberFG(54);

                if (titleScreenVars.update(arduboy.isFrameCount(12))) {

                    gamePlay.gameState = GameState::Game_StartLevel; 
                    titleScreenVars.count = 0;
                    fadeEffect.reset();

                }

                break;

            case TitleScreenMode::CutScene_5:

                renderChamberBG();
                FX::drawBitmap(titleScreenVars.princess.x, 28, Images::Princess_Bounce, (titleScreenVars.count % 16), dbmMasked);
                renderChamberFG(63, 1);
                
                if (titleScreenVars.update(arduboy.isFrameCount(3))) {

                    gamePlay.gameState = GameState::Game_StartLevel; 
                    titleScreenVars.count = 0;
                    fadeEffect.reset();

                }

                break;

            case TitleScreenMode::CutScene_9:
                {

                    renderChamberBG();
                    FX::drawBitmap(titleScreenVars.prince.x, 29, Images::Prince_Left, titleScreenVars.prince.image - 1, dbmMasked);
                    FX::drawBitmap(titleScreenVars.princess.x, 28, Images::Princess, titleScreenVars.princess.image, dbmMasked);
                    renderChamberFG();

                    if (titleScreenVars.update(arduboy.isFrameCount(4))) {

                        titleScreenVars.setMode(TitleScreenMode::IntroGame_9, level);
                        titleScreenVars.count = 0;

                    }

                    Item &heart = level.getItem(Constants::Item_LoveHeart);

                    if (arduboy.isFrameCount(2)) {
                        heart.data.loveHeart.counter++;
                    }

                    uint8_t imageIdx = 255;

                    switch (heart.data.loveHeart.counter) {

                        case 0 ... 189:
                            break;

                        case 190 ... 193:
                        case 198 ... 201:
                            imageIdx = 2;
                            break;

                        case 194 ... 197:
                        case 202 ... 205:
                            imageIdx = 3;
                            break;

                        case 206:
                        case 208:
                            heart.y--;
                            imageIdx = 1;
                            break;

                        case 207:
                        case 209:
                            imageIdx = 1;
                            break;

                        case 210:
                        case 212:
                            heart.y--;
                            imageIdx = 0;
                            break;

                        case 211:
                        case 213:
                            imageIdx = 0;
                            break;


                    }

                    if (imageIdx != 255) {

                        FX::drawBitmap(heart.x, heart.y, Images::Hearts, imageIdx, dbmNormal);
                        
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
