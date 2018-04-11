#include "NormalSnail.hpp"
#include <cmath>

std::vector<Animation> NormalSnail::animList;
int NormalSnail::speed;

NormalSnail::NormalSnail(const int & x, const int & y, const int & type, Aquarium & aquarium, double now) : AquariumObject(Position(x, y), aquarium) {
    AquariumObject::timeSpawned = now;
    animFrame = 0;
    animMode = 0;
    idle = false;
    right = false;
}

Position NormalSnail::getPosition() {
    return position;
}

void NormalSnail::update(double now, double secSinceLast) {
    printf("%lf\n", AquariumObject::timeSpawned);
    if (animMode % 3 == 1 && animFrame == 9) {

    }
    else if (right && animMode % 3 == 2 && animFrame == 9) {
        animMode = 0 + 3 * right;
        animFrame = 0;
        AquariumObject::timeSpawned = now;
    }
    else if (!right && animMode % 3 == 2) {
        animFrame = 9 - (fmod((now - AquariumObject::timeSpawned) * 50, 60)) / 6;
        if (animFrame == 0) {
            animMode = 0 + 3 * right;
            animFrame = 0;
            AquariumObject::timeSpawned = now;            
        }
    }
    else {
        NormalSnail::animFrame = (fmod((now - AquariumObject::timeSpawned) * 50, 60)) / 6;
    }
    if (!idle && findNearestCoin() == NULL) {
        direction = 0;
        animMode = 1 + 3 * right;
        animFrame = 0;
        idle = true;
        AquariumObject::timeSpawned = now;
    }
    else if (findNearestCoin() != NULL) {
        if (idle) {
            idle = false;
            animMode = 0 + 3 * right;
            animFrame = 0;
            AquariumObject::timeSpawned = now;
        }
        move(secSinceLast);
        takeCoin();
    }
    if (direction == 1 && !right) {
        animMode = 2 + 3 * right;
        if (right) {
            animFrame = 9;
        }
        AquariumObject::timeSpawned = now;
        right = true;
    }
    else if (direction == -1 && right) {
        animMode = 2 + 3 * right;
        if (right) {
            animFrame = 9;
        }
        AquariumObject::timeSpawned = now;
        right = false;        
    }
}

Animation NormalSnail::getAnim(int index) {
    return NormalSnail::animList.at(index);
}

int NormalSnail::getAnimFrame() {
    return animFrame;
}

int NormalSnail::getAnimMode() {
    return animMode;
}

void NormalSnail::move(double secSinceLast) {
    Coin * nearestCoin = findNearestCoin();
    if (nearestCoin->getPosition().x < position.x && position.x - nearestCoin->getPosition().x >= 20) {
        direction = -1;
    }
    else if (nearestCoin->getPosition().x > position.x && nearestCoin->getPosition().x - position.x >= 20){
        direction = 1;
    }
    else if (abs(nearestCoin->getPosition().x - position.x) <= 20) {
        animFrame = 0;
        direction = 0;
    }
    position.x += direction * speed * secSinceLast;
}

Coin * NormalSnail::findNearestCoin() {
    Coin * nearestCoin = NULL;
    double minDistance = 9999;
    for (int i = 0; i < aquarium.coins.length(); i++) {
        Coin * coin = aquarium.coins[i];
        if (position.distanceFrom(coin->getPosition()) < minDistance) {
            minDistance = position.distanceFrom(coin->getPosition());
            nearestCoin = coin;
        }
    }
    return nearestCoin;
}

bool NormalSnail::takeCoin() {
    Coin * coin = findNearestCoin();
    if (position.distanceFrom(coin->getPosition()) <= 20) {
        aquarium.coins.remove(coin);
        return true;
    }
    return false;
}

