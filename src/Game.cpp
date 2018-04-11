#include "Game.hpp"
#include <chrono>
#include <iostream>
#include <sstream>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

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

    // Load small guppy animation
    Animation animGuppySmallMove("../res/smallswim.png", 80, 0);
    Animation animGuppySmallEat("../res/smalleat.png", 80, 0);
    Animation animGuppySmallTurn("../res/smallturn.png", 80, 0);
    Animation animGuppySmallHungryMove("../res/hungryswim.png", 80, 0);
    Animation animGuppySmallHungryEat("../res/hungryeat.png", 80, 0);
    Animation animGuppySmallHungryTurn("../res/hungryturn.png", 80, 0);
    Animation animGuppyFlipSmallMove("../res/smallswimflip.png", 80, 0);
    Animation animGuppyFlipSmallEat("../res/smalleatflip.png", 80, 0);
    Animation animGuppyFlipSmallTurn("../res/smallturnflip.png", 80, 0);
    Animation animGuppyFlipSmallHungryMove("../res/hungryswimflip.png", 80, 0);
    Animation animGuppyFlipSmallHungryEat("../res/hungryeatflip.png", 80, 0);
    Animation animGuppyFlipSmallHungryTurn("../res/hungryturnflip.png", 80, 0);
    Guppy::animList.push_back(animGuppySmallMove);
    Guppy::animList.push_back(animGuppySmallEat);
    Guppy::animList.push_back(animGuppySmallTurn);
    Guppy::animList.push_back(animGuppySmallHungryMove);
    Guppy::animList.push_back(animGuppySmallHungryEat);
    Guppy::animList.push_back(animGuppySmallHungryTurn);
    Guppy::animList.push_back(animGuppyFlipSmallMove);
    Guppy::animList.push_back(animGuppyFlipSmallEat);
    Guppy::animList.push_back(animGuppyFlipSmallTurn);
    Guppy::animList.push_back(animGuppyFlipSmallHungryMove);
    Guppy::animList.push_back(animGuppyFlipSmallHungryEat);
    Guppy::animList.push_back(animGuppyFlipSmallHungryTurn);

    Animation animGuppyMediumMove("../res/smallswim.png", 80, 1);
    Animation animGuppyMediumEat("../res/smalleat.png", 80, 1);
    Animation animGuppyMediumTurn("../res/smallturn.png", 80, 1);
    Animation animGuppyMediumHungryMove("../res/hungryswim.png", 80, 1);
    Animation animGuppyMediumHungryEat("../res/hungryeat.png", 80, 1);
    Animation animGuppyMediumHungryTurn("../res/hungryturn.png", 80, 1);
    Animation animGuppyFlipMediumMove("../res/smallswimflip.png", 80, 1);
    Animation animGuppyFlipMediumEat("../res/smalleatflip.png", 80, 1);
    Animation animGuppyFlipMediumTurn("../res/smallturnflip.png", 80, 1);
    Animation animGuppyFlipMediumHungryMove("../res/hungryswimflip.png", 80, 1);
    Animation animGuppyFlipMediumHungryEat("../res/hungryeatflip.png", 80, 1);
    Animation animGuppyFlipMediumHungryTurn("../res/hungryturnflip.png", 80, 1);
    Guppy::animList.push_back(animGuppyMediumMove);
    Guppy::animList.push_back(animGuppyMediumEat);
    Guppy::animList.push_back(animGuppyMediumTurn);
    Guppy::animList.push_back(animGuppyMediumHungryMove);
    Guppy::animList.push_back(animGuppyMediumHungryEat);
    Guppy::animList.push_back(animGuppyMediumHungryTurn);
    Guppy::animList.push_back(animGuppyFlipMediumMove);
    Guppy::animList.push_back(animGuppyFlipMediumEat);
    Guppy::animList.push_back(animGuppyFlipMediumTurn);
    Guppy::animList.push_back(animGuppyFlipMediumHungryMove);
    Guppy::animList.push_back(animGuppyFlipMediumHungryEat);
    Guppy::animList.push_back(animGuppyFlipMediumHungryTurn);

    Animation animGuppyLargeMove("../res/smallswim.png", 80, 2);
    Animation animGuppyLargeEat("../res/smalleat.png", 80, 2);
    Animation animGuppyLargeTurn("../res/smallturn.png", 80, 2);
    Animation animGuppyLargeHungryMove("../res/hungryswim.png", 80, 2);
    Animation animGuppyLargeHungryEat("../res/hungryeat.png", 80, 2);
    Animation animGuppyLargeHungryTurn("../res/hungryturn.png", 80, 2);
    Animation animGuppyFlipLargeMove("../res/smallswimflip.png", 80, 2);
    Animation animGuppyFlipLargeEat("../res/smalleatflip.png", 80, 2);
    Animation animGuppyFlipLargeTurn("../res/smallturnflip.png", 80, 2);
    Animation animGuppyFlipLargeHungryMove("../res/hungryswimflip.png", 80, 2);
    Animation animGuppyFlipLargeHungryEat("../res/hungryeatflip.png", 80, 2);
    Animation animGuppyFlipLargeHungryTurn("../res/hungryturnflip.png", 80, 2);
    Guppy::animList.push_back(animGuppyLargeMove);
    Guppy::animList.push_back(animGuppyLargeEat);
    Guppy::animList.push_back(animGuppyLargeTurn);
    Guppy::animList.push_back(animGuppyLargeHungryMove);
    Guppy::animList.push_back(animGuppyLargeHungryEat);
    Guppy::animList.push_back(animGuppyLargeHungryTurn);    
    Guppy::animList.push_back(animGuppyFlipLargeMove);
    Guppy::animList.push_back(animGuppyFlipLargeEat);
    Guppy::animList.push_back(animGuppyFlipLargeTurn);
    Guppy::animList.push_back(animGuppyFlipLargeHungryMove);
    Guppy::animList.push_back(animGuppyFlipLargeHungryEat);
    Guppy::animList.push_back(animGuppyFlipLargeHungryTurn);  

    Animation animGuppyKingMove("../res/smallswim.png", 80, 3);
    Animation animGuppyKingEat("../res/smalleat.png", 80, 3);
    Animation animGuppyKingTurn("../res/smallturn.png", 80, 3);
    Animation animGuppyKingHungryMove("../res/hungryswimflip.png", 80, 3);
    Animation animGuppyKingHungryEat("../res/hungryeatflip.png", 80, 3);
    Animation animGuppyKingHungryTurn("../res/hungryturnflip.png", 80, 3);
    Animation animGuppyFlipKingMove("../res/smallswimflip.png", 80, 3);
    Animation animGuppyFlipKingEat("../res/smalleatflip.png", 80, 3);
    Animation animGuppyFlipKingTurn("../res/smallturnflip.png", 80, 3);
    Animation animGuppyFlipKingHungryMove("../res/hungryswimflip.png", 80, 3);
    Animation animGuppyFlipKingHungryEat("../res/hungryeatflip.png", 80, 3);
    Animation animGuppyFlipKingHungryTurn("../res/hungryturnflip.png", 80, 3);
    Guppy::animList.push_back(animGuppyKingMove);
    Guppy::animList.push_back(animGuppyKingEat);
    Guppy::animList.push_back(animGuppyKingTurn);
    Guppy::animList.push_back(animGuppyKingHungryMove);
    Guppy::animList.push_back(animGuppyKingHungryEat);
    Guppy::animList.push_back(animGuppyKingHungryTurn);   
    Guppy::animList.push_back(animGuppyFlipKingMove);
    Guppy::animList.push_back(animGuppyFlipKingEat);
    Guppy::animList.push_back(animGuppyFlipKingTurn);
    Guppy::animList.push_back(animGuppyFlipKingHungryMove);
    Guppy::animList.push_back(animGuppyFlipKingHungryEat);
    Guppy::animList.push_back(animGuppyFlipKingHungryTurn);   

    Animation animGuppySmallDie("../res/smalldie.png", 80, 0);
    Animation animGuppyFlipSmallDie("../res/smalldieflip.png", 80, 0);
    Animation animGuppyMediumDie("../res/smalldie.png", 80, 1);
    Animation animGuppyFlipMediumDie("../res/smalldieflip.png", 80, 1);
    Animation animGuppyLargeDie("../res/smalldie.png", 80, 2);
    Animation animGuppyFlipLargeDie("../res/smalldieflip.png", 80, 2);
    Animation animGuppyKingDie("../res/smalldie.png", 80, 3);
    Animation animGuppyFlipKingDie("../res/smalldieflip.png", 80, 3);
    Guppy::animList.push_back(animGuppySmallDie);
    Guppy::animList.push_back(animGuppyFlipSmallDie);
    Guppy::animList.push_back(animGuppyMediumDie);
    Guppy::animList.push_back(animGuppyFlipMediumDie);
    Guppy::animList.push_back(animGuppyLargeDie);
    Guppy::animList.push_back(animGuppyFlipLargeDie);
    Guppy::animList.push_back(animGuppyKingDie);
    Guppy::animList.push_back(animGuppyFlipKingDie);

    Animation animPiranhaMove("../res/smallswim.png", 80, 4);
    Animation animPiranhaEat("../res/smalleat.png", 80, 4);
    Animation animPiranhaTurn("../res/smallturn.png", 80, 4);
    Animation animPiranhaHungryMove("../res/hungryswim.png", 80, 4);
    Animation animPiranhaHungryEat("../res/hungryeat.png", 80, 4);
    Animation animPiranhaHungryTurn("../res/hungryturn.png", 80, 4);
    Animation animPiranhaFlipMove("../res/smallswimflip.png", 80, 4);
    Animation animPiranhaFlipEat("../res/smalleatflip.png", 80, 4);
    Animation animPiranhaFlipTurn("../res/smallturnflip.png", 80, 4);
    Animation animPiranhaFlipHungryMove("../res/hungryswimflip.png", 80, 4);
    Animation animPiranhaFlipHungryEat("../res/hungryeatflip.png", 80, 4);
    Animation animPiranhaFlipHungryTurn("../res/hungryturnflip.png", 80, 4);
    Piranha::animList.push_back(animPiranhaMove);
    Piranha::animList.push_back(animPiranhaEat);
    Piranha::animList.push_back(animPiranhaTurn);
    Piranha::animList.push_back(animPiranhaHungryMove);
    Piranha::animList.push_back(animPiranhaHungryEat);
    Piranha::animList.push_back(animPiranhaHungryTurn);
    Piranha::animList.push_back(animPiranhaFlipMove);
    Piranha::animList.push_back(animPiranhaFlipEat);
    Piranha::animList.push_back(animPiranhaFlipTurn);
    Piranha::animList.push_back(animPiranhaFlipHungryMove);
    Piranha::animList.push_back(animPiranhaFlipHungryEat);
    Piranha::animList.push_back(animPiranhaFlipHungryTurn);

    Animation animPiranhaDie("../res/smalldie.png", 80, 4);
    Animation animPiranhaFlipDie("../res/smalldieflip.png", 80, 4);
    Piranha::animList.push_back(animPiranhaDie);
    Piranha::animList.push_back(animPiranhaFlipDie);

    Animation animSnailMove("../res/stinky.png", 80, 0);
    Animation animSnailIdle("../res/stinky.png", 80, 2);
    Animation animSnailTurn("../res/stinky.png", 80, 1);
    Animation animSnailFlipMove("../res/stinkyflip.png", 80, 0);
    Animation animSnailFlipIdle("../res/stinkyflip.png", 80, 2);
    Animation animSnailFlipTurn("../res/stinkyflip.png", 80, 1);
    NormalSnail::animList.push_back(animSnailMove);
    NormalSnail::animList.push_back(animSnailIdle);
    NormalSnail::animList.push_back(animSnailTurn);
    NormalSnail::animList.push_back(animSnailFlipMove);
    NormalSnail::animList.push_back(animSnailFlipIdle);
    NormalSnail::animList.push_back(animSnailFlipTurn);

    Animation animFoodMove("../res/food.png", 40, 1);
    NormalFood::animList.push_back(animFoodMove);

    NormalFood::speed = 30;

    Animation animCoinMove("../res/money.png", 72, 0);
    Animation animGoldCoinMove("../res/money.png", 72, 1);
    Animation animStarCoinMove("../res/money.png", 72, 2);
    Animation animDiamondCoinMove("../res/money.png", 72, 3);
    SilverCoin::animList.push_back(animCoinMove);
    SilverCoin::animList.push_back(animGoldCoinMove);
    SilverCoin::animList.push_back(animStarCoinMove);
    SilverCoin::animList.push_back(animDiamondCoinMove);

    Guppy::foodForUpgrade = 1;
    Guppy::timeForCoin = 5;
    Guppy::speed = 50;
    Guppy::price = 200;
    Piranha::speed = 60;
    Piranha::price = 500;

    Fish::timeUntilHungry = 5;
    Fish::timeUntilDead = 10;

    SilverCoin::speed = 30;
    NormalSnail::speed = 30;

    NormalFood::price = 20;

    framesPassed = 0;
    fpcStart = timeSinceStart();
    fpsText = "FPS: 0";

    cy = SCREEN_HEIGHT / 2;
    cx = SCREEN_WIDTH / 2;
    
    NormalSnail * snail = new NormalSnail(SCREEN_WIDTH / 2, SCREEN_HEIGHT - 20, 0, aquarium, now);
    aquarium.snails.add(snail);

    running = true;

    prevTime = timeSinceStart();
}

void Game::update() {
    printf("Game success running\n");
    while (running) {
        updateGameTime();

        handleInput();

        if (!playAgain && aquarium.numberOfEggs >= 3) {
            SDL_Event e;
            SDL_PollEvent(&e);
            while(e.type != SDL_KEYDOWN && e.key.keysym.sym != SDLK_ESCAPE) {
                SDL_PollEvent(&e);
                drawImage("../res/background.jpg", SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
                drawText("You Win!", 40, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 255, 255, 255);
                drawText("Press escape to resume game", 16, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 40, 255, 255, 255);
                drawText("Gold:" + std::to_string(aquarium.gold), 16, 10, 10, 255, 255, 255);
                drawText("Eggs:" + std::to_string(aquarium.numberOfEggs), 16, 10, 34, 255, 255, 255);
                drawObjects();
                updateScreen();
            }
            if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE) {
                printf("Resume\n");
                playAgain = true;
            }
        }

        if (aquarium.fishes.length() == 0 && aquarium.coins.length() == 0 && aquarium.gold < Guppy::price) {
            SDL_Event e;
            SDL_PollEvent(&e);
            while(e.type != SDL_KEYDOWN && e.key.keysym.sym != SDLK_ESCAPE) {
                SDL_PollEvent(&e);
                drawImage("../res/background.jpg", SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
                drawText("You Lose!", 40, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 255, 255, 255);
                drawText("Press escape to quit game", 16, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 40, 255, 255, 255);
                drawText("Gold:" + std::to_string(aquarium.gold), 16, 10, 10, 255, 255, 255);
                drawText("Eggs:" + std::to_string(aquarium.numberOfEggs), 16, 10, 34, 255, 255, 255);
                drawText("Control:", 10, 10, SCREEN_HEIGHT - 35, 255, 255, 255);
                drawText("Piranha: x   Guppy: g   Food: left click", 10, 10, SCREEN_HEIGHT - 20, 255, 255, 255);
                drawObjects();
                updateScreen();
            }
            if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE) {
                printf("Resume\n");
                running = false;
            }            
        }

        if (quit) {
            running = false;
            printf("Exit\n");
        }
        clearScreen();
        updateObjects();
        drawImage("../res/background.jpg", SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
        drawText("Gold:" + std::to_string(aquarium.gold), 16, 10, 10, 255, 255, 255);
        drawText("Eggs:" + std::to_string(aquarium.numberOfEggs), 16, 10, 34, 255, 255, 255);
        drawText("Control:", 10, 10, SCREEN_HEIGHT - 35, 255, 255, 255);
        drawText("Piranha: P   Guppy: G   Egg: E", 10, 10, SCREEN_HEIGHT - 20, 255, 255, 255);
        drawObjects();
        updateScreen();
    }
}

void Game::updateObjects() {
    for (int i = 0; i < aquarium.fishes.length(); i++) {
        Fish * fish = aquarium.fishes[i];
        if (!fish->getDestroyed())
            fish->update(now, secSinceLast);
        else 
            aquarium.fishes.remove(fish);
    }
    for (int i = 0; i < aquarium.snails.length(); i++) {
        Snail * snail = aquarium.snails[i];
        snail->update(now, secSinceLast);
    }        
    for (int i = 0; i < aquarium.coins.length(); i++) {
        Coin * coin = aquarium.coins[i];
        coin->update(now, secSinceLast);
    }
    for (int i = 0; i < aquarium.foods.length(); i++) {
        Food * food = aquarium.foods[i];
        if (!food->getDestroyed()) {
            food->update(now, secSinceLast);
        }
        else
            aquarium.foods.remove(food);
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
    for (int i = 0; i < aquarium.fishes.length(); i++) {
        Fish * fish = aquarium.fishes[i];
        Position pos = fish->getPosition();
        Animation anim = fish->getAnim(fish->animMode);
        drawFrame(anim.getSprite(), pos.x, pos.y, anim.get(fish->animFrame));
    }
    for (int i = 0; i < aquarium.snails.length(); i++) {
        Snail * snail = aquarium.snails[i];
        Position pos = snail->getPosition();
        Animation anim = snail->getAnim(snail->getAnimMode());
        drawFrame(anim.getSprite(), pos.x, pos.y, anim.get(snail->getAnimFrame()));
    } 
    for (int i = 0; i < aquarium.coins.length(); i++) {
        Coin * coin = aquarium.coins[i];
        Position pos = coin->getPosition();
        Animation anim = coin->getAnim(coin->getAnimMode());
        drawFrame(anim.getSprite(), pos.x, pos.y, anim.get(coin->getAnimFrame()));
    }
    for (int i = 0; i < aquarium.foods.length(); i++) {
        Food * food = aquarium.foods[i];
        Position pos = food->getPosition();
        Animation anim = food->getAnim(food->getAnimMode());
        drawFrame(anim.getSprite(), pos.x, pos.y, anim.get(food->getAnimFrame()));
    }
}

void Game::drawFrame(const std::string &filename, int x, int y, SDL_Rect* frame) {
    if (loadedSurfaces.count(filename) < 1) {
        loadedSurfaces[filename] = loadSurface(filename);
    }

    SDL_Surface* s = loadedSurfaces[filename];

    SDL_Rect dest;
    dest.x = x - frame->w/2;
    dest.y = y - frame->h/2;
    dest.w = s->w;
    dest.h = s->h;
    SDL_BlitSurface(s, frame, gScreenSurface, &dest);
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
            if (e.key.keysym.sym == SDLK_p) {
                if (aquarium.gold >= Piranha::price) {
                    int x, y;
                    SDL_GetMouseState(&x, &y);
                    Piranha * piranha = new Piranha(x, y, aquarium, now);
                    aquarium.fishes.add(piranha);     
                    printf("Piranha spawned\n");     
                }      
            }
            else if (e.key.keysym.sym == SDLK_g) {
                if (aquarium.gold >= Guppy::price) {
                    int x, y;
                    SDL_GetMouseState(&x, &y);
                    Guppy * guppy = new Guppy(x, y, aquarium, now);
                    aquarium.fishes.add(guppy);
                }       
            }
            else if (e.key.keysym.sym == SDLK_e) {
                if (aquarium.gold >= EGG_COST) {
                    aquarium.numberOfEggs++;
                }
            }
        }
        else if (e.type == SDL_KEYUP) {
            pressedKeys.erase(e.key.keysym.sym);
        }
        else if (e.type == SDL_MOUSEBUTTONDOWN) {
            if (e.button.button == SDL_BUTTON_LEFT && aquarium.gold >= NormalFood::price) {
                int x, y;
                SDL_GetMouseState(&x, &y);
                NormalFood * food = new NormalFood(x, y, aquarium, now);
                aquarium.foods.add(food);
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



