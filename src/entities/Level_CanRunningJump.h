RunningJumpResult canRunningJump(Prince &prince, Action action) {

    int8_t tileXIdx = this->coordToTileIndexX(prince.getPosition().x) - this->getXLocation();
    int8_t tileYIdx = this->coordToTileIndexY(prince.getPosition().y) - this->getYLocation();
    int8_t offset = prince.getDirection() == Direction::Left ? -1 : 1;

    #if defined(DEBUG) && defined(DEBUG_ACTION_CANRUNNINGJUMP)
    DEBUG_PRINTLN(F("------------------------------"));
    printAction(action);
    DEBUG_PRINT(F(" coordToTileIndexX "));
    DEBUG_PRINT(prince.getPosition().x);
    DEBUG_PRINT(F(" = "));
    DEBUG_PRINT(tileXIdx);
    DEBUG_PRINT(F(", coordToTileIndexY "));
    DEBUG_PRINT(prince.getPosition().y);
    DEBUG_PRINT(F(" = "));
    DEBUG_PRINTLN(tileYIdx);
    #endif
    
    switch (action) {

        case Action::RunJump_3:
            {
                int8_t distToEdgeOfCurrentTile = distToEdgeOfTile(prince.getDirection(), prince.getPosition().x);

                WallTileResults wallTile1_CurrLvl = this->isWallTile_ByCoords(tileXIdx, tileYIdx, prince.getDirection());
                WallTileResults wallTile2_CurrLvl = this->isWallTile_ByCoords(tileXIdx + (1 * offset), tileYIdx, prince.getDirection());
                WallTileResults wallTile3_CurrLvl = this->isWallTile_ByCoords(tileXIdx + (2 * offset), tileYIdx, prince.getDirection());
                WallTileResults wallTile4_CurrLvl = this->isWallTile_ByCoords(tileXIdx + (3 * offset), tileYIdx, prince.getDirection());
                WallTileResults wallTile5_CurrLvl = this->isWallTile_ByCoords(tileXIdx + (4 * offset), tileYIdx, prince.getDirection());
                WallTileResults wallTile6_CurrLvl = this->isWallTile_ByCoords(tileXIdx + (5 * offset), tileYIdx, prince.getDirection());
                WallTileResults wallTile1_NextLvl = this->isWallTile_ByCoords(tileXIdx, tileYIdx + 1, prince.getDirection());
                WallTileResults wallTile2_NextLvl = this->isWallTile_ByCoords(tileXIdx + (1 * offset), tileYIdx + 1, prince.getDirection());
                WallTileResults wallTile3_NextLvl = this->isWallTile_ByCoords(tileXIdx + (2 * offset), tileYIdx + 1, prince.getDirection());
                WallTileResults wallTile4_NextLvl = this->isWallTile_ByCoords(tileXIdx + (3 * offset), tileYIdx + 1, prince.getDirection());
                WallTileResults wallTile5_NextLvl = this->isWallTile_ByCoords(tileXIdx + (4 * offset), tileYIdx + 1, prince.getDirection());
                WallTileResults wallTile6_NextLvl = this->isWallTile_ByCoords(tileXIdx + (5 * offset), tileYIdx + 1, prince.getDirection());

                bool isGroundTile1_CurrLvl = this->isGroundTile_ByCoords(tileXIdx, tileYIdx);
                bool isGroundTile2_CurrLvl = this->isGroundTile_ByCoords(tileXIdx + (1 * offset), tileYIdx);
                bool isGroundTile3_CurrLvl = this->isGroundTile_ByCoords(tileXIdx + (2 * offset), tileYIdx);
                bool isGroundTile4_CurrLvl = this->isGroundTile_ByCoords(tileXIdx + (3 * offset), tileYIdx);
                bool isGroundTile5_CurrLvl = this->isGroundTile_ByCoords(tileXIdx + (4 * offset), tileYIdx);
                bool isGroundTile6_CurrLvl = this->isGroundTile_ByCoords(tileXIdx + (5 * offset), tileYIdx);
                bool isGroundTile1_NextLvl = this->isGroundTile_ByCoords(tileXIdx, tileYIdx + 1);
                bool isGroundTile2_NextLvl = this->isGroundTile_ByCoords(tileXIdx + (1 * offset), tileYIdx + 1);
                bool isGroundTile3_NextLvl = this->isGroundTile_ByCoords(tileXIdx + (2 * offset), tileYIdx + 1);
                bool isGroundTile4_NextLvl = this->isGroundTile_ByCoords(tileXIdx + (3 * offset), tileYIdx + 1);
                bool isGroundTile5_NextLvl = this->isGroundTile_ByCoords(tileXIdx + (4 * offset), tileYIdx + 1);
                bool isGroundTile6_NextLvl = this->isGroundTile_ByCoords(tileXIdx + (5 * offset), tileYIdx + 1);


                #if defined(DEBUG) && defined(DEBUG_ACTION_CANRUNNINGJUMP)

                if (prince.getDirection() == Direction::Left) {
                    DEBUG_PRINT("CL ");
                    DEBUG_PRINT((uint8_t)wallTile6_CurrLvl);
                    DEBUG_PRINT(" ");
                    DEBUG_PRINT((uint8_t)wallTile5_CurrLvl);
                    DEBUG_PRINT(" ");
                    DEBUG_PRINT((uint8_t)wallTile4_CurrLvl);
                    DEBUG_PRINT(" ");
                    DEBUG_PRINT((uint8_t)wallTile3_CurrLvl);
                    DEBUG_PRINT(" ");
                    DEBUG_PRINT((uint8_t)wallTile2_CurrLvl);
                    DEBUG_PRINT(" ");
                    DEBUG_PRINT((uint8_t)wallTile1_CurrLvl);
                    DEBUG_PRINTLN(" ");
                    DEBUG_PRINT("NL ");
                    DEBUG_PRINT((uint8_t)wallTile6_NextLvl);
                    DEBUG_PRINT(" ");
                    DEBUG_PRINT((uint8_t)wallTile5_NextLvl);
                    DEBUG_PRINT(" ");
                    DEBUG_PRINT((uint8_t)wallTile4_NextLvl);
                    DEBUG_PRINT(" ");
                    DEBUG_PRINT((uint8_t)wallTile3_NextLvl);
                    DEBUG_PRINT(" ");
                    DEBUG_PRINT((uint8_t)wallTile2_NextLvl);
                    DEBUG_PRINTLN(" _");
                    DEBUG_PRINT("GT ");
                    DEBUG_PRINT((uint8_t)isGroundTile6_CurrLvl);
                    DEBUG_PRINT(" ");
                    DEBUG_PRINT((uint8_t)isGroundTile5_CurrLvl);
                    DEBUG_PRINT(" ");
                    DEBUG_PRINT((uint8_t)isGroundTile4_CurrLvl);
                    DEBUG_PRINT(" ");
                    DEBUG_PRINT((uint8_t)isGroundTile3_CurrLvl);
                    DEBUG_PRINT(" ");
                    DEBUG_PRINT((uint8_t)isGroundTile2_CurrLvl);
                    DEBUG_PRINTLN(" _");
                    DEBUG_PRINT("Dist ");
                    DEBUG_PRINTLN(distToEdgeOfCurrentTile);

                }
                else {

                    DEBUG_PRINT("CL ");
                    DEBUG_PRINT((uint8_t)wallTile1_CurrLvl);
                    DEBUG_PRINT(" ");
                    DEBUG_PRINT((uint8_t)wallTile2_CurrLvl);
                    DEBUG_PRINT(" ");
                    DEBUG_PRINT((uint8_t)wallTile3_CurrLvl);
                    DEBUG_PRINT(" ");
                    DEBUG_PRINT((uint8_t)wallTile4_CurrLvl);
                    DEBUG_PRINT(" ");
                    DEBUG_PRINT((uint8_t)wallTile5_CurrLvl);
                    DEBUG_PRINT(" ");
                    DEBUG_PRINT((uint8_t)wallTile6_CurrLvl);
                    DEBUG_PRINTLN(" ");
                    DEBUG_PRINT("NL ");
                    DEBUG_PRINT((uint8_t)wallTile2_NextLvl);
                    DEBUG_PRINT(" ");
                    DEBUG_PRINT((uint8_t)wallTile3_NextLvl);
                    DEBUG_PRINT(" ");
                    DEBUG_PRINT((uint8_t)wallTile4_NextLvl);
                    DEBUG_PRINT(" ");
                    DEBUG_PRINT((uint8_t)wallTile5_NextLvl);
                    DEBUG_PRINT(" ");
                    DEBUG_PRINT((uint8_t)wallTile6_NextLvl);
                    DEBUG_PRINTLN(" _");
                    DEBUG_PRINT("GT ");
                    DEBUG_PRINT((uint8_t)isGroundTile2_CurrLvl);
                    DEBUG_PRINT(" ");
                    DEBUG_PRINT((uint8_t)isGroundTile3_CurrLvl);
                    DEBUG_PRINT(" ");
                    DEBUG_PRINT((uint8_t)isGroundTile4_CurrLvl);
                    DEBUG_PRINT(" ");
                    DEBUG_PRINT((uint8_t)isGroundTile5_CurrLvl);
                    DEBUG_PRINT(" ");
                    DEBUG_PRINT((uint8_t)isGroundTile6_CurrLvl);
                    DEBUG_PRINTLN(" _");
                    DEBUG_PRINT("Dist ");
                    DEBUG_PRINTLN(distToEdgeOfCurrentTile);

                }
                #endif


                // Can we jump four blanks to the same level?

                if ((distToEdgeOfCurrentTile == 2 || distToEdgeOfCurrentTile == 6) &&
                    wallTile2_CurrLvl == WallTileResults::None && 
                    wallTile3_CurrLvl == WallTileResults::None && 
                    wallTile4_CurrLvl == WallTileResults::None && 
                    wallTile5_CurrLvl == WallTileResults::None && 
                    wallTile6_CurrLvl == WallTileResults::None &&
                    !isGroundTile2_CurrLvl &&
                    !isGroundTile3_CurrLvl &&
                    !isGroundTile4_CurrLvl &&
                    !isGroundTile5_CurrLvl &&
                    isGroundTile6_NextLvl) {

                    switch (distToEdgeOfCurrentTile) {

                        case 2:

                            #if defined(DEBUG) && defined(DEBUG_ACTION_CANRUNNINGJUMP) && defined(DEBUG_ACTION_CANRUNNINGJUMP_DETAIL)
                            DEBUG_PRINTLN("R3-1");
                            #endif

                            return RunningJumpResult::Jump4_GrabLedge_Pos2;

                        case 6:

                            #if defined(DEBUG) && defined(DEBUG_ACTION_CANRUNNINGJUMP) && defined(DEBUG_ACTION_CANRUNNINGJUMP_DETAIL)
                            DEBUG_PRINTLN("R3-2");
                            #endif

                            return RunningJumpResult::Jump4_GrabLedge_Pos6;

                    }

                }


                // Can we jump four levels to the a lower level ?

                if ((distToEdgeOfCurrentTile == 2 || distToEdgeOfCurrentTile == 6) &&
                    wallTile2_CurrLvl == WallTileResults::None && 
                    wallTile3_CurrLvl == WallTileResults::None && 
                    wallTile4_CurrLvl == WallTileResults::None && 
                    wallTile5_CurrLvl == WallTileResults::None && 
                    wallTile2_NextLvl == WallTileResults::None && 
                    wallTile3_NextLvl == WallTileResults::None && 
                    wallTile4_NextLvl == WallTileResults::None && 
                    wallTile5_NextLvl == WallTileResults::None && 
                    wallTile6_NextLvl == WallTileResults::None && 
                    !isGroundTile3_CurrLvl &&
                    !isGroundTile4_CurrLvl &&
                    !isGroundTile5_CurrLvl &&
                    !isGroundTile2_NextLvl &&
                    !isGroundTile3_NextLvl &&
                    !isGroundTile4_NextLvl &&
                    !isGroundTile5_NextLvl &&
                    isGroundTile6_NextLvl) {

                    #if defined(DEBUG) && defined(DEBUG_ACTION_CANRUNNINGJUMP) && defined(DEBUG_ACTION_CANRUNNINGJUMP_DETAIL)
                    DEBUG_PRINTLN("R3-3");
                    #endif

                    return RunningJumpResult::Jump4_DropLevel;

                }


                // Can we jump three blanks to the same level?

                if (wallTile2_CurrLvl == WallTileResults::None && 
                    wallTile3_CurrLvl == WallTileResults::None && 
                    wallTile4_CurrLvl == WallTileResults::None && 
                    wallTile5_CurrLvl == WallTileResults::None && 
                    !isGroundTile2_CurrLvl &&
                    !isGroundTile3_CurrLvl &&
                    !isGroundTile4_CurrLvl &&
                    isGroundTile5_CurrLvl) {

                    switch (distToEdgeOfCurrentTile) {

                        case 2:
                        case 6:

                            #if defined(DEBUG) && defined(DEBUG_ACTION_CANRUNNINGJUMP) && defined(DEBUG_ACTION_CANRUNNINGJUMP_DETAIL)
                            DEBUG_PRINTLN("R3-4");
                            #endif

                            return RunningJumpResult::Jump3_KeepLevel_Short;

                        default:

                            #if defined(DEBUG) && defined(DEBUG_ACTION_CANRUNNINGJUMP) && defined(DEBUG_ACTION_CANRUNNINGJUMP_DETAIL)
                            DEBUG_PRINTLN("R3-5");
                            #endif

                            return RunningJumpResult::Jump3_KeepLevel;

                    }

                }


                // Can we jump three blanks to a lower level?  This occurs on the first level, top left corner.

                if (wallTile2_CurrLvl == WallTileResults::None && 
                    wallTile3_CurrLvl == WallTileResults::None && 
                    wallTile4_CurrLvl == WallTileResults::None && 
                    wallTile5_CurrLvl != WallTileResults::None && 
                    wallTile2_NextLvl == WallTileResults::None && 
                    wallTile3_NextLvl == WallTileResults::None && 
                    wallTile4_NextLvl == WallTileResults::None && 
                    wallTile5_NextLvl == WallTileResults::None && 
                    !isGroundTile2_CurrLvl &&
                    !isGroundTile3_CurrLvl &&
                    !isGroundTile4_CurrLvl &&
                    !isGroundTile2_NextLvl &&
                    !isGroundTile3_NextLvl &&
                    !isGroundTile4_NextLvl &&
                    isGroundTile5_NextLvl) {

                    #if defined(DEBUG) && defined(DEBUG_ACTION_CANRUNNINGJUMP) && defined(DEBUG_ACTION_CANRUNNINGJUMP_DETAIL)
                    DEBUG_PRINTLN("R3-6");
                    #endif

                    switch (distToEdgeOfCurrentTile) {

                        case 2:
                        case 6:
                            return RunningJumpResult::Jump3_DropLevel;

                    }

                }

                if (wallTile4_CurrLvl == WallTileResults::None) {

                    #if defined(DEBUG) && defined(DEBUG_ACTION_CANRUNNINGJUMP) && defined(DEBUG_ACTION_CANRUNNINGJUMP_DETAIL)
                    DEBUG_PRINTLN("R3-7");
                    #endif

                    return RunningJumpResult::Normal;

                }
                else {

                    #if defined(DEBUG) && defined(DEBUG_ACTION_CANRUNNINGJUMP) && defined(DEBUG_ACTION_CANRUNNINGJUMP_DETAIL)
                    DEBUG_PRINTLN("R3-8");
                    #endif

                    return RunningJumpResult::None;

                }

            }

            #if defined(DEBUG) && defined(DEBUG_ACTION_CANRUNNINGJUMP) && defined(DEBUG_ACTION_CANRUNNINGJUMP_DETAIL)
            DEBUG_PRINTLN("R3-9");
            #endif

            return RunningJumpResult::Normal;                                

        case Action::RunJump_2:
            {
                WallTileResults wallTile3_CurrLvl = this->isWallTile_ByCoords(tileXIdx + (2 * offset), tileYIdx, prince.getDirection());

                if (wallTile3_CurrLvl == WallTileResults::None) {

                    #if defined(DEBUG) && defined(DEBUG_ACTION_CANRUNNINGJUMP) && defined(DEBUG_ACTION_CANRUNNINGJUMP_DETAIL)
                    DEBUG_PRINTLN("R2-1");
                    #endif

                    return RunningJumpResult::Normal;

                }
                else {

                    #if defined(DEBUG) && defined(DEBUG_ACTION_CANRUNNINGJUMP) && defined(DEBUG_ACTION_CANRUNNINGJUMP_DETAIL)
                    DEBUG_PRINTLN("R2-2");
                    #endif

                    return RunningJumpResult::None;
                }

            }

            #if defined(DEBUG) && defined(DEBUG_ACTION_CANRUNNINGJUMP) && defined(DEBUG_ACTION_CANRUNNINGJUMP_DETAIL)
            DEBUG_PRINTLN("R2-3");
            #endif

            return RunningJumpResult::Normal;

        case Action::RunJump_1:
            {
                WallTileResults wallTile2_CurrLvl = this->isWallTile_ByCoords(tileXIdx + (1 * offset), tileYIdx, prince.getDirection());

                if (wallTile2_CurrLvl == WallTileResults::None) {

                    #if defined(DEBUG) && defined(DEBUG_ACTION_CANRUNNINGJUMP) && defined(DEBUG_ACTION_CANRUNNINGJUMP_DETAIL)
                    DEBUG_PRINTLN("R1-1");
                    #endif

                    return RunningJumpResult::Normal;

                }
                else {

                    #if defined(DEBUG) && defined(DEBUG_ACTION_CANRUNNINGJUMP) && defined(DEBUG_ACTION_CANRUNNINGJUMP_DETAIL)
                    DEBUG_PRINTLN("R1-2");
                    #endif

                    return RunningJumpResult::None;
                }

            }

            #if defined(DEBUG) && defined(DEBUG_ACTION_CANRUNNINGJUMP) && defined(DEBUG_ACTION_CANRUNNINGJUMP_DETAIL)
            DEBUG_PRINTLN("R1-3");
            #endif

            return RunningJumpResult::Normal;

        default: 
            
            #if defined(DEBUG) && defined(DEBUG_ACTION_CANRUNNINGJUMP) && defined(DEBUG_ACTION_CANRUNNINGJUMP_DETAIL)
            DEBUG_PRINTLN("RD ");
            #endif
            
            return RunningJumpResult::None;

    }

    return RunningJumpResult::Normal;

}
