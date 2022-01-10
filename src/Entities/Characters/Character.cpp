#include "Entities/Characters/Character.h"

namespace Entities {

    namespace Characters {

        Character::Character(Math::CoordF position, Math::CoordF size, ID id, int life, const float atckCool, const float attackingTime) :
        MovingEntity(position, size, id),
        attackCooldown(atckCool),
        attackingTime(attackingTime) {
            this->life = life;
            this->cooldownTimer = 0;
            this->attackTimer = 0;
            flagIsAttacking = false;
            hasAttacked = false;
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

        const bool Character::canAttack() const {
            return cooldownTimer > attackCooldown ? true : false;
        }

        void Character::attack() {
            if (canAttack()) {
                flagIsAttacking = true;
                hasAttacked = false;
            }
        }

        void Character::incrementAttackTime(const float dt) {
            if (flagIsAttacking) {
                cooldownTimer = 0;
                attackTimer += dt;
                if (attackTimer > attackingTime)
                    flagIsAttacking = false;
            } //
            else {
                cooldownTimer += dt;
                attackTimer = 0;
            }
        }

        const bool Character::isAttacking() const {
            return flagIsAttacking;
        }

        unsigned int Character::getDamage() {
            if (isAttacking() && !hasAttacked) {
                hasAttacked = true;
                return damage;
            }
            return 0;
        }

    } // namespace Characters

} // namespace Entities
