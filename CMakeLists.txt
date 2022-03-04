cmake_minimum_required(VERSION 3.21)
project(comp335_p)

set(CMAKE_CXX_STANDARD 14)

add_executable(comp345_p main.cpp src/Order/Orders.cpp src/Order/Orders.h src/Order/OrdersDriver.cpp src/Cards/Cards.h src/Cards/Cards.cpp src/Cards/CardsDriver.cpp src/GameEngine/GameEngine.cpp src/GameEngine/GameEngineDriver.cpp src/GameEngine/GameEngine.h src/Map/Map.cpp src/Map/Map.h src/Map/MapDriver.cpp src/Player/Player.h src/Player/Player.cpp src/Player/PlayerDriver.cpp src/Observer/LoggingObserver.cpp src/Observer/LoggingObserver.h)
