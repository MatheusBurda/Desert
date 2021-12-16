#include "Entities/MovingEntity.h"

namespace Entities {
    MovingEntity::MovingEntity(Math::CoordF position, Math::CoordF size, ID id) :
    Entity(position, size, id),
    sprite() {
        active = true;
        velocity = Math::CoordF(0.0f, 0.0f);
    }

    MovingEntity::~MovingEntity() { }

    void MovingEntity::render(){
        sprite.render();
    }

    const bool MovingEntity::isFacingLeft() const{
        return velocity.x >= 0.0f ? false : true;
    }

    const bool MovingEntity::isActive() const{
        return active;
    }

    Math::CoordF MovingEntity::getVelocity() const{
        return velocity;
    }

    void MovingEntity::setVelocity(Math::CoordF velo){
        velocity = velo;
    }

} // namespace Entities
