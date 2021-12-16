#pragma once

#include "Entities/Characters/Character.h"

namespace Entities {

    namespace Characters {

        class Player;

        namespace Enemies {

            class Enemy : public Character {
            private:
                Player* pPlayer;
                
            public:
                Enemy(Math::CoordF position = Math::CoordF(0.f, 0.f), Math::CoordF size = Math::CoordF(0.f, 0.f), ID id = empty, int life = 1, Entities::Characters::Player* pP = NULL);
                
                ~Enemy();

                void setpPlayer(Entities::Characters::Player* pP);

                Math::CoordF getPlayerPosition();

                virtual void update(const float dt) = 0;

                virtual void initialize() = 0;

                virtual void collide(Entity* otherEntity, Math::CoordF intersect) = 0;

                virtual void updateSprite(const float dt) = 0;

            };

        } // namespace Enemies

    } // namespace Characters

} // namespace Entities
