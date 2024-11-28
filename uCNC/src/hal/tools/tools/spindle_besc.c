/*
	Name: spindle_relay.c
	Description: Defines a spindle tool using a brushless motor and a ESC controller

	Copyright: Copyright (c) João Martins
	Author: João Martins
	Date: 05/05/2022

	µCNC is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version. Please see <http://www.gnu.org/licenses/>

	µCNC is distributed WITHOUT ANY WARRANTY;
	Also without the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
	See the	GNU General Public License for more details.
*/

#include "../../../cnc.h"

/**
 * Configures a simple spindle control with digital pins for tool forward (`M3`) and reverse (`M4`).
 * There is also provision for digital pins for coolant mist (`M7`) and flood (`M8`).
 *
 * */

// Spindle enable pins.  You can set these to the same pin if required.
#ifndef SPINDLE_BESC_SERVO
#define SPINDLE_BESC_SERVO SERVO0
#endif
#ifndef SPINDLE_BESC_POWER_RELAY
#define SPINDLE_BESC_POWER_RELAY DOUT0
#endif

#ifdef ENABLE_COOLANT
#ifndef SPINDLE_BESC_COOLANT_FLOOD
#define SPINDLE_BESC_COOLANT_FLOOD DOUT2
#endif
#ifndef SPINDLE_BESC_COOLANT_MIST
#define SPINDLE_BESC_COOLANT_MIST DOUT3
#endif
#endif

#ifndef SPINDLE_BESC_LOW
#define SPINDLE_BESC_LOW 50
#endif
#ifndef SPINDLE_BESC_MID
#define SPINDLE_BESC_MID 127
#endif
#ifndef SPINDLE_BESC_HIGH
#define SPINDLE_BESC_HIGH 255
#endif
#define SPINDLE_BESC_RANGE (ABS((SPINDLE_BESC_HIGH - SPINDLE_BESC_LOW)))

#ifdef SPINDLE_BESC_HAS_RPM_ENCODER
#ifndef ENABLE_ENCODER_RPM
#error "TO use RPM encoder you must enable ENABLE_ENCODER_RPM in the HAL"
#endif
#endif

static void startup_code(void)
{
// do whatever routine you need to do here to arm the ESC
#if ASSERT_PIN(SPINDLE_BESC_POWER_RELAY)
#if ASSERT_PIN(SPINDLE_BESC_SERVO)
	io_set_pwm(SPINDLE_BESC_SERVO, SPINDLE_BESC_MID);
#endif
	io_set_output(SPINDLE_BESC_POWER_RELAY);
	cnc_delay_ms(1000);
#if ASSERT_PIN(SPINDLE_BESC_SERVO)
	io_set_pwm(SPINDLE_BESC_SERVO, SPINDLE_BESC_LOW);
#endif
	cnc_delay_ms(2000);
#endif
}

static void shutdown_code(void)
{
#if ASSERT_PIN(SPINDLE_BESC_POWER_RELAY)
	io_clear_output(SPINDLE_BESC_POWER_RELAY);
#endif
}

static int16_t range_speed(int16_t value, uint8_t conv)
{
	if (value == 0)
	{
		return 0;
	}

	if (!conv)
	{
		value = (int16_t)((SPINDLE_BESC_RANGE) * (((float)value) / g_settings.spindle_max_rpm) + SPINDLE_BESC_LOW);
	}
	else
	{
		value = (int16_t)roundf((1.0f / (float)SPINDLE_BESC_RANGE) * (value - SPINDLE_BESC_LOW) * g_settings.spindle_max_rpm);
	}
	return value;
}

static void ramp_to_speed(uint8_t target)
{
	uint8_t current = io_get_pwm(SPINDLE_BESC_SERVO);
	while (current != target)
	{
		if (current < target)
			current++;
		else
			current--;

		io_set_pwm(SPINDLE_BESC_SERVO, current);

		cnc_dwell_ms(20);
	}
}

static void set_speed(int16_t value)
{

	if ((value <= 0))
	{
#if ASSERT_PIN(SPINDLE_BESC_SERVO)
		io_set_pwm(SPINDLE_BESC_SERVO, SPINDLE_BESC_LOW);
		ramp_to_speed(SPINDLE_BESC_LOW);
#endif
	}
	else
	{
#if ASSERT_PIN(SPINDLE_BESC_SERVO)
		ramp_to_speed((uint8_t)value);
#endif
	}
}

static void set_coolant(uint8_t value)
{
#ifdef ENABLE_COOLANT
	SET_COOLANT(SPINDLE_BESC_COOLANT_FLOOD, SPINDLE_BESC_COOLANT_MIST, value);
#endif
}

static uint16_t get_speed(void)
{
#ifdef SPINDLE_BESC_HAS_RPM_ENCODER
	return encoder_get_rpm();
#else
#if ASSERT_PIN(SPINDLE_BESC_SERVO)
	return tool_get_setpoint();
#else
	return 0;
#endif
#endif
}

const tool_t spindle_besc = {
	.startup_code = &startup_code,
	.shutdown_code = &shutdown_code,
	.pid_update = NULL,
	.range_speed = &range_speed,
	.get_speed = &get_speed,
	.set_speed = &set_speed,
	.set_coolant = &set_coolant};
