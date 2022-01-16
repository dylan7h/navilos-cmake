cmake_minimum_required(VERSION 3.16)

project(
    # Project Name
    navilos
    # Version <Major>.<Minor>.<Patch>.<Tweak>
    VERSION         0.0.0.1
)

# Identify Target Architecture
if(${CMAKE_C_COMPILER_TARGET} STREQUAL arm-none-eabi)
    set(BOOT_ARCH   aarch32)
elseif(${CMAKE_C_COMPILER_TARGET} STREQUAL aarch64-arm-none-eabi)
    set(BOOT_ARCH   aarch64)
else()
    message(FATAL_ERROR "Invalid CMAKE_C_COMPILER_TARGET")
endif()

# Set Default Boot Source Path
set(DEFAULT_STARTUP         ${CMAKE_HOME_DIRECTORY}/boot/${BOOT_ARCH}/${TARGET_MACHINE}/startup.S)
set(DEFAULT_LINKER_SCRIPT   ${CMAKE_HOME_DIRECTORY}/boot/${BOOT_ARCH}/${TARGET_MACHINE}/default.ld)
set(INCS                    ${CMAKE_HOME_DIRECTORY}/${BOOT_ARCH}/${TARGET_MACHINE})

# Call CMakeLists.txt at Subdiretory
add_subdirectory(Lib)
add_subdirectory(App)
