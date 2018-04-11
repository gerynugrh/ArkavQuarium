#ifndef SNAIL_HPP
#define SNAIL_HPP

#include "Position.hpp"
#include "Animation.hpp"

class Snail {
public:
    int animMode, animFrame;
    virtual Position getPosition() = 0;
    virtual void update(double now, double secSinceLast) = 0;
    virtual Animation getAnim(int index) = 0;
};

#endif