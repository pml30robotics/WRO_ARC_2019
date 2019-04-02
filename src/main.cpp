#include <iostream>
#include <unistd.h>
// #include <cjson/cJSON.h>
// #include <libconfig.h>
// #include <thread>
#include "robot/Robot.hpp"
#include "robot/TetrixMotor.hpp"
#include "robot/DiamondChassis.hpp"
#include "robot/MyRioI2CDevice.hpp"
#include "sensor/MPU9255.hpp"

// /* functions decloration */
// void motors_init();
void I2c_Write(uint8_t address, uint8_t* data, uint32_t numBytes);
extern NiFpga_Session myrio_session;

//
// /* Motors declaration */
// PWM* pwm_rf_motor;
// DIO* dio_rf_motor;
// Motor* rf_motor;
//
// PWM* pwm_lf_motor;
// DIO* dio_lf_motor;
// Motor* lf_motor;
//
// PWM* pwm_rb_motor;
// DIO* dio_rb_motor;
// Motor* rb_motor;
//
// PWM* pwm_lb_motor;
// DIO* dio_lb_motor;
// Motor* lb_motor;

int main(int argc, char **argv) {
  Robot& robot = Robot::get_instance();

  Robot_Config config = {
    {true, 213}, {true, 213}
  };

  robot.init(config);

  // sleeps for 1 second
  //usleep(1000 * 1000);
  //
  // motors_init();
  // DiamondChassis chasssis(*rf_motor, *lf_motor, *rb_motor, *lb_motor);
  // chasssis.drive_forward();
  //
  // // sleeps for 2 seconds
  // usleep(1000 * 2000);
  //
  // chasssis.stop();

  MPU9255* mpu9255 = new MPU9255(
    MyRioExpPort::MXP_A,
    MPU9255::G_SCALE::GFS_500DPS,
    MPU9255::A_SCALE::AFS_2G
  );

  mpu9255->init();

  for (;;) {
    std::cout << "X = " << mpu9255->get_X_angle_accel() << '\t';
    std::cout << "Y = " << mpu9255->get_Y_angle_accel() << '\t';
    std::cout << "Z = " << mpu9255->get_Z_angle_accel() << '\n';
    usleep(1000 * 300);
  }

  // uint8_t data[] = {0};
  // for (int i = 0; i < 128; ++i) {
  //   MyRioI2CDevice i2c_dev(MyRioExpPort::MXP_A, i);
  //   std::cout << i << std::endl;
  //   i2c_dev.read(data, 1);
  //   std::cout << "\n\n\n" << std::endl;
  // }
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
