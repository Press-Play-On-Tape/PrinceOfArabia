#pragma once

#include <Arduboy2.h>   
#include "../utils/Constants.h"
#include "../utils/Stack.h"
#include "../entities/Structs.h"

struct Enemy : public BaseEntity {

    private:

        uint8_t moveCount = 0;
        Direction moveDirection = Direction::Forward;

    public:

        uint8_t getMoveCount()                      { return this->moveCount; }
        Direction getMoveDirection()                { return this->moveDirection; }

        void setMoveCount(uint8_t val)              { this->moveCount = val; }
        void setMoveDirection(Direction val)        { this->moveDirection = val; }

        void decMoveCount() {

            if (this->moveCount > 0) this->moveCount--;
            
        }

        void init(int16_t x, int16_t y, Direction direction, uint16_t stance, uint8_t health) {

            this->x = x;
            this->y = y;
            this->direction = direction;
            this->stance = stance;
            this->health = health;
            this->healthMax = health;

        }

    	void update() {

            this->stack->update();

            this->location.x = this->x;
            this->location.y = this->y;

        }

};