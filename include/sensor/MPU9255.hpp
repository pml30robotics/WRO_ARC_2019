#ifndef SENSOR_MPU9255_HPP
#define SENSOR_MPU9255_HPP

#include "../robot/I2CDevice.hpp"
#include "../robot/Robot.hpp"
#include "Gyroscope.hpp"
#include "Sensor.hpp"
#include "Accelerometer.hpp"

#define SMPLRT_DIV 0x19
#define CONFIG 0x1A
#define GYRO_CONFIG 0x1B
#define ACCEL_CONFIG 0x1C
#define ACCEL_CONFIG2 0x1D
#define MOT_DUR 0x20
#define ZMOT_THR 0x21
#define ZRMOT_DUR 0x22
#define INT_PIN_CFG 0x37
#define INT_ENABLE 0x38
#define ACCEL_XOUT_H 0x3B
#define ACCEL_XOUT_L 0x3C
#define ACCEL_YOUT_H 0x3D
#define ACCEL_YOUT_L 0x3E
#define ACCEL_ZOUT_H 0x3F
#define ACCEL_ZOUT_L 0x40
#define TEMP_OUT_H 0x41
#define TEMP_OUT_L 0x42
#define GYRO_XOUT_H 0x43
#define GYRO_XOUT_L 0x44
#define GYRO_YOUT_H 0x45
#define GYRO_YOUT_L 0x46
#define GYRO_ZOUT_H 0x47
#define GYRO_ZOUT_L 0x48
#define PWR_MGMT_1 0x6B
#define WHO_AM_I_MPU9250 0x75
#define XA_OFFSET_H 0x77
#define XA_OFFSET_L 0x78
#define YA_OFFSET_H 0x7A
#define YA_OFFSET_L 0x7B
#define ZA_OFFSET_H 0x7D
#define ZA_OFFSET_L 0x7E
#define MPU9250_ADDRESS_ADO 0x69
#define MPU9250_ADDRESS_AD1 0x68

struct MPU9255 : Sensor, Gyroscope, Accelerometer {
  enum G_SCALE : uint8_t {
    GFS_250DPS = 0,
    GFS_500DPS,
    GFS_1000DPS,
    GFS_2000DPS
  };

  enum A_SCALE : uint8_t {
    AFS_2G = 0,
    AFS_4G,
    AFS_8G,
    AFS_16G
  };

  MPU9255(MyRioExpPort port, G_SCALE g_scale, A_SCALE a_scale);

  // implementation of Sensor interface
  virtual void calibrate();
  virtual void init();

  // implementation of Gyroscope interface
  virtual double get_X_angle_accel();
  virtual double get_Y_angle_accel();
  virtual double get_Z_angle_accel();
  virtual double get_X_angle();
  virtual double get_Y_angle();
  virtual double get_Z_angle();

  // implementation of Gyroscope interface
  virtual double get_X_accel();
  virtual double get_Y_accel();
  virtual double get_Z_accel();
  virtual double get_X();
  virtual double get_Y();
  virtual double get_Z();
private:
  I2CDevice* i2c_device;
  uint8_t g_scale, a_scale;
  float g_scale_val, a_scale_val;
};

#endif
