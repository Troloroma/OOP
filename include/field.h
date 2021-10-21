using namespace std;
#pragma once
#include "grid.h"
#include <string.h>

class Field{
private:
    int height = 0;
    int width = 0;
    void createField(int width, int height);
    void createField();
    void createField(int size);
    void drawField(int width, int height);
    string getRandom(int width, int height);
    Grid** grid;
public:
    Field(int width, int height);
    Field(const Field &);   //копирование
    Field &operator=(const Field &);
    Field(Field &&);
    Field &operator=(Field &&);
    ~Field();
};