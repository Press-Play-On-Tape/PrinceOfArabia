#include "src/utils/Arduboy2Ext.h"  
#include <ArduboyFX.h>  
#include "fxdata/Images.h"  
#include "fxdata/Levels.h"  

#include "src/utils/Constants.h"
#include "src/utils/Stack.h"
#include "src/entities/Entities.h"
#include "src/fonts/Font3x5.h"


void game_Init() {

    // prince.init(66, 25, Direction::Right, Stance::Crouch_3_End, 3);          // Upper gate
    // prince.init(70, 25 + 31, Direction::Right, Stance::Crouch_3_End, 3);          // Under collapsible floor
    // prince.init(58 +36, 56, Direction::Left, Stance::Crouch_3_End, 3);          // Exit Seq
    prince.init(6, 56, Direction::Right, Stance::Crouch_3_End, 3);          // Normal starting pos
    // prince.init(104, 56, Direction::Left, Stance::Crouch_3_End, 3);          // Both floor types
    // prince.init(86, 87, Direction::Right, Stance::Crouch_3_End, 3);          // Normal starting pos but next to drop floor 3rd floor
    // prince.init(70, 25, Direction::Left, Stance::Crouch_3_End, 3);          // Under collapsible floor
    // prince.init(66, 56, Direction::Right, Stance::Crouch_3_End, 3);        // Get tonic
//    prince.init(50, 87, Direction::Left, Stance::Crouch_3_End, 3);     // Column of climbs
    // prince.init(80, 25, Direction::Right, Stance::Crouch_3_End, 3);     // Top Left
    // prince.init(18, 25, Direction::Right,Stance:: Crouch_3_End, 3);          // Long Fall
    // prince.init(18, 56, Direction::Right, Stance::Crouch_3_End, 3);          // problem
    // prince.init(98, 87, Direction::Left, Stance::Crouch_3_End, 3);          // At bottom of tthree level drop.


    gamePlay.init(arduboy, 1);
    
    level.setLevel(1);
    // level.init(prince, 50, 0);  // Upper Gate
    // level.init(prince, 40, 3);  // Under collapsible floor
    // level.init(prince, 80, 3);  // Exit Seq
    level.init(prince, 60, 0);  // Normal starting posa
    // level.init(prince, 20, 3);  // Both floor types
    // level.init(prince, 60, 0);  //Normal starting pos but next to drop floor 3rd floor
    // level.init(prince, 50, 3);  // Under collapsible floor
    // level.init(prince, Constants::TileHeight, 0);   // Get tonic
    // level.init(prince, 0, 3);   // Column of climbs
    // level.init(prince, 0, 0);   // Top left
    // level.init(prince, 40, 4);  // Long Fall
    // level.init(prince, 60, 3);  // problem
    // level.init(prince, 30, 6); // At bottom of tthree level drop.

    gamePlay.gameState = GameState::Game;
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


    // Have we scrolled to another screen ?

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


    // Remove later !!!
    //
    if (justPressed & B_BUTTON) {

        switch (level.distToEdgeOfTile(prince.getDirection(), (level.getXLocation() * Constants::TileWidth) + prince.getX())) {

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
    //
    // REmove later !!




    // Update the objects ..

    prince.update(level.getXLocation(), level.getYLocation());
    level.update(arduboy);
    /* if (gamePlay.gameState == GameState::Game) */ gamePlay.update(arduboy);

    if (menu.update()) gamePlay.gameState = GameState::Game;
    

    // ---------------------------------------------------------------------------------------------------------------------------------------
    //  
    //  If prince queue is empty then accept input from player ..
    //
    // ---------------------------------------------------------------------------------------------------------------------------------------

    if (gamePlay.gameState == GameState::Game && prince.isEmpty()) {


        // Check to see if we can leave the level, otherise 

        if (!leaveLevel(prince, level)) {

            switch (prince.getStance()) {

                case Stance::Upright:

                    if (prince.getDirection() == Direction::Right) {

                        if ((pressed & RIGHT_BUTTON) && (pressed & DOWN_BUTTON)) {

                            if (level.canMoveForward(prince, Action::SmallStep)) {

                                prince.pushSequence(Stance::Small_Step_1_Start, Stance::Small_Step_6_End, Stance::Upright, true);
                                break;

                            }

                        }
                        else if (pressed & RIGHT_BUTTON) {

                            if (level.canMoveForward(prince, Action::Step)) {

                                prince.push(Stance::Single_Step_1_Start, true);
                                break;

                            }
                            else if (level.canMoveForward(prince, Action::SmallStep)) {

                                prince.pushSequence(Stance::Small_Step_1_Start, Stance::Small_Step_6_End, Stance::Upright, true);
                                break;

                            }

                        }
                        else if (pressed & LEFT_BUTTON) {

                            prince.pushSequence(Stance::Standing_Turn_1_Start, Stance::Standing_Turn_5_End, Stance::Upright_Turn, true);
                            break;

                        }
                        else if (pressed & A_BUTTON) {

                            if (level.canMoveForward(prince, Action::StandingJump)) {
                                prince.pushSequence(Stance::Standing_Jump_1_Start, Stance::Standing_Jump_18_End, Stance::Upright, true);
                                break;
                            }

                        }
                        
                    }
                    else {

                        if ((pressed & LEFT_BUTTON) && (pressed & DOWN_BUTTON)) {

                            if (level.canMoveForward(prince, Action::SmallStep)) {
                                prince.pushSequence(Stance::Small_Step_1_Start, Stance::Small_Step_6_End, Stance::Upright, true);
                                break;
                            }

                        }
                        else if (pressed & LEFT_BUTTON) {

                            if (level.canMoveForward(prince, Action::Step)) {

                                prince.push(Stance::Single_Step_1_Start, true);
                                break;

                            }
                            else if (level.canMoveForward(prince, Action::SmallStep)) {

                                prince.pushSequence(Stance::Small_Step_1_Start, Stance::Small_Step_6_End, Stance::Upright, true);
                                break;

                            }
                            
                        }
                        else if (pressed & RIGHT_BUTTON) {

                            prince.pushSequence(Stance::Standing_Turn_1_Start, Stance::Standing_Turn_5_End, Stance::Upright_Turn, true);
                            break;

                        }
                        else if (pressed & A_BUTTON) {

                            if (level.canMoveForward(prince, Action::StandingJump)) {
                                prince.pushSequence(Stance::Standing_Jump_1_Start, Stance::Standing_Jump_18_End, Stance::Upright, true);
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

                                prince.pushSequence(Stance::Step_Climbing_15_End, Stance::Step_Climbing_1_Start, Stance::Jump_Up_A_14_End, true);
                                break;

                            case CanClimbDownResult::StepThenClimbDown:
                                #if defined(DEBUG) && defined(DEBUG_PRINT_ACTION)
                                DEBUG_PRINTLN(F("DOWN_BUTTON, Step then climb down Pos 2"));
                                #endif

                                prince.pushSequence(Stance::Step_Climbing_15_End, Stance::Step_Climbing_1_Start, Stance::Jump_Up_A_14_End, true);
                                prince.pushSequence(Stance::Small_Step_6_End, Stance::Small_Step_1_Start, Stance::Upright, false);
                                break;

                            case CanClimbDownResult::TurnThenClimbDown:
                                #if defined(DEBUG) && defined(DEBUG_PRINT_ACTION)
                                DEBUG_PRINTLN(F("DOWN_BUTTON, Step then climb down Pos 2"));
                                #endif

                                prince.pushSequence(Stance::Step_Climbing_15_End, Stance::Step_Climbing_1_Start, Stance::Jump_Up_A_14_End, true);
                                prince.pushSequence(Stance::Standing_Turn_1_Start, Stance::Standing_Turn_5_End, Stance::Upright_Turn, false);
                                break;

                            case CanClimbDownResult::StepThenTurnThenClimbDown:
                                #if defined(DEBUG) && defined(DEBUG_PRINT_ACTION)
                                DEBUG_PRINTLN(F("DOWN_BUTTON, Step then turn then climb down Pos 2"));
                                #endif

                                prince.pushSequence(Stance::Step_Climbing_15_End, Stance::Step_Climbing_1_Start, Stance::Jump_Up_A_14_End, true);
                                prince.pushSequence(Stance::Standing_Turn_1_Start, Stance::Standing_Turn_5_End, Stance::Upright_Turn, false);
                                prince.pushSequence(Stance::Small_Step_1_Start, Stance::Small_Step_6_End, Stance::Upright, false);
                                break;

                            default:
                                #if defined(DEBUG) && defined(DEBUG_PRINT_ACTION)
                                DEBUG_PRINTLN(F("DOWN_BUTTON, Cannot climb down, squat"));
                                #endif

                                gamePlay.crouchTimer++;
                                
                                if (gamePlay.crouchTimer == 4) {
                                    prince.pushSequence(Stance::Crouch_1_Start, Stance::Crouch_3_End, false);
                                }
                                break;

                        }

                    }
                    else if (pressed & UP_BUTTON) {

                        CanJumpUpResult jumpResult = level.canJumpUp(prince);

                        switch (jumpResult) {

                            case CanJumpUpResult::Jump:
                                prince.pushSequence(Stance::Jump_Up_A_1_Start, Stance::Jump_Up_A_14_End, true);
                                break;

                            case CanJumpUpResult::JumpThenFall:
                                pushJumpUp_Drop(prince);
                                break;

                            case CanJumpUpResult::JumpThenFall_CollapseFloor:
                                {
                                    int8_t tileXIdx = level.coordToTileIndexX(prince.getDirection(), prince.getPosition().x) + prince.getDirectionOffset(1);
                                    int8_t tileYIdx = level.coordToTileIndexY(prince.getDirection(), prince.getPosition().y) - 1;
                                    uint8_t itemIdx = level.getItem(ItemType::CollapsingFloor, tileXIdx, tileYIdx);

                                    if (itemIdx != Constants::NoItemFound) {

                                        Item &item = level.getItem(itemIdx);
                                        item.data.collapsingFloor.timeToFall = 52;

                                    }

                                    pushJumpUp_Drop(prince);

                                }
                                break;

                            case CanJumpUpResult::JumpThenFall_CollapseFloorAbove:
                                {
                                    int8_t tileXIdx = level.coordToTileIndexX(prince.getDirection(), prince.getPosition().x);
                                    int8_t tileYIdx = level.coordToTileIndexY(prince.getDirection(), prince.getPosition().y) - 1;
                                    uint8_t itemIdx = level.getItem(ItemType::CollapsingFloor, tileXIdx, tileYIdx);

                                    if (itemIdx != Constants::NoItemFound) {

                                        Item &item = level.getItem(itemIdx);
                                        item.data.collapsingFloor.timeToFall = 52;

                                    }

                                    pushJumpUp_Drop(prince);

                                }
                                break;

                            case CanJumpUpResult::StepThenJumpThenFall_CollapseFloor:
                                {
                                    int8_t tileXIdx = level.coordToTileIndexX(prince.getDirection(), prince.getPosition().x) + prince.getDirectionOffset(1);
                                    int8_t tileYIdx = level.coordToTileIndexY(prince.getDirection(), prince.getPosition().y) - 1;
                                    uint8_t itemIdx = level.getItem(ItemType::CollapsingFloor, tileXIdx, tileYIdx);

                                    if (itemIdx != Constants::NoItemFound) {

                                        Item &item = level.getItem(itemIdx);
                                        item.data.collapsingFloor.timeToFall = 52;

                                    }

                                    pushJumpUp_Drop(prince);
                                    prince.pushSequence(Stance::Small_Step_1_Start, Stance::Small_Step_6_End, Stance::Upright, false);

                                }
                                break;

                            case CanJumpUpResult::StepThenJump:
                                prince.pushSequence(Stance::Jump_Up_A_1_Start, Stance::Jump_Up_A_14_End, Stance::Upright, true);
                                prince.pushSequence(Stance::Small_Step_1_Start, Stance::Small_Step_6_End, Stance::Upright, false);
                                break;

                            case CanJumpUpResult::TurnThenJump:
                                prince.pushSequence(Stance::Jump_Up_A_1_Start, Stance::Jump_Up_A_14_End, false);
                                prince.pushSequence(Stance::Standing_Turn_1_Start, Stance::Standing_Turn_5_End, Stance::Upright_Turn, true);
                                break;

                            case CanJumpUpResult::JumpDist10:
                                prince.pushSequence(Stance::Jump_Up_B_1_Start, Stance::Jump_Up_B_14_End, true);
                                break;

                            default: break;

                        }

                    }

                    break;

                case Stance::Jump_Up_A_14_End:     // Hanging on ledge  (dist 2)..
                case Stance::Jump_Up_B_14_End:    
                
                    if (pressed & DOWN_BUTTON) {

                        CanClimbDownPart2Result climbDownResult = level.canClimbDown_Part2(prince, 0);

                        switch (climbDownResult) {

                            case CanClimbDownPart2Result::Level_1_Under:
                                prince.pushSequence(Stance::Jump_Up_Drop_B_1_Start, Stance::Jump_Up_Drop_B_5_End, Stance::Upright, true);
                                break;

                            case CanClimbDownPart2Result::Level_1:
                                prince.pushSequence(Stance::Jump_Up_Drop_A_1_Start, Stance::Jump_Up_Drop_A_5_End, Stance::Upright, true);
                                break;

                            case CanClimbDownPart2Result::Falling:
// Serial.pintln("B setFalling(1)");                        
                                prince.setFalling(1);
                                prince.pushSequence(Stance::Jump_Up_Drop_C_1_Start, Stance::Jump_Up_Drop_C_5_End, true);
                                break;

                            default:
                                break;

                        }

                    }
                    else if (pressed & UP_BUTTON) {

                        if (level.canJumpUp_Part2(prince)) {
                            prince.pushSequence(Stance::Step_Climbing_1_Start, Stance::Step_Climbing_15_End, Stance::Upright, true);
                        }
                        else {
                            prince.pushSequence(Stance::Step_Climbing_Block_1_Start, Stance::Step_Climbing_Block_9_End, Stance::Upright, true);                        
                        }

                    }

                    // Drop after a period of time hanging ..

                    else if(prince.getHangingCounter() == 0) {

                        CanClimbDownPart2Result climbDownResult = level.canClimbDown_Part2(prince, 0);

                        switch (climbDownResult) {

                            case CanClimbDownPart2Result::Level_1_Under:
                                prince.pushSequence(Stance::Jump_Up_Drop_B_1_Start, Stance::Jump_Up_Drop_B_5_End, Stance::Upright, true);
                                break;

                            case CanClimbDownPart2Result::Level_1:
                                prince.pushSequence(Stance::Jump_Up_Drop_A_1_Start, Stance::Jump_Up_Drop_A_5_End, Stance::Upright, true);
                                break;

                            case CanClimbDownPart2Result::Falling:
// Serial.pintln("C setFalling(1)");    
                                prince.setFalling(1);
                                prince.pushSequence(Stance::Jump_Up_Drop_C_1_Start, Stance::Jump_Up_Drop_C_5_End, true);
                                break;

                            default:
                                break;

                        }

                    }

                    break;

                case Stance::Single_Step_1_Start:

                    // If the user is still holding the left / right button then escalate the movement to a run ..

                    if (prince.getDirection() == Direction::Right) {

                        if (pressed & RIGHT_BUTTON) {

                            if (level.canMoveForward(prince, Action::RunStart)) {
                                prince.pushSequence(Stance::Run_Start_2, Stance::Run_Start_6_End, true);
                            }
                            else {
                                prince.pushSequence(Stance::Single_Step_2, Stance::Single_Step_8_End, Stance::Upright, true);
                            }

                        }
                        else if (!(pressed & RIGHT_BUTTON)) {
                            prince.pushSequence(Stance::Single_Step_2, Stance::Single_Step_8_End, Stance::Upright, true);
                        }

                    }
                    else {

                        if (pressed & LEFT_BUTTON) {

                            if (level.canMoveForward(prince, Action::RunStart)) {
                                prince.pushSequence(Stance::Run_Start_2, Stance::Run_Start_6_End, true);
                            }
                            else {
                                prince.pushSequence(Stance::Single_Step_2, Stance::Single_Step_8_End, Stance::Upright, true);
                            }     
                                                
                        }
                        else if (!(pressed & LEFT_BUTTON)) {
                            prince.pushSequence(Stance::Single_Step_2, Stance::Single_Step_8_End, Stance::Upright, true);
                        }

                    }
                    break;

                case Stance::Run_Repeat_4:

                    if (prince.getDirection() == Direction::Right) {
                            
                        if ((pressed & RIGHT_BUTTON) && (pressed & A_BUTTON)) {

                            #if defined(DEBUG) && defined(DEBUG_ACTION_RUNJUMP)
                            DEBUG_PRINTLN(F("LEFT_BUTTON & A_BUTTON, Running Jump from Run_Repeat_4"));
                            #endif

                            processRunJump(prince, level);

                        }
                        else if (pressed & RIGHT_BUTTON) {

                            if (level.canMoveForward(prince, Action::RunRepeat)) {

                                #if defined(DEBUG) && defined(DEBUG_PRINT_ACTION)
                                DEBUG_PRINTLN(F("RIGHT_BUTTON, Run Repeat (1)"));
                                #endif

                                prince.pushSequence(Stance::Run_Repeat_5_Mid, Stance::Run_Repeat_8_End, true);
                            }
                            else {

                                #if defined(DEBUG) && defined(DEBUG_PRINT_ACTION)
                                DEBUG_PRINTLN(F("RIGHT_BUTTON, Run Stop (1)"));
                                #endif

                                prince.pushSequence(Stance::Stopping_1_Start, Stance::Stopping_5_End, Stance::Upright, true);
                            }

                        }
                        else if (pressed & LEFT_BUTTON) {

                            #if defined(DEBUG) && defined(DEBUG_PRINT_ACTION)
                            DEBUG_PRINTLN(F("LEFT_BUTTON, Switch Directions"));
                            #endif

                            prince.pushSequence(Stance::Running_Turn_1_Start, Stance::Running_Turn_13_End, Stance::Run_Repeat_8_End_Turn, true);
                        }
                        else if (!(pressed  & RIGHT_BUTTON)) {

                            #if defined(DEBUG) && defined(DEBUG_PRINT_ACTION)
                            DEBUG_PRINTLN(F("RIGHT_BUTTON, Run Stop (2)"));
                            #endif

                            prince.pushSequence(Stance::Stopping_1_Start, Stance::Stopping_5_End, Stance::Upright, true);
                        }

                    }
                    else {

                        if ((pressed & LEFT_BUTTON) && (pressed & A_BUTTON)) {

                            #if defined(DEBUG) && defined(DEBUG_ACTION_RUNJUMP)
                            DEBUG_PRINTLN(F("LEFT_BUTTON & A_BUTTON, Running Jump from Run_Repeat_4"));
                            #endif
                            processRunJump(prince, level);

                        }
                        else if (pressed & LEFT_BUTTON) {

                            if (level.canMoveForward(prince, Action::RunRepeat)) {

                                #if defined(DEBUG) && defined(DEBUG_PRINT_ACTION)
                                DEBUG_PRINTLN(F("LEFT_BUTTON, Running Repeat"));
                                #endif

                                prince.pushSequence(Stance::Run_Repeat_5_Mid, Stance::Run_Repeat_8_End, true);
                            }
                            else {

                                #if defined(DEBUG) && defined(DEBUG_PRINT_ACTION)
                                DEBUG_PRINTLN(F("LEFT_BUTTON, Running Stop"));
                                #endif

                                prince.pushSequence(Stance::Stopping_1_Start,Stance:: Stopping_5_End, Stance::Upright, true);
                            }                        
                        }
                        else if (pressed & RIGHT_BUTTON) {

                            #if defined(DEBUG) && defined(DEBUG_PRINT_ACTION)
                            DEBUG_PRINTLN(F("RIGHT_BUTTON, Running Start"));
                            #endif

                            prince.pushSequence(Stance::Running_Turn_1_Start, Stance::Running_Turn_13_End, Stance::Run_Repeat_8_End_Turn, true);
                        }
                        else if (!(pressed & LEFT_BUTTON)) {

                            #if defined(DEBUG) && defined(DEBUG_PRINT_ACTION)
                            DEBUG_PRINTLN(F("LEFT_BUTTON, Running Stop (4)"));
                            #endif

                            prince.pushSequence(Stance::Stopping_1_Start, Stance::Stopping_5_End, Stance::Upright, true);
                        }

                    }
                    break;

                case Stance::Run_Start_6_End:
                case Stance::Run_Repeat_8_End:
                case Stance::Run_Repeat_8_End_Turn:

                    if (prince.getDirection() == Direction::Right) {
                                        
                        if ((pressed & RIGHT_BUTTON) && (pressed & A_BUTTON)) {

                            #if defined(DEBUG) && defined(DEBUG_ACTION_RUNJUMP)
                            DEBUG_PRINTLN(F("LEFT_BUTTON & A_BUTTON, Running Jump from Run_Start_6_End, Run_Repeat_8_End or Run_Repeat_8_End_Turn"));
                            #endif

                            processRunJump(prince, level);

                        }
                        else if (pressed & RIGHT_BUTTON) {

                            if (level.canMoveForward(prince, Action::RunRepeat)) {

                                #if defined(DEBUG) && defined(DEBUG_PRINT_ACTION)
                                DEBUG_PRINTLN(F("RIGHT_BUTTON, Running Repeat"));
                                #endif
                                
                                prince.pushSequence(Stance::Run_Repeat_1_Start, Stance::Run_Repeat_4, true);
                            }
                            else {

                                #if defined(DEBUG) && defined(DEBUG_PRINT_ACTION)
                                DEBUG_PRINTLN(F("RIGHT_BUTTON, Running Stop"));
                                #endif

                                prince.pushSequence(Stance::Stopping_1_Start, Stance::Stopping_5_End, Stance::Upright, true);
                            }

                        }
                        else if (pressed & LEFT_BUTTON) {

                            #if defined(DEBUG) && defined(DEBUG_PRINT_ACTION)
                            DEBUG_PRINTLN(F("LEFT_BUTTON, Running Turn"));
                            #endif

                            prince.pushSequence(Stance::Running_Turn_1_Start, Stance::Running_Turn_13_End, Stance::Run_Repeat_8_End_Turn, true);
                        }
                        else if (!(pressed & RIGHT_BUTTON)) {

                            #if defined(DEBUG) && defined(DEBUG_PRINT_ACTION)
                            DEBUG_PRINTLN(F("RIGHT_BUTTON, Running Stop"));
                            #endif

                            prince.pushSequence(Stance::Stopping_1_Start, Stance::Stopping_5_End, Stance::Upright, true);
                        }

                    }
                    else {
                                        
                        if ((pressed & LEFT_BUTTON) && (pressed & A_BUTTON)) {

                            #if defined(DEBUG) && defined(DEBUG_ACTION_RUNJUMP)
                            DEBUG_PRINTLN(F("LEFT_BUTTON & A_BUTTON, Running Jump from Run_Start_6_End, Run_Repeat_8_End or Run_Repeat_8_End_Turn"));
                            #endif

                            processRunJump(prince, level);

                        }
                        else if (pressed & LEFT_BUTTON) {

                            if (level.canMoveForward(prince, Action::RunRepeat)) {

                                #if defined(DEBUG) && defined(DEBUG_PRINT_ACTION)
                                DEBUG_PRINTLN(F("LEFT_BUTTON, Running Repeat"));
                                #endif

                                prince.pushSequence(Stance::Run_Repeat_1_Start, Stance::Run_Repeat_4, true);

                            }
                            else {
                                prince.pushSequence(Stance::Stopping_1_Start, Stance::Stopping_5_End, Stance::Upright, true);
                            }         

                        }
                        else if (pressed & RIGHT_BUTTON) {

                            prince.pushSequence(Stance::Running_Turn_1_Start, Stance::Running_Turn_13_End, Stance::Run_Repeat_8_End_Turn, true);

                        }
                        else if (!(pressed & LEFT_BUTTON)) {

                            prince.pushSequence(Stance::Stopping_1_Start, Stance::Stopping_5_End, Stance::Upright, true);

                        }

                    }

                    break;

                case Stance::Crouch_3_End:
                case Stance::Crouch_HOP_7_End:

                    if (prince.getCrouchingCounter() == 0) {

                        if (!(pressed & DOWN_BUTTON)) {

                            prince.pushSequence(Stance::Crouch_Stand_3, Stance::Crouch_Stand_12_End, Stance::Upright, true);

                        }
                        else if ((pressed & LEFT_BUTTON) || (pressed & RIGHT_BUTTON)) {

                            if (level.canMoveForward(prince, Action::CrouchHop)) {
                                prince.pushSequence(Stance::Crouch_HOP_1_Start, Stance::Crouch_HOP_7_End, true);
                            }

                        }
                        else if (pressed & A_BUTTON) {

                            uint8_t itemIdx = level.canReachItem(prince, ItemType::Potion_Small);

                            if (itemIdx != Constants::NoItemFound) {

                                Item &item = level.getItem(itemIdx);
                                item.itemType = ItemType::None;
                                prince.pushSequence(Stance::Drink_Tonic_1_Start, Stance::Drink_Tonic_15_End, Stance::Upright, true);

                                break;

                            }

                            itemIdx = level.canReachItem(prince, ItemType::Sword);

                            if (itemIdx != Constants::NoItemFound) {

                                Item &item = level.getItem(itemIdx);
                                item.itemType = ItemType::None;
                                prince.setSword(true);
                                prince.pushSequence(Stance::Pickup_Sword_1_Start, Stance::Pickup_Sword_16_End, Stance::Upright, true);

                            }

                        }

                    }

                    break;
                

                default: break;

            }

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


    // ---------------------------------------------------------------------------------------------------------------------------------------
    //  
    //  Queue handling ..
    //
    // ---------------------------------------------------------------------------------------------------------------------------------------

    if (prince.getStackFrame() == 0) {

        if (!prince.isEmpty()) {

            Point offset;

            int16_t newStance = prince.pop();
            prince.setStance(abs(newStance));


            // Handle specific events .. such as turning at end of sequences, falling after a land, etc.

            switch (prince.getStance()) {

                case Stance::Leave_Gate_14_End:
                    gamePlay.gameState = GameState::Title_Init;
                    break;

                case Stance::Upright_Turn:
                    newStance = Stance::Upright;
                    prince.setStance(Stance::Upright);
                    prince.changeDirection();
                    break;

                case Stance::Run_Repeat_8_End_Turn:
                    prince.changeDirection();
                    break;

                case Stance::Jump_Up_Drop_A_4: // Ripple collapsible floors.
                case Stance::Jump_Up_Drop_B_4: 

                    for (uint8_t i = 2; i < Constants::NumberOfItems; i++) {
                        
                        Item &item = level.getItem(i);

                        if (item.itemType == ItemType::CollapsingFloor && item.data.collapsingFloor.frame == 0) {

                            item.data.collapsingFloor.frame = 3;

                        }

                    }

                    break;

                case Stance::Jump_Up_Drop_C_5_End: // Falling after climbing down ..

                    if (level.canFall(prince)) { // Fall some more

// Serial.pint("D incFalling() from ");    
// Serial.pint(prince.getFalling());    
                        prince.incFalling();
// Serial.pint(" to ");    
// Serial.pintln(prince.getFalling());    
                        prince.pushSequence(Stance::Jump_Up_Drop_C_1_Start, Stance::Jump_Up_Drop_C_5_End, true);

                    }
                    else {

                        uint8_t itemIdx = activateSpikes(prince, 32);

                        if (itemIdx == Constants::NoItemFound) {

                            switch (prince.getFalling()) {

                                case 1:
                                    prince.pushSequence(Stance::Crouch_Stand_1_Start, Stance::Crouch_Stand_12_End, Stance::Upright, true);
                                    break;

                                case 2:
                                    initFlash(prince, level);
                                    prince.pushSequence(Stance::Crouch_Stand_1_Start, Stance::Crouch_Stand_12_End, Stance::Upright, true);
                                    prince.pushSequence(Stance::Falling_Injured_1_Start, Stance::Falling_Injured_2_End, true);
                                    prince.decHealth(1);
                                    break;

                                default:    // Dead!
                                    prince.pushSequence(Stance::Falling_Dead_1_Start, Stance::Falling_Dead_3_End, true);
                                    prince.setHealth(0);
                                    break;

                            }

                        }
                        else {

                            prince.pushSequence(Stance::Falling_Dead_1_Start, Stance::Falling_Dead_3_End, true);
                            prince.setHealth(0);

                        }
                        
                    }

                    break;

                // case Stance::Falling_SmallStep_5_Check_CanFall:
                // case Stance::Falling_RunningJump_5_Check_CanFall:
                // case Stance::Falling_C_5_Check_CanFall:
                // case Stance::Falling_StandingJump_5_Check_CanFall:
                // case Stance::Falling_SingleStep_5_Check_CanFall:
                case Stance::Falling_Down_5_End:
                case Stance::Falling_StepWalkRun_P0_4_8_5_Check_CanFall:
                case Stance::Falling_StepWalkRun_P1_5_9_5_Check_CanFall:
                case Stance::Falling_StepWalkRun_P2_6_10_5_Check_CanFall:
                case Stance::Falling_StepWalkRun_P3_7_11_5_Check_CanFall:
                case Stance::Collide_Wall_P2_Start_End:
                case Stance::Collide_Wall_P1_Start_End:
                case Stance::Collide_Wall_P0_Start_End:
                case Stance::Collide_Wall_M1_Start_End:
                case Stance::Collide_Wall_M2_Start_End:

                    if (level.canFallSomeMore(prince)) { // Fall some more

                        #if defined(DEBUG) && defined(DEBUG_ACTION_CANJUMPUP)
                        DEBUG_PRINTLN(F("Fall some more"));
                        #endif

// Serial.pint("E incFalling() from ");    
// Serial.pint(prince.getFalling());    
                        prince.incFalling();
// Serial.pint(" to ");    
// Serial.pintln(prince.getFalling());  
                        prince.setPrevStance(prince.getStance());
                        prince.pushSequence(Stance::Falling_Down_1_Start, Stance::Falling_Down_5_End, true);

                    }
                    else {

                        uint8_t itemIdx = activateSpikes(prince, 32);

                        if (itemIdx == Constants::NoItemFound) {
                                
                            switch (prince.getFalling()) {

                                case 1:
                                    prince.pushSequence(Stance::Crouch_Stand_1_Start, Stance::Crouch_Stand_12_End, Stance::Upright, true);
                                    break;

                                case 2:     // OK but lose some health as well
                                    initFlash(prince, level);                          
                                    prince.pushSequence(Stance::Crouch_Stand_1_Start, Stance::Crouch_Stand_12_End, Stance::Upright, true);
                                    prince.pushSequence(Stance::Falling_Injured_1_Start, Stance::Falling_Injured_2_End, true);
                                    prince.decHealth(1);
                                    break;

                                default:    // Dead!
                                    prince.pushSequence(Stance::Falling_Dead_1_Start, Stance::Falling_Dead_3_End, true);
                                    prince.setHealth(0);
                                    break;

                            }

                        }
                        else {

                            prince.pushSequence(Stance::Falling_Dead_1_Start, Stance::Falling_Dead_3_End, true);
                            prince.setHealth(0);

                        }

                        #if defined(DEBUG) && defined(DEBUG_ACTION_CANJUMPUP)
                        DEBUG_PRINT(F("End jump, stand up "));
                        DEBUG_PRINTLN(prince.getFalling());
                        #endif

                        switch (prince.getStance()) {

                            // case Stance::Falling_SmallStep_5_Check_CanFall:    
                            // case Stance::Falling_RunningJump_5_Check_CanFall:
                            // case Stance::Falling_C_5_Check_CanFall:
                            // case Stance::Falling_StandingJump_5_Check_CanFall:
                            // case Stance::Falling_SingleStep_5_Check_CanFall:
                            case Stance::Falling_StepWalkRun_P2_6_10_5_Check_CanFall:
                            case Stance::Falling_StepWalkRun_P0_4_8_5_Check_CanFall:
                            case Stance::Falling_StepWalkRun_P1_5_9_5_Check_CanFall:
                            case Stance::Falling_StepWalkRun_P3_7_11_5_Check_CanFall:
                                prince.push(prince.getStance() + 1, true);
                                break;

                            case Stance::Falling_Down_5_End:
                                prince.push(prince.getPrevStance() + 1, true);
                                break;

                            default:  
                                break;

                        }

                        prince.setPrevStance(Stance::None);

                    }

                    break;

                case Stance::Drink_Tonic_14:
                    prince.incHealth(2);
                    break;

                case Stance::Upright:
// Serial.pintln("A setFalling(0)");                        
                    prince.setFalling(0);
                    break;

            }


            getStance_Offsets(prince.getDirection(), offset, prince.getStance());
            prince.incX(offset.x * (newStance < 0 ? -1 : 1));
            prince.incY(offset.y * (newStance < 0 ? -1 : 1));



            // Has the player stepped on anything ?

            if (prince.isFootDown()) {

// Serial.println("Foot down!");


                // Check for floor buttons and collapsing floors ..

                uint8_t imageIndex = static_cast<uint8_t>(pgm_read_byte(&Constants::StanceToImageXRef[prince.getStance()]));
                uint16_t pos = (imageIndex - 1) * 3;
                int8_t footToe = static_cast<int8_t>(pgm_read_byte(&Constants::Prince_ImageDetails[pos + 1]));
                int8_t footHeel = static_cast<int8_t>(pgm_read_byte(&Constants::Prince_ImageDetails[pos + 2]));


                // Test with player's toe ..

                int8_t tileXIdx = level.coordToTileIndexX(prince.getDirection(), prince.getPosition().x + prince.getDirectionOffset(footToe));
                int8_t tileYIdx = level.coordToTileIndexY(prince.getDirection(), prince.getPosition().y);
                uint8_t itemIdx = level.getItem(ItemType::AnyItem, tileXIdx, tileYIdx);


                // If no match, test with player's heel ..

                if (itemIdx == Constants::NoItemFound) {

                    tileXIdx = level.coordToTileIndexX(prince.getDirection(), prince.getPosition().x + prince.getDirectionOffset(footHeel));
                    itemIdx = level.getItem(ItemType::AnyItem, tileXIdx, tileYIdx);

                }


                if (itemIdx != Constants::NoItemFound) {

                    Item &item = level.getItem(itemIdx);

                    switch (item.itemType) {
                        
                        case ItemType::CollapsingFloor:

                            if (item.x == tileXIdx && item.y == tileYIdx && item.data.collapsingFloor.timeToFall == 0) {

                                item.data.collapsingFloor.timeToFall = 24;//12;

                            }

                            break;

                        case ItemType::FloorButton1:

                            itemIdx = level.getItem(ItemType::Gate, item.data.floorButton1.gateX, item.data.floorButton1.gateY);

                            if (itemIdx != Constants::NoItemFound) {

                                Item &gate = level.getItem(itemIdx);

                                item.data.floorButton1.frame = 1;
                                item.data.floorButton1.timeToFall = 24;
                                gate.data.gate.closingDelay = 48;
                                gate.data.gate.closingDelayMax = 48;

                            }

                            break;

                        case ItemType::FloorButton2:

                            itemIdx = level.getItem(ItemType::Gate, item.data.floorButton2.gateX, item.data.floorButton2.gateY);

                            if (itemIdx != Constants::NoItemFound) {

                                Item &gate = level.getItem(itemIdx);

                                item.data.floorButton2.frame = 1;
                                item.data.floorButton2.timeToFall = 24;
                                gate.data.gate.closingDelay = 10;
                                gate.data.gate.closingDelayMax = 255;

                            }

                            break;

                        default: break;

                    }

                }

            }


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


    if (prince.isFootDown() && level.canFall(prince) && prince.getFalling() == 0) {

        prince.clear();
// Serial.pintln("F setFalling(1)");    
        prince.setFalling(1);
        prince.setPrevStance(prince.getStance());

        #if defined(DEBUG) && defined(DEBUG_ACTION_CANJUMPUP)
        DEBUG_PRINTLN(F("Start falling"));
        #endif

        switch (prince.getX() % 12) {

            case 0:
            case 4:
            case 8:
                prince.pushSequence(Stance::Falling_StepWalkRun_P0_4_8_1_Start, Stance::Falling_StepWalkRun_P0_4_8_5_Check_CanFall, true);
                prince.setPrevStance(Stance::Falling_StepWalkRun_P0_4_8_5_Check_CanFall);
                break;

            case 1:
            case 5:
            case 9:
                prince.pushSequence(Stance::Falling_StepWalkRun_P1_5_9_1_Start, Stance::Falling_StepWalkRun_P1_5_9_5_Check_CanFall, true);
                prince.setPrevStance(Stance::Falling_StepWalkRun_P1_5_9_5_Check_CanFall);
                break;

            case 2:
            case 6:
            case 10:
                prince.pushSequence(Stance::Falling_StepWalkRun_P2_6_10_1_Start, Stance::Falling_StepWalkRun_P2_6_10_5_Check_CanFall, true);
                prince.setPrevStance(Stance::Falling_StepWalkRun_P2_6_10_5_Check_CanFall);
                break;

            case 3:
            case 7:
            case 11:
                prince.pushSequence(Stance::Falling_StepWalkRun_P3_7_11_1_Start, Stance::Falling_StepWalkRun_P3_7_11_5_Check_CanFall, true);
                prince.setPrevStance(Stance::Falling_StepWalkRun_P3_7_11_5_Check_CanFall);
                break;

        }

    }


    // If in the air and touching wall, then move backwards ..

    if (prince.inAir() && prince.getFalling() == 0) {

        if (level.collideWithWall(prince)) {

            #if defined(DEBUG) && defined(DEBUG_ACTION_COLLIDEWITHWALL)
            DEBUG_PRINT(F("Collide with wall - X:"));
            DEBUG_PRINT(prince.getX());
            DEBUG_PRINT(", Y:");
            DEBUG_PRINT(prince.getY());
            DEBUG_PRINT(", Coll:");
            DEBUG_PRINTLN(level.collideWithWall(prince));
            #endif

            prince.clear();
// Serial.println("G setFalling(1)");    
            prince.setFalling(1);


            // Do we need to apply any horizontal adjustment?

            switch (prince.getX() % 12) {

                case 0:
                    prince.push(Stance::Collide_Wall_M2_Start_End, false);
                    break;

                case 1:
                case 5:
                case 9:
                case 3:
                    prince.push(Stance::Collide_Wall_M1_Start_End, false);
                    break;

                case 2:
                case 6:
                case 10:
                    prince.push(Stance::Collide_Wall_P0_Start_End, false);
                    break;

                // case 3:
                case 7:
                case 11:
                    prince.push(Stance::Collide_Wall_P1_Start_End, false);
                    break;

                case 4:
                case 8:
                case 12:
                    prince.push(Stance::Collide_Wall_P2_Start_End, false);
                    break;

            }                    


            // Do we need to apply some vertical adjustment?
            
            uint8_t adj = (prince.getY() - 25) % 31;
// Serial.print("prince.getY():");
// Serial.print(prince.getY());
// Serial.print(", Adj:");
// Serial.print(adj);

            if (adj != 0) {

                adj = 31 - adj;
                adj = (adj - 1) * 5;

                for (uint8_t i = adj; i < adj + 5; i++) {
                    
                    uint8_t adjustment = static_cast<uint8_t>(pgm_read_byte(&Constants::VertAdjustments[i]));

                    if (adjustment > 0) {
    // Serial.print(", adjustment:");
    // Serial.print(adjustment);
    // Serial.print(", base:");
    // Serial.println(Stance::Vert_Adjustment_1_Start_End);
                        prince.push(Stance::Vert_Adjustment_1_Start_End - 1 + adjustment, false);

                    }

                }

            }
    // Serial.println("");        

        }

    }


    // Open exit door ?

    {

        Item &item = level.getItem(1);

        if (item.data.exitDoor.position == 0) {

            int8_t tileXIdx = level.coordToTileIndexX(prince.getDirection(), prince.getPosition().x);
            int8_t tileYIdx = level.coordToTileIndexY(prince.getDirection(), prince.getPosition().y);

            if (tileXIdx >= item.data.exitDoor.left && tileXIdx <= item.data.exitDoor.right && item.y == tileYIdx) {

                item.data.exitDoor.direction = Direction::Up;

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
    font3x5.print(prince.getY());
    font3x5.print(F(" D"));
    font3x5.print(level.distToEdgeOfTile(prince.getDirection(), (level.getXLocation() * Constants::TileWidth) + prince.getX()));
    #endif


    #if defined(DEBUG) && defined(DEBUG_ONSCREEN_DETAILS_MIN)
    font3x5.setTextColor(0);
    font3x5.setCursor(1, 0);
    arduboy.fillRect(0, 0, 13, 7);
    font3x5.print(F("D"));
    font3x5.print(level.distToEdgeOfTile(prince.getDirection(),  (level.getXLocation() * Constants::TileWidth) + prince.getX()));
    #endif

}