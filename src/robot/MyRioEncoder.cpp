#include <unistd.h>
#include "MyRioEncoder.hpp"

extern NiFpga_Session myrio_session;

MyRioEncoder::MyRioEncoder(MyRioExpPort port, uint8_t enc_cnfg, uint8_t enc_num)
: port(port)
{
  switch (port) {
    case MyRioExpPort::MSP:
      enc_num = enc_num % 2;
      if (enc_num == 0) {
        // enable ENC0 on MSP
        Registers::read_and_update_u8(SYSSELECTC, 0, 1);
        NiFpga_MergeStatus(&status,
          NiFpga_WriteU8(myrio_session, ENCC_0CNFG, enc_cnfg));
        cntr_reg = ENCC_0CNTR;
        cnfg_reg = ENCC_0CNFG;
      } else {
        // enable ENC1 on MSP
        Registers::read_and_update_u8(SYSSELECTC, 2, 1);
        NiFpga_MergeStatus(&status,
          NiFpga_WriteU8(myrio_session, ENCC_1CNFG, enc_cnfg));
        cntr_reg = ENCC_1CNTR;
        cnfg_reg = ENCC_1CNFG;
      }
      break;
    case MyRioExpPort::MXP_A:
      // enable ENC on MXP A
      Registers::read_and_update_u8(SYSSELECTA, 5, 1);
      NiFpga_MergeStatus(&status,
        NiFpga_WriteU8(myrio_session, ENCACNFG, enc_cnfg));
      cntr_reg = ENCACNTR;
      cnfg_reg = ENCACNFG;
      break;
    case MyRioExpPort::MXP_B:
      // enable ENC on MXP A
      Registers::read_and_update_u8(SYSSELECTB, 5, 1);
      NiFpga_MergeStatus(&status,
        NiFpga_WriteU8(myrio_session, ENCBCNFG, enc_cnfg));
      cntr_reg = ENCBCNTR;
      cnfg_reg = ENCBCNFG;
  }

}

int32_t MyRioEncoder::get_count() {
  int32_t enc_val;
  NiFpga_MergeStatus(&status,
    NiFpga_ReadI32(myrio_session, cntr_reg, &enc_val));
  return enc_val;
}

void MyRioEncoder::reset() {
  Registers::read_and_update_u8(cnfg_reg, 1, 1);
  usleep(500); // sleeps for half milliseconds
  Registers::read_and_update_u8(cnfg_reg, 1, 0);
}

NiFpga_Status MyRioEncoder::get_status() const {
  return status;
}
