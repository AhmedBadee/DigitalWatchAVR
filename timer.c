/*
 * timer.c
 *
 *  Created on: May 16, 2016
 *      Author: ahmed
 */

#include "driver.h"
#include "timer.h"

void timerInit() {
	ControlRegisterB = (1 << WaveGeneration12)                //CTC Mode
					 | (1 << ClockSelect12);                  //Prescaling 256
	Counter = 0;
}

void timerCount(short value) {
	OutputCompareA = value;
}

void timerDelay_s(double time) {
	short countValue = ((time / (256.0 / Freq_CPU)) - 1);
	while ( Counter < countValue);
	Counter = 0;
}

void timerDelay_ms(double time) {
	short countValue = (((time / 1000) / (256.0 / Freq_CPU)) - 1);
	while ( Counter < countValue);
	Counter = 0;
}

void timerDelay_us(double time) {
	short countValue = (((time / 1000000) / (256.0 / Freq_CPU)) - 1);
	while ( Counter < countValue);
	Counter = 0;
}
