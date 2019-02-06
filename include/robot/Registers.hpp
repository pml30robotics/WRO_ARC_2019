#ifndef ROBOT_REGISTERS_HPP
#define ROBOT_REGISTERS_HPP

#include "myRio/MyRio.h"
#include "myRio_enums.hpp"

struct Registers {
  enum : uint8_t {
    LOW = 0,
    HIGH = 1,
    INPUT = 2,
    OUTPUT = 3
  };

  static NiFpga_Status read_and_update_u8(uint32_t reg, uint8_t bit_num, uint8_t val);
private:
  Registers() {};
};

#endif
