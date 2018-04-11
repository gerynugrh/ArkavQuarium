#ifndef COIN_HPP
#define COIN_HPP

#include "Animation.hpp"
#include "Position.hpp"

class Coin {
public:
    virtual void removeCoin() = 0;
    virtual Position getPosition() = 0;
    virtual Animation getAnim(int index) = 0;
    virtual void update(double now, double secSinceLast) = 0;
    virtual int getAnimFrame() = 0;
    virtual int getAnimMode() = 0;
};

#endif