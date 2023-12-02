add_executable(random Random.cpp)

target_link_libraries(random accelstepper)

pico_add_extra_outputs(random)
