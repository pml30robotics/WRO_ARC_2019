# WRO_ARC_2019

Program written in C/C++ for [WRO ARC 2019](https://wro-association.org/competition/advanced-robotics-challenge/) robotics competition.

## Description

Program written in C/C++ using default FPGA personality provided by NI.

## Platform

As a main controller is used **NI myRIO-1900** which have 2 **Expansion Port (MXP)** connectors with 34 GPIO each and  **Mini System Port (MSP)** connector with 20 GPIO.

- CPU: Xilinx Z-7010, 667 MHz, 2 cores
- FPGA: Xilinx Z-7010
- RAM: 256 MB
- USB: 2.0 Hi-Speed
- WI-FI: IEEE 802.11 b,g,n

[myRIO official documentation](http://www.ni.com/pdf/manuals/376047c.pdf)

## Installation

To build project the "GNU C & C++ Compilers for ARMv7 Linux" should be installed and declared in Makefile in TOOLCHAIN_DIR variable. Specified toolchain can be downloaded from my [Google Drive](https://drive.google.com/file/d/1Vl-CFlGpVN-_7cPudg3TTurl4eZtOfNb/view?usp=sharing) or from [official NI site](http://www.ni.com/download/labview-real-time-module-2017/6760/en/)
