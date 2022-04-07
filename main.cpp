/*
** Personal PROJECT, 2022
** SnakeGame
** File description:
** SnakeGame Engine
*/

#include <utility>
#include <string>
#include <array>
#include <memory>
#include <iostream>
#include <ostream>
#include <list>

#include "src/Game/Snake.hpp"
#include "src/Utils/Error.hpp"
#include "src/Graphics/Graphics.hpp"


void gameloop(SDL_Renderer *renderer)
{

}

void core()
{
    std::array<std::array<Map, X_MAP>, Y_MAP> map;
    game::Snake game(map);
    game::Graphics graphics;

    graphics.gameloop();
//    game::Snake::print_map(map);
//    game.gameLogic(map, {KEY_Q, 0, 0});
//    game::Snake::print_map(map);
//    game.gameLogic(map, {KEY_Q, 0, 0});
//    game::Snake::print_map(map);
}

int main(int ac, char **av) {
    try {
        core();
    }
    catch (Error &e) {
        std::cout << e.what() << std::endl;
        return (84);
    }
    return (0);
}