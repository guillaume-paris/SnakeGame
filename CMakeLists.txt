cmake_minimum_required(VERSION 3.21)
project (SnakeGame)

set(CMAKE_CXX_STANDARD 23)


set(SDL2_INCLUDE_DIR C:/libs/SDL2-2.0.20/include)
set(SDL2_LIB_DIR C:/libs/SDL2-2.0.20/lib/x64)

include_directories( ${SDL2_INCLUDE_DIR} )
link_directories(${SDL2_LIB_DIR})

add_executable(SnakeGame main.cpp src/Game/Snake.cpp src/Game/Snake.hpp src/IGame.hpp src/Utils/Map.hpp src/Utils/Map.cpp src/Utils/Inputs.hpp src/Utils/Error.hpp src/Graphics/Graphics.cpp src/Graphics/Graphics.hpp)

target_link_libraries(SnakeGame SDL2main SDL2)