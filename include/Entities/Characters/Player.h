#pragma once

#include "../Entity.h"

#define PLAYER_SIZE_X 100.0f
#define PLAYER_SIZE_Y 100.0f

namespace Entities {

    namespace Characters {

        class Player : public Entity {
        private:
            const bool isPlayer1;
            float time;

        public:
            Player(Math::CoordF position = Math::CoordF(0.f, 0.f), bool isPLayer1 = true);
            ~Player();

            void update(float dt);

            void initiallize();
        };

    }

}