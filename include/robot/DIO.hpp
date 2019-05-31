#ifndef ROBOT_DIO_HPP
#define ROBOT_DIO_HPP

#include "Robot.hpp"
#include "myRio/MyRio.h"
#include "Registers.hpp"

struct DIO {
  enum Direction : uint8_t {
    INPUT = 0,
    OUTPUT = 1
  };
  /* Member functions. */
  DIO(MyRioExpPort port, uint8_t pin, Direction dir);
  DIO(MyRioExpPort port, uint8_t pin);
  void write(uint8_t val);
  uint8_t read();
  void change_dir(Direction dir);
  NiFpga_Status get_status();
private:
  uint8_t pin_resolver(uint8_t pin_num);
  // Member fields decloration.
  NiFpga_Status status;
  MyRioExpPort port;
  uint32_t pin_register_out;
  uint32_t pin_register_in;
  uint32_t pin_register_dir;
  uint8_t pin_num;
  Direction dir;
};

#endif
