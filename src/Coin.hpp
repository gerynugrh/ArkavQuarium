#ifndef COIN_HPP
#define COIN_HPP

#include "Animation.hpp"

class Coin {
public:
    virtual void removeCoin() = 0;
    virtual void getPosition() = 0;
    virtual Animation getAnim(int index) = 0;
};

#endif