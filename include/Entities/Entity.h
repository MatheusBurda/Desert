#pragma once

#include "../Math/CoordTL.h"

namespace Entities {

    enum ID {
        empty = 0,
        player,
        platform
    };

    class Entity {
    private:
        Math::CoordF position;
        Math::CoordF size;
        ID id;

    public:
        Entity(Math::CoordF position = Math::CoordF(0.f, 0.f), Math::CoordF size = Math::CoordF(0.f, 0.f), ID id = empty);

        ~Entity();

        void setPosition(Math::CoordF pos);

        Math::CoordF getPosition() const;

        Math::CoordF getSize() const;

        ID getId() const;

        virtual void render();

        virtual void update(float dt) = 0;

        virtual void initiallize() = 0;
    };

}