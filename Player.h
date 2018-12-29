#include <LiquidCrystal.h>
#include "Bullet.h"

#define COLUMN_INDEX 1
#define ROW_INDEX 0

#define PLAYER_ICON 'O'

class Player {
    public:
        enum Side {
            LEFT,RIGHT
        };
        Player(Side side) {
            if(side == Side::LEFT) {
                this->position[COLUMN_INDEX] = 0;
                this->sideModifier = 0;
            }
            else {
                this->position[COLUMN_INDEX] = 15;
                this->sideModifier = 8;
            }
        }
        void moveVertically() {
            ++(this->position[ROW_INDEX]) %= 2; 
        }
        void moveLeft() {
            if(--this->position[COLUMN_INDEX] < sideModifier)
                this->position[COLUMN_INDEX] = sideModifier;
        }
        void moveRight() {
            if(++this->position[COLUMN_INDEX] > sideModifier + 7)
                this->position[COLUMN_INDEX] = sideModifier + 7;
        }
        void fire() {

        }
        void draw(LiquidCrystal *lcd) {
            lcd->setCursor(this->position[COLUMN_INDEX] , this->position[ROW_INDEX]);
            lcd->write(PLAYER_ICON);
        }
        private:
            char sideModifier;
            char position[2];
};
