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
    auto pressed = arduboy.pressedButtons();

    #ifdef DEBUG_CUT_SCENES

        if (justPressed & B_BUTTON) {

            //setRenderChamberBG();
            titleScreenVars.setMode(TitleScreenMode::CutScene_7_RemoveArches);

            Invader_General &general = level.getItem(Constants::Invaders_General).data.invader_General;
            general.y = 0;

            //FX::setFrame(Title_IntroGame_End_Frame, 4 - 1);
        }

    #endif

    if (titleScreenVars.getMode() == TitleScreenMode::Main) {

        #ifdef DEBUG_LEVELS

            auto pressed = arduboy.pressedButtons();

            if ((justPressed & UP_BUTTON) && (pressed & A_BUTTON) && (startLevel < 13)) {

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

                }

                break;

            case TitleScreenMode::IntroGame_End:

                if (!FX::drawFrame()) {

                    gamePlay.gameState = GameState::Title_Init; 

                }

                break;

            case TitleScreenMode::CutScene_7_RemoveArches:
                {
                    Invader_General &general = level.getItem(Constants::Invaders_General).data.invader_General;
                  
                    uint8_t topY = (general.y > 20 ? general.y - 20  : 0);
                    uint8_t botY = (general.y > 25 ? (general.y - 25) / 4 : 0);

                    FX::drawBitmap(0, 0 - topY, Images::Chambers_BG_01, 0, dbmNormal);
                    FX::drawBitmap(0, 55 + botY, Images::Chambers_BG_02, 0, dbmNormal);
                    FX::drawBitmap(0, 0 - topY, Images::Chambers_FG, 0, dbmMasked);
                    

                    // Increment counter and see if we should progress to the next phase ..

                    general.y = general.y + 1;

                    if (general.y == 90) {

                        level.loadItems(0, prince);
                        titleScreenVars.setMode(TitleScreenMode::CutScene_7_EnterPlayers);

                    }

                }

                break;

            case TitleScreenMode::CutScene_7_EnterPlayers:
                {
                    Invader_General &general = level.getItem(Constants::Invaders_General).data.invader_General;
                    Invader_Player &player = level.getItem(Constants::Invaders_Player).data.invader_Player;
                  
                    uint8_t y = (general.y ? general.y / 2 : 0);

                    invader_RenderEnemies(-36 + y);
                    invader_RenderBarriers(36 - y);
                    invader_RenderPlayer(player, 36 - y, true);


                    // Increment counter and see if we should progress to the next phase ..

                    general.y = general.y + 1;

                    if (general.y == 36 * 2) {

                        titleScreenVars.setMode(TitleScreenMode::CutScene_7_PlayGame);

                    }

                    FX::drawBitmap(120 + (36/4) - (general.y / 8), 0, Images::HUD_Backgrounds, 2, dbmNormal);


                }

                break;

            case TitleScreenMode::CutScene_7_PlayGame:
                
                invader_PlayGame();
                break;                

        #endif

        default: break;

    }

}
