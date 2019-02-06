#ifndef ROBOT_ENCODER_HPP
#define ROBOT_ENCODER_HPP

#include "myRio/MyRio.h"
/**
 * Encoder interface
 */
struct Encoder {
  virtual int32_t get_count() = 0;
  virtual void reset() = 0;

  virtual ~Encoder() {};
};

#endif
