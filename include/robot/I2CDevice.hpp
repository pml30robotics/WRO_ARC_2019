#ifndef ROBOT_I2C_DEVICE_HPP
#define ROBOT_I2C_DEVICE_HPP

#include "myRio/MyRio.h"

/**
 * @struct I2CDevice
 * @brief Abstract class for i2c devices manipulation.
 */
struct I2CDevice {
  I2CDevice(uint8_t address);

  virtual void request_bytes(uint8_t reg_addr, uint8_t* data, uint32_t num_bytes) = 0;
  virtual void read_bytes(uint8_t* data, uint32_t num_bytes) = 0;
  virtual void write_bytes(uint8_t* data, uint32_t num_bytes) = 0;

  virtual uint8_t read_byte(uint8_t reg_addr) = 0;
  virtual void write_byte(uint8_t reg_addr, uint8_t data) = 0;

  void set_address(uint8_t i2c_address);
  uint8_t get_address();

  virtual ~I2CDevice() {};
protected:
  uint8_t i2c_address;
};

#endif
