#include "AquariumObject.hpp"

AquariumObject::AquariumObject(const Position & pos, Aquarium & aquarium) : aquarium(aquarium) {
    position = pos;  
}

Position AquariumObject::getPosition() const {
    return position;
}

void AquariumObject::setPosition(const Position & pos) {
    position = pos;
}