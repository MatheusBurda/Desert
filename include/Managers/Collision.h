#pragma once

#include "Entities/Entity.h"
#include "List/EntityList.h"

namespace Managers {

    class Collision {
    private:
        List::EntityList* movingEntities;
        List::EntityList* staticEntities;

    public:
        Collision(List::EntityList* movingEntities, List::EntityList* staticEntities);
        ~Collision();

        void collide();
        void clear();
    };

} // namespace Managers
