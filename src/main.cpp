#include <iostream>
#include <unistd.h>
#include "robot/Robot.hpp"
#include "robot/TetrixMotor.hpp"

int main(int argc, char **argv) {
  Robot& robot = Robot::get_instance();

  robot.open_session();

  PWM mot_pwm(
    MyRioExpPort::MXP_A,
    PWM::ENABLE_INV | PWM::ENABLE_MODE,
    1,
    MyRioClockDivider::CLOCK_DIV_4,
    1000
  );

  DIO mot_dio(MyRioExpPort::MXP_A, 10, DIO::Direction::OUTPUT);

  TetrixMotor test_mot(mot_pwm, mot_dio);

  test_mot.set_power(900);
  // sleep for 3 second
  usleep(1000 * 3000);

  test_mot.set_power(-900);
  // sleep for 3 second
  usleep(1000 * 3000);

  test_mot.set_power(0);

  robot.close_session();
}
