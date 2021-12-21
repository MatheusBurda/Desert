#pragma once

#include "Entities/StaticEntity.h"

#define QUICKSAND_WIDTH 96.f
#define QUICKSAND_HEIGHT 32.f
#define QUICKSAND_PATH "./assets/Obstacles/Quicksand.png"

namespace Entities {

    namespace Obstacles {

        class Quicksand : public StaticEntity {
        private:

        public:
            Quicksand(Math::CoordF position = Math::CoordF(0.f, 0.f));
            ~Quicksand();

            void update(const float dt);

            void initialize();

            void collide(Entity* otherEntity, Math::CoordF intersect);
        };

    } // namespace Obstacles

} // namespace Entities
