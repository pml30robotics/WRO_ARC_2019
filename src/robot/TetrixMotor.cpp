#include "TetrixMotor.hpp"
#include "myRio/MyRio.h"

extern NiFpga_Session myrio_session;

TetrixMotor::TetrixMotor(PWM& pwm, DIO& dio, Encoder& encoder)
  : pwm(&pwm), dio(&dio), encoder(&encoder) {}

TetrixMotor::TetrixMotor(PWM& pwm, DIO& dio)
  : pwm(&pwm), dio(&dio), encoder(nullptr) {}

void TetrixMotor::set_power(int16_t pwr) {
  if (pwr < 0) {
    dio->write(Registers::HIGH);
  } else {
    dio->write(Registers::LOW);
  }
  pwm->write(pwr);
}

int32_t TetrixMotor::get_count() {
  return (encoder != nullptr) ? encoder->get_count() : 0;
}

void TetrixMotor::reset() {
  if (encoder != nullptr)
    encoder->reset();
}
