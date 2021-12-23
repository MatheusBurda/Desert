#pragma once

#include "Managers/Input.h"

namespace Control {

    class Observer {
    private:
        Managers::Input* pIM;

    public:
        Observer();

        virtual ~Observer();
        
        virtual void notify(std::string key) = 0;
    };

} // namespace Control