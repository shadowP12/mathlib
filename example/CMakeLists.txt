cmake_minimum_required(VERSION 3.15)
project(ex)

set(CMAKE_CXX_STANDARD 14)

include_directories(../mathlib)

add_executable(ex main.cpp)
