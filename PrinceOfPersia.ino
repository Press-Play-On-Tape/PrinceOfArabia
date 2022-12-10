#include "src/utils/Arduboy2Ext.h"
#include <ArduboyFX.h>  
#include "fxdata/Images.h"  
#include "fxdata/Levels.h"  

#include "src/utils/Constants.h"
#include "src/utils/Stack.h"
#include "src/utils/FadeEffects.h"
#include "src/entities/Entities.h"
#include "src/fonts/Font3x5.h"
#include "src/utils/EEPROM_Utils.h"


#ifdef SAVE_MEMORY_USB
ARDUBOY_NO_USB
#endif

Arduboy2Ext arduboy;

#if (defined(DEBUG) && defined(DEBUG_ONSCREEN_DETAILS)) or (defined(DEBUG) && defined(DEBUG_ONSCREEN_DETAILS_MIN))
    Font3x5 font3x5 = Font3x5();
#endif

Cookie cookie;
Stack <int16_t, Constants::StackSize> princeStack;
Prince &prince = cookie.prince;
Stack <int16_t, Constants::StackSize> enemyStack;
Enemy &enemy = cookie.enemy;
Level &level = cookie.level;
GamePlay &gamePlay = cookie.gamePlay;
TitleScreenVars titleScreenVars = cookie.titleScreenVars;
MenuItem menu;

#ifndef SAVE_MEMORY_OTHER
    FadeEffects fadeEffect;
#endif

void setup() {

    arduboy.boot();
    arduboy.display();
    arduboy.flashlight();
    arduboy.systemButtons();
    // arduboy.audio.begin();

    arduboy.setFrameRate(Constants::FrameRate);

    FX::disableOLED();
    FX::begin(FX_DATA_PAGE);

    prince.setStack(&princeStack);
    enemy.setStack(&enemyStack);

    #ifdef SAVE_MEMORY_OTHER
        gamePlay.gameState = GameState::Game_Init;
    #else
        gamePlay.gameState = GameState::SplashScreen_Init;
        EEPROM_Utils::initEEPROM(cookie);
    #endif

}

void loop() {

    if (!arduboy.nextFrame()) return; 
    arduboy.pollButtons();

    switch (gamePlay.gameState) {

        #ifndef SAVE_MEMORY_OTHER
            
            case GameState::SplashScreen_Init:

                splashScreen_Init();
                splashScreen();
                break;

            case GameState::SplashScreen:

                splashScreen();
                break;

            case GameState::Title_Init:

                gamePlay.gameState = GameState::Title;
                #ifndef SAVE_MEMORY_OTHER
                    fadeEffect.complete();
                #endif
                title_Init();
                title();
                break;

            case GameState::Title:

                title();
                break;

        #endif

        case GameState::Game_Init:

            #ifndef SAVE_MEMORY_OTHER
                fadeEffect.reset();
            #endif
            game_Init();
            game();
            break;

        case GameState::Game_StartLevel:

            #ifndef SAVE_MEMORY_OTHER
                fadeEffect.reset();
            #endif
            game_StartLevel();
            game();
            break;

        case GameState::Game:
        #ifndef SAVE_MEMORY_OTHER
        case GameState::Menu:
        #endif

            game();
            break;

        case GameState::Game_Over:

            // todo
            break;

        default: break;

    }


    FX::enableOLED();

    // Invert screen ?
    
    switch (prince.getStance()) {

        case Stance::Pickup_Sword_3:
        case Stance::Pickup_Sword_5:
            arduboy.invert(true);
            break;

        default:
            arduboy.invert(false);
            break;

    }    

    if (titleScreenVars.getMode() == TitleScreenMode::CutScene_1 && titleScreenVars.count == 168 && titleScreenVars.prevCount != 168) {

        arduboy.invert(true);
        
    }

    if (titleScreenVars.getMode() == TitleScreenMode::CutScene_1 && titleScreenVars.count == 171 && titleScreenVars.prevCount != 171) {

        arduboy.invert(true);
        
    }


    // Handle fade effects ..

    #ifndef SAVE_MEMORY_OTHER
    
        if (!fadeEffect.isComplete()) {

            fadeEffect.draw(arduboy);
            fadeEffect.update();

        }

    #endif

    arduboy.display(CLEAR_BUFFER);
    FX::disableOLED();

}