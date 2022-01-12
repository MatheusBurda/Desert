#pragma once

#include "Entities/StaticEntity.h"

#define CACTUS_WIDTH 32.f
#define CACTUS_HEIGHT 70.f 

namespace Entities {

    namespace Obstacles {

        class Cactus : public StaticEntity {
        public:
            Cactus(Math::CoordF position = Math::CoordF(0.f, 0.f));
            
            ~Cactus();

            void initialize();

            unsigned int getDamage() const;
        };

    } // namespace Obstacles

} // namespace Entities
