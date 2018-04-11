#ifndef FISH_HPP
#define FISH_HPP

#include "Coin.hpp"
#include "Position.hpp"
#include "Food.hpp"
#include "Animation.hpp"

class Fish {
protected:
    enum Type {GUPPY = 1, PIRANHA = 2};
    const int type;
    bool alive, hungry;
    int stage;
protected:
    virtual Coin * produceCoin() = 0;
    virtual void move(double secSinceLast) = 0;
public:
    int animMode, animFrame;
    int timeHungry, timeEat;
    static int timeUntilHungry, timeUntilDead;
    Fish(const int &);
    int getType();
    virtual ~Fish();
    virtual Position getPosition() const = 0;
    virtual int getStage() const = 0;
    virtual void update(double now, double secSinceLast) = 0;
    virtual Animation getAnim(int index) = 0;
};

#endif
