#include "../include/item.h"

Item::Item(int x, int y, Field* field) : GridEntity(x, y, field) {
    entityType = ITEM;
}