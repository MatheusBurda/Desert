#pragma once

#include "../Managers/Graphics.h"
#include "../Math/CoordTL.h"
#include <SFML/Graphics.hpp>

namespace GraphicalElements {

    class Animation {
    protected:
        sf::RectangleShape body;

        static Managers::Graphics* pGraphicM;

    public:
        Animation();

        virtual ~Animation();

        void render();
    };

} // namespace GraphicalElements
