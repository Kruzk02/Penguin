#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <string>

#include "Game.h"

class Game1 : public Game {
    void start() override {

    }

    void update() override{
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        constexpr SDL_FRect rect = { 200, 150, 400, 300 };
        SDL_RenderFillRect(renderer, &rect);
    }
};

int main([[maybe_unused]] int argc, [[maybe_unused]] char** argv) {
    Game1 game;
    game.run();
    return 0;
}
