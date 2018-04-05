#ifndef SNAIL_HPP
#define SNAIL_HPP

#include "Position.hpp"

class Snail {
public:
    virtual void update() = 0;
    virtual Position getPosition() = 0;
};

#endif