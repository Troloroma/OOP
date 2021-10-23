#pragma once

enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};
class IMove{
public:
    virtual void move(Direction direction) = 0;
};

