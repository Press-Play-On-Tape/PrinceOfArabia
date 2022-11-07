#include "src/utils/Arduboy2Ext.h"  
#include <ArduboyFX.h>  
#include "fxdata/Images.h"  
#include "fxdata/Levels.h"  

#include "src/utils/Constants.h"
#include "src/utils/Stack.h"
#include "src/entities/Entities.h"
#include "src/fonts/Font3x5.h"


void getStance_Offsets(Direction direction, Point &offset, int16_t stance) {

    uint16_t idx = (stance - 1) * 2;
    offset.x = static_cast<int8_t>(pgm_read_byte(&Constants::Prince_XOffset[idx])) * (direction == Direction::Left ? -1 : 1) * (stance < 0 ? -1 : 1);
    offset.y = static_cast<int8_t>(pgm_read_byte(&Constants::Prince_XOffset[idx + 1])) * (stance < 0 ? -1 : 1);

}

void processRunJump(const Prince &prince, const Level &level) {

    if (level.canMoveForward(prince, Action::RunJump_1)) {

        if (level.canMoveForward(prince, Action::RunJump_2)) {

            if (level.canMoveForward(prince, Action::RunJump_3)) {

                #if defined(DEBUG) && defined(DEBUG_ACTION_RUNJUMP)
                DEBUG_PRINTLN(F("RunningJump_3 true, Jump"));
                #endif

                prince.pushSequence(Stance::Running_Jump_1_Start, Stance::Running_Jump_11_End, Stance::Run_Repeat_4, true);

            }
            else {

                #if defined(DEBUG) && defined(DEBUG_ACTION_RUNJUMP)
                DEBUG_PRINTLN(F("RunningJump_3 false, RunRepeat"));
                #endif

                prince.pushSequence(Stance::Run_Repeat_1_Start, Stance::Run_Repeat_4, true);

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

void initFlash(const Prince &prince, Level &level) {

    Item &flash = level.getItem(0);
    flash.itemType = ItemType::Flash;
    flash.data.flash.frame = 5;
    flash.x = level.coordToTileIndexX(prince.getDirection(), prince.getX()) + level.getXLocation();
    flash.y = level.coordToTileIndexY(prince.getDirection(), prince.getY()) + level.getYLocation(); 

}

uint8_t activateSpikes(const Prince &prince, uint8_t closingDelay) {

    int8_t tileXIdx = level.coordToTileIndexX(prince.getDirection(), prince.getPosition().x);
    int8_t tileYIdx = level.coordToTileIndexY(prince.getDirection(), prince.getPosition().y);
    uint8_t itemIdx = level.getItem(ItemType::Spikes, tileXIdx, tileYIdx);


    // Withdraw spikes after a few second..

    if (itemIdx != Constants::NoItemFound) {

        Item &spikes = level.getItem(itemIdx);
        spikes.data.spikes.closingDelay = closingDelay;


        itemIdx = level.getItem(ItemType::Spikes, tileXIdx - 1, tileYIdx);

        if (itemIdx != Constants::NoItemFound) {

            Item &spikes = level.getItem(itemIdx);
            spikes.data.spikes.closingDelay = closingDelay;

        }

        itemIdx = level.getItem(ItemType::Spikes, tileXIdx + 1, tileYIdx);

        if (itemIdx != Constants::NoItemFound) {

            Item &spikes = level.getItem(itemIdx);
            spikes.data.spikes.closingDelay = closingDelay;

        }

    }

    return itemIdx;
    
}

void pushJumpUp_Drop(const Prince &prince) {

    prince.pushSequence(Stance::Jump_Up_Drop_A_1_Start, Stance::Jump_Up_Drop_A_5_End, Stance::Upright, false);
    prince.pushSequence(Stance::Jump_Up_A_1_Start, Stance::Jump_Up_A_14_End, true);

}

bool leaveLevel(const Prince &prince, const Level &level) {

    int8_t tileXIdx = level.coordToTileIndexX(prince.getDirection(), prince.getPosition().x);
    int8_t tileYIdx = level.coordToTileIndexY(prince.getDirection(), prince.getPosition().y);

    Item &exitGate = level.getItem(1);


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