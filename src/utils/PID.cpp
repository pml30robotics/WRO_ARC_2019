#include "PID.hpp"

PID::PID(double p_k, double i_k, double d_k)
: p_k(p_k), i_k(i_k), d_k(d_k), prev_state(0), int_sum(0), target_state(0) {}

PID::PID() : PID::PID(0, 0, 0) {}

double PID::calc_action(double curr_state, time_t elapsed_time) {
  /*
   https://en.wikipedia.org/wiki/PID_controller#Discrete_implementation
   with manual tuning method
  */
  double curr_error = target_state - curr_state;
  int_sum += curr_error;
  double prev_error = target_state - prev_state;

  double P = ((p_k != 0) ? p_k * curr_error : 0);
  double I = ((i_k != 0) ? i_k * elapsed_time * int_sum : 0);
  double D = ((d_k != 0) ? d_k * (curr_error - prev_error) / elapsed_time : 0);

  return P + I + D;
}
void PID::set_actoin_range(double max, double min) {}
void PID::set_target(double target_state) {}
void PID::set_P(double p_k) {}
void PID::set_I(double p_i) {}
void PID::set_D(double p_d) {}
void PID::reset() {}
PID::~PID() {}
