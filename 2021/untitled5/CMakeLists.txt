cmake_minimum_required(VERSION 3.17)
project(untitled5 CUDA)

set(CMAKE_CUDA_STANDARD 14)

add_executable(untitled5 main.cu)

set_target_properties(
        untitled5
        PROPERTIES
        CUDA_SEPARABLE_COMPILATION ON)