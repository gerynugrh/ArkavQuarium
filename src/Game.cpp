#include "Game.hpp"
#include <chrono>
#include <iostream>
#include <sstream>

Game::Game() {
    time_start = chrono::high_resolution_clock::now();
    printf("Game started\n");
    start();
    update();
}

void Game::start() {
    if (!init()) {
        printf("Exited manually due to error\n");
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
    printf("Game success running\n");
    while (running) {
        updateGameTime();

        handleInput();

        if (quit) {
            running = false;
            printf("Exit\n");
        }
        clearScreen();
        drawObjects();
        updateScreen();
    }
}

SDL_Surface* Game::loadSurface( std::string path )
{
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if( loadedSurface == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
    }

    return loadedSurface;
}

void Game::drawImage(const std::string &filename, int x, int y) {
    if (loadedSurfaces.count(filename) < 1) {
        loadedSurfaces[filename] = loadSurface(filename);
    }

    SDL_Surface* s = loadedSurfaces[filename];

    SDL_Rect dest;
    dest.x = x - s->w/2;
    dest.y = y - s->h/2;
    dest.w = s->w;
    dest.h = s->h;
    SDL_BlitSurface(s, NULL, gScreenSurface, &dest);
}

void Game::drawText(std::string text, int font_size, int x, int y, unsigned char r, unsigned char g, unsigned char b) {
    if (loadedFontSizes.count(font_size) < 1) {
        loadedFontSizes[font_size] = TTF_OpenFont(FONT_NAME, font_size);
    }

    TTF_Font* font = loadedFontSizes[font_size];
    SDL_Surface* result = TTF_RenderText_Blended(font, text.c_str(), {r, g, b});
    SDL_Rect dest;
    dest.x = x;
    dest.y = y;
    dest.w = result->w;
    dest.h = result->h;
    SDL_BlitSurface(result, NULL, gScreenSurface, &dest);
    SDL_FreeSurface(result);
}

void Game::drawObjects() {
    printf("%d\n", aquarium.objects.length());
    for (int i = 0; i < aquarium.objects.length(); i++) {
        AquariumObject * object = aquarium.objects[i];
        printf("Gangerti Anjeng\n");
        Position pos = object->getPosition();
        printf("Jantuk\n");
        drawImage(object->sprite, pos.x, pos.y);
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
                printf("Check linked list\n");
                int x, y;
                SDL_GetMouseState(&x, &y);
                Guppy * guppy = new Guppy(x, y, aquarium);
                aquarium.objects.add(guppy);
                aquarium.fishes.add(guppy);
                printf("Fish added\n");
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



