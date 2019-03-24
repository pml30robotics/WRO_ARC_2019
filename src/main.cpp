#include <iostream>
#include <unistd.h>
#include "robot/Robot.hpp"
#include "robot/TetrixMotor.hpp"
#include "robot/DiamondChassis.hpp"

/* functions decloration */
void motors_init();

/* Motors declaration */
PWM* pwm_rf_motor;
DIO* dio_rf_motor;
Motor* rf_motor;

PWM* pwm_lf_motor;
DIO* dio_lf_motor;
Motor* lf_motor;

PWM* pwm_rb_motor;
DIO* dio_rb_motor;
Motor* rb_motor;

PWM* pwm_lb_motor;
DIO* dio_lb_motor;
Motor* lb_motor;

int main(int argc, char **argv) {
  Robot& robot = Robot::get_instance();

  // sleeps for 1 second
  usleep(1000 * 1000);

  motors_init();
  DiamondChassis chasssis(*rf_motor, *lf_motor, *rb_motor, *lb_motor);
  chasssis.drive_forward();

  // sleeps for 2 seconds
  usleep(1000 * 2000);

  chasssis.stop();
}


/* functions implementation */
void motors_init() {
  /**
   * Forward motors
   */
  // right forward motor initialization
  pwm_rf_motor = new PWM(
    MyRioExpPort::MXP_B,
    PWM::ENABLE_INV | PWM::ENABLE_MODE,
    0,
    MyRioClockDivider::CLOCK_DIV_4,
    1000
  );
  dio_rf_motor = new DIO(MyRioExpPort::MXP_B, 6, DIO::Direction::OUTPUT);
  rf_motor = new TetrixMotor(*pwm_rf_motor, *dio_rf_motor);

  // left forward motor initialization
  pwm_lf_motor = new PWM(
    MyRioExpPort::MXP_B,
    PWM::ENABLE_INV | PWM::ENABLE_MODE,
    1,
    MyRioClockDivider::CLOCK_DIV_4,
    1000
  );
  dio_lf_motor = new DIO(MyRioExpPort::MXP_B, 10, DIO::Direction::OUTPUT);
  lf_motor = new TetrixMotor(*pwm_lf_motor, *dio_lf_motor);

  /**
   * Backward motors
   */
   // right backward motor initialization
   pwm_rb_motor = new PWM(
     MyRioExpPort::MXP_A,
     PWM::ENABLE_INV | PWM::ENABLE_MODE,
     0,
     MyRioClockDivider::CLOCK_DIV_4,
     1000
   );
   dio_rb_motor = new DIO(MyRioExpPort::MXP_A, 6, DIO::Direction::OUTPUT);
   rb_motor = new TetrixMotor(*pwm_rb_motor, *dio_rb_motor);

   // left forward motor initialization
   pwm_lb_motor = new PWM(
     MyRioExpPort::MXP_A,
     PWM::ENABLE_INV | PWM::ENABLE_MODE,
     1,
     MyRioClockDivider::CLOCK_DIV_4,
     1000
   );
   dio_lb_motor = new DIO(MyRioExpPort::MXP_A, 10, DIO::Direction::OUTPUT);
   lb_motor = new TetrixMotor(*pwm_lb_motor, *dio_lb_motor);
}
