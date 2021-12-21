#pragma once

#include "Entities/StaticEntity.h"

namespace Entities {

    namespace Obstacles {

        class Platform : public StaticEntity {
        private:

        public:
            Platform(Math::CoordF position = Math::CoordF(0.f, 0.f));
            ~Platform();

            void update(const float dt);

            void initialize();

            void collide(Entity* otherEntity, Math::CoordF intersect);
        };

    } // namespace Obstacles

} // namespace Entities
