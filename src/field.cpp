#include "../include/field.h"


Field::Field(int w, int h)
    :width(w),
    height(h)
    {
    createField(width, height);
}

Field::Field(const Field &other):   //конструктор копирования
    width(other.width),
    height(other.height)
    {
    createField(width, height);
}

Field &Field::operator=(const Field &other){    //оператор копирования
    for(int i = 0; i< width; i++)
        delete [] grid[i];
    delete [] grid;

    width = other.width;
    height = other.height;
    createField(width, height);
    return *this;
}

Field::Field(Field &&other):    //конструктор перемещения
    width(other.width),
    height(other.height),
    grid(other.grid)
    {
    if(&other == this) return;
    other.grid = nullptr;
}

Field &Field::operator=(Field &&other){ //оператор перемещения
    if(this != &other)  //попытка присвоить объект самому себе
        return *this;

    for(int i = 0; i < width; i++)
        delete [] grid[i];
    delete [] grid;

    width = other.width;
    height = other.height;
    grid = other.grid;

    return *this;
}

void Field::createField(int width, int height){
    srand(time(NULL));
    int x_start, y_start, x_end, y_end; //задание случайных координат на границах поля
    /*string cord = getRandom(width, height);
    char *chr_start = new char[cord.length() + 1];  //преобразованние полученной строки в char
    strcpy(chr_start, cord.c_str());
    sscanf(chr_start, "%d %d", &x_start, &y_start);
    cord = getRandom(width, height);
    char *chr_end = new char[cord.length() + 1];
    strcpy(chr_end, cord.c_str());
    sscanf(chr_end, "%d %d", &x_end, &y_end);
    printf("start x = %d, y = %d\n", x_start, y_start);
    printf("end x = %d, y = %d\n", x_end, y_end);
    delete [] chr_start;
    delete [] chr_end;*/    
    x_start = rand()%(width/4) + 1; //создание случайных координат входа и выхода внутри поля
    y_start = rand()%(height/4) + 1;
    x_end = rand()%(width/4) + width*3/4 - 1;
    y_end = rand()%(height/4) + height*3/4 - 1;

    grid = new Grid*[width];
    for (int i = 0; i < width; i++) {
        grid[i] = new Grid[height];
        for (int j = 0; j < height; j++) {
            if (i * j == 0 || i == width - 1 || j == height - 1) {   //назначение краев карты
                grid[i][j] = Grid(i, j, BORDER);
            }
            else
                grid[i][j] = Grid(i, j, EMPTY);    //остальные пустые клетки
        }
    }
    grid[x_start][y_start] = Grid(x_start, y_start, START);
    grid[x_end][y_end] = Grid(x_end, y_end, END);
    drawField(width, height);
}

string Field::getRandom(int width, int height){ //получение случайных входа и выхода по краям поля
    int x = rand() % width;
    int y = rand() % height;
    if(rand() % 2 == 0){
        if((x == 0) || (x == width - 1)){}  //крайний левый или правый столбец
        else{
            if((height - 1 - y) < (0 + y))  //остальные столбцы
                y = height - 1;
            else
                y = 0;  
        }
    }
    else{
        if((y == 0) || (y == height - 1)){} //верхняя или нижняя строка
        else{    
            if((width - 1 - x) < (0 + x))   //остальные строки
                x = width - 1;
            else
                x = 0;
        }
    }
    string res = to_string(x) + " " + to_string(y);
    return res;
}

void Field::createField(){
    createField(10, 10);
}

void Field::createField(int size){
    createField(size, size);
}

void Field::drawField(int width, int height) {
    string char_to_str = "";    //преобразование char в string для отрисовки поля
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            char_to_str += grid[i][j].getValue();
            cout << " " + char_to_str;
            char_to_str = "";
        }
        cout << "" << endl;
    }
}

Field::~Field() {
    for (int i = 0; i < width; i++) {
        delete [] grid[i];
    }
    delete[] grid;
}