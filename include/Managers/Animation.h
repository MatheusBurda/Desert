#pragma once

#include "../Math/CoordTL.h"
#include "Graphics.h"
#include <SFML/Graphics.hpp>

namespace Managers {

    enum Animation_ID {
        walk = 0,
        idle = 1,
        attack = 2
    };

    class AnimationManager {
    private:

        class Animation {
        private:
            unsigned int imageCount;
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

    private:
        static Managers::Graphics* pGraphicM;

    public:
        AnimationManager();
        ~AnimationManager();

        void addNewAnimation(Animation_ID id, const char* path, unsigned int imageCount);
        void update(Animation_ID id, bool facingLeft, Math::CoordF position);
        void render();
    };

    AnimationManager::AnimationManager() {
    }

    AnimationManager::~AnimationManager() {
    }

} // namespace Managers
