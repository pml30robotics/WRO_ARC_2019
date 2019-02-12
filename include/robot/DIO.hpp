#ifndef ROBOT_DIO_HPP
#define ROBOT_DIO_HPP

#include "Robot.hpp"
#include "myRio/MyRio.h"
#include "Registers.hpp"

struct DIO {
  /* Member functions. */
  DIO(MyRioExpPort port, uint8_t pin, uint8_t dir);
  DIO(MyRioExpPort port, uint8_t pin);
  void write(uint8_t val);
  uint8_t read();
  NiFpga_Status get_status();
private:
  uint8_t pin_resolver(uint8_t pin_num);
  void change_dir(uint32_t reg, uint8_t dir, bool force);
  // Member fields decloration.
  NiFpga_Status status;
  MyRioExpPort port;
  uint32_t pin_register_out;
  uint32_t pin_register_in;
  uint32_t pin_register_dir;
  uint8_t pin_num;
  uint8_t dir;
};

#endif
