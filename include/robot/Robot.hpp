#ifndef ROBOT_ROBOT_HPP
#define ROBOT_ROBOT_HPP

#include "myRio/MyRio.h"
#include <unistd.h>

/******************************
 *
 * Structs and classes decloration.
 *
 ******************************/
struct Robot;

/******************************
 *
 * Enum decloration.
 *
 ******************************/
enum struct MyRioExpPort;
enum struct MyRioClockDivider : uint8_t;
enum struct MyRioConfigBitMask : uint8_t;

/**
 * @struct Robot
 * @brief Singleton class for robot hardware configuration.
 */

struct Robot {
  static Robot& get_instance();
  NiFpga_Status get_status() const;
private:
  Robot();
  ~Robot();

  Robot(Robot const&) = delete;
  Robot& operator= (Robot const&) = delete;

  NiFpga_Status status;
};

/**
 * @enum MyRioExpPort
 * @brief NI MyRio expansion ports definition.
 */
enum struct MyRioExpPort { MXP_A, MXP_B, MSP };

/**
 * @enum MyRioClockDivider
 * @brief Clock divider constansts for PWM, SPI subsystems configurations.
 */
enum struct MyRioClockDivider : uint8_t {
  CLOCK_DIV_OFF = 0b00000000,
  CLOCK_DIV_1 = 0b00000001,
  CLOCK_DIV_2 = 0b00000010,
  CLOCK_DIV_4 = 0b00000011,
  CLOCK_DIV_8 = 0b00000100,
  CLOCK_DIV_16 = 0b00000101,
  CLOCK_DIV_32 = 0b00000110,
  CLOCK_DIV_64 = 0b00000111
};

/**
 * @enum MyRioConfigBitMasks
 * @brief Bit masks for configuration of defult FPGA personality.
 */
enum struct MyRioConfigBitMask : uint8_t {
  // MSP
  MSP_PWM0_ENABLE = 0b00000010,
  MSP_PWM1_ENABLE = 0b00001000,
  MSP_ENC0_ENABLE = 0b00000001,
  MSP_ENC1_ENABLE = 0b00000100,
  // MXP
  MXP_PWM0_ENABLE = 0b00000100,
  MXP_PWM1_ENABLE = 0b00001000,
  MXP_PWM2_ENABLE = 0b00010000,
};

#endif
