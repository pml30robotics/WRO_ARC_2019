#include <iostream>
#include <unistd.h>
#include "MPU9255.hpp"
#include "robot/MyRioI2CDevice.hpp"
#include "utils/types_utils.h"

MPU9255::MPU9255(MyRioExpPort port) : i2c_device(new MyRioI2CDevice(port, MPU_address)) { }

// implementation of Sensor interface
void MPU9255::calibrate() {}

bool MPU9255::init() {
  hard_reset(); // chip hard reset

  usleep(1000 * 10);
  i2c_device->write_byte(CONFIG, 0x03); // set DLPF_CFG to 11
  i2c_device->write_byte(SMPLRT_DIV, 0x00); // set prescaler sample rate to 0
  i2c_device->write_byte(GYRO_CONFIG, 0x01); // set gyro to 3.6 KHz bandwidth, and 0.11 ms using FCHOICE bits
  i2c_device->write_byte(INT_PIN_CFG, 0x02); // enable bypass

  // read factory gyroscope offset
  GX_offset = uint8_to_uint16(
    i2c_device->read_byte(XG_OFFSET_L),
    i2c_device->read_byte(XG_OFFSET_H)
  );
  GY_offset = uint8_to_uint16(
    i2c_device->read_byte(YG_OFFSET_L),
    i2c_device->read_byte(YG_OFFSET_H)
  );
  GZ_offset = uint8_to_uint16(
    i2c_device->read_byte(ZG_OFFSET_L),
    i2c_device->read_byte(ZG_OFFSET_H)
  );

  //Based on http://www.digikey.com/en/pdf/i/invensense/mpu-hardware-offset-registers .
  //read factory accelerometer offset

  //read the register values and save them as a 16 bit value
  AX_offset = uint8_to_uint16(
    i2c_device->read_byte(XA_OFFSET_L),
    i2c_device->read_byte(XA_OFFSET_H)
  );
  AY_offset = uint8_to_uint16(
    i2c_device->read_byte(YA_OFFSET_L),
    i2c_device->read_byte(YA_OFFSET_H)
  );
  AZ_offset = uint8_to_uint16(
    i2c_device->read_byte(ZA_OFFSET_L),
    i2c_device->read_byte(ZA_OFFSET_H)
  );

  //shift offset values to the right to remove the LSB
  AX_offset = AX_offset >> 1;
  AY_offset = AY_offset >> 1;
  AZ_offset = AZ_offset >> 1;

  return test();
}

// implementation of Gyroscope interface
double MPU9255::get_X_angle_accel() {
  return gx / g_scale;
}

double MPU9255::get_Y_angle_accel() {
  return gy / g_scale;
}

double MPU9255::get_Z_angle_accel() {
  return gz / g_scale;
}

// implementation of Gyroscope interface
double MPU9255::get_X_accel() {
  return ax / a_scale;
}

double MPU9255::get_Y_accel() {
  return ay / a_scale;
}

double MPU9255::get_Z_accel() {
  return az / a_scale;
}

// self methods
bool MPU9255::test() {
  if(i2c_device->read_byte(WHO_AM_I) == 0x73) {
    return true;
  }
  return false;
}

void MPU9255::read_accel() {
  uint8_t raw_data[6];
  i2c_device->request_bytes(ACCEL_XOUT_H, raw_data, 6);

  //store data in raw data variables
  ax = uint8_to_uint16(raw_data[1], raw_data[0]);
  ay = uint8_to_uint16(raw_data[3], raw_data[2]);
  az = uint8_to_uint16(raw_data[5], raw_data[4]);
}

void MPU9255::read_gyro() {
  uint8_t raw_data[6];
  i2c_device->request_bytes(GYRO_XOUT_H, raw_data, 6);

  //store data in raw data variables
  gx = uint8_to_uint16(raw_data[1], raw_data[0]);
  gy = uint8_to_uint16(raw_data[3], raw_data[2]);
  gz = uint8_to_uint16(raw_data[5], raw_data[4]);
}

void MPU9255::offset_adjust() {

  int16_t gX_offset = 0; //gyroscope X axis offset
  int16_t gY_offset = 0; //gyroscope Y axis offset
  int16_t gZ_offset = 0; //gyroscope Z axis offset

  int16_t aX_offset = 0; //accelerometer X axis offset
  int16_t aY_offset = 0; //accelerometer Y axis offset
  int16_t aZ_offset = 0; //accelerometer Z axis offset

  //update flags

  //gyroscope
  bool update_gX = true;
  bool update_gY = true;
  bool update_gZ = true;

  //accelerometer
  bool update_aX = true;
  bool update_aY = true;
  bool update_aZ = true;

  //discard the first reading
  read_accel();
  read_gyro();
  usleep(1000 * 10);

  while(1) //offset adjusting loop
  {
    read_accel();
    read_gyro();

    //-------- adjust accelerometer X axis offset ----------

    if (ax > 0 && update_aX == true) { //if X axis readings are greater than 0
      aX_offset --; //decrement offset
    }


    if (ax < 0 && update_aX == true) {
      aX_offset ++;//increment offset
    }

    //-------- adjust accelerometer Y axis offset ----------

    if (ay > 0 && update_aY == true) { //if X axis readings are greater than 0
      aY_offset --;//decrement offset
    }

    if (ay < 0 && update_aY == true) {
      aY_offset ++;//increment offset
    }

    //-------- adjust accelerometer Z axis offset ----------

    if (az > 0 && update_aZ == true) { //if X axis readings are greater than 0
      aZ_offset --;//decrement offset
    }

    if (az < 0 && update_aZ == true) {
      aZ_offset ++;//increment offset
    }

    //-------- adjust gyroscope X axis offset ----------

    if (gx > 0 && update_gX == true) { //if X axis readings are greater than 0
      gX_offset --;//decrement offset
    }

    if (gx < 0 && update_gX == true) {
      gX_offset ++;//increment offset
    }

    //-------- adjust gyroscope Y axis offset ----------

    if (gy > 0 && update_gY == true) { //if X axis readings are greater than 0
      gY_offset --;//decrement offset
    }

    if (gy < 0 && update_gY == true) {
      gY_offset ++;//increment offset
    }

    //-------- adjust gyroscope Z axis offset ----------

    if (gz > 0 && update_gZ == true) { //if X axis readings are greater than 0
      gZ_offset --;//decrement offset
    }

    if (gz < 0 && update_gZ == true) {
      gZ_offset ++;//increment offset
    }

    //set new offset
    if (update_gX == true) {
      set_gyro_offset(X_axis,gX_offset);
    }

    if (update_gY == true) {
      set_gyro_offset(Y_axis,gY_offset);
    }

    if (update_gZ == true) {
      set_gyro_offset(Z_axis,gZ_offset);
    }

    if (update_aX == true) {
      set_acc_offset(X_axis,aX_offset);
    }

    if (update_aY == true) {
      set_acc_offset(Y_axis,aY_offset);
    }

    if (update_aZ == true) {
      set_acc_offset(Z_axis,aZ_offset);
    }

    //------ Check if each axis is adjusted -----
    const short maximum_error = 5;//set maximum deviation to 5 LSB
    if ((ax - maximum_error) <= 0) { }

    if((std::abs(ax) - maximum_error) <= 0) {
      update_aX = false;
    }

    if((std::abs(ay) - maximum_error) <= 0) {
      update_aY = false;
    }

    if((std::abs(az) - maximum_error) <= 0) {
      update_aZ = false;
    }

    if((std::abs(gx) - maximum_error) <= 0) {
      update_gX = false;
    }

    if((std::abs(gy) - maximum_error) <= 0) {
      update_gY = false;
    }

    if((std::abs(gz) - maximum_error) <= 0) {
      update_gZ = false;
    }

    //------ Adjust procedure end condition ------
    if(update_gX==false && update_gY==false && update_gZ==false && update_aX==false && update_aY==false && update_aZ==false) {
      break;
    }

    usleep(1000 * 10);
  }
}

void MPU9255::hard_reset() {
  uint8_t data = i2c_device->read_byte(PWR_MGMT_1);
  data |= 1 << 7;
  i2c_device->write_byte(PWR_MGMT_1, data);
}

void MPU9255::set_accel_scale(scales selected_scale) {
  uint8_t current_state = i2c_device->read_byte(ACCEL_CONFIG);

  switch (selected_scale) {
  case scale_2g:
    current_state &= ~((1<<3)|(1<<4));
    a_scale = 16384.0;
    break;
  case scale_4g:
    current_state &= ~(1<<4);
    current_state |= (1<<3);
    a_scale = 8192.0;
    break;
  case scale_8g:
    current_state &= ~(1<<3);
    current_state |= (1<<4);
    a_scale = 4096.0;
    break;
  case scale_16g:
    current_state |= (1<<4)|(1<<3);
    a_scale = 2048.0;
    break;
  }

  i2c_device->write_byte(ACCEL_CONFIG, current_state);
}

void MPU9255::set_gyro_scale(scales selected_scale) {
  uint8_t current_state = i2c_device->read_byte(GYRO_CONFIG);

  switch (selected_scale) {
  case scale_250dps:
    current_state &= ~((1<<3)|(1<<4));
    g_scale = 131;
    break;
  case scale_500dps:
    current_state &= ~(1<<4);
    current_state |= (1<<3);
    g_scale = 65.5;
    break;
  case scale_1000dps:
    current_state &= ~(1<<3);
    current_state |= (1<<4);
    g_scale = 32.8;
    break;
  case scale_2000dps:
    current_state |= (1<<4)|(1<<3);
    g_scale = 16.4;
    break;
  }

  i2c_device->write_byte(GYRO_CONFIG, current_state);
}

void MPU9255::set_gyro_bandwidth(bandwidth selected_bandwidth) {
  switch (selected_bandwidth) {
    case gyro_8800Hz:
      write_OR(GYRO_CONFIG, (1<<0)); //set Fchoice_b <0> to 1
      break;
    case gyro_3600Hz:
      write_AND(GYRO_CONFIG, ~(1<<0)); //set Fchoice_b <0> to 0
      write_OR(GYRO_CONFIG, (1<<1)); //set Fchoice_b <1> to 1
      break;
    case gyro_250Hz:
      write_AND(GYRO_CONFIG, ~((1<<0)|(1<<1)));//set both Fchoice_b to 0
      write_AND(CONFIG, ~((1<<0)|(1<<1)|(1<<2)));
      break;
    case gyro_184Hz:
      write_AND(GYRO_CONFIG, ~((1<<0)|(1<<1)));//set both Fchoice_b to 0
      write_AND(CONFIG, ~((1<<1)|(1<<2)));
      write_OR(CONFIG, (1<<0));
      break;
    case gyro_92Hz:
      write_AND(GYRO_CONFIG,~((1<<0)|(1<<1)));//set both Fchoice_b to 0
      write_AND(CONFIG,~((1<<2)|(1<<0)));
      write_OR(CONFIG,(1<<1));
      break;
    case gyro_41Hz:
      write_AND(GYRO_CONFIG,~((1<<0)|(1<<1)));//set both Fchoice_b to 0
      //write 3(011) to DLPF_CFG
      write_AND(CONFIG,~(1<<2));
      write_OR(CONFIG,(1<<0)|(1<<1));
      break;
    case gyro_20Hz:
      write_AND(GYRO_CONFIG,~((1<<0)|(1<<1)));//set both Fchoice_b to 0
      //write 4(100) to DLPF_CFG
      write_AND(CONFIG,~((1<<1)|(1<<0)));
      write_OR(CONFIG,(1<<2));
      break;
    case gyro_10Hz:
      write_AND(GYRO_CONFIG,~((1<<0)|(1<<1)));//set both Fchoice_b to 0
      //write 5(101) to DLPF_CFG
      write_AND(CONFIG,~(1<<1));
      write_OR(CONFIG,(1<<2)|(1<<0));
      break;
    case gyro_5Hz:
      write_AND(GYRO_CONFIG,~((1<<0)|(1<<1)));//set both Fchoice_b to 0
      //write 6(110) to DLPF_CFG
      write_AND(CONFIG,~(1<<0));
      write_OR(CONFIG,(1<<1)|(1<<2));
      break;
  }
}

void MPU9255::set_accel_bandwidth(bandwidth selected_bandwidth) {
  switch (selected_bandwidth) {
    case acc_1113Hz:
      write_OR(ACCEL_CONFIG_2, (1<<3)); //set Fchoice_b <0> to 1
      break;
    case acc_460Hz:
      //set accel_fchoice_b to 0 and  A_DLPF_CFG to 0(000)
      write_AND(ACCEL_CONFIG_2, ~((1<<3)|(1<<2)|(1<<1)|(1<<0)));
      break;
    case acc_184Hz:
      write_AND(ACCEL_CONFIG_2, ~(1<<3));//set accel_fchoice_b to 0
      //set A_DLPF_CFG to 1(001)
      write_AND(ACCEL_CONFIG_2, ~((1<<1)|(1<<2)));
      write_OR(ACCEL_CONFIG_2, (1<<0));
      break;
    case acc_92Hz:
      write_AND(ACCEL_CONFIG_2, ~(1<<3));//set accel_fchoice_b to 0
      //set A_DLPF_CFG to 2(010)
      write_AND(ACCEL_CONFIG_2, ~((1<<0)|(1<<2)));
      write_OR(ACCEL_CONFIG_2, (1<<1));
      break;
    case acc_41Hz:
        write_AND(ACCEL_CONFIG_2, ~(1<<3));//set accel_fchoice_b to 0
        //set A_DLPF_CFG to 3(011)
        write_AND(ACCEL_CONFIG_2, ~(1<<2));
        write_OR(ACCEL_CONFIG_2, (1<<0)|(1<<1));
      break;
    case acc_20Hz:
      write_AND(ACCEL_CONFIG_2, ~(1<<3));//set accel_fchoice_b to 0
      //set A_DLPF_CFG to 4(100)
      write_AND(ACCEL_CONFIG_2, ~((1<<0)|(1<<1)));
      write_OR(ACCEL_CONFIG_2, (1<<2));
      break;
    case acc_10Hz:
      write_AND(ACCEL_CONFIG_2, ~(1<<3));//set accel_fchoice_b to 0
      //set A_DLPF_CFG to 5(101)
      write_AND(ACCEL_CONFIG_2, ~(1<<1));
      write_OR(ACCEL_CONFIG_2, (1<<0)|(1<<2));
      break;
    case acc_5Hz:
      write_AND(ACCEL_CONFIG_2, ~(1<<3));//set accel_fchoice_b to 0
      //set A_DLPF_CFG to 6(110)
      write_AND(ACCEL_CONFIG_2, ~(1<<0));
      write_OR(ACCEL_CONFIG_2, (1<<1)|(1<<2));
      break;
  }
}

void MPU9255::set_acc_offset(axis selected_axis, int16_t offset) {
  switch(selected_axis) {
  case X_axis:
    offset = offset + AX_offset;//add offset to the factory offset
    i2c_device->write_byte(XA_OFFSET_L, (offset & 0xFF) << 1);//write low byte
    i2c_device->write_byte(XA_OFFSET_H, (offset >> 7));//write high byte
    break;
  case Y_axis:
    offset = offset + AY_offset;
    i2c_device->write_byte(YA_OFFSET_L, (offset & 0xFF) << 1);
    i2c_device->write_byte(YA_OFFSET_H, (offset >> 7));
    break;
  case Z_axis:
    offset = offset + AZ_offset;
    i2c_device->write_byte(ZA_OFFSET_L, (offset & 0xFF) << 1);
    i2c_device->write_byte(ZA_OFFSET_H, (offset >> 7) );
    break;
  }
}

void MPU9255::set_gyro_offset(axis selected_axis, int16_t offset) {
  switch(selected_axis) {
  case X_axis:
    offset = offset + GX_offset;//add offset to the factory offset
    i2c_device->write_byte(XG_OFFSET_L, (offset & 0xFF));//write low byte
    i2c_device->write_byte(XG_OFFSET_H, (offset >> 8));//write high byte
    break;
  case Y_axis:
    offset = offset + GY_offset;
    i2c_device->write_byte(YG_OFFSET_L, (offset & 0xFF));
    i2c_device->write_byte(YG_OFFSET_H, (offset >> 8));
    break;
  case Z_axis:
    offset = offset + GZ_offset;
    i2c_device->write_byte(ZG_OFFSET_L, (offset & 0xFF));
    i2c_device->write_byte(ZG_OFFSET_H, (offset >> 8));
    break;
  }
}

// i2c util function
void MPU9255::write_AND(uint8_t reg_addres, uint8_t data) {
  uint8_t c = i2c_device->read_byte(reg_addres);
  c &= data;
  i2c_device->write_byte(reg_addres, c);
}

void MPU9255::write_OR(uint8_t reg_addres, uint8_t data) {
  uint8_t c = i2c_device->read_byte(reg_addres);
  c |= data;
  i2c_device->write_byte(reg_addres, c);
}
