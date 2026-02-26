#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <string>

constexpr int screenWidth = 640;
constexpr int screenHeight = 480;

bool init();
void close();

SDL_Window *window = nullptr;
SDL_Surface *screen = nullptr;

int main([[maybe_unused]] int argc, [[maybe_unused]] char** argv) {
    if (!init()) {
        SDL_Log("Unable to initialize program!\n");
        return 1;
    }

    bool quit = false;

    SDL_Event e;
    SDL_zero(e);

    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }
            SDL_FillSurfaceRect(screen, nullptr, SDL_MapSurfaceRGB(screen, 0, 200, 125));

            SDL_UpdateWindowSurface(window);
        }
    }

    close();

    return 0;
}

bool init() {
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("SDL could not initialize! SDL error: %s\n", SDL_GetError());
        return false;
    }

    if (window = SDL_CreateWindow("Penguin", screenWidth, screenHeight, 0); window == nullptr) {
        SDL_Log( "Window could not be created! SDL error: %s\n", SDL_GetError() );
        return false;
    }

    screen = SDL_GetWindowSurface(window);
    return true;
}

void close() {
    SDL_DestroyWindow(window);
    window = nullptr;
    screen = nullptr;

    SDL_Quit();
}