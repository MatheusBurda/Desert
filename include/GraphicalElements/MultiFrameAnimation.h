#pragma once

#include "GraphicalElements/Animation.h"
#include <map>

namespace GraphicalElements {

    enum Animation_ID {
        walk = 0,
        idle = 1,
        attack = 2
    };

    class MultiFrameAnimation : public Animation {
    private:
        class SingleAnimation {
        private:
            friend class MultiFrameAnimation;

            const unsigned int imageCount;
            unsigned int currentImage;
            sf::Texture* texture;
            float totalTime;
            sf::IntRect rectSize;
            static const float switchTime;

        public:
            SingleAnimation(const char* path, const unsigned int imageCount) :
            imageCount(imageCount),
            currentImage(0),
            texture(pGraphicM->loadTexture(path)),
            totalTime(0.0f),
            rectSize() {
                if (texture == NULL) {
                    std::cout << "ERROR: loading texture failed on SingleAnimation::SingleAnimation()." << std::endl;
                    exit(1);
                }

                rectSize.width = texture->getSize().x / float(imageCount);
                rectSize.height = texture->getSize().y;
            }
            
            ~SingleAnimation() { }

            void update(const float dt, bool facingLeft) {
                /* Based on this tutorial --> https://www.youtube.com/watch?v=Aa8bXSq5LDE&t=196s */
                totalTime += dt;

                if (totalTime >= switchTime) {
                    totalTime -= switchTime;
                    currentImage++;

                    if (currentImage >= imageCount) {
                        currentImage = 0;
                    }
                }

                if (!facingLeft) {
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
        std::map<Animation_ID, SingleAnimation*> animationMap;
        Animation_ID currentID;

    public:
        MultiFrameAnimation();
        ~MultiFrameAnimation();

        void addNewAnimation(Animation_ID id, const char* path, unsigned int imageCount);
        void update(Animation_ID id, bool facingLeft, Math::CoordF position, const float dt);
    };

} // namespace Managers
