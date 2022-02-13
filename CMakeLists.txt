cmake_minimum_required(VERSION 3.21)
project(comp335_p)

set(CMAKE_CXX_STANDARD 14)

add_executable(comp345_p main.cpp Orders.cpp Orders.h OrdersDriver.cpp src/Cards/Cards.h src/Cards/Cards.cpp src/Cards/CardsDriver.cpp  GameEngine.cpp GameEngineDriver.cpp GameEngine.h)


