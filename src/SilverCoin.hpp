#ifndef SILVER_COIN_HPP
#define SILVER_COIN_HPP

#include "AquariumObject.hpp"
#include "Aquarium.hpp"

class SilverCoin : public AquariumObject{
private:
    static int speed;
protected:
    void move();
public:
    SilverCoin(const int&, const int&, const Aquarium&);
    void getPosition();
    void removeCoin();
    void update();
};

#endif