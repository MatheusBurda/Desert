#pragma once

#include "Managers/Graphics.h"
//#include "InputManager.h"

namespace Managers {

    class Events {
    private:
        Graphics* pGraphicM;
        //InputManager* pInputM;
        sf::RenderWindow* pWindow;

        /* Singleton design pattern */
        static Events* instance;
        Events();

    public:
        ~Events();

        static Events* getInstance();

        void setGraphicManager();
        //void setInputManager(InputManager* pIM);

        void pollEvents();
    };

} // namespace Managers