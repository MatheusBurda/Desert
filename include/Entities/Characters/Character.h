#pragma once

#include "Entities/MovingEntity.h"

namespace Entities {

    namespace Characters {

        class Character : public MovingEntity {
        protected:
            int life;
            bool flagIsAttacking;
            const float attackCooldown;
            const float attackingTime;
            float attackTimer;
            float cooldownTimer;
            bool hasAttacked;

        public:
            Character(Math::CoordF position = Math::CoordF(0.f, 0.f),
                Math::CoordF size = Math::CoordF(0.f, 0.f),
                ID id = empty,
                int life = 1,
                const float attackCooldown = 0.0f,
                const float attackingTime = 0.0f);

            virtual ~Character();

            const int getLife() const;

            virtual void receiveDamage(const int damage);

            virtual void update(const float dt) = 0;

            virtual void initialize() = 0;

            virtual void collide(Entity* otherEntity, Math::CoordF intersect) = 0;

            virtual void updateSprite(const float dt) = 0;

            virtual void attack();

            const bool canAttack() const;

            void incrementAttackTime(const float dt);

            const bool isAttacking() const;

            unsigned int getDamage();
        };

    } // namespace Characters

} // namespace Entities
