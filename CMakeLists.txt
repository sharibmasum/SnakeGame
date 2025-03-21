cmake_minimum_required(VERSION 3.14)
project(snakeGame)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp
        snake.cpp
        snake.h
        apple.cpp
        apple.h)
add_executable(snakeGame ${SOURCE_FILES})
include_directories(/usr/local/include)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(snakeGame sfml-system sfml-window sfml-graphics sfml-audio sfml-network)