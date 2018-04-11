#ifndef SILVER_COIN_HPP
#define SILVER_COIN_HPP

#include "AquariumObject.hpp"
#include "Aquarium.hpp"
#include "Animation.hpp"

class SilverCoin : public AquariumObject, public Coin{
private:
    bool touchedGround;
protected:
    void move(double secSinceLast);
public:
    int animFrame, animMode, type, value;
    static std::vector<Animation> animList;
    static int speed;
    SilverCoin(const int&, const int&, Aquarium&,double now, int value);
    Position getPosition();
    void removeCoin();
    void update(double now, double secSinceLast);
    Animation getAnim(int index);
    int getAnimFrame();
    int getAnimMode();
};

#endif