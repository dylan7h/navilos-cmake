include(.config/options.cmake)

#++++++++++++++++++++++++++++++++++++++++++
#           Project Description
#++++++++++++++++++++++++++++++++++++++++++
project(
    # Project Name
    realview-pb-a8
    # Version <Major>.<Minor>.<Patch>.<Tweak>
    VERSION         0.0.0.1
    # Language Information
    LANGUAGES       C
)


#++++++++++++++++++++++++++++++++++++++++++
#           Include Directories
#++++++++++++++++++++++++++++++++++++++++++
list(APPEND INCS Include/common)
list(APPEND INCS Include/sfr)
list(APPEND INCS Include/Interface)


#++++++++++++++++++++++++++++++++++++++++++
#           Source Paths
#++++++++++++++++++++++++++++++++++++++++++
# ASM
list(APPEND ASRC )

# C
list(APPEND CSRC Source/uart/pl011.c)

#++++++++++++++++++++++++++++++++++++++++++
#           Link Libraries
#++++++++++++++++++++++++++++++++++++++++++
# Library Directories
list(APPEND LIBDIR)

# Libaray Name
list(APPEND LIBS)

#++++++++++++++++++++++++++++++++++++++++++
#           Target Definition
#++++++++++++++++++++++++++++++++++++++++++
# For lib
add_library(${PROJECT_NAME} ${ASRC} ${CSRC})
target_include_directories(${PROJECT_NAME} PUBLIC ${INCS})
target_compile_options(${PROJECT_NAME} PUBLIC
    ${FLAGS}
    $<$<COMPILE_LANGUAGE:ASM>:${ASFLAGS}>
    $<$<COMPILE_LANGUAGE:C>:${CFLAGS}>
    $<$<COMPILE_LANGUAGE:CXX>:${CXXFLAGS}>
)
set_target_properties(${PROJECT_NAME} PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/bin/lib)
set_target_properties(${PROJECT_NAME} PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/bin/lib)
