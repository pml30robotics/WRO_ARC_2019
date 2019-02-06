#ifndef ROBOT_MOTOR_HPP
#define ROBOT_MOTOR_HPP

#include "myRio/MyRio.h"

/**
 * Motor interface
 */
struct Motor {
  virtual void set_power(int16_t pwr) = 0;
  virtual int32_t move_to_position_abs(int32_t cnts) = 0;
  virtual int32_t move_to_position_rel(int32_t cnts) = 0;

  // member function which should be diligate to Encoder 
  virtual int32_t get_count() = 0;
  virtual void reset();

  virtual ~Motor() {};
};

#endif
