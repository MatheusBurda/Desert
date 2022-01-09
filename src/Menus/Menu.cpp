#include "Menus/Menu.h"

#include "Managers/Graphics.h"

namespace Menus {

    Menu::Menu() :
    selected(0),
    min(0),
    max(2),
    control(this),
    /*back(sf::Vector2f(0, 0), backPath), */
    active(false) {
        /*  GraphicManager* GM = GraphicManager::getInstance();
         back.changePos(sf::Vector2f(GM->getWindowSize().x / 2.0f, GM->getWindowSize().y / 2)); */
    }

    Menu::~Menu() {
        GraphicalElements::Button* bt = NULL;
        while (vectorOfButtons.size() != 0) {
            bt = vectorOfButtons.back();
            delete (bt);
            vectorOfButtons.pop_back();
        }
        vectorOfButtons.clear();
    }

    void Menu::updateView() {
        Managers::Graphics::getInstance()->centerView(Math::CoordF(Managers::Graphics::getInstance()->getWindowSize().x/2, Managers::Graphics::getInstance()->getWindowSize().y/2));
    }

    /* Make the menu selection go Down */
    void Menu::selectDown() {
        if (active) {
            vectorOfButtons[selected]->select(false);
            selected++;
            if (selected > max)
                selected = min;
            vectorOfButtons[selected]->select(true);
        }
    }

    /* Make the menu selection go Up */
    void Menu::selectUp() {
        if (active) {
            vectorOfButtons[selected]->select(false);
            selected--;
            if (selected < min)
                selected = max;
            vectorOfButtons[selected]->select(true);
        }
    }

} // namespace Menus
