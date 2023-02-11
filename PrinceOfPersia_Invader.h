#include <Arduboy2.h>

void invader_LoadEnemies() {

    arduboy.frameCount = 5;

    FX::seekData(FX::readIndexedUInt24(Levels::Level_Items, 0) + 16);

    for(uint8_t x = 0; x < 21; x++) {

        Item &item = level.getItem(Constants::Invaders_Enemy_Row_1_Start + x);
        item.itemType = static_cast<ItemType>(FX::readPendingUInt8());
        FX::readBytes((uint8_t*)&item.data.rawData, sizeof(item.data.rawData));

        item.data.invader_Enemy.y = item.data.invader_Enemy.y - 24;

    }

    FX::readEnd();

}

uint8_t invader_EnemiesAlive() {

    uint8_t count = 0;

    for (uint8_t x = Constants::Invaders_Enemy_Row_1_Start; x <= Constants::Invaders_Enemy_Row_3_End; x++) {
   
        Item &enemy = level.getItem(x);
        if (enemy.data.invader_Enemy.status == Status::Active)  count++;

    }

    return count++;

}

uint8_t invaders_getSpeed() {

    return 22;
    // return 2 + (invader_EnemiesAlive() / 1);

}

void invader_RenderHUD(Invader_General &general) {

    FX::drawBitmap(120, 0, Images::HUD_Backgrounds, 1, dbmNormal);

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

        Invader_Enemy &enemy = level.getItem(x).data.invader_Enemy;
        
        // Calculate frame ..
        
        switch (enemy.status) {

            case Status::Active:
                frame = (arduboy.getFrameCountHalf(80) ? (x % 2) : 1 - (x % 2));
                break;

            case Status::Exploding1 ... Status::Exploding4:
                frame = static_cast<uint8_t>(enemy.status) - 3;
                break;

            default:
                continue;

        }

        if (enemy.status != Status::Dead) {
            
            FX::drawBitmap(enemy.x - 8, enemy.y + yOffset - 8, Images::Invaders, image + frame, dbmMasked);
        
        }

    }

}

void invader_RenderBarriers(int yOffset = 0) {

    for (uint8_t x = Constants::Invaders_Barrier_Start; x <= Constants::Invaders_Barrier_End; x++) {

        Item &barrier = level.getItem(x);
        FX::drawBitmap(barrier.data.invader_Barrier.x, barrier.data.invader_Barrier.y + yOffset, Images::Barriers, 0, dbmMasked);

    }

}

void invader_RenderPlayer(Invader_Player &player, int yOffset = 0, bool show = false) {

    uint8_t frame = 0;
    switch (player.status) {

        case Status::Active:
            frame = 0;
            break;

        case Status::Safe:
            if (!show && arduboy.getFrameCountHalf(32)) return;
            break;

        case Status::Exploding1 ... Status::Exploding4:
            frame = static_cast<uint8_t>(player.status) - 4;
            break;

        case Status::Dead:
            return;

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

void invader_MoveEnemies_Down(Invader_Player &player) {

    if (player.status == Status::Active) {

        for (uint8_t x = Constants::Invaders_Enemy_Row_1_Start; x <= Constants::Invaders_Enemy_Row_3_End; x++) {

            Invader_Enemy &enemy = level.getItem(x).data.invader_Enemy;
            enemy.y++;

        }

    }

}

void invader_MoveEnemies_Left(Invader_General &general, Invader_Player &player, uint8_t startPos, uint8_t endPos, uint8_t test) {

    Invader_Enemy &testItem = level.getItem(test).data.invader_Enemy;

    for (uint8_t x = startPos; x <= endPos; x++) {

        Invader_Enemy &enemy = level.getItem(x).data.invader_Enemy;
        enemy.x = enemy.x - 2;

    }


    // Move enemies down ?

    if (startPos == Constants::Invaders_Enemy_Row_1_Start && testItem.x <= 5) {

        general.direction = Direction::Right;
        invader_MoveEnemies_Down(player);
        
    }

}

void invader_MoveEnemies_Right(Invader_General &general, Invader_Player &player, uint8_t startPos, uint8_t endPos, uint8_t test) {
    
    Invader_Enemy &testItem = level.getItem(test).data.invader_Enemy;

    for (uint8_t x = startPos; x <= endPos; x++) {

        Invader_Enemy &enemy = level.getItem(x).data.invader_Enemy;
        enemy.x = enemy.x + 2;

    }


    // Move enemies down ?

    if (startPos == Constants::Invaders_Enemy_Row_1_Start && testItem.x >= 103) {

        general.direction = Direction::Left;
        invader_MoveEnemies_Down(player);
        
    }

}

void invader_UpdateEnemy(Invader_General &general, Invader_Player &player) {

    uint8_t frameCount = arduboy.getFrameCount(invaders_getSpeed());


    if (frameCount == 0) {

        general.right = 0;
        general.left = 6;

        for (uint8_t x = Constants::Invaders_Enemy_Row_1_Start; x <= Constants::Invaders_Enemy_Row_1_End; x++) {

            for (uint8_t y = 0; y <= 2; y++) {

                Item &enemy = level.getItem(x + (y * 7));
                
                if (enemy.data.invader_Enemy.status != Status::Dead) {

                    if (x > general.right) general.right = x;
                    if (x < general.left)  general.left  = x;

                }

            }

        }

        general.right = general.right - Constants::Invaders_Enemy_Row_1_Start;
        general.left = general.left - Constants::Invaders_Enemy_Row_1_Start;

    }




    // Move enemies ..

    switch (general.direction) {

        case Direction::Left:

            switch (frameCount) {

                case 0:

                    invader_MoveEnemies_Left(general, player, Constants::Invaders_Enemy_Row_1_Start, Constants::Invaders_Enemy_Row_1_End, Constants::Invaders_Enemy_Row_1_Start + general.left);
                    break;

                case 2:
                    {   
                        Item &enemy = level.getItem(Constants::Invaders_Enemy_Row_1_Start + general.right);
                        if (enemy.data.invader_Enemy.x >= 103) {
                            invader_MoveEnemies_Right(general, player, Constants::Invaders_Enemy_Row_2_Start, Constants::Invaders_Enemy_Row_2_End, Constants::Invaders_Enemy_Row_1_Start + general.right);
                        }
                        else {
                            invader_MoveEnemies_Left(general, player, Constants::Invaders_Enemy_Row_2_Start, Constants::Invaders_Enemy_Row_2_End, Constants::Invaders_Enemy_Row_1_Start + general.left);
                        }

                    }

                    break;

                case 4:
                    {   
                        Item &enemy = level.getItem(Constants::Invaders_Enemy_Row_1_Start + general.right);

                        if (enemy.data.invader_Enemy.x >= 103) {
                            invader_MoveEnemies_Right(general, player, Constants::Invaders_Enemy_Row_3_Start, Constants::Invaders_Enemy_Row_3_End, Constants::Invaders_Enemy_Row_1_Start + general.right);
                        }
                        else {
                            invader_MoveEnemies_Left(general, player, Constants::Invaders_Enemy_Row_3_Start, Constants::Invaders_Enemy_Row_3_End, Constants::Invaders_Enemy_Row_1_Start + general.left);
                        }

                    }
                    break;

            }

            break;

        case Direction::Right:

            switch (frameCount) {

                case 0:

                    invader_MoveEnemies_Right(general, player, Constants::Invaders_Enemy_Row_1_Start, Constants::Invaders_Enemy_Row_1_End, Constants::Invaders_Enemy_Row_1_Start + general.right);
                    break;

                case 2:
                    {   
                        Item &enemy = level.getItem(Constants::Invaders_Enemy_Row_1_Start + general.left);

                        if (enemy.data.invader_Enemy.x <= 5) {
                            invader_MoveEnemies_Left(general, player, Constants::Invaders_Enemy_Row_2_Start, Constants::Invaders_Enemy_Row_2_End, Constants::Invaders_Enemy_Row_1_Start + general.left);
                        }
                        else {
                            invader_MoveEnemies_Right(general, player, Constants::Invaders_Enemy_Row_2_Start, Constants::Invaders_Enemy_Row_2_End, Constants::Invaders_Enemy_Row_1_Start + general.right);
                        }

                    }

                    break;

                case 4:
                    {   
                        Item &enemy = level.getItem(Constants::Invaders_Enemy_Row_1_Start + general.left);

                        if (enemy.data.invader_Enemy.x <= 5) {
                            invader_MoveEnemies_Left(general, player, Constants::Invaders_Enemy_Row_3_Start, Constants::Invaders_Enemy_Row_3_End, Constants::Invaders_Enemy_Row_1_Start + general.left);
                        }
                        else {
                            invader_MoveEnemies_Right(general, player, Constants::Invaders_Enemy_Row_3_Start, Constants::Invaders_Enemy_Row_3_End, Constants::Invaders_Enemy_Row_1_Start + general.right);
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


void invader_UpdatePlayer(Invader_General &general, Invader_General2 &general2, Invader_Player &player) {
    
    if (player.status >= Status::Exploding1 && player.status < Status::Dead) {

        player.status = static_cast<Status>(static_cast<uint8_t>(player.status) + 1);

        if (player.status == Status::Dead) {

            general.lives--;
            general2.deathCountdown = 48;

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

                if (arduboy.collide(bulletPoint, playerRect)) {

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

    invader_UpdateEnemy(general, player);
    invader_UpdatePlayer(general, general2, player);
    invader_UpdateEnemyBullets(player);
    invader_EnemyDropsBullet(general2, player);

    if (bullet.y > -4) {
        
        bullet.y = bullet.y - 2;

    }

    invader_DetectPlayerBulletHit(general, bullet);


    // Handle movements ..

    if (player.status <= Status::Safe) {
            
        if (pressed & LEFT_BUTTON && player.x > 4) {
            player.status = Status::Active;
            player.x--;
        }

        if (pressed & RIGHT_BUTTON && player.x < 104) {
            player.status = Status::Active;
            player.x++;
        }

        if (pressed & A_BUTTON) {

            player.status = Status::Active;

            if (bullet.y == -4) {

                bullet.x = player.x + 4;
                bullet.y = player.y - 10;
                
            }

        }

    }

    invader_RenderEnemies();
    invader_RenderBarriers();

    if (player.status != Status::Dead || general.lives != 0) {
        invader_RenderPlayer(player);
    }

    invader_RenderPlayerBullet(bullet);
    invader_RenderEnemyBullets();
    invader_RenderHUD(general);


    switch (player.status) {

        case Status::Active:

            if (invader_EnemiesAlive() == 0) {

                invader_LoadEnemies();

            }

            break;

        case Status::Safe:

            FX::drawBitmap(35, 25, Images::Levels, general.lives, dbmMasked);
            break;

        case Status::Dead:

            if (general2.deathCountdown > 0) {
                general2.deathCountdown--;
            }
            else {

                if (general.lives > 0) {

                    player.status = Status::Safe;

                }
                else {

                    FX::drawBitmap(35, 25, Images::Levels, general.lives, dbmMasked);

                }

            }

            break;

    }

}