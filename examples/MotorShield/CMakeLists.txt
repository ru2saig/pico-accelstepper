add_executable(motor_shield MotorShield.cpp)

target_link_libraries(motor_shield accelstepper)

pico_add_extra_outputs(motor_shield)
