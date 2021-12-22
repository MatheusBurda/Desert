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
    pGraphicM(NULL),
    pInputM(NULL),
    pWindow(NULL) {
        setGraphicManager();
    }

    /* ========================================= */

    Events::~Events() {
        if (pInputM)
            delete (pInputM);
        pGraphicM = NULL;
        pInputM = NULL;
        pWindow = NULL;
    }

    void Events::setGraphicManager() {
        pGraphicM = Graphics::getInstance();
        if (pGraphicM != NULL)
            pWindow = pGraphicM->getWindow();
    }

    void Events::setInputManager(InputManager* pIM) {
        pInputM = pIM;
    }

    void Events::pollEvents() {
        sf::Event event;

        while (pWindow->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                pGraphicM->closeWindow();
            if (event.type == sf::Event::Resized)
                pGraphicM->handleWindowResize();
            if ((event.type == sf::Event::KeyPressed || event.type == sf::Event::KeyReleased) && pInputM)
                pInputM->handleKeyPressed();
            if (event.type == sf::Event::TextEntered)
                pInputM->handleTextEntered(event);
        }
    }

} // namespace Managers