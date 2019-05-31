#ifndef ROBOT_MYRIO_I2C_DEVICE_HPP
#define ROBOT_MYRIO_I2C_DEVICE_HPP

#include "I2CDevice.hpp"
#include "Robot.hpp"
#include "myRio/MyRio.h"

/******************************
 *
 * Enum decloration.
 *
 ******************************/
 /**
  * I2C control options.
  */
 enum I2c_ControlBits {
     I2c_Rx_Tx = 1,   /* 0b00000001 */
     I2c_Start = 2,   /* 0b00000010 */
     I2c_Stop = 4,    /* 0b00000100 */
     I2c_Ack = 8      /* 0b00001000 */
 };

 /**
  * I2C status options.
  */
 enum I2c_StatusBits {
     I2c_Busy = 1,         /* 0b00000001 */
     I2c_Error = 2,        /* 0b00000010 */
     I2c_Address_Nak = 4,  /* 0b00000100 */
     I2c_Data_Nak = 8,     /* 0b00001000 */
     I2c_In_Use = 16,      /* 0b00010000 */
     I2c_Bus_Busy = 32     /* 0b00100000 */
 };

/**
 * @struct MyRioI2CDevice
 * @brief Concrete class for myRio i2c devices manipulation.
 */
struct MyRioI2CDevice: I2CDevice {
  MyRioI2CDevice(MyRioExpPort port, uint8_t address);

  virtual void request_bytes(uint8_t reg_addr, uint8_t* data, uint32_t num_bytes);
  virtual void read_bytes(uint8_t* data, uint32_t num_bytes);
  virtual void write_bytes(uint8_t* data, uint32_t num_bytes);

  virtual uint8_t read_byte(uint8_t reg_addr);
  virtual void write_byte(uint8_t reg_addr, uint8_t data);

  NiFpga_Status get_status() const;
private:
  NiFpga_Status status;
  uint32_t address_reg;
  uint32_t cntl_reg;
  uint32_t stat_reg;
  uint32_t go_reg;
  uint32_t data_in_reg;
  uint32_t data_out_reg;
};

#endif
