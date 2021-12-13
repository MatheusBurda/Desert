#include "Entities/Characters/Character.h"

namespace Entities {

    namespace Characters {

        Character::Character(Math::CoordF position, Math::CoordF size, ID id, int life) :
        MovingEntity(position, size, id) {
            this->life = life;
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

        void Character::moveOnCollision(Math::CoordF intersect, Math::CoordF otherPos) {
            if (intersect.x > intersect.y) { // Colision on x direction
                if (position.x < otherPos.x)
                    position.x += intersect.x;
                else
                    position.x -= intersect.x;
                velocity.x = 0.0f;
            }

            else {                          // Colision on y direction
                if (position.y < otherPos.y)
                    position.y += intersect.y;
                else
                    position.y -= intersect.y;
                velocity.y = 0.0f;
            }
        }

    } // namespace Characters

} // namespace Entities
