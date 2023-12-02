add_executable(blocking Blocking.cpp)

target_link_libraries(blocking accelstepper)

pico_add_extra_outputs(blocking)
