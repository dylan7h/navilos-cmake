# Target Configuration
# TOOLCHAIN_FILE			?=.config/toolchain/llvm-arm-none-eabi.cmake
TOOLCHAIN_FILE			?=.config/toolchain/arm-none-eabi.cmake
CONFIG_FILE				?=.config/defconfig.cmake
BINARY_DIR				?=build
TARGET					?=all

# CMake Configurtation
VERBOSE_MAKEFILE		?=ON
BUILD_TYPE				?=Debug
EXPORT_COMPILE_COMMANDS	?=ON
COLOR_MAKEFILE			?=ON

.PHONY: config build

all: config build

toolchain_install:
	@./tools/InstallToolChain.sh

config:
	@cmake 	-C ${CONFIG_FILE} \
			-DCMAKE_TOOLCHAIN_FILE:PATH=${TOOLCHAIN_FILE} \
			-DCMAKE_VERBOSE_MAKEFILE:PATH=${VERBOSE_MAKEFILE} \
			-DCMAKE_BUILD_TYPE:STRING=${BUILD_TYPE} \
			-DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=${EXPORT_COMPILE_COMMANDS} \
			-DCMAKE_COLOR_MAKEFILE:BOOL=${COLOR_MAKEFILE} \
			-H$(PWD) -B${BINARY_DIR}

build:
	@cmake --build ${BINARY_DIR} --target ${TARGET}

clean:
	@cmake --build ${BINARY_DIR} --target clean

distclean:
	@echo remove 'build & bin' direcotry
	@cmake -E remove_directory build bin

