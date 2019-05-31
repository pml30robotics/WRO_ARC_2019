#ifndef ROBOT_ROBOT_HPP
#define ROBOT_ROBOT_HPP

#include "myRio/MyRio.h"

/******************************
 *
 * Structs and classes decloration.
 *
 ******************************/
struct Robot;
struct Robot_Config;
struct MXP_Config;

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
  /*
   * Singleton implementation
   */
  static Robot& get_instance();

  NiFpga_Status init(Robot_Config& config);
  NiFpga_Status get_status() const;

  void get_coordinates(double* coord);
  /*
   * Public constansts
   */
  const double G_ACC = 9.81908;
private:
  /*
   * Singleton implementation
   */
  Robot();
  ~Robot();
  Robot(Robot const&) = delete;
  Robot& operator= (Robot const&) = delete;

  // subsystems  initialization
  void i2c_init();

  // coordinates calculation utils
  double simple_kalman_filter(double prev_state, double curr_state, double k);
  double integrate(double prev_state, double curr_state, double elapsed_sec);

  // coordinates calculation variables
  double filtered_acc_prev_state[3] = {.0}; // filtered accel values
  double spd_prev_state[3] = {.0}; // integrated accel values
  double coord_prev_state[3] = {.0}; // integrated speed values
  double kalman_k[3] = {0.02, 0.02, 0.02};

  NiFpga_Status status;
  Robot_Config const* config;

  enum Regissters_Nums {
    I2C_MXP_SYS = 7
  };
};

/**
 * @struct MXP_Config
 * @brief configuration data-only embeddable configuration structure for specified MXP port on myRIO
 */
struct MXP_Config {
  enum : uint8_t {
    I2C_CNTR_DISABLE = 0,
    I2C_CNTR_100_KBPS = 213,
    I2C_CNTR_400_KBPS = 63
  };
  bool I2C_enable;
  uint8_t I2C_cntr;
};

/**
 * @struct RobotConfig
 * @brief configuration data-only structure
 */
struct Robot_Config {
  MXP_Config MXP_A;
  MXP_Config MXP_B;
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
