#ifndef SENSOR_MPU9255_HPP
#define SENSOR_MPU9255_HPP

#include "robot/I2CDevice.hpp"
#include "robot/Robot.hpp"
#include "Gyroscope.hpp"
#include "Sensor.hpp"
#include "Accelerometer.hpp"

#include <stdint.h>

//available scalese
enum scales {
  scale_2g,//+-2g
  scale_4g,//+-4g
  scale_8g,//+-8g
  scale_16g,//+-16g
  scale_250dps,//+-250 degrees per second
  scale_500dps,//+- 500 degrees per second
  scale_1000dps,//+- 1000 degrees per second
  scale_2000dps,//+- 2000 degrees per second
};

//axis
enum axis
{
  X_axis,
  Y_axis,
  Z_axis,
};

//bandwidth
enum bandwidth {
  gyro_8800Hz,
  gyro_3600Hz,
  gyro_250Hz,
  gyro_184Hz,
  gyro_92Hz,
  gyro_41Hz,
  gyro_20Hz,
  gyro_10Hz,
  gyro_5Hz,
  acc_1113Hz,
  acc_460Hz,
  acc_184Hz,
  acc_92Hz,
  acc_41Hz,
  acc_20Hz,
  acc_10Hz,
  acc_5Hz,
};

struct MPU9255 : Sensor, Gyroscope, Accelerometer {

  MPU9255(MyRioExpPort port);

  // implementation of Sensor interface
  virtual void calibrate();
  virtual bool init();

  // implementation of Gyroscope interface
  virtual double get_X_angle_accel();
  virtual double get_Y_angle_accel();
  virtual double get_Z_angle_accel();

  // implementation of Accelerometer interface
  virtual double get_X_accel();
  virtual double get_Y_accel();
  virtual double get_Z_accel();

  /******************************
   * Other methods
   ******************************/
  void read_accel();
  void read_gyro();
  bool test();
  void offset_adjust();

  // chip settings
  void hard_reset();
  void set_accel_scale(scales selected_scale);
  void set_gyro_scale(scales selected_scale);
  void set_gyro_bandwidth(bandwidth selected_bandwidth);
  void set_accel_bandwidth(bandwidth selected_bandwidth);
  void set_acc_offset(axis selected_axis, int16_t offset);
  void set_gyro_offset(axis selected_axis, int16_t offset);
private:
  // i2c util function
  void write_AND(uint8_t reg_addres, uint8_t data);
  void write_OR(uint8_t reg_addres, uint8_t data);

  I2CDevice* i2c_device;

  /*
    To get acceleration in 'g', each reading has to be divided by :
    -> 16384 for +- 2g scale (default scale)
    -> 8192  for +- 4g scale
    -> 4096  for +- 8g scale
    -> 2048  for +- 16g scale
 */
  double a_scale = 16384.0;

  /*
    To get rotation velocity in dps (degrees per second), each reading has to be divided by :
    -> 131   for +- 250  dps scale (default value)
    -> 65.5  for +- 500  dps scale
    -> 32.8  for +- 1000 dps scale
    -> 16.4  for +- 2000 dps scale
  */
  double g_scale = 131;

  //accelerometer factory offset
  int AX_offset; //X axis
  int AY_offset; //Y axis
  int AZ_offset; //Z axis

  //gyroscope factory offset
  int GX_offset; //X axis
  int GY_offset; //Y axis
  int GZ_offset; //Z axisv

  //acceleration raw data
  int16_t ax = 0; //X axis
  int16_t ay = 0; //Y axis
  int16_t az = 0; //Z axis

  //gyroscope raw data
  int16_t gx = 0; //X axis
  int16_t gy = 0; //Y axis
  int16_t gz = 0; //Z axis

  // registers map
  enum registers {
    //sensor adresses
    MAG_address       = 0x0C, //magnetometer
    MPU_address       = 0x68, //main chip

    //main chip
    USER_CTRL         = 0x6A,
    PWR_MGMT_1        = 0x6B,
    PWR_MGMT_2        = 0x6C,
    SIGNAL_PATH_RESET = 0x68,
    INT_PIN_CFG       = 0x37,
    ST1               = 0x02,
    ACCEL_CONFIG      = 0x1C,
    ACCEL_CONFIG_2    = 0x1D,
    MOT_DETECT_CTRL   = 0x69,
    WOM_THR           = 0x1F,
    GYRO_CONFIG       = 0x1B,
    CONFIG            = 0x1A,
    SMPLRT_DIV        = 0x19,
    INT_ENABLE        = 0x38,
    INT_STATUS        = 0x3A,
    WHO_AM_I          = 0x75,

    //gyroscope offset
    XG_OFFSET_H       = 0x13,
    XG_OFFSET_L       = 0x14,
    YG_OFFSET_H       = 0x15,
    YG_OFFSET_L       = 0x16,
    ZG_OFFSET_H       = 0x17,
    ZG_OFFSET_L       = 0x18,

    //accelerometer offset
    XA_OFFSET_H       = 0x77,
    XA_OFFSET_L       = 0x78,
    YA_OFFSET_H       = 0x7A,
    YA_OFFSET_L       = 0x7B,
    ZA_OFFSET_H       = 0x7D,
    ZA_OFFSET_L       = 0x7E,

    //magnetometer
    MAG_ID            = 0x00,
    CNTL              = 0x0A,
    CNTL2             = 0x0B,
    ASAX              = 0x10,
    ASAY              = 0x11,
    ASAZ              = 0x12,

    /// data registers
    MAG_XOUT_L        = 0x03,//magnetometer
    GYRO_XOUT_H       = 0x43,//gyro
    ACCEL_XOUT_H      = 0x3B,//accelerometer
    TEMP_OUT_H        = 0x41,//thermometer
  };
};

#endif
