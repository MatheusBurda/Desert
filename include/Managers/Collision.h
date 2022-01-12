#pragma once

#include "Entities/Entity.h"
#include "List/EntityList.h"

namespace States {
    class Level;
} // namespace States

namespace Managers {

    class Collision {
    private:
        List::EntityList* movingEntities;
        List::EntityList* staticEntities;
        States::Level* plvl;

    public:
        Collision(List::EntityList* movingEntities, List::EntityList* staticEntities, States::Level* plvl);

        ~Collision();

        void collide();

        void clear();
    };

} // namespace Managers
