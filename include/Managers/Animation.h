#pragma once

#include "../Math/CoordTL.h"
#include "Graphics.h"
#include <SFML/Graphics.hpp>
#include <map>

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
            const unsigned int imageCount;
            unsigned int currentImage;
            sf::Texture* texture;
            float totalTime;
            sf::IntRect rectSize;
            static const float switchTime;

        public:
            Animation(const char* path, const unsigned int imageCount) :
            imageCount(imageCount),
            currentImage(0),
            texture(pGraphicM->loadTexture(path)),
            totalTime(0.0f),
            rectSize() {
                if (texture == NULL) {
                    std::cout << "ERROR: loading texture failed on Animation::Animation()." << std::endl;
                    exit(1);
                }

                rectSize.width = texture->getSize().x / float(imageCount);
                rectSize.height = texture->getSize().y;
            }
            ~Animation() { }

            void update(float dt, bool facingLeft) {
                /* Based on this tutorial --> https://www.youtube.com/watch?v=Aa8bXSq5LDE&t=196s */
                totalTime += dt;

                if (totalTime >= switchTime) {
                    totalTime -= switchTime;
                    currentImage++;

                    if (currentImage >= imageCount) {
                        currentImage = 0;
                    }
                }

                if (facingLeft) {
                    rectSize.left = (currentImage + 1) * abs(rectSize.width);
                    rectSize.width = -abs(rectSize.width);
                } //
                else {
                    rectSize.left = currentImage * rectSize.width;
                    rectSize.width = abs(rectSize.width);
                }
            }

            void reset() {
                currentImage = 0;
                totalTime = 0;
            }
            sf::IntRect getSize() const { return rectSize; }
            sf::Texture* getTexture() const { return texture; }
        };

    private:
        sf::RectangleShape body;
        std::map<Animation_ID, Animation*> animationMap;
        Animation_ID currentID;

        static Managers::Graphics* pGraphicM;

    public:
        AnimationManager();
        ~AnimationManager();

        void addNewAnimation(Animation_ID id, const char* path, unsigned int imageCount);
        void update(Animation_ID id, bool facingLeft, Math::CoordF position, float dt);
        void render();
    };

} // namespace Managers
