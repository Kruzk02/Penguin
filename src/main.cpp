
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_log.h>
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_scancode.h>

#include "Game.h"

class Game1 : public Game {
    SDL_FRect rect{};

    const float spawnInterval = 2.0f;
    const float gravity = 250.0f;

    float centerY;
    float spawnTimer = 0.0f;
    float velocityY = 0.0f;

    bool prevKeys[SDL_SCANCODE_COUNT] = {0};
    bool isJumping = false;

    void start() override {
        rect = {0, 0, (screenWidth - 400.0f) / 2, (screenHeight - 400.0f) / 2};
        centerY = screenHeight / 2.0f - rect.h / 2.0f;
        rect.y = centerY;
    }

    void update() override {
        SDL_PumpEvents();

        const bool* state = SDL_GetKeyboardState(nullptr);

        if (state[SDL_SCANCODE_SPACE] && !prevKeys[SDL_SCANCODE_SPACE] && !isJumping) {
            velocityY -= 450.0f;
            isJumping = true;
        }

        velocityY += gravity * deltaTime;
        rect.y += velocityY * deltaTime;

        if (rect.y >= centerY) {
            rect.y = centerY;
            velocityY = 0;
            isJumping = false;
        } else if (rect.y <= centerY) {
            rect.y += gravity * deltaTime;
        }

        spawnTimer += deltaTime;
        if (spawnTimer >= spawnInterval) {
            spawnTimer = 0.0f;
        }

        prevKeys[SDL_SCANCODE_SPACE] = state[SDL_SCANCODE_SPACE];
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(renderer, &rect);
    }
};

int main([[maybe_unused]] int argc, [[maybe_unused]] char** argv) {
    Game1 game;
    game.run();
    return 0;
}
