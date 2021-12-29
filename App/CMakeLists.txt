project(
    # Project Name
    Application
    # Version <Major>.<Minor>.<Patch>.<Tweak>
    VERSION         0.0.0.1
)

set(LINKER_SCRIPT ${CMAKE_CURRENT_LIST_DIR}/default.ld)

add_subdirectory(TestApp)
