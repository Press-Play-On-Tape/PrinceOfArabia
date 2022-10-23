#include "src/utils/Arduboy2Ext.h"  
#include <ArduboyFX.h>  
#include "fxdata/Images.h"  
#include "fxdata/Levels.h"  

#include "src/utils/Constants.h"
#include "src/utils/Stack.h"
#include "src/entities/Entities.h"
#include "src/fonts/Font3x5.h"


void game_Init() {

    prince.init(18, 56, Direction::Right, STANCE_CROUCH_3_END, 3);          // Normal starting pos
    // prince.init(66, 56, Direction::Right, STANCE_CROUCH_3_END, 3);        // Get tonic
    // prince.init(30, 56 + Constants::TileHeight, Direction::Right, STANCE_CROUCH_3_END, 3);     // Column of climbs
    // prince.init(80, 25, Direction::Right, STANCE_CROUCH_3_END, 3);     // Top Left
    // prince.init(18, 25, Direction::Right, STANCE_CROUCH_3_END, 3);          // Long Fall
    // prince.init(18, 56, Direction::Right, STANCE_CROUCH_3_END, 3);          // problem


    gamePlay.init(arduboy, 1);
    
    level.setLevel(1);
    level.init(prince, 60, 0);  // Normal starting posa
    // level.init(prince, Constants::TileHeight, 0);   // Get tonic
//    level.init(prince, 0, 3);   // Column of climbs
    // level.init(prince, 0, 0);   // Top left
    // level.init(prince, 40, 4);  // Long Fall
    // level.init(prince, 60, 3);  // problem

    menu.init();

}

void game() {


    auto justPressed = arduboy.justPressedButtons();
    auto pressed = arduboy.pressedButtons();

    #if defined(DEBUG) && defined(DEBUG_PRINCE_DETAILS)
    DEBUG_PRINT(F("Stance: "));
    DEBUG_PRINT(prince.getStance());
    DEBUG_PRINT(F(", Direction: "));
    DEBUG_PRINT((uint8_t)prince.getDirection());
    DEBUG_PRINT(F(", X: "));
    DEBUG_PRINT(prince.getX());
    DEBUG_PRINT(F(", Y: "));
    DEBUG_PRINT(prince.getY());
    DEBUG_PRINT(F(", yOffset: "));
    DEBUG_PRINTLN(level.getYOffset());
    #endif


    if (prince.getY() - level.getYOffset() >= 56 + Constants::TileHeight) {

        prince.incY(- Constants::TileHeight * 3);
        level.setYLocation(level.getYLocation() + 3);
        level.loadMap();
        level.setYOffset(0);
        level.setYOffsetDir(Direction::None);

    }
    else if (static_cast<int8_t>(prince.getY() - level.getYOffset()) < static_cast<int8_t>(0)) {

        prince.incY(Constants::TileHeight * 3);
        level.setYLocation(level.getYLocation() - 3);
        level.loadMap();
        level.setYOffset(Constants::TileHeight);
        level.setYOffsetDir(Direction::None);

    }
    else if (prince.getX() < 0) {

        prince.incX(Constants::TileWidth * Constants::ScreenWidthInTiles);
        level.setXLocation(level.getXLocation() - 10);
        level.loadMap();

    }
    else if (prince.getX() > Constants::TileWidth * Constants::ScreenWidthInTiles) {

        prince.incX(-Constants::TileWidth * Constants::ScreenWidthInTiles);
        level.setXLocation(level.getXLocation() + 10);
        level.loadMap();

    }






    // Calculate screen offset ..

    if (prince.getYPrevious() <= 56 && prince.getY() > 56) {
        level.setYOffsetDir(Direction::Down);
    }
    else if (prince.getYPrevious() > 56 && prince.getY() <= 56) {
        level.setYOffsetDir(Direction::Up);
    }



    if (justPressed & B_BUTTON) {
//prince.pushSequence(STANCE_RUNNING_JUMP_1_START, STANCE_RUNNING_JUMP_11_END, STANCE_RUN_REPEAT_4, true);
// prince.pushSequence(STANCE_RUNNING_JUMP_1_START, STANCE_RUNNING_JUMP_11_END, STANCE_RUN_START_6_END, true);
// //
        switch (level.distToEdgeOfTile(prince.getDirection(),  (level.getXLocation() * Constants::TileWidth) + prince.getX())) {

            case 0:
                prince.incX(2);
                break;

            case 1:
            case 5:
            case 9:
                prince.incX(1);
                break;

            case 3:
            case 7:
            case 11:
                prince.incX(-1);
                break;

            case 2:
            case 6:
            case 10:
                break;

            case 4:
            case 8:
                prince.incX(2);
                break;

        }

    }




    // Update the objects ..

    prince.update(level.getXLocation(), level.getYLocation());
    level.update(arduboy, prince);
    /* if (gamePlay.gameState == GameState::Game) */ gamePlay.update(arduboy);
    if (menu.update()) gamePlay.gameState = GameState::Game;
    

    // ---------------------------------------------------------------------------------------------------------------------------------------
    //  
    //  If prince queue is empty then accept input from player ..
    //
    // ---------------------------------------------------------------------------------------------------------------------------------------

    if (gamePlay.gameState == GameState::Game && prince.isEmpty()) {

        switch (prince.getStance()) {

            case STANCE_UPRIGHT:

                if (prince.getDirection() == Direction::Right) {

                    if ((pressed & RIGHT_BUTTON) && (pressed & DOWN_BUTTON)) {

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

                    if ((pressed & LEFT_BUTTON) && (pressed & DOWN_BUTTON)) {

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
                            DEBUG_PRINTLN(F("DOWN_BUTTON, Climb down Pos 2"));
                            #endif

                            prince.pushSequence(STANCE_STEP_CLIMBING_15_END, STANCE_STEP_CLIMBING_1_START, STANCE_JUMP_UP_A_14_END, true);
                            break;

                        case CanClimbDownResult::StepThenClimbDown:
                            #if defined(DEBUG) && defined(DEBUG_PRINT_ACTION)
                            DEBUG_PRINTLN(F("DOWN_BUTTON, Step then climb down Pos 2"));
                            #endif

                            prince.pushSequence(STANCE_STEP_CLIMBING_15_END, STANCE_STEP_CLIMBING_1_START, STANCE_JUMP_UP_A_14_END, true);
                            prince.pushSequence(STANCE_SMALL_STEP_6_END, STANCE_SMALL_STEP_1_START, STANCE_UPRIGHT, false);
                            break;

                        case CanClimbDownResult::TurnThenClimbDown:
                            #if defined(DEBUG) && defined(DEBUG_PRINT_ACTION)
                            DEBUG_PRINTLN(F("DOWN_BUTTON, Step then climb down Pos 2"));
                            #endif

                            prince.pushSequence(STANCE_STEP_CLIMBING_15_END, STANCE_STEP_CLIMBING_1_START, STANCE_JUMP_UP_A_14_END, true);
                            prince.pushSequence(STANCE_STANDING_TURN_1_START, STANCE_STANDING_TURN_5_END, STANCE_UPRIGHT_TURN, false);
                            break;

                        case CanClimbDownResult::StepThenTurnThenClimbDown:
                            #if defined(DEBUG) && defined(DEBUG_PRINT_ACTION)
                            DEBUG_PRINTLN(F("DOWN_BUTTON, Step then turn then climb down Pos 2"));
                            #endif

                            prince.pushSequence(STANCE_STEP_CLIMBING_15_END, STANCE_STEP_CLIMBING_1_START, STANCE_JUMP_UP_A_14_END, true);
                            prince.pushSequence(STANCE_STANDING_TURN_1_START, STANCE_STANDING_TURN_5_END, STANCE_UPRIGHT_TURN, false);
                            prince.pushSequence(STANCE_SMALL_STEP_1_START, STANCE_SMALL_STEP_6_END, STANCE_UPRIGHT, false);
                            break;

                        default:
                            #if defined(DEBUG) && defined(DEBUG_PRINT_ACTION)
                            DEBUG_PRINTLN(F("DOWN_BUTTON, Cannot climb down, squat"));
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
                            prince.pushSequence(STANCE_JUMP_UP_DROP_A_1_START, STANCE_JUMP_UP_DROP_A_5_END, STANCE_UPRIGHT, false);
                            prince.pushSequence(STANCE_JUMP_UP_A_1_START, STANCE_JUMP_UP_A_14_END, true);
                            break;

                        case CanJumpUpResult::JumpThenFall_CollapseFloor:
                            {
                                int8_t tileXIdx = level.coordToTileIndexX(prince.getDirection(), prince.getPosition().x) + (prince.getDirection() == Direction::Left ? -1 : 1);
                                int8_t tileYIdx = level.coordToTileIndexY(prince.getDirection(), prince.getPosition().y) - 1;
                                uint8_t itemIdx = level.getItem(ItemType::CollapsingFloor, tileXIdx, tileYIdx);

                                if (itemIdx != Constants::NoItemFound) {

                                    Item &item = level.getItem(itemIdx);
                                    item.data.collapsingFloor.timeToFall = 52;

                                }

                                prince.pushSequence(STANCE_JUMP_UP_DROP_A_1_START, STANCE_JUMP_UP_DROP_A_5_END, STANCE_UPRIGHT, false);
                                prince.pushSequence(STANCE_JUMP_UP_A_1_START, STANCE_JUMP_UP_A_14_END, true);
                            }
                            break;

                        case CanJumpUpResult::StepThenJumpThenFall_CollapseFloor:
                            {
                                int8_t tileXIdx = level.coordToTileIndexX(prince.getDirection(), prince.getPosition().x) + (prince.getDirection() == Direction::Left ? -1 : 1);
                                int8_t tileYIdx = level.coordToTileIndexY(prince.getDirection(), prince.getPosition().y) - 1;
                                uint8_t itemIdx = level.getItem(ItemType::CollapsingFloor, tileXIdx, tileYIdx);

                                if (itemIdx != Constants::NoItemFound) {

                                    Item &item = level.getItem(itemIdx);
                                    item.data.collapsingFloor.timeToFall = 52;

                                }

                                prince.pushSequence(STANCE_JUMP_UP_DROP_A_1_START, STANCE_JUMP_UP_DROP_A_5_END, STANCE_UPRIGHT, false);
                                prince.pushSequence(STANCE_JUMP_UP_A_1_START, STANCE_JUMP_UP_A_14_END, true);
                                prince.pushSequence(STANCE_SMALL_STEP_1_START, STANCE_SMALL_STEP_6_END, STANCE_UPRIGHT, false);
                            }
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

                    CanClimbDownPart2Result climbDownResult = level.canClimbDown_Part2(prince, 0);

                    switch (climbDownResult) {

                        case CanClimbDownPart2Result::Level_1_Under:
                            prince.pushSequence(STANCE_JUMP_UP_DROP_B_1_START, STANCE_JUMP_UP_DROP_B_5_END, STANCE_UPRIGHT, true);
                            break;

                        case CanClimbDownPart2Result::Level_1:
                            prince.pushSequence(STANCE_JUMP_UP_DROP_A_1_START, STANCE_JUMP_UP_DROP_A_5_END, STANCE_UPRIGHT, true);
                            break;

                        case CanClimbDownPart2Result::Falling:
                            prince.setFalling(1);
                            prince.pushSequence(STANCE_JUMP_UP_DROP_C_1_START, STANCE_JUMP_UP_DROP_C_5_END, true);
                            break;

                        default:
                            break;

                    }

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

                    CanClimbDownPart2Result climbDownResult = level.canClimbDown_Part2(prince, 0);

                    switch (climbDownResult) {

                        case CanClimbDownPart2Result::Level_1_Under:
                            prince.pushSequence(STANCE_JUMP_UP_DROP_B_1_START, STANCE_JUMP_UP_DROP_B_5_END, STANCE_UPRIGHT, true);
                            break;

                        case CanClimbDownPart2Result::Level_1:
                            prince.pushSequence(STANCE_JUMP_UP_DROP_A_1_START, STANCE_JUMP_UP_DROP_A_5_END, STANCE_UPRIGHT, true);
                            break;

                        case CanClimbDownPart2Result::Falling:
                            prince.setFalling(1);
                            prince.pushSequence(STANCE_JUMP_UP_DROP_C_1_START, STANCE_JUMP_UP_DROP_C_5_END, true);
                            break;

                        default:
                            break;

                    }

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

                        if (true) {

                            prince.pushSequence(STANCE_RUNNING_JUMP_1_START, STANCE_RUNNING_JUMP_11_END, STANCE_RUN_START_6_END, true);

                        }
                        else {

                            prince.pushSequence(STANCE_STOPPING_1_START, STANCE_STOPPING_5_END, STANCE_UPRIGHT, true);
                        }
                    }
                    else if (pressed & RIGHT_BUTTON) {

                        if (level.canMoveForward(Action::RunRepeat, prince)) {

                            #if defined(DEBUG) && defined(DEBUG_PRINT_ACTION)
                            DEBUG_PRINTLN(F("RIGHT_BUTTON, Run Repeat (1)"));
                            #endif

                            prince.pushSequence(STANCE_RUN_REPEAT_5_MID, STANCE_RUN_REPEAT_8_END, true);
                        }
                        else {

                            #if defined(DEBUG) && defined(DEBUG_PRINT_ACTION)
                            DEBUG_PRINTLN(F("RIGHT_BUTTON, Run Stop (1)"));
                            #endif

                            prince.pushSequence(STANCE_STOPPING_1_START, STANCE_STOPPING_5_END, STANCE_UPRIGHT, true);
                        }

                    }
                    else if (pressed & LEFT_BUTTON) {

                        #if defined(DEBUG) && defined(DEBUG_PRINT_ACTION)
                        DEBUG_PRINTLN(F("LEFT_BUTTON, Switch Directions"));
                        #endif

                        prince.pushSequence(STANCE_RUNNING_TURN_1_START, STANCE_RUNNING_TURN_13_END, STANCE_RUN_REPEAT_8_END_TURN, true);
                    }
                    else if (!(pressed  & RIGHT_BUTTON)) {

                        #if defined(DEBUG) && defined(DEBUG_PRINT_ACTION)
                        DEBUG_PRINTLN(F("RIGHT_BUTTON, Run Stop (2)"));
                        #endif

                        prince.pushSequence(STANCE_STOPPING_1_START, STANCE_STOPPING_5_END, STANCE_UPRIGHT, true);
                    }

                }
                else {

                    if ((pressed & LEFT_BUTTON) && (pressed & A_BUTTON)) {

                        // if (this->world.canMoveForward(Action::RunJump)) {
                        if (true) {

                            #if defined(DEBUG) && defined(DEBUG_PRINT_ACTION)
                            DEBUG_PRINTLN(F("LEFT_BUTTON & A_BUTTON, Running Jumpp"));
                            #endif

                            prince.pushSequence(STANCE_RUNNING_JUMP_1_START, STANCE_RUNNING_JUMP_11_END, STANCE_RUN_START_6_END, true);

                        }
                        else {

                            #if defined(DEBUG) && defined(DEBUG_PRINT_ACTION)
                            DEBUG_PRINTLN(F("LEFT_BUTTON & A_BUTTON, Running Stop (3)"));
                            #endif

                            prince.pushSequence(STANCE_STOPPING_1_START, STANCE_STOPPING_5_END, STANCE_UPRIGHT, true);
                        }
                    }
                    else if (pressed & LEFT_BUTTON) {

                        if (level.canMoveForward(Action::RunRepeat, prince)) {

                            #if defined(DEBUG) && defined(DEBUG_PRINT_ACTION)
                            DEBUG_PRINTLN(F("LEFT_BUTTON, Running Repeat"));
                            #endif

                            prince.pushSequence(STANCE_RUN_REPEAT_5_MID, STANCE_RUN_REPEAT_8_END, true);
                        }
                        else {

                            #if defined(DEBUG) && defined(DEBUG_PRINT_ACTION)
                            DEBUG_PRINTLN(F("LEFT_BUTTON, Running Stop"));
                            #endif

                            prince.pushSequence(STANCE_STOPPING_1_START, STANCE_STOPPING_5_END, STANCE_UPRIGHT, true);
                        }                        
                    }
                    else if (pressed & RIGHT_BUTTON) {

                        #if defined(DEBUG) && defined(DEBUG_PRINT_ACTION)
                        DEBUG_PRINTLN(F("RIGHT_BUTTON, Running Start"));
                        #endif

                        prince.pushSequence(STANCE_RUNNING_TURN_1_START, STANCE_RUNNING_TURN_13_END, STANCE_RUN_REPEAT_8_END_TURN, true);
                    }
                    else if (!(pressed & LEFT_BUTTON)) {

                        #if defined(DEBUG) && defined(DEBUG_PRINT_ACTION)
                        DEBUG_PRINTLN(F("LEFT_BUTTON, Running Stop (4)"));
                        #endif

                        prince.pushSequence(STANCE_STOPPING_1_START, STANCE_STOPPING_5_END, STANCE_UPRIGHT, true);
                    }

                }
                break;

            case STANCE_RUN_START_6_END:
            case STANCE_RUN_REPEAT_8_END:
            case STANCE_RUN_REPEAT_8_END_TURN:

                if (prince.getDirection() == Direction::Right) {
                                    
                    if ((pressed & RIGHT_BUTTON) && (pressed & A_BUTTON)) {

                        if (true) {

                            prince.pushSequence(STANCE_RUNNING_JUMP_1_START, STANCE_RUNNING_JUMP_11_END, STANCE_RUN_REPEAT_4, true);

                        }
                        else {

                            prince.pushSequence(STANCE_STOPPING_1_START, STANCE_STOPPING_5_END, STANCE_UPRIGHT, true);

                        }

                    }
                    else if (pressed & RIGHT_BUTTON) {

                        if (level.canMoveForward(Action::RunRepeat, prince)) {

                            #if defined(DEBUG) && defined(DEBUG_PRINT_ACTION)
                            DEBUG_PRINTLN(F("RIGHT_BUTTON, Running Repeat"));
                            #endif
                            
                            prince.pushSequence(STANCE_RUN_REPEAT_1_START, STANCE_RUN_REPEAT_4, true);
                        }
                        else {

                            #if defined(DEBUG) && defined(DEBUG_PRINT_ACTION)
                            DEBUG_PRINTLN(F("RIGHT_BUTTON, Running Stop"));
                            #endif

                            prince.pushSequence(STANCE_STOPPING_1_START, STANCE_STOPPING_5_END, STANCE_UPRIGHT, true);
                        }

                    }
                    else if (pressed & LEFT_BUTTON) {
                        // this->world.switchDirections(Direction::Left);

                        #if defined(DEBUG) && defined(DEBUG_PRINT_ACTION)
                        DEBUG_PRINTLN(F("LEFT_BUTTON, Running Turn"));
                        #endif

                        prince.pushSequence(STANCE_RUNNING_TURN_1_START, STANCE_RUNNING_TURN_13_END, STANCE_RUN_REPEAT_8_END_TURN, true);
                    }
                    else if (!(pressed & RIGHT_BUTTON)) {

                        #if defined(DEBUG) && defined(DEBUG_PRINT_ACTION)
                        DEBUG_PRINTLN(F("RIGHT_BUTTON, Running Stop"));
                        #endif

                        prince.pushSequence(STANCE_STOPPING_1_START, STANCE_STOPPING_5_END, STANCE_UPRIGHT, true);
                    }

                }
                else {
                                    
                    if ((pressed & LEFT_BUTTON) && (pressed & A_BUTTON)) {
                        // if (this->world.canMoveForward(Action::RunJump)) {
                        if (true) {

                            prince.pushSequence(STANCE_RUNNING_JUMP_1_START, STANCE_RUNNING_JUMP_11_END, STANCE_RUN_REPEAT_4, true);

                        }
                        else {
// printf("Run Jump 4 FAIL\n");
                            prince.pushSequence(STANCE_STOPPING_1_START, STANCE_STOPPING_5_END, STANCE_UPRIGHT, true);
                        }
                    }
                    else if (pressed & LEFT_BUTTON) {

                        if (level.canMoveForward(Action::RunRepeat, prince)) {

                            #if defined(DEBUG) && defined(DEBUG_PRINT_ACTION)
                            DEBUG_PRINTLN(F("LEFT_BUTTON, Running Repeat"));
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

                if (prince.getCrouchingCounter() == 0) {

                    if (!(pressed & DOWN_BUTTON)) {

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
                    else if (pressed & A_BUTTON) {

                        uint8_t itemIdx = level.canReachItem(prince, ItemType::Potion_Small);

                        if (itemIdx != Constants::NoItemFound) {

                            Item &item = level.getItem(itemIdx);
                            item.active = false;
                            prince.pushSequence(STANCE_DRINK_TONIC_1_START, STANCE_DRINK_TONIC_15_END, STANCE_UPRIGHT, true);

                        }

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

            if (justPressed & B_BUTTON)                         menu.direction = Direction::Right;
            if (justPressed & UP_BUTTON && menu.cursor > 0)     menu.cursor--;
            if (justPressed & DOWN_BUTTON && menu.cursor < 3)   menu.cursor++;

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


    // Have we collided with a wall?




    // ---------------------------------------------------------------------------------------------------------------------------------------
    //  
    //  Queue handling ..
    //
    // ---------------------------------------------------------------------------------------------------------------------------------------

    if (prince.getStackFrame() == 0) {

        if (!prince.isEmpty()) {

            Point offset;
            // int8_t xOffset = 0;
            // int8_t yOffset = 0;

            int16_t newStance = prince.pop();
            prince.setStance(abs(newStance));


            // Handle specific events .. such as turning at end of sequences, falling after a land, etc.

            switch (prince.getStance()) {

                case STANCE_UPRIGHT_TURN:
                    newStance = STANCE_UPRIGHT;
                    prince.setStance(STANCE_UPRIGHT);
                    prince.changeDirection();
                    break;

                case STANCE_RUN_REPEAT_8_END_TURN:
                    prince.changeDirection();
                    break;

                case STANCE_SMALL_STEP_5:
                case STANCE_SINGLE_STEP_5:
                case STANCE_RUNNING_JUMP_4:

                    if (level.canFall(prince)) {

                        prince.clear();
                        prince.pushSequence(STANCE_CROUCH_STAND_1_START, STANCE_CROUCH_STAND_12_END, STANCE_UPRIGHT, true);
                        prince.pushSequence(STANCE_FALLING_A_1_START, STANCE_FALLING_A_6_END, true);
                    }

                    break;

                case STANCE_RUNNING_JUMP_1_START:
                case STANCE_RUNNING_JUMP_10:
                    
                    if (level.canFall(prince)) {

                        prince.clear();

                        int8_t dist = abs(level.distToEdgeOfTile(prince.getDirection(), (level.getXLocation() * Constants::TileWidth) + prince.getX()));

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

                    break;

                case STANCE_JUMP_UP_DROP_A_4: // Ripple collapsible floors.
                case STANCE_JUMP_UP_DROP_B_4: 

                    for (uint8_t i = 0; i < Constants::NumberOfItems; i++) {
                        
                        Item &item = level.getItem(i);

                        if (item.active && item.itemType == ItemType::CollapsingFloor && item.data.collapsingFloor.frame == 0) {

                            item.data.collapsingFloor.frame = 3;

                        }

                    }

                    break;

                case STANCE_JUMP_UP_DROP_C_5_END: // Falling after climbing down ..

                    if (level.canFall(prince)) { // Fall some more

                        prince.incFalling();
                        prince.pushSequence(STANCE_JUMP_UP_DROP_C_1_START, STANCE_JUMP_UP_DROP_C_5_END, true);

                    }
                    else {

                        switch (prince.getFalling()) {

                            case 1:     // OK but lose some health as well
                                prince.pushSequence(STANCE_CROUCH_STAND_1_START, STANCE_CROUCH_STAND_12_END, STANCE_UPRIGHT, true);
                                prince.pushSequence(STANCE_FALLING_D_1_START, STANCE_FALLING_D_2_END, true);
                                prince.decHealth(1);
                                break;

                            default:    // Dead!
                                prince.pushSequence(STANCE_FALLING_DEAD_1_START, STANCE_FALLING_DEAD_3_END, true);
                                prince.setHealth(0);
                                break;

                        }
                        
                    }

                    break;

            }

            getStance_Offsets(prince.getDirection(), offset, prince.getStance());
            prince.incX(offset.x * (newStance < 0 ? -1 : 1));
            prince.incY(offset.y * (newStance < 0 ? -1 : 1));



            // Has the player collided with a wall?

            level.collideWithWall(prince);


            #if defined(DEBUG) && defined(DEBUG_PRINCE_DETAILS)
            DEBUG_PRINT(F("Stance: "));
            DEBUG_PRINT(prince.getStance());
            DEBUG_PRINT(F(", Direction: "));
            DEBUG_PRINT((uint8_t)prince.getDirection());
            DEBUG_PRINT(F(", xOffset: "));
            DEBUG_PRINT(offset.x);
            DEBUG_PRINT(F(", yOffset: "));
            DEBUG_PRINTLN(offset.y);
            #endif

        }

    }



    // Trigger floors 
    {

        int8_t tileXIdx = level.coordToTileIndexX(prince.getDirection(), prince.getPosition().x);
        int8_t tileYIdx = level.coordToTileIndexY(prince.getDirection(), prince.getPosition().y);

        for (uint8_t i = 0; i < Constants::NumberOfItems; i++) {
            
            Item &item = level.getItem(i);

            if (item.active && item.itemType == ItemType::CollapsingFloor && item.x == tileXIdx && item.y == tileYIdx && item.data.collapsingFloor.timeToFall == 0) {

                item.data.collapsingFloor.timeToFall = 12;

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
    font3x5.print(level.coordToTileIndexX(prince.getDirection(), (level.getXLocation() * Constants::TileWidth) + prince.getX()));
    font3x5.print(F(" "));
    font3x5.print((level.getXLocation() * Constants::TileWidth) + prince.getX());
    font3x5.print(F(" y"));
    font3x5.print(level.coordToTileIndexY(prince.getDirection(), (level.getYLocation() * Constants::TileHeight) + prince.getY()));
    font3x5.print(F(" "));
 //   font3x5.print((level.getYLocation() * Constants::TileHeight) + prince.getY());
    font3x5.print(prince.getY());
    font3x5.print(F(" dst"));
    font3x5.print(level.distToEdgeOfTile(prince.getDirection(),  (level.getXLocation() * Constants::TileWidth) + prince.getX()));
    #endif

}

void getStance_Offsets(Direction direction, Point &offset, int16_t stance) {

    uint16_t idx = (stance - 1) * 2;
    offset.x = static_cast<int8_t>(pgm_read_byte(&Constants::Prince_XOffset[idx])) * (direction == Direction::Left ? -1 : 1) * (stance < 0 ? -1 : 1);
    offset.y = static_cast<int8_t>(pgm_read_byte(&Constants::Prince_XOffset[idx + 1])) * (stance < 0 ? -1 : 1);

}