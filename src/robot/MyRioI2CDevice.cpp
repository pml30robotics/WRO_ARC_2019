#include <ctime>
#include <cstdio>
#include "MyRioI2CDevice.hpp"
#include "myRio/MyRio.h"

extern NiFpga_Session myrio_session;

MyRioI2CDevice::MyRioI2CDevice(MyRioExpPort port, uint8_t address)
  : I2CDevice(address), status(0) {
  if (port == MyRioExpPort::MXP_A) {
    address_reg = I2CAADDR;
    data_out_reg = I2CADATO;
    data_in_reg = I2CADATI;
    cntl_reg = I2CACNTL;
    stat_reg = I2CASTAT;
    go_reg = I2CAGO;
  } else if (port == MyRioExpPort::MXP_B) {
    address_reg = I2CBADDR;
    data_out_reg = I2CBDATO;
    data_in_reg = I2CBDATI;
    cntl_reg = I2CBCNTL;
    stat_reg = I2CBSTAT;
    go_reg = I2CBGO;
  }
}

void MyRioI2CDevice::request_bytes(uint8_t req_addr, uint8_t* data, uint32_t numBytes) {
  uint8_t data_out[] = {req_addr};

  write(data_out, 2);
  read(data, numBytes);
}

/* Copied from 'myRIO examples-I2C' */
void MyRioI2CDevice::read(uint8_t* data, uint32_t numBytes) {
  const uint8_t timeoutDelay = 1;  /* 1 Second */
  NiFpga_Status status;
    uint32_t index;
    uint32_t lastIndex;
    uint8_t control;
    uint8_t stat;
    NiFpga_Bool busy;
    NiFpga_Bool timeout = NiFpga_False;
    NiFpga_Bool error = NiFpga_False;
    NiFpga_Bool addrNak;
    time_t startTime;
    time_t currentTime;

    /*
     * Fix the I2C address based on the read operation.
     *
     * Shift the address one bit to the left and set bit0.
     */
    uint8_t _i2c_address = (i2c_address << 1) | 0x01;

    /*
     * Set the address of the slave device
     */
    status = NiFpga_WriteU8(myrio_session, address_reg, _i2c_address);

    /*
     * Check if writing to the address register was successful.
     *
     * If there was an error then the rest of the function cannot complete
     * correctly so print an error message to stdout and return from the
     * function early.
     */
    MyRio_ReturnIfNotSuccess(status,
                "Could not write to the I2C address register!");

    /*
     * Store the index value for the last byte.
     */
    lastIndex = numBytes - 1;

    /*
     * Repeat for all bytes
     */
    for (index = 0; index < numBytes; index++)
    {
        /*
         * If there is only one byte then the I2C transmission is different
         * than if there is more than 1 byte to write.
         */
        if (numBytes == 1)
        {
            /*
             * Only one byte.
             * Generate start bit, receive byte, and generate stop bit.
             * Do not send an ACK since this the last byte.
             */
            control = I2c_Start | I2c_Rx_Tx | I2c_Stop; /* 0b00000111 */
        }
        else
        {
            if (index == 0)
            {
                /*
                 * First byte.
                 * Generate start bit and receive the first byte.
                 * Send an ACK so the slave knows it will have to send more
                 * data.
                 */
                control = I2c_Ack | I2c_Start | I2c_Rx_Tx; /* 0b00001011 */

            }
            else if (index == lastIndex)
            {
                /*
                 * Last byte.
                 * Receive last byte and generate stop bit.
                 * Do not send an ACK since this the last byte.
                 */
                control = I2c_Rx_Tx | I2c_Stop; /* 0b00000101 */
            }
            else
            {
                /*
                 * Intermediate byte.
                 * Send the byte.
                 * Send an ACK so the slave knows it will have to send more
                 * data.
                 */
                control = I2c_Ack | I2c_Rx_Tx; /* 0b00001001 */
            }
        }

        /*
         * Write the control byte.
         */
        status = NiFpga_WriteU8(myrio_session, cntl_reg, control);
        if (MyRio_IsNotSuccess(status))
        {
            error = NiFpga_True;
            MyRio_PrintStatus(status);
            printf("Could not write to the I2C control register!");
            break;
        }

        /*
         * Start the I2C operation.
         *
         * Write a true value. The value will automatically be reset to false
         * after the I2C block starts the operation.
         */
        status = NiFpga_WriteBool(myrio_session, go_reg, NiFpga_True);
        if (MyRio_IsNotSuccess(status))
        {
            error = NiFpga_True;
            MyRio_PrintStatus(status);
            printf("Could not start the I2C operation!");
            break;
        }

        /*
         * Wait for the I2C Operation to complete
         */
        startTime = time(NULL); /* Get the start time */
        do
        {
            /*
             * Get the status of the I2C block.
             */
            status = NiFpga_ReadU8(myrio_session, stat_reg, &stat);
            if (MyRio_IsNotSuccess(status))
            {
                error = NiFpga_True;
                MyRio_PrintStatus(status);
                printf("Could not read from the I2C status register!");
                break;
            }

            /*
             * Check the busy bit of the status register
             */
            busy = stat & I2c_Busy;

            if (!busy)
            {
                break;
            }

            /*
             * Check if one second has passed since the operation was started.
             * If it has then the operation has timed out
             */
            currentTime = time(NULL);
            timeout = (currentTime - startTime) >= timeoutDelay;
        }
        while (!timeout || !error);

        /*
         * If there was no error with the operation of the I2C block then check
         * if there was an error with the actual I2C transmission.
         */
        if (!timeout || !error)
        {
            error = stat & I2c_Error;
            if (error)
            {
                /*
                 * Pull out the value of the Address NAK. Data NAK is not
                 * important since this is a read operation.
                 */
                addrNak = (stat & I2c_Address_Nak) > 0;

                printf("read: Error during I2C Transmission!\n");
                printf("read: ADRNAK: %d\n", addrNak);
            }
            else
            {
                /*
                 * Read the data byte received.
                 */
                status = NiFpga_ReadU8(myrio_session, data_in_reg,
                                &data[index]);

                /*
                 * Check if reading from the data in register was successful.
                 *
                 * If there was an error then the rest of the bytes cannot be
                 * received so print an error message to stdout and set error
                 * to break out of the loop. The function cannot return early
                 * otherwise the I2C bus will not be released and will be left
                 * in a bad state.
                 */
                if (MyRio_IsNotSuccess(status))
                {
                    error = NiFpga_True;
                    MyRio_PrintStatus(status);
                    printf("Could not read from the I2C Data In register!");
                }
            }
        }

        /*tus;
         * If there was a timeout or an error then don't continue to send the
         * rest of the data bytes so break out of the loop.
         */
        if (timeout || error)
        {
            break;
        }
    }

    /*
     * If there was a timeout or an error then try to generate the stop bit to
     * release the I2C bus and leave it in a good state. If there was no error
     * then the stop bit would have already been generated so this step can be
     * skipped.
     */
    if (timeout || error)
    {
        status = NiFpga_WriteU8(myrio_session, cntl_reg, I2c_Stop);
        MyRio_ReturnIfNotSuccess(status,
                    "Could not write to the I2C control register!");
    }
}

/* Copied from 'myRIO examples-I2C' */
void MyRioI2CDevice::write(uint8_t* data, uint32_t numBytes) {
  const uint8_t timeoutDelay = 1;  /* 1 Second */
  uint32_t index;
  uint32_t lastIndex;
  NiFpga_Status status;
  uint8_t control;
  uint8_t stat;
  NiFpga_Bool busy;
  NiFpga_Bool timeout = NiFpga_False;
  NiFpga_Bool error = NiFpga_False;
  NiFpga_Bool addrNak;
  NiFpga_Bool dataNak;
  time_t startTime;
  time_t currentTime;

  /*
   * Fix the I2C address based on the write operation.
   *
   * Shift the address one bit to the left and clear bit0.
   */
  uint8_t _i2c_address = (i2c_address << 1) | 0x01;

  /*
   * Set the address of the slave device.
   */
  status = NiFpga_WriteU8(myrio_session, address_reg, _i2c_address);

  /*
     * Check if writing to the address register was successful.
     *
     * If there was an error then the rest of the function cannot complete
     * correctly so print an error message to stdout and return from the
     * function early.
     */
  MyRio_ReturnIfNotSuccess(status,
              "Could not write to the I2C address register!");

  /*
   * Store the index value for the last byte.
   */
  lastIndex = numBytes - 1;

  /*
   * Repeat for all bytes. If there was a timeout or an error then don't continue to
   * send the rest of the data bytes so break out of the loop.
   */
  for (index = 0; (index < numBytes) && (!timeout & !error); index++)
  {
      /*
       * If there is only one byte then the I2C transmission is different
       * than if there is more than 1 byte to write.
       */
      if (numBytes == 1)
      {
          /*
           * Only one byte.
           * Generate start bit, send byte, and generate stop bit.
           */
          control = I2c_Start | I2c_Rx_Tx | I2c_Stop; /* 0b00000111 */
      }
      else
      {
          if (index == 0)
          {
              /*
               * First byte.
               * Generate start bit and send the first byte.
               */
              control = I2c_Start | I2c_Rx_Tx; /* 0b00000011 */

          }
          else if (index == lastIndex)
          {
              /*
               * Last byte.
               * Send the last byte and generate stop bit
               */
              control = I2c_Rx_Tx | I2c_Stop; /* 0b00000101 */
          }
          else
          {
              /*
               * Intermediate byte.
               * Send the byte.
               */
              control = I2c_Rx_Tx; /* 0b00000001 */
          }
      }

      /*
       * Write the data byte to be transmitted.
       */
      status = NiFpga_WriteU8(myrio_session, data_out_reg, data[index]);

      /*
       * Check if writing to the data out register was successful.
       *
       * If there was an error then the rest of the bytes cannot be sent so
       * so print an error message to stdout and break out of the loop. The
       * function cannot return early otherwise the I2C bus will not be
       * released and will be left in a bad state.
       */
      if (MyRio_IsNotSuccess(status))
      {
          error = NiFpga_True;
          MyRio_PrintStatus(status);
          printf("Could not write to the I2C data out register!");
          break;
      }

      /*
       * Write the control byte.
       */
      status = NiFpga_WriteU8(myrio_session, cntl_reg, control);
      if (MyRio_IsNotSuccess(status))
      {
          error = NiFpga_True;
          MyRio_PrintStatus(status);
          printf("Could not write to the I2C control register!");
          break;
      }

      /*
       * Start the I2C operation.
       *
       * Write a true value. The value will automatically be reset to false
       * after the I2C block starts the operation.
       */
      status = NiFpga_WriteBool(myrio_session, go_reg, NiFpga_True);
      if (MyRio_IsNotSuccess(status))
      {
          error = NiFpga_True;
          MyRio_PrintStatus(status);
          printf("Could not start the I2C operation!");
          break;
      }

      /*
       * Wait for the I2C operation to complete
       */
      startTime = time(NULL); /* Get the start time */
      do
      {
          /*
           * Get the status of the I2C block.
           */
          status = NiFpga_ReadU8(myrio_session, stat_reg, &stat);
          if (MyRio_IsNotSuccess(status))
          {
              error = NiFpga_True;
              MyRio_PrintStatus(status);
              printf("Could not read from the I2C status register!");
              break;
          }

          /*
           * Check the busy bit of the status register
           */
          busy = stat & I2c_Busy;

          if (!busy)
          {
              break;
          }
          /*
           * Check if one second has passed since the operation was started.
           * If it has then the operation has timed out
           */
          currentTime = time(NULL);
          timeout = (currentTime - startTime) >= timeoutDelay;
      }
      while (!timeout || !error);

      /*
       * If there was no error with the operation of the I2C block then check
       * if there was an error with the actual I2C transmission.
       */
      if (!timeout || !error)
      {
          error = stat & I2c_Error;
          if (error)
          {
              /*
               * Pull out the values of the Address NAK and Data NAK bits.
               */
              addrNak = (stat & I2c_Address_Nak) > 0;
              dataNak = (stat & I2c_Data_Nak) > 0;

              printf("write: Error during I2C Transmission!\n");
              printf("write: ADRNAK: %d, DATNAK: %d\n", addrNak, dataNak);
          }
      }
  }

  /*
   * If there was a timeout or an error then try to generate the stop bit to
   * release the I2C bus and leave it in a good state. If there was no error
   * then the stop bit would have already been generated so this step can be
   * skipped.
   */
  if (timeout || error)
  {
      status = NiFpga_WriteU8(myrio_session, cntl_reg, I2c_Stop);
      MyRio_ReturnIfNotSuccess(status,
                  "Could not write to the I2C control register!");
  }
}

NiFpga_Status MyRioI2CDevice::get_status() const {
  return status;
}
