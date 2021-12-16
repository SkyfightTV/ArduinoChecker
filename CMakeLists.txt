cmake_minimum_required(VERSION 3.21)
project(ArduinoChecker)

set(CMAKE_CXX_STANDARD 11)

add_executable(ArduinoChecker src/AChecker.cpp src/utils/Result.cpp src/utils/Enums.h src/utils/Enums.cpp)
