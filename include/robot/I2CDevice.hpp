#ifndef ROBOT_I2C_DEVICE_HPP
#define ROBOT_I2C_DEVICE_HPP

#include "myRio/MyRio.h"

/**
 * @struct I2CDevice
 * @brief Abstract class for i2c devices manipulation.
 */
struct I2CDevice {
  I2CDevice(uint8_t address);

  virtual void request_bytes(uint8_t req_addr, uint8_t* data, uint32_t numBytes) = 0;
  virtual void read(uint8_t* data, uint32_t numBytes) = 0;
  virtual void write(uint8_t* data, uint32_t numBytes) = 0;

  void set_address(uint8_t i2c_address);
  uint8_t get_address();

  virtual ~I2CDevice() {};
protected:
  uint8_t i2c_address;
};

#endif
