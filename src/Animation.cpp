#include "Animation.hpp"

SDL_Rect* Animation::get(int index) {
    return anim.at(index);
}

Animation::Animation(std::string path, int size, int index) {
    this->path = path;
    SDL_Surface * sprite = IMG_Load(path.c_str());
    if (sprite == NULL) {
        printf("Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError);
    }

    for (int i = 0; i < sprite->w / size; i++) {
        SDL_Rect * frame = new SDL_Rect();
        frame->x = i * size;
        frame->y = index * size;
        frame->h = size;
        frame->w = size;

        anim.push_back(frame);
    }
}

std::string Animation::getSprite() {
    return path;
}