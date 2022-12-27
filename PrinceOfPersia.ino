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
    arduboy.systemButtons();

    #ifndef SAVE_MEMORY_SOUND
        arduboy.audio.begin();
    #endif

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

    #ifndef SAVE_MEMORY_SOUND
        sound.fillBufferFromFX();
    #endif

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

                #ifndef SAVE_MEMORY_SOUND
                    sound.tonesFromFX(Sounds::Theme);
                #endif

                #ifndef SAVE_MEMORY_OTHER
                    fadeEffect.complete();
                #endif

                gamePlay.gameState = GameState::Title;
                
                title_Init();
                title();
                break;

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
    
    switch (prince.getStance()) {

        case Stance::Pickup_Sword_3:
        case Stance::Pickup_Sword_5:
        case Stance::Drink_Tonic_Small_12:
        case Stance::Drink_Tonic_Small_14:
        case Stance::Drink_Tonic_Large_12:
        case Stance::Drink_Tonic_Large_14:
            arduboy.invert(true);
            break;

        case Stance::Drink_Tonic_Poison_12:
        case Stance::Drink_Tonic_Poison_14:
            arduboy.invert(true);
            break;

        default:
            arduboy.invert(false);
            break;

    }    


    // Invert screen when striking player / enemy in sword fight ?
    
    {
        Flash &flash = level.getFlash();
    
        if ((flash.frame == 2 || flash.frame == 4) && flash.type == FlashType::SwordFight) {

            arduboy.invert(true);

        }
    
    }


    // Invert screen during sequence ?

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