#pragma once
#include "../Game/Objects/Field.h"
#include "GridView.h"
#include "PlayerView.h"

class FieldView {
private:
	Field& field;
public:
	FieldView(Field& obj);
	void print();
};