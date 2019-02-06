#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>
#include "robot/myRio/MyRio.h"

extern NiFpga_Session myrio_session;

int main(int argc, char **argv) {
  NiFpga_Status status;
  uint8_t sys_select_a;

  status = MyRio_Open();

  if (MyRio_IsNotSuccess(status))
    return status;

  // get current state of SYS.SELECTA register
  NiFpga_MergeStatus(&status,
    NiFpga_ReadU8(myrio_session, SYSSELECTA, &sys_select_a));

  // enable PWM1 on MXP A
  sys_select_a |=  0b00001000;
  // enable DIO10 on MXP A
  sys_select_a &=  0b11101111;
  NiFpga_MergeStatus(&status,
    NiFpga_WriteU8(myrio_session, SYSSELECTA, sys_select_a));

  MyRio_ReturnValueIfNotSuccess(status, status,
    "Could not write to the or SYS.SELECTC channel registers!");

  /*
    Setting up PWM for controling motor1 thru Digilrnt motor adapter
   */

  // confugering PWM.A_1.CNFG register with PWM enable, invert
  NiFpga_MergeStatus(&status,
    NiFpga_WriteU8(myrio_session, PWMA_1CNFG, (uint8_t) 0b00000101));

  // setup PWM.A_1.CS with 4 divider. PWM frequency = 40MHz / 4 = 10 MHz
  NiFpga_MergeStatus(&status,
    NiFpga_WriteU8(myrio_session, PWMA_1CS, (uint8_t) 0b00000011));

  // set counter maximum to 100. PWM frequency = 40MHz / 4 = 10 MHz / 1000 = 100kHz
  NiFpga_MergeStatus(&status,
    NiFpga_WriteU16(myrio_session, PWMA_1MAX, (uint16_t) 1000));

  MyRio_ReturnValueIfNotSuccess(status, status,
    "Could not setup PWMA_1XXXX registers");

  NiFpga_WriteU16(myrio_session, PWMA_1CMP, (uint16_t) 900);

  /*
    Setup motor1 direction
   */

  // set DIO.A_10 as output pin
  NiFpga_MergeStatus(&status,
    NiFpga_WriteU8(myrio_session, DIOA_158DIR, (uint8_t) 0b00000100));

  // set DIO.A_10 HIGH
  NiFpga_MergeStatus(&status,
    NiFpga_WriteU8(myrio_session, DIOA_158OUT, (uint8_t) 0b00000100));

  MyRio_ReturnValueIfNotSuccess(status, status,
    "Could not setup DIOA_158XXX register");

  // /*
  //   Confugering ENC0 on MSP
  //  */
  //
  // NiFpga_MergeStatus(&status,
  //   NiFpga_WriteU8(myrio_session, ENCC_0CNFG,(uint8_t) 0b00011001));
  //
  // MyRio_ReturnValueIfNotSuccess(status, status,
  //   "Could not write ENC.C_0.CNFG register");

//  while () {
//    NiFpga_ReadU32(myrio_session, ENCC_0CNTR, &enc_val);
//    printf("Current encoder value: %i \n", (int32_t) enc_val);
//    // sleep for 300 milliseconds
//    usleep(1000 * 30);
//  }

  usleep(1000 * 5000);

  /* set DIO.A_10 LOW */
  NiFpga_MergeStatus(&status,
    NiFpga_WriteU8(myrio_session, DIOA_158OUT, (uint8_t) 0b00000000));

  status = MyRio_Close();

  return status;
}
