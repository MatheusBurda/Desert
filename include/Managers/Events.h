#pragma once

#include "Managers/Graphics.h"
#include "Managers/Input.h"

namespace Managers {

    class Events {
    private:
        Graphics* pGraphicM;
        Input* pInputM;
        sf::RenderWindow* pWindow;

        /* Singleton design pattern */
        static Events* instance;
        Events();

    public:
        ~Events();

        static Events* getInstance();

        void setGraphicManager();
        void setInput(Input* pIM);

        void pollEvents();
    };

} // namespace Managers