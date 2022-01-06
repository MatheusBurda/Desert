#include "GraphicalElements/Text.h"

#define TEXT_SIZE 24

namespace GraphicalElements {

    Managers::Graphics* Text::pGraphicM = Managers::Graphics::getInstance();

    Text::Text(Math::CoordF position, std::string info) :
    info(info) {
        text.setString(info);

        text.setFont(*pGraphicM->getFont());

        text.setCharacterSize(TEXT_SIZE);

        text.setOrigin(0, 0);

        text.setPosition(sf::Vector2f(position.x, position.y));

        text.setFillColor(sf::Color::White);
    }

    Text::~Text() { }

    void Text::setTextInfo(std::string info) {
        this->info = info;
        text.setString(this->info);

    }

    void Text::setPosition(Math::CoordF position) {
        text.setPosition(sf::Vector2f(position.x, position.y));
    }

    void Text::setTextColor(const unsigned int R, const unsigned int G, const unsigned int B) {
        text.setFillColor(sf::Color(R, G, B));
    }

    void Text::setFontSize(const unsigned int size) {
        text.setCharacterSize(size);
    }

    Math::CoordF Text::getSize() const {
        sf::FloatRect textRect = text.getLocalBounds();
        return Math::CoordF(textRect.width, textRect.height);
    }

    void Text::render() {
        pGraphicM->render(&text);
    }

    std::string Text::getInfo() const {
        return info;
    }

} // namespace GraphicalElements