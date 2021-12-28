#pragma once

#include "Control/Observer.h"

namespace Control {
    
    class TextInput : public Observer {
    private:
        std::string text;

    public:
        TextInput();

        ~TextInput();

        void notifyPressed(std::string key);

        void notifyReleased(std::string key);

    };

} // namespace Control
