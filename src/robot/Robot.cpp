#include "Robot.hpp"

extern NiFpga_Session myrio_session;

/*
 * RobotDestroyer member function implementation.
 */
RobotDestroyer::~RobotDestroyer() {
  delete instance_ptr;
}

void RobotDestroyer::init(Robot* robot) {
  instance_ptr = robot;
}

/*
 * Robot member function implementation.
 */
Robot* Robot::instance_ptr = nullptr;
RobotDestroyer Robot::destroyer;

Robot& Robot::get_instance() {
  if (instance_ptr != nullptr) {
    instance_ptr = new Robot();
    destroyer.init(instance_ptr);
  }
  return *instance_ptr;
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
