/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2023 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-CriticalSection/graphs/contributors.
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include "CritSec.h"

#if defined(ARDUINO_MINIMA) || defined(ARDUINO_UNOWIFIR4) || defined(ARDUINO_PORTENTA_C33)

#include <Arduino.h>

/**************************************************************************************
 * GLOBAL VARIABLES
 **************************************************************************************/

static volatile uint32_t interrupt_save = 0;

/**************************************************************************************
 * FUNCTION DEFINITION
 **************************************************************************************/

extern "C" void crit_sec_enter()
{
  interrupt_save = __get_PRIMASK();
  __disable_irq();
}

extern "C" void crit_sec_leave()
{
  __set_PRIMASK(interrupt_save);
}

#endif /* defined(ARDUINO_MINIMA) || defined(ARDUINO_UNOWIFIR4) || defined(ARDUINO_PORTENTA_C33) */
