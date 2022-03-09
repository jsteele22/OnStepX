// Platform setup ------------------------------------------------------------------------------------
#pragma once

// We define a more generic symbol, in case more Teensy boards based on different lines are supported
#define __TEENSYDUINO__

// This platform has digitalReadFast, digitalWriteFast, etc.
#define HAL_HAS_DIGITAL_FAST

// 1/5000 second sidereal timer
#define HAL_FRACTIONAL_SEC 5000.0F

// This platform has up to 15 bit PWM
#ifndef ANALOG_WRITE_PWM_BITS
  #define ANALOG_WRITE_PWM_BITS 13
#endif
#ifndef ANALOG_WRITE_PWM_RANGE
  #define ANALOG_WRITE_PWM_RANGE 8191
#endif
#ifndef ANALOG_WRITE_PWM_FREQUENCY
  #define ANALOG_WRITE_PWM_FREQUENCY 18310.55
#endif

// Lower limit (fastest) step rate in uS for this platform (in SQW mode) and width of step pulse
#define HAL_MAXRATE_LOWER_LIMIT 1.5
#define HAL_PULSE_WIDTH 0  // effectively disable pulse mode
#define HAL_FAST_PROCESSOR

// TMC2209 setup -----------------------------------------------------------------------------------
#define TMC2209_SOFTWARE_SERIAL
#define TMC_UART_SERIAL_NO_RX
#define TMC_UART_SERIAL_BAUD 230400

// New symbol for the default I2C port -------------------------------------------------------------
#include <Wire.h>
#define HAL_Wire Wire
#define HAL_WIRE_CLOCK 100000

// Non-volatile storage ------------------------------------------------------------------------------
#if NV_DRIVER == NV_DEFAULT
  #include "EEPROM.h"
  #include "../lib/nv/NV_EEPROM.h"
  #define HAL_NV_INIT() nv.init(E2END + 1, true, 0, false);
#endif

//--------------------------------------------------------------------------------------------------
// General purpose initialize for HAL
#include "imxrt.h"

#ifdef EmptyStr
  #undef EmptyStr
#endif
#define EmptyStr "\1"

#define HAL_INIT() { \
  analogReadResolution(10); \
  analogWriteResolution(ANALOG_WRITE_PWM_BITS); \
}

#define HAL_RESET() { \
  SCB_AIRCR = 0x05FA0004; \
  asm volatile ("dsb"); \
}

//--------------------------------------------------------------------------------------------------
// Internal MCU temperature (in degrees C)
#define HAL_TEMP() ( NAN )
