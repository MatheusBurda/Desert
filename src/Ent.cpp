#include "Ent.h"

Ent::Ent(Math::CoordF position, Math::CoordF size) :
position(position),
size(size) { }

Ent::~Ent() { }

void Ent::setPosition(Math::CoordF pos) {
    this->position = pos;
}

Math::CoordF Ent::getPosition() const {
    return position;
}

void Ent::setSize(Math::CoordF size) {
    this->size = size;
}

Math::CoordF Ent::getSize() const {
    return size;
}