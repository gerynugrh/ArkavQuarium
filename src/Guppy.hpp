#ifndef GUPPY_HPP
#define GUPPY_HPP

#include "AquariumObject.hpp"
#include "Aquarium.hpp"
#include "Food.hpp"
#include "LinkedList.hpp"
#include "Fish.hpp"
#include "Coin.hpp"
#include "SilverCoin.hpp"
#include <vector>
#include "Animation.hpp"

class Guppy : public AquariumObject, public Fish {
private:
    int amountOfFood;
    bool right;
protected:
    bool eat(double now);
    void produceCoin(double now);
    void upgrade();
    Food* findNearestFood();
    void move(double secSinceLast);
public:
    static int foodForUpgrade, timeForCoin, speed;
    static std::vector<Animation> animList;
    void update(double now, double secSinceLast);
    Guppy(const int&, const int&, Aquarium&, double now);
    int getStage() const;
    int getSpeed();
    Position getPosition() const;
    Animation getAnim(int index);
};

#endif
