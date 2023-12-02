add_executable(quickstop Quickstop.cpp)

target_link_libraries(quickstop accelstepper)

pico_add_extra_outputs(quickstop)
