#pragma once

#include "Entities/Characters/Character.h"

#define PLAYER_SIZE_Y 84.0f
#define PLAYER_SIZE_X 32.0f
#define PLAYER_LIFE 100

namespace Entities {

    namespace Characters {

        class Player : public Character {
        private:
            const bool isPlayer1;
            float time;

        public:
            Player(Math::CoordF position = Math::CoordF(0.f, 0.f), bool isPLayer1 = true);
            ~Player();

            void update(float dt);

            void initialize();

            void collide(Entity* otherEntity, Math::CoordF intersect);

        };

    }

}