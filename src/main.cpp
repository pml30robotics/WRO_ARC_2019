#include <iostream>
//#include <time.h>
#include "robot/Robot.hpp"

int main(int argc, char **argv) {
  Robot& robot = Robot::get_instance();
  robot.start_session();
  robot.end_session();
}
