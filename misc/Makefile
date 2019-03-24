#===============================================================================
#
#  Use DMACROS variable for passing additional CPPFLAGS (with -D prefixes).
#  Use MODULES variable to specify which additional modules (directories)
#  should be added to build.
#
#===============================================================================

################################################################
# Default make options
################################################################
MAKEFLAGS += --output-sync --no-print-directory

################################################################
# Generated executable name
################################################################
PROJECT_NAME = robot

################################################################
# Environment setup
################################################################
SHELL := /bin/bash

################################################################
# Project directories
################################################################
PRJ_PATH = $(PWD)
BUILD_DIR = build
INCS_DIR = include
SRC_DIR = src
LIB_DIR = lib
BIN_DIR = bin
TOOLCHAIN_DIR = toolchain

################################################################
# Toolchain setup
################################################################
OECORE_SYSROOT := $(TOOLCHAIN_DIR)/oecore-x86_64/sysroots
TARGET_SYSROOT := $(OECORE_SYSROOT)/cortexa9-vfpv3-nilrt-linux-gnueabi
NATIVE_SYSROOT := $(OECORE_SYSROOT)/x86_64-nilrtsdk-linux
CROSS_COMPILER := arm-nilrt-linux-gnueabi
PATH := \
	$(NATIVE_SYSROOT)/usr/bin\
	:$(NATIVE_SYSROOT)/usr/bin/arm-nilrt-linux-gnueabi:$(PATH)
MYRIO_TARGET := MyRio_1900

################################################################
# Compilers settings and options. Mostly copied
# from 'toolchain/oecore-x86_64/sysroot/environment-setup-cortexa9-vfpv3-nilrt-linux-gnueabi'
################################################################
PLATFORM := -march=armv7-a -mfloat-abi=softfp -mfpu=vfpv3 \
-mtune=cortex-a9 --sysroot=$(TARGET_SYSROOT)

CC = $(CROSS_COMPILER)-gcc $(PLATFORM)
CXX = $(CROSS_COMPILER)-g++ $(PLATFORM)
CPP = $(CROSS_COMPILER)-gcc -E $(PLATFORM)
LD = $(CROSS_COMPILER)-ld  --sysroot=$(TARGET_SYSROOT)
AS = $(CROSS_COMPILER)-as
AR = $(CROSS_COMPILER)-ar

CFLAGS = -std=c99 -Wall -O2 -pipe -g -feliminate-unused-debug-types \
	-fdiagnostics-color
CXXFLAGS = -std=c++11 -Wall -O2 -pipe -g -feliminate-unused-debug-types \
	-fdiagnostics-color
CPPFLAGS = -MMD -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
LDFLAGS = -Wl,-O1

# default preprocessor 'define' macroses
# -D_DEFAULT_SOURCE needed by unistd.h
override DMACROS += -D$(MYRIO_TARGET) -D_DEFAULT_SOURCE
CPPFLAGS += $(DMACROS)

################################################################
# Dependencies: libraries and header files
################################################################
LDLIBS = -L$(LIB_DIR) -ldl
INCS = -I$(addprefix $(INCS_DIR), $(dir $(subst $(SRC_DIR), , $<)))

################################################################
# Defining which directories should be compiled
################################################################
override MODULES += $(SRC_DIR) $(SRC_DIR)/robot/myRio $(SRC_DIR)/robot
BUILD_MODULES = $(addprefix $(BUILD_DIR)/, \
	$(patsubst /%, %, $(subst $(SRC_DIR), , $(MODULES))))

################################################################
# List C, CXX files for compile
################################################################
C_SRCS := $(shell find $(MODULES) -maxdepth 1 -name '*.c')
CXX_SRCS := $(shell find $(MODULES) -maxdepth 1 -name '*.cpp')

C_OBJS := $(patsubst src/%.c, build/%.o, $(C_SRCS))
################################################################
# List all generated object
################################################################
CXX_OBJS := $(patsubst src/%.cpp, build/%.o, $(CXX_SRCS))

################################################################
# Default myRio deployment settings in local network
################################################################
MYRIO_HOST_NAME := ni-myrio-1900-robot30.local
MYRIO_USER_NAME := admin
MYRIO_DEPLOY_PATH := /home/admin
MYRIO_DEPLOY := $(MYRIO_USER_NAME)@$(MYRIO_HOST_NAME):$(MYRIO_DEPLOY_PATH)

#===============================================================================
# TARGETS
#===============================================================================
.PHONY: all
all: build deploy

.PHONY: clean
clean:
	@rm -rf $(BUILD_DIR)/* $(BIN_DIR)/*
	@echo -- All content of $(BUILD_DIR), $(BIN_DIR) directories were removed.

.PHONY: _working_dirs
_working_dirs:
	@mkdir -p $(BUILD_DIR) $(BUILD_MODULES) $(BIN_DIR)

################################################################
# Deployment
################################################################
.PHONY: deploy
deploy: $(BIN_DIR)/$(PROJECT_NAME)
	@echo -- Deploying: $< binary to $(MYRIO_DEPLOY).
	@scp $< $(MYRIO_DEPLOY)

################################################################
# Building targets
################################################################
.PHONY: build
build: info _working_dirs $(BIN_DIR)/$(PROJECT_NAME)

.PHONY: info
info:
	@echo -- Target sysroot: $(TARGET_SYSROOT)
	@echo -- Project name: $(PROJECT_NAME)
	@echo -- Compiling modules: $(MODULES)
	@echo -- DMACROSes: $(DMACROS)

################################################################
# Linking all generated object files into executable
################################################################
$(BIN_DIR)/$(PROJECT_NAME): $(C_OBJS) $(CXX_OBJS)
	@echo -- Collecting object files into executable.
	@$(CXX) $(LDFLAGS) $(LDLIBS) -o $@ $^
	@echo -- Done building! Generated: $@

################################################################
# Building 'C' source files in specified in MODULES variable
################################################################
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@echo ---- Building C object from $<.
	@$(CC) $(CFLAGS) $(INCS) $(CPPFLAGS) -c
	@echo ---- $@ Done!

################################################################
# Building 'CXX' source files in specified in MODULES variable
################################################################
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@echo ---- Building CXX object from $<.
	@$(CXX) $(CXXFLAGS) $(INCS) $(CPPFLAGS) -c
	@echo ---- $@ Done!
