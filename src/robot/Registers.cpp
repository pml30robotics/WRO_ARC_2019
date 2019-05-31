#include <iostream>
#include "Registers.hpp"

extern NiFpga_Session myrio_session;

NiFpga_Status Registers::read_and_update_u8(uint32_t reg, uint8_t bit_num, uint8_t val) {
  NiFpga_Status status = 0;
  uint8_t current_reg_state;
  uint8_t mod_register_mask = 0x1 << bit_num;

  // get current state of reg register
  NiFpga_MergeStatus(&status,
    NiFpga_ReadU8(myrio_session, reg, &current_reg_state));
  if (val == 0) {
    mod_register_mask = ~mod_register_mask;
    current_reg_state &= mod_register_mask;
  } else {
    current_reg_state |= mod_register_mask;
  }

  // write updated value into reg register
  NiFpga_MergeStatus(&status,
    NiFpga_WriteU8(myrio_session, reg, current_reg_state));
  return status;
}
