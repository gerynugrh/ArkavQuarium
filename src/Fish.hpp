#ifndef FISH_HPP
#define FISH_HPP

#include "Coin.hpp"
#include "Position.hpp"

class Fish {
protected:
    enum Type {GUPPY = 1, PIRANHA = 2};
    const int type;
    bool alive;
    int stage;
protected:
    virtual void findNearestFood() = 0;
    virtual Coin& produceCoin() = 0;
    virtual void move() = 0;
    virtual bool eat() = 0;
public:
    int timeUntilHungry, timeUntilDead;
    Fish(const int &);
    virtual ~Fish();
    virtual void update() = 0;
    virtual Position getPosition() const = 0;
    virtual int getStage() const = 0;
};

#endif