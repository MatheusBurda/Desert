#pragma once

#include "../Entities/Entity.h"
#include "List/List.h"

namespace List {

    class EntityList {
    private:
        List<Entities::Entity> list;

    public:
        EntityList();
        ~EntityList();

        void addEntity(Entities::Entity* pEntity);
        void removeEntity(Entities::Entity* pEntity);
        void removeEntity(unsigned int index);
        unsigned int getSize();
        Entities::Entity* operator[](int index);
    };

} // namespace List
