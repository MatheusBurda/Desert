#include "Menus/PauseMenu.h"

#define BACKGROUND_PATH "./assets/Backgrounds/MenuBackground.png"

namespace Menus {

    PauseMenuState::PauseMenuState(States::StateMachine* pSM, States::Level* plvl) :
    Menu(),
    State(pSM, States::stateID::pauseMenu),
    plvl(plvl) {
        Managers::Graphics* GM = Managers::Graphics::getInstance();

        GraphicalElements::Button* bt = NULL;

        bt = new GraphicalElements::Button(Math::CoordF(GM->getWindowSize().x / 2.0f, GM->getWindowSize().y / 2 - 100), "RESUME GAME");
        bt->select(true);
        vectorOfButtons.push_back(bt);

        bt = new GraphicalElements::Button(Math::CoordF(GM->getWindowSize().x / 2.0f, GM->getWindowSize().y / 2), "SETTINGS");
        vectorOfButtons.push_back(bt);

        bt = new GraphicalElements::Button(Math::CoordF(GM->getWindowSize().x / 2.0f, GM->getWindowSize().y / 2 + 100), "Quit to Main MENU");
        vectorOfButtons.push_back(bt);

        selected = 0;
    }

    PauseMenuState::~PauseMenuState() { }

    void PauseMenuState::update(float dt) { }

    /* Menu operation to render all it's objects. */
    void PauseMenuState::render() {
        updateView();
        // back.render();
        for (it = vectorOfButtons.begin(); it != vectorOfButtons.end(); ++it)
            (*it)->render();
    }

    void PauseMenuState::exec() {
        if (active) {
            active = false;
            switch (selected) {
            case 0:
                changeState(States::stateID::playing);
                break;
            case 1:
                changeState(States::stateID::settings);
                break;
            case 2:
                changeState(States::stateID::mainMenu);
                plvl->endLevel();
                break;
            default:
                break;
            }
        }
    }

    void PauseMenuState::resetState() {
        for (it = vectorOfButtons.begin(); it != vectorOfButtons.end(); ++it)
            (*it)->select(false);
        selected = 0;
        vectorOfButtons[selected]->select(true);
        active = true;
    }

    /* Trigger open the pause menu */
    void PauseMenuState::TriggerPauseMenu() {
        if (pSM->getCurrentStateID() == States::stateID::playing) {
            changeState(States::stateID::pauseMenu);
        }
    }

}