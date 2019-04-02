#ifndef ROBOT_PID_HPP
#define ROBOT_PID_HPP

#include <ctime>

struct PID {
  PID(double p_k, double i_k, double d_k);
  PID();

  double calc_action(double curr_state, time_t elapsed_time);
  void set_actoin_range(double max, double min);

  void set_P(double p_k);
  void set_I(double p_i);
  void set_D(double p_d);
  
  void reset();
  ~PID();
private:
  // coefficients
  double p_k;
  double i_k;
  double d_k;

  double prev_state;
  double int_sum;
  double target_state;
};

#endif
