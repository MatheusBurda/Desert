#include "Menus/MainMenu.h"

#include "States/Game.h"

namespace Menus {

    MainMenuState::MainMenuState(States::Game* pG) :
    Menu(),
    State(static_cast<States::StateMachine*>(pG), States::stateID::mainMenu),
    pGame(pG),
    title() {
        Managers::Graphics* GM = Managers::Graphics::getInstance();
        GraphicalElements::Button* bt = NULL;

        bt = new GraphicalElements::Button(Math::CoordF(GM->getWindowSize().x / 2.0f, GM->getWindowSize().y / 2), "PLAY GAME");
        bt->select(true);
        vectorOfButtons.push_back(bt);

        bt = new GraphicalElements::Button(Math::CoordF(GM->getWindowSize().x / 2.0f, GM->getWindowSize().y / 2 + 100), "LEADERBOARD");
        vectorOfButtons.push_back(bt);

        bt = new GraphicalElements::Button(Math::CoordF(GM->getWindowSize().x / 2.0f, GM->getWindowSize().y / 2 + 200), "SETTINGS");
        vectorOfButtons.push_back(bt);

        bt = new GraphicalElements::Button(Math::CoordF(GM->getWindowSize().x / 2.0f, GM->getWindowSize().y / 2 + 300), "EXIT GAME");
        vectorOfButtons.push_back(bt);

        title.setTextInfo("DESERT");
        title.setFontSize(140);
        title.setTextColor(77.6, 68.2, 44.3);
        title.setTextAlignment(GraphicalElements::TextAlignment::center);

        title.setPosition(Math::CoordF(GM->getWindowSize().x / 2.0f, 0.0f - title.getSize().y / 2));

        max = 3;
    }

    MainMenuState::~MainMenuState() {
    }

    void MainMenuState::update(float dt) {
        active = true;
        if (title.getPosition().y < 200)
            title.setPosition(Math::CoordF(title.getPosition().x, title.getPosition().y + 1));
    }

    /* Menu operation to render all it's objects. */
    void MainMenuState::render() {
        updateView();
        back.render();
        for (it = vectorOfButtons.begin(); it != vectorOfButtons.end(); ++it)
            (*it)->render();
        title.render();
    }

    void MainMenuState::exec() {
        if (active) {
            active = false;
            switch (selected) {
            case 0:
                changeState(States::stateID::playing);
                break;
            case 1:
                changeState(States::stateID::leaderboard);
                break;
            case 2:
                changeState(States::stateID::settings);
                break;
            case 3:
                pGame->endGame();
                break;
            default:
                break;
            }
        }
    }

    void MainMenuState::resetState() {
        vectorOfButtons[selected]->select(false);
        selected = 0;
        vectorOfButtons[selected]->select(true);
        title.setPosition(Math::CoordF(title.getPosition().x, 0.0f - title.getSize().y / 2));
    }

}