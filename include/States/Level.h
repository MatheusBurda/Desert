#pragma once

#include "States/State.h"

#include "Entities/Characters/Player.h"
#include "GraphicalElements/Hud.h"
#include "GraphicalElements/SingleFrameAnimation.h"
#include "List/EntityList.h"
#include "Managers/Collision.h"
#include "Managers/Graphics.h"
#include "Math/CoordTL.h"
#include "States/StateMachine.h"
#include "WorldGenerator/WorldGenerator.h"

namespace States {

    class Level : public State {
    private:
        Entities::Characters::Player* player;
        GraphicalElements::SingleFrameAnimation background;
        List::EntityList staticEntitiesList;
        List::EntityList movingEntitiesList;
        Managers::Collision collisionManager;
        GraphicalElements::Hud hud;
        Managers::Graphics* pGraphicM;
        bool levelEnded;
        int playerPoints;
        WorldGenerator::WorldGenerator worldGen;
        Math::CoordF nextPositionToRender;

    public:
        Level(StateMachine* pSM = nullptr);

        ~Level();

        void update(const float dt);

        void render();

        void resetState();

        void endLevel();

        int getPlayerPoints() const;

        void coinBomb(Math::CoordF position);
    };

} // namespace States
