#include "NormalFood.hpp"

std::vector<Animation> NormalFood::animList;
int NormalFood::speed;

NormalFood::NormalFood(const int & x, const int & y, Aquarium & aquarium, double now) : AquariumObject(Position(x, y), aquarium) {
    animFrame = 0;
    animMode = 0;
    AquariumObject::timeSpawned = now;
}

Position NormalFood::getPosition() {
    return AquariumObject::position;
}

void NormalFood::removeFood() {

}

void NormalFood::update(double now, double secSinceLast) {
    NormalFood::animFrame = (fmod((now - AquariumObject::timeSpawned) * 50, 60)) / 6;
    move(secSinceLast);
}

void NormalFood::move(double secSinceLast) {
    double newY = position.y + secSinceLast * speed;
    if (newY <= SCREEN_HEIGHT - 40) {
        position.y = newY;
    }
    else {
        touchedGround = true;
    }
}

Animation NormalFood::getAnim(int index) {
    return animList.at(index);
}

int NormalFood::getAnimFrame() {
    return animFrame;
}

int NormalFood::getAnimMode() {
    return animMode;
}
