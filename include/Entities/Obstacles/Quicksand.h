#pragma once

#include "Entities/StaticEntity.h"

namespace Entities {

    namespace Obstacles {

        class Quicksand : public StaticEntity {
        public:
            Quicksand(Math::CoordF position = Math::CoordF(0.f, 0.f));

            ~Quicksand();

            void initialize();

            const float getSlowness() const;
        };

    } // namespace Obstacles

} // namespace Entities
