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

    #ifdef DEBUG_CUT_SCENES

        if (justPressed & B_BUTTON) {

            setRenderChamberBG();
            titleScreenVars.setMode(TitleScreenMode::CutScene_End);
            //FX::setFrame(Title_IntroGame_9_Frame, 4 - 1);
        }

    #endif

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

    #ifdef DEBUG_CUT_SCENES
    if (justPressed & (A_BUTTON)) {
    #else
    if (justPressed & (A_BUTTON | B_BUTTON)) {
    #endif
    
        switch (titleScreenVars.getMode()) {

        case TitleScreenMode::Main:

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

                        titleScreenVars.setMode(TitleScreenMode::IntroGame_1A);
                        FX::setFrame(Title_IntroGame_1A_Frame, 4 - 1);

                        break;

                    case TitleScreenOptions::Credits:

                        titleScreenVars.setMode(TitleScreenMode::Credits);
                        FX::setFrame(Title_Credits_Frame, 5 - 1);

                        break;

                    case TitleScreenOptions::High:

                        titleScreenVars.setMode(TitleScreenMode::High);
                        FX::setFrame(Title_High_Frame, 5 - 1);
                        break;

                #endif

                default: break;

            }

            break;

        #ifndef SAVE_MEMORY_OTHER

            case TitleScreenMode::Credits:
            case TitleScreenMode::High:
            case TitleScreenMode::TimeOut:

                #ifdef DEBUG_CUT_SCENES
                if (justPressed & (A_BUTTON)) {
                #else
                if (justPressed & (A_BUTTON | B_BUTTON)) {
                #endif

                    titleScreenVars.setMode(TitleScreenMode::Main);

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

                #ifndef SAVE_MEMORY_SOUND
                    sound.tonesFromFX(Sounds::Seque);
                #endif

                titleScreenVars.setMode(TitleScreenMode::IntroGame_1B);
                gamePlay.gameState = GameState::Game_Init; 
                //fadeEffect.reset();

                break;

            case TitleScreenMode::CutScene_1:

                titleScreenVars.setMode(TitleScreenMode::IntroGame_1B);
                gamePlay.gameState = GameState::Game_Init; 
                //fadeEffect.reset();

                break;

            case TitleScreenMode::IntroGame_1B:

                gamePlay.gameState = GameState::Game_Init; 
                break;

            case TitleScreenMode::CutScene_2:
            case TitleScreenMode::CutScene_3:
            case TitleScreenMode::CutScene_4:
            case TitleScreenMode::CutScene_5:
            case TitleScreenMode::CutScene_6:

                gamePlay.gameState = GameState::Game_StartLevel; 
                break;

            case TitleScreenMode::CutScene_End:

                gamePlay.gameState = GameState::Title_Init; 
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
                    
                    titleScreenVars.setMode(TitleScreenMode::Main);

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
            case TitleScreenMode::TimeOut:

                FX::drawFrame();
                break;
            
            case TitleScreenMode::High:
                
                FX::drawFrame();
                FX::drawBitmap(38, 40, Images::Numbers_Large, cookie.highMin, dbmNormal);
                FX::drawBitmap(68, 40, Images::Numbers_Large, cookie.highSec, dbmNormal);

                break;

            case TitleScreenMode::IntroGame_1A:

                if (!FX::drawFrame()) {

                    titleScreenVars.setMode(TitleScreenMode::CutScene_1);
                    FX::setFrame(Title_CutScene_1_Frame, 3 - 1);

                }

                break;

            case TitleScreenMode::CutScene_1:

                if (!FX::drawFrame()) {

                    titleScreenVars.setMode(TitleScreenMode::IntroGame_1B);
                    FX::setFrame(Title_IntroGame_1B_Frame, 4 - 1);

                }

                break;

            case TitleScreenMode::IntroGame_1B:

                if (!FX::drawFrame()) {

                    gamePlay.gameState = GameState::Game_Init; 

                }

                break;

            case TitleScreenMode::CutScene_2:
            case TitleScreenMode::CutScene_3:
            case TitleScreenMode::CutScene_4:
            case TitleScreenMode::CutScene_5:
            case TitleScreenMode::CutScene_6:

                if (!FX::drawFrame()) {

                    gamePlay.gameState = GameState::Game_StartLevel; 

                }

                break;

            case TitleScreenMode::CutScene_End:
                
                if (!FX::drawFrame()) {

                    titleScreenVars.setMode(TitleScreenMode::IntroGame_End);
                    FX::setFrame(Title_IntroGame_End_Frame, 5 - 1);

                }

                break;

            case TitleScreenMode::IntroGame_End:

                if (!FX::drawFrame()) {

                    gamePlay.gameState = GameState::Title_Init; 

                }

                break;

        #endif

        default: break;

    }

}
