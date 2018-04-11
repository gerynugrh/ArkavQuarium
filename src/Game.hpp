#ifndef GAME_HPP
#define GAME_HPP

#include "Aquarium.hpp"
#include "Guppy.hpp"
#include "NormalSnail.hpp"
#include "Piranha.hpp"
#include "SilverCoin.hpp"
#include "NormalFood.hpp"
#include <chrono>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <set>
#include <map>

// Pengaturan ukuran layar yang dihasilkan.
class Game {
private:
    const char* const FONT_NAME = "../res/04B_19__.TTF";
    Aquarium aquarium;
    chrono::high_resolution_clock::time_point time_start;
    SDL_Window * sdlWindow;
    SDL_Surface * gScreenSurface = NULL;
    int framesPassed;
    const int EGG_COST = 100;
    int playAgain = false;
    double fpcStart, cy, cx, prevTime, now, secSinceLast;
    std::string fpsText;
    bool running, quit = false;
    std::set<SDL_Keycode> pressedKeys;
    std::set<SDL_Keycode> tappedKeys;
    std::map<std::string, SDL_Surface*> loadedSurfaces;
    std::map<int, TTF_Font*> loadedFontSizes;

    SDL_Surface * loadSurface(std::string path);
    void drawText(std::string text, int font_size, int x, int y, unsigned char r, unsigned char g, unsigned char b);
    void drawImage(const std::string &filename, int x, int y);
    void drawFrame(const std::string &flinemae, int x, int y, SDL_Rect* frame);
    void drawObjects();
    void updateScreen();
    void clearScreen();
    void updateObjects();
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