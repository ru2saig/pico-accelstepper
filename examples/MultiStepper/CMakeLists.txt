add_executable(multi_stepper MultiStepper.cpp)

target_link_libraries(multi_stepper accelstepper)

pico_add_extra_outputs(multi_stepper)
