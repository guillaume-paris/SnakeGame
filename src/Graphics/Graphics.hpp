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
        SDL_Window *window;
        SDL_Renderer *renderer;

        void drawMap();
    };
}

#endif //SNAKEGAME_GRAPHICS_HPP
