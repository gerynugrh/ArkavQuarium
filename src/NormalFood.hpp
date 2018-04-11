#ifndef NORMAL_FOOD_HPP
#define NORMAL_FOOD_HPP

#include "AquariumObject.hpp"
#include "Aquarium.hpp"
#include "Position.hpp"

class NormalFood : public AquariumObject, public Food {
private:
    static int speed;
protected:
    void move();
public:
    static std::vector<Animation> animList;
    
    NormalFood(const int&, const int&, Aquarium&);
    void removeFood();
    Position getPosition();
    void update();
    Animation getAnim(int index);
};

#endif
