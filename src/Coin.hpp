#ifndef COIN_HPP
#define COIN_HPP

class Coin {
public:
    virtual void update() = 0;
    virtual void removeCoin() = 0;
    virtual void getPosition() = 0;
};

#endif