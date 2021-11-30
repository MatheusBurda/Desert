#include <SFML/Graphics.hpp>
#include "Math/CoordTL.h"
#include <iostream>

int main() {
    Math::CoordF pos1(100.45f, 100.0f);
    Math::CoordF pos2(300.0f, 200.10f);
    Math::Coord<float> pos3;

    std::cout << "Pos1.x: " << pos1.x << " Pos1.y: " << pos1.y << std::endl;
    std::cout << "Pos2.x: " << pos2.x << " Pos2.y: " << pos2.y << std::endl;
    std::cout << "Pos3.x: " << pos3.x << " Pos3.y: " << pos3.y << std::endl;

    pos3 = pos2 + pos1;

    std::cout << "Pos1.x: " << pos1.x << " Pos1.y: " << pos1.y << std::endl;
    std::cout << "Pos2.x: " << pos2.x << " Pos2.y: " << pos2.y << std::endl;
    std::cout << "Pos3.x: " << pos3.x << " Pos3.y: " << pos3.y << std::endl;
    
    
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::RectangleShape shape(sf::Vector2f(100.0f, 100.0f));
    shape.setFillColor(sf::Color::Green);
    shape.setOrigin(sf::Vector2f(50.0f, 50.0f));

    shape.setPosition(sf::Vector2f(pos1.x, pos1.y));

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}