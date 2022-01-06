#pragma once

#include "Ent.h"
#include "GraphicalElements/Text.h"
#include "GraphicalElements/Heart.h"

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

    public:
        Hud(Entities::Characters::Player* pPlayer = nullptr);

        ~Hud();

        void render();

        void update(const float dt);

        void initialize();

        void updatePlayerPoints();

        void updateHearts();
    };

} // namespace GraphicalElements
