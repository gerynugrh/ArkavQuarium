#include "NormalFood.hpp"

std::vector<Animation> NormalFood::animList;

NormalFood::NormalFood(const int & x, const int & y, Aquarium & aquarium) : AquariumObject(Position(x, y), aquarium) {

}

Position NormalFood::getPosition() {
    return AquariumObject::position;
}

void NormalFood::removeFood() {

}

Animation NormalFood::getAnim(int index) {
    return animList.at(index);
}
