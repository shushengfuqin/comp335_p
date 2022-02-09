cmake_minimum_required(VERSION 3.21)
project(comp335_p)

set(CMAKE_CXX_STANDARD 14)

add_executable(comp335_p main.cpp Player.cpp Player.h Cards.cpp Cards.h Map.cpp Map.h Orders.cpp Orders.h PlayerDriver.cpp)
