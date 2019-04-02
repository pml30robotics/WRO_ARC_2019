#ifndef ROBOT_TETRIX_MOTOR_HPP
#define ROBOT_TETRIX_MOTOR_HPP

#include "Motor.hpp"
#include "PWM.hpp"
#include "DIO.hpp"
#include "../sensor/Encoder.hpp"

struct TetrixMotor: Motor {
  TetrixMotor(PWM& pwm, DIO& dio, Encoder& encoder);
  TetrixMotor(PWM& pwm, DIO& dio);

  // implementation of Motor interface
  virtual void set_power(int16_t pwr);
  virtual int32_t move_to_position_abs(int32_t cnts) { return 0; };
  virtual int32_t move_to_position_rel(int32_t cnts) { return 0; };
  virtual int32_t get_count();
  virtual void reset();
private:
  PWM *const pwm;
  DIO *const dio;
  Encoder *const encoder;
};

#endif
