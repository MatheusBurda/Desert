#pragma once

#include "GraphicalElements/Animation.h"

namespace GraphicalElements {

    class SingleFrameAnimation : public Animation {
    private:
        sf::Texture* texture;

    public:
        SingleFrameAnimation();

        virtual ~SingleFrameAnimation();

        void initialize(const char* path, Math::CoordF position, Math::CoordF size);

        void update(Math::CoordF position);
    };

} // namespace GraphicalElements
