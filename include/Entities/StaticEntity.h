#pragma once

#include "Entities/Entity.h"
#include "GraphicalElements/SingleFrameAnimation.h"

namespace Entities {

    class StaticEntity : public Entity {
    protected:
        GraphicalElements::SingleFrameAnimation sprite;

    public:
        StaticEntity(Math::CoordF position = Math::CoordF(0.f, 0.f), Math::CoordF size = Math::CoordF(0.f, 0.f), ID id = empty);

        virtual ~StaticEntity();

        void render();

        virtual void update(const float dt) { }

        virtual void initialize() = 0;

        virtual void collide(Entity* otherEntity, Math::CoordF intersect) { }
    };

} // namespace Entities
