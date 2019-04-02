#include "I2CDevice.hpp"

I2CDevice::I2CDevice(uint8_t address) : i2c_address(address) {}

void I2CDevice::set_address(uint8_t address) {
  i2c_address = address;
}

uint8_t I2CDevice::get_address() {
  return i2c_address;
}
