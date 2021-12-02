#pragma once

#include "../Entity.h"

namespace Entities {

    namespace Characters {

        class Player : public Entity {
        private:
        public:
            Player();
            ~Player();

            void update(float dt);

            void initiallize();
        };

    }

}