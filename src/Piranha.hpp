#ifndef PIRANHA_HPP
#define PIRANHA_HPP

#include "Aquarium.hpp"
#include "AquariumObject.hpp"
#include "Position.hpp"
#include "Animation.hpp"
#include "Fish.hpp"
#include "Coin.hpp"
#include "SilverCoin.hpp"

class Piranha : public AquariumObject, public Fish {
private:
    bool right;
protected:
    void upgrade();
    Fish * findNearestFood();
    void move(double secSinceLast);
    void produceCoin(double now);
    bool eat(double now);
public:
    static int speed;
    static std::vector<Animation> animList;
    Piranha(const int&, const int&, Aquarium&, double now);
    Position getPosition() const;
    int getStage() const; 
    int getSpeed();
    void update(double now, double secSinceLast);
    Animation getAnim(int index);
};

#endif