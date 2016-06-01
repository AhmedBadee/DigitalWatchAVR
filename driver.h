/*
 * driver.h
 *
 *  Created on: May 21, 2016
 *      Author: ahmed
 */

#ifndef DRIVER_H_
#define DRIVER_H_

#define Freq_CPU                8000000

#define DirectionA              (*(volatile unsigned int *) 0x3A)
#define OutputA                 (*(volatile unsigned int *) 0x3B)
#define D4                      4
#define D5                      5
#define D6                      6
#define D7                      7

#define DirectionB              (*(volatile unsigned int *) 0x37)
#define OutputB                 (*(volatile unsigned int *) 0x38)
#define InputB                  (*(volatile unsigned int *) 0x36)
#define RS                      1
#define RW                      2
#define E                       3
#define PB7                     7

#define DirectionD              (*(volatile unsigned int *) 0x31)
#define InputD                  (*(volatile unsigned int *) 0x30)
#define PD0                     0
#define PD1                     1
#define PD2                     2

//Timer 1
#define ControlRegisterA        (*(volatile unsigned char *) 0x4F)
#define CompareOutputMatchA1    7
#define CompareOutputMatchA0    6

#define ControlRegisterB        (*(volatile unsigned char *) 0x4E)
#define WaveGeneration12        3
#define ClockSelect12           2

#define InterruptMask           (*(volatile unsigned char *) 0x59)
#define OutputCompareInterruptA 4

#define OutputCompareA          (*(volatile unsigned short *) 0x4A)

#define InterruptFlag           (*(volatile unsigned char *) 0x58)
#define OuputCompareFlagA       4
#define OverflowFlag            2

#define Counter                 (*(volatile unsigned short *) 0x4C)


#endif /* DRIVER_H_ */
