################################################################
# Additional directories
################################################################
DEPS_DIR := deps
TOOLCHAIN_CORTEXA9_DIR := $(TOOLCHAIN_DIR)/sysroots/cortexa9-vfpv3-nilrt-linux-gnueabi

################################################################
# List of all installing libraries
################################################################
LIBS = -DCMAKE_INSTALL_PREFIX=$$SDKTARGETSYSROOT/usr

LIBCJSON := cJSON
LIBCJSON_URL := https://github.com/DaveGamble/$(LIBCJSON).git
LIBS += $(DEPS_DIR)/$(LIBCJSON)

LIBCONFIG := libconfig
LIBCONFIG_URL := https://github.com/invadrew/$(LIBCONFIG).git
LIBS += $(DEPS_DIR)/$(LIBCONFIG)

#===============================================================================
# TARGETS
#===============================================================================
.PHONY: all-deps
all-deps: $(LIBS)

.PHONY: clean-deps
clean-deps:
	@rm -rf $(DEPS_DIR)/*
	@echo -- All content of $(DEPS_DIR) directory were removed.

.PHONY: _deps_working_dirs
_deps_working_dirs:
	@mkdir -p $(DEPS_DIR)

################################################################
# Dependencies installation in local toolchain directorie
################################################################
.PHONY: install-deps
install-deps: _deps_working_dirs deps-info install-libconfig install-cjson
	@echo -- Libraries: $(LIBS) were successfully installed.

.PHONY: deps-info
deps-info:
ifeq ("$(wildcard $(LIBS))", "")
	@echo -- Installing dependencies libraries into local toolchain directory: $(TOOLCHAIN_DIR).
else
	@echo -- Nothing to do.
endif

################################################################
# Dependencies installation on remote NI-myRIO host
################################################################
.PHONY: install-remote-deps
install-remote-deps: deps-rem-info install-libconfig-rem install-cjson-rem
	@echo -- Libraries: $(LIBS) were successfully deployed.

.PHONY: deps-rem-info
deps-rem-info:
	@echo -- Installing dependencies libraries on remote NI-myRIO host: $(MYRIO_USER_NAME)@$(MYRIO_HOST_NAME).

################################################################
# libconfig
# C/C++ library for processing structured configuration files.
################################################################
$(DEPS_DIR)/$(LIBCONFIG):
	@echo ---- Building library: $(LIBCONFIG)
	@git clone $(LIBCONFIG_URL) $@
	@cd $@ && mkdir -p build ; cd build ; source $(TOOLCHAIN_ENV_SETUP) \
		&& cmake .. -DBUILD_TESTS=OFF -DBUILD_EXAMPLES=OFF
	@cd $@ && cd build ; source $(TOOLCHAIN_ENV_SETUP) make
	@echo

.PHONY: install-libconfig
install-libconfig: $(DEPS_DIR)/$(LIBCONFIG)
	@cd $(DEPS_DIR)/$(LIBCONFIG)/build && source $(TOOLCHAIN_ENV_SETUP) \
		&& sudo make install DESTDIR=$(TOOLCHAIN_CORTEXA9_DIR)

.PHONY: install-libconfig-rem
install-libconfig-rem: $(DEPS_DIR)/$(LIBCONFIG)
	@mkdir -p $(DEPS_DIR)/tmp
	@cd $(DEPS_DIR)/$(LIBCONFIG)/build && make install DESTDIR=$(PRJ_PATH)/$(DEPS_DIR)/tmp
	@scp -r $(DEPS_DIR)/tmp $(MYRIO_USER_NAME)@$(MYRIO_HOST_NAME):/

################################################################
# cJSON
# Ultralightweight JSON parser in ANSI C.
################################################################
$(DEPS_DIR)/$(LIBCJSON):
	@echo ---- Building library: $(LIBCJSON)
	@git clone $(LIBCJSON_URL) $@
	@cd $@ && mkdir -p build ; cd build ; source $(TOOLCHAIN_ENV_SETUP) \
		&& cmake .. -DENABLE_CJSON_TEST=OFF
	@cd $@ && cd build ; source $(TOOLCHAIN_ENV_SETUP) && make
	@echo

.PHONY: install-cjson
install-cjson: $(DEPS_DIR)/$(LIBCJSON)
	@cd $(DEPS_DIR)/$(LIBCJSON)/build && source $(TOOLCHAIN_ENV_SETUP) \
		&& sudo make install DESTDIR=$(TOOLCHAIN_CORTEXA9_DIR)

.PHONY: install-cjson-rem
install-cjson-rem: $(DEPS_DIR)/$(LIBCJSON)
	@mkdir -p $(DEPS_DIR)/tmp
	@cd $(DEPS_DIR)/$(LIBCJSON)/build && make install DESTDIR=$(PRJ_PATH)/$(DEPS_DIR)/tmp
	@scp -r $(DEPS_DIR)/tmp $(MYRIO_USER_NAME)@$(MYRIO_HOST_NAME):/
