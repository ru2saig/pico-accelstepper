add_executable(bounce Bounce.cpp)

target_link_libraries(bounce accelstepper)

pico_add_extra_outputs(bounce)
