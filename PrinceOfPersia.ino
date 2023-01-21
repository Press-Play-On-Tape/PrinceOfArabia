#include "src/utils/Arduboy2Ext.h"
#include "src/ArduboyTonesFX.h"
#include <ArduboyFX.h>  
#include "fxdata/Images.h"  

#include "src/utils/Constants.h"
#include "src/utils/Enums.h"
#include "src/utils/Stack.h"
#include "src/utils/FadeEffects.h"
#include "src/entities/Entities.h"
#include "src/fonts/Font3x5.h"
#include "src/utils/EEPROM_Utils.h"


#ifdef SAVE_MEMORY_USB
ARDUBOY_NO_USB
#endif

Arduboy2Ext arduboy;

#ifndef SAVE_MEMORY_SOUND
    uint16_t buffer[16]; 
    ArduboyTonesFX sound(arduboy.audio.enabled, buffer);
#endif

#if (defined(DEBUG) && defined(DEBUG_ONSCREEN_DETAILS)) or (defined(DEBUG) && defined(DEBUG_ONSCREEN_DETAILS_MIN))
    Font3x5 font3x5 = Font3x5();
#endif

Cookie cookie;
Stack <int16_t, Constants::StackSize> princeStack;
Prince &prince = cookie.prince;
Stack <int16_t, Constants::StackSize> enemyStack;
Mouse mouse;

#ifndef SAVE_MEMORY_ENEMY
Enemy &enemy = cookie.enemy;
#endif

Level &level = cookie.level;
GamePlay &gamePlay = cookie.gamePlay;
TitleScreenVars titleScreenVars;
MenuItem menu;

#ifndef SAVE_MEMORY_OTHER
    FadeEffects fadeEffect;
#endif

void setup() {

    arduboy.boot();
    FX::display(CLEAR_BUFFER);
    arduboy.systemButtons();

    #ifndef SAVE_MEMORY_SOUND
        arduboy.audio.begin();
    #endif

    arduboy.setFrameRate(Constants::FrameRate);

    FX::begin(FX_DATA_PAGE);

    prince.setStack(&princeStack);

    #ifndef SAVE_MEMORY_ENEMY
        enemy.setStack(&enemyStack);
    #endif

    #ifdef SAVE_MEMORY_OTHER
        gamePlay.gameState = GameState::Game_Init;
    #else
        gamePlay.gameState = GameState::SplashScreen_Init;
//        EEPROM_Utils::initEEPROM(cookie);
    #endif

}

void loop() {

    if (!arduboy.nextFrame()) return; 
    arduboy.pollButtons();

    #ifndef SAVE_MEMORY_SOUND
        sound.fillBufferFromFX();
    #endif

    switch (gamePlay.gameState) {

        #ifndef SAVE_MEMORY_OTHER
            
            case GameState::SplashScreen_Init:

                splashScreen_Init();
                [[fallthrough]];

            case GameState::SplashScreen:

                splashScreen();
                break;

            case GameState::Title_Init:

                #ifndef SAVE_MEMORY_SOUND
                    sound.tonesFromFX(Sounds::Theme);
                #endif

                #ifndef SAVE_MEMORY_OTHER
                    fadeEffect.complete();
                #endif

                gamePlay.gameState = GameState::Title;
                
                title_Init();
                [[fallthrough]];

            case GameState::Title:

                title();
                break;

        #endif

        case GameState::Game_Init:

            #ifndef SAVE_MEMORY_SOUND
                sound.noTone();
            #endif
            
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


    // Invert screen during play ?
    
    { 

        bool invert = false;
        
        switch (prince.getStance()) {

            case Stance::Pickup_Sword_3:
            case Stance::Pickup_Sword_5:
            case Stance::Drink_Tonic_Small_12:
            case Stance::Drink_Tonic_Small_14:
            case Stance::Drink_Tonic_Large_12:
            case Stance::Drink_Tonic_Large_14:
            case Stance::Drink_Tonic_Poison_12:
            case Stance::Drink_Tonic_Poison_14:
            case Stance::Drink_Tonic_Float_12:
            case Stance::Drink_Tonic_Float_14:
                invert = true;
                break;

        }    


        // Invert screen when striking player / enemy in sword fight ?
    
        Flash &flash = level.getFlash();
    
        if ((flash.frame == 2 || flash.frame == 4) && flash.type == FlashType::SwordFight) {
            invert = true;
        }
         
        if ((flash.frame == 2 || flash.frame == 4) && flash.type == FlashType::MirrorLevel12) {
            invert = true;
        }

        if (flash.frame == 1 && flash.type == FlashType::MirrorLevel12) {
            enemy.setStatus(Status::Dormant);
        }

        arduboy.invert(invert);

    }


    // Handle fade effects ..

    #ifndef SAVE_MEMORY_OTHER
    
        if (!fadeEffect.isComplete()) {

            fadeEffect.draw(arduboy);
            fadeEffect.update();

        }

    #endif

    FX::display(CLEAR_BUFFER);

}