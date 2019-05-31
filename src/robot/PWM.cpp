#include "PWM.hpp"

extern NiFpga_Session myrio_session;

PWM::PWM(MyRioExpPort port, uint8_t pwm_cnfg, uint8_t pwm_num,
  MyRioClockDivider pwm_clock, uint16_t pwm_max)
  : status(0), port(port), cnfg(pwm_cnfg), num(pwm_num), clock(pwm_clock), max(pwm_max)
{
  num = pin_resolver(pwm_num);

  uint8_t sys_select;
  switch (port) {
    case MyRioExpPort::MSP:
      // get current state of SYS.SELECTC register
      NiFpga_MergeStatus(&status,
        NiFpga_ReadU8(myrio_session, SYSSELECTC, &sys_select));
      if (num == 0) {
        // enable PWM0 on MSP
        init_pwm_subsystem(MyRioConfigBitMask::MSP_PWM0_ENABLE, SYSSELECTC,
          sys_select, PWMC_0CNFG, PWMC_0CS, PWMC_0MAX);
        cmp_reg = PWMC_0CMP;
      } else {
        // enable PWM1 on MSP
        init_pwm_subsystem(MyRioConfigBitMask::MSP_PWM1_ENABLE, SYSSELECTC,
          sys_select, PWMC_1CNFG, PWMC_1CS, PWMC_1MAX);
        cmp_reg = PWMC_1CMP;
      }
      break;
    case MyRioExpPort::MXP_A:
      // get current state of SYS.SELECTA register
      NiFpga_MergeStatus(&status,
        NiFpga_ReadU8(myrio_session, SYSSELECTA, &sys_select));
      if (num == 0) {
        // enable PWM0 on MXP A
        init_pwm_subsystem(MyRioConfigBitMask::MXP_PWM0_ENABLE, SYSSELECTA,
          sys_select, PWMA_0CNFG, PWMA_0CS, PWMA_0MAX);
        cmp_reg = PWMA_0CMP;
      } else if (num == 1) {
        // enable PWM1 on MXP A
        init_pwm_subsystem(MyRioConfigBitMask::MXP_PWM1_ENABLE, SYSSELECTA,
          sys_select, PWMA_1CNFG, PWMA_1CS, PWMA_1MAX);
        cmp_reg = PWMA_1CMP;
      } else {
        // enable PWM2 on MXP A
        init_pwm_subsystem(MyRioConfigBitMask::MXP_PWM2_ENABLE, SYSSELECTA,
          sys_select, PWMA_2CNFG, PWMA_2CS, PWMA_2MAX);
        cmp_reg = PWMA_2CMP;
      }
      break;
    case MyRioExpPort::MXP_B:
      // get current state of SYS.SELECTB register
      NiFpga_MergeStatus(&status,
        NiFpga_ReadU8(myrio_session, SYSSELECTB, &sys_select));
      if (num == 0) {
        // enable PWM0 on MXP B
        init_pwm_subsystem(MyRioConfigBitMask::MXP_PWM0_ENABLE, SYSSELECTB,
          sys_select, PWMB_0CNFG, PWMB_0CS, PWMB_0MAX);
        cmp_reg = PWMB_0CMP;
      } else if (num == 1) {
        // enable PWM1 on MXP B
        init_pwm_subsystem(MyRioConfigBitMask::MXP_PWM1_ENABLE, SYSSELECTB,
          sys_select, PWMB_1CNFG, PWMB_1CS, PWMB_1MAX);
        cmp_reg = PWMB_1CMP;
      } else {
        // enable PWM2 on MXP B
        init_pwm_subsystem(MyRioConfigBitMask::MXP_PWM2_ENABLE, SYSSELECTB,
          sys_select, PWMB_2CNFG, PWMB_2CS, PWMB_2MAX);
        cmp_reg = PWMB_2CMP;
      }
  }
}

void PWM::write(uint16_t val) {
  NiFpga_MergeStatus(&status,
    NiFpga_WriteU16(myrio_session, cmp_reg, (val > max) ? max : val));
}

NiFpga_Status PWM::get_status() const {
  return status;
}

/*
 * Private member functions implementation.
 */
uint8_t PWM::pin_resolver(uint8_t pin_num) {
  switch (port) {
    case MyRioExpPort::MSP:
      pin_num %= 2;
      break;
    case MyRioExpPort::MXP_A: case MyRioExpPort::MXP_B:
      pin_num %= 3;
  }
  return pin_num;
}

void PWM::init_pwm_subsystem(MyRioConfigBitMask pwm, uint32_t sys_select_reg,
  uint8_t sys_select_prev_val ,uint32_t pwm_cnfg_reg, uint32_t pwm_cs_reg, uint32_t pwm_max_reg)
{
  // enable pwm on sys_select
  uint8_t sys_select_new_mask = sys_select_prev_val | static_cast<uint8_t>(pwm);
  NiFpga_MergeStatus(&status,
    NiFpga_WriteU8(myrio_session, sys_select_reg, sys_select_new_mask));
  // PWM config
  NiFpga_MergeStatus(&status,
    NiFpga_WriteU8(myrio_session, pwm_cnfg_reg, cnfg));
  NiFpga_MergeStatus(&status,
    NiFpga_WriteU8(myrio_session, pwm_cs_reg, static_cast<uint8_t>(clock)));
  NiFpga_MergeStatus(&status,
    NiFpga_WriteU16(myrio_session, pwm_max_reg, max));
}
