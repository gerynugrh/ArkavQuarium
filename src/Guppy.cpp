#include "Guppy.hpp"

Guppy::Guppy(const int & x, const int & y, Aquarium & aquarium) : AquariumObject(Position(x, y), aquarium), Fish(Fish::Type::GUPPY) {
    sprite = "../res/ikan.png";
    amountOfFood = 0;
}

void Guppy::update() {

}

int Guppy::getStage() const {
    return stage;
}

Position Guppy::getPosition() const {
    return AquariumObject::position;
}

bool Guppy::eat() {
    amountOfFood++;
}

Coin& Guppy::produceCoin() {

}

void Guppy::upgrade() {

}

void Guppy::findNearestFood() {

}

void Guppy::move() {

}