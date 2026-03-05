#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <string>

#include "Game.h"

class Game1 : public Game {

    SDL_FRect rect{};

    void start() override {
        rect = { 200, 150, 400, 400};
    }

    void update() override {
        SDL_PumpEvents();

        const bool *state = SDL_GetKeyboardState(nullptr);

        if (state[SDL_SCANCODE_W]) rect.y -= 50.0f * deltaTime;
        if (state[SDL_SCANCODE_S]) rect.y += 50.0f * deltaTime;
        if (state[SDL_SCANCODE_A]) rect.x -= 50.0f * deltaTime;
        if (state[SDL_SCANCODE_D]) rect.x += 50.0f * deltaTime;

        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(renderer, &rect);
    }
};

int main([[maybe_unused]] int argc, [[maybe_unused]] char** argv) {
    Game1 game;
    game.run();
    return 0;
}
