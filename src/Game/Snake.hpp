/*
** Personal PROJECT, 2022
** SnakeGame
** File description:
** SnakeGame Engine
*/
#ifndef SNAKEGAME_SNAKE_HPP
#define SNAKEGAME_SNAKE_HPP

#include <list>
#include "../IGame.hpp"

namespace game {
    class Snake {
    public:
        explicit Snake(std::array<std::array<Map, X_MAP>, Y_MAP> &map);
        ~Snake();
        bool gameLogic(std::array<std::array<Map, X_MAP>, Y_MAP>& map, std::tuple<Inputs, std::size_t, std::size_t> input);
        static void print_map(std::array<std::array<Map, X_MAP>, Y_MAP> &map);
    protected:
    private:
        std::list<std::pair<int, int>> snake_pos{};
        std::list<std::pair<int, int>> candy_pos{};
        void generateCandy(int seed);
        void eraseSnakeCandyOnMap(std::array<std::array<Map, 16>, 16> &map);
        void moveBody();
        void moveSnakeHead(std::tuple<Inputs, size_t, size_t> input);
        void addTailSnake();
        void eventSnakeEatCandy();
        void placeSnakeCandyInMap(std::array<std::array<Map, 16>, 16> &map);
        bool detectIfSnakeEatBody();
        bool detectIfSnakeHeadHitWall();
    };
}

#endif //SNAKEGAME_SNAKE_HPP
