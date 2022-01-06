#include "GraphicalElements/Button.h"

#define BUTTON_PATH_DEFAULT "./assets/Button/Default.png"
#define BUTTON_PATH_SELECTED "./assets/Button/Selected.png"
#define BUTTON_HEIGHT 64
#define BUTTON_WIDTH 240
#define BUTTON_TEXT_COLOR 77.6, 68.2, 44.3

namespace GraphicalElements {

    Button::Button(Math::CoordF position, std::string info) :
    textInfo(position, info),
    defaultTexture(nullptr),
    selectedTexture(nullptr) {
        defaultTexture = pGraphicM->loadTexture(BUTTON_PATH_DEFAULT);
        selectedTexture = pGraphicM->loadTexture(BUTTON_PATH_SELECTED);

        body.setSize(sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT));

        body.setOrigin(sf::Vector2f(BUTTON_WIDTH / 2, BUTTON_HEIGHT / 2));

        body.setPosition(sf::Vector2f(position.x, position.y)); 

        textInfo.setFontSize(30);

        textInfo.setTextAlignment(TextAlignment::center);

        textInfo.setTextColor(BUTTON_TEXT_COLOR);

        textInfo.setPosition(Math::CoordF(position.x, position.y ));
    }

    Button::~Button() {
    }

    void Button::select(const bool isSelected) {
        if (isSelected)
            body.setTexture(selectedTexture);
        else
            body.setTexture(defaultTexture);
    }

    void Button::render() {
        pGraphicM->render(&body);

        textInfo.render();
    }

} // namespace GraphicalElements