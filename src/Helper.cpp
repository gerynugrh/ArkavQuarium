#include "Helper.hpp"
#include <cmath>
#include <iostream>

double getArea(Position p1, Position p2) {
    printf("%lf\n", std::abs(p1.x - p2.x) * std::abs(p1.y - p2.y));
    return std::abs(p1.x - p2.x) * std::abs(p1.y - p2.y);
}