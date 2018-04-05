#ifndef NORMAL_SNAIL_HPP
#define NORMAL_SNAIL_HPP

#include "Aquarium.hpp"
#include "AquariumObject.hpp"
#include "Position.hpp"

class NormalSnail : public AquariumObject {
private:
    static int speed;
protected:
    void getNearestCoin();
    void move();
    bool takeCoin();
public:
    NormalSnail(const int & x, const int & type, const Aquarium & aquarium);
    Position getPosition();
    void update();
};

#endif