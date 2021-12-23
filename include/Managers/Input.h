#pragma once

#include <list>
#include <map>
#include <SFML/Graphics.hpp>
#include <string>

namespace Control {
    class Observer;
} // namespace Control

namespace Managers {

    class Input {
    private:
        std::list<Control::Observer*> objObserving;
        std::list<Control::Observer*>::iterator it;

        std::map<sf::Keyboard::Key, std::string> keyMap;
        std::map<sf::Keyboard::Key, bool> keysDown;

        /* Singleton design pattern */
        static Input* instance;

        Input();

    public:
        ~Input();

        static Input* getInstance();

        void Attach(Control::Observer* pObserver);

        void Detach(Control::Observer* pObserver);

        void handleKeyPressed(sf::Keyboard::Key key);

        void handleKeyReleased(sf::Keyboard::Key key);

        std::string getInputAsString();
    };

} // namespace Managers