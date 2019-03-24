#include "DiamondChassis.hpp"
#include "myRio/MyRio.h"

extern NiFpga_Session myrio_session;

DiamondChassis::DiamondChassis(Motor& rf_motor, Motor& lf_motor, Motor& rb_motor, Motor& lb_motor)
  : motors{&rf_motor, &lf_motor, &rb_motor, &lb_motor} {}

void DiamondChassis::drive_forward() {
  motors[RF_MOT]->set_power(-MAX_SPEED);
  motors[LF_MOT]->set_power(MAX_SPEED);

  motors[RB_MOT]->set_power(MAX_SPEED);
  motors[LB_MOT]->set_power(-MAX_SPEED);
}

void DiamondChassis::stop() {
  for (int i = 0; i < NUM_OF_WHEELS; ++i) {
    motors[0]->set_power(0);
  }
}
