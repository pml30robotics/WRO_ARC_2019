#include "Robot.hpp"

extern NiFpga_Session myrio_session;

/*
 * Robot member function implementation.
 */

Robot& Robot::get_instance(){
       static Robot instance;
       return instance;
}

NiFpga_Status Robot::get_status() const {
  return status;
}

NiFpga_Status Robot::open_session() {
  return (status = MyRio_Open());
}

NiFpga_Status Robot::close_session() {
  return (status = MyRio_Close());
}
