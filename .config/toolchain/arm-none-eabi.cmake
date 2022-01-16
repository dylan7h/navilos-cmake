set(GCC_DIR                     "${CMAKE_SOURCE_DIR}/tools/toolchain/arm-none-eabi")

set(CMAKE_SYSTEM_NAME           Generic)
set(CMAKE_SYSTEM_PROCESSOR      cortex-a8)
set(CMAKE_C_COMPILER_TARGET     arm-none-eabi)


LIST(APPEND CMAKE_PROGRAM_PATH  ${TOOL_DIR})

set(CMAKE_AR                    ${GCC_DIR}/bin/arm-none-eabi-ar)

# set(CMAKE_ASM_COMPILER          ${GCC_DIR}/bin/arm-none-eabi-as)
set(CMAKE_ASM_COMPILER          ${GCC_DIR}/bin/arm-none-eabi-gcc)

set(CMAKE_C_COMPILER            ${GCC_DIR}/bin/arm-none-eabi-gcc)
set(CMAKE_C_COMPILER_AR         ${GCC_DIR}/bin/arm-none-eabi-ar)     # GCC archiver
set(CMAKE_C_COMPILER_RANLIB     ${GCC_DIR}/bin/arm-none-eabi-ranlib) # Generate index for GCC archive

set(CMAKE_CXX_COMPILER          ${GCC_DIR}/bin/arm-none-eabi-g++)
set(CMAKE_CXX_COMPILER_AR       ${GCC_DIR}/bin/arm-none-eabi-ar)
set(CMAKE_CXX_COMPILER_RANLIB   ${GCC_DIR}/bin/arm-none-eabi-ranlib)

set(CMAKE_LINKER                ${GCC_DIR}/bin/arm-none-eabi-ld)

set(CMAKE_ADDR2LINE             ${GCC_DIR}/bin/arm-none-eabi-addr2line)
set(CMAKE_NM                    ${GCC_DIR}/bin/arm-none-eabi-nm)
set(CMAKE_OBJCOPY               ${GCC_DIR}/bin/arm-none-eabi-objcopy)
set(CMAKE_OBJDUMP               ${GCC_DIR}/bin/arm-none-eabi-objdump)
set(CMAKE_RANLIB                ${GCC_DIR}/bin/arm-none-eabi-ranlib)
set(CMAKE_READELF               ${GCC_DIR}/bin/arm-none-eabi-readelf)
set(CMAKE_STRIP                 ${GCC_DIR}/bin/arm-none-eabi-strip)

# Don't run the linker on compiler check
SET(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

# Where is the target environment
set(CMAKE_FIND_ROOT_PATH        ${GCC_DIR})

# Search for programs in the build host directories
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)

# For libraries and headers in the target directories
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
