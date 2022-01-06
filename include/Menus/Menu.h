#pragma once

#include "GraphicalElements/Button.h"
#include <vector>

namespace Menus {

    class Menu {
    private:
        std::vector<GraphicalElements::Button*> vectorOfButtons;
        std::vector<GraphicalElements::Button*>::iterator it;
        int selected;
        int min;
        int max;
       /*  MenuControl control;
        Background back; */
        bool active;

    public:
        Menu();

        virtual ~Menu();

        virtual void exec() = 0;

        void updateView();

        void selectDown();

        void selectUp();
    };

} // namespace Menus
