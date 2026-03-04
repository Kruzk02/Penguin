#include "Game.h"

#include <SDL3/SDL_init.h>
#include <SDL3/SDL_log.h>
#include <SDL3/SDL_timer.h>

void Game::run() {
    if (!init()) {
        SDL_Log("unable to initialize SDL: %s", SDL_GetError());
        return;
    }

    bool isRunning = true;

    SDL_Event e;
    SDL_zero(e);

    start();

    lastFrame = SDL_GetPerformanceCounter();

    while (isRunning) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                isRunning = false;
            }
        }

        const Uint64 currentTime = SDL_GetPerformanceCounter();
        deltaTime = static_cast<float>(currentTime - lastFrame) / static_cast<float>(SDL_GetPerformanceFrequency());
        lastFrame = currentTime;

        if (deltaTime > 0.1f)
            deltaTime = 0.1f;

        SDL_SetRenderDrawColor(renderer, 20, 20, 20, 255);
        SDL_RenderClear(renderer);

        update();

        SDL_RenderPresent(renderer);
    }

    close();
}

bool Game::init() {
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("SDL could not initialize! SDL error: %s\n", SDL_GetError());
        return false;
    }

    if (window = SDL_CreateWindow("Penguin", screenWidth, screenHeight, 0); window == nullptr) {
        SDL_Log( "Window could not be created! SDL error: %s\n", SDL_GetError() );
        return false;
    }

    if (renderer = SDL_CreateRenderer(window, nullptr); renderer == nullptr) {
        SDL_Log("Renderer could not be created! SDL error: %s\n", SDL_GetError());
        return false;
    }
    return true;
}

void Game::close() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    window = nullptr;
    renderer = nullptr;

    SDL_Quit();
}
