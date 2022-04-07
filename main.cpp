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

int main(int ac, char **av) {
    try {
        game::Graphics graphics;
        graphics.gameloop();
    }
    catch (Error &e) {
        std::cout << e.what() << std::endl;
        return (84);
    }
    return (0);
}