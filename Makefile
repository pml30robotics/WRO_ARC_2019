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

################################################################
# Toolchain setup
################################################################
SYSROOT := $(OECORE_TARGET_SYSROOT)
CROSS_COMPILER := arm-nilrt-linux-gnueabi
PATH := \
	$(OECORE_NATIVE_SYSROOT)/usr/bin\
	:$(OECORE_NATIVE_SYSROOT)/usr/bin/arm-nilrt-linux-gnueabi:$(PATH)
MYRIO_TARGET := MyRio_1900

################################################################
# Compilers settings and options. Mostly copied
# from 'environment-setup-cortexa9-vfpv3-nilrt-linux-gnueabi'
################################################################
PLATFORM := -march=armv7-a -mfloat-abi=softfp -mfpu=vfpv3 \
-mtune=cortex-a9 --sysroot=$(SYSROOT)

CC = $(CROSS_COMPILER)-gcc $(PLATFORM)
CXX = $(CROSS_COMPILER)-g++ $(PLATFORM)
CPP = $(CROSS_COMPILER)-gcc -E $(PLATFORM)
LD = $(CROSS_COMPILER)-ld  --sysroot=$(SYSROOT)
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
override MODULES += $(SRC_DIR) $(SRC_DIR)/robot/myRio
BUILD_MODULES = $(addprefix $(BUILD_DIR)/, \
	$(patsubst /%, %, $(subst $(SRC_DIR), , $(MODULES))))

################################################################
# List C, CXX files for compile
################################################################
C_SRCS := $(shell find $(MODULES) -maxdepth 1 -name '*.c')
CXX_SRCS := $(shell find $(MODULES) -maxdepth 1 -name '*.cpp')

################################################################
# List all generated object
################################################################
C_OBJS := $(patsubst src/%.c, build/%.o, $(C_SRCS))
CXX_OBJS := $(patsubst src/%.cpp, build/%.o, $(CXX_SRCS))

#===============================================================================
# TARGETS
#===============================================================================
.PHONY: clean
clean:
	@rm -rf $(BUILD_DIR)/* $(BIN_DIR)/*
	@echo -- All content of $(BUILD_DIR), $(BIN_DIR) directories were removed.

.PHONY: _working_dirs
_working_dirs:
	@mkdir -p $(BUILD_DIR) $(BUILD_MODULES) $(BIN_DIR)

################################################################
# Building targets
################################################################
.PHONY: build
build: info _working_dirs $(BIN_DIR)/$(PROJECT_NAME)

.PHONY: info
info:
	@echo -- $(SYSROOT)
	@echo -- Project name: $(PROJECT_NAME)
	@echo -- Compiling modules: $(MODULES)
	@echo -- DMACROS: $(DMACROS)

################################################################
# Linking all generated object files into executable
################################################################
$(BIN_DIR)/$(PROJECT_NAME): $(C_OBJS) $(CXX_OBJS)
	@echo -- Collecting object files into executable.
	@$(CC) $(LDFLAGS) $(LDLIBS) -o $@ $^
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
