#include "PID.hpp"

PID::PID(double p_k, double i_k, double d_k)
: p_k(p_k), i_k(i_k), d_k(d_k), prev_state(0), int_sum(0), target_state(0) {}

PID::PID() : PID::PID(0, 0, 0) {}

double PID::calc_action(double curr_state, time_t elapsed_time) {
  /*
   https://en.wikipedia.org/wiki/PID_controller#Discrete_implementation
  */
  double curr_error = target_state - curr_state;
  int_sum += curr_error;
  double prev_error = target_state - prev_state;

  double P = p_k * curr_error;
  double I = i_k * elapsed_time * int_sum;
  double D = d_k * (curr_error - prev_error) / elapsed_time;

  return P + I + D;
}
void PID::set_actoin_range(double max, double min) {}

void PID::set_P(double p_k) {
  this->p_k = p_k;
}

void PID::set_I(double i_k) {
  this->i_k = i_k;
}

void PID::set_D(double d_k) {
  this->d_k = d_k;
}

void PID::reset() {
  prev_state = 0;
  int_sum = 0;
  target_state = 0;
}

PID::~PID() {}
