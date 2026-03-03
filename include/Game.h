#pragma once
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_video.h>

class Game {
public:
    virtual ~Game() = default;

    void run();
protected:
    int screenWidth = 640;
    int screenHeight = 480;

    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;

    virtual void start() = 0;
    virtual void update() = 0;
private:
    bool init();
    void close();
};
