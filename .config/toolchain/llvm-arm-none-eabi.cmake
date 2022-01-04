set(LLVM_DIR                    "${CMAKE_SOURCE_DIR}/tools/toolchain/llvm")
set(GCC_DIR                     "${CMAKE_SOURCE_DIR}/tools/toolchain/arm-none-eabi")

set(CMAKE_SYSTEM_NAME           Generic)
set(CMAKE_SYSTEM_PROCESSOR      cortex-a8)
set(CMAKE_SYSROOT               ${GCC_DIR})
set(CLANG_TARGET_TRIPLE         arm-none-eabi)

LIST(APPEND CMAKE_PROGRAM_PATH ${TOOL_DIR})

set(CMAKE_AR                    ${LLVM_DIR}/bin/llvm-ar)

set(CMAKE_ASM_COMPILER          ${LLVM_DIR}/bin/clang)
set(CMAKE_ASM_COMPILER_TARGET   ${CLANG_TARGET_TRIPLE})

set(CMAKE_C_COMPILER            ${LLVM_DIR}/bin/clang)
set(CMAKE_C_COMPILER_TARGET     ${CLANG_TARGET_TRIPLE})
set(CMAKE_C_COMPILER_AR         ${LLVM_DIR}/bin/llvm-ar)     # LLVM archiver
set(CMAKE_C_COMPILER_RANLIB     ${LLVM_DIR}/bin/llvm-ranlib) # Generate index for LLVM archive

set(CMAKE_CXX_COMPILER          ${LLVM_DIR}/bin/clang++)
set(CMAKE_CXX_COMPILER_TARGET   ${CLANG_TARGET_TRIPLE})
set(CMAKE_CXX_COMPILER_AR       ${LLVM_DIR}/bin/llvm-ar)
set(CMAKE_CXX_COMPILER_RANLIB   ${LLVM_DIR}/bin/llvm-ranlib)

set(CMAKE_LINKER                ${LLVM_DIR}/bin/ld.lld)
set(CMAKE_DLLTOOL               ${LLVM_DIR}/bin/llvm-dlltool)

set(CMAKE_ADDR2LINE             ${LLVM_DIR}/bin/llvm-addr2line)
set(CMAKE_NM                    ${LLVM_DIR}/bin/llvm-nm)
set(CMAKE_OBJCOPY               ${LLVM_DIR}/bin/llvm-objcopy)
set(CMAKE_OBJDUMP               ${LLVM_DIR}/bin/llvm-objdump)
set(CMAKE_RANLIB                ${LLVM_DIR}/bin/llvm-ranlib)
set(CMAKE_READELF               ${LLVM_DIR}/bin/llvm-readelf)
set(CMAKE_STRIP                 ${LLVM_DIR}/bin/llvm-strip)

# Don't run the linker on compiler check
SET(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

# Where is the target environment
set(CMAKE_FIND_ROOT_PATH        ${GCC_DIR} ${LLVM_DIR})

# Search for programs in the build host directories
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)

# For libraries and headers in the target directories
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
