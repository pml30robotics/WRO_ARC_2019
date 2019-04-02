#include "Robot.hpp"
#include "myRio/MyRio.h"
#include "Registers.hpp"

extern NiFpga_Session myrio_session;

/*
 * Robot member function implementation.
 */

Robot::Robot() : status(0) {
  status = MyRio_Open();
}

Robot::~Robot() {
  MyRio_PrintStatus(MyRio_Close());
}

Robot& Robot::get_instance() {
       static Robot instance;
       return instance;
}

NiFpga_Status Robot::get_status() const {
  return status;
}

NiFpga_Status Robot::init(Robot_Config& config) {
  this->config = &config;
  i2c_init();
  return status;
}

void Robot::i2c_init() {
  if (config->MXP_A.I2C_enable == true) {
    NiFpga_MergeStatus(&status,
      Registers::read_and_update_u8(SYSSELECTA, I2C_MXP_SYS_REGISTER_NUM, 1));

    NiFpga_MergeStatus(&status,
      NiFpga_WriteU8(myrio_session, I2CACNFG, config->MXP_A.I2C_cntr));
  }

  if (config->MXP_B.I2C_enable == true) {
    NiFpga_MergeStatus(&status,
      Registers::read_and_update_u8(SYSSELECTB, I2C_MXP_SYS_REGISTER_NUM, 1));

    NiFpga_MergeStatus(&status,
      NiFpga_WriteU8(myrio_session, I2CACNFG, config->MXP_B.I2C_cntr));
  }
}
