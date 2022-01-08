#pragma once

#include "Entities/Characters/Player.h"
#include "Managers/Events.h"
#include "Managers/Graphics.h"
#include "States/StateMachine.h"

#define TICK_RATE 0.0078125

namespace States {

    class Game : public StateMachine {
    private:
        Managers::Graphics* pGraphicManager;
        Managers::Events* pEventManager;
        Entities::Characters::Player* p1;

        sf::Clock clock;
        float dt;

    public:
        Game();

        ~Game();

        void exec();

        void endGame();
    };

} // namespace States