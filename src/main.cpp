#include <iostream>
#include <fstream>
#include <unistd.h>

#include <chrono>
#include <ctime>
#include "robot/Robot.hpp"
#include "robot/TetrixMotor.hpp"
#include "robot/DiamondChassis.hpp"
#include "robot/MyRioI2CDevice.hpp"
#include "sensor/MPU9255.hpp"

int main(int argc, char **argv) {
  Robot& robot = Robot::get_instance();

  Robot_Config config = {
    {true, 63}, {true, 213}
  };

  robot.init(config);

  std::fstream file_gyro;
  file_gyro.open("telemetry_gyro.csv", std::fstream::out);

  std::fstream file_accel;
  file_accel.open("telemetry_accel.csv", std::fstream::out);

  file_gyro << "x;y;z;time(seconds)" << '\n';
  file_accel << "x;y;z;time(seconds)" << '\n';

  MPU9255* mpu9255 = new MPU9255(
    MyRioExpPort::MXP_A,
    MPU9255::G_SCALE::GFS_2000DPS,
    MPU9255::A_SCALE::AFS_16G
  );
  mpu9255->init();

  std::cout << "Start" << '\n';
  auto start = std::chrono::system_clock::now();

  for (;;) {
    file_gyro << mpu9255->get_X_angle_accel() << "; ";
    //std::cout << "X = " << mpu9255->get_X_angle_accel() << '\t';
    file_gyro << mpu9255->get_Y_angle_accel() << "; ";
    //std::cout << "Y = " << mpu9255->get_Y_angle_accel() << '\t';
    file_gyro << mpu9255->get_Z_angle_accel() << "; ";
    //std::cout << "Z = " << mpu9255->get_Z_angle_accel() << '\n';

    file_accel << mpu9255->get_X_accel() << "; ";
    // std::cout << "X = " << mpu9255->get_X_accel() << '\t';
    file_accel << mpu9255->get_Y_accel() << "; ";
    // std::cout << "Y = " << mpu9255->get_Y_accel() << '\t';
    file_accel << mpu9255->get_Z_accel() << "; ";
    // std::cout << "Z = " << mpu9255->get_Z_accel() << '\n';

    auto curr = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed = curr - start;
    double elapsed_time = elapsed.count();
    file_gyro << elapsed_time << '\n';
    file_accel << elapsed_time << '\n';
    std::cout << "Elapsed time: " << elapsed_time << '\n';

    // measure time for 10 seconds
    if (elapsed_time > 30) break;

    usleep(1000 * 10);
  }
  std::cout << "End" << '\n';

  file_gyro.close();
  file_accel.close();
}


// /* functions implementation */
// void motors_init() {
//   /**
//    * Forward motors
//    */
//   // right forward motor initialization
//   pwm_rf_motor = new PWM(
//     MyRioExpPort::MXP_B,
//     PWM::ENABLE_INV | PWM::ENABLE_MODE,
//     0,
//     MyRioClockDivider::CLOCK_DIV_4,
//     1000
//   );
//   dio_rf_motor = new DIO(MyRioExpPort::MXP_B, 6, DIO::Direction::OUTPUT);
//   rf_motor = new TetrixMotor(*pwm_rf_motor, *dio_rf_motor);
//
//   // left forward motor initialization
//   pwm_lf_motor = new PWM(
//     MyRioExpPort::MXP_B,
//     PWM::ENABLE_INV | PWM::ENABLE_MODE,
//     1,
//     MyRioClockDivider::CLOCK_DIV_4,
//     1000
//   );
//   dio_lf_motor = new DIO(MyRioExpPort::MXP_B, 10, DIO::Direction::OUTPUT);
//   lf_motor = new TetrixMotor(*pwm_lf_motor, *dio_lf_motor);
//
//   /**
//    * Backward motors
//    */
//    // right backward motor initialization
//    pwm_rb_motor = new PWM(
//      MyRioExpPort::MXP_A,
//      PWM::ENABLE_INV | PWM::ENABLE_MODE,
//      0,
//      MyRioClockDivider::CLOCK_DIV_4,
//      1000
//    );
//    dio_rb_motor = new DIO(MyRioExpPort::MXP_A, 6, DIO::Direction::OUTPUT);
//    rb_motor = new TetrixMotor(*pwm_rb_motor, *dio_rb_motor);
//
//    // left forward motor initialization
//    pwm_lb_motor = new PWM(
//      MyRioExpPort::MXP_A,
//      PWM::ENABLE_INV | PWM::ENABLE_MODE,
//      1,
//      MyRioClockDivider::CLOCK_DIV_4,
//      1000
//    );
//    dio_lb_motor = new DIO(MyRioExpPort::MXP_A, 10, DIO::Direction::OUTPUT);
//    lb_motor = new TetrixMotor(*pwm_lb_motor, *dio_lb_motor);
// }
