#include "Entities/MovingEntity.h"

namespace Entities {
    MovingEntity::MovingEntity(Math::CoordF position, Math::CoordF size, ID id, Math::CoordF velocity) :
    Entity(position, size, id),
    sprite() {
        active = true;
        this->velocity = velocity;
        facingLeft = false;
        damage = 0;
    }

    MovingEntity::~MovingEntity() { }

    void MovingEntity::render() {
        sprite.render();
    }

    const bool MovingEntity::isFacingLeft() const {
        return facingLeft;
    }

    void MovingEntity::setFacingLeft(const bool left) {
        facingLeft = left;
    }

    void MovingEntity::setFacingLeft() {
        facingLeft = velocity.x >= 0.0f ? false : true;
    }

    const bool MovingEntity::isActive() const {
        return active;
    }

    Math::CoordF MovingEntity::getVelocity() const {
        return velocity;
    }

    void MovingEntity::setVelocity(Math::CoordF velo) {
        velocity = velo;
    }

    void MovingEntity::moveOnCollision(Math::CoordF intersect, Entities::Entity* other) {
        Math::CoordF otherPos = other->getPosition();

        if (intersect.x > intersect.y) { // Colision on x direction
            if (position.x < otherPos.x)
                position.x += intersect.x;
            else
                position.x -= intersect.x;
            velocity.x = 0.0f;
        }

        else { // Colision on y direction
            if (position.y < otherPos.y)
                position.y += intersect.y;

            else
                position.y -= intersect.y;

            velocity.y = 0.0f;
        }
    }

    void MovingEntity::setDamage(unsigned int dmg) {
        damage = dmg;
    }

    unsigned int MovingEntity::getDamage() {
        return damage;
    }

} // namespace Entities
