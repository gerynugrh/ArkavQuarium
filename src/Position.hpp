#ifndef POSITION_HPP
#define POSITION_HPP

class Position {   
public:
    int x, y;
    Position();
    Position(const int&, const int&);
    double distanceFrom(const Position &);
};

#endif