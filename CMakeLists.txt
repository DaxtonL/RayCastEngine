cmake_minimum_required(VERSION 4.4.4)
project(RayEngine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(RayEngine
    src/main.cpp
    src/ray.cpp
)

target_include_directories(RayEngine PRIVATE include)
target_compile_options(RayEngine PRIVATE -Wall -Wextra)