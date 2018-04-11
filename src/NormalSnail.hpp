#ifndef NORMAL_SNAIL_HPP
#define NORMAL_SNAIL_HPP

#include "Aquarium.hpp"
#include "AquariumObject.hpp"
#include "Position.hpp"
#include <vector>

class NormalSnail : public AquariumObject, public Snail {
private:
    int direction;
    bool idle, right;
protected:
    void move(double secSinceLast);
    bool takeCoin();
    Coin * findNearestCoin();
public:
    static int speed;
    static std::vector<Animation> animList;
    int animMode, animFrame;
    NormalSnail(const int & x, const int & y, const int & type, Aquarium & aquarium, double now);
    Position getPosition();
    void update(double now, double secSinceLast);
    Animation getAnim(int index);
    int getAnimFrame();
    int getAnimMode();
};

#endif