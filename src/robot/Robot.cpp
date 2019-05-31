#include <unistd.h>
#include <chrono>
#include <cmath>
#include <cstdio>

#include "Robot.hpp"
#include "myRio/MyRio.h"
#include "Registers.hpp"
#include "sensor/MPU9255.hpp"

extern NiFpga_Session myrio_session;

/*
 * Robot member function implementation.
 */

Robot::Robot() : status(0) {
  status = MyRio_Open();
}

Robot::~Robot() {
  MyRio_PrintStatus(MyRio_Close());
}

Robot& Robot::get_instance() {
       static Robot instance;
       return instance;
}

NiFpga_Status Robot::get_status() const {
  return status;
}

NiFpga_Status Robot::init(Robot_Config& config) {
  this->config = &config;
  i2c_init();
  return status;
}

void Robot::get_coordinates(double* coord) {
  MPU9255 mpu9255 = MPU9255(MyRioExpPort::MXP_A);
  mpu9255.init();

  // accel settings
  mpu9255.set_accel_scale(scale_2g);
  mpu9255.set_accel_bandwidth(acc_5Hz);

  // gyro settings
  mpu9255.set_gyro_scale(scale_250dps);
  mpu9255.set_gyro_bandwidth(gyro_5Hz);

  printf("Offset adjustment:\n");
  mpu9255.offset_adjust();
  printf("Done: Offset adjustment!\n");

  double curr_acc_val[3] = {.0};
  double curr_spd_val[3] = {.0};
  double curr_coord_val[3] = {.0};

  long cnt = 0;
  auto prev_time = std::chrono::system_clock::now();
  for (;;) {
    mpu9255.read_accel();

    curr_acc_val[0] = mpu9255.get_X_accel();
    curr_acc_val[1] = mpu9255.get_Y_accel();
    curr_acc_val[2] = mpu9255.get_Z_accel();

    auto curr_time = std::chrono::system_clock::now();
    for (int i = 0; i < 3; i++) {
      std::chrono::duration<double> elapsed = curr_time - prev_time;
      double elapsed_time = elapsed.count();
      // convert g to m/s^2
      curr_acc_val[i] = curr_acc_val[i] * G_ACC;
      // filter accel values
      curr_acc_val[i] = simple_kalman_filter(filtered_acc_prev_state[i], curr_acc_val[i], kalman_k[i]);
      // get first integral - speed in m/s
      curr_spd_val[i] += integrate(filtered_acc_prev_state[i], curr_acc_val[i], elapsed_time);
      // get second integral - coordinates in m
      curr_coord_val[i] += integrate(spd_prev_state[i], curr_spd_val[i], elapsed_time);

      filtered_acc_prev_state[i] = curr_acc_val[i];
      spd_prev_state[i] = curr_spd_val[i];
      coord_prev_state[i] = curr_coord_val[i];
      prev_time = curr_time;
    }

    if (cnt++ % 10 == 0) {
      printf("X: %f, Y: %f, Z: %f\n", curr_spd_val[0], curr_spd_val[1], curr_spd_val[2]);
    }

    usleep(1000 * 100);
  }
}

/*
 * private methods implementation
 */

void Robot::i2c_init() {
  if (config->MXP_A.I2C_enable == true) {
    NiFpga_MergeStatus(&status,
      Registers::read_and_update_u8(SYSSELECTA, I2C_MXP_SYS, 0x01));

    // enabling i2c
    NiFpga_MergeStatus(&status,
      NiFpga_WriteU8(myrio_session, I2CACNFG, 0x01));

    // set i2c counter
    NiFpga_MergeStatus(&status,
      NiFpga_WriteU8(myrio_session, I2CACNTR, config->MXP_A.I2C_cntr));
  }

  if (config->MXP_B.I2C_enable == true) {
    NiFpga_MergeStatus(&status,
      Registers::read_and_update_u8(SYSSELECTB, I2C_MXP_SYS , 0x01));

    // enabling i2c
    NiFpga_MergeStatus(&status,
      NiFpga_WriteU8(myrio_session, I2CBCNFG, 0x01));

    // set i2c counter
    NiFpga_MergeStatus(&status,
      NiFpga_WriteU8(myrio_session, I2CBCNTR, config->MXP_B.I2C_cntr));
  }
}

// coordinates calculation utils
double Robot::simple_kalman_filter(double prev_state, double curr_state, double k) {
  return k * curr_state + (1 - k) * prev_state;
}

// https://en.wikipedia.org/wiki/Trapezoidal_rule
double Robot::integrate(double prev_state, double curr_state, double elapsed_sec) {
  return (curr_state + prev_state) / 2 * elapsed_sec;
}
