add_executable(multiple_steppers MultipleSteppers.cpp)

target_link_libraries(multiple_steppers accelstepper)

pico_add_extra_outputs(multiple_steppers)
