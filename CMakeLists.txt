cmake_minimum_required(VERSION 4.0)
project(balboa_32u4_student_project_g2 CXX)

set(CMAKE_C_STANDARD 20)

include_directories()

add_executable(balboa_sensors.h
        src/balboa_sensors_cpp.cpp)
