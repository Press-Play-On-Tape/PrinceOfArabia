#include <Arduboy2.h>   
#include <ArduboyFX.h>  
#include "fxdata/Images.h"  
#include "fxdata/Levels.h"  

#include "src/utils/Constants.h"
#include "src/utils/Stack.h"
#include "src/entities/Entities.h"


uint8_t xLoc = 60;
uint8_t yLoc = 0;

uint8_t playerXLoc = 10;
uint8_t playerYLoc = 26;

// uint8_t xLoc = 40;
// uint8_t yLoc = 0;

// uint8_t playerXLoc = 10;
// uint8_t playerYLoc = -6;

int8_t bg[3][11];
int8_t fg[3][11];

Arduboy2 arduboy;


Stack <uint8_t, 15> princeStack;
Prince prince;

void printMap() {

    Serial.println("Map ---------------");
    Serial.print("xLoc: ");
    Serial.print(xLoc);
    Serial.print(", yLoc: ");
    Serial.println(yLoc);

    Serial.println("BG ---------------");

    for (uint8_t y = 0; y < 3; y++) {

        for (uint8_t x = 0; x < 11; x++) {

            Serial.print(bg[y][x]);
            Serial.print(" ");

        }

        Serial.println("");

    }


    Serial.println("FG ---------------");

    for (uint8_t y = 0; y < 3; y++) {

        for (uint8_t x = 0; x < 11; x++) {

            Serial.print(fg[y][x]);
            Serial.print(" ");

        }

        Serial.println("");

    }

}


void loadMap(uint8_t xLoc, uint8_t yLoc) {


    // Background ..

    for (uint8_t y = yLoc; y < yLoc + 3; y++) {

        FX::seekData(static_cast<uint24_t>(Levels::Level1_BG + (y * Levels::Level1_Width) + xLoc));

        for (uint8_t x = 0; x < 11; x++) {

            int8_t tileId = static_cast<int8_t>(FX::readPendingUInt8());
            bg[y - yLoc][x] = tileId;

        }

        FX::readEnd();

    }

    // Foreground ..

    for (uint8_t y = yLoc; y < yLoc + 3; y++) {

        FX::seekData(static_cast<uint24_t>(Levels::Level1_FG + (y * Levels::Level1_Width) + xLoc));

        for (uint8_t x = 0; x < 11; x++) {

            int8_t tileId = static_cast<int8_t>(FX::readPendingUInt8());
            fg[y - yLoc][x] = tileId;

        }

        FX::readEnd();

    }

    //printMap();

}

void setup() {

    arduboy.begin();
    FX::disableOLED();
    FX::begin(FX_DATA_PAGE);

    loadMap(xLoc, yLoc);
    prince.setStack(&princeStack);

}

void loop() {

    if (!arduboy.nextFrame()) return; 
    arduboy.pollButtons();

    prince.update();


// Serial.println("----------------------");
Serial.print("Stance: ");
Serial.print(prince.getStance());
Serial.print(", Direction: ");
Serial.println((uint8_t)prince.getDirection());

    // if (arduboy.justPressed(LEFT_BUTTON)) {
    //     xLoc = xLoc - 10;
    //     loadMap(xLoc, yLoc);
    // }
    // if (arduboy.justPressed(RIGHT_BUTTON)) {
    //     xLoc = xLoc + 10;
    //     loadMap(xLoc, yLoc);
    // }
    // if (arduboy.justPressed(UP_BUTTON)) {
    //     yLoc = yLoc - 3;
    //     loadMap(xLoc, yLoc);
    // }
    // if (arduboy.justPressed(DOWN_BUTTON)) {
    //     yLoc = yLoc + 3;
    //     loadMap(xLoc, yLoc);
    // }



    if (!prince.isFalling()) { //} && this->world.aboutToFall(Action::RunRepeat, tile, distToTile, distToFall)) {

        // switch (tile) {

        //     case SceneryTile::GroundPit:
        //         this->prince.clear();
        //         this->prince.setFalling(true);
        //         this->prince.pushSequence(STANCE_DYING_1_START, STANCE_DYING_6_END, true);
        //         this->prince.setStance(STANCE_DYING_1_START);
        //         break;

        //     case SceneryTile::GroundNormal:
        //     case SceneryTile::PlatformLH:
        //     case SceneryTile::Platform:
        //     case SceneryTile::PlatformRH:

        //         switch (distToFall) {

        //             case 1:
        //                 this->prince.clear();
        //                 this->prince.setFalling(true);
        //                 this->prince.pushSequence(STANCE_SQUAT_1_START, STANCE_SQUAT_10_END, STANCE_UPRIGHT, true);
        //                 this->prince.pushSequence(STANCE_FALLING_1_START, STANCE_FALLING_3_END, true);
        //                 this->prince.setStance(STANCE_FALLING_1_START);
        //                 break;

        //             case 2:
        //                 this->prince.clear();
        //                 this->prince.setFalling(true);
        //                 this->prince.pushSequence(STANCE_SQUAT_1_START, STANCE_SQUAT_10_END, STANCE_UPRIGHT, true);
        //                 this->prince.pushSequence(STANCE_FALLING_1_START, STANCE_FALLING_3_END, true);
        //                 this->prince.setStance(STANCE_FALLING_1_START);
        //                 break;

        //         }

        //         break;

        // }

    }


    if (prince.isEmpty()) {

// Serial.println("Stack empty");
        switch (prince.getStance()) {

            case STANCE_UPRIGHT:

                if (prince.getDirection() == Direction::Right) {

                    if (arduboy.pressed(RIGHT_BUTTON)) {
                        if (true) {
                        // if (this->world.canMoveForward(Action::Step)) {
                            prince.push(STANCE_SINGLE_STEP_1_START, true);
                        }
                    }
                    else if (arduboy.pressed(LEFT_BUTTON)/* && !this->world.isChangingDirections()*/) {
// Serial.println("Left Pressed");
                        // this->world.switchDirections(Direction::Left);
                        prince.pushSequence(STANCE_STANDING_TURN_1_START, STANCE_STANDING_TURN_5_END, STANCE_UPRIGHT_TURN, true);
                    }
                    else if (arduboy.pressed(A_BUTTON)) {
                        prince.pushSequence(STANCE_STANDING_JUMP_1_START, STANCE_STANDING_JUMP_18_END, STANCE_UPRIGHT, true);
                    }
                    
                }
                else {

                    if (arduboy.pressed(LEFT_BUTTON)) {
                        // if (this->world.canMoveForward(Action::Step)) {
                        if (true) {
                            prince.push(STANCE_SINGLE_STEP_1_START, true);
                        }
                    }
                    else if (arduboy.pressed(RIGHT_BUTTON) /*&& !this->world.isChangingDirections()*/) {
// Serial.println("ss Pressed");
                        // this->world.switchDirections(Direction::Right);
                        prince.pushSequence(STANCE_STANDING_TURN_1_START, STANCE_STANDING_TURN_5_END, STANCE_UPRIGHT_TURN, true);
                    }
                    else if (arduboy.pressed(A_BUTTON)) {
                        prince.pushSequence(STANCE_STANDING_JUMP_1_START, STANCE_STANDING_JUMP_18_END, STANCE_UPRIGHT, true);
                    }


                }

                if (arduboy.pressed(DOWN_BUTTON)) {
                    //prince.pushSequence(STANCE_SQUAT_1_START, STANCE_SQUAT_3_LOW_POINT, true);
                }
                else if (arduboy.pressed(UP_BUTTON)) {

/*
                    SceneryLevel level = this->world.getLevel();
                    int16_t distance = this->world.distanceToTile(--level, this->prince.getDirection() == Direction::Right ? SceneryTile::PlatformLH : SceneryTile::PlatformRH);
printf("distance %i\n", distance);                    
                    switch (distance) {

                        case -6 ... -1:
// printf("Climb 0\n");                        
                            // step back
                            this->world.decX(8);
                            this->prince.climbUpwards();
                            break;

                        case 0 ... 5:
// printf("Climb 0\n");                        
                            // step back
                            this->world.decX(4);
                            this->prince.climbUpwards();
                            break;

                        case 6 ... 7:
// printf("Climb 1\n");                        
                            this->prince.climbUpwards();
                            this->prince.push(STANCE_SINGLE_STEP_2, true);
                            break;

                        case 8 ... 9:
// printf("Climb 2\n");                        
                            this->prince.climbUpwards();
                            this->prince.stepForwardOne();
                            break;

                        case 10 ... 12:
// printf("Climb 3\n");                        
                            this->prince.climbUpwards();
                            this->prince.stepForwardTwo();
                            break;

                        case 13 ... 18:
// printf("Climb 4\n");                   
                            this->prince.pushSequence(STANCE_STEP_CLIMBING_1_START, STANCE_STEP_CLIMBING_20_END, STANCE_UPRIGHT_END_CLIMB, true);
                            break;

                        case 19 ... 21:
// printf("Climb 5\n");                   
//                            prince.pushSequence(STANCE_STEP_CLIMBING_1_START, STANCE_STEP_CLIMBING_20_END, STANCE_UPRIGHT_END_CLIMB, true);
                            prince.pushSequence(STANCE_STEP_CLIMBING_1_START, STANCE_STEP_CLIMBING_20_END, STANCE_UPRIGHT_END_CLIMB, true);
                            prince.pushSequence(STANCE_SINGLE_STEP_2, STANCE_SINGLE_STEP_8_END, STANCE_UPRIGHT, true);
                            prince.push(STANCE_SINGLE_STEP_1_START, true);
                            break;

                        default: 
                            distance = TILE_NOT_FOUND;
                            break;

                    }

                    if (distance == TILE_NOT_FOUND) {
// printf("Swing\n");  
                        this->prince.pushSequence(STANCE_SWINGING_1_START, STANCE_SWINGING_12_END, STANCE_UPRIGHT, true);

                    }
*/
                }

                break;

            case STANCE_SINGLE_STEP_1_START:

                if (prince.getDirection() == Direction::Right) {
// printf("canMoveForward STANCE_SINGLE_STEP_1_START 1\n");
                    if (arduboy.pressed(RIGHT_BUTTON)) {
                        // if (this->world.canMoveForward(Action::RunStart)) {
                        if (true) {
                            prince.pushSequence(STANCE_RUN_START_2, STANCE_RUN_START_6_END, true);
                        }
                        else {
                            prince.pushSequence(STANCE_SINGLE_STEP_2, STANCE_SINGLE_STEP_8_END, STANCE_UPRIGHT, true);
                        }
                    }
                    else if (!arduboy.pressed(RIGHT_BUTTON)) {
                        prince.pushSequence(STANCE_SINGLE_STEP_2, STANCE_SINGLE_STEP_8_END, STANCE_UPRIGHT, true);
                    }

                }
                else {

                    if (arduboy.pressed(LEFT_BUTTON)) {
                        // if (this->world.canMoveForward(Action::RunStart)) {
                        if (true) {
                            prince.pushSequence(STANCE_RUN_START_2, STANCE_RUN_START_6_END, true);
                        }
                        else {
                            prince.pushSequence(STANCE_SINGLE_STEP_2, STANCE_SINGLE_STEP_8_END, STANCE_UPRIGHT, true);
                        }                            
                    }
                    else if (!arduboy.pressed(LEFT_BUTTON)) {
                        prince.pushSequence(STANCE_SINGLE_STEP_2, STANCE_SINGLE_STEP_8_END, STANCE_UPRIGHT, true);
                    }

                }
                break;

            case STANCE_RUN_REPEAT_4:

                if (prince.getDirection() == Direction::Right) {
                        
                    if (arduboy.pressed(RIGHT_BUTTON) && arduboy.pressed(A_BUTTON)) {
                        // if (this->world.canMoveForward(Action::RunJump)) {
                        if (true) {
                            
//                             distToTile = this->world.distanceToTile(this->world.getLevel(), SceneryTile::GroundPit);
// printf("dist %i\n", distToTile);                            
//                             if (distToTile > 20) {

// printf("Run Jump 1a\n");                            
                            prince.pushSequence(STANCE_RUNNING_JUMP_1_START, STANCE_RUNNING_JUMP_11_END, STANCE_RUN_START_6_END, true);
//                             }
//                             else {
// printf("Run Jump 1b\n");                            
//                                 this->prince.pushSequence(STANCE_RUNNING_JUMP_2, STANCE_RUNNING_JUMP_11_END, STANCE_RUN_START_6_END, true);

//                             }
                        }
                        else {
// printf("Run Jump 1 FAIL\n");                            
                            prince.pushSequence(STANCE_STOPPING_1_START, STANCE_STOPPING_5_END, STANCE_UPRIGHT, true);
                        }
                    }
                    else if (arduboy.pressed(RIGHT_BUTTON)) {
                        // if (this->world.canMoveForward(Action::RunRepeat)) {
                        if (true) {
// printf("Run 1\n");                            
                            prince.pushSequence(STANCE_RUN_REPEAT_5_MID, STANCE_RUN_REPEAT_8_END, true);
                        }
                        else {
                            prince.pushSequence(STANCE_STOPPING_1_START, STANCE_STOPPING_5_END, STANCE_UPRIGHT, true);
                        }
                    }
                    else if (arduboy.pressed(LEFT_BUTTON)) {
                        // this->world.switchDirections(Direction::Left);
                        prince.pushSequence(STANCE_RUNNING_TURN_1_START, STANCE_RUNNING_TURN_13_END, STANCE_RUN_REPEAT_8_END_TURN, true);
                    }
                    else if (!arduboy.pressed(RIGHT_BUTTON)) {
                        prince.pushSequence(STANCE_STOPPING_1_START, STANCE_STOPPING_5_END, STANCE_UPRIGHT, true);
                    }

                }
                else {

                    if (arduboy.pressed(LEFT_BUTTON) && arduboy.pressed(A_BUTTON)) {
                        // if (this->world.canMoveForward(Action::RunJump)) {
                        if (true) {
//                             distToTile = this->world.distanceToTile(this->world.getLevel(), SceneryTile::GroundPit);
// printf("dist %i\n", distToTile);                            
//                             if (distToTile > 20) {
// printf("Run Jump 2a\n"); 
                                prince.pushSequence(STANCE_RUNNING_JUMP_1_START, STANCE_RUNNING_JUMP_11_END, STANCE_RUN_START_6_END, true);
//                             }
//                             else {
// printf("Run Jump 2b\n"); 
//                                 this->prince.pushSequence(STANCE_RUNNING_JUMP_2, STANCE_RUNNING_JUMP_11_END, STANCE_RUN_START_6_END, true);
//                             }
                        }
                        else {
// printf("Run Jump 2 FAIL\n"); 
                            prince.pushSequence(STANCE_STOPPING_1_START, STANCE_STOPPING_5_END, STANCE_UPRIGHT, true);
                        }
                    }
                    else if (arduboy.pressed(LEFT_BUTTON)) {
                        // if (this->world.canMoveForward(Action::RunRepeat)) {
                        if (true) {
// printf("Run 2\n"); 
                            prince.pushSequence(STANCE_RUN_REPEAT_5_MID, STANCE_RUN_REPEAT_8_END, true);
                        }
                        else {
                            prince.pushSequence(STANCE_STOPPING_1_START, STANCE_STOPPING_5_END, STANCE_UPRIGHT, true);
                        }                        
                    }
                    else if (arduboy.pressed(RIGHT_BUTTON)) {
                        // this->world.switchDirections(Direction::Right);
                        prince.pushSequence(STANCE_RUNNING_TURN_1_START, STANCE_RUNNING_TURN_13_END, STANCE_RUN_REPEAT_8_END_TURN, true);
                    }
                    else if (!arduboy.pressed(LEFT_BUTTON)) {
                        prince.pushSequence(STANCE_STOPPING_1_START, STANCE_STOPPING_5_END, STANCE_UPRIGHT, true);
                    }

                }
                break;

            case STANCE_RUN_START_6_END:
            case STANCE_RUN_REPEAT_8_END:

                if (prince.getDirection() == Direction::Right) {
                                    
                    if (arduboy.pressed(RIGHT_BUTTON) && arduboy.pressed(A_BUTTON)) {
                        // if (this->world.canMoveForward(Action::RunJump)) {
                        if (true) {
//                             distToTile = this->world.distanceToTile(this->world.getLevel(), SceneryTile::GroundPit);
// printf("dist %i\n", distToTile);                            
//                             if (distToTile > 20) {
// printf("Run Jump 3a\n");
                            prince.pushSequence(STANCE_RUNNING_JUMP_1_START, STANCE_RUNNING_JUMP_11_END, STANCE_RUN_REPEAT_4, true);
//                             }
//                             else {
// printf("Run Jump 3b\n");
//                             this->prince.pushSequence(STANCE_RUNNING_JUMP_2, STANCE_RUNNING_JUMP_11_END, STANCE_RUN_REPEAT_4, true);

//                             }
                        }
                        else {
// printf("Run Jump 3 FAIL\n");
                            prince.pushSequence(STANCE_STOPPING_1_START, STANCE_STOPPING_5_END, STANCE_UPRIGHT, true);
                        }
                    }
                    else if (arduboy.pressed(RIGHT_BUTTON)) {
                        // if (this->world.canMoveForward(Action::RunRepeat)) {
                        if (true) {
// printf("Run 3\n");
                            prince.pushSequence(STANCE_RUN_REPEAT_1_START, STANCE_RUN_REPEAT_4, true);
                        }
                        else {
                            prince.pushSequence(STANCE_STOPPING_1_START, STANCE_STOPPING_5_END, STANCE_UPRIGHT, true);
                        }
                    }
                    else if (arduboy.pressed(LEFT_BUTTON)) {
                        // this->world.switchDirections(Direction::Left);
                        prince.pushSequence(STANCE_RUNNING_TURN_1_START, STANCE_RUNNING_TURN_13_END, STANCE_RUN_REPEAT_8_END_TURN, true);
                    }
                    else if (!arduboy.pressed(RIGHT_BUTTON)) {
                        prince.pushSequence(STANCE_STOPPING_1_START, STANCE_STOPPING_5_END, STANCE_UPRIGHT, true);
                    }

                }
                else {
                                    
                    if (arduboy.pressed(LEFT_BUTTON) && arduboy.pressed(A_BUTTON)) {
                        // if (this->world.canMoveForward(Action::RunJump)) {
                        if (true) {
//                             distToTile = this->world.distanceToTile(this->world.getLevel(), SceneryTile::GroundPit);
// printf("dist %i\n", distToTile);                            
//                             if (distToTile > 20) {
// printf("Run Jump 4a\n");
//                             // this->prince.push(STANCE_RUN_REPEAT_4, STANCE_RUNNING_JUMP_11_END, STANCE_RUNNING_JUMP_7, true);
//                             // this->prince.push(STANCE_RUNNING_JUMP_6, STANCE_RUNNING_JUMP_6, STANCE_RUNNING_JUMP_5, true);
                               prince.pushSequence(STANCE_RUNNING_JUMP_1_START, STANCE_RUNNING_JUMP_11_END, STANCE_RUN_REPEAT_4, true);
//                             }
//                             else{
// printf("Run Jump 4b\n");
//                             // this->prince.push(STANCE_RUN_REPEAT_4, STANCE_RUNNING_JUMP_11_END, STANCE_RUNNING_JUMP_7, true);
//                             // this->prince.push(STANCE_RUNNING_JUMP_6, STANCE_RUNNING_JUMP_6, STANCE_RUNNING_JUMP_5, true);
//                             this->prince.pushSequence(STANCE_RUNNING_JUMP_2, STANCE_RUNNING_JUMP_11_END, STANCE_RUN_REPEAT_4, true);

//                             }
                        }
                        else {
// printf("Run Jump 4 FAIL\n");
                            prince.pushSequence(STANCE_STOPPING_1_START, STANCE_STOPPING_5_END, STANCE_UPRIGHT, true);
                        }
                    }
                    else if (arduboy.pressed(LEFT_BUTTON)) {
                        // if (this->world.canMoveForward(Action::RunRepeat)) {
                        if (true) {
// printf("Run 4\n");
                            prince.pushSequence(STANCE_RUN_REPEAT_1_START, STANCE_RUN_REPEAT_4, true);
                        }
                        else {
                            prince.pushSequence(STANCE_STOPPING_1_START, STANCE_STOPPING_5_END, STANCE_UPRIGHT, true);
                        }                        
                    }
                    else if (arduboy.pressed(RIGHT_BUTTON)) {
                        // this->world.switchDirections(Direction::Right);
                        prince.pushSequence(STANCE_RUNNING_TURN_1_START, STANCE_RUNNING_TURN_13_END, STANCE_RUN_REPEAT_8_END_TURN, true);
                    }
                    else if (!arduboy.pressed(LEFT_BUTTON)) {
                        prince.pushSequence(STANCE_STOPPING_1_START, STANCE_STOPPING_5_END, STANCE_UPRIGHT, true);
                    }

                }

                break;
/*
            case STANCE_SQUAT_3_LOW_POINT:

                if (prince.getDirection() == Direction::Right) {
                        
                    if (arduboy.justPressed(RIGHT_BUTTON) && arduboy.pressed(DOWN_BUTTON)) {
                        prince.pushSequence(STANCE_SQUAT_MOVE_1_START, STANCE_SQUAT_MOVE_3_END, STANCE_SQUAT_3_LOW_POINT, true);
                    }
                    else if (arduboy.pressed(RIGHT_BUTTON) && !arduboy.pressed(DOWN_BUTTON)) {
                        prince.push(STANCE_RUN_REPEAT_4, true);
                        prince.pushSequence(STANCE_SQUAT_4, STANCE_SQUAT_9, true);
                    }
                    else if (arduboy.justPressed(LEFT_BUTTON) && arduboy.pressed(DOWN_BUTTON) / *&& !this->world.isChangingDirections()* /) {
                        // this->world.switchDirections(Direction::Left);
                        prince.pushSequence(STANCE_SQUAT_ROTATE_01_START, STANCE_SQUAT_ROTATE_05_END, true);
                    }

                }
                else {
                        
                    if (arduboy.justPressed(LEFT_BUTTON) && arduboy.pressed(DOWN_BUTTON)) {
                        prince.pushSequence(STANCE_SQUAT_MOVE_1_START, STANCE_SQUAT_MOVE_3_END, STANCE_SQUAT_3_LOW_POINT, true);
                    }
                    else if (arduboy.justPressed(LEFT_BUTTON) && !arduboy.pressed(DOWN_BUTTON)) {
                        prince.push(STANCE_RUN_REPEAT_4, true);
                        prince.pushSequence(STANCE_SQUAT_4, STANCE_SQUAT_9, true);
                    }
                    else if (arduboy.justPressed(RIGHT_BUTTON) && arduboy.pressed(DOWN_BUTTON) / *&& !this->world.isChangingDirections()* /) {
                        // this->world.switchDirections(Direction::Right);
                        prince.pushSequence(STANCE_SQUAT_ROTATE_01_START, STANCE_SQUAT_ROTATE_05_END, true);
                    }
                }
                
                if (!arduboy.pressed(DOWN_BUTTON)) {
                    prince.pushSequence(STANCE_SQUAT_4, STANCE_SQUAT_10_END, STANCE_UPRIGHT, true);
                }

                break;
*/
            default: break;

        }

    }





    // Update the prince's stance ..

    if (prince.getStackFrame() == 0) {

        if (!prince.isEmpty()) {

            int xOffset = 0;
            prince.setStance(prince.pop());

            FX::seekData(static_cast<uint24_t>(Images::Prince_XOffset + ((prince.getStance() - 1) * 2)));
            xOffset = static_cast<int8_t>(FX::readPendingUInt8()) * (prince.getDirection() == Direction::Left ? -1 : 1);
            FX::readEnd();

            playerXLoc = playerXLoc + xOffset;

// Serial.println(prince.getStance());
// Serial.print("Stance: ");
// Serial.print(prince.getStance());
// Serial.print(", Direction: ");
// Serial.println((uint8_t)prince.getDirection());

            switch (prince.getStance()) {

                // case STANCE_UPRIGHT_END_CLIMB:
                //     //this->world.decLevel();
                //     prince.setStance(STANCE_UPRIGHT);
                //     break;

                case STANCE_UPRIGHT_TURN:
                    prince.setStance(STANCE_UPRIGHT);
                    prince.changeDirection();
                    break;

                // case STANCE_FALLING_3_END:
                //     // this->world.incLevel();
                //     // this->world.setY(this->world.getY() - 13);
                //     prince.setStance(STANCE_FALLING_3_ADJ);
                //     prince.setFalling(false);
                //     break;

                case STANCE_RUN_REPEAT_8_END_TURN:
                    prince.setStance(STANCE_RUN_REPEAT_8_END);
                    prince.changeDirection();
                    break;

                // case STANCE_SQUAT_ROTATE_05_END:
                //     prince.setStance(STANCE_SQUAT_3_LOW_POINT);
                //     prince.changeDirection();
                //     break;

/*
                case STANCE_SWINGING_10:
                    {
                        int8_t xOffset = 0;
                        int8_t width = 0;

                        if (prince.getDirection() == Direction::Right) {

                            xOffset = prince.getXOffset();
                            width = 12; // distance from LHS image to middle of hand

                        }
                        else {

                            xOffset = -prince.getXOffset();
                            width = -12;

                        }
printf("%i,%i,%i,%i >> %i, %i\n", this->world.getX() ,this->world.getXOffset() , width , xOffset, (this->world.getX() - width - xOffset) , this->gateSwitch.getX());
                        if (abs((this->world.getX() - width - xOffset) - (this->gateSwitch.getX() - 3 )) < 16) {
printf("do it!\n");
                            this->gateSwitch.update();

                        }

                    }
                    break;
*/

            }

        }

    }



    for (uint8_t y = 0; y < 3; y++) {

        for (uint8_t x = 0; x < 11; x++) {

            int8_t bgTile = bg[y][x];
            int8_t fgTile = fg[y][x];

            if (bgTile >= 0) {
                FX::drawBitmap(x * 12, y * 31, Images::Tile_Dungeon[Images::xRef[bgTile]], 0, dbmNormal);
            }


//            FX::drawBitmap(playerXLoc, playerYLoc, Images::Prince[prince.getStance()], 0, dbmMasked);

            // FX::drawBitmap(0, 0, Images::Tile_Dungeon_49, 0, dbmMasked);

            uint16_t stance = prince.getStance();
            uint24_t startPos = Images::Prince_Left_001 + ((stance - 1) * 364);

            if (prince.getDirection() == Direction::Left) {

//                 if (stance == STANCE_UPRIGHT) {
// //                    FX::drawBitmap(playerXLoc, playerYLoc, Images::Prince[STANCE_UPRIGHT], 0, dbmMasked);
//                     FX::drawBitmap(playerXLoc, playerYLoc, Images::Prince_Left_001 + ((STANCE_UPRIGHT - 1) * 364), 0, dbmMasked);
//                 }
//                 else {
                    // FX::drawBitmap(playerXLoc, playerYLoc, Images::Prince_Left[stance], 0, dbmMasked);
                    FX::drawBitmap(playerXLoc, playerYLoc, startPos, 0, dbmMasked);
                // }

            }
            else {

                // if (stance == STANCE_UPRIGHT) {
                //     // FX::drawBitmap(playerXLoc, playerYLoc, Images::Prince[STANCE_UPRIGHT] + (Images::Prince_Right_001 - Images::Prince_Left_001), 0, dbmMasked);
                //     // Serial.println("33333333333333333333");
                //     FX::drawBitmap(playerXLoc, playerYLoc, Images::Prince_Left_001 + ((STANCE_UPRIGHT - 1) * 364) + (Images::Prince_Right_001 - Images::Prince_Left_001), 0, dbmMasked);
                // }
                // else {
                    // Serial.println("44444444444444444444");
                    // FX::drawBitmap(playerXLoc, playerYLoc, Images::Prince[stance] + (Images::Prince_Right_001 - Images::Prince_Left_001), 0, dbmMasked);
                    FX::drawBitmap(playerXLoc, playerYLoc, startPos + (Images::Prince_Right_001 - Images::Prince_Left_001), 0, dbmMasked);
                // }

            }

            if (fgTile >= 0) {

                if (Images::xRef_IsMasked[fgTile]) {
                    // FX::drawBitmap(x * 12, y * 31, Images::Tile_Dungeon_Mask[Images::xRef[fgTile]], 0, dbmWhite);
                    FX::drawBitmap(x * 12, y * 31, Images::Tile_Dungeon[Images::xRef[fgTile]], 0, dbmMasked);

                }
                else {
                    FX::drawBitmap(x * 12, y * 31, Images::Tile_Dungeon[Images::xRef[fgTile]], 0, dbmNormal);

                }
            }

        }

    }


// FX::drawBitmap(0, -4, Images::Prince_Left_090, 0, dbmMasked);
// FX::drawBitmap(16, -4, Images::Prince_Left_091, 0, dbmMasked);
// FX::drawBitmap(32, -4, Images::Prince_Left_092, 0, dbmMasked);
// FX::drawBitmap(48, -4, Images::Prince_Left_093, 0, dbmMasked);
// uint24_t startPos = (90 - 1) * 364;
// FX::drawBitmap(0, -4, Images::Prince_Left_001 + (startPos), 0, dbmMasked);
// startPos = startPos + 364;
// FX::drawBitmap(16, -4, Images::Prince_Left_001 + (startPos), 0, dbmMasked);
// startPos = startPos + 364;
// FX::drawBitmap(32, -4, Images::Prince_Left_001 + (startPos), 0, dbmMasked);
// startPos = startPos + 364;
// FX::drawBitmap(48, -4, Images::Prince_Left_001 + (startPos), 0, dbmMasked);

    //program code


    arduboy.setTextColor(0);
    arduboy.fillRect(0, 0, 25, 8);
    arduboy.setCursor(0, 0);
    arduboy.print(prince.getStance());

    FX::enableOLED();
    arduboy.display(CLEAR_BUFFER);
    FX::disableOLED();


}
