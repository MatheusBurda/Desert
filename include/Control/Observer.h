#pragma once

#include "Managers/Input.h"

namespace Control {

    class Observer {
    private:
        Managers::Input* pIM;

    public:
        Observer();

        virtual ~Observer();
        
        virtual void notifyPressed(std::string key) = 0;

        virtual void notifyReleased(std::string key) = 0;

    };

} // namespace Control