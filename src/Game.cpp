#include "Game.hpp"
#include <chrono>
#include <iostream>
#include <sstream>

Game::Game() {
    time_start = chrono::high_resolution_clock::now();

    start();


}

void Game::start() {
    if (!init()) {
        printf("Exited manually due to error");
    }

    framesPassed = 0;
    fpcStart = timeSinceStart();
    fpsText = "FPS: 0";

    cy = SCREEN_HEIGHT / 2;
    cx = SCREEN_WIDTH / 2;
    
    running = true;

    prevTime = timeSinceStart();
}

void Game::update() {
    while (running) {
        updateGameTime();

        handleInput();

        if (quit) {
            running = false;
        }

        clearScreen();

        updateScreen();
    }
}

void Game::drawObjects() {
    for (int i = 0; i < aquarium.objects.length(); i++) {
        AquariumObject object = aquarium.objects[i];
        Position pos = object.getPosition();
    }
}

void Game::handleInput() {
    SDL_Event e;
    if (!tappedKeys.empty()) tappedKeys.clear();
    while (SDL_PollEvent(&e) != 0) {
        if (e.type == SDL_QUIT) {
            quit = true;
        }
        else if (e.type == SDL_KEYDOWN && !e.key.repeat) {
            pressedKeys.insert(e.key.keysym.sym);
            tappedKeys.insert(e.key.keysym.sym);
        }
        else if (e.type == SDL_KEYUP) {
            pressedKeys.erase(e.key.keysym.sym);
        }
        else if (e.type == SDL_MOUSEBUTTONDOWN) {
            if (e.button.button == SDL_BUTTON_LEFT) {

            }
        }
    }
}

void Game::clearScreen() {
    SDL_FillRect(gScreenSurface, NULL, SDL_MapRGB(
        gScreenSurface->format, 
        255, 255, 255));
}

void Game::updateScreen() {
    SDL_UpdateWindowSurface(sdlWindow);
}

void Game::updateFPS() {
    framesPassed++;
    if (now - fpcStart > 1) {
        std::ostringstream strs;
        strs << "FPS: ";
        strs << framesPassed / (now - fpcStart);
        fpsText = strs.str();
        fpcStart = now;
        framesPassed = 0;
    }
}

void Game::updateGameTime() {
    now = timeSinceStart();
    secSinceLast = now - prevTime;
    prevTime = now;
}

bool Game::init() {
    bool success = true;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        success = false;
    }
    else {
        if (TTF_Init() == -1) {
            printf("TTF_Init: %s\n", TTF_GetError());
            success = false;
        }
        sdlWindow = SDL_CreateWindow(
            "ArkavQuarium", 
            SDL_WINDOWPOS_UNDEFINED, 
            SDL_WINDOWPOS_UNDEFINED, 
            SCREEN_WIDTH, 
            SCREEN_HEIGHT, 
            SDL_WINDOW_SHOWN);
        if (sdlWindow == NULL) {
            printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
            success = false;
        }
        else {
            gScreenSurface = SDL_GetWindowSurface(sdlWindow);
        }
    }

    return success;
}

double Game::timeSinceStart() {
    chrono::high_resolution_clock::time_point now = chrono::high_resolution_clock::now();
    return chrono::duration_cast<chrono::duration<double>>(now - time_start).count();
}



