#pragma once

#include "GraphicalElements/Animation.h"
#include "GraphicalElements/SingleAnimation.h"

namespace GraphicalElements {

    class CoinAnimation : public Animation {
    private:
        SingleAnimation texture;

    public:
        CoinAnimation();

        ~CoinAnimation();

        void update(Math::CoordF position, const float dt);
    };

} // namespace GraphicalElements
