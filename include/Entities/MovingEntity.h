#pragma once

#include "Entity.h"
#include "../GraphicalElements/SingleFrameAnimation.h"

namespace Entities {
    
    class MovingEntity : public Entity {
    private:
        Math::CoordF velocity;
        bool facingLeft;
        bool active;

    public:
        MovingEntity(Math::CoordF position = Math::CoordF(0.f, 0.f), Math::CoordF size = Math::CoordF(0.f, 0.f), ID id = empty);

        ~MovingEntity();

        virtual void update(float dt) = 0;

        virtual void initialize() = 0;

        const bool isFacingLeft() const;
        
        const bool isActive() const;
        
        Math::CoordF getVelocity() const;

        void setVelocity(Math::CoordF velo);

    };

} // namespace Entities
