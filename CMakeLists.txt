cmake_minimum_required(VERSION 3.14)
set(PROJECT accelstepper) # project name and the name of the library are the same
option(BUILD_EXAMPLES "Build all of the examples" OFF)

if (NOT EXISTS $ENV{PICO_SDK_PATH})
  message(FATAL_ERROR "Pico SDK location was not specified. Please set PICO_SDK_PATH to your installation.")
endif ()

include($ENV{PICO_SDK_PATH}/pico_sdk_init.cmake)

project(${PROJECT} C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_library(${PROJECT}
  src/AccelStepper.cpp
  src/MultiStepper.cpp)

target_include_directories(${PROJECT} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(${PROJECT} pico_stdlib pico_double pico_time) 


if(BUILD_EXAMPLES)
  message(STATUS "Building provided examples")
  add_subdirectory(examples)
else()
  message(STATUS "Skipping building the examples")
endif()
