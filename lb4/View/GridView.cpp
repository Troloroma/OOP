#include "GridView.h"
#include "../Game/Entity/Player.h"
#include "../Game/Entity/Enemies/Knight.h"
#include "../Game/Entity/Enemies/Horseman.h"
#include "../Game/Entity/Enemies/Wolf.h"
#include "../Game/Entity/Items/Medkit.h"
#include "../Game/Entity/Items/Power.h"
#include "../Game/Entity/Items/Shield.h"

GridView::GridView(Grid& obj) : cell(obj) {}

std::ostream& operator<< (std::ostream& out, const GridView& obj) {
	if (obj.cell.getEntity() == nullptr) {
		if (obj.cell.getType() == "WALL") { out << "#"; }
		if (obj.cell.getType() == "START") { out << "𝥃  "; }
		if (obj.cell.getType() == "FINISH") { out << "🚪 "; }
		if (obj.cell.getType() == "EMPTY") { out << "_  "; }
	}
	else {
		if (typeid(*obj.cell.getEntity()).name() == typeid(Player).name()) {
			out << "👤 ";
		}
		if (typeid(*obj.cell.getEntity()).name() == typeid(Horseman).name()) {
			out << "🐎 ";
		}
		if (typeid(*obj.cell.getEntity()).name() == typeid(Knight).name()) {
			out << "💂 ";
		}
		if (typeid(*obj.cell.getEntity()).name() == typeid(Wolf).name()) {
			out << "🐺 ";
		}
		if (typeid(*obj.cell.getEntity()).name() == typeid(Medkit).name() || typeid(*obj.cell.getEntity()).name() == typeid(Shield).name() || typeid(*obj.cell.getEntity()).name() == typeid(Power).name()) {
			out << "🎁 ";
		}
	}
	return out;
}