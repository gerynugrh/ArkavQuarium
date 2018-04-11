#include "SilverCoin.hpp"

std::vector<Animation> SilverCoin::animList;
int SilverCoin::speed;

SilverCoin::SilverCoin(const int & x, const int & y, Aquarium & aquarium, double now) : AquariumObject(Position(x,y), aquarium) {
    animFrame = 0;
    animMode = 0;
    AquariumObject::timeSpawned = now;
    touchedGround = false;
}

Animation SilverCoin::getAnim(int index) {
    return SilverCoin::animList.at(index);
}

Position SilverCoin::getPosition() {
    return AquariumObject::position;
} 

void SilverCoin::removeCoin() {

}

void SilverCoin::update(double now, double secSinceLast) {
    if (touchedGround && animFrame == 0) {
        animFrame = 0;
    }
    else {
        printf("%lf\n", AquariumObject::timeSpawned);
        animFrame = (fmod((now - AquariumObject::timeSpawned) * 50, 60)) / 6;
        move(secSinceLast);
    }
}

void SilverCoin::move(double secSinceLast) {
    double newY = position.y + secSinceLast * speed;
    if (newY <= SCREEN_HEIGHT - 40) {
        position.y = newY;
    }
    else {
        touchedGround = true;
    }
}

int SilverCoin::getAnimMode() {
    return animMode;
}

int SilverCoin::getAnimFrame() {
    return animFrame;
}