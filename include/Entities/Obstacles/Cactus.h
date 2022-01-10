#pragma once

#include "Entities/StaticEntity.h"

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
