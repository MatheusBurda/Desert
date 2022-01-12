#include "Menus/SettingsMenu.h"

#define SETTINGS_FILE "./saves/Settings.txt"

#include "Managers/Graphics.h"
#include "States/Game.h"
#include <fstream>

namespace Menus {

    SettingsMenu::SettingsMenu(States::Game* pG) :
    Menu(),
    State(static_cast<States::StateMachine*>(pG), States::stateID::settings),
    pGame(pG) {
        Managers::Graphics* GM = Managers::Graphics::getInstance();
        GraphicalElements::Button* bt = NULL;

        bt = new GraphicalElements::Button(Math::CoordF(GM->getWindowSize().x / 2.0f, GM->getWindowSize().y / 2), "Render distance 30");
        bt->select(true);
        vectorOfButtons.push_back(bt);

        bt = new GraphicalElements::Button(Math::CoordF(GM->getWindowSize().x / 2.0f, GM->getWindowSize().y / 2 + 100), "Render distance 50");
        vectorOfButtons.push_back(bt);

        bt = new GraphicalElements::Button(Math::CoordF(GM->getWindowSize().x / 2.0f, GM->getWindowSize().y / 2 + 300), "return");
        vectorOfButtons.push_back(bt);

        max = 2;

        renderDistance = 30;
    }

    SettingsMenu::~SettingsMenu() { }

    void SettingsMenu::update(float dt) {
        active = true;
    }

    /* Menu operation to render all it's objects. */
    void SettingsMenu::render() {
        updateView();
        back.render();
        for (it = vectorOfButtons.begin(); it != vectorOfButtons.end(); ++it)
            (*it)->render();
    }

    void SettingsMenu::exec() {
        if (active) {
            active = false;
            switch (selected) {
            case 0:
                renderDistance = 30;
                break;
            case 1:
                renderDistance = 50;
                break;
            case 2:
                changeState(pSM->getLastStateID());
                break;
            default:
                break;
            }
            saveSettings();
            resetState();
        }
    }

    void SettingsMenu::resetState() {
        vectorOfButtons[selected]->select(false);
        selected = 2;
        vectorOfButtons[selected]->select(true);
    }

    void SettingsMenu::saveSettings() {
        std::ofstream writeFile;

        writeFile.open(SETTINGS_FILE, std::ios::out | std::ios::trunc);

        if (!writeFile) {
            std::cout << "ERROR writing to file on GameOverMenu" << std::endl;
            exit(1);
        }

        writeFile << renderDistance;

        writeFile.close();
    }

}