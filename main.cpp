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

void core()
{
    std::array<std::array<Map, X_MAP>, Y_MAP> map;
    game::Snake game(map);
    game::Snake::print_map(map);
    game.gameLogic(map, {KEY_Q, 0, 0});
    game::Snake::print_map(map);
    game.gameLogic(map, {KEY_Q, 0, 0});
    game::Snake::print_map(map);
    int gd = DETECT, gm;
    initgraph(−gd, −gm, "C:\\TC\\BGI");
    rectangle(100,100,200,200);
    getch();
    closegraph();
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