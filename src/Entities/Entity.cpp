#include "Entities/Entity.h"

namespace Entities {
    
    Entity::Entity(Math::CoordF position, Math::CoordF size, ID id) :
    position(position),
    size(size),
    id(id) { }

    Entity::~Entity() { }

    void Entity::setPosition(Math::CoordF pos) {
        this->position = pos;
    }

    Math::CoordF Entity::getPosition() const {
        return position;
    }

    Math::CoordF Entity::getSize() const {
        return size;
    }

    ID Entity::getId() const {
        return id;
    }

    void Entity::render(){
        
    }
    
}