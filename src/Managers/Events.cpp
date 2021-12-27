#include "Managers/Events.h"

namespace Managers {

    /* Singleton design pattern - Only one instance will be created */
    Events* Events::instance = nullptr;

    Events* Events::getInstance() {
        if (instance == nullptr) {
            instance = new Events();
        }
        return instance;
    }

    Events::Events() :
    pGraphicM(Managers::Graphics::getInstance()),
    pInputM(Managers::Input::getInstance()),
    pWindow(nullptr) {
        if (pGraphicM != nullptr)
            pWindow = pGraphicM->getWindow();
    }

    /* ========================================= */

    Events::~Events() {
        pGraphicM = nullptr;
        pInputM = nullptr;
        pWindow = nullptr;
    }

    void Events::pollEvents() {
        sf::Event event;
        
        while (pWindow->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                pGraphicM->closeWindow();
            if (event.type == sf::Event::Resized)
                pGraphicM->handleWindowResize();
            if (event.type == sf::Event::KeyPressed)
                pInputM->handleKeyPressed(event.key.code);
            if (event.type == sf::Event::KeyReleased)
                pInputM->handleKeyReleased(event.key.code);
        }
    }

} // namespace Managers