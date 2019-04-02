#include <iostream>
#include <unistd.h>
#include "MPU9255.hpp"
#include "../robot/MyRioI2CDevice.hpp"

MPU9255::MPU9255(MyRioExpPort port, G_SCALE g_scale = G_SCALE::GFS_250DPS, A_SCALE a_scale = A_SCALE::AFS_2G)
  : i2c_device(new MyRioI2CDevice(port, MPU9250_ADDRESS_AD1))
{
  this->g_scale = g_scale;
  switch (g_scale) {
  case G_SCALE::GFS_250DPS:
    g_scale_val = 131.072;
    break;
  case G_SCALE::GFS_500DPS:
    g_scale_val = 65.536;
    break;
  case G_SCALE::GFS_1000DPS:
    g_scale_val = 32.768;
    break;
  case G_SCALE::GFS_2000DPS:
    g_scale_val = 16.384;
  }

  this->a_scale = a_scale;
  switch (a_scale) {
  case A_SCALE::AFS_2G:
    a_scale_val = 16384.0;
    break;
  case A_SCALE::AFS_4G:
    a_scale_val = 8192.0;
    break;
  case A_SCALE::AFS_8G:
    a_scale_val = 4096.0;
    break;
  case A_SCALE::AFS_16G:
    a_scale_val = 2048.0;
  }
}

void MPU9255::calibrate() {}

void MPU9255::init() {
  uint8_t data_out[2];
  uint8_t data_in[1];

  data_out[0] = PWR_MGMT_1;
  data_out[1] = 0x00;
  i2c_device->write(data_out, 2);
  usleep(1000 * 2000);

  data_out[0] = PWR_MGMT_1;
  data_out[1] = 0x01;
  i2c_device->write(data_out, 2);
  usleep(1000 * 200);

  data_out[0] = CONFIG;
  data_out[1] = 0x03;
  i2c_device->write(data_out, 3);

  data_out[0] = SMPLRT_DIV;
  data_out[1] = 0x04;
  i2c_device->write(data_out, 3);

  data_out[0] = GYRO_CONFIG;
  i2c_device->write(data_out, 2);
  i2c_device->read(data_in, 1);

  data_out[0] = GYRO_CONFIG;
  data_out[1] = data_in[0] & ~0x02;
  i2c_device->write(data_out, 3);

  data_out[0] = GYRO_CONFIG;
  data_out[1] = data_in[0] & ~0x18;
  i2c_device->write(data_out, 3);

  data_out[0] = GYRO_CONFIG;
  data_out[1] = data_in[0] | g_scale << 3;
  i2c_device->write(data_out, 3);

  data_out[0] = ACCEL_CONFIG;
  i2c_device->write(data_out, 2);
  i2c_device->read(data_in, 1);

  data_out[0] = ACCEL_CONFIG;
  data_out[1] = data_in[0] & ~0x18;
  i2c_device->write(data_out, 3);

  data_out[0] = ACCEL_CONFIG;
  data_out[1] = data_in[0] | a_scale << 3;
  i2c_device->write(data_out, 3);

  data_out[0] = ACCEL_CONFIG2;
  i2c_device->write(data_out, 2);
  i2c_device->read(data_in, 1);

  data_out[0] = ACCEL_CONFIG2;
  data_out[1] = data_in[0] & ~0x0F;
  i2c_device->write(data_out, 3);

  data_out[0] = ACCEL_CONFIG2;
  data_out[1] = data_in[0] | 0x03;
  i2c_device->write(data_out, 3);

  data_out[0] = INT_PIN_CFG;
  data_out[1] = 0x22;
  i2c_device->write(data_out, 3);

  data_out[0] = INT_ENABLE;
  data_out[1] = 0x01;
  i2c_device->write(data_out, 3);
  usleep(1000 * 1000);
}

double MPU9255::get_X_angle_accel() {
  uint8_t data_in[2];
  uint8_t data_out[1] = {GYRO_XOUT_H};
  i2c_device->write(data_out, 2);
  i2c_device->read(data_in ,2);

  return (((int16_t)data_in[0] << 8) | data_in[1]) / g_scale_val;
}

double MPU9255::get_Y_angle_accel() {
  uint8_t data_in[2];
  uint8_t data_out[1] = {GYRO_YOUT_H};
  i2c_device->write(data_out, 2);
  i2c_device->read(data_in ,2);

  return (((int16_t)data_in[0] << 8) | data_in[1]) / g_scale_val;
}

double MPU9255::get_Z_angle_accel() {
  uint8_t data_in[2];
  uint8_t data_out[1] = {GYRO_ZOUT_H};
  i2c_device->write(data_out, 2);
  i2c_device->read(data_in ,2);

  return (((int16_t)data_in[0] << 8) | data_in[1]) / g_scale_val;
}
double MPU9255::get_X_angle() {
  return .0;
}
double MPU9255::get_Y_angle() {
  return .0;
}
double MPU9255::get_Z_angle() {
  return .0;
}

double MPU9255::get_X_accel() {
  uint8_t data_in[2];
  uint8_t data_out[1] = {ACCEL_XOUT_H};
  i2c_device->write(data_out, 2);
  i2c_device->read(data_in ,2);

  return (((int16_t)data_in[0] << 8) | data_in[1]) / a_scale_val;
}

double MPU9255::get_Y_accel() {
  uint8_t data_in[2];
  uint8_t data_out[1] = {ACCEL_YOUT_H};
  i2c_device->write(data_out, 2);
  i2c_device->read(data_in ,2);

  return (((int16_t)data_in[0] << 8) | data_in[1]) / a_scale_val;
}

double MPU9255::get_Z_accel() {
  uint8_t data_in[2];
  uint8_t data_out[1] = {ACCEL_ZOUT_H};
  i2c_device->write(data_out, 2);
  i2c_device->read(data_in ,2);

  return (((int16_t)data_in[0] << 8) | data_in[1]) / a_scale_val;
}

double MPU9255::get_X() {
  return .0;
}
double MPU9255::get_Y() {
  return .0;
}
double MPU9255::get_Z() {
  return .0;
}
