#include "NormalSnail.hpp"

std::vector<Animation> NormalSnail::animList;

NormalSnail::NormalSnail(const int & x, const int & y, const int & type, Aquarium & aquarium, double now) : AquariumObject(Position(x, y), aquarium) {
    AquariumObject::timeSpawned = now;
    Snail::animFrame = 0;
    Snail::animMode = 0;
}

Position NormalSnail::getPosition() {
    return position;
}

void NormalSnail::update(double now, double secSinceLast) {
    printf("%lf\n", AquariumObject::timeSpawned);
    NormalSnail::animFrame = (fmod((now - AquariumObject::timeSpawned) * 50, 60)) / 6;
}

Animation NormalSnail::getAnim(int index) {
    return NormalSnail::animList.at(index);
}