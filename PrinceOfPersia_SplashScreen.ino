#include <Arduboy2.h>


// ----------------------------------------------------------------------------
//  Initialise state ..
//
void splashScreen_Init() {

    gamePlay.gameState = GameState::SplashScreen;
    FX::setFrame(splashScreen_Frame, 12-1);
}


// ----------------------------------------------------------------------------
//  Handle state updates .. 
//
void splashScreen() { 

    auto justPressed = arduboy.justPressedButtons();

    if (justPressed > 0) {
        
        gamePlay.gameState = GameState::Title_Init; 

    }

    FX::drawFrame();
}
