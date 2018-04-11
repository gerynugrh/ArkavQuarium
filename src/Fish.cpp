#include "Fish.hpp"

int Fish::timeUntilHungry, Fish::timeUntilDead;

Fish::Fish(const int & type) : type(type) {
    alive = 1;
    stage = 1;
    destroy = false;
    hungry = false;
}

int Fish::getType() {
    return type;
}

bool Fish::getDestroyed() {
    return destroy;
}

Fish::~Fish() {

}
