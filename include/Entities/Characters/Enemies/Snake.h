#pragma once

#include "Entities/Characters/Enemies/Enemy.h"

#define SNAKE_SIZE_X 60
#define SNAKE_SIZE_Y 26
#define SNAKE_LIFE 50

namespace Entities {

    namespace Characters {

        namespace Enemies {

            class Snake : public Enemy {
            private:
            public:
                Snake(Math::CoordF position = Math::CoordF(0.f, 0.f), Entities::Characters::Player* pP = NULL);

                ~Snake();

                void update(const float dt);

                void initialize();

                void collide(Entity* otherEntity, Math::CoordF intersect);

                void updateSprite(const float dt);

            };

        } // namespace Enemies

    } // namespace Characters

} // namespace Entities