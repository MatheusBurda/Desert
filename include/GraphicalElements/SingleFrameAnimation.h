#pragma once

#include "Math/CoordTL.h"
#include <SFML/Graphics.hpp>

namespace GraphicalElements {

    class SingleFrameAnimation {
    private:
        sf::Texture* texture;
        sf::RectangleShape body;

    public:
        SingleFrameAnimation(const char* path, Math::CoordF position, Math::CoordF size, float scale);
        ~SingleFrameAnimation();

        void update(Math::CoordF position);
        void render();
    };

} // namespace GraphicalElements
