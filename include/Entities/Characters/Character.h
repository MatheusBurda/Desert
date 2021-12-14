#pragma once

#include "Entities/MovingEntity.h"

namespace Entities {

    namespace Characters {

        class Character : public MovingEntity {
        private:
            int life;

        public:
            Character(Math::CoordF position = Math::CoordF(0.f, 0.f), Math::CoordF size = Math::CoordF(0.f, 0.f), ID id = empty, int life = 1);
            
            ~Character();

            const int getLife() const;

            void receiveDamage(const int damage);

            void moveOnCollision(Math::CoordF intersect, Entities::Entity* other);
        };

    } // namespace Characters

} // namespace Entities
