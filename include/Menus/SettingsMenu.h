#pragma once

#include "Menus/Menu.h"
#include "States/State.h"

namespace States {
    class Game;
}

namespace Menus {

    class SettingsMenu : public Menu, public States::State {
    private:
        States::Game* pGame;
        unsigned int renderDistance;

    public:
        SettingsMenu(States::Game* pG = nullptr);
        
        ~SettingsMenu();

        void update(const float dt);

        void render();

        void resetState();

        void exec();

        void saveSettings();
    };

}
