/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2023 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-CriticalSection/graphs/contributors.
 */

#ifndef INC_107_ARDUINO_CRITICALSECTION_107_ARDUINO_CRITICALSECTION_H
#define INC_107_ARDUINO_CRITICALSECTION_107_ARDUINO_CRITICALSECTION_H

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include "CritSec.h"

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class CriticalSection
{
public:
  CriticalSection() { crit_sec_enter(); }
  ~CriticalSection() { crit_sec_leave(); }
};

#endif /* INC_107_ARDUINO_CRITICALSECTION_107_ARDUINO_CRITICALSECTION_H */
