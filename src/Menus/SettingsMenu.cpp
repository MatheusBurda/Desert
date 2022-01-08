#include "Menus/SettingsMenu.h"

#define BACKGROUND_MAIN_MENU "./assets/Backgrounds/MainMenuBackground.png"

#include "Managers/Graphics.h"
#include "States/Game.h"

namespace Menus {

    SettingsMenu::SettingsMenu(States::Game* pG) :
    Menu(),
    State(static_cast<States::StateMachine*>(pG), States::stateID::settings),
    pGame(pG) {
        Managers::Graphics* GM = Managers::Graphics::getInstance();
        GraphicalElements::Button* bt = NULL;

        bt = new GraphicalElements::Button(Math::CoordF(GM->getWindowSize().x / 2.0f, GM->getWindowSize().y / 2), "800x600");
        bt->select(true);
        vectorOfButtons.push_back(bt);

        bt = new GraphicalElements::Button(Math::CoordF(GM->getWindowSize().x / 2.0f, GM->getWindowSize().y / 2 + 100), "1280x720");
        vectorOfButtons.push_back(bt);

        bt = new GraphicalElements::Button(Math::CoordF(GM->getWindowSize().x / 2.0f, GM->getWindowSize().y / 2 + 200), "toggle sound on/off");
        vectorOfButtons.push_back(bt);

        bt = new GraphicalElements::Button(Math::CoordF(GM->getWindowSize().x / 2.0f, GM->getWindowSize().y / 2 + 300), "return");
        vectorOfButtons.push_back(bt);

        max = 3;
    }

    SettingsMenu::~SettingsMenu() {
    }

    void SettingsMenu::update(float dt) {
        active = true;
    }

    /* Menu operation to render all it's objects. */
    void SettingsMenu::render() {
        updateView();
        // back.render();
        for (it = vectorOfButtons.begin(); it != vectorOfButtons.end(); ++it)
            (*it)->render();
    }

    void SettingsMenu::exec() {
        if (active) {
            active = false;
            switch (selected) {
            case 0:
                Managers::Graphics::getInstance()->setWindowSize(Math::CoordU(800, 600));
                break;
            case 1:
                Managers::Graphics::getInstance()->setWindowSize(Math::CoordU(1280, 720));
                break;
            case 2:
                /* Sound ON/OFF */
                break;
            case 3:
                changeState(pSM->getLastStateID());
                break;
            default:
                break;
            }
        }
    }

    void SettingsMenu::resetState() {
        vectorOfButtons[selected]->select(false);
        selected = 0;
        vectorOfButtons[selected]->select(true);
    }

}