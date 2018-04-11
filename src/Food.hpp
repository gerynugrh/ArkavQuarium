#ifndef FOOD_HPP
#define FOOD_HPP

#include "Position.hpp"
#include "Animation.hpp"

class Food {
public:
    virtual void removeFood() = 0;
    virtual Position getPosition() = 0;
    virtual void update(double now, double secSinceLast) = 0;
    virtual Animation getAnim(int index) = 0;
    virtual int getAnimFrame() = 0;
    virtual int getAnimMode() = 0;
};

#endif