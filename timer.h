/*
 * timer.h
 *
 *  Created on: May 16, 2016
 *      Author: ahmed
 */

#ifndef TIMER_H_
#define TIMER_H_

void timerInit();
void timerCount(short value);
void timerDelay_s(double value);
void timerDelay_ms(double value);
void timerDelay_us(double value);

#endif /* TIMER_H_ */
