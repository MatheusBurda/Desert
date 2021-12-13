#include "Entities/StaticEntity.h"

namespace Entities {

    StaticEntity::StaticEntity(Math::CoordF position, Math::CoordF size, ID id) :
    Entity(position, size, id),
    sprite() {
    }

    StaticEntity::~StaticEntity() {
    }

    void StaticEntity::render() {
        sprite.render();
    }

} // namespace Entities
