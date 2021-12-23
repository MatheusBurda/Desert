#include "Managers/Events.h"

namespace Managers {

    /* Singleton design pattern - Only one instance will be created */
    Events* Events::instance = NULL;

    Events* Events::getInstance() {
        if (instance == NULL) {
            instance = new Events();
        }
        return instance;
    }

    Events::Events() :
    pGraphicM(Managers::Graphics::getInstance()),
    pInputM(Managers::Input::getInstance()),
    pWindow(NULL) {
        if (pGraphicM != NULL)
            pWindow = pGraphicM->getWindow();
    }

    /* ========================================= */

    Events::~Events() {
        pGraphicM = NULL;
        pInputM = NULL;
        pWindow = NULL;
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