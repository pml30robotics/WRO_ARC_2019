#include <iostream>
#include <unistd.h>
#include "robot/Robot.hpp"
#include "robot/TetrixMotor.hpp"

extern NiFpga_Session myrio_session;

int main(int argc, char **argv) {
  //Robot& robot = Robot::get_instance();
  MyRio_PrintStatus(MyRio_Open());
  //MyRio_PrintStatus(robot.get_status());

  DIO mot_dio = DIO(MyRioExpPort::MXP_A, 10, Registers::OUTPUT);

  PWM mot_pwm = PWM(
    MyRioExpPort::MXP_A,
    PWM::ENABLE_INV | PWM::ENABLE_MODE,
    1,
    MyRioClockDivider::CLOCK_DIV_4,
    1000
  );

  TetrixMotor test_mot = TetrixMotor(mot_pwm, mot_dio);

  test_mot.set_power(900);

  // sleep for 3 second
  usleep(1000 * 3000);

  test_mot.set_power(-600);

  // sleep for 3 second
  usleep(1000 * 3000);

  test_mot.set_power(0);

  MyRio_Close();
}
