#include "List/EntityList.h"

namespace List {

    EntityList::EntityList() { }

    EntityList::~EntityList() {
        list.clear();
    }

    void EntityList::addEntity(Entities::Entity* pEntity) {
        if (pEntity == NULL)
            std::cout << "Pointer to entity NULL on addEntity" << std::endl;

        list.push(pEntity);
    }

    void EntityList::removeEntity(Entities::Entity* pEntity) {
        if (pEntity == NULL)
            std::cout << "Pointer to entity NULL on removeEntity" << std::endl;

        list.pop(pEntity);
    }

    void EntityList::removeEntity(unsigned int index) {
        list.pop(index);
    }

    unsigned int EntityList::getSize() {
        return list.getSize();
    }

    Entities::Entity* EntityList::operator[](int index) {
        return list[index];
    }

} // namespace List
