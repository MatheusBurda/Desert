#pragma once

#include "Ent.h"
#include "GraphicalElements/Text.h"
#include "GraphicalElements/Heart.h"
#include "GraphicalElements/CoinAnimation.h"

namespace Entities::Characters {
    class Player;
} // namespace Entities::Characters

namespace GraphicalElements {

    class Hud : public Ent {
    private:
        Entities::Characters::Player* pPlayer;
        Text points;
        Math::CoordU windowSize;
        Managers::Graphics* pGraphicM;
        Heart* allHeart;
        CoinAnimation coin;
        Text coinsText;

    public:
        Hud(Entities::Characters::Player* pPlayer = nullptr);

        ~Hud();

        void render();

        void update(const float dt);

        void initialize();

        void updatePlayerPoints();

        void updateHearts();

        void updateCoins(const float dt);

        void setPlayer(Entities::Characters::Player* pPlayer);
    };

} // namespace GraphicalElements
