#include "States/Game.h"

#include "Menus/MainMenu.h"
#include "Menus/PauseMenu.h"
#include "Menus/SettingsMenu.h"
#include "States/Level.h"

namespace States {

    Game::Game() :
    pGraphicManager(Managers::Graphics::getInstance()),
    pEventManager(Managers::Events::getInstance()),
    p1(new Entities::Characters::Player(Math::CoordF(200.f, 400.f))) {
        clock.restart();
        dt = 0;

        State* states = new States::Level(this, p1);
        insertState(states);

        states = static_cast<State*>(new Menus::MainMenuState(this));
        insertState(states);

        states = static_cast<State*>(new Menus::PauseMenuState(this));
        insertState(states);

        states = static_cast<State*>(new Menus::SettingsMenu(this));
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