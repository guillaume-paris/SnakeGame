cmake_minimum_required(VERSION 3.21)
project (SnakeGame)

set(CMAKE_CXX_STANDARD 23)

add_executable(SnakeGame main.cpp src/Game/Snake.cpp src/Game/Snake.hpp src/IGame.hpp src/Utils/Map.hpp src/Utils/Map.cpp src/Utils/Inputs.hpp src/Utils/Error.hpp include/graphics.h)
