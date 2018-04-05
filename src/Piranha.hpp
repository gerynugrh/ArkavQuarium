#ifndef PIRANHA_HPP
#define PIRANHA_HPP

#include "Aquarium.hpp"
#include "AquariumObject.hpp"
#include "Position.hpp"
#include "Fish.hpp"
#include "Coin.hpp"

class Piranha : public AquariumObject, public Fish {
private:
    static int speed;
protected:
    void upgrade();
    void findNearestFood();
    void move();
    Coin& produceCoin();
    bool eat();
public:
    Piranha(const int&, const int&, const Aquarium&);
    void update();
    Position getPosition();
};

#endif