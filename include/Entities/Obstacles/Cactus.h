#pragma once

#include "Entities/StaticEntity.h"

#define CACTUS_WIDTH 96.f
#define CACTUS_HEIGHT 32.f
#define CACTUS_PATH "./assets/Obstacles/Cactus.png"

namespace Entities {

    namespace Obstacles {

        class Cactus : public StaticEntity {
        private:

        public:
            Cactus(Math::CoordF position = Math::CoordF(0.f, 0.f));
            ~Cactus();

            void update(const float dt);

            void initialize();

            void collide(Entity* otherEntity, Math::CoordF intersect);
        };

    } // namespace Obstacles

} // namespace Entities
