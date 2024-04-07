// boardmap override dummy file

#ifndef BOARDMAP_OVERRIDES_H
#define BOARDMAP_OVERRIDES_H

#ifdef __cplusplus
extern "C"
{
#endif

// LCD_CS
#define SERVO0_BIT 3
#define SERVO0_PORT A

// bed temp
#define ESTOP_BIT 6
#define ESTOP_PORT A
#define ESTOP_ISR 0

// end temp
#define PROBE_BIT 7
#define PROBE_PORT A
#define PROBE_ISR 0

#ifdef __cplusplus
}
#endif

#endif
