#ifndef TYPES_UTILS_UTILS_H
#define TYPES_UTILS_UTILS_H

#include <stdint.h>

#if NiFpga_Cpp
extern "C" {
#endif

uint16_t uint8_to_uint16(uint8_t high_byte, uint8_t low_byte);

#if NiFpga_Cpp
}
#endif

#endif
