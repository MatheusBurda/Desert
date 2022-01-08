#pragma once

#include "Menus/Menu.h"
#include "States/State.h"
#include "States/StateMachine.h"

namespace Menus {

    class PauseMenuState : public Menu, public States::State {
    private:

    public:
        PauseMenuState(States::StateMachine* pSM = NULL);

        ~PauseMenuState();

        void update(float dt);

        void render();

        void exec();

        void resetState();

        void TriggerPauseMenu();
    };

}
