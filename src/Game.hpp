#ifndef GAME_HPP
#define GAME_HPP

#include "Aquarium.hpp"

class Game {
private:
    Aquarium aquarium;
public:
    Game();
    void update();
};

#endif