#include "GraphicalElements/SingleFrameAnimation.h"

#include "Managers/Graphics.h"

namespace GraphicalElements {

    SingleFrameAnimation::SingleFrameAnimation() :
    texture(nullptr) { }

    SingleFrameAnimation::~SingleFrameAnimation() { }

    void SingleFrameAnimation::initialize(const char* path, Math::CoordF position, Math::CoordF size) {
        texture = pGraphicM->loadTexture(path);

        body.setSize(sf::Vector2f(size.x, size.y));
        body.setPosition(sf::Vector2f(position.x, position.y));
        body.setOrigin(sf::Vector2f(size.x/2, size.y/2));
        body.setTexture(texture);
    }

    void SingleFrameAnimation::update(Math::CoordF position) {
        body.setPosition(sf::Vector2f(position.x, position.y));
    }

} // namespace GraphicalElements
