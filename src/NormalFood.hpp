#ifndef NORMAL_FOOD_HPP
#define NORMAL_FOOD_HPP

#include "AquariumObject.hpp"
#include "Aquarium.hpp"
#include "Position.hpp"

class NormalFood : public AquariumObject, public Food {
private:
    bool touchedGround;
protected:
    void move(double secSinceLast);
public:
    static int speed;
    static std::vector<Animation> animList;
    int animFrame, animMode;
    NormalFood(const int&, const int&, Aquarium&, double now);
    void removeFood();
    Position getPosition();
    void update(double now, double secSinceLast);
    Animation getAnim(int index);
    int getAnimFrame();
    int getAnimMode();
};

#endif
