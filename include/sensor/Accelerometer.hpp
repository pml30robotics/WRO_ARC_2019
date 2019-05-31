#ifndef SENSOR_ACCELEROMETER_HPP
#define SENSOR_ACCELEROMETER_HPP

struct Accelerometer {
  virtual double get_X_accel() = 0;
  virtual double get_Y_accel() = 0;
  virtual double get_Z_accel() = 0;
};

#endif
