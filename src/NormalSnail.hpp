#ifndef NORMAL_SNAIL_HPP
#define NORMAL_SNAIL_HPP

#include "Aquarium.hpp"
#include "AquariumObject.hpp"
#include "Position.hpp"
#include <vector>

class NormalSnail : public AquariumObject, public Snail {
private:
    static int speed;
protected:
    void getNearestCoin();
    void move();
    bool takeCoin();
public:
    static std::vector<Animation> animList;

    NormalSnail(const int & x, const int & y, const int & type, Aquarium & aquarium, double now);
    Position getPosition();
    void update(double now, double secSinceLast);
    Animation getAnim(int index);
};

#endif