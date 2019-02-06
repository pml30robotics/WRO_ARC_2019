#ifndef ROBOT_ROBOT_HPP
#define ROBOT_ROBOT_HPP

#include "myRio/MyRio.h"
#include "myRio_enums.hpp"

/**
 * Structs and classes decloration.
 */
struct Robot;
struct RobotDestroyer;
struct PWMSetup;
struct DIO;
struct PWM;
struct DIOConfig;

/**
 * @enum RobotDestroyer
 * @brief Utiluty class for Robot object destruction.
 */
struct RobotDestroyer {
  ~RobotDestroyer();
  void init(Robot* robot);
private:
  Robot* instance_ptr;
};

/**
 * @enum Robot
 * @brief Singleton class for robot hardware configuration.
 */
struct Robot {
  static Robot& get_instance();
private:
  Robot() {};
  Robot(Robot const &);
  Robot& operator=(Robot&);
  ~Robot() {};
  friend struct RobotDestroyer;
  // Member fields decloration.
  static Robot* instance_ptr;
  static RobotDestroyer destroyer;
};

/**
 * @struct PwmSetup
 * @brief Structure describing PWM initializing settings.
 */
struct PWMSetup {
  MyRioExpPort port; /**< MXP.A, MXP.B, MSP port on MyRio. */
  uint8_t pwm_cnfg; /**< Configure PWM subsystem, first bit determins INV, third bit determins MODE. */
  uint8_t pwm_num; /**< Number of pwm pin according to default FPGA personality. */
  MyRioClockDivider pwm_clock; /**<  Clock settings which set frequency according to f_clk / pwm_clock,
    * where base clock frequency f_clk is 40Mhz. */
  uint16_t pwm_max; /**< Sets maximum counter value. The counter counts from 0 to pwm
    * The final frequency of the PWM waveform is f_clk / pwm_clock / pwm_max,
    * e.g. 40 MHz / 4 / 1000 = 10 kHz. */
};

/**
 * @struct PwmConfig
 * @brief Structure contains ready-to-use PWM information.
 */
struct PWM {
  uint32_t pwm_cmp; /**< Compare register, e.g. PWMA_1CMP. */
  uint16_t pwm_resolution; /**< Maximum count of pwm */
};

#endif
