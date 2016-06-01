/*
 * lcd.c
 *
 *  Created on: May 21, 2016
 *      Author: ahmed
 */

#include <stdlib.h>
#include "driver.h"
#include "timer.h"

void lcdCommand(unsigned char command) {
	OutputA = (OutputA & 0x0F) | (command & 0xF0);

	OutputB &= ~(1 << RS) & ~(1 << RW);

	OutputB |= (1 << E);
	timerDelay_us(1);
	OutputB &= ~(1 << E);

	timerDelay_us(100);

	OutputA = (OutputA & 0x0F) | (command << 4);

	OutputB |= (1 << E);
	timerDelay_us(1);
	OutputB &= ~(1 << E);

	timerDelay_us(100);
}

void lcdChar(unsigned char character) {
	OutputA = (OutputA & 0x0F) | (character & 0xF0);

	OutputB |= (1 << RS);
	OutputB &= ~(1 << RW);

	OutputB |= (1 << E);
	timerDelay_us(1);
	OutputB &= ~(1 << E);

	timerDelay_us(100);

	OutputA = (OutputA & 0x0F) | (character << 4);

	OutputB |= (1 << E);
	timerDelay_us(1);
	OutputB &= ~(1 << E);

	timerDelay_us(100);
}

void lcdString(char *string) {
	unsigned char i = 0;

	while(string[i] != 0) {
		lcdChar(string[i]);
		i++;
	}
}

void lcdInteger(int number) {
	char string[12];

	itoa( number, string, 10);

	lcdString(string);
}

void lcdInit() {
	DirectionA |= (1 << D4) | (1 << D5) | (1 << D6) | (1 << D7);
	OutputA &= ~(1 << D4) & ~(1 << D5) & ~(1 << D6) & ~(1 << D7);

	DirectionB |= (1 << RS) | (1 << RW) | (1 << E);
	OutputB &= ~(1 << E);

	lcdCommand(0x33);
	lcdCommand(0x32);
	lcdCommand(0x28);                              // 4 bit mode
	lcdCommand(0x0E);                              // Display on, Cursor on
	lcdCommand(0x01);                              // Clear Display

	timerDelay_us(2000);
}

void clearDisplay() {
	lcdCommand(0x01);
}

void returnHome() {
	lcdCommand(0x02);
}

void cursorPosition( unsigned char x, unsigned char y) {
	unsigned char line[] = { 0x80, 0xC0};

	lcdCommand(line[y-1]);
	while( x > 0 ) {
		lcdCommand(0x14);                          // Cursor shifts to right
		x--;
	}
}
