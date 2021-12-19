#pragma once

#include "Entities/MovingEntity.h"

namespace Entities {

    namespace Characters {

        class Character : public MovingEntity {
        private:
            int life;
            bool isAttacking;
            const float attackCooldown;
            float attackTime;

        public:
            Character(Math::CoordF position = Math::CoordF(0.f, 0.f),
                Math::CoordF size = Math::CoordF(0.f, 0.f),
                ID id = empty,
                int life = 1,
                const float atckCool = 0.0f);

            ~Character();

            const int getLife() const;

            void receiveDamage(const int damage);

            void moveOnCollision(Math::CoordF intersect, Entities::Entity* other);

            virtual void update(const float dt) = 0;

            virtual void initialize() = 0;

            virtual void collide(Entity* otherEntity, Math::CoordF intersect) = 0;

            virtual void updateSprite(const float dt) = 0;

            virtual void attack();

            const bool canAttack() const;
        };

    } // namespace Characters

} // namespace Entities
