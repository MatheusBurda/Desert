#include "GraphicalElements/CoinAnimation.h"

#define COIN_PATH "./assets/Loot/Coin.png"
#define COIN_IMAGE_COUNT 8

namespace GraphicalElements {

    CoinAnimation::CoinAnimation() :
    Animation(),
    texture(COIN_PATH, COIN_IMAGE_COUNT, 0.2f) {
        body.setSize(sf::Vector2f(30, 30));
    }

    CoinAnimation::~CoinAnimation() { }

    void CoinAnimation::update(Math::CoordF position, const float dt) {
        texture.update(dt, true);
        body.setPosition(sf::Vector2f(position.x, position.y));
        body.setTextureRect(texture.getSize());
        body.setTexture(texture.getTexture());
    }

} // namespace GraphicalElements