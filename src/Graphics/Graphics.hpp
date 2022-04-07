/*
** EPITECH PROJECT, 2022
** SnakeGame
** File description:
** TODO: add description
*/
#ifndef SNAKEGAME_GRAPHICS_HPP
#define SNAKEGAME_GRAPHICS_HPP

#include <SDL.h>
#include "../Game/Snake.hpp"

namespace game {
    class Graphics {
    public:
        Graphics();
        ~Graphics();
        void gameloop();
    protected:
    private:
        bool isRunning;
        const Uint8 *keystates;
        SDL_Window *window;
        SDL_Renderer *renderer;
        game::Snake *game;
        std::array<std::array<Map, X_MAP>, Y_MAP> map;
        void drawMap();
        void handleKeyPressed();
    };
}

#endif //SNAKEGAME_GRAPHICS_HPP
