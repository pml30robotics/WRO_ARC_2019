#ifndef ROBOT_MYRIO_ENCODER_HPP
#define ROBOT_MYRIO_ENCODER_HPP

#include "Encoder.hpp"
#include "Robot.hpp"
#include "Registers.hpp"

struct MyRioEncoder : Encoder {
  enum : uint8_t {
    CNFG_COVR = 0b00010000,
    CNFG_CERR = 0b00001000,
    CNFG_MODE = 0b00000100,
    CNFG_RST = 0b00000010,
    CNFG_EN = 0b00000001,

  };

  MyRioEncoder(MyRioExpPort port, uint8_t enc_cnfg, uint8_t enc_num);
  NiFpga_Status get_status() const;

  // implementation of Encoder interface
  virtual int32_t get_count();
  virtual void reset();
private:
  NiFpga_Status status;
  MyRioExpPort port;
  uint32_t cnfg_reg;
  uint32_t cntr_reg;
};

#endif
