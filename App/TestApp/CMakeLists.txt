include(.config/options.cmake)

#++++++++++++++++++++++++++++++++++++++++++
#           Project Description
#++++++++++++++++++++++++++++++++++++++++++
project(
    # Project Name
    TestApp
    # Version <Major>.<Minor>.<Patch>.<Tweak>
    VERSION         0.0.0.1
    # Language Information
    LANGUAGES       ASM C
)


#++++++++++++++++++++++++++++++++++++++++++
#           Include Directories
#++++++++++++++++++++++++++++++++++++++++++
list(APPEND INCS include)


#++++++++++++++++++++++++++++++++++++++++++
#           Source Paths
#++++++++++++++++++++++++++++++++++++++++++
# Linker Script
set(LINKER_SCRIPT ${CMAKE_CURRENT_LIST_DIR}/source/boot/default.ld)

# ASM
list(APPEND ASRC source/boot/startup.S)
# C
list(APPEND CSRC source/boot/main.c)


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
# For ELF or AXF
add_executable(${PROJECT_NAME} ${ASRC} ${CSRC})
target_include_directories(${PROJECT_NAME} PUBLIC ${INCS})
target_compile_options(${PROJECT_NAME} PUBLIC
    ${FLAGS}
    $<$<COMPILE_LANGUAGE:ASM>:${ASFLAGS}>
    $<$<COMPILE_LANGUAGE:C>:${CFLAGS}>
    $<$<COMPILE_LANGUAGE:CXX>:${CXXFLAGS}>
)
target_link_options(${PROJECT_NAME} PUBLIC
    ${FLAGS}
    -T ${LINKER_SCRIPT}
    ${LDFLAGS}
    # --cref : Generate Cross Reference Table into Map file
    -Wl,-Map=${CMAKE_HOME_DIRECTORY}/bin/${PROJECT_NAME}/${PROJECT_NAME}.map,--cref
)
target_link_directories(${PROJECT_NAME} PUBLIC ${LIBDIR})
target_link_libraries(${PROJECT_NAME} PUBLIC ${LIBS})
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/bin/${PROJECT_NAME})
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME ${PROJECT_NAME} SUFFIX ".axf")
# Add Clean Rule(map, asm, bin, hex files)
set_property(
        TARGET ${PROJECT_NAME}
        APPEND
        PROPERTY ADDITIONAL_CLEAN_FILES 
        ${CMAKE_HOME_DIRECTORY}/bin/${PROJECT_NAME}/${PROJECT_NAME}.map
        ${CMAKE_HOME_DIRECTORY}/bin/${PROJECT_NAME}/${PROJECT_NAME}.asm
        ${CMAKE_HOME_DIRECTORY}/bin/${PROJECT_NAME}/${PROJECT_NAME}.bin
        ${CMAKE_HOME_DIRECTORY}/bin/${PROJECT_NAME}/${PROJECT_NAME}.hex
)

# For ASM
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    WORKING_DIRECTORY ${CMAKE_HOME_DIRECTORY}/bin/${PROJECT_NAME}
    COMMAND ${CMAKE_OBJDUMP} -S --disassemble ${PROJECT_NAME}.axf > ${PROJECT_NAME}.asm
)

# For BIN
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    WORKING_DIRECTORY ${CMAKE_HOME_DIRECTORY}/bin/${PROJECT_NAME}
    COMMAND ${CMAKE_OBJCOPY} -O binary -S ${PROJECT_NAME}.axf ${PROJECT_NAME}.bin
)

# For HEX
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    WORKING_DIRECTORY ${CMAKE_HOME_DIRECTORY}/bin/${PROJECT_NAME}
    COMMAND ${CMAKE_OBJCOPY} -O ihex ${PROJECT_NAME}.axf ${PROJECT_NAME}.hex
)
