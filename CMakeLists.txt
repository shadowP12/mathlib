cmake_minimum_required(VERSION 3.15)
project(test)

set(CMAKE_CXX_STANDARD 14)

include_directories(mathlib)
include_directories(3rdParty)
include_directories(3rdParty/stb)

add_executable(test example/main.cpp)
