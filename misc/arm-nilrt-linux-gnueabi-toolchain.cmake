set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR arm)

# environment setup
set(MYRIO_TARGET MyRio_1900)
set(OECORE_ROOT "toolchain/oecore-x86_64/sysroots")
set(TARGET_SYSROOT "${OECORE_ROOT}/cortexa9-vfpv3-nilrt-linux-gnueabi")
set(NATIVE_SYSROOT "${OECORE_ROOT}/x86_64-nilrtsdk-linux")
# toolchain and flags setup
set(TOOLCHAIN "${NATIVE_SYSROOT}/usr/bin/arm-nilrt-linux-gnueabi")
set(CROSS_COMPILER_PREFIX arm-nilrt-linux-gnueabi)
set(PLATFORM_SPEC "-march=armv7-a -mfloat-abi=softfp -mfpu=vfpv3 -mtune=cortex-a9")
set(GENERIC_COMPILER_FLAGS "-Wall -O2 -pipe -g -feliminate-unused-debug-types -fdiagnostics-color")

# cross-compilers definition
set(CMAKE_C_COMPILER "${TOOLCHAIN}/${CROSS_COMPILER_PREFIX}-gcc")
set(CMAKE_CXX_COMPILER "${TOOLCHAIN}/${CROSS_COMPILER_PREFIX}-g++")
set(CMAKE_AR "${TOOLCHAIN}/${CROSS_COMPILER_PREFIX}-ar")
# compilers flags
set(CMAKE_C_FLAGS "-std=c99 ${GENERIC_COMPILER_FLAGS} ${PLATFORM_SPEC}")
set(CMAKE_CXX_FLAGS "-std=c++11 ${GENERIC_COMPILER_FLAGS} ${PLATFORM_SPEC}")
set(CMAKE_EXE_LINKER_FLAGS "-Wl,-O1")

# target environment location
set(CMAKE_FIND_ROOT_PATH ${TARGET_SYSROOT})
set(CMAKE_SYSROOT ${TARGET_SYSROOT})

# search for programs in the build host directories
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
# for libraries and headers in the target directories
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
