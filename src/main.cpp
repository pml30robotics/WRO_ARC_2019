#include <iostream>
#include <fstream>
#include <unistd.h>
#include <chrono>
#include <ctime>
#include <cmath>

#include "robot/Robot.hpp"
#include "robot/TetrixMotor.hpp"
#include "robot/DiamondChassis.hpp"
#include "robot/MyRioI2CDevice.hpp"
#include "sensor/MPU9255.hpp"

// function declaration
void print_data(MPU9255* mpu);

int main(int argc, char **argv) {
  Robot& robot = Robot::get_instance();

  Robot_Config config = {
    {.I2C_enable=true, MXP_Config::I2C_CNTR_100_KBPS},
    {.I2C_enable=false, MXP_Config::I2C_CNTR_DISABLE}
  };

  robot.init(config);

  robot.get_coordinates(nullptr);

  MPU9255* mpu9255 = new MPU9255(MyRioExpPort::MXP_A);
  // MPU9255 mpu9255(MyRioExpPort::MXP_A);
  // mpu9255->init();
  //
  // // accel settings
  // mpu9255->set_accel_scale(scale_2g);
  // mpu9255->set_accel_bandwidth(acc_5Hz);
  //
  // // gyro settings
  // mpu9255->set_gyro_scale(scale_250dps);
  // mpu9255->set_gyro_bandwidth(gyro_5Hz);
  //
  // std::cout << "Offset adjusting:" << '\n';
  // mpu9255->offset_adjust();
  // std::cout << "Done: Offset adjusting:" << '\n';
  //
  // // files setup
  // std::fstream file_gyro;
  // file_gyro.open("telemetry_gyro.csv", std::fstream::out);
  //
  // std::fstream file_accel;
  // file_accel.open("telemetry_accel.csv", std::fstream::out);
  //
  // file_gyro << "x;y;z;time(seconds)" << '\n';
  // file_accel << "x;y;z;time(seconds)" << '\n';
  //
  // std::cout << '\n' << "Start" << '\n';
  // auto start = std::chrono::system_clock::now();
  //
  // for (;;) {
  //   mpu9255->read_gyro();
  //   file_gyro << mpu9255->get_X_angle_accel() << "; ";
  //   //std::cout << "X = " << mpu9255->get_X_angle_accel() << '\t';
  //   file_gyro << mpu9255->get_Y_angle_accel() << "; ";
  //   //std::cout << "Y = " << mpu9255->get_Y_angle_accel() << '\t';
  //   file_gyro << mpu9255->get_Z_angle_accel() << "; ";
  //   //std::cout << "Z = " << mpu9255->get_Z_angle_accel() << '\n';
  //
  //   mpu9255->read_accel();
  //   file_accel << mpu9255->get_X_accel() << "; ";
  //   // std::cout << "X = " << mpu9255->get_X_accel() << '\t';
  //   file_accel << mpu9255->get_Y_accel() << "; ";
  //   // std::cout << "Y = " << mpu9255->get_Y_accel() << '\t';
  //   file_accel << mpu9255->get_Z_accel() << "; ";
  //   // std::cout << "Z = " << mpu9255->get_Z_accel() << '\n';
  //
  //   auto curr = std::chrono::system_clock::now();
  //   std::chrono::duration<double> elapsed = curr - start;
  //   double elapsed_time = elapsed.count();
  //   file_gyro << elapsed_time << '\n';
  //   file_accel << elapsed_time << '\n';
  //   std::cout << "Elapsed time: " << elapsed_time << '\n';
  //
  //   // measure time for 30 seconds
  //   if (elapsed_time > 20) break;
  //
  //   usleep(1000 * 10);
  // }
  // std::cout << "End" << std::endl;
  //
  // file_gyro.close();
  // file_accel.close();
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

void print_data(MPU9255* mpu) {
  for(int i=0;i<=10;i++)
  {
    mpu->read_accel();
    mpu->read_gyro();

    std::cout << "AX: "
    << mpu->get_X_accel()
    << " AY: "
    << mpu->get_Y_accel()
    << " AZ: "
    << mpu->get_Z_accel()
    << "    GX: "
    << mpu->get_X_angle_accel()
    << " GY: "
    << mpu->get_Y_angle_accel()
    << " GZ: "
    << mpu->get_Z_angle_accel() << '\n';
    usleep(1000 * 500);
  }
}
