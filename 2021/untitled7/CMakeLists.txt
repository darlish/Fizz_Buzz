cmake_minimum_required(VERSION 3.17)
project(untitled7 CUDA)

set(CMAKE_CUDA_STANDARD 14)

add_executable(untitled7 main.cu)

set_target_properties(
        untitled7
        PROPERTIES
        CUDA_SEPARABLE_COMPILATION ON)