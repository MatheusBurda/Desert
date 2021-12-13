#include "GraphicalElements/SingleFrameAnimation.h"

#include "Managers/Graphics.h"

namespace GraphicalElements {

    SingleFrameAnimation::SingleFrameAnimation(const char* path, Math::CoordF position, Math::CoordF size, float scale) :
    texture(NULL) {
        texture = pGraphicM->loadTexture(path);

        body.setSize(sf::Vector2f(size.x, size.y));
        body.setPosition(sf::Vector2f(position.x, position.y));
        body.setScale(sf::Vector2f(scale, scale));

        body.setTexture(texture);
    }

    SingleFrameAnimation::~SingleFrameAnimation() { }

    void SingleFrameAnimation::update(Math::CoordF position) {
        body.setPosition(sf::Vector2f(position.x, position.y));
    }

} // namespace GraphicalElements
