void loadItems(uint8_t level, Prince &prince) {


    // Deactivate all items ..            

    for (Item &item : items) {
        item.itemType = ItemType::None;
    }

    this->sign.counter = 0;

    uint8_t itemIdx = 0;
    FX::seekData(FX::readIndexedUInt24(Levels::Level_Items, level));
    uint8_t itemType = FX::readPendingUInt8();

    while (itemType != 255) {

        Item &item = this->items[itemIdx];
        item.itemType = static_cast<ItemType>(itemType);

        switch (item.itemType) {

            case ItemType::Gate:
                {
                    Gate gate;
                    FX::readBytes((uint8_t*)&gate, sizeof(gate));

                    if (!(level == 6 && itemIdx == 7 && item.data.gate.position == 9)) {
                        item.data.gate.x = gate.x;
                        item.data.gate.y = gate.y;
                        item.data.gate.position = gate.position;
                        item.data.gate.closingDelay = gate.closingDelay;
                        item.data.gate.defaultClosingDelay = gate.defaultClosingDelay;
                        item.data.gate.closingDelayMax = gate.closingDelayMax;
                        item.data.gate.direction = gate.direction;
                    }

                }
                break;

            default:

                FX::readBytes((uint8_t*)&item.data.rawData, sizeof(item.data.rawData));
                break;

        }

        itemType = FX::readPendingUInt8();
        itemIdx++;

    }

    FX::readEnd();

    prince.setSword(level > 1);

}

void loadMap(GamePlay &gamePlay) {


    uint8_t offset = 0;
    if (this->xLoc) {
        offset = this->xLoc - 3;
    }

    // Background ..

    for (uint8_t x = 0; x < 5 * 16; x++) {

        *(&bg[0][0] + x) = TILE_NONE;
    }

    for (int8_t y = this->yLoc - 1; y < (int8_t)(this->yLoc + 4); y++) {

        if (y >= 0) {
            FX::seekDataArray(FX::readIndexedUInt24(Levels::Level_BG, gamePlay.level), y, offset, this->width);

            for (uint8_t x = 0; x < 16; x++) {

                if (x >= 3 || offset) {
                    bg[y - this->yLoc + 1][x] = static_cast<int8_t>(FX::readPendingUInt8());
                }

            }

            FX::readEnd();
        }

    }


    // Foreground ..

    for (uint8_t x = 0; x < 5 * 16; x++) {

        *(&fg[0][0] + x) = TILE_FG_WALL_1;

    }

    for (int8_t y = this->yLoc - 1; y < (int8_t)(this->yLoc + 4); y++) {

        if (y >= 0) {

            FX::seekDataArray(FX::readIndexedUInt24(Levels::level_FG, gamePlay.level), y, offset, this->width);

            for (uint8_t x = 0; x < 16; x++) {

                if (x >= 3 || offset) {
                    fg[y - this->yLoc + 1][x] = static_cast<int8_t>(FX::readPendingUInt8());
                }
            }

            FX::readEnd();
        }

    }

    #if defined(DEBUG) && defined(DEBUG_LEVEL_LOAD_MAP)
    printMap();
    #endif

}