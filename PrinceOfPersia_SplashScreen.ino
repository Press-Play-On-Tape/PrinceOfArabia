#include <Arduboy2.h>


// ----------------------------------------------------------------------------
//  Initialise state ..
//
void splashScreen_Init() {

    gameState = GameState::SplashScreen;

}


// ----------------------------------------------------------------------------
//  Handle state updates .. 
//
void splashScreen() { 

    auto justPressed = arduboy.justPressedButtons();

    if (justPressed > 0) {
        
        gameState = GameState::Title_Init; 

    }

    FX::drawBitmap(32, 16, Images::PPOT[arduboy.getFrameCount(48) / 12], 0, dbmWhite);

}
