#include <Arduboy2.h>

uint8_t invader_EnemiesAlive() {

    uint8_t count = 0;

    for (uint8_t x = Constants::Invaders_Enemy_Row_1_Start; x <= Constants::Invaders_Enemy_Row_3_End; x++) {
   
        Item &enemy = level.getItem(x);
        if (enemy.data.invader_Enemy.status == Status::Active)  count++;

    }

    return count++;

}

uint8_t invaders_getSpeed() {

    return 2 + (invader_EnemiesAlive() / 1);

}

void invader_RenderHUD(Invader_General &general) {

    FX::drawBitmap(120, 0, Images::HUD_Backgrounds, 1, dbmNormal);

    // Item &item = level.getItem(Constants::Invaders_General);

    for (uint8_t i = 0; i < general.lives; i++) {

        FX::drawBitmap(123, 1 + (i * 6), Images::HUD_Spaceship, 0, dbmNormal);

    }

    FX::drawBitmap(123, 40, Images::Numbers_Small, 0, dbmNormal);
    FX::drawBitmap(123, 48, Images::Numbers_Small, general.score / 100, dbmNormal);
    FX::drawBitmap(123, 56, Images::Numbers_Small, general.score % 100, dbmNormal);

}

void invader_RenderEnemies(int yOffset = 0) {

    for (uint8_t x = Constants::Invaders_Enemy_Row_1_Start; x <= Constants::Invaders_Enemy_Row_3_End; x++) {

        uint8_t image = ((x - static_cast<uint8_t>(Constants::Invaders_Enemy_Row_1_Start)) / 7) * 6;
        uint8_t frame = 0;

        Item &enemy = level.getItem(x);
        
        // Calculate frame ..
        
        switch (enemy.data.invader_Enemy.status) {

            case Status::Active:
                frame = (arduboy.getFrameCountHalf(80) ? (x % 2) : 1 - (x % 2));
                break;

            case Status::Exploding1 ... Status::Exploding4:
                frame = static_cast<uint8_t>(enemy.data.invader_Enemy.status) - 2;
                break;

            default:
                continue;

        }

        if (enemy.data.invader_Enemy.status != Status::Dead) {
            
            FX::drawBitmap(enemy.data.invader_Enemy.x - 8, enemy.data.invader_Enemy.y + yOffset - 8, Images::Invaders, image + frame, dbmMasked);
        
        }

    }

}

void invader_RenderBarriers(int yOffset = 0) {

    for (uint8_t x = Constants::Invaders_Barrier_Start; x <= Constants::Invaders_Barrier_End; x++) {

        Item &barrier = level.getItem(x);
        FX::drawBitmap(barrier.data.invader_Barrier.x, barrier.data.invader_Barrier.y + yOffset, Images::Barriers, 0, dbmMasked);

    }

}

void invader_RenderPlayer(Invader_Player &player, int yOffset = 0) {

    uint8_t frame = 0;
    
    switch (player.status) {

        case Status::Active:
            frame = 0;
            break;

        case Status::Exploding1 ... Status::Exploding4:
            frame = static_cast<uint8_t>(player.status) - 2;
            break;

        default: break;

    }

    FX::drawBitmap(player.x - 8, player.y + yOffset - 8, Images::Player, frame, dbmMasked);

}

void invader_RenderPlayerBullet(Invader_Player_Bullet &bullet) {

    FX::drawBitmap(bullet.x, bullet.y, Images::Bullet, 0, dbmNormal);
    
}

void invader_RenderEnemyBullets() {

    for (uint8_t x = Constants::Invaders_Enemy_Bullet_Start; x <= Constants::Invaders_Enemy_Bullet_End; x++) {

        Item &bullet = level.getItem(x);

        if (bullet.data.invader_Enemy_Bullet.y < 64) {

            FX::drawBitmap(bullet.data.invader_Enemy_Bullet.x, bullet.data.invader_Enemy_Bullet.y, Images::Bullet, 0, dbmNormal);
            
        }

    }
    
}

void invader_MoveInvaders_Left(Invader_General &general, uint8_t startPos, uint8_t endPos) {
    
    for (uint8_t x = startPos; x <= endPos; x++) {

        Item &enemy = level.getItem(x);
        enemy.data.invader_Enemy.x = enemy.data.invader_Enemy.x - 2;

        if (startPos == static_cast<uint8_t>(Constants::Invaders_Enemy_Row_1_Start) && enemy.data.invader_Enemy.x == 5) {

            general.direction = Direction::Right;

            for (uint8_t x = Constants::Invaders_Enemy_Row_1_Start; x <= Constants::Invaders_Enemy_Row_3_End; x++) {

                Item &enemy2 = level.getItem(x);
                enemy2.data.invader_Enemy.y++;

            }

        }

    }

}

void invader_MoveInvaders_Right(Invader_General &general, uint8_t startPos, uint8_t endPos) {
    
    for (uint8_t x = startPos; x <= endPos; x++) {

        Item &enemy = level.getItem(x);
        enemy.data.invader_Enemy.x = enemy.data.invader_Enemy.x + 2;

        if (startPos == static_cast<uint8_t>(Constants::Invaders_Enemy_Row_1_Start) && enemy.data.invader_Enemy.x == 103) {

            general.direction = Direction::Left;

            for (uint8_t x = Constants::Invaders_Enemy_Row_1_Start; x <= Constants::Invaders_Enemy_Row_3_End; x++) {

                Item &enemy2 = level.getItem(x);
                enemy2.data.invader_Enemy.y++;

            }
            
        }

    }

}

void invader_UpdateInvaders(Invader_General &general) {

    uint8_t frameCount = arduboy.getFrameCount(invaders_getSpeed());

    switch (general.direction) {

        case Direction::Left:

            switch (frameCount) {

                case 0:

                    invader_MoveInvaders_Left(general, Constants::Invaders_Enemy_Row_1_Start, Constants::Invaders_Enemy_Row_1_End);
                    break;

                case 3:
                    {   
                        Item &enemy = level.getItem(Constants::Invaders_Enemy_Row_1_End);
                        if (enemy.data.invader_Enemy.x == 103) {
                            invader_MoveInvaders_Right(general, Constants::Invaders_Enemy_Row_2_Start, Constants::Invaders_Enemy_Row_2_End);
                        }
                        else {
                            invader_MoveInvaders_Left(general, Constants::Invaders_Enemy_Row_2_Start, Constants::Invaders_Enemy_Row_2_End);
                        }

                    }

                    break;

                case 6:
                    {   
                        Item &enemy = level.getItem(Constants::Invaders_Enemy_Row_1_End);

                        if (enemy.data.invader_Enemy.x == 103) {
                            invader_MoveInvaders_Right(general, Constants::Invaders_Enemy_Row_3_Start, Constants::Invaders_Enemy_Row_3_End);
                        }
                        else {
                            invader_MoveInvaders_Left(general, Constants::Invaders_Enemy_Row_3_Start, Constants::Invaders_Enemy_Row_3_End);
                        }

                    }
                    break;

            }

            break;

        case Direction::Right:

            switch (frameCount) {

                case 0:

                    invader_MoveInvaders_Right(general, Constants::Invaders_Enemy_Row_1_Start, Constants::Invaders_Enemy_Row_1_End);
                    break;

                case 3:
                    {   
                        Item &enemy = level.getItem(Constants::Invaders_Enemy_Row_1_Start);

                        if (enemy.data.invader_Enemy.x == 5) {
                            invader_MoveInvaders_Left(general, Constants::Invaders_Enemy_Row_2_Start, Constants::Invaders_Enemy_Row_2_End);
                        }
                        else {
                            invader_MoveInvaders_Right(general, Constants::Invaders_Enemy_Row_2_Start, Constants::Invaders_Enemy_Row_2_End);
                        }

                    }

                    break;

                case 6:
                    {   
                        Item &enemy = level.getItem(Constants::Invaders_Enemy_Row_1_Start);

                        if (enemy.data.invader_Enemy.x == 5) {
                            invader_MoveInvaders_Left(general, Constants::Invaders_Enemy_Row_3_Start, Constants::Invaders_Enemy_Row_3_End);
                        }
                        else {
                            invader_MoveInvaders_Right(general, Constants::Invaders_Enemy_Row_3_Start, Constants::Invaders_Enemy_Row_3_End);
                        }

                    }
                    break;

            }

            break;

        default: break;

    }


    // Update explosions, etc ..

    for (uint8_t x = Constants::Invaders_Enemy_Row_1_Start; x <= Constants::Invaders_Enemy_Row_3_End; x++) {

        Invader_Enemy &enemy = level.getItem(x).data.invader_Enemy;
        
        if (enemy.status >= Status::Exploding1 && enemy.status < Status::Dead) {

            enemy.status = static_cast<Status>(static_cast<uint8_t>(enemy.status) + 1);

        }

    }

}


void invader_UpdatePlayer(Invader_General &general, Invader_Player &player) {
    
    if (player.status >= Status::Exploding1 && player.status < Status::Dead) {

        player.status = static_cast<Status>(static_cast<uint8_t>(player.status) + 1);

        if (player.status == Status::Dead) {

            general.lives--;

        }

    }

}

void invader_EnemyDropsBullet(Invader_General2 &general2, Invader_Player &player) {

    // Are we still in the pause period between bullets ?

    if (general2.bulletCountdown > 0 || player.status != Status::Active) {
        general2.bulletCountdown--;
        return;
    }



    // Do we have a spare bullet?

    uint8_t found = 255;

    for (uint8_t x = Constants::Invaders_Enemy_Bullet_Start; x <= Constants::Invaders_Enemy_Bullet_End; x++) {

        Invader_Enemy_Bullet &bullet = level.getItem(x).data.invader_Enemy_Bullet;

        if (bullet.y == 64) {

            found = x;
            break;
            
        }

    }


    // If we found a bullet then launch it!

    if (found != 255) {

        // Invader_Player &player = level.getItem(Constants::Invaders_Player);
        Invader_Enemy_Bullet &bullet = level.getItem(found).data.invader_Enemy_Bullet;

        for (uint8_t x = Constants::Invaders_Enemy_Row_3_End; x > Constants::Invaders_Enemy_Row_1_Start; x--) {

            Invader_Enemy &enemy = level.getItem(x).data.invader_Enemy;
            
            if (enemy.status == Status::Active && abs(enemy.x - player.x) < 16) {

                bullet.x = enemy.x + 4;
                bullet.y = enemy.y + 8;

                uint8_t x = invaders_getSpeed();

                general2.bulletCountdown = random(x, x * 2);
                general2.bulletCountdown = random(x * 2, x * 4);

            }

        }

    }

}


void invader_DetectPlayerBulletHit(Invader_General &general, Invader_Player_Bullet &bullet) {

    Point bulletPoint = { bullet.x, bullet.y };

    for (uint8_t x = Constants::Invaders_Enemy_Row_1_Start; x <= Constants::Invaders_Enemy_Row_3_End; x++) {

        Invader_Enemy &enemy = level.getItem(x).data.invader_Enemy;

        if (enemy.status == Status::Active) {

            Rect enemyRect = { enemy.x + 1, enemy.y, 7, 7 };

            if (arduboy.collide(bulletPoint, enemyRect)) {

                enemy.status = Status::Exploding1;
                bullet.y = -4;
                general.score++;

            }

        }

    }

}

void invader_UpdateEnemyBullets(Invader_Player &player) {

    for (uint8_t x = Constants::Invaders_Enemy_Bullet_Start; x <= Constants::Invaders_Enemy_Bullet_End; x++) {

        Invader_Enemy_Bullet &bullet = level.getItem(x).data.invader_Enemy_Bullet;

        if (bullet.y < 64) {

            bullet.y++;

            Point bulletPoint = { bullet.x, bullet.y };

            // Item &player = level.getItem(Constants::Invaders_Player);

            if (player.status == Status::Active) {

                Rect playerRect = { player.x, player.y + 2, 9, 7 };

// arduboy.drawRect(playerRect.x, playerRect.y, 9, 7, WHITE);
// Serial.print(playerRect.x);
// Serial.print("-");
// Serial.print(playerRect.x + 9);
// Serial.print(" ");
// Serial.println(bullet.x);

                if (arduboy.collide(bulletPoint, playerRect)) {
// Serial.println("dsfd");
                    player.status = Status::Exploding1;
                    bullet.y = 64;

                }

            }

        }

    }

}

void invader_PlayGame() {

    auto justPressed = arduboy.justPressedButtons();
    auto pressed = arduboy.pressedButtons();

    Invader_General &general = level.getItem(Constants::Invaders_General).data.invader_General;
    Invader_General2 &general2 = level.getItem(Constants::Invaders_General2).data.invader_General2;
    Invader_Player &player = level.getItem(Constants::Invaders_Player).data.invader_Player;
    Invader_Player_Bullet &bullet = level.getItem(Constants::Invaders_Player_Bullet).data.invader_Player_Bullet;


    // Update bullets ..

    invader_UpdateInvaders(general);
    invader_UpdatePlayer(general, player);
    invader_UpdateEnemyBullets(player);
    invader_EnemyDropsBullet(general2, player);

    if (bullet.y > -4) {
        
        bullet.y = bullet.y - 2;

    }

    invader_DetectPlayerBulletHit(general, bullet);


    // Handle movements ..

    if (pressed & LEFT_BUTTON && player.x > 4) {
        player.x--;
    }

    if (pressed & RIGHT_BUTTON && player.x < 104) {
        player.x++;
    }

    if (pressed & A_BUTTON) {

        if (bullet.y == -4) {

            bullet.x = player.x + 4;
            bullet.y = player.y - 10;
            
        }

    }



    invader_RenderEnemies();
    invader_RenderBarriers();
    invader_RenderPlayer(player);
    invader_RenderPlayerBullet(bullet);
    invader_RenderEnemyBullets();
    invader_RenderHUD(general);

}