#++++++++++++++++++++++++++++++++++++++++++
#           Compile Options
#++++++++++++++++++++++++++++++++++++++++++
# Common
list(APPEND FLAGS -march=${ARM_CPU_ARCH})
list(APPEND FLAGS -mfloat-abi=${ARM_FPU_ABI})
if(NOT ${ARM_FPU} STREQUAL "")
list(APPEND FLAGS -mfpu=${ARM_FPU})
endif()

# ASM

# C
list(APPEND CFLAGS -m${ARM_INST_SET})
list(APPEND CFLAGS -std=${ARM_C_STANDARD})

# CXX
list(APPEND CXXFLAGS -m${ARM_INST_SET})
list(APPEND CXXFLAGS -std=${ARM_CXX_STANDARD})

# Linker
list(APPEND LDFLAGS -nostdlib)
list(APPEND LDFLAGS -Wl,-n)                 # Do not auto-sort sections
list(APPEND LDFLAGS -Wl,--gc-sections)      # Garbage Collection Unused Sections
