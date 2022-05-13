cmake_minimum_required(VERSION 3.17)
project(yannis C)

set(CMAKE_C_STANDARD 99)

add_executable(yannis main.c conio.c rubiks.c rubiks.h)