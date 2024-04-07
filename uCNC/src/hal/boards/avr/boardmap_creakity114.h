/*
	Name: boardmap_rambo14.h
	Description: Contains all MCU and PIN definitions for Arduino UNO to run µCNC.

	Copyright: Copyright (c) João Martins
	Author: João Martins
	Date: 05/02/2020

	µCNC is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version. Please see <http://www.gnu.org/licenses/>

	µCNC is distributed WITHOUT ANY WARRANTY;
	Also without the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
	See the	GNU General Public License for more details.
*/

#ifndef BOARDMAP_RAMBO14_H
#define BOARDMAP_RAMBO14_H

#ifdef __cplusplus
extern "C"
{
#endif

#ifndef BOARD_NAME
#define BOARD_NAME "CREALITY 114"
#endif

#define AVR6

#define PCINT0_PORT A
#define PCINT1_PORT B
#define PCINT2_PORT C

// SAME AS GRBL for test purposes
// Setup step pins
#define STEP3_BIT 1	 // assigns STEP3 pin
#define STEP3_PORT B // assigns STEP3 port
#define STEP2_BIT 3	 // assigns STEP2 pin
#define STEP2_PORT B // assigns STEP2 port
#define STEP1_BIT 6	 // assigns STEP1 pin
#define STEP1_PORT C // assigns STEP1 port
#define STEP0_BIT 7	 // assigns STEP0 pin
#define STEP0_PORT D // assigns STEP0 port

// Setup dir pins
#define DIR3_BIT 0	// assigns DIR3 pin
#define DIR3_PORT B // assigns DIR3 port
#define DIR2_BIT 2	// assigns DIR2 pin
#define DIR2_PORT B // assigns DIR2 port
#define DIR1_BIT 7	// assigns DIR1 pin
#define DIR1_PORT C // assigns DIR1 port
#define DIR0_BIT 5	// assigns DIR0 pin
#define DIR0_PORT C // assigns DIR0 port

	// Setup limit pins

#define LIMIT_X_BIT 2		// assigns LIMIT_X pin
#define LIMIT_X_PORT C	// assigns LIMIT_X port
#define LIMIT_X_ISR 2		// assigns LIMIT_X ISR
// #define LIMIT_X2_BIT 2	// assigns LIMIT_X pin
// #define LIMIT_X2_PORT A // assigns LIMIT_X port
#define LIMIT_Y_BIT 3		// assigns LIMIT_Y pin
#define LIMIT_Y_PORT C	// assigns LIMIT_Y port
#define LIMIT_Y_ISR 2		// assigns LIMIT_Y ISR
// #define LIMIT_Y2_BIT 1	// assigns LIMIT_Y pin
// #define LIMIT_Y2_PORT A // assigns LIMIT_Y port
#define LIMIT_Z_BIT 4		// assigns LIMIT_Z pin
#define LIMIT_Z_PORT C	// assigns LIMIT_Z port
#define LIMIT_Z_ISR 2		// assigns LIMIT_Z ISR

// Setup probe pin
// #define PROBE_BIT 7
// #define PROBE_PORT C

// Setup com pins
#define RX_BIT 0
#define TX_BIT 1
#define RX_PORT D
#define TX_PORT D
// #define RX_PULLUP
// only uncomment this if other port other then 0 is used
// #define UART_PORT 0

// Setup PWM
// #define PWM0_BIT 6	// assigns PWM0 pin
// #define PWM0_PORT H // assigns PWM0 pin
// #define PWM0_CHANNEL B
// #define PWM0_TIMER 2

// Setup generic IO Pins
// Functionalities are set in config.h file
// #define DOUT0_BIT 5
// #define DOUT0_PORT B
// #define DOUT1_BIT 0
// define DOUT1_PORT B
// #define DOUT2_BIT 3
// #define DOUT2_PORT C

// Stepper enable pin. For Grbl on Uno board a single pin is used
#define STEP0_EN_BIT 6
#define STEP0_EN_PORT D
#define STEP1_EN_BIT 6
#define STEP1_EN_PORT D
#define STEP2_EN_BIT 5
#define STEP2_EN_PORT A
#define STEP3_EN_BIT 6
#define STEP3_EN_PORT D

	// Setup the Step Timer used has the heartbeat for µCNC
	// Timer 1 is used by default
	// #define ITP_TIMER 1
	// Setup the RTC Timer used by µCNC to provide an (mostly) accurate time base for all time dependent functions
	// Timer 0 is set by default
	// #define RTC_TIMER 0

// blink led
#define DOUT31_BIT 4
#define DOUT31_PORT A

#define ONESHOT_TIMER 2

#define ENABLE_PARSER_MODULES

#ifdef __cplusplus
}
#endif

#endif
