#include "States/Game.h"

#include "Menus/GameOverMenu.h"
#include "Menus/LeaderboardMenu.h"
#include "Menus/MainMenu.h"
#include "Menus/PauseMenu.h"
#include "Menus/SettingsMenu.h"
#include "States/Level.h"

namespace States {

    Game::Game() :
    pGraphicManager(Managers::Graphics::getInstance()),
    pEventManager(Managers::Events::getInstance()) {
        clock.restart();
        dt = 0;

        State* states = new States::Level(this);
        insertState(states);

        states = static_cast<State*>(new Menus::PauseMenuState(this, dynamic_cast<States::Level*>(mapOfStates[stateID::playing])));
        insertState(states);

        states = static_cast<State*>(new Menus::MainMenuState(this));
        insertState(states);

        states = static_cast<State*>(new Menus::SettingsMenu(this));
        insertState(states);

        states = static_cast<State*>(new Menus::LeaderboardMenu(this));
        insertState(states);

        states = static_cast<State*>(new Menus::GameOverMenu(this, dynamic_cast<States::Level*>(mapOfStates[stateID::playing])));
        insertState(states);

        changeCurrentState(stateID::mainMenu);

        exec();
    }

    Game::~Game() {
    }

    void Game::exec() {
        while (pGraphicManager->isWindowOpen()) {

            pEventManager->pollEvents();

            pGraphicManager->clear();

            if (dt < TICK_RATE) {
                dt += clock.getElapsedTime().asSeconds();
                clock.restart();
            } //
            else {
                updateCurrentState(0.01);
                dt -= TICK_RATE;
            }

            renderCurrentState();

            pGraphicManager->display();
        }
    }

    void Game::endGame() {
        pGraphicManager->closeWindow();
    }

}