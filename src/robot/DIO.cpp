#include "DIO.hpp"

extern NiFpga_Session myrio_session;

DIO::DIO(MyRioExpPort port, uint8_t pin, Direction dir)
: status(0), port(port), dir(dir)
{
  this->pin_num = pin_resolver(pin);

  switch (port) {
    case MyRioExpPort::MSP:
      pin_register_in = DIOC_70IN;
      pin_register_out = DIOC_70OUT;
      pin_register_dir = DIOC_70DIR;
      break;
    case MyRioExpPort::MXP_A:
      if (pin > 7) {
        pin_register_in = DIOA_158IN;
        pin_register_out = DIOA_158OUT;
        pin_register_dir = DIOA_158DIR;
      } else {
        pin_register_in = DIOA_70IN;
        pin_register_out = DIOA_70OUT;
        pin_register_dir = DIOA_70DIR;
      }
      break;
    case MyRioExpPort::MXP_B:
      if (pin > 7) {
        pin_register_in = DIOB_158IN;
        pin_register_out = DIOB_158OUT;
        pin_register_dir = DIOB_158DIR;
      } else {
        pin_register_in = DIOB_70IN;
        pin_register_out = DIOB_70OUT;
        pin_register_dir = DIOB_70DIR;
      }
  }
  change_dir(dir);
}

DIO::DIO(MyRioExpPort port, uint8_t pin)
: DIO::DIO(port, pin, DIO::Direction::INPUT) {}

void DIO::write(uint8_t val) {
  if (this->dir != DIO::Direction::OUTPUT)
    change_dir(DIO::Direction::OUTPUT);

  val = ((val == 0) ? Registers::LOW : Registers::HIGH);
  NiFpga_MergeStatus(&status,
    Registers::read_and_update_u8(pin_register_out, pin_num, val));
}

uint8_t DIO::read() {
  if (this->dir != DIO::Direction::INPUT)
    change_dir(DIO::Direction::INPUT);

  uint8_t raw_val;
  NiFpga_MergeStatus(&status,
    NiFpga_ReadU8(myrio_session, pin_register_in, &raw_val));

  raw_val &= (0x01 << pin_num);
  return (raw_val == 0) ? Registers::LOW : Registers::HIGH;
}

NiFpga_Status DIO::get_status() {
  return status;
}

void DIO::change_dir(DIO::Direction dir) {
  this->dir = dir;
  uint8_t output_dir = ((dir == DIO::Direction::OUTPUT) ? Registers::HIGH : Registers::LOW);
  NiFpga_MergeStatus(&status,
    Registers::read_and_update_u8(pin_register_dir, pin_num, output_dir));
}

/*
 * Private member functions implementation.
 */
uint8_t DIO::pin_resolver(uint8_t pin_num) {
  switch (port) {
    case MyRioExpPort::MSP:
      pin_num %= 8;
      break;
    case MyRioExpPort::MXP_A: case MyRioExpPort::MXP_B:
      pin_num %= 16;
      (pin_num > 7) ? pin_num -= 8 : 0;  // 0 is no-op
  }
  return pin_num;
}
