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
        Entities::Entity* removeEntity(Entities::Entity* pEntity);
        Entities::Entity* removeEntity(unsigned int index);
        void deleteEntity(Entities::Entity* pEntity);
        void deleteEntity(unsigned int index);
        unsigned int getSize();
        Entities::Entity* operator[](int index);
    };

} // namespace List
