#include "src/utils/Arduboy2Ext.h"  
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

    prince.init(18, 56, Direction::Right, STANCE_CROUCH_3_END);
    gamePlay.init(arduboy, 1);
    menu.init();

}

void game() {


    auto justPressed = arduboy.justPressedButtons();
    auto pressed = arduboy.pressedButtons();


    // Calculate screen offset ..

    if (prince.getYPrevious() <= 56 && prince.getY() > 56) {
        level.setYOffsetDir(Direction::Down);
    }
    else if (prince.getYPrevious() > 56 && prince.getY() <= 56) {
        level.setYOffsetDir(Direction::Up);
    }



    // Update the objects ..

    prince.update(level.getXLocation(), level.getYLocation());
    level.update(arduboy, prince);
    /* if (gamePlay.gameState == GameState::Game) */ gamePlay.update(arduboy);
    if (menu.update()) gamePlay.gameState = GameState::Game;
    



    #if defined(DEBUG) && defined(DEBUG_PRINCE_DETAILS)
    DEBUG_PRINT("Stance: ");
    DEBUG_PRINT(prince.getStance());
    DEBUG_PRINT(", Direction: ");
    DEBUG_PRINT((uint8_t)prince.getDirection());
    DEBUG_PRINT(", X: ");
    DEBUG_PRINTLN(prince.getX());
    #endif


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
        //                 this->prince.pushSequence(STANCE_FALLING_A_1_START, STANCE_FALLING_3_END, true);
        //                 this->prince.setStance(STANCE_FALLING_A_1_START);
        //                 break;

        //             case 2:
        //                 this->prince.clear();
        //                 this->prince.setFalling(true);
        //                 this->prince.pushSequence(STANCE_SQUAT_1_START, STANCE_SQUAT_10_END, STANCE_UPRIGHT, true);
        //                 this->prince.pushSequence(STANCE_FALLING_A_1_START, STANCE_FALLING_3_END, true);
        //                 this->prince.setStance(STANCE_FALLING_A_1_START);
        //                 break;

        //         }

        //         break;

        // }

    }
// if (arduboy.justPressed(B_BUTTON)) {
// prince.pushSequence(STANCE_RUNNING_JUMP_1_START, STANCE_RUNNING_JUMP_11_END, STANCE_RUN_START_6_END, true);    
// }

    if (gamePlay.gameState == GameState::Game && prince.isEmpty()) {

        switch (prince.getStance()) {

            case STANCE_UPRIGHT:

                if (prince.getDirection() == Direction::Right) {

                    if ((pressed & RIGHT_BUTTON) && (pressed &DOWN_BUTTON)) {

                        if (level.canMoveForward(Action::SmallStep, prince)) {

                            prince.pushSequence(STANCE_SMALL_STEP_1_START, STANCE_SMALL_STEP_6_END, STANCE_UPRIGHT, true);
                            break;

                        }

                    }
                    else if (pressed & RIGHT_BUTTON) {

                        if (level.canMoveForward(Action::Step, prince)) {

                            prince.push(STANCE_SINGLE_STEP_1_START, true);
                            break;

                        }
                        else if (level.canMoveForward(Action::SmallStep, prince)) {

                            prince.pushSequence(STANCE_SMALL_STEP_1_START, STANCE_SMALL_STEP_6_END, STANCE_UPRIGHT, true);
                            break;

                        }

                    }
                    else if (pressed & LEFT_BUTTON) {

                        prince.pushSequence(STANCE_STANDING_TURN_1_START, STANCE_STANDING_TURN_5_END, STANCE_UPRIGHT_TURN, true);
                        break;

                    }
                    else if (pressed & A_BUTTON) {

                        if (level.canMoveForward(Action::StandingJump, prince)) {
                            prince.pushSequence(STANCE_STANDING_JUMP_1_START, STANCE_STANDING_JUMP_18_END, STANCE_UPRIGHT, true);
                            break;
                        }

                    }
                    
                }
                else {

                    if ((pressed &LEFT_BUTTON) && (pressed & DOWN_BUTTON)) {

                        if (level.canMoveForward(Action::SmallStep, prince)) {
                            prince.pushSequence(STANCE_SMALL_STEP_1_START, STANCE_SMALL_STEP_6_END, STANCE_UPRIGHT, true);
                            break;
                        }

                    }
                    else if (pressed & LEFT_BUTTON) {

                        if (level.canMoveForward(Action::Step, prince)) {

                            prince.push(STANCE_SINGLE_STEP_1_START, true);
                            break;

                        }
                        else if (level.canMoveForward(Action::SmallStep, prince)) {

                            prince.pushSequence(STANCE_SMALL_STEP_1_START, STANCE_SMALL_STEP_6_END, STANCE_UPRIGHT, true);
                            break;

                        }
                        
                    }
                    else if (pressed & RIGHT_BUTTON) {

                        prince.pushSequence(STANCE_STANDING_TURN_1_START, STANCE_STANDING_TURN_5_END, STANCE_UPRIGHT_TURN, true);
                        break;

                    }
                    else if (pressed & A_BUTTON) {

                        if (level.canMoveForward(Action::StandingJump, prince)) {
                            prince.pushSequence(STANCE_STANDING_JUMP_1_START, STANCE_STANDING_JUMP_18_END, STANCE_UPRIGHT, true);
                            break;
                        }

                    }

                }

                if (pressed & DOWN_BUTTON) {
                
                    CanClimbDownResult canClimbDownResult = level.canClimbDown(prince);

                    switch (canClimbDownResult) {

                        case CanClimbDownResult::ClimbDown:

                            #if defined(DEBUG) && defined(DEBUG_PRINT_ACTION)
                            DEBUG_PRINTLN("DOWN_BUTTON, Climb down");
                            #endif

                            prince.pushSequence(STANCE_STEP_CLIMBING_15_END, STANCE_STEP_CLIMBING_1_START, STANCE_JUMP_UP_A_14_END, true);
                            break;

                        case CanClimbDownResult::StepThenClimbDown:
                            #if defined(DEBUG) && defined(DEBUG_PRINT_ACTION)
                            DEBUG_PRINTLN("DOWN_BUTTON, Step then climb down");
                            #endif

                            prince.pushSequence(STANCE_STEP_CLIMBING_15_END, STANCE_STEP_CLIMBING_1_START, STANCE_JUMP_UP_A_14_END, true);
                            prince.pushSequence(STANCE_SMALL_STEP_6_END, STANCE_SMALL_STEP_1_START, STANCE_UPRIGHT, false);
                            break;

                        case CanClimbDownResult::TurnThenClimbDown:
                            #if defined(DEBUG) && defined(DEBUG_PRINT_ACTION)
                            DEBUG_PRINTLN("DOWN_BUTTON, Step then climb down");
                            #endif

                            prince.pushSequence(STANCE_STEP_CLIMBING_15_END, STANCE_STEP_CLIMBING_1_START, STANCE_JUMP_UP_A_14_END, true);
                            prince.pushSequence(STANCE_STANDING_TURN_1_START, STANCE_STANDING_TURN_5_END, STANCE_UPRIGHT_TURN, false);
                            break;

                        case CanClimbDownResult::StepThenTurnThenClimbDown:
                            #if defined(DEBUG) && defined(DEBUG_PRINT_ACTION)
                            DEBUG_PRINTLN("DOWN_BUTTON, Step then turn then climb down");
                            #endif

                            prince.pushSequence(STANCE_STEP_CLIMBING_15_END, STANCE_STEP_CLIMBING_1_START, STANCE_JUMP_UP_A_14_END, true);
                            prince.pushSequence(STANCE_STANDING_TURN_1_START, STANCE_STANDING_TURN_5_END, STANCE_UPRIGHT_TURN, false);
                            prince.pushSequence(STANCE_SMALL_STEP_1_START, STANCE_SMALL_STEP_6_END, STANCE_UPRIGHT, false);
                            break;

                        case CanClimbDownResult::None:
                            #if defined(DEBUG) && defined(DEBUG_PRINT_ACTION)
                            DEBUG_PRINTLN("DOWN_BUTTON, Cannot climb down, squat");
                            #endif

                            gamePlay.crouchTimer++;
                            
                            if (gamePlay.crouchTimer == 4) {
                                prince.pushSequence(STANCE_CROUCH_1_START, STANCE_CROUCH_3_END, false);
                            }
                            break;

                    }


                }
                else if (pressed & UP_BUTTON) {

                    CanJumpUpResult jumpResult = level.canJumpUp(prince);

                    switch (jumpResult) {

                        case CanJumpUpResult::Jump:
                            prince.pushSequence(STANCE_JUMP_UP_A_1_START, STANCE_JUMP_UP_A_14_END, true);
                            break;

                        case CanJumpUpResult::JumpThenFall:
                            prince.pushSequence(STANCE_JUMP_UP_DROP_1_START, STANCE_JUMP_UP_DROP_5_END, STANCE_UPRIGHT, false);
                            prince.pushSequence(STANCE_JUMP_UP_A_1_START, STANCE_JUMP_UP_A_14_END, true);
                            break;

                        case CanJumpUpResult::StepThenJump:
                            prince.pushSequence(STANCE_JUMP_UP_A_1_START, STANCE_JUMP_UP_A_14_END, STANCE_UPRIGHT, true);
                            prince.pushSequence(STANCE_SMALL_STEP_1_START, STANCE_SMALL_STEP_6_END, STANCE_UPRIGHT, false);
                            break;

                        case CanJumpUpResult::TurnThenJump:
                            prince.pushSequence(STANCE_JUMP_UP_A_1_START, STANCE_JUMP_UP_A_14_END, false);
                            prince.pushSequence(STANCE_STANDING_TURN_1_START, STANCE_STANDING_TURN_5_END, STANCE_UPRIGHT_TURN, true);
                            break;

                        case CanJumpUpResult::JumpDist10:
                            prince.pushSequence(STANCE_JUMP_UP_B_1_START, STANCE_JUMP_UP_B_14_END, true);
                            break;

                        default: break;

                    }

                }

                break;

            case STANCE_JUMP_UP_A_14_END:     // Hanging on ledge  (dist 2)..
            case STANCE_JUMP_UP_B_14_END:    
            
                if (pressed & DOWN_BUTTON) {

                    prince.pushSequence(STANCE_JUMP_UP_DROP_1_START, STANCE_JUMP_UP_DROP_5_END, STANCE_UPRIGHT, true);

                }
                else if (pressed & UP_BUTTON) {

                    if (level.canJumpUp_Part2(prince)) {
                        prince.pushSequence(STANCE_STEP_CLIMBING_1_START, STANCE_STEP_CLIMBING_15_END, STANCE_UPRIGHT, true);
                    }
                    else {
                        prince.pushSequence(STANCE_STEP_CLIMBING_BLOCK_1_START, STANCE_STEP_CLIMBING_BLOCK_9_END, STANCE_UPRIGHT, true);
                        
                    }

                }

                // Drop after a period of time hanging ..

                else if(prince.getHangingCounter() == 0) {
                    prince.pushSequence(STANCE_JUMP_UP_DROP_1_START, STANCE_JUMP_UP_DROP_5_END, STANCE_UPRIGHT, true);
                }

                break;

            case STANCE_SINGLE_STEP_1_START:

                // If the user is still holding the left / right button then escalate the movement to a run ..

                if (prince.getDirection() == Direction::Right) {

                    if (pressed & RIGHT_BUTTON) {

                        if (level.canMoveForward(Action::RunStart, prince)) {
                            prince.pushSequence(STANCE_RUN_START_2, STANCE_RUN_START_6_END, true);
                        }
                        else {
                            prince.pushSequence(STANCE_SINGLE_STEP_2, STANCE_SINGLE_STEP_8_END, STANCE_UPRIGHT, true);
                        }

                    }
                    else if (!(pressed & RIGHT_BUTTON)) {
                        prince.pushSequence(STANCE_SINGLE_STEP_2, STANCE_SINGLE_STEP_8_END, STANCE_UPRIGHT, true);
                    }

                }
                else {

                    if (pressed & LEFT_BUTTON) {
                        if (level.canMoveForward(Action::RunStart, prince)) {
                            prince.pushSequence(STANCE_RUN_START_2, STANCE_RUN_START_6_END, true);
                        }
                        else {
                            prince.pushSequence(STANCE_SINGLE_STEP_2, STANCE_SINGLE_STEP_8_END, STANCE_UPRIGHT, true);
                        }                            
                    }
                    else if (!(pressed & LEFT_BUTTON)) {
                        prince.pushSequence(STANCE_SINGLE_STEP_2, STANCE_SINGLE_STEP_8_END, STANCE_UPRIGHT, true);
                    }

                }
                break;

            case STANCE_RUN_REPEAT_4:

                if (prince.getDirection() == Direction::Right) {
                        
                    if ((pressed & RIGHT_BUTTON) && (pressed & A_BUTTON)) {
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
                    else if (pressed & RIGHT_BUTTON) {

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
                    else if (pressed & LEFT_BUTTON) {

                        #if defined(DEBUG) && defined(DEBUG_PRINT_ACTION)
                        DEBUG_PRINTLN("LEFT_BUTTON, Switch Directions");
                        #endif

                        prince.pushSequence(STANCE_RUNNING_TURN_1_START, STANCE_RUNNING_TURN_13_END, STANCE_RUN_REPEAT_8_END_TURN, true);
                    }
                    else if (!(pressed  & RIGHT_BUTTON)) {

                        #if defined(DEBUG) && defined(DEBUG_PRINT_ACTION)
                        DEBUG_PRINTLN("RIGHT_BUTTON, Run Stop (2)");
                        #endif

                        prince.pushSequence(STANCE_STOPPING_1_START, STANCE_STOPPING_5_END, STANCE_UPRIGHT, true);
                    }

                }
                else {

                    if ((pressed & LEFT_BUTTON) && (pressed & A_BUTTON)) {

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
                    else if (pressed & LEFT_BUTTON) {

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
                    else if (pressed & RIGHT_BUTTON) {

                        #if defined(DEBUG) && defined(DEBUG_PRINT_ACTION)
                        DEBUG_PRINTLN("RIGHT_BUTTON, Running Start");
                        #endif

                        prince.pushSequence(STANCE_RUNNING_TURN_1_START, STANCE_RUNNING_TURN_13_END, STANCE_RUN_REPEAT_8_END_TURN, true);
                    }
                    else if (!(pressed & LEFT_BUTTON)) {

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
                                    
                    if ((pressed & RIGHT_BUTTON) && (pressed & A_BUTTON)) {
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
                    else if (pressed & RIGHT_BUTTON) {

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
                    else if (pressed & LEFT_BUTTON) {
                        // this->world.switchDirections(Direction::Left);

                        #if defined(DEBUG) && defined(DEBUG_PRINT_ACTION)
                        DEBUG_PRINTLN("LEFT_BUTTON, Running Turn");
                        #endif

                        prince.pushSequence(STANCE_RUNNING_TURN_1_START, STANCE_RUNNING_TURN_13_END, STANCE_RUN_REPEAT_8_END_TURN, true);
                    }
                    else if (!(pressed & RIGHT_BUTTON)) {

                        #if defined(DEBUG) && defined(DEBUG_PRINT_ACTION)
                        DEBUG_PRINTLN("RIGHT_BUTTON, Running Stop");
                        #endif

                        prince.pushSequence(STANCE_STOPPING_1_START, STANCE_STOPPING_5_END, STANCE_UPRIGHT, true);
                    }

                }
                else {
                                    
                    if ((pressed & LEFT_BUTTON) && (pressed & A_BUTTON)) {
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
                    else if (pressed & LEFT_BUTTON) {

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
                    else if (pressed & RIGHT_BUTTON) {

                        prince.pushSequence(STANCE_RUNNING_TURN_1_START, STANCE_RUNNING_TURN_13_END, STANCE_RUN_REPEAT_8_END_TURN, true);

                    }
                    else if (!(pressed & LEFT_BUTTON)) {

                        prince.pushSequence(STANCE_STOPPING_1_START, STANCE_STOPPING_5_END, STANCE_UPRIGHT, true);

                    }

                }

                break;

            case STANCE_CROUCH_3_END:
            case STANCE_CROUCH_HOP_7_END:

                if (!(pressed & DOWN_BUTTON) && prince.getCrouchingCounter() == 0) {

                    prince.pushSequence(STANCE_CROUCH_STAND_3, STANCE_CROUCH_STAND_12_END, STANCE_UPRIGHT, true);

                }
                else if (pressed & LEFT_BUTTON) {

                    if (level.canMoveForward(Action::CrouchHop, prince)) {
                        prince.pushSequence(STANCE_CROUCH_HOP_1_START, STANCE_CROUCH_HOP_7_END, true);
                    }

                }
                else if (pressed & RIGHT_BUTTON) {

                    if (level.canMoveForward(Action::CrouchHop, prince)) {
                        prince.pushSequence(STANCE_CROUCH_HOP_1_START, STANCE_CROUCH_HOP_7_END, true);
                    }

                }

                break;
            

            default: break;

        }

    }



    // Post input cleanup!

    if (!(pressed & DOWN_BUTTON)) {

        gamePlay.crouchTimer = 0;

    }



    // Handle menu

    switch (gamePlay.gameState) {

        case GameState::Game:

            if (justPressed & B_BUTTON) {

                gamePlay.gameState = GameState::Menu;
                menu.direction = Direction::Left;
                menu.cursor = static_cast<uint8_t>(MenuOption::Resume);

            }

            break;


        case GameState::Menu:

            if (justPressed & B_BUTTON) {

                menu.direction = Direction::Right;

            }

            if (justPressed & UP_BUTTON && menu.cursor > 0) {

                menu.cursor--;
                
            }

            if (justPressed & DOWN_BUTTON && menu.cursor < 3) {

                menu.cursor++;
                
            }

            if (justPressed & A_BUTTON) {

                switch (static_cast<MenuOption>(menu.cursor)) {

                    case MenuOption::Resume:
                        menu.direction = Direction::Right;  
                        break;

                    case MenuOption::Save:
                        menu.direction = Direction::Right;  
                        break;

                    case MenuOption::Load:
                        menu.direction = Direction::Right;  
                        break;

                    case MenuOption::MainMenu:
                        gamePlay.gameState = GameState::Title_Init;  
                        break;
                        
                }

            }   

        default: break;

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

                case STANCE_UPRIGHT_TURN:
                    prince.setStance(STANCE_UPRIGHT);
                    prince.changeDirection();
                    break;

                case STANCE_RUN_REPEAT_8_END_TURN:
                    prince.setStance(STANCE_RUN_REPEAT_8_END);
                    prince.changeDirection();
                    break;

                case STANCE_SMALL_STEP_5:
                case STANCE_SINGLE_STEP_5:
                case STANCE_RUNNING_JUMP_4:
                    {
                        if (level.canFall(prince)) {
                            prince.clear();
                            prince.pushSequence(STANCE_CROUCH_STAND_1_START, STANCE_CROUCH_STAND_12_END, STANCE_UPRIGHT, true);
                            prince.pushSequence(STANCE_FALLING_A_1_START, STANCE_FALLING_A_6_END, true);
                        }
                    }
                    break;

                case STANCE_RUNNING_JUMP_1_START:
                case STANCE_RUNNING_JUMP_10:
                    {
                        if (level.canFall(prince)) {

                            prince.clear();

                            int8_t dist = abs(level.distToEdgeOfTile(prince.getDirection(), (level.getXLocation() * 12) + prince.getX()));

                            switch (dist) {

                                case 0:
                                case 4:
                                case 8:
                                case 12:
                                    prince.pushSequence(STANCE_CROUCH_STAND_1_START, STANCE_CROUCH_STAND_12_END, STANCE_UPRIGHT, true);
                                    prince.pushSequence(STANCE_FALLING_B_1_START, STANCE_FALLING_B_6_END, true);
                                    break;

                                case 2:
                                case 6:
                                case 10:
                                    prince.pushSequence(STANCE_CROUCH_STAND_1_START, STANCE_CROUCH_STAND_12_END, STANCE_UPRIGHT, true);
                                    prince.pushSequence(STANCE_FALLING_C_1_START, STANCE_FALLING_C_6_END, true);
                                    break;

                            }

                        }

                    }
                    break;

                case STANCE_JUMP_UP_DROP_4: // Ripple collapsible floors.

                    for (uint8_t i = 0; i < Constants::NumberOfItems; i++) {
                        
                        Item &item = level.getItem(i);

                        if (item.active && item.itemType == ItemType::CollapsingFloor && item.data.collapsingFloor.frame == 0) {

                            item.data.collapsingFloor.frame = 3;

                        }

                    }

                    break;

                // case STANCE_RUNNING_JUMP_4:
                //     {
                //         if (level.canFall(prince, 10)) {
                //             prince.clear();
                //             prince.pushSequence(STANCE_CROUCH_STAND_1_START, STANCE_CROUCH_STAND_12_END, STANCE_UPRIGHT, true);
                //             prince.pushSequence(STANCE_FALLING_A_1_START, STANCE_FALLING_A_6_END, true);
                //         }
                //     }
                //     break;

                // case STANCE_RUNNING_JUMP_10:
                //     {
                //         if (level.canFall(prince, 8)) {
                //             prince.clear();
                //             prince.pushSequence(STANCE_CROUCH_STAND_1_START, STANCE_CROUCH_STAND_12_END, STANCE_UPRIGHT, true);
                //             prince.pushSequence(STANCE_FALLING_B_1_START, STANCE_FALLING_B_6_END, true);
                //         }
                //     }
                //     break;

            }

        }

    }




    // Render scene ..

    render();
    
    if (gamePlay.gameState == GameState::Menu) {
        renderMenu();
    }


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
