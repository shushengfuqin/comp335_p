cmake_minimum_required(VERSION 3.21)
project(comp335_p)

set(CMAKE_CXX_STANDARD 14)

add_executable( src/Observer/LoggingObserver.cpp src/Observer/LoggingObserver.h src/Observer/LoggingObserverDriver.cpp)
