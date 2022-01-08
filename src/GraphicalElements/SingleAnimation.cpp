#include "GraphicalElements/SingleAnimation.h"

namespace GraphicalElements {

    SingleAnimation::SingleAnimation(const char* path, const unsigned int imageCount, const float switchTime) :
    imageCount(imageCount),
    currentImage(0),
    texture(Managers::Graphics::getInstance()->loadTexture(path)),
    totalTime(0.0f),
    rectSize(),
    switchTime(switchTime) {
        if (texture == nullptr) {
            std::cout << "ERROR: loading texture failed on SingleAnimation::SingleAnimation()." << std::endl;
            exit(1);
        }

        rectSize.width = texture->getSize().x / float(imageCount);
        rectSize.height = texture->getSize().y;
    }

    SingleAnimation::~SingleAnimation() { }

    void SingleAnimation::update(const float dt, bool facingLeft) {
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

    void SingleAnimation::reset() {
        currentImage = 0;
        totalTime = 0;
    }

    sf::IntRect SingleAnimation::getSize() const {
        return rectSize;
    }

    sf::Texture* SingleAnimation::getTexture() const {
        return texture;
    }

} // namespace GraphicalElements
