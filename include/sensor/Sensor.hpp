#ifndef SENSOR_SENSOR_HPP
#define SENSOR_SENSOR_HPP

struct Sensor {
  virtual void calibrate() = 0;
  virtual bool init() = 0;
};

#endif
