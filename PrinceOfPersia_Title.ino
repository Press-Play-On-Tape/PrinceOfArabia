#include <Arduboy2.h>
#include "PrinceOfPersia_Invader.h"

void title_Init() {

    gamePlay.gameState = GameState::Title;
    titleScreenVars.reset();

}




// ----------------------------------------------------------------------------
//  Handle state updates .. 
//
void title() { 

    auto justPressed = arduboy.justPressedButtons();

    #ifdef DEBUG_CUT_SCENES

        if (justPressed & B_BUTTON && titleScreenVars.getMode() != TitleScreenMode::CutScene_7_PlayGame) {

            //setRenderChamberBG();
            titleScreenVars.setMode(TitleScreenMode::CutScene_7_Transition);

            Invader_General &general = level.getItem(Constants::Invaders_General).data.invader_General;
            general.y = 0;

            //FX::setFrame(Title_IntroGame_End_Frame, 4 - 1);
        }

    #endif

    if (titleScreenVars.getMode() == TitleScreenMode::Main) {

        #ifdef DEBUG_LEVELS

            auto pressed = arduboy.pressedButtons();

            if ((justPressed & UP_BUTTON) && (pressed & A_BUTTON) && (startLevel < 27)) {

                startLevel++;

            }

            if ((justPressed & DOWN_BUTTON) && (pressed & A_BUTTON) && (startLevel > 1)) {

                startLevel--;

            }

        #endif


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

                            prince.setHealth(3);
                            prince.setHealthMax(3);

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

            #ifndef SAVE_MEMORY_INVADER

                case TitleScreenMode::CutScene_7_Transition:
                case TitleScreenMode::CutScene_7_PlayGame:

                    titleScreenVars.setMode(TitleScreenMode::CutScene_7_PlayGame);
                    gamePlay.gameState = GameState::Game_StartLevel; 
                    arduboy.setFrameRate(Constants::FrameRate);
                    break;

            #endif

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

            #ifdef DEBUG_LEVELS

                FX::drawBitmap(116, 0, Images::LevelRect, 0, dbmNormal);
                renderNumber_Upright(118, 2, startLevel);

            #endif

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

                    #ifndef SAVE_MEMORY_SOUND
                        sound.tonesFromFX(Sounds::Ending);
                    #endif

                }

                break;

            case TitleScreenMode::IntroGame_End:

                if (!FX::drawFrame()) {

                    gamePlay.gameState = GameState::Title_Init; 

                }

                break;

            #ifndef SAVE_MEMORY_INVADER

                case TitleScreenMode::CutScene_7_Transition:

                    if (!FX::drawFrame()) {

                        level.loadItems(0, prince);
                        titleScreenVars.setMode(TitleScreenMode::CutScene_7_PlayGame);
                        arduboy.frameCount = 5;
                        arduboy.setFrameRate(60);

                    }

                    break;

                case TitleScreenMode::CutScene_7_PlayGame:
                    
                    invader_PlayGame();
                    break;          

            #endif      

        #endif

        default: break;

    }

}
