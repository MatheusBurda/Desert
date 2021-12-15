#pragma once

#include "Entities/Characters/Character.h"

namespace Entities {

    namespace Characters {

        class Player;

        namespace Enemies {

            class Enemy : public Character{
            private:
                Player* pPlayer1;
                Player* pPlayer2;

            public:
                Enemy(Math::CoordF position = Math::CoordF(0.f, 0.f), Math::CoordF size = Math::CoordF(0.f, 0.f), ID id = empty, int life = 1, Entities::Characters::Player* pP1 = NULL, Entities::Characters::Player* pP2 = NULL);
                ~Enemy();

                void setpPlayer1(Entities::Characters::Player* pP1);
                void setpPlayer2(Entities::Characters::Player* pP2);

                Entities::Characters::Player* getNearestPlayer();

            };

        } // namespace Enemies

    } // namespace Characters

} // namespace Entities
