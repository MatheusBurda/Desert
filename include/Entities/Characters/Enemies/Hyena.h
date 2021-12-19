#pragma once

#include "Entities/Characters/Enemies/Enemy.h"

#define HYENA_SIZE_X 65
#define HYENA_SIZE_Y 50
#define HYENA_LIFE 50

namespace Entities {

    namespace Characters {

        namespace Enemies {

            class Hyena : public Enemy {
            private:
            public:
                Hyena(Math::CoordF position = Math::CoordF(0.f, 0.f), Entities::Characters::Player* pP = NULL);

                ~Hyena();

                void update(const float dt);

                void initialize();

                void collide(Entity* otherEntity, Math::CoordF intersect);

                void updateSprite(const float dt);

            };

        } // namespace Enemies

    } // namespace Characters

} // namespace Entities