#include "Position.hpp"
#include <cmath>

Position::Position() {
    x = 0;
    y = 0;
}

Position::Position(const int & x, const int & y) {
    this->x = x;
    this->y = y;
}

double Position::distanceFrom(const Position & pos) {
    double distance = sqrt((x - pos.x) * (x - pos.x) + (y - pos.y) * (y - pos.y));

    return distance;
}