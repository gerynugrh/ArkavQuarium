#ifndef AQUARIUM_OBJECT_HPP
#define AQUARIUM_OBJECT_HPP

#include "Direction.hpp"
#include "Position.hpp"

class Aquarium;
class AquariumObject {
protected:
    Direction direction;
    Position position;
    Aquarium& aquarium;

public:
    std::string sprite;

    AquariumObject(const Position & pos, const Aquarium & aquarium);
    AquariumObject(const Position & pos, const Direction & dir, const Aquarium & aquarium);
    Position getPosition() const;
    Direction getDirection() const;
    void setPosition(const Position&);
    void setDirection(const Direction&);
};

#endif