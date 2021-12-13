#pragma once

#include "GraphicalElements/Animation.h"

namespace GraphicalElements {

    class SingleFrameAnimation : public Animation {
    private:
        sf::Texture* texture;

    public:
        SingleFrameAnimation(const char* path, Math::CoordF position, Math::CoordF size, float scale);
        ~SingleFrameAnimation();

        void update(Math::CoordF position);
    };

} // namespace GraphicalElements
