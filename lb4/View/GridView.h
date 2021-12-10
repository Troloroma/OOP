#pragma once
#include "../Game/Objects/Grid.h"

class GridView {
private:
	Grid& cell;
public:
	GridView(Grid& obj);
	friend std::ostream& operator<< (std::ostream& out, const GridView& obj);
};