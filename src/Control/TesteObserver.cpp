#include "Control/TesteObserver.h"

#include <iostream>

namespace Control {

    TesteObserver::TesteObserver() {
    }

    TesteObserver::~TesteObserver() {
    }

    void TesteObserver::notify(std::string key) {
        if (key == "BackSpace") {
            if (text.size() > 0)
                text.pop_back();
        } //
        else if (key == "Space")
            text += " ";
        else
            text += key;

        std::cout << text << std::endl;
    }

} // namespace Control
