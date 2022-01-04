#include "Entities/Entity.h"

namespace Entities {

    Entity::Entity(Math::CoordF position, Math::CoordF size, ID id) :
    Ent(position, size),
    id(id) { }

    Entity::~Entity() { }

    ID Entity::getId() const {
        return id;
    }

}