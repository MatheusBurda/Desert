#pragma once

#include "Entities/MovingEntity.h"

namespace Entities {

    namespace Loot {

        class Coin : public MovingEntity {
        public:
            Coin(Math::CoordF position = Math::CoordF(0.f, 0.f), Math::CoordF velocity = Math::CoordF(0.f, 0.f));

            ~Coin();

            virtual void update(const float dt);

            virtual void initialize();

            virtual void collide(Entity* otherEntity, Math::CoordF intersect);

            virtual void updateSprite(const float dt);
        };

    } // namespace Loot

} // namespace Entities
