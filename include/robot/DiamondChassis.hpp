#ifndef ROBOT_CHASSIS_HPP
#define ROBOT_CHASSIS_HPP

#include "Motor.hpp"

#define NUM_OF_WHEELS 4

/* Motors numbering */
#define RF_MOT 0
#define LF_MOT 1
#define RB_MOT 2
#define LB_MOT 3

struct DiamondChassis {
  DiamondChassis(Motor& rf_motor, Motor& lf_motor, Motor& rb_motor, Motor& lb_motor);
  // test method
  void drive_forward();
  // test method
  void stop();
  // WIP method
  void drive_dist_at_angle(uint16_t angle, uint16_t);
  /* Constant member fields */
  const int16_t MAX_SPEED = 900;

private:
  Motor *motors[NUM_OF_WHEELS];
};

#endif
