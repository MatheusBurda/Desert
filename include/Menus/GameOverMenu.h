#pragma once

#include "Control/TextInput.h"
#include "GraphicalElements/Text.h"
#include "Menus/Menu.h"
#include "States/State.h"
#include "States/StateMachine.h"
#include "States/Level.h"

namespace Menus {

    class GameOverMenu : public Menu, public States::State {
    private:
        GraphicalElements::Text title;
        GraphicalElements::Text points;
        GraphicalElements::Text name;
        GraphicalElements::Text nameLabel;
        Control::TextInput input;
        unsigned int pointsToIncrement;
        States::Level* plvl;

    public:
        GameOverMenu(States::StateMachine* pSM = nullptr, States::Level* plvl = nullptr);

        ~GameOverMenu();

        void update(float dt);

        void render();

        void exec();

        void resetState();

        void writeToLeaderboardFile();
    };

}
