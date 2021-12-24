#include "Control/TextInput.h"

#include <iostream>

namespace Control {

    TextInput::TextInput() { }

    TextInput::~TextInput() { }

    void TextInput::notifyPressed(std::string key) {
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

    void TextInput::notifyReleased(std::string key) { }

} // namespace Control
