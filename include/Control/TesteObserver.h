#pragma once

#include "Control/Observer.h"

namespace Control {
    class TesteObserver : public Observer {
    private:
        std::string text;

    public:
        TesteObserver();

        ~TesteObserver();

        void notify(std::string key);
    };

} // namespace Control
