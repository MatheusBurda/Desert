#include "Managers/Graphics.h"

#include <cstring>
#include <iostream>

#define FONT_PATH "./assets/Fonts/minecraft-ten.ttf"
#define WIDTH 1200
#define HEIGHT 720
#define FRAME_RATE 100

namespace Managers {

    float Graphics::dt = 0;

    Graphics::Graphics() :
    window(new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "king++")),
    view(sf::Vector2f(WIDTH / 2, HEIGHT / 2), sf::Vector2f(WIDTH, HEIGHT)),
    texturesMap(),
    clock(){
        font = NULL;
    }

    Graphics::~Graphics() {

        std::map<const char*, sf::Texture*>::iterator it;
        for (it = texturesMap.begin(); it != texturesMap.end(); ++it)
            delete (it->second);

        delete (window);
    }

    /* Give a pointer to a body and it will be drawn to the screen. */
    void Graphics::render(sf::RectangleShape* body) {
        window->draw(*body);
    }

    /* Give a pointer to a Text and it will be drawn to the screen */
    void Graphics::render(sf::Text* text) {
        window->draw(*text);
    }

    /* Display everything that was drawn. */
    void Graphics::display() {
        if (isWindowOpen())
            window->display();
    }

    /* Clear the window to re-display stuff. */
    void Graphics::clear() {
        if (isWindowOpen())
            window->clear();
    }

    /* Returns pointer to the window. */
    sf::RenderWindow* Graphics::getWindow() const {
        return window;
    }

    /* Returns if the window is open. */
    bool Graphics::isWindowOpen() const {
        return window->isOpen();
    }

    /* CAUTION: Call the close window function - SFML window will close. */
    void Graphics::closeWindow() {
        window->close();
    }

    /* Handles  resize. */
    void Graphics::handleWindowResize() {
        float aspectRatio = float(window->getSize().x / float(window->getSize().y));
        view.setSize(sf::Vector2f(HEIGHT * aspectRatio, HEIGHT));
        window->setView(view);
    }

    /* Returns the window size. */
    sf::Vector2u Graphics::getWindowSize() const {
        return window->getSize();
    }

    /* Changes the view position. */
    void Graphics::centerView(Math::CoordF pos) {
        view.setCenter(sf::Vector2f(pos.x, pos.y));
        window->setView(view);
    }

    /* Returns a texture to be used by an entity. */
    sf::Texture* Graphics::loadTexture(const char* path) {
        /* Tries to find an existing texture linked by the id. */
        std::map<const char*, sf::Texture*>::iterator it = texturesMap.begin();
        while (it != texturesMap.end()) {
            if (!strcmp(it->first, path))
                return it->second;
            it++;
        }

        /* If not found, have to load it. */
        sf::Texture* tex = new sf::Texture();

        if (!tex->loadFromFile(path)) {
            std::cout << "ERROR loading file " << path << std::endl;
            exit(1);
        }

        texturesMap.insert(std::pair<const char*, sf::Texture*>(path, tex));

        return tex;
    }

    /* Returns a font pointer to be used by texts. */
    sf::Font* Graphics::getFont() {
        if (!font) {
            font = new sf::Font();
            if (!font->loadFromFile(FONT_PATH)) {
                std::cout << "Error loading Font!" << std::endl;
                exit(1);
            }
        }
        return font;
    }

    /* Update the static dt timer */
    void Graphics::updateDeltaTime(){
        dt = clock.getElapsedTime().asSeconds();
        clock.restart();
    }

} // namespace Managers