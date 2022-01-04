#pragma once

#include "Entities/Characters/Character.h"
#include "Control/PlayerControl.h"

namespace Entities {

    namespace Characters {

        class Player : public Character {
        private:
            Control::PlayerControl pControl;
            bool isWalking;
            bool canJump;
            int points;

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

           int getPlayerPoints() const;

        };

    }

}