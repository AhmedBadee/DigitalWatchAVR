/*
 * lcd.h
 *
 *  Created on: May 21, 2016
 *      Author: ahmed
 */

#ifndef LCD_H_
#define LCD_H_

void lcdInit();
void lcdString(char *string);
void lcdCommand(unsigned char command);
void lcdChar(unsigned char character);
void lcdInteger(unsigned int number);
void clearDisplay();
void returnHome();
void cursorPosition( unsigned char x, unsigned char y);

#endif /* LCD_H_ */
