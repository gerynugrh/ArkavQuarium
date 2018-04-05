#ifndef GUPPY_HPP
#define GUPPY_HPP

#include "AquariumObject.hpp"
#include "Aquarium.hpp"
#include "Food.hpp"
#include "LinkedList.hpp"
#include "Fish.hpp"
#include "Coin.hpp"

class Guppy : public AquariumObject, public Fish {
private:   
    static int foodForUpgrade, timeForCoin, speed;
protected:
    bool eat();
    Coin& produceCoin();
    void upgrade();
    void findNearestFood();
    void move();
public:
    Guppy(const int&, const int&, const Aquarium&);
    void update();
    int getStage() const;
    Position getPosition() const;
};

#endif