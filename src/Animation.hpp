#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include <vector>

class Animation {
private:
    std::vector<SDL_Rect*> anim;
    std::string path;
public:
    Animation(std::string path, int size, int index);
    SDL_Rect* get(int index);
    std::string getSprite();
};

#endif