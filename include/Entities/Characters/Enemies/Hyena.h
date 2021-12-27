#pragma once

#include "Entities/Characters/Enemies/Enemy.h"

namespace Entities {

    namespace Characters {

        namespace Enemies {

            class Hyena : public Enemy {
            private:
                float acceleration;

            public:
                Hyena(Math::CoordF position = Math::CoordF(0.f, 0.f), Entities::Characters::Player* pP = nullptr);

                ~Hyena();

                void update(const float dt);

                void initialize();

                void updateSprite(const float dt);

            };

        } // namespace Enemies

    } // namespace Characters

} // namespace Entities