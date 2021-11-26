#pragma once
#include "item.h"

class Gaze : public Item{   //взгляд (увеличение дальности атаки персонажа)
public:
    Gaze(int, int, Field *);
    void effect(Player &);
};