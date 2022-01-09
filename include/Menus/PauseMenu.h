#pragma once

#include "Menus/Menu.h"
#include "States/Level.h"
#include "States/State.h"
#include "States/StateMachine.h"

namespace Menus {

    class PauseMenuState : public Menu, public States::State {
    private:
        States::Level* plvl;

    public:
        PauseMenuState(States::StateMachine* pSM = nullptr, States::Level* plvl = nullptr);

        ~PauseMenuState();

        void update(float dt);

        void render();

        void exec();

        void resetState();

        void TriggerPauseMenu();
    };

}
