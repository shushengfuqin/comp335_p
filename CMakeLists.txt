cmake_minimum_required(VERSION 3.21)
project(comp335_p)

set(CMAKE_CXX_STANDARD 14)

add_executable(comp335_p main.cpp OrdersDriver.cpp Orders.cpp Orders.h src/Cards/CardsDriver.cpp src/Cards/Cards.cpp src/Cards/Cards.h GameEngineDriver.cpp GameEngine.cpp GameEngine.h)


