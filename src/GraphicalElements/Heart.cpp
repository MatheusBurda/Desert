#include "GraphicalElements/Heart.h"

#define PATH_FULL "./assets/etc/HeartFULL.png"
#define PATH_HALF "./assets/etc/HeartHALF.png"
#define PATH_EMPTY "./assets/etc/HeartEMPTY.png"

namespace GraphicalElements {

    Heart::Heart() {
        empty = pGraphicM->loadTexture(PATH_EMPTY);
        half = pGraphicM->loadTexture(PATH_HALF);
        full = pGraphicM->loadTexture(PATH_FULL);

        body.setTexture(full);

        body.setOrigin(0,0);

        body.setSize(sf::Vector2f(HEART_SIZE_X, HEART_SIZE_Y));
    }

    Heart::~Heart() { }

    void Heart::update(HeartID id, Math::CoordF position) {
        switch (id) {
        case HeartID::empty:
            body.setTexture(empty);
            break;
        case HeartID::half:
            body.setTexture(half);
            break;

        case HeartID::full:
            body.setTexture(full);
            break;
        }

        body.setPosition(sf::Vector2f(position.x, position.y));
    }

} // namespace GraphicalElements
