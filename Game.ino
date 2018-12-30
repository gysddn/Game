#include <LiquidCrystal.h>
#include <IRremote.h>
#include "Bullet.h"
#include "Player.h"

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

Player left(Player::Side::LEFT);
Player right(Player::Side::RIGHT);

int inputX = A0;
int inputY = A1;
int inputB = A5;

int RECV_PIN = 7;
IRrecv irrecv(RECV_PIN);
decode_results results;

#define RMT_LEFT 0xFFA25D
#define RMT_RIGHT 0xFFE01F
#define RMT_UP 0xFF02FD
#define RMT_DOWN 0xFF22DD
#define RMT_FIRE 0xFF10EF

void setup() {
	lcd.begin(16,2);
	irrecv.enableIRIn();
}

int lastEntry = 0;

void loop() {
	lcd.clear();
	if (treatValue(analogRead(inputY)) != 52) {
		left.moveVertically();
	}
	int analogHor = treatValue(analogRead(inputX));
	if (analogHor != 52) {
		if (analogHor < 52) {
			left.moveLeft();
		} else {
			left.moveRight();
		}
	}

	if (irrecv.decode(&results)) {
		if (results.value != 0xFFFFFFFF) {
			lastEntry = results.value;
		}
		switch (lastEntry) {
			case RMT_UP:
			case RMT_DOWN: { right.moveVertically(); break; }
			case RMT_RIGHT: { right.moveRight(); break; }
			case RMT_LEFT: { right.moveLeft(); break; }
			case RMT_FIRE: {}
			default: left.moveRight();
		}
	irrecv.resume();
	}
	left.draw(&lcd);
	right.draw(&lcd);
	delay(200);
}

int treatValue(int data) {
	return (data * 9 / 1024) + 48;
}

boolean treatButton(int data) {
	return (data == 0) ? true : false;
}
