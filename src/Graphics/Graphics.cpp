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
    game = new game::Snake(map);
}

void game::Graphics::gameloop()
{
    game->gameLogic(map, {KEY_Q, 0, 0});
    game::Snake::print_map(map);
    bool isRunning = true;
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    while (isRunning) {
        SDL_Event event;
        keystates = SDL_GetKeyboardState(NULL);
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                isRunning = false;
            }
            handleKeyPressed();
        }
    }
}

void game::Graphics::drawMap()
{
    SDL_Rect rect;
    rect.x = 15;
    rect.y = 15;
    rect.w = 15;
    rect.h = 15;

    for(int x = 0; x != 16; x++) {
        for(int y = 0; y != 16; y++) {
            rect.x = 15 + (x * 15);
            rect.y = 15 + (y * 15);
            if (map[y][x].getChar() == " ") {
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
            }
            if (map[y][x].getChar() == "X") {
                SDL_SetRenderDrawColor(renderer, 247, 49, 79, 255);
            }
            if (map[y][x].getChar() == "0") {
                SDL_SetRenderDrawColor(renderer, 49, 124, 247, 255);
            }
            if (map[y][x].getChar() == "O") {
                SDL_SetRenderDrawColor(renderer, 64, 247, 49, 255);
            }
            if (map[y][x].getChar() == "8") {
                SDL_SetRenderDrawColor(renderer, 247, 184, 49, 255);
            }
            SDL_RenderFillRect(renderer,&rect);
        }
    }
}

game::Graphics::~Graphics()
{
    delete(game);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void game::Graphics::handleKeyPressed()
{
    if (keystates[SDL_SCANCODE_UP]) {
        std::cout << "debug03" << std::endl;
        // Clear elements and Draw the Screen
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
        drawMap();
        SDL_RenderClear(renderer);

        // Show the elements
        SDL_RenderPresent(renderer);

    }

}

