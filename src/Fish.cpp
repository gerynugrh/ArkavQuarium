#include "Fish.hpp"

int Fish::timeUntilHungry, Fish::timeUntilDead;

Fish::Fish(const int & type) : type(type) {
    alive = 1;
    stage = 1;
    hungry = false;
}

int Fish::getType() {
    return type;
}

Fish::~Fish() {

}
