#pragma once

#include "Control/PlayerControl.h"
#include "Entities/Characters/Character.h"

namespace Entities {

    namespace Characters {

        class Player : public Character {
        private:
            Control::PlayerControl pControl;
            bool isWalking;
            bool canJump;
            bool sprinting;
            unsigned int points;
            unsigned int coins;
            const float swordDistance;

        public:
            Player(Math::CoordF position = Math::CoordF(0.f, 0.f));

            ~Player();

            void update(const float dt);

            void initialize();

            void collide(Entity* otherEntity, Math::CoordF intersect);

            void updateSprite(const float dt);

            void jump();

            void walk(bool toLeft);

            void stopWalking();

            unsigned int getPlayerPoints() const;

            void incrementPoints(unsigned int points);

            unsigned int getCoins() const;

            void setIsSprinting(const bool option);

        };

    }

}