#ifndef SNAIL_HPP
#define SNAIL_HPP

#include "Position.hpp"
#include "Animation.hpp"

class Snail {
protected:
    virtual Coin * findNearestCoin() = 0;
    virtual void move(double secSinceLast) = 0;
public:
    virtual Position getPosition() = 0;
    virtual void update(double now, double secSinceLast) = 0;
    virtual Animation getAnim(int index) = 0;
    virtual int getAnimFrame() = 0;
    virtual int getAnimMode() = 0;
};

#endif