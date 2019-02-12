#ifndef ROBOT_PWM_HPP
#define ROBOT_PWM_HPP

#include "myRio/MyRio.h"
#include "Robot.hpp"

struct PWM {
  enum : uint8_t {
    ENABLE_MODE = 0b00000100,
    ENABLE_INV = 0b00000001
  };
  /**
   * PWM constructor.
   * @param[in] port MXP.A, MXP.B, MSP port on MyRio.
   * @param[in] cnfg Configure PWM subsystem, first bit determins INV, third bit determins MODE.
   * @param[in] num Number of pwm pin according to default FPGA personality.
   * @param[in] clock Clock settings which set frequency according to f_clk / pwm_clock,
   *  where base clock frequency f_clk is 40Mhz.
   * @param[in] max Sets maximum counter value. The counter counts from 0 to pwm
   *  The final frequency of the PWM waveform is f_clk / pwm_clock / pwm_max,
   *  e.g. 40 MHz / 4 / 1000 = 10 kHz.
   */
  PWM(MyRioExpPort port, uint8_t cnfg, uint8_t num,
    MyRioClockDivider clock, uint16_t max);

  void write(uint16_t val);
  NiFpga_Status get_status() const;
private:
  void init_pwm_subsystem(MyRioConfigBitMask pwm, uint32_t sys_select_reg,
    uint8_t sys_select_prev_val, uint32_t pwm_cnfg_reg, uint32_t pwm_cs_reg, uint32_t pwm_max_reg);
  uint8_t pin_resolver(uint8_t pin_num);
  // Member fields decloration.
  NiFpga_Status status;
  MyRioExpPort port;
  uint8_t cnfg;
  uint8_t num;
  MyRioClockDivider clock;
  uint16_t max;
  uint32_t cmp_reg;
};

#endif
