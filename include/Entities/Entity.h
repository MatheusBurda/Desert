#pragma once

#include "../Math/CoordTL.h"
#include "../GraphicalElements/Animation.h"
#include "math.h"

#define GRAVITY 980.f

namespace Entities {

    enum ID {
        empty = 0,
        player,
        platform,
        snake,
        hyena,
        cactus

    };

    class Entity {
    protected:
        Math::CoordF position;
        Math::CoordF size;
        ID id;

    public:
        Entity(Math::CoordF position = Math::CoordF(0.f, 0.f), Math::CoordF size = Math::CoordF(0.f, 0.f), ID id = empty);

        virtual ~Entity();

        void setPosition(Math::CoordF pos);

        Math::CoordF getPosition() const;

        Math::CoordF getSize() const;

        ID getId() const;

        virtual void render() = 0;

        virtual void update(const float dt) = 0;

        virtual void initialize() = 0;

        virtual void collide(Entity* otherEntity, Math::CoordF intersect) = 0;

    };

}