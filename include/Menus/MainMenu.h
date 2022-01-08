#pragma once

#include "Menus/Menu.h"
#include "States/State.h"

namespace States {
    class Game;
}

namespace Menus {

    class MainMenuState : public Menu, public States::State {
    private:
        States::Game* pGame;

    public:
        MainMenuState(States::Game* pG = NULL);

        ~MainMenuState();

        void update(const float dt);

        void render();
        
        void resetState();

        void exec();
    };

}
