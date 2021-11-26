#include "../include/field.h"

Field::Field(int w, int h)
    :width(w),
    height(h)
    {
    createField(width, height);
}

void Field::createField(int width, int height){
    srand(time(NULL));
    int x_start, y_start, x_end, y_end; //задание случайных координат на границах поля    
    x_start = rand()%(width/4) + 1; //создание случайных координат входа и выхода внутри поля
    y_start = rand()%(height/4) + 1;
    x_end = rand()%(width/4) + width*3/4 - 1;
    y_end = rand()%(height/4) + height*3/4 - 1;
    
    grid = new Grid*[width];
    for (int i = 0; i < width; i++) {
        grid[i] = new Grid[height];
        for (int j = 0; j < height; j++) {
            if (i * j == 0 || i == width - 1 || j == height - 1) {   //назначение краев карты
                grid[i][j] = Grid(i, j, Grid::BORDER);
            }
            else
                grid[i][j] = Grid(i, j, Grid::EMPTY);    //остальные пустые клетки
        }
    }
    grid[x_start][y_start] = Grid(x_start, y_start, Grid::START);
    grid[x_end][y_end] = Grid(x_end, y_end, Grid::END);
}

Field::Field(const Field &other):   //конструктор копирования
    width(other.width),
    height(other.height)
    {
    for(int i = 0; i < width; i++){
        for(int j = 0; j < width; j++){
            grid[i][j] = other.grid[i][j];
        }
    }
}

Field &Field::operator=(const Field &other){    //оператор копирования
    if(&other == this) return *this;
    for(int i = 0; i < width; i++)
        delete [] grid[i];
    delete [] grid;

    width = other.width;
    height = other.height;
    grid = new Grid*[width];
    for(int i = 0; i < width; i++){
        grid[i] = new Grid[height];
    }
    for(int i = 0; i < width; i++){
        for (int j = 0; j < height; j++){
            grid[i][j] = other.grid[i][j];
        }
    }
    return *this;
}

Field::Field(Field &&other):    //конструктор перемещения
    width(other.width),
    height(other.height),
    grid(other.grid)
    {
    std::swap(grid, other.grid);
    std::swap(width, other.width);
    std::swap(height, other.height);
}

Field &Field::operator=(Field &&other){ //оператор перемещения
    if(this == &other)  //попытка присвоить объект самому себе
        return *this;
    std::swap(grid, other.grid);
    std::swap(width, other.width);
    std::swap(height, other.height);
    return *this;
}

void Field::createField(){
    createField(10, 10);
}

void Field::createField(int size){
    createField(size, size);
}

Grid Field::getGrid(int x, int y){
    return grid[x][y];
}

int Field::getWidth(){
    return width;
}

int Field::getHeight(){
    return height;
}

Field::~Field() {
    for (int i = 0; i < width; i++) {
        delete [] grid[i];
    }
    delete[] grid;
}