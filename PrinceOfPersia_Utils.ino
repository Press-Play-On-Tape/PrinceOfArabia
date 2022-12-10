#include "src/utils/Arduboy2Ext.h"  
#include <ArduboyFX.h>  
#include "fxdata/Images.h"  
#include "fxdata/Levels.h"  

#include "src/utils/Constants.h"
#include "src/utils/Stack.h"
#include "src/entities/Entities.h"
#include "src/fonts/Font3x5.h"

void testScroll(Prince &prince, Level &level) {


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

}

void getStance_Offsets(Direction direction, Point &offset, int16_t stance) {

    uint16_t idx = (stance - 1) * 2;
    offset.x = static_cast<int8_t>(pgm_read_byte(&Constants::Prince_XOffset[idx])) * (direction == Direction::Left ? -1 : 1) * (stance < 0 ? -1 : 1);
    offset.y = static_cast<int8_t>(pgm_read_byte(&Constants::Prince_XOffset[idx + 1])) * (stance < 0 ? -1 : 1);

}

void processRunJump(Prince &prince, Level &level) {

    RunningJumpResult jump_1_Result = level.canRunningJump(prince, Action::RunJump_1);

    if (jump_1_Result != RunningJumpResult::None) {

        RunningJumpResult jump_2_Result = level.canRunningJump(prince, Action::RunJump_2);

        if (jump_2_Result != RunningJumpResult::None) {

            RunningJumpResult jump_3_Result = level.canRunningJump(prince, Action::RunJump_3);

            switch (jump_3_Result) {

                case RunningJumpResult::Jump4_DropLevel:
                    prince.pushSequence(Stance::Crouch_Stand_1_Start, Stance::Crouch_Stand_12_End, Stance::Upright, true);
                    prince.pushSequence(Stance::Running_Jump_4_DropLvl_1_Start, Stance::Running_Jump_4_DropLvl_14_End, true);
                    prince.setIgnoreWallCollisions(true);
                    break;

                case RunningJumpResult::Jump3_DropLevel:
                    prince.pushSequence(Stance::Crouch_Stand_1_Start, Stance::Crouch_Stand_12_End, Stance::Upright, true);
                    prince.pushSequence(Stance::Running_Jump_3_DropLvl_1_Start, Stance::Running_Jump_3_DropLvl_14_End, true);
                    prince.setIgnoreWallCollisions(true);
                    break;

                case RunningJumpResult::Jump3_KeepLevel:
                    prince.pushSequence(Stance::Running_Jump_3_SameLvl_1_Start, Stance::Running_Jump_3_SameLvl_8_End,  Stance::Run_Repeat_4, true);
                    prince.setIgnoreWallCollisions(true);
                    break;

                case RunningJumpResult::Normal:
                    #if defined(DEBUG) && defined(DEBUG_ACTION_RUNJUMP)
                    DEBUG_PRINTLN(F("RunningJump_3 true, Jump"));
                    #endif

                    prince.pushSequence(Stance::Running_Jump_Short_1_Start, Stance::Running_Jump_Short_7_End, Stance::Run_Repeat_4, true);

                    break;

                case RunningJumpResult::None:

                    #if defined(DEBUG) && defined(DEBUG_ACTION_RUNJUMP)
                    DEBUG_PRINTLN(F("RunningJump_3 false, RunRepeat"));
                    #endif

                    prince.pushSequence(Stance::Run_Repeat_1_Start, Stance::Run_Repeat_4, true);
                    break;

            }

        }
        else {

            #if defined(DEBUG) && defined(DEBUG_ACTION_RUNJUMP)
            DEBUG_PRINTLN(F("RunningJump_2 false, RunRepeat"));
            #endif

            prince.pushSequence(Stance::Run_Repeat_1_Start, Stance::Run_Repeat_4, true);

        }

    }
    else {

        #if defined(DEBUG) && defined(DEBUG_ACTION_RUNJUMP)
        DEBUG_PRINTLN(F("RunningJump_1 false, Stopping"));
        #endif

        prince.pushSequence(Stance::Stopping_1_Start, Stance::Stopping_5_End, Stance::Upright, true);
    }

}


void processStandingJump(Prince &prince, Level &level) {

    StandingJumpResult standingJumpResult = level.canStandingJump(prince);

    switch (standingJumpResult) {

        case StandingJumpResult::DropLevel:
            prince.pushSequence(Stance::Crouch_Stand_1_Start, Stance::Crouch_Stand_12_End, Stance::Upright, true);
            prince.pushSequence(Stance::Standing_Jump_DropLvl_1_Start, Stance::Standing_Jump_DropLvl_16_End, true);
            prince.setIgnoreWallCollisions(true);
            break;

        case StandingJumpResult::Normal:
            prince.pushSequence(Stance::Standing_Jump_1_Start, Stance::Standing_Jump_18_End, Stance::Upright, true);
            break;

        case StandingJumpResult::None:
            break;

    }

}

void initFlash(Prince &prince, Level &level) {

    Item &flash = level.getItem(Constants::Item_Flash);
    flash.itemType = ItemType::Flash;
    flash.data.flash.frame = 5;
    flash.x = level.coordToTileIndexX(prince.getX()) + level.getXLocation();
    flash.y = level.coordToTileIndexY(prince.getY()) + level.getYLocation(); 

}

uint8_t activateSpikes(Prince &prince, Level &level) {

    int8_t tileXIdx = level.coordToTileIndexX(prince.getPosition().x);
    int8_t tileYIdx = level.coordToTileIndexY(prince.getPosition().y);
    uint8_t itemIdx = level.getItem(ItemType::Spikes, tileXIdx, tileYIdx);


    // Withdraw spikes after a few second..

    if (itemIdx != Constants::NoItemFound) {

        Item &spikes = level.getItem(itemIdx);

        if (spikes.data.spikes.closingDelay == 0) {
            spikes.data.spikes.closingDelay = Constants::SpikeClosingDelay;
        }

        uint8_t itemIdx2 = level.getItem(ItemType::Spikes, tileXIdx - 1, tileYIdx);

        if (itemIdx2 != Constants::NoItemFound) {

            Item &spikes = level.getItem(itemIdx2);

            if (spikes.data.spikes.closingDelay == 0) {
                spikes.data.spikes.closingDelay = Constants::SpikeClosingDelay;
            }

        }

        itemIdx2 = level.getItem(ItemType::Spikes, tileXIdx + 1, tileYIdx);

        if (itemIdx2 != Constants::NoItemFound) {

            Item &spikes = level.getItem(itemIdx2);

            if (spikes.data.spikes.closingDelay == 0) {
                spikes.data.spikes.closingDelay = Constants::SpikeClosingDelay;
            }

        }

    }

    return itemIdx;
    
}

void pushJumpUp_Drop(Prince &prince) {

    prince.pushSequence(Stance::Jump_Up_Drop_A_1_Start, Stance::Jump_Up_Drop_A_5_End, Stance::Upright, false);
    prince.pushSequence(Stance::Jump_Up_A_1_Start, Stance::Jump_Up_A_14_End, true);

}

bool leaveLevel(Prince &prince, Level &level) {

    int8_t tileXIdx = level.coordToTileIndexX(prince.getPosition().x);
    int8_t tileYIdx = level.coordToTileIndexY(prince.getPosition().y);

    Item &exitGate = level.getItem(Constants::Item_ExitDoor);


    // Are we close to the exist gate?  If so, exit scene ..

    if (tileXIdx == exitGate.x - 1 && tileYIdx == exitGate.y) {

        switch (prince.getDirection()) {

            case Direction::Left:

                prince.pushSequence(Stance::Standing_Turn_1_Start, Stance::Standing_Turn_5_End, Stance::Upright_Turn, true);
                break;

            case Direction::Right:

                prince.pushSequence(Stance::Leave_Gate_1_Start, Stance::Leave_Gate_14_End, true);
                    
                switch (level.distToEdgeOfTile(prince.getDirection(), (level.getXLocation() * Constants::TileWidth) + prince.getX())) {

                    case 2:
                        prince.pushSequence(Stance::Small_Step_1_Start, Stance::Small_Step_6_End, true);
                        break;

                    case 6:
                        prince.pushSequence(Stance::Single_Step_2, Stance::Single_Step_8_End, true);
                        break;

                    case 10:
                        prince.pushSequence(Stance::Small_Step_1_Start, Stance::Small_Step_6_End, true);
                        prince.pushSequence(Stance::Single_Step_2, Stance::Single_Step_8_End, true);
                        break;

                    default: break;

                }

                return true;

            default: break;

        }

        return true;

    }
    else if (tileXIdx == exitGate.x && tileYIdx == exitGate.y) {

        prince.pushSequence(Stance::Standing_Turn_1_Start, Stance::Standing_Turn_5_End, Stance::Upright_Turn, true);

        switch (prince.getDirection()) {

            case Direction::Left:
                    
                switch (level.distToEdgeOfTile(prince.getDirection(), (level.getXLocation() * Constants::TileWidth) + prince.getX())) {

                    case 6:
                        prince.pushSequence(Stance::Small_Step_1_Start, Stance::Small_Step_6_End, true);
                        break;

                    case 10:
                        prince.pushSequence(Stance::Single_Step_1_Start, Stance::Single_Step_8_End, true);
                        break;

                    default: break;

                }

                break;

            case Direction::Right:

                prince.pushSequence(Stance::Leave_Gate_1_Start, Stance::Leave_Gate_14_End, true);
                    
                switch (level.distToEdgeOfTile(prince.getDirection(), (level.getXLocation() * Constants::TileWidth) + prince.getX())) {

                    case 2:
                        prince.pushSequence(Stance::Single_Step_8_End, Stance::Single_Step_1_Start, true);
                        break;

                    case 6:
                        prince.pushSequence(Stance::Small_Step_6_End, Stance::Small_Step_1_Start, true);
                        break;

                    default: break;

                }

                break;

            default: break;
            
        }

        return true;

    }

    return false;

}

void pushDead(Prince &entity, Level &level, GamePlay &gamePlay, bool clear) {

    if (clear) prince.clear();
    entity.pushSequence(Stance::Falling_Dead_1_Start, Stance::Falling_Dead_3_End, true);
    entity.setHealth(0);

    if (gamePlay.isGameOver()) {

        showSign(entity, level, SignType::GameOver, 20);

    }
    else {

        showSign(entity, level, SignType::PressA, 20);

    }

}

void pushDead(Enemy &entity, Level &level, GamePlay &gamePlay, bool clear) {

    if (clear) entity.clear();
    entity.pushSequence(Stance::Falling_Dead_1_Start, Stance::Falling_Dead_3_End, true);
    entity.setHealth(0);

}

void showSign(Prince &prince, Level &level, SignType signType, uint8_t counter) {

    Item &sign = level.getItem(Constants::Item_Sign);

    switch (signType) {

        case SignType::GameOver:
            sign.data.sign.counter = counter;
            sign.data.sign.type = SignType::GameOver;
            sign.x = 39;
            break;

        case SignType::PressA:
            sign.data.sign.counter = counter;
            sign.data.sign.type = SignType::PressA;
            sign.x = 24;
            break;

    }

    switch (prince.getY()) {

        case 25:
            sign.y = 48;
            break;

        case 56:
        case 87:
            sign.y = 1;
            break;

    }

}