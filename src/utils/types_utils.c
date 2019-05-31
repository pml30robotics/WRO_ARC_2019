#include "types_utils.h"

uint16_t uint8_to_uint16(uint8_t low_byte, uint8_t high_byte) {
  return ((int16_t)high_byte << 8) | low_byte;
}
