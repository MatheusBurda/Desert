#pragma once

#include "../Managers/Graphics.h"
#include "../Math/CoordTL.h"
#include <SFML/Graphics.hpp>

namespace GraphicalElements {

    class Animation {
    private:
        Managers::Graphics* pGraphicM;
        Math::CoordU imageCount;
        sf::Texture* texture;
        Math::CoordU currentImage;
        sf::RectangleShape body;
        sf::IntRect uvRect;
        float totalTime;
        static const float switchTime;

    public:
        Animation();
        ~Animation();

        void initializeTexture(const char* path, Math::CoordU imageCount);
        void Update(int row, float dt, bool facingLeft, sf::Vector2f position);
        void render();
    };
    
}