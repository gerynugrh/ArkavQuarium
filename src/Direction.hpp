#ifndef DIRECTION_HPP
#define DIRECTION_HPP

class Direction {
public:
    bool up, down, right, left;
    Direction();
    Direction(bool, bool, bool, bool);
};

#endif