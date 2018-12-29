#include <LiquidCrystal.h>
#include "Bullet.h"
#include "Player.h"

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

Player left(Player::Side::LEFT);
Player right(Player::Side::RIGHT);

void setup() {
	lcd.begin(16,2);
	lcd.print("It works");
}

void loop() {
}
