cmake_minimum_required(VERSION 3.6)
project(Tic_Tac_Toe)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/main.cpp)
add_executable(Tic_Tac_Toe ${SOURCE_FILES})