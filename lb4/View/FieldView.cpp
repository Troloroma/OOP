#include "FieldView.h"


FieldView::FieldView(Field& obj) : field(obj) {}
void FieldView::print() {
	for (int i = 0; i < field.getWidth(); i++) {
		for (int j = 0; j < field.getHeight(); j++) {
			GridView tmp(field.board[i][j]);
			std::cout << tmp;
		}
		std::cout << '\n';
	}
	PlayerView charStats(dynamic_cast<Player&>(*field.getPlayer()->getEntity()));
	charStats.printStats();
}