#ifndef GAME_HPP
#define GAME_HPP

#include "Aquarium.hpp"
#include <chrono>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <set>

// Pengaturan ukuran layar yang dihasilkan.
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

class Game {
private:
    Aquarium aquarium;
    chrono::high_resolution_clock::time_point time_start;
    SDL_Window * sdlWindow;
    SDL_Surface * gScreenSurface = NULL;
    int framesPassed;
    double fpcStart, cy, cx, prevTime, now, secSinceLast;
    std::string fpsText;
    bool running, quit;
    std::set<SDL_Keycode> pressedKeys;
    std::set<SDL_Keycode> tappedKeys;

    void drawObjects();
    void updateScreen();
    void clearScreen();
    void updateFPS();
    void updateGameTime();
    void handleInput();
    double timeSinceStart();
    bool init();
    void start();

public:
    Game();
    void update();
};

#endif