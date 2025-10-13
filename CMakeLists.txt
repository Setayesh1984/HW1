cmake_minimum_required(VERSION 3.10)
project(HW1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

add_executable(HW1
    src/main.cpp
    src/student.cpp
)
