#pragma once

#include "Entity.h"
#include "../GraphicalElements/SingleFrameAnimation.h"

namespace Entities {
    class StaticEntity : public Entity {
    private:
        GraphicalElements::SingleFrameAnimation sprite;

    public:
        StaticEntity();
        ~StaticEntity();

        void update(float dt) = 0;
        void initialize() = 0;
    };

} // namespace Entities
