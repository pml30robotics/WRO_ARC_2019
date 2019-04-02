#ifndef SENSOR_GYROSCOPE_HPP
#define SENSOR_GYROSCOPE_HPP

struct Gyroscope {
  virtual double get_X_angle_accel() = 0;
  virtual double get_Y_angle_accel() = 0;
  virtual double get_Z_angle_accel() = 0;

  virtual double get_X_angle() = 0;
  virtual double get_Y_angle() = 0;
  virtual double get_Z_angle() = 0;
};

#endif
