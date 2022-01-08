#include "Control/MenuControl.h"

#include "Menus/Menu.h"
#include "Menus/PauseMenu.h"

namespace Control {

    MenuControl::MenuControl(Menus::Menu* pM) :
    Observer() {
        pMenu = pM;
    }

    MenuControl::~MenuControl() {
        pMenu = NULL;
    }

    void MenuControl::notifyPressed(std::string key) {
        if (pMenu == NULL) {
            std::cout << "ERROR pointer to Menu NULL on MenuControl::notify()." << std::endl;
            exit(1);
        }

        if (key == "Down")
            pMenu->selectDown();
        if (key == "Up")
            pMenu->selectUp();
        if (key == "Enter")
            pMenu->exec();
        if (key == "Escape")
            if (dynamic_cast<Menus::PauseMenuState*>(pMenu) != nullptr)
                dynamic_cast<Menus::PauseMenuState*>(pMenu)->TriggerPauseMenu();
    }

    void MenuControl::notifyReleased(std::string key) { }

    void MenuControl::setMenu(Menus::Menu* p) {
        pMenu = p;
    }

} // namespace Control