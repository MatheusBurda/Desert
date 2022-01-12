#pragma once

#include "Managers/Graphics.h"
#include "Math/CoordTL.h"

#include <SFML/Graphics.hpp>
#include <string>

#define FONT_PATH "./assets/Fonts/MainFont.ttf"

namespace GraphicalElements {

    enum TextAlignment {
        left,
        center,
        right
    };

    class Text {
    private:
        std::string info;

        sf::Text text;

        static Managers::Graphics* pGraphicM;

    public:
        Text(Math::CoordF position = Math::CoordF(0, 0), std::string info = "", const char* path = FONT_PATH);

        ~Text();

        void setTextInfo(std::string info);

        void setPosition(Math::CoordF position);

        void setTextColor(const unsigned int R, const unsigned int G, const unsigned int B);

        void setFontSize(const unsigned int size);

        void setTextAlignment(TextAlignment option);

        Math::CoordF getSize() const;

        void render();

        std::string getInfo() const;

        Math::CoordF getPosition() const;
    };

} // namespace GraphicalElements
