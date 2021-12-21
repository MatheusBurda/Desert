#pragma once

#include "Entities/StaticEntity.h"

namespace Entities {

    namespace Obstacles {

        enum EffectID{
            none = 0,
            dealDamage,
            slowness
        };

        class Obstacle : public StaticEntity {
        private:
            EffectID id;

        public:
            Obstacle(Math::CoordF position = Math::CoordF(0.f, 0.f));
            
            ~Obstacle();

            void update(const float dt);

            void initialize();

            void collide(Entity* otherEntity, Math::CoordF intersect);

            EffectID getEffect() const;

            float getMultiplier();
        };

    } // namespace Obstacles

} // namespace Entities
