cmake_minimum_required(VERSION 4.0)
project(balboa_32u4_student_project_g2 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(balboa_32u4_student_project_g2
        balboa_balance.h
        balboa_pid.h)
