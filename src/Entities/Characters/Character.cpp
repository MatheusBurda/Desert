#include "Entities/Characters/Character.h"

namespace Entities {

    namespace Characters {

        Character::Character(Math::CoordF position, Math::CoordF size, ID id, int life, const float atckCool) :
        MovingEntity(position, size, id),
        attackCooldown(atckCool) {
            this->life = life;
            this->cooldownTime = 0;
            this->attackTime = 0;
            flagIsAttacking = false;
        }

        Character::~Character() { }

        const int Character::getLife() const {
            return life;
        }

        void Character::receiveDamage(const int damage) {
            life -= damage;
            if (life <= 0)
                active = false;
        }

        void Character::moveOnCollision(Math::CoordF intersect, Entities::Entity* other) {
            Math::CoordF otherPos = other->getPosition();
            Math::CoordF otherVelo = static_cast<Entities::Characters::Character*>(other)->getVelocity();
            if (intersect.x > intersect.y) { // Colision on x direction
                if (position.x < otherPos.x)
                    position.x += intersect.x;
                else
                    position.x -= intersect.x;
                velocity.x *= 0.0f;
            }

            else {                          // Colision on y direction
                if (position.y < otherPos.y)
                    position.y += intersect.y;

                else
                    position.y -= intersect.y;

                velocity.y = 0.0f;
            }
        }

        const bool Character::canAttack() const {
            return cooldownTime > attackCooldown ? true : false;
        }

        void Character::attack() {
            if (canAttack())
                flagIsAttacking = true;
        }

        void Character::incrementAttackTime(const float dt) {
            if (flagIsAttacking) {
                cooldownTime = 0;
                attackTime += dt;
                if (attackTime > attackCooldown)
                    flagIsAttacking = false;
            } //
            else {
                cooldownTime += dt;
                attackTime = 0;
            }
        }

        const bool Character::isAttacking() const {
            return flagIsAttacking;
        }

    } // namespace Characters

} // namespace Entities
