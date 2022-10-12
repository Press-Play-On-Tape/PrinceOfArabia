#include "src/utils/Arduboy2Ext.h"
#include <ArduboyFX.h>  
#include "fxdata/Images.h"  
#include "fxdata/Levels.h"  

#include "src/utils/Constants.h"
#include "src/utils/Stack.h"
#include "src/entities/Entities.h"
#include "src/fonts/Font3x5.h"


// int16_t playerXLoc = 10;
// uint8_t playerYLoc = 26;

Arduboy2Ext arduboy;
Font3x5 font3x5 = Font3x5();

Stack <int16_t, 30>  princeStack;
Prince prince;
Level level;
GameState gameState = GameState::SplashScreen_Init;


void setup() {

    arduboy.begin();
    arduboy.setFrameRate(30);

    FX::disableOLED();
    FX::begin(FX_DATA_PAGE);

    prince.setStack(&princeStack);

}

void loop() {

    if (!arduboy.nextFrame()) return; 
    arduboy.pollButtons();

    switch (gameState) {

        case GameState::SplashScreen_Init:

            splashScreen_Init();
            splashScreen();
            break;

        case GameState::SplashScreen:

            splashScreen();
            break;

        case GameState::Title_Init:

            gameState = GameState::Title;
            title_Init();
            title();
            break;

        case GameState::Title:

            title();
            break;

        case GameState::Game_Init:

            game_Init();
            game();
            break;

        case GameState::Game:

            game();
            break;

    }


    FX::enableOLED();
    arduboy.display(CLEAR_BUFFER);
    FX::disableOLED();

}