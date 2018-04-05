#ifndef FOOD_HPP
#define FOOD_HPP

#include "Position.hpp"

class Food {
public:
    virtual void removeFood() = 0;
    virtual Position getPosition() = 0;
    virtual void update() = 0;
};

#endif