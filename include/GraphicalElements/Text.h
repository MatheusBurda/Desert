#pragma once

#include "Math/CoordTL.h"
#include "Managers/Graphics.h"

#include <SFML/Graphics.hpp>
#include <string>

namespace GraphicalElements {

    class Text {
    private:
        std::string info;
        sf::Text text;

        static Managers::Graphics* pGraphicM;

    public:
        Text(Math::CoordF position = Math::CoordF(0, 0), std::string info = "");

        ~Text();

        void setTextInfo(std::string info);

        void setPosition(Math::CoordF position);

        void setTextColor(const unsigned int R, const unsigned int G, const unsigned int B);

        void setFontSize(const unsigned int size);

        Math::CoordF getSize() const;

        void render();

        std::string getInfo() const;
    
    };

} // namespace GraphicalElements
