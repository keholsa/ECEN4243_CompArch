cmake_minimum_required(VERSION 3.21)
project(lab1 C)

set(CMAKE_C_STANDARD 11)

include_directories(src)

add_executable(lab1
        src/isa.h
        src/shell.c
        src/shell.h
        src/sim.c)
