#!/bin/bash
RELATIVE_DIR=`dirname "$0"`
CANONICAL_DIR=`readlink -f $RELATIVE_DIR`

if ! [ -x "$(command -v aria2c)" ]; then
    echo Installing aria2
    sudo apt install aria2
fi

HOST_ARCH="x86_64"
HOST_DISTRIB="ubuntu-20.04"
LLVM_VER="13.0.0"
ARM_VER="10.3-2021.07"

ARM_A_URL_PRFIX="https://developer.arm.com/-/media/Files/downloads"
LLVM_URL_PREFIX="https://github.com/llvm/llvm-project/releases/download/llvmorg-${LLVM_VER}"

LLVM="clang+llvm-${LLVM_VER}-${HOST_ARCH}-linux-gnu-${HOST_DISTRIB}"
ARM_NONE_EABI="gcc-arm-${ARM_VER}-${HOST_ARCH}-arm-none-eabi"
AACH64_NONE_ELF="gcc-arm-${ARM_VER}-${HOST_ARCH}-aarch64-none-elf"

URLS+="${LLVM_URL_PREFIX}/${LLVM}.tar.xz "
URLS+="${ARM_A_URL_PRFIX}/gnu-a/${ARM_VER}/binrel/${ARM_NONE_EABI}.tar.xz "
URLS+="${ARM_A_URL_PRFIX}/gnu-a/${ARM_VER}/binrel/${AACH64_NONE_ELF}.tar.xz "


mkdir -p ${CANONICAL_DIR}/Download
mkdir -p ${CANONICAL_DIR}/toolchain

# Download ToolChain
echo ">> Downloading ToolChain..."
aria2c -d "${CANONICAL_DIR}/Download" -Z ${URLS}

# Install llvm
echo ">> decompressing ${LLVM}.tar.xz ..."
tar Jxvf ${CANONICAL_DIR}/Download/${LLVM}.tar.xz -C ${CANONICAL_DIR}/toolchain/ 2> /dev/null
echo Create a symbolic link with ${LLVM} as llvm
ln -s ${CANONICAL_DIR}/toolchain/${LLVM} ${CANONICAL_DIR}/toolchain/llvm 2> /dev/null

# Install arm-none-eabi
echo ">> decompressing ${ARM_NONE_EABI}.tar.xz ..."
tar Jxvf ${CANONICAL_DIR}/Download/${ARM_NONE_EABI}.tar.xz -C ${CANONICAL_DIR}/toolchain/ 2> /dev/null
echo Create a symbolic link with ${ARM_NONE_EABI} as arm-none-eabi 2> /dev/null
ln -s ${CANONICAL_DIR}/toolchain/${ARM_NONE_EABI} ${CANONICAL_DIR}/toolchain/arm-none-eabi

# Install aarch64-none-elf
echo ">> decompressing ${AACH64_NONE_ELF}.tar.xz ..."
tar Jxvf ${CANONICAL_DIR}/Download/${AACH64_NONE_ELF}.tar.xz -C ${CANONICAL_DIR}/toolchain/ 2> /dev/null
echo Create a symbolic link with ${AACH64_NONE_ELF} as aarch64-none-elf
ln -s ${CANONICAL_DIR}/toolchain/${AACH64_NONE_ELF} ${CANONICAL_DIR}/toolchain/aarch64-none-elf 2> /dev/null
