/*
** EPITECH PROJECT, 2022
** SnakeGame
** File description:
** TODO: add description
*/
#ifndef SNAKEGAME_IGAME_HPP
#define SNAKEGAME_IGAME_HPP

#include "Utils/Map.hpp"
#include "Utils/Inputs.hpp"

#define X_MAP 16
#define Y_MAP 16

namespace game {
    class IGame {
    public:
        virtual ~IGame() = default;
        virtual bool gameLogic(std::array<std::array<Map, Y_MAP>, X_MAP>& map, std::tuple<Inputs, std::size_t, std::size_t> input) = 0;

    protected:
    private:
    };
}

#endif //SNAKEGAME_IGAME_HPP
