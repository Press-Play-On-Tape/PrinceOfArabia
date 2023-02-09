#include <Arduboy2.h>

void title_Init() {

    gamePlay.gameState = GameState::Title;
    titleScreenVars.reset();

}


void invader_RenderEnemies(int yOffset = 0) {

    for (uint8_t x = Constants::Invaders_Enemy_Row_1_Start; x <= Constants::Invaders_Enemy_Row_3_End; x++) {

        uint8_t image = ((x - 1) / 7) * 2;
        uint8_t frame = arduboy.getFrameCountHalf(80);

        Item &enemy = level.getItem(x);
        FX::drawBitmap(enemy.data.invader_Enemy.x, enemy.data.invader_Enemy.y + yOffset, Images::Invaders, image + (x % 2 == 0 ? frame : !frame), dbmMasked);

    }

}

void invader_RenderBarriers(int yOffset = 0) {

    for (uint8_t x = Constants::Invaders_Barrier_Start; x <= Constants::Invaders_Barrier_End; x++) {

        Item &barrier = level.getItem(x);
        FX::drawBitmap(barrier.data.invader_Barrier.x, barrier.data.invader_Barrier.y + yOffset, Images::Barriers, 0, dbmMasked);

    }

}

void invader_RenderPlayer(int yOffset = 0) {

    Item &player = level.getItem(Constants::Invaders_Player);
    FX::drawBitmap(player.data.invader_Player.x, player.data.invader_Player.y + yOffset, Images::Player, 0, dbmMasked);
    
}

void invader_RenderPlayerBullet() {

    Item &bullet = level.getItem(Constants::Invaders_Player_Bullet);
    FX::drawBitmap(bullet.data.invader_Player_Bullet.x, bullet.data.invader_Player_Bullet.y, Images::Bullet, 0, dbmNormal);
    
}

void invader_MoveInvaders_Left(uint8_t startPos, uint8_t endPos) {
    
    for (uint8_t x = startPos; x <= endPos; x++) {

        Item &enemy = level.getItem(x);
        enemy.data.invader_Enemy.x--;

        if (startPos == 1 && enemy.data.invader_Enemy.x == 5) {

            Item &item = level.getItem(Constants::Invaders_General);
            item.data.invader_General.direction = Direction::Right;

            for (uint8_t x = Constants::Invaders_Enemy_Row_1_Start; x <= Constants::Invaders_Enemy_Row_3_End; x++) {

                Item &enemy2 = level.getItem(x);
                enemy2.data.invader_Enemy.y++;

            }

        }

    }

}

void invader_MoveInvaders_Right(uint8_t startPos, uint8_t endPos) {
    
    for (uint8_t x = startPos; x <= endPos; x++) {

        Item &enemy = level.getItem(x);
        enemy.data.invader_Enemy.x++;

        if (startPos == 1 && enemy.data.invader_Enemy.x == 103) {

            Item &item = level.getItem(Constants::Invaders_General);
            item.data.invader_General.direction = Direction::Left;

            for (uint8_t x = Constants::Invaders_Enemy_Row_1_Start; x <= Constants::Invaders_Enemy_Row_3_End; x++) {

                Item &enemy2 = level.getItem(x);
                enemy2.data.invader_Enemy.y++;

            }
            
        }

    }

}

void invader_MoveInvaders() {

    Item &item = level.getItem(0);

    uint8_t frameCount = arduboy.getFrameCount(22);


    switch (item.data.invader_General.direction) {

        case Direction::Left:

            switch (frameCount) {

                case 0:

                    invader_MoveInvaders_Left(Constants::Invaders_Enemy_Row_1_Start, Constants::Invaders_Enemy_Row_1_End);
                    break;

                case 3:
                    {   
                        Item &enemy = level.getItem(Constants::Invaders_Enemy_Row_1_End);
                        if (enemy.data.invader_Enemy.x == 103) {
                            invader_MoveInvaders_Right(Constants::Invaders_Enemy_Row_2_Start, Constants::Invaders_Enemy_Row_2_End);
                        }
                        else {
                            invader_MoveInvaders_Left(Constants::Invaders_Enemy_Row_2_Start, Constants::Invaders_Enemy_Row_2_End);
                        }

                    }

                    break;

                case 6:
                    {   
                        Item &enemy = level.getItem(Constants::Invaders_Enemy_Row_1_End);

                        if (enemy.data.invader_Enemy.x == 103) {
                            invader_MoveInvaders_Right(Constants::Invaders_Enemy_Row_3_Start, Constants::Invaders_Enemy_Row_3_End);
                        }
                        else {
                            invader_MoveInvaders_Left(Constants::Invaders_Enemy_Row_3_Start, Constants::Invaders_Enemy_Row_3_End);
                        }

                    }
                    break;

            }

            break;

        case Direction::Right:

            switch (frameCount) {

                case 0:

                    invader_MoveInvaders_Right(1, 7);
                    break;

                case 3:
                    {   
                        Item &enemy = level.getItem(Constants::Invaders_Enemy_Row_1_Start);

                        if (enemy.data.invader_Enemy.x == 5) {
                            invader_MoveInvaders_Left(Constants::Invaders_Enemy_Row_2_Start, Constants::Invaders_Enemy_Row_2_End);
                        }
                        else {
                            invader_MoveInvaders_Right(Constants::Invaders_Enemy_Row_2_Start, Constants::Invaders_Enemy_Row_2_End);
                        }

                    }

                    break;

                case 6:
                    {   
                        Item &enemy = level.getItem(Constants::Invaders_Enemy_Row_1_Start);

                        if (enemy.data.invader_Enemy.x == 5) {
                            invader_MoveInvaders_Left(Constants::Invaders_Enemy_Row_3_Start, Constants::Invaders_Enemy_Row_3_End);
                        }
                        else {
                            invader_MoveInvaders_Right(Constants::Invaders_Enemy_Row_3_Start, Constants::Invaders_Enemy_Row_3_End);
                        }

                    }
                    break;

            }

            break;


    }

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

            Item &item = level.getItem(0);
            item.data.invader_General.y = 0;

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
                    Item &item = level.getItem(0);
                  
                    uint8_t topY = (item.data.invader_General.y > 20 ? item.data.invader_General.y - 20  : 0);
                    uint8_t botY = (item.data.invader_General.y > 25 ? (item.data.invader_General.y - 25) / 4 : 0);

                    FX::drawBitmap(0, 0 - topY, Images::Chambers_BG_01, 0, dbmNormal);
                    FX::drawBitmap(0, 55 + botY, Images::Chambers_BG_02, 0, dbmNormal);
                    FX::drawBitmap(0, 0 - topY, Images::Chambers_FG, 0, dbmMasked);
                    

                    // Increment counter and see if we should progress to the next phase ..

                    item.data.invader_General.y = item.data.invader_General.y + 1;

                    if (item.data.invader_General.y == 90) {

                        level.loadItems(0, prince);
                        titleScreenVars.setMode(TitleScreenMode::CutScene_7_EnterPlayers);

                    }

                }

                break;

            case TitleScreenMode::CutScene_7_EnterPlayers:
                {
                    Item &item = level.getItem(0);
                  
                    uint8_t y = (item.data.invader_General.y ? item.data.invader_General.y / 2 : 0);

                    invader_RenderEnemies(-36 + y);
                    invader_RenderBarriers(36 - y);
                    invader_RenderPlayer(36 - y);


                    // Increment counter and see if we should progress to the next phase ..

                    item.data.invader_General.y = item.data.invader_General.y + 1;

                    if (item.data.invader_General.y == 36 * 2) {

                        titleScreenVars.setMode(TitleScreenMode::CutScene_7_PlayGame);

                    }


                    FX::drawBitmap(120 + (36/4) - (item.data.invader_General.y / 8), 0, Images::HUD_Backgrounds, 2, dbmNormal);



                }

                break;

            case TitleScreenMode::CutScene_7_PlayGame:
                {

                    FX::drawBitmap(120, 0, Images::HUD_Backgrounds, 2, dbmNormal);

                    Item &player = level.getItem(Constants::Invaders_Player);
                    Item &bullet = level.getItem(Constants::Invaders_Player_Bullet);

                    if (pressed & LEFT_BUTTON && player.data.invader_Player.x > 4) {
                        player.data.invader_Player.x--;
                    }

                    if (pressed & RIGHT_BUTTON && player.data.invader_Player.x < 104) {
                        player.data.invader_Player.x++;
                    }

                    if (pressed & A_BUTTON) {

                        if (bullet.data.invader_Player_Bullet.y == -4) {

                            bullet.data.invader_Player_Bullet.x = player.data.invader_Player.x + 4;
                            bullet.data.invader_Player_Bullet.y = player.data.invader_Player.y - 10;
                            
                        }

                    }



                    invader_RenderEnemies();
                    invader_RenderBarriers();
                    invader_RenderPlayer();
                    invader_RenderPlayerBullet();



                    // Housekeeping ..

                    invader_MoveInvaders();

                    if (bullet.data.invader_Player_Bullet.y > -4) {
                     
                        bullet.data.invader_Player_Bullet.y = bullet.data.invader_Player_Bullet.y - 2;
   
                    }

                }

                break;                

        #endif

        default: break;

    }

}
