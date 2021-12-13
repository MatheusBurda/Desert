#pragma once

#include "../Math/CoordTL.h"
#include "../Managers/Graphics.h"
#include <SFML/Graphics.hpp>

namespace GraphicalElements {

    class Animation {
    protected:
        sf::RectangleShape body;
        static Managers::Graphics* pGraphicM;

    public:
        Animation();
        ~Animation();

        void render();
    };

} // namespace GraphicalElements
