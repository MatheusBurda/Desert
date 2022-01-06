#pragma once

#include "GraphicalElements/Animation.h"

#define HEART_SIZE_X 25
#define HEART_SIZE_Y 21.5

namespace GraphicalElements {

    enum HeartID {
        empty = 0,
        half,
        full
    };

    class Heart : public Animation {
    private:
        sf::Texture* empty;
        sf::Texture* half;
        sf::Texture* full;

    public:
        Heart();
        ~Heart();

        void update(HeartID id, Math::CoordF position);
    };

} // namespace GraphicalElements
