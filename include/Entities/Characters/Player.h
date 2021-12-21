#pragma once

#include "Entities/Characters/Character.h"

namespace Entities {

    namespace Characters {

        class Player : public Character {
        private:
            const bool isPlayer1;
            float time;

        public:
            Player(Math::CoordF position = Math::CoordF(0.f, 0.f), bool isPLayer1 = true);
            ~Player();

            void update(const float dt);

            void initialize();

            void collide(Entity* otherEntity, Math::CoordF intersect);

            void updateSprite(const float dt);

        };

    }

}