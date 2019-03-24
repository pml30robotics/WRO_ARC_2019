#include "Robot.hpp"
#include "myRio/MyRio.h"

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
