#ifndef AQUARIUM_OBJECT_HPP
#define AQUARIUM_OBJECT_HPP

#include "Direction.hpp"
#include "Position.hpp"
#include <string>

class Aquarium;
class AquariumObject {
protected:
    Position position;
    Aquarium& aquarium;

public:
    std::string sprite;

    AquariumObject(const Position & pos, Aquarium & aquarium);
    Position getPosition() const;
    void setPosition(const Position&);
};

#endif