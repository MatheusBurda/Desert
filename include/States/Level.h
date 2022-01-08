#pragma once

#include "States/State.h"

#include "Entities/Characters/Player.h"
#include "Managers/Graphics.h"
#include "States/StateMachine.h"
#include "GraphicalElements/Hud.h"
#include "List/EntityList.h"
#include "Managers/Collision.h"

/* ============== REMOVER ============== */
#include "Entities/Characters/Enemies/Hyena.h"
#include "Entities/Characters/Enemies/Snake.h"
#include "Entities/Obstacles/Platform.h"
/* ===================================== */

namespace States {

    class Level : public State {
    private:
        Entities::Characters::Player* player;
        // GraphicalElements::SingleFrameAnimation background;
        List::EntityList staticEntitiesList;
        List::EntityList movingEntitiesList;
        Managers::Collision collisionManager;
        GraphicalElements::Hud hud;

    public:
        Level(StateMachine* pSM = nullptr, Entities::Characters::Player* p1 = nullptr);

        ~Level();

        void update(const float dt);

        void render();

        void resetState();
    };

} // namespace States
