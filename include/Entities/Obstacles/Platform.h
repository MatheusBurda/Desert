#pragma once

#include "Entities/StaticEntity.h"

#define PLATFORM_WIDTH 96.f
#define PLATFORM_HEIGHT 32.f
#define PLATFORM_PATH "./assets/Obstacles/Platform.png"

namespace Entities {

    namespace Obstacles {

        class Platform : public StaticEntity {
        private:

        public:
            Platform(Math::CoordF position = Math::CoordF(0.f, 0.f));
            ~Platform();

            void update(float dt);

            void initialize();

            void collide(Entity* otherEntity, Math::CoordF intersect);
        };

    } // namespace Obstacles

} // namespace Entities
