#pragma once

#include "Ent.h"
#include "GraphicalElements/Text.h"

namespace Entities::Characters {
    class Player;
} // namespace Entities::Characters

namespace GraphicalElements {

    class Hud : public Ent {
    private:
        Entities::Characters::Player* pPlayer;
        Text points;
        
    public:
        Hud(Entities::Characters::Player* pPlayer = nullptr);

        ~Hud();

        void render();

        void update(const float dt);

        void initialize();

        void updatePlayerPoints();

        void centerHud(Math::CoordF position);
        
    };

} // namespace GraphicalElements
