
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>

#include "Game.h"

class Game1 : public Game {
    SDL_FRect rect{};

    const float spawnInterval = 2.0f;
    float spawnTimer = 0.0f;

    void start() override { rect = {0, 0, (screenWidth - 400.0f) / 2, (screenHeight - 400.0f) / 2}; }

    void update() override {
        SDL_PumpEvents();

        const bool* state = SDL_GetKeyboardState(nullptr);

        if (state[SDL_SCANCODE_W]) rect.y -= 50.0f * deltaTime;
        if (state[SDL_SCANCODE_S]) rect.y += 50.0f * deltaTime;
        if (state[SDL_SCANCODE_A]) rect.x -= 50.0f * deltaTime;
        if (state[SDL_SCANCODE_D]) rect.x += 50.0f * deltaTime;

        spawnTimer += deltaTime;
        if (spawnTimer >= spawnInterval) {
            spawnTimer = 0.0f;
        }

        rect.y = screenHeight / 2.0f - rect.h / 2.0f;

        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(renderer, &rect);
    }
};

int main([[maybe_unused]] int argc, [[maybe_unused]] char** argv) {
    Game1 game;
    game.run();
    return 0;
}
