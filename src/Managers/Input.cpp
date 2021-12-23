#include "Managers/Input.h"

#include "Control/Observer.h"

#include <iostream>

namespace Managers {

    Input* Input::instance = NULL;

    Input* Input::getInstance() {
        if (instance == NULL) {
            instance = new Input();
        }
        return instance;
    }

    Input::Input() {
        keyMap[sf::Keyboard::A] = "A";
        keyMap[sf::Keyboard::B] = "B";
        keyMap[sf::Keyboard::C] = "C";
        keyMap[sf::Keyboard::D] = "D";
        keyMap[sf::Keyboard::E] = "E";
        keyMap[sf::Keyboard::F] = "F";
        keyMap[sf::Keyboard::G] = "G";
        keyMap[sf::Keyboard::H] = "H";
        keyMap[sf::Keyboard::I] = "I";
        keyMap[sf::Keyboard::J] = "J";
        keyMap[sf::Keyboard::K] = "K";
        keyMap[sf::Keyboard::L] = "L";
        keyMap[sf::Keyboard::M] = "M";
        keyMap[sf::Keyboard::N] = "N";
        keyMap[sf::Keyboard::O] = "O";
        keyMap[sf::Keyboard::P] = "P";
        keyMap[sf::Keyboard::Q] = "Q";
        keyMap[sf::Keyboard::R] = "R";
        keyMap[sf::Keyboard::S] = "S";
        keyMap[sf::Keyboard::T] = "T";
        keyMap[sf::Keyboard::U] = "U";
        keyMap[sf::Keyboard::V] = "V";
        keyMap[sf::Keyboard::W] = "W";
        keyMap[sf::Keyboard::X] = "X";
        keyMap[sf::Keyboard::Y] = "Y";
        keyMap[sf::Keyboard::Z] = "Z";
        keyMap[sf::Keyboard::Num1] = "1";
        keyMap[sf::Keyboard::Num2] = "2";
        keyMap[sf::Keyboard::Num3] = "3";
        keyMap[sf::Keyboard::Num4] = "4";
        keyMap[sf::Keyboard::Num5] = "5";
        keyMap[sf::Keyboard::Num6] = "6";
        keyMap[sf::Keyboard::Num7] = "7";
        keyMap[sf::Keyboard::Num8] = "8";
        keyMap[sf::Keyboard::Num9] = "9";
        keyMap[sf::Keyboard::Num0] = "0";
        keyMap[sf::Keyboard::Space] = "Space";
        keyMap[sf::Keyboard::Enter] = "Enter";
        keyMap[sf::Keyboard::Escape] = "Escape";
        keyMap[sf::Keyboard::BackSpace] = "BackSpace";
        keyMap[sf::Keyboard::Right] = "Right";
        keyMap[sf::Keyboard::Left] = "Left";
        keyMap[sf::Keyboard::Up] = "Up";
        keyMap[sf::Keyboard::Down] = "Down";

        std::map<sf::Keyboard::Key, std::string>::iterator it;

        for (it = keyMap.begin(); it != keyMap.end(); it++) {
            keysDown[it->first] = false;
        }
    }

    Input::~Input() {
        objObserving.clear();
        keysDown.clear();
        keyMap.clear();
    }

    /* Subscribe a Observer to recieve a notification when something happens. */
    void Input::Attach(Control::Observer* pObserver) {
        objObserving.push_back(pObserver);
    }

    void Input::Detach(Control::Observer* pObserver) {
        objObserving.remove(pObserver);
    }

    /* Check for keys pressed and notify every Observer. */
    void Input::handleKeyPressed(sf::Keyboard::Key key) {
        keysDown[key] = true;
        for (it = objObserving.begin(); it != objObserving.end(); ++it)
            (*it)->notify(keyMap[key]);
    }

    /* Check for keys pressed and notify every Observer. */
    void Input::handleKeyReleased(sf::Keyboard::Key key) {
        keysDown[key] = false;
    }

} // namespace Managers