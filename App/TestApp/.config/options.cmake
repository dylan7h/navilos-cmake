#++++++++++++++++++++++++++++++++++++++++++
#           Compile Options
#++++++++++++++++++++++++++++++++++++++++++
# Common
list(APPEND FLAGS -march=${ARM_CPU_ARCH})
list(APPEND FLAGS -mcpu=${ARM_CPU})
list(APPEND FLAGS -mfloat-abi=${ARM_FPU_ABI})
list(APPEND FLAGS -m${ARM_INST_SET})
if(NOT ${ARM_FPU} STREQUAL "")
    list(APPEND FLAGS -mfpu=${ARM_FPU})
endif()

# ASM

# C
list(APPEND CFLAGS -std=${ARM_C_STANDARD})

# CXX
list(APPEND CXXFLAGS -std=${ARM_CXX_STANDARD})

# Linker
list(APPEND LDFLAGS -T ${LINKER_SCRIPT})
list(APPEND LDFLAGS -nostdlib)
list(APPEND LDFLAGS -Wl,-n)                 # Do not auto-sort sections
list(APPEND LDFLAGS -Wl,--gc-sections)      # Garbage Collection Unused Sections
