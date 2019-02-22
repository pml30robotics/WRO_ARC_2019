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

  MyRioEncoder mot_enc(
    MyRioExpPort::MSP,
    MyRioEncoder::CNFG_EN | MyRioEncoder::CNFG_CERR | MyRioEncoder::CNFG_COVR,
    0
  );

  TetrixMotor test_mot(mot_pwm, mot_dio, mot_enc);

  test_mot.set_power(-900);
  std::cout << "Motor power is -900" << std::endl;
  // sleep for 3 seconds
  usleep(1000 * 3000);
  std::cout << "Current encoder counts: " << test_mot.get_count() << std::endl;

  test_mot.set_power(0);
  // sleep for half second
  usleep(1000 * 500);
  std::cout << std::endl;
  test_mot.reset();

  test_mot.set_power(900);
  std::cout << "Motor power is 900" << std::endl;
  // sleep for 3 seconds
  usleep(1000 * 3000);
  std::cout << "Current encoder counts: " << test_mot.get_count() << std::endl;

  test_mot.set_power(0);

  robot.close_session();
}
