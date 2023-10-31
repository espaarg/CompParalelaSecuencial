cmake_minimum_required(VERSION 3.26)
project(ProgramaSecuencial C)

set(CMAKE_C_STANDARD 11)

add_executable(ProgramaSecuencial main.c)

MATH(EXPR stack_size "128 * 1024 * 1024") # 32 Mb
set(CMAKE_EXE_LINKER_FLAGS "-Wl,--stack,${stack_size}")
