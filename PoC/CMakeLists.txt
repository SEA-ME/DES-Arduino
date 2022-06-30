cmake_minimum_required(VERSION 3.0.0)

set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/external/Arduino-CMake-Toolchain/Arduino-toolchain.cmake)
set(ARDUINO_BOARD_OPTIONS_FILE ${CMAKE_SOURCE_DIR}/resources/BoardOptions.cmake)

project(arduino_can_example CXX)

add_subdirectory(src/)

