#pragma once

#include "GraphicalElements/Text.h"
#include "GraphicalElements/Animation.h"

namespace GraphicalElements {

    class Button : public Animation {
    private:
        Text textInfo;
        sf::Texture* defaultTexture;
        sf::Texture* selectedTexture;

    public:
        Button(Math::CoordF position = Math::CoordF(0, 0), std::string info = "");

        ~Button();

        void select(const bool isSelected);

        void render();
    };

} // namespace GraphicalElements
