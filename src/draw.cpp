#include "../include/draw.h"

void Draw::drawField(Field *field){
    int width = field->getWidth();
    int height = field->getHeight();
    string char_to_str = "";    //преобразование char в string для отрисовки поля
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            char_to_str += field->grid[i][j].getValue();
            cout << " " + char_to_str;
            char_to_str = "";
        }
        cout << "" << endl;
    }
}