#pragma once

#include "Menus/Menu.h"
#include "States/State.h"
#include "GraphicalElements/Text.h"
#include <vector>

namespace Menus {

    class LeaderboardMenu : public Menu, public States::State {
    private:
        std::vector<GraphicalElements::Text*> allPoints;
        std::vector<GraphicalElements::Text*>::iterator itr;

    public:
        LeaderboardMenu(States::StateMachine* pSM = nullptr);

        ~LeaderboardMenu();

        void update(const float dt);

        void render();

        void resetState();

        void exec();

        void buildLeaderboard();

    };

}
