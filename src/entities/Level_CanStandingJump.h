
        // StandingJumpResult canStandingJump(Prince &prince) {

        //     int8_t tileXIdx = this->coordToTileIndexX(prince.getPosition().x) - this->getXLocation();
        //     int8_t tileYIdx = this->coordToTileIndexY(prince.getPosition().y) - this->getYLocation();
        //     int8_t distToEdgeOfCurrentTile = distToEdgeOfTile(prince.getDirection(), prince.getPosition().x);

        //     #if defined(DEBUG) && defined(DEBUG_ACTION_CANSTANDINGJUMP)
        //     DEBUG_PRINTLN(F("------------------------------"));
        //     DEBUG_PRINT(F("StandingJump coordToTileIndexX "));
        //     DEBUG_PRINT(prince.getPosition().x);
        //     DEBUG_PRINT(F(" = "));
        //     DEBUG_PRINT(tileXIdx);
        //     DEBUG_PRINT(F(", coordToTileIndexY "));
        //     DEBUG_PRINT(prince.getPosition().y);
        //     DEBUG_PRINT(F(" = "));
        //     DEBUG_PRINTLN(tileYIdx);
        //     #endif

        //     switch (prince.getDirection()) {

        //         case Direction::Left:
        //             {

        //                 WallTileResults wallTile1_CurrLvl = this->isWallTile_ByCoords(tileXIdx, tileYIdx, Direction::Left);
        //                 WallTileResults wallTile2_CurrLvl = this->isWallTile_ByCoords(tileXIdx - 1, tileYIdx, Direction::Left);
        //                 WallTileResults wallTile3_CurrLvl = this->isWallTile_ByCoords(tileXIdx - 2, tileYIdx, Direction::Left);
        //                 WallTileResults wallTile4_CurrLvl = this->isWallTile_ByCoords(tileXIdx - 3, tileYIdx, Direction::Left);
        //                 WallTileResults wallTile5_CurrLvl = this->isWallTile_ByCoords(tileXIdx - 4, tileYIdx, Direction::Left);
        //                 WallTileResults wallTile2_NextLvl = this->isWallTile_ByCoords(tileXIdx - 1, tileYIdx + 1, Direction::Left);
        //                 WallTileResults wallTile3_NextLvl = this->isWallTile_ByCoords(tileXIdx - 2, tileYIdx + 1, Direction::Left);
        //                 WallTileResults wallTile4_NextLvl = this->isWallTile_ByCoords(tileXIdx - 3, tileYIdx + 1, Direction::Left);
        //                 WallTileResults wallTile5_NextLvl = this->isWallTile_ByCoords(tileXIdx - 4, tileYIdx + 1, Direction::Left);


   
        //                 // WallTileResults, 0 None, 1 Normal, 2 GateClosed

        //                 bool isGroundTile2_CurrLvl = this->isGroundTile_ByCoords(tileXIdx - 1, tileYIdx);
        //                 bool isGroundTile3_CurrLvl = this->isGroundTile_ByCoords(tileXIdx - 2, tileYIdx);
        //                 bool isGroundTile4_CurrLvl = this->isGroundTile_ByCoords(tileXIdx - 3, tileYIdx);
        //                 bool isGroundTile5_CurrLvl = this->isGroundTile_ByCoords(tileXIdx - 4, tileYIdx);
        //                 bool isGroundTile2_NextLvl = this->isGroundTile_ByCoords(tileXIdx - 1, tileYIdx + 1);
        //                 bool isGroundTile3_NextLvl = this->isGroundTile_ByCoords(tileXIdx - 2, tileYIdx + 1);
        //                 bool isGroundTile4_NextLvl = this->isGroundTile_ByCoords(tileXIdx - 3, tileYIdx + 1);

        //                 #if defined(DEBUG) && defined(DEBUG_ACTION_CANSTANDINGJUMP)
        //                 DEBUG_PRINT(isGroundTile5_CurrLvl);
        //                 DEBUG_PRINT("/");
        //                 DEBUG_PRINT((uint8_t)wallTile5_CurrLvl);
        //                 DEBUG_PRINT(" ");
        //                 DEBUG_PRINT((uint8_t)wallTile4_CurrLvl);
        //                 DEBUG_PRINT(" ");
        //                 DEBUG_PRINT((uint8_t)wallTile3_CurrLvl);
        //                 DEBUG_PRINT(" ");
        //                 DEBUG_PRINT((uint8_t)wallTile2_CurrLvl);
        //                 DEBUG_PRINT(" ");
        //                 DEBUG_PRINT((uint8_t)wallTile1_CurrLvl);
        //                 DEBUG_PRINTLN(" ");
        //                 DEBUG_PRINT("NL");
        //                 DEBUG_PRINT((uint8_t)wallTile5_NextLvl);
        //                 DEBUG_PRINT(" ");
        //                 DEBUG_PRINT((uint8_t)wallTile4_NextLvl);
        //                 DEBUG_PRINT(" ");
        //                 DEBUG_PRINT((uint8_t)wallTile3_NextLvl);
        //                 DEBUG_PRINT(" ");
        //                 DEBUG_PRINT((uint8_t)wallTile2_NextLvl);
        //                 DEBUG_PRINTLN(" _");
        //                 DEBUG_PRINT("GT");
        //                 DEBUG_PRINT((uint8_t)isGroundTile5_CurrLvl);
        //                 DEBUG_PRINT(" ");
        //                 DEBUG_PRINT((uint8_t)isGroundTile4_CurrLvl);
        //                 DEBUG_PRINT(" ");
        //                 DEBUG_PRINT((uint8_t)isGroundTile3_CurrLvl);
        //                 DEBUG_PRINT(" ");
        //                 DEBUG_PRINT((uint8_t)isGroundTile2_CurrLvl);
        //                 DEBUG_PRINTLN(" _");
        //                 DEBUG_PRINT("Dist ");
        //                 DEBUG_PRINTLN(distToEdgeOfCurrentTile);
        //                 #endif

        //                 if (wallTile1_CurrLvl == WallTileResults::None && 
        //                     wallTile2_CurrLvl == WallTileResults::None && 
        //                     wallTile3_CurrLvl == WallTileResults::None && 
        //                     !isGroundTile3_CurrLvl &&
        //                     isGroundTile4_CurrLvl) {

        //                     switch (distToEdgeOfCurrentTile) {
                                
        //                         case 2:
                                    
        //                             #if defined(DEBUG) && defined(DEBUG_ACTION_CANSTANDINGJUMP) && defined(DEBUG_ACTION_CANSTANDINGJUMP_DETAIL)
        //                             DEBUG_PRINTLN("L1");
        //                             #endif

        //                             return StandingJumpResult::Normal;

        //                         case 6:

        //                             #if defined(DEBUG) && defined(DEBUG_ACTION_CANSTANDINGJUMP) && defined(DEBUG_ACTION_CANSTANDINGJUMP_DETAIL)
        //                             DEBUG_PRINTLN("L2");
        //                             #endif

        //                             return StandingJumpResult::Short_GrabLedge_Pos6;

        //                         case 10:

        //                             #if defined(DEBUG) && defined(DEBUG_ACTION_CANSTANDINGJUMP) && defined(DEBUG_ACTION_CANSTANDINGJUMP_DETAIL)
        //                             DEBUG_PRINTLN("L3");
        //                             #endif

        //                             return StandingJumpResult::Short_GrabLedge_Pos10;

        //                     }

        //                 }
        //                 else if ((distToEdgeOfCurrentTile == 2 || distToEdgeOfCurrentTile == 6) &&
        //                     wallTile1_CurrLvl == WallTileResults::None && 
        //                     wallTile2_CurrLvl == WallTileResults::None && 
        //                     wallTile3_CurrLvl == WallTileResults::None && 
        //                     wallTile4_CurrLvl == WallTileResults::None && 
        //                     wallTile5_CurrLvl == WallTileResults::None && 
        //                     wallTile2_NextLvl == WallTileResults::None && 
        //                     wallTile3_NextLvl == WallTileResults::None && 
        //                     wallTile4_NextLvl == WallTileResults::None && 
        //                     !isGroundTile3_CurrLvl &&
        //                     (wallTile5_NextLvl != WallTileResults::None || isGroundTile5_CurrLvl)) {

        //                     if (distToEdgeOfCurrentTile == 2) {

        //                         #if defined(DEBUG) && defined(DEBUG_ACTION_CANSTANDINGJUMP) && defined(DEBUG_ACTION_CANSTANDINGJUMP_DETAIL)
        //                         DEBUG_PRINTLN("L4");
        //                         #endif

        //                         return StandingJumpResult::Normal_GrabLedge_Pos2;
        //                     }
        //                     else {

        //                         #if defined(DEBUG) && defined(DEBUG_ACTION_CANSTANDINGJUMP) && defined(DEBUG_ACTION_CANSTANDINGJUMP_DETAIL)
        //                         DEBUG_PRINTLN("L5");
        //                         #endif

        //                         return StandingJumpResult::Normal_GrabLedge_Pos6;
        //                     }

        //                 }
        //                 else if (distToEdgeOfCurrentTile == 2 &&
        //                     wallTile1_CurrLvl == WallTileResults::None && 
        //                     wallTile2_CurrLvl == WallTileResults::None && 
        //                     wallTile3_CurrLvl == WallTileResults::None && 
        //                     wallTile4_CurrLvl == WallTileResults::None && 
        //                     wallTile5_CurrLvl != WallTileResults::None && 
        //                     wallTile4_NextLvl == WallTileResults::None && 
        //                     wallTile5_NextLvl == WallTileResults::None 
        //                     ) {

        //                     #if defined(DEBUG) && defined(DEBUG_ACTION_CANSTANDINGJUMP) && defined(DEBUG_ACTION_CANSTANDINGJUMP_DETAIL)
        //                     DEBUG_PRINTLN("L6");
        //                     #endif

        //                     return StandingJumpResult::Normal_DropLevel_Pos2;

        //                 }
        //                 else if (

        //                     wallTile1_CurrLvl == WallTileResults::None && 
        //                     wallTile2_CurrLvl == WallTileResults::None && 
        //                     wallTile3_CurrLvl == WallTileResults::None && 
        //                     wallTile2_NextLvl == WallTileResults::None && 
        //                     wallTile3_NextLvl != WallTileResults::None) {
                        
        //                     switch(distToEdgeOfCurrentTile) {

        //                         case 2:

        //                             #if defined(DEBUG) && defined(DEBUG_ACTION_CANSTANDINGJUMP) && defined(DEBUG_ACTION_CANSTANDINGJUMP_DETAIL)
        //                             DEBUG_PRINTLN("L7");
        //                             #endif

        //                             return StandingJumpResult::Short_Pos2;

        //                         case 6:

        //                             #if defined(DEBUG) && defined(DEBUG_ACTION_CANSTANDINGJUMP) && defined(DEBUG_ACTION_CANSTANDINGJUMP_DETAIL)
        //                             DEBUG_PRINTLN("L8");
        //                             #endif

        //                             return StandingJumpResult::Short_Pos6;

        //                         case 10:

        //                             #if defined(DEBUG) && defined(DEBUG_ACTION_CANSTANDINGJUMP) && defined(DEBUG_ACTION_CANSTANDINGJUMP_DETAIL)
        //                             DEBUG_PRINTLN("L9");
        //                             #endif

        //                             return StandingJumpResult::Short_Pos10;

        //                     }                            

        //                 }
        //                 else if (wallTile1_CurrLvl == WallTileResults::None && 
        //                     wallTile2_CurrLvl == WallTileResults::None && 
        //                     wallTile3_CurrLvl == WallTileResults::None && 
        //                     wallTile2_NextLvl == WallTileResults::None && 
        //                     wallTile3_NextLvl == WallTileResults::None && 
        //                     wallTile4_NextLvl == WallTileResults::None && 
        //                     !isGroundTile2_CurrLvl &&
        //                     !isGroundTile3_CurrLvl &&
        //                     !isGroundTile2_NextLvl &&
        //                     !isGroundTile3_NextLvl &&
        //                     isGroundTile4_NextLvl) {

        //                         switch (distToEdgeOfCurrentTile) {

        //                             case 6:
        //                             case 10:

        //                                 #if defined(DEBUG) && defined(DEBUG_ACTION_CANSTANDINGJUMP) && defined(DEBUG_ACTION_CANSTANDINGJUMP_DETAIL)
        //                                 DEBUG_PRINTLN("L10");
        //                                 #endif
                                   
        //                                 return StandingJumpResult::DropLevel;

        //                             default:

        //                                 #if defined(DEBUG) && defined(DEBUG_ACTION_CANSTANDINGJUMP) && defined(DEBUG_ACTION_CANSTANDINGJUMP_DETAIL)
        //                                 DEBUG_PRINTLN("L11");
        //                                 #endif
                                    
        //                                 return (wallTile1_CurrLvl == WallTileResults::None && wallTile2_CurrLvl == WallTileResults::None ? StandingJumpResult::Normal : StandingJumpResult::None);
                                    
        //                         }

        //                 }
        //                 else {
                           
        //                     if (wallTile1_CurrLvl == WallTileResults::None && wallTile2_CurrLvl == WallTileResults::None) {

        //                         switch (wallTile3_CurrLvl) {

        //                             case WallTileResults::None:

        //                                 if (wallTile4_CurrLvl != WallTileResults::None) {

        //                                     switch (distToEdgeOfCurrentTile) {
                                                
        //                                         case 2:

        //                                             #if defined(DEBUG) && defined(DEBUG_ACTION_CANSTANDINGJUMP) && defined(DEBUG_ACTION_CANSTANDINGJUMP_DETAIL)
        //                                             DEBUG_PRINTLN("L12");
        //                                             #endif
                                  
        //                                             return StandingJumpResult::Short_Pos2;
                                                
        //                                         case 6:
        //                                         case 10:

        //                                             #if defined(DEBUG) && defined(DEBUG_ACTION_CANSTANDINGJUMP) && defined(DEBUG_ACTION_CANSTANDINGJUMP_DETAIL)
        //                                             DEBUG_PRINTLN("L13");
        //                                             #endif
                                   
        //                                             return StandingJumpResult::Medium;

        //                                         default:

        //                                             #if defined(DEBUG) && defined(DEBUG_ACTION_CANSTANDINGJUMP) && defined(DEBUG_ACTION_CANSTANDINGJUMP_DETAIL)
        //                                             DEBUG_PRINTLN("L14");
        //                                             #endif

        //                                             return StandingJumpResult::Normal;

        //                                     }

        //                                 }

        //                                 #if defined(DEBUG) && defined(DEBUG_ACTION_CANSTANDINGJUMP) && defined(DEBUG_ACTION_CANSTANDINGJUMP_DETAIL)
        //                                 DEBUG_PRINTLN("L15");
        //                                 #endif

        //                                 return StandingJumpResult::Normal;

        //                             case WallTileResults::SolidWall:
        //                             case WallTileResults::GateClosed:

        //                                 #if defined(DEBUG) && defined(DEBUG_ACTION_CANSTANDINGJUMP) && defined(DEBUG_ACTION_CANSTANDINGJUMP_DETAIL)
        //                                 DEBUG_PRINTLN("L16");
        //                                 #endif

        //                                 return StandingJumpResult::Short_Pos2;

        //                         }

        //                     }
        //                     else {

        //                         #if defined(DEBUG) && defined(DEBUG_ACTION_CANSTANDINGJUMP) && defined(DEBUG_ACTION_CANSTANDINGJUMP_DETAIL)
        //                         DEBUG_PRINTLN("L17");
        //                         #endif

        //                         return StandingJumpResult::None;

        //                     }
                             
        //                 }

        //             }

        //             break;

        //         case Direction::Right:
        //             {

        //                 WallTileResults wallTile1_CurrLvl = this->isWallTile_ByCoords(tileXIdx, tileYIdx, Direction::Left);
        //                 WallTileResults wallTile2_CurrLvl = this->isWallTile_ByCoords(tileXIdx + 1, tileYIdx, Direction::Left);
        //                 WallTileResults wallTile3_CurrLvl = this->isWallTile_ByCoords(tileXIdx + 2, tileYIdx, Direction::Left);
        //                 WallTileResults wallTile4_CurrLvl = this->isWallTile_ByCoords(tileXIdx + 3, tileYIdx, Direction::Left);
        //                 WallTileResults wallTile5_CurrLvl = this->isWallTile_ByCoords(tileXIdx + 4, tileYIdx, Direction::Left);
        //                 WallTileResults wallTile2_NextLvl = this->isWallTile_ByCoords(tileXIdx + 1, tileYIdx + 1, Direction::Left);
        //                 WallTileResults wallTile3_NextLvl = this->isWallTile_ByCoords(tileXIdx + 2, tileYIdx + 1, Direction::Left);
        //                 WallTileResults wallTile4_NextLvl = this->isWallTile_ByCoords(tileXIdx + 3, tileYIdx + 1, Direction::Left);
        //                 WallTileResults wallTile5_NextLvl = this->isWallTile_ByCoords(tileXIdx + 4, tileYIdx + 1, Direction::Left);


        //                 // WallTileResults, 0 None, 1 Normal, 2 GateClosed

        //                 bool isGroundTile2_CurrLvl = this->isGroundTile_ByCoords(tileXIdx + 1, tileYIdx);
        //                 bool isGroundTile3_CurrLvl = this->isGroundTile_ByCoords(tileXIdx + 2, tileYIdx);
        //                 bool isGroundTile4_CurrLvl = this->isGroundTile_ByCoords(tileXIdx + 3, tileYIdx);
        //                 bool isGroundTile5_CurrLvl = this->isGroundTile_ByCoords(tileXIdx + 4, tileYIdx);
        //                 bool isGroundTile2_NextLvl = this->isGroundTile_ByCoords(tileXIdx + 1, tileYIdx + 1);
        //                 bool isGroundTile3_NextLvl = this->isGroundTile_ByCoords(tileXIdx + 2, tileYIdx + 1);
        //                 bool isGroundTile4_NextLvl = this->isGroundTile_ByCoords(tileXIdx + 3, tileYIdx + 1);


        //                 #if defined(DEBUG) && defined(DEBUG_ACTION_CANSTANDINGJUMP)
        //                 DEBUG_PRINT((uint8_t)wallTile1_CurrLvl);
        //                 DEBUG_PRINT(" ");
        //                 DEBUG_PRINT((uint8_t)wallTile2_CurrLvl);
        //                 DEBUG_PRINT(" ");
        //                 DEBUG_PRINT((uint8_t)wallTile3_CurrLvl);
        //                 DEBUG_PRINT(" ");
        //                 DEBUG_PRINT((uint8_t)wallTile4_CurrLvl);
        //                 DEBUG_PRINT(" ");
        //                 DEBUG_PRINT((uint8_t)wallTile5_CurrLvl);
        //                 DEBUG_PRINT("/");
        //                 DEBUG_PRINT(isGroundTile5_CurrLvl);
        //                 DEBUG_PRINTLN(" ");
        //                 DEBUG_PRINT("NL _ ");
        //                 DEBUG_PRINT((uint8_t)wallTile2_NextLvl);
        //                 DEBUG_PRINT(" ");
        //                 DEBUG_PRINT((uint8_t)wallTile3_NextLvl);
        //                 DEBUG_PRINT(" ");
        //                 DEBUG_PRINT((uint8_t)wallTile4_NextLvl);
        //                 DEBUG_PRINT(" ");
        //                 DEBUG_PRINTLN((uint8_t)wallTile5_NextLvl);
        //                 DEBUG_PRINT("GT _ ");
        //                 DEBUG_PRINT((uint8_t)isGroundTile2_CurrLvl);
        //                 DEBUG_PRINT(" ");
        //                 DEBUG_PRINT((uint8_t)isGroundTile3_CurrLvl);
        //                 DEBUG_PRINT(" ");
        //                 DEBUG_PRINT((uint8_t)isGroundTile4_CurrLvl);
        //                 DEBUG_PRINT(" ");
        //                 DEBUG_PRINTLN((uint8_t)isGroundTile5_CurrLvl);
        //                 DEBUG_PRINT("Dist ");
        //                 DEBUG_PRINTLN(distToEdgeOfCurrentTile);
        //                 #endif


        //                 if (wallTile1_CurrLvl == WallTileResults::None && 
        //                     wallTile2_CurrLvl == WallTileResults::None && 
        //                     wallTile3_CurrLvl == WallTileResults::None && 
        //                     !isGroundTile3_CurrLvl &&
        //                     isGroundTile4_CurrLvl) {

        //                     switch (distToEdgeOfCurrentTile) {
                                
        //                         case 2:

        //                             #if defined(DEBUG) && defined(DEBUG_ACTION_CANSTANDINGJUMP) && defined(DEBUG_ACTION_CANSTANDINGJUMP_DETAIL)
        //                             DEBUG_PRINTLN("R1");
        //                             #endif

        //                             return StandingJumpResult::Normal;

        //                         case 6:

        //                             #if defined(DEBUG) && defined(DEBUG_ACTION_CANSTANDINGJUMP) && defined(DEBUG_ACTION_CANSTANDINGJUMP_DETAIL)
        //                             DEBUG_PRINTLN("R2");
        //                             #endif

        //                             return StandingJumpResult::Short_GrabLedge_Pos6;

        //                         case 10:

        //                             #if defined(DEBUG) && defined(DEBUG_ACTION_CANSTANDINGJUMP) && defined(DEBUG_ACTION_CANSTANDINGJUMP_DETAIL)
        //                             DEBUG_PRINTLN("R3");
        //                             #endif

        //                             return StandingJumpResult::Short_GrabLedge_Pos10;

        //                     }

        //                 }
        //                 else if ((distToEdgeOfCurrentTile == 2 || distToEdgeOfCurrentTile == 6) &&
        //                     wallTile1_CurrLvl == WallTileResults::None && 
        //                     wallTile2_CurrLvl == WallTileResults::None && 
        //                     wallTile3_CurrLvl == WallTileResults::None && 
        //                     wallTile4_CurrLvl == WallTileResults::None && 
        //                     wallTile5_CurrLvl == WallTileResults::None && 
        //                     wallTile2_NextLvl == WallTileResults::None && 
        //                     wallTile3_NextLvl == WallTileResults::None && 
        //                     wallTile4_NextLvl == WallTileResults::None && 
        //                     !isGroundTile3_CurrLvl &&
        //                     (wallTile5_NextLvl != WallTileResults::None || isGroundTile5_CurrLvl)) {

        //                     if (distToEdgeOfCurrentTile == 2) {

        //                         #if defined(DEBUG) && defined(DEBUG_ACTION_CANSTANDINGJUMP) && defined(DEBUG_ACTION_CANSTANDINGJUMP_DETAIL)
        //                         DEBUG_PRINTLN("R4");
        //                         #endif

        //                         return StandingJumpResult::Normal_GrabLedge_Pos2;

        //                     }
        //                     else {

        //                         #if defined(DEBUG) && defined(DEBUG_ACTION_CANSTANDINGJUMP) && defined(DEBUG_ACTION_CANSTANDINGJUMP_DETAIL)
        //                         DEBUG_PRINTLN("R5");
        //                         #endif

        //                         return StandingJumpResult::Normal_GrabLedge_Pos6;
        //                     }

        //                 }
        //                 else if (distToEdgeOfCurrentTile == 2 &&
        //                     wallTile1_CurrLvl == WallTileResults::None && 
        //                     wallTile2_CurrLvl == WallTileResults::None && 
        //                     wallTile3_CurrLvl == WallTileResults::None && 
        //                     wallTile4_CurrLvl == WallTileResults::None && 
        //                     wallTile5_CurrLvl != WallTileResults::None && 
        //                     wallTile4_NextLvl == WallTileResults::None && 
        //                     wallTile5_NextLvl == WallTileResults::None 
        //                     ) {

        //                     #if defined(DEBUG) && defined(DEBUG_ACTION_CANSTANDINGJUMP) && defined(DEBUG_ACTION_CANSTANDINGJUMP_DETAIL)
        //                     DEBUG_PRINTLN("R6");
        //                     #endif
                            
        //                     return StandingJumpResult::Normal_DropLevel_Pos2;

        //                 }                        
        //                 else if (

        //                     wallTile1_CurrLvl == WallTileResults::None && 
        //                     wallTile2_CurrLvl == WallTileResults::None && 
        //                     wallTile3_CurrLvl == WallTileResults::None && 
        //                     wallTile2_NextLvl == WallTileResults::None && 
        //                     wallTile3_NextLvl != WallTileResults::None) {
                        
        //                     switch(distToEdgeOfCurrentTile) {

        //                         case 2:

        //                             #if defined(DEBUG) && defined(DEBUG_ACTION_CANSTANDINGJUMP) && defined(DEBUG_ACTION_CANSTANDINGJUMP_DETAIL)
        //                             DEBUG_PRINTLN("R7");
        //                             #endif
                                    
        //                             return StandingJumpResult::Short_Pos2;

        //                         case 6:

        //                             #if defined(DEBUG) && defined(DEBUG_ACTION_CANSTANDINGJUMP) && defined(DEBUG_ACTION_CANSTANDINGJUMP_DETAIL)
        //                             DEBUG_PRINTLN("R8");
        //                             #endif

        //                             return StandingJumpResult::Short_Pos6;

        //                         case 10:

        //                             #if defined(DEBUG) && defined(DEBUG_ACTION_CANSTANDINGJUMP) && defined(DEBUG_ACTION_CANSTANDINGJUMP_DETAIL)
        //                             DEBUG_PRINTLN("R9");
        //                             #endif

        //                             return StandingJumpResult::Short_Pos10;

        //                     }                            

        //                 }                        
        //                 else if (wallTile1_CurrLvl == WallTileResults::None && 
        //                     wallTile2_CurrLvl == WallTileResults::None && 
        //                     wallTile3_CurrLvl == WallTileResults::None && 
        //                     wallTile2_NextLvl == WallTileResults::None && 
        //                     wallTile3_NextLvl == WallTileResults::None && 
        //                     wallTile4_NextLvl == WallTileResults::None && 
        //                     !isGroundTile2_CurrLvl &&
        //                     !isGroundTile3_CurrLvl &&
        //                     !isGroundTile2_NextLvl &&
        //                     !isGroundTile3_NextLvl &&
        //                     isGroundTile4_NextLvl) {

        //                         switch (distToEdgeOfCurrentTile) {

        //                             case 6:
        //                             case 10:

        //                                 #if defined(DEBUG) && defined(DEBUG_ACTION_CANSTANDINGJUMP) && defined(DEBUG_ACTION_CANSTANDINGJUMP_DETAIL)
        //                                 DEBUG_PRINTLN("R10");
        //                                 #endif

        //                                 return StandingJumpResult::DropLevel;

        //                             default:

        //                                 #if defined(DEBUG) && defined(DEBUG_ACTION_CANSTANDINGJUMP) && defined(DEBUG_ACTION_CANSTANDINGJUMP_DETAIL)
        //                                 DEBUG_PRINTLN("R11");
        //                                 #endif

        //                                 return (wallTile1_CurrLvl == WallTileResults::None && wallTile2_CurrLvl == WallTileResults::None ? StandingJumpResult::Normal : StandingJumpResult::None);
                                    
        //                         }

        //                 }
        //                 else {

        //                     if (wallTile1_CurrLvl == WallTileResults::None && wallTile2_CurrLvl == WallTileResults::None) {

        //                         switch (wallTile3_CurrLvl) {

        //                             case WallTileResults::None:

        //                                 if (wallTile4_CurrLvl != WallTileResults::None) {

        //                                     switch (distToEdgeOfCurrentTile) {
                                                
        //                                         case 2:

        //                                             #if defined(DEBUG) && defined(DEBUG_ACTION_CANSTANDINGJUMP) && defined(DEBUG_ACTION_CANSTANDINGJUMP_DETAIL)
        //                                             DEBUG_PRINTLN("R12");
        //                                             #endif
                                  
        //                                             return StandingJumpResult::Short_Pos2;
                                                
        //                                         case 6:
        //                                         case 10:

        //                                             #if defined(DEBUG) && defined(DEBUG_ACTION_CANSTANDINGJUMP) && defined(DEBUG_ACTION_CANSTANDINGJUMP_DETAIL)
        //                                             DEBUG_PRINTLN("R13");
        //                                             #endif
                                   
        //                                             return StandingJumpResult::Medium;

        //                                         default:

        //                                             #if defined(DEBUG) && defined(DEBUG_ACTION_CANSTANDINGJUMP) && defined(DEBUG_ACTION_CANSTANDINGJUMP_DETAIL)
        //                                             DEBUG_PRINTLN("R14");
        //                                             #endif

        //                                             return StandingJumpResult::Normal;

        //                                     }

        //                                 }

        //                                 #if defined(DEBUG) && defined(DEBUG_ACTION_CANSTANDINGJUMP) && defined(DEBUG_ACTION_CANSTANDINGJUMP_DETAIL)
        //                                 DEBUG_PRINTLN("R15");
        //                                 #endif

        //                                 return StandingJumpResult::Normal;

        //                             case WallTileResults::SolidWall:
        //                             case WallTileResults::GateClosed:

        //                                 #if defined(DEBUG) && defined(DEBUG_ACTION_CANSTANDINGJUMP) && defined(DEBUG_ACTION_CANSTANDINGJUMP_DETAIL)
        //                                 DEBUG_PRINTLN("R16");
        //                                 #endif

        //                                 return StandingJumpResult::Short_Pos2;

        //                         }

        //                     }
        //                     else {

        //                         #if defined(DEBUG) && defined(DEBUG_ACTION_CANSTANDINGJUMP) && defined(DEBUG_ACTION_CANSTANDINGJUMP_DETAIL)
        //                         DEBUG_PRINTLN("R17");
        //                         #endif

        //                         return StandingJumpResult::None;

        //                     }
                            
        //                 }

        //             }
        //             break;

        //         default: break;

        //     }

        //     #if defined(DEBUG) && defined(DEBUG_ACTION_CANSTANDINGJUMP) && defined(DEBUG_ACTION_CANSTANDINGJUMP_DETAIL)
        //     DEBUG_PRINTLN("LR18");
        //     #endif

        //     return StandingJumpResult::Normal;

        // }


StandingJumpResult canStandingJump(Prince &prince) {

    int8_t tileXIdx = this->coordToTileIndexX(prince.getPosition().x) - this->getXLocation();
    int8_t tileYIdx = this->coordToTileIndexY(prince.getPosition().y) - this->getYLocation();
    int8_t distToEdgeOfCurrentTile = distToEdgeOfTile(prince.getDirection(), prince.getPosition().x);
    int8_t offset = prince.getDirection() == Direction::Left ? -1 : 1;

    #if defined(DEBUG) && defined(DEBUG_ACTION_CANSTANDINGJUMP)
    DEBUG_PRINTLN(F("------------------------------"));
    DEBUG_PRINT(F("StandingJump coordToTileIndexX "));
    DEBUG_PRINT(prince.getPosition().x);
    DEBUG_PRINT(F(" = "));
    DEBUG_PRINT(tileXIdx);
    DEBUG_PRINT(F(", coordToTileIndexY "));
    DEBUG_PRINT(prince.getPosition().y);
    DEBUG_PRINT(F(" = "));
    DEBUG_PRINTLN(tileYIdx);
    #endif


    WallTileResults wallTile1_CurrLvl = this->isWallTile_ByCoords(tileXIdx, tileYIdx,prince.getDirection());
    WallTileResults wallTile2_CurrLvl = this->isWallTile_ByCoords(tileXIdx + (1 * offset), tileYIdx, prince.getDirection());
    WallTileResults wallTile3_CurrLvl = this->isWallTile_ByCoords(tileXIdx + (2 * offset), tileYIdx, prince.getDirection());
    WallTileResults wallTile4_CurrLvl = this->isWallTile_ByCoords(tileXIdx + (3 * offset), tileYIdx, prince.getDirection());
    WallTileResults wallTile5_CurrLvl = this->isWallTile_ByCoords(tileXIdx + (4 * offset), tileYIdx, prince.getDirection());
    WallTileResults wallTile2_NextLvl = this->isWallTile_ByCoords(tileXIdx + (1 * offset), tileYIdx + 1, prince.getDirection());
    WallTileResults wallTile3_NextLvl = this->isWallTile_ByCoords(tileXIdx + (2 * offset), tileYIdx + 1, prince.getDirection());
    WallTileResults wallTile4_NextLvl = this->isWallTile_ByCoords(tileXIdx + (3 * offset), tileYIdx + 1, prince.getDirection());
    WallTileResults wallTile5_NextLvl = this->isWallTile_ByCoords(tileXIdx + (4 * offset), tileYIdx + 1, prince.getDirection());



    // WallTileResults, 0 None, 1 Normal, 2 GateClosed

    bool isGroundTile2_CurrLvl = this->isGroundTile_ByCoords(tileXIdx + (1 * offset), tileYIdx);
    bool isGroundTile3_CurrLvl = this->isGroundTile_ByCoords(tileXIdx + (2 * offset), tileYIdx);
    bool isGroundTile4_CurrLvl = this->isGroundTile_ByCoords(tileXIdx + (3 * offset), tileYIdx);
    bool isGroundTile5_CurrLvl = this->isGroundTile_ByCoords(tileXIdx + (4 * offset), tileYIdx);
    bool isGroundTile2_NextLvl = this->isGroundTile_ByCoords(tileXIdx + (1 * offset), tileYIdx + 1);
    bool isGroundTile3_NextLvl = this->isGroundTile_ByCoords(tileXIdx + (2 * offset), tileYIdx + 1);
    bool isGroundTile4_NextLvl = this->isGroundTile_ByCoords(tileXIdx + (3 * offset), tileYIdx + 1);

    #if defined(DEBUG) && defined(DEBUG_ACTION_CANSTANDINGJUMP)

    bool isGroundTile5_NextLvl = this->isGroundTile_ByCoords(tileXIdx + (4 * offset), tileYIdx + 1);

    if (prince.getDirection() == Direction::Left) {
        DEBUG_PRINTLN("__  5  4  3  2  1 ");
        DEBUG_PRINT("_");
        DEBUG_PRINT(isGroundTile5_CurrLvl);
        DEBUG_PRINT("/");
        DEBUG_PRINT((uint8_t)wallTile5_CurrLvl);
        DEBUG_PRINT("  ");
        DEBUG_PRINT((uint8_t)wallTile4_CurrLvl);
        DEBUG_PRINT(" ");
        DEBUG_PRINT((uint8_t)wallTile3_CurrLvl);
        DEBUG_PRINT(" ");
        DEBUG_PRINT((uint8_t)wallTile2_CurrLvl);
        DEBUG_PRINT(" ");
        DEBUG_PRINT((uint8_t)wallTile1_CurrLvl);
        DEBUG_PRINTLN(" ");
        DEBUG_PRINT("NL ");
        DEBUG_PRINT((uint8_t)wallTile5_NextLvl);
        DEBUG_PRINT(" ");
        DEBUG_PRINT((uint8_t)wallTile4_NextLvl);
        DEBUG_PRINT(" ");
        DEBUG_PRINT((uint8_t)wallTile3_NextLvl);
        DEBUG_PRINT(" ");
        DEBUG_PRINT((uint8_t)wallTile2_NextLvl);
        DEBUG_PRINTLN(" _");
        DEBUG_PRINT("GC ");
        DEBUG_PRINT((uint8_t)isGroundTile5_CurrLvl);
        DEBUG_PRINT(" ");
        DEBUG_PRINT((uint8_t)isGroundTile4_CurrLvl);
        DEBUG_PRINT(" ");
        DEBUG_PRINT((uint8_t)isGroundTile3_CurrLvl);
        DEBUG_PRINT(" ");
        DEBUG_PRINT((uint8_t)isGroundTile2_CurrLvl);
        DEBUG_PRINTLN(" _");
        DEBUG_PRINT("GN ");
        DEBUG_PRINT((uint8_t)isGroundTile5_NextLvl);
        DEBUG_PRINT(" ");
        DEBUG_PRINT((uint8_t)isGroundTile4_NextLvl);
        DEBUG_PRINT(" ");
        DEBUG_PRINT((uint8_t)isGroundTile3_NextLvl);
        DEBUG_PRINT(" ");
        DEBUG_PRINT((uint8_t)isGroundTile2_NextLvl);
        DEBUG_PRINTLN(" _");
        DEBUG_PRINT("Dist ");
        DEBUG_PRINTLN(distToEdgeOfCurrentTile);
    }
    else {

        DEBUG_PRINTLN("   1  2  3  4  5 ");
        DEBUG_PRINT("CL _ ");
        DEBUG_PRINT((uint8_t)wallTile1_CurrLvl);
        DEBUG_PRINT(" ");
        DEBUG_PRINT((uint8_t)wallTile2_CurrLvl);
        DEBUG_PRINT(" ");
        DEBUG_PRINT((uint8_t)wallTile3_CurrLvl);
        DEBUG_PRINT(" ");
        DEBUG_PRINT((uint8_t)wallTile4_CurrLvl);
        DEBUG_PRINT(" ");
        DEBUG_PRINT((uint8_t)wallTile5_CurrLvl);
        DEBUG_PRINT("/");
        DEBUG_PRINT(isGroundTile5_CurrLvl);
        DEBUG_PRINTLN(" ");
        DEBUG_PRINT("NL _ ");
        DEBUG_PRINT((uint8_t)wallTile2_NextLvl);
        DEBUG_PRINT(" ");
        DEBUG_PRINT((uint8_t)wallTile3_NextLvl);
        DEBUG_PRINT(" ");
        DEBUG_PRINT((uint8_t)wallTile4_NextLvl);
        DEBUG_PRINT(" ");
        DEBUG_PRINTLN((uint8_t)wallTile5_NextLvl);
        DEBUG_PRINT("GC _ ");
        DEBUG_PRINT((uint8_t)isGroundTile2_CurrLvl);
        DEBUG_PRINT(" ");
        DEBUG_PRINT((uint8_t)isGroundTile3_CurrLvl);
        DEBUG_PRINT(" ");
        DEBUG_PRINT((uint8_t)isGroundTile4_CurrLvl);
        DEBUG_PRINT(" ");
        DEBUG_PRINTLN((uint8_t)isGroundTile5_CurrLvl);
        DEBUG_PRINT("GN _ ");
        DEBUG_PRINT((uint8_t)isGroundTile2_NextLvl);
        DEBUG_PRINT(" ");
        DEBUG_PRINT((uint8_t)isGroundTile3_NextLvl);
        DEBUG_PRINT(" ");
        DEBUG_PRINT((uint8_t)isGroundTile4_NextLvl);
        DEBUG_PRINT(" ");
        DEBUG_PRINTLN((uint8_t)isGroundTile5_NextLvl);
        DEBUG_PRINT("Dist ");
        DEBUG_PRINTLN(distToEdgeOfCurrentTile);

    }
    #endif

    if (wallTile1_CurrLvl == WallTileResults::None && 
        wallTile2_CurrLvl == WallTileResults::None && 
        wallTile3_CurrLvl == WallTileResults::None && 
        !isGroundTile3_CurrLvl &&
        isGroundTile4_CurrLvl) {

        switch (distToEdgeOfCurrentTile) {
            
            case 2:
                
                #if defined(DEBUG) && defined(DEBUG_ACTION_CANSTANDINGJUMP) && defined(DEBUG_ACTION_CANSTANDINGJUMP_DETAIL)
                DEBUG_PRINTLN("R1");
                #endif

                return StandingJumpResult::Normal;

            case 6:

                #if defined(DEBUG) && defined(DEBUG_ACTION_CANSTANDINGJUMP) && defined(DEBUG_ACTION_CANSTANDINGJUMP_DETAIL)
                DEBUG_PRINTLN("R2");
                #endif

                return StandingJumpResult::Short_GrabLedge_Pos6;

            case 10:

                #if defined(DEBUG) && defined(DEBUG_ACTION_CANSTANDINGJUMP) && defined(DEBUG_ACTION_CANSTANDINGJUMP_DETAIL)
                DEBUG_PRINTLN("R3");
                #endif

                return StandingJumpResult::Short_GrabLedge_Pos10;

        }

    }

    if ((distToEdgeOfCurrentTile == 2 || distToEdgeOfCurrentTile == 6) &&
         wallTile1_CurrLvl == WallTileResults::None && 
         wallTile2_CurrLvl == WallTileResults::None && 
         wallTile3_CurrLvl == WallTileResults::None && 
         wallTile4_CurrLvl == WallTileResults::None && 
         wallTile5_CurrLvl == WallTileResults::None && 
         wallTile2_NextLvl == WallTileResults::None && 
         wallTile3_NextLvl == WallTileResults::None && 
         wallTile4_NextLvl == WallTileResults::None && 
         !isGroundTile3_CurrLvl &&
         (wallTile5_NextLvl != WallTileResults::None || isGroundTile5_CurrLvl)) {

        if (distToEdgeOfCurrentTile == 2) {

            #if defined(DEBUG) && defined(DEBUG_ACTION_CANSTANDINGJUMP) && defined(DEBUG_ACTION_CANSTANDINGJUMP_DETAIL)
            DEBUG_PRINTLN("R4");
            #endif

            return StandingJumpResult::Normal_GrabLedge_Pos2;
        }
        else {

            #if defined(DEBUG) && defined(DEBUG_ACTION_CANSTANDINGJUMP) && defined(DEBUG_ACTION_CANSTANDINGJUMP_DETAIL)
            DEBUG_PRINTLN("R5");
            #endif

            return StandingJumpResult::Normal_GrabLedge_Pos6;
        }

    }

    if (distToEdgeOfCurrentTile == 2 &&
        wallTile1_CurrLvl == WallTileResults::None && 
        wallTile2_CurrLvl == WallTileResults::None && 
        wallTile3_CurrLvl == WallTileResults::None && 
        wallTile4_CurrLvl == WallTileResults::None && 
        wallTile5_CurrLvl != WallTileResults::None && 
        wallTile4_NextLvl == WallTileResults::None && 
        wallTile5_NextLvl == WallTileResults::None &&
        !isGroundTile3_CurrLvl &&
        !isGroundTile4_CurrLvl
        ) {

        #if defined(DEBUG) && defined(DEBUG_ACTION_CANSTANDINGJUMP) && defined(DEBUG_ACTION_CANSTANDINGJUMP_DETAIL)
        DEBUG_PRINTLN("R6");
        #endif

        return StandingJumpResult::Normal_DropLevel_Pos2;

    }

    if (

        wallTile1_CurrLvl == WallTileResults::None && 
        wallTile2_CurrLvl == WallTileResults::None && 
        wallTile3_CurrLvl == WallTileResults::None && 
        wallTile2_NextLvl == WallTileResults::None && 
        wallTile3_NextLvl != WallTileResults::None) {
    
        switch(distToEdgeOfCurrentTile) {

            case 2:

                #if defined(DEBUG) && defined(DEBUG_ACTION_CANSTANDINGJUMP) && defined(DEBUG_ACTION_CANSTANDINGJUMP_DETAIL)
                DEBUG_PRINTLN("R7");
                #endif

                return StandingJumpResult::Short_Pos2;

            case 6:

                #if defined(DEBUG) && defined(DEBUG_ACTION_CANSTANDINGJUMP) && defined(DEBUG_ACTION_CANSTANDINGJUMP_DETAIL)
                DEBUG_PRINTLN("R8");
                #endif

                return StandingJumpResult::Short_Pos6;

            case 10:

                #if defined(DEBUG) && defined(DEBUG_ACTION_CANSTANDINGJUMP) && defined(DEBUG_ACTION_CANSTANDINGJUMP_DETAIL)
                DEBUG_PRINTLN("R9");
                #endif

                return StandingJumpResult::Short_Pos10;

        }                            

    }

    if (wallTile1_CurrLvl == WallTileResults::None && 
        wallTile2_CurrLvl == WallTileResults::None && 
        wallTile3_CurrLvl == WallTileResults::None && 
        wallTile2_NextLvl == WallTileResults::None && 
        wallTile3_NextLvl == WallTileResults::None && 
        wallTile4_NextLvl == WallTileResults::None && 
        !isGroundTile2_CurrLvl &&
        !isGroundTile3_CurrLvl &&
        !isGroundTile2_NextLvl &&
        !isGroundTile3_NextLvl &&
        isGroundTile4_NextLvl) {

        switch (distToEdgeOfCurrentTile) {

            case 6:
            case 10:

                #if defined(DEBUG) && defined(DEBUG_ACTION_CANSTANDINGJUMP) && defined(DEBUG_ACTION_CANSTANDINGJUMP_DETAIL)
                DEBUG_PRINTLN("L10");
                #endif
            
                return StandingJumpResult::DropLevel;

            default:

                #if defined(DEBUG) && defined(DEBUG_ACTION_CANSTANDINGJUMP) && defined(DEBUG_ACTION_CANSTANDINGJUMP_DETAIL)
                DEBUG_PRINTLN("L11");
                #endif
            
                return (wallTile1_CurrLvl == WallTileResults::None && wallTile2_CurrLvl == WallTileResults::None ? StandingJumpResult::Normal : StandingJumpResult::None);
            
        }

    }
    else {
        
        if (wallTile1_CurrLvl == WallTileResults::None && wallTile2_CurrLvl == WallTileResults::None) {

            switch (wallTile3_CurrLvl) {

                case WallTileResults::None:

                    if (wallTile4_CurrLvl != WallTileResults::None) {

                        switch (distToEdgeOfCurrentTile) {
                            
                            case 2:

                                #if defined(DEBUG) && defined(DEBUG_ACTION_CANSTANDINGJUMP) && defined(DEBUG_ACTION_CANSTANDINGJUMP_DETAIL)
                                DEBUG_PRINTLN("L12");
                                #endif
                
                                return StandingJumpResult::Short_Pos2;
                            
                            case 6:
                            case 10:

                                #if defined(DEBUG) && defined(DEBUG_ACTION_CANSTANDINGJUMP) && defined(DEBUG_ACTION_CANSTANDINGJUMP_DETAIL)
                                DEBUG_PRINTLN("L13");
                                #endif
                
                                return StandingJumpResult::Medium;

                            default:

                                #if defined(DEBUG) && defined(DEBUG_ACTION_CANSTANDINGJUMP) && defined(DEBUG_ACTION_CANSTANDINGJUMP_DETAIL)
                                DEBUG_PRINTLN("L14");
                                #endif

                                return StandingJumpResult::Normal;

                        }

                    }

                    #if defined(DEBUG) && defined(DEBUG_ACTION_CANSTANDINGJUMP) && defined(DEBUG_ACTION_CANSTANDINGJUMP_DETAIL)
                    DEBUG_PRINTLN("L15");
                    #endif

                    return StandingJumpResult::Normal;

                case WallTileResults::SolidWall:
                case WallTileResults::GateClosed:

                    #if defined(DEBUG) && defined(DEBUG_ACTION_CANSTANDINGJUMP) && defined(DEBUG_ACTION_CANSTANDINGJUMP_DETAIL)
                    DEBUG_PRINTLN("L16");
                    #endif

                    return StandingJumpResult::Short_Pos2;

            }

        }
        else {

            #if defined(DEBUG) && defined(DEBUG_ACTION_CANSTANDINGJUMP) && defined(DEBUG_ACTION_CANSTANDINGJUMP_DETAIL)
            DEBUG_PRINTLN("L17");
            #endif

            return StandingJumpResult::None;

        }
            
    }

    #if defined(DEBUG) && defined(DEBUG_ACTION_CANSTANDINGJUMP) && defined(DEBUG_ACTION_CANSTANDINGJUMP_DETAIL)
    DEBUG_PRINTLN("LR18");
    #endif

    return StandingJumpResult::Normal;

}