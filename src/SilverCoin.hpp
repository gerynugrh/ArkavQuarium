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
    static std::vector<Animation> animList;

    SilverCoin(const int&, const int&, const Aquarium&);
    void getPosition();
    void removeCoin();
};

#endif