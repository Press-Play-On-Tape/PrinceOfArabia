#include <Arduboy2.h>   
#include <ArduboyFX.h>  
#include "fxdata/Images.h"  
#include "fxdata/Levels.h"  

#include "src/utils/Constants.h"
#include "src/utils/Stack.h"
#include "src/entities/Entities.h"
#include "src/fonts/Font3x5.h"


void game_Init() {

    level.setLevel(1);
    level.init(60, 0);

    prince.init(18, 56);
    gameState = GameState::Game;

}

void game() {


    // Update the objects ..

    prince.update();

    for (uint8_t i = 0; i < NUMBER_OF_ITEMS; i++) {

        Item &item = level.getItem(i);

        if (item.active) {

            switch (item.itemType) {

                case ItemType::Gate:
                    if (item.data.gate.closingDelay > 0) {
                        item.data.gate.closingDelay--;
                    }
                    else {

                        if (item.data.gate.position > 0 && arduboy.getFrameCount(3)) {

                            item.data.gate.position--;
                        }
                    }
                    break;

                case ItemType::Torch:
                    if (arduboy.getFrameCount(3)) {
                        item.data.torch.frame = (++item.data.torch.frame) % 5;
                    }
                    break;

                default: break;

            }

        }
    }



    #if defined(DEBUG) && defined(DEBUG_PRINCE_DETAILS)
    DEBUG_PRINTLN("----------------------");
    DEBUG_PRINT("Stance: ");
    DEBUG_PRINT(prince.getStance());
    DEBUG_PRINT(", Direction: ");
    DEBUG_PRINT((uint8_t)prince.getDirection());
    DEBUG_PRINT(", X: ");
    DEBUG_PRINTLN(prince.getX());
    #endif

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
// if (arduboy.justPressed(B_BUTTON)) {
// prince.pushSequence(STANCE_RUNNING_JUMP_1_START, STANCE_RUNNING_JUMP_11_END, STANCE_RUN_START_6_END, true);    
// }

    if (prince.isEmpty()) {

        switch (prince.getStance()) {

            case STANCE_UPRIGHT:

                if (prince.getDirection() == Direction::Right) {

                    if (arduboy.pressed(RIGHT_BUTTON) && arduboy.pressed(DOWN_BUTTON)) {

                        if (level.canMoveForward(Action::SmallStep, prince)) {
                            prince.pushSequence(STANCE_SMALL_STEP_1_START, STANCE_SMALL_STEP_6_END, STANCE_UPRIGHT, true);
                        }

                    }
                    else if (arduboy.pressed(RIGHT_BUTTON)) {

                        if (level.canMoveForward(Action::Step, prince)) {
                            prince.push(STANCE_SINGLE_STEP_1_START, true);
                        }
                        else if (level.canMoveForward(Action::SmallStep, prince)) {
                            prince.pushSequence(STANCE_SMALL_STEP_1_START, STANCE_SMALL_STEP_6_END, STANCE_UPRIGHT, true);
                        }

                    }
                    else if (arduboy.pressed(LEFT_BUTTON)) {

                        prince.pushSequence(STANCE_STANDING_TURN_1_START, STANCE_STANDING_TURN_5_END, STANCE_UPRIGHT_TURN, true);

                    }
                    else if (arduboy.pressed(A_BUTTON)) {

                        if (level.canMoveForward(Action::StandingJump, prince)) {
                            prince.pushSequence(STANCE_STANDING_JUMP_1_START, STANCE_STANDING_JUMP_18_END, STANCE_UPRIGHT, true);
                        }

                    }
                    
                }
                else {

                    if (arduboy.pressed(LEFT_BUTTON) && arduboy.pressed(DOWN_BUTTON)) {

                        if (level.canMoveForward(Action::SmallStep, prince)) {
                            prince.pushSequence(STANCE_SMALL_STEP_1_START, STANCE_SMALL_STEP_6_END, STANCE_UPRIGHT, true);
                        }

                    }
                    else if (arduboy.pressed(LEFT_BUTTON)) {

                        if (level.canMoveForward(Action::Step, prince)) {
                            prince.push(STANCE_SINGLE_STEP_1_START, true);
                        }
                        else if (level.canMoveForward(Action::SmallStep, prince)) {
                            prince.pushSequence(STANCE_SMALL_STEP_1_START, STANCE_SMALL_STEP_6_END, STANCE_UPRIGHT, true);
                        }
                        
                    }
                    else if (arduboy.pressed(RIGHT_BUTTON)) {

                        prince.pushSequence(STANCE_STANDING_TURN_1_START, STANCE_STANDING_TURN_5_END, STANCE_UPRIGHT_TURN, true);

                    }
                    else if (arduboy.pressed(A_BUTTON)) {

                        if (level.canMoveForward(Action::StandingJump, prince)) {
                            prince.pushSequence(STANCE_STANDING_JUMP_1_START, STANCE_STANDING_JUMP_18_END, STANCE_UPRIGHT, true);
                        }

                    }


                }

                if (arduboy.pressed(DOWN_BUTTON)) {
                
                    CanClimbDownResult canClimbDownResult = level.canClimbDown(prince);

                    switch (canClimbDownResult) {

                        case CanClimbDownResult::ClimbDown:

                            #if defined(DEBUG) && defined(DEBUG_PRINT_ACTION)
                            DEBUG_PRINTLN("DOWN_BUTTON, Climb down");
                            #endif

                            prince.pushSequence(STANCE_STEP_CLIMBING_15_END, STANCE_STEP_CLIMBING_1_START, STANCE_JUMP_UP_14_END, true);
                            break;

                        case CanClimbDownResult::StepThenClimbDown:
                            #if defined(DEBUG) && defined(DEBUG_PRINT_ACTION)
                            DEBUG_PRINTLN("DOWN_BUTTON, Step then climb down");
                            #endif

                            prince.pushSequence(STANCE_STEP_CLIMBING_15_END, STANCE_STEP_CLIMBING_1_START, STANCE_JUMP_UP_14_END, true);
                            // prince.pushSequence(STANCE_SMALL_STEP_1_START, STANCE_SMALL_STEP_6_END, STANCE_UPRIGHT, false);
                            prince.pushSequence(STANCE_SMALL_STEP_6_END, STANCE_SMALL_STEP_1_START, STANCE_UPRIGHT, false);
                            break;

                        case CanClimbDownResult::TurnThenClimbDown:
                            #if defined(DEBUG) && defined(DEBUG_PRINT_ACTION)
                            DEBUG_PRINTLN("DOWN_BUTTON, Step then climb down");
                            #endif

                            prince.pushSequence(STANCE_STEP_CLIMBING_15_END, STANCE_STEP_CLIMBING_1_START, STANCE_JUMP_UP_14_END, true);
                            prince.pushSequence(STANCE_STANDING_TURN_1_START, STANCE_STANDING_TURN_5_END, STANCE_UPRIGHT_TURN, false);
                            break;

                        case CanClimbDownResult::StepThenTurnThenClimbDown:
                            #if defined(DEBUG) && defined(DEBUG_PRINT_ACTION)
                            DEBUG_PRINTLN("DOWN_BUTTON, Step then turn then climb down");
                            #endif

                            prince.pushSequence(STANCE_STEP_CLIMBING_15_END, STANCE_STEP_CLIMBING_1_START, STANCE_JUMP_UP_14_END, true);
                            prince.pushSequence(STANCE_STANDING_TURN_1_START, STANCE_STANDING_TURN_5_END, STANCE_UPRIGHT_TURN, false);
                            prince.pushSequence(STANCE_SMALL_STEP_1_START, STANCE_SMALL_STEP_6_END, STANCE_UPRIGHT, false);
                            break;

                        case CanClimbDownResult::None:
                            break;

                    }


                }
                else if (arduboy.pressed(UP_BUTTON)) {

                    CanJumpResult jumpResult = level.canJumpUp(prince);

                    switch (jumpResult) {

                        case CanJumpResult::Jump:
                            prince.pushSequence(STANCE_JUMP_UP_1_START, STANCE_JUMP_UP_14_END, true);
                            break;

                        case CanJumpResult::JumpThenFall:
                            prince.pushSequence(STANCE_JUMP_UP_DROP_1_START, STANCE_JUMP_UP_DROP_5_END, STANCE_UPRIGHT, false);
                            prince.pushSequence(STANCE_JUMP_UP_1_START, STANCE_JUMP_UP_14_END, true);
                            break;

                        case CanJumpResult::StepThenJump:
                            prince.pushSequence(STANCE_JUMP_UP_1_START, STANCE_JUMP_UP_14_END, false);
                            prince.pushSequence(STANCE_SMALL_STEP_1_START, STANCE_SMALL_STEP_6_END, STANCE_UPRIGHT, true);
                            break;

                        case CanJumpResult::TurnThenJump:
                            prince.pushSequence(STANCE_JUMP_UP_1_START, STANCE_JUMP_UP_14_END, false);
                            prince.pushSequence(STANCE_STANDING_TURN_1_START, STANCE_STANDING_TURN_5_END, STANCE_UPRIGHT_TURN, true);
                            break;

                        default: break;

                    }

                }

                break;

            case STANCE_JUMP_UP_14_END:

                if (arduboy.pressed(DOWN_BUTTON)) {
                    prince.pushSequence(STANCE_JUMP_UP_DROP_1_START, STANCE_JUMP_UP_DROP_5_END, STANCE_UPRIGHT, true);
                }
                else if (arduboy.pressed(UP_BUTTON)) {
                    prince.pushSequence(STANCE_STEP_CLIMBING_1_START, STANCE_STEP_CLIMBING_15_END, STANCE_UPRIGHT, true);
                }

                // Drop after a period of time hanging ..

                else if(prince.getHangingCounter() == 0) {
                    prince.pushSequence(STANCE_JUMP_UP_DROP_1_START, STANCE_JUMP_UP_DROP_5_END, STANCE_UPRIGHT, true);
                }

                break;

            case STANCE_SINGLE_STEP_1_START:

                if (prince.getDirection() == Direction::Right) {
// printf("canMoveForward STANCE_SINGLE_STEP_1_START 1\n");
                    if (arduboy.pressed(RIGHT_BUTTON)) {
                        if (level.canMoveForward(Action::RunStart, prince)) {
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
                        if (level.canMoveForward(Action::RunStart, prince)) {
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

                        if (level.canMoveForward(Action::RunRepeat, prince)) {

                            #if defined(DEBUG) && defined(DEBUG_PRINT_ACTION)
                            DEBUG_PRINTLN("RIGHT_BUTTON, Run Repeat (1)");
                            #endif

                            prince.pushSequence(STANCE_RUN_REPEAT_5_MID, STANCE_RUN_REPEAT_8_END, true);
                        }
                        else {

                            #if defined(DEBUG) && defined(DEBUG_PRINT_ACTION)
                            DEBUG_PRINTLN("RIGHT_BUTTON, Run Stop (1)");
                            #endif

                            prince.pushSequence(STANCE_STOPPING_1_START, STANCE_STOPPING_5_END, STANCE_UPRIGHT, true);
                        }

                    }
                    else if (arduboy.pressed(LEFT_BUTTON)) {

                        #if defined(DEBUG) && defined(DEBUG_PRINT_ACTION)
                        DEBUG_PRINTLN("LEFT_BUTTON, Switch Directions");
                        #endif

                        prince.pushSequence(STANCE_RUNNING_TURN_1_START, STANCE_RUNNING_TURN_13_END, STANCE_RUN_REPEAT_8_END_TURN, true);
                    }
                    else if (!arduboy.pressed(RIGHT_BUTTON)) {

                        #if defined(DEBUG) && defined(DEBUG_PRINT_ACTION)
                        DEBUG_PRINTLN("RIGHT_BUTTON, Run Stop (2)");
                        #endif

                        prince.pushSequence(STANCE_STOPPING_1_START, STANCE_STOPPING_5_END, STANCE_UPRIGHT, true);
                    }

                }
                else {

                    if (arduboy.pressed(LEFT_BUTTON) && arduboy.pressed(A_BUTTON)) {

                        // if (this->world.canMoveForward(Action::RunJump)) {
                        if (true) {

                            #if defined(DEBUG) && defined(DEBUG_PRINT_ACTION)
                            DEBUG_PRINTLN("LEFT_BUTTON & A_BUTTON, Running Jumpp");
                            #endif


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

                            #if defined(DEBUG) && defined(DEBUG_PRINT_ACTION)
                            DEBUG_PRINTLN("LEFT_BUTTON & A_BUTTON, Running Stop (3)");
                            #endif

                            prince.pushSequence(STANCE_STOPPING_1_START, STANCE_STOPPING_5_END, STANCE_UPRIGHT, true);
                        }
                    }
                    else if (arduboy.pressed(LEFT_BUTTON)) {

                        if (level.canMoveForward(Action::RunRepeat, prince)) {

                            #if defined(DEBUG) && defined(DEBUG_PRINT_ACTION)
                            DEBUG_PRINTLN("LEFT_BUTTON, Running Repeat");
                            #endif

                            prince.pushSequence(STANCE_RUN_REPEAT_5_MID, STANCE_RUN_REPEAT_8_END, true);
                        }
                        else {

                            #if defined(DEBUG) && defined(DEBUG_PRINT_ACTION)
                            DEBUG_PRINTLN("LEFT_BUTTON, Running Stop");
                            #endif

                            prince.pushSequence(STANCE_STOPPING_1_START, STANCE_STOPPING_5_END, STANCE_UPRIGHT, true);
                        }                        
                    }
                    else if (arduboy.pressed(RIGHT_BUTTON)) {

                        #if defined(DEBUG) && defined(DEBUG_PRINT_ACTION)
                        DEBUG_PRINTLN("RIGHT_BUTTON, Running Start");
                        #endif
                        // this->world.switchDirections(Direction::Right);
                        prince.pushSequence(STANCE_RUNNING_TURN_1_START, STANCE_RUNNING_TURN_13_END, STANCE_RUN_REPEAT_8_END_TURN, true);
                    }
                    else if (!arduboy.pressed(LEFT_BUTTON)) {

                        #if defined(DEBUG) && defined(DEBUG_PRINT_ACTION)
                        DEBUG_PRINTLN("LEFT_BUTTON, Running Stop (4)");
                        #endif

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

                        if (level.canMoveForward(Action::RunRepeat, prince)) {

                            #if defined(DEBUG) && defined(DEBUG_PRINT_ACTION)
                            DEBUG_PRINTLN("RIGHT_BUTTON, Running Repeat");
                            #endif
                            
                            prince.pushSequence(STANCE_RUN_REPEAT_1_START, STANCE_RUN_REPEAT_4, true);
                        }
                        else {

                            #if defined(DEBUG) && defined(DEBUG_PRINT_ACTION)
                            DEBUG_PRINTLN("RIGHT_BUTTON, Running Stop");
                            #endif

                            prince.pushSequence(STANCE_STOPPING_1_START, STANCE_STOPPING_5_END, STANCE_UPRIGHT, true);
                        }

                    }
                    else if (arduboy.pressed(LEFT_BUTTON)) {
                        // this->world.switchDirections(Direction::Left);

                        #if defined(DEBUG) && defined(DEBUG_PRINT_ACTION)
                        DEBUG_PRINTLN("LEFT_BUTTON, Running Turn");
                        #endif

                        prince.pushSequence(STANCE_RUNNING_TURN_1_START, STANCE_RUNNING_TURN_13_END, STANCE_RUN_REPEAT_8_END_TURN, true);
                    }
                    else if (!arduboy.pressed(RIGHT_BUTTON)) {

                        #if defined(DEBUG) && defined(DEBUG_PRINT_ACTION)
                        DEBUG_PRINTLN("RIGHT_BUTTON, Running Stop");
                        #endif

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

                        if (level.canMoveForward(Action::RunRepeat, prince)) {

                            #if defined(DEBUG) && defined(DEBUG_PRINT_ACTION)
                            DEBUG_PRINTLN("LEFT_BUTTON, Running Repeat");
                            #endif

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
            int yOffset = 0;

            int16_t newStance = prince.pop();
            prince.setStance(abs(newStance));

            FX::seekData(static_cast<uint24_t>(Images::Prince_XOffset + ((prince.getStance() - 1) * 2)));
            xOffset = static_cast<int8_t>(FX::readPendingUInt8()) * (prince.getDirection() == Direction::Left ? -1 : 1) * (newStance < 0 ? -1 : 1);
            yOffset = static_cast<int8_t>(FX::readPendingUInt8()) * (newStance < 0 ? -1 : 1);
            FX::readEnd();

            prince.incX(xOffset);
            prince.incY(yOffset);

            #if defined(DEBUG) && defined(DEBUG_PRINCE_DETAILS)
            DEBUG_PRINTLN(prince.getStance());
            DEBUG_PRINT("Stance: ");
            DEBUG_PRINT(prince.getStance());
            DEBUG_PRINT(", Direction: ");
            DEBUG_PRINT((uint8_t)prince.getDirection());
            DEBUG_PRINT(", xOffset: ");
            DEBUG_PRINT(xOffset);
            DEBUG_PRINT(", yOffset: ");
            DEBUG_PRINTLN(yOffset);
            #endif

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




    // Render scene ..

    render();


    #if defined(DEBUG) && defined(DEBUG_ONSCREEN_DETAILS)
    font3x5.setTextColor(0);
    arduboy.fillRect(0, 0, 128, 7);
    font3x5.setCursor(0, 0);
    font3x5.print(F("St"));
    font3x5.print(prince.getStance());
    font3x5.print(F(" px"));
    font3x5.print(prince.getX());
    font3x5.print(F(" x"));
    font3x5.print(level.coordToTileIndexX(prince.getDirection(), (level.getXLocation() * 12) + prince.getX()));
    font3x5.print(F(" "));
    font3x5.print((level.getXLocation() * 12) + prince.getX());
    font3x5.print(F(" y"));
    font3x5.print(level.coordToTileIndexY(prince.getDirection(), (level.getYLocation() * 31) + prince.getY()));
    font3x5.print(F(" "));
    font3x5.print((level.getYLocation() * 31) + prince.getY());
    font3x5.print(F(" dst"));
    font3x5.print(level.distToEdgeOfTile(prince.getDirection(),  (level.getXLocation() * 12) + prince.getX()));
    #endif

}
