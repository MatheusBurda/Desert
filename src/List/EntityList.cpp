#include "List/EntityList.h"

namespace List {

    EntityList::EntityList() { }

    EntityList::~EntityList() {
        list.clear();
    }

    void EntityList::addEntity(Entities::Entity* pEntity) {
        if (pEntity == nullptr)
            std::cout << "Pointer to entity nullptr on addEntity" << std::endl;

        list.push(pEntity);
    }

    Entities::Entity* EntityList::removeEntity(Entities::Entity* pEntity) {
        if (pEntity == nullptr)
            std::cout << "Pointer to entity nullptr on removeEntity" << std::endl;

        return list.pop(pEntity);
    }

    Entities::Entity* EntityList::removeEntity(unsigned int index) {
        return list.pop(index);
    }

    void EntityList::deleteEntity(Entities::Entity* pEntity) {
        Entities::Entity* tmp = nullptr;

        tmp = list.pop(pEntity);

        if (tmp)
            delete (tmp);
    }

    void EntityList::deleteEntity(unsigned int index) {
        Entities::Entity* tmp = nullptr;

        tmp = list.pop(index);

        if (tmp)
            delete (tmp);
    }

    unsigned int EntityList::getSize() {
        return list.getSize();
    }

    Entities::Entity* EntityList::operator[](int index) {
        return list[index];
    }

    void EntityList::cleanList(){
        list.clear();
    }

} // namespace List
