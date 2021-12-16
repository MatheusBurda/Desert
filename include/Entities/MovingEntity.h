#pragma once

#include "Entity.h"
#include "../GraphicalElements/MultiFrameAnimation.h"

namespace Entities {
    
    class MovingEntity : public Entity {
    protected:
        Math::CoordF velocity;
        bool active;

        GraphicalElements::MultiFrameAnimation sprite;

    public:
        MovingEntity(Math::CoordF position = Math::CoordF(0.f, 0.f), Math::CoordF size = Math::CoordF(0.f, 0.f), ID id = empty);

        ~MovingEntity();

        virtual void render();

        virtual void update(const float dt) = 0;

        virtual void initialize() = 0;

        virtual void collide(Entity* otherEntity, Math::CoordF intersect) = 0;

        virtual void updateSprite(const float dt) = 0;

        const bool isFacingLeft() const;
        
        const bool isActive() const;
        
        Math::CoordF getVelocity() const;

        void setVelocity(Math::CoordF velo);

    };

} // namespace Entities
