#ifndef AQUARIUM_OBJECT_HPP
#define AQUARIUM_OBJECT_HPP

#include "Direction.hpp"
#include "Position.hpp"
#include <string>
#include <vector>
#include "Animation.hpp"
#include <random>

#define PI 3.14159265

class Aquarium;
extern std::default_random_engine generator;
extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;
class AquariumObject {
protected:
    Position position;
    Aquarium& aquarium;

public:
    double timeSpawned, direction, moveDuration;
    AquariumObject(const Position & pos, Aquarium & aquarium);
    Position getPosition() const;
    void setPosition(const Position&);
    virtual Animation getAnim(int index) = 0;
};

#endif