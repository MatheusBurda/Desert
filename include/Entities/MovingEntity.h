#pragma once

#include "../GraphicalElements/MultiFrameAnimation.h"
#include "Entity.h"

namespace Entities {

    class MovingEntity : public Entity {
    protected:
        Math::CoordF velocity;
        bool active;
        bool facingLeft;

        GraphicalElements::MultiFrameAnimation sprite;

    public:
        MovingEntity(Math::CoordF position = Math::CoordF(0.f, 0.f),
            Math::CoordF size = Math::CoordF(0.f, 0.f),
            ID id = empty,
            Math::CoordF velocity = Math::CoordF(0.f, 0.f));

        virtual ~MovingEntity();

        virtual void render();

        virtual void update(const float dt) = 0;

        virtual void initialize() = 0;

        virtual void collide(Entity* otherEntity, Math::CoordF intersect) = 0;

        virtual void updateSprite(const float dt) = 0;

        const bool isFacingLeft() const;

        void setFacingLeft(const bool left);

        void setFacingLeft();

        const bool isActive() const;

        Math::CoordF getVelocity() const;

        void setVelocity(Math::CoordF velo);

        void moveOnCollision(Math::CoordF intersect, Entities::Entity* other);
    };

} // namespace Entities
