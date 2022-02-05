cmake_minimum_required(VERSION 3.21)
project(comp335_p)

set(CMAKE_CXX_STANDARD 14)

add_executable(comp335_p main.cpp)
add_executable(comp335_p_cards Cards/CardsDriver.cpp Cards/Card.h Cards/Card.cpp Cards/Deck.h Cards/Deck.cpp Cards/Hand.h Cards/Hand.cpp)
