#include "src/utils/Arduboy2Ext.h"
#include <ArduboyFX.h>  
#include "fxdata/Images.h"  
#include "fxdata/Levels.h"  

#include "src/utils/Constants.h"
#include "src/utils/Stack.h"
#include "src/utils/FadeEffects.h"
#include "src/entities/Entities.h"
#include "src/fonts/Font3x5.h"


#ifdef SAVE_MEMORY
ARDUBOY_NO_USB
#endif

Arduboy2Ext arduboy;

#ifdef SAVE_MEMORY
Font3x5 font3x5 = Font3x5();
#endif

Stack <int16_t, 30>  princeStack;
Prince prince;
Level level;
MenuItem menu;
GamePlay gamePlay;
TitleScreenVars titleScreenVars;
FadeInEffect fadeInEffect;


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
    gamePlay.gameState = GameState::SplashScreen_Init;

}

void loop() {

    if (!arduboy.nextFrame()) return; 
    arduboy.pollButtons();

    switch (gamePlay.gameState) {

        case GameState::SplashScreen_Init:

            splashScreen_Init();
            splashScreen();
            break;

        case GameState::SplashScreen:

            splashScreen();
            break;

        case GameState::Title_Init:

            gamePlay.gameState = GameState::Title;
            fadeInEffect.reset();
            title_Init();
            title();
            break;

        case GameState::Title:

            title();
            break;

        case GameState::Game_Init:

            fadeInEffect.reset();
            game_Init();
            game();
            break;

        case GameState::Game_StartLevel:

            fadeInEffect.reset();
            game_StartLevel();
            game();
            break;

        case GameState::Game:
        case GameState::Menu:

            game();
            break;

        case GameState::Game_Over:

            // todo
            break;

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

    arduboy.display(CLEAR_BUFFER);
    FX::disableOLED();

}