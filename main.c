/*
 * main.c
 *
 *  Created on: May 21, 2016
 *      Author: ahmed
 */

#include "driver.h"
#include "timer.h"
#include "lcd.h"

int main() {

	timerInit();
	lcdInit();

	DirectionB &= ~(1 << PB7);
	DirectionD &= ~(1 << PD0) & ~(1 << PD1) & ~(1 << PD2);

	int sec = 0;
	int min = 0;
	int hrs = 0;

	while (1) {
		clearDisplay();
		cursorPosition( 5, 1);

		if ( hrs < 10 ) {
			lcdChar('0');
			lcdInteger(hrs);
		} else {
			lcdInteger(hrs);
		}

		lcdChar(':');

		if ( min < 10 ) {
			lcdChar('0');
			lcdInteger(min);
		} else {
			lcdInteger(min);
		}

		lcdChar(':');

		if ( sec < 10 ) {
			lcdChar('0');
			lcdInteger(sec);
		} else {
			lcdInteger(sec);
		}

		if ( (InputB & (1 << PB7)) != 0 ) {
			if ( (InputD & (1 << PD2)) != 0 ) {
				if ( hrs == 23 )
					hrs = 0;
				else
					hrs++;
			} else if ( (InputD & (1 << PD1)) != 0 ) {
				if ( min == 59 )
					min = 0;
				else
					min++;
			}
		} else {
			sec++;

			if ( (sec == 60) && (min == 59) && (hrs == 23) ) {
				sec = 0;
				min = 0;
				hrs = 0;
			} else if ( (sec == 60) && (min == 59) && (hrs < 23) ) {
				sec = 0;
				min = 0;
				hrs++;
			} else if ( (sec == 60) && (min < 59) ) {
				sec = 0;
				min++;
			}
		}

		timerDelay_s(1);
	}

	return 0;
}
