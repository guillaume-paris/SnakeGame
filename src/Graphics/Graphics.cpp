/*
** EPITECH PROJECT, 2022
** SnakeGame
** File description:
** TODO: add description
*/
#include "Graphics.hpp"

game::Graphics::Graphics()
{
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Snake",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,640,480,0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
}

void game::Graphics::gameloop()
{
    bool isRunning = true;
    while (isRunning) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                isRunning = false;
            }
        }
        // Clear elements and Draw the Screen
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer);
        drawMap();
        // Show the elements
        SDL_RenderPresent(renderer);
    }
}

void game::Graphics::drawMap()
{

}

game::Graphics::~Graphics()
{
    SDL_DestroyWindow(window);
    SDL_Quit();
}

