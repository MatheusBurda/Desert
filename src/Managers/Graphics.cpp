#include "Managers/Graphics.h"

#include <cstring>
#include <iostream>

#define WIDTH 1280
#define HEIGHT 720

namespace Managers {

    /* Singleton design pattern - Only one instance will be created */
    Graphics* Graphics::instance = nullptr;

    /* Returns a pointer to the Graphics. */
    Graphics* Graphics::getInstance() {
        if (instance == nullptr) {
            instance = new Graphics();
        }
        return instance;
    }

    Graphics::Graphics() :
    window(new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "Desert", sf::Style::Titlebar | sf::Style::Close)),
    view(sf::Vector2f(WIDTH / 2, HEIGHT / 2), sf::Vector2f(WIDTH, HEIGHT)),
    texturesMap(),
    fontsMap() { }

    Graphics::~Graphics() {
        std::map<const char*, sf::Texture*>::iterator it;

        for (it = texturesMap.begin(); it != texturesMap.end(); ++it) {
            delete (it->second);
        }

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

    /* Returns if the window is open. */
    bool Graphics::isWindowOpen() const {
        return window->isOpen();
    }

    /* CAUTION: Call the close window function - SFML window will close. */
    void Graphics::closeWindow() {
        window->close();
    }

    /* Sets window size to its parameters */
    void Graphics::setWindowSize(Math::CoordU size) {
        window->setSize(sf::Vector2u(size.x, size.y));
        view.setSize(size.x, size.y);
        window->setView(view);
    }

    /* Returns the window size. */
    Math::CoordU Graphics::getWindowSize() const {
        return Math::CoordU(window->getSize().x, window->getSize().y);
    }

    /* Returns the top left position of screen. */
    Math::CoordF Graphics::getTopLeftPosition() const {
        return Math::CoordF(window->getView().getCenter().x - window->getSize().x / 2, window->getView().getCenter().y - window->getSize().y / 2);
    }

    /* Changes the view position. */
    void Graphics::centerView(Math::CoordF pos) {
        view.setCenter(sf::Vector2f(pos.x, pos.y));
        window->setView(view);
    }

    /* Returns a texture to be used by an entity. */
    sf::Texture* Graphics::loadTexture(const char* path) {
        /* Tries to find an existing texture linked by the path to it. */
        std::map<const char*, sf::Texture*>::iterator it = texturesMap.begin();
        while (it != texturesMap.end()) {
            if (!strcmp(it->first, path))
                return it->second;
            it++;
        }

        /* If not found, must load it. */
        sf::Texture* tex = new sf::Texture();

        if (!tex->loadFromFile(path)) {
            std::cout << "ERROR loading file " << path << std::endl;
            exit(1);
        }

        texturesMap.insert(std::pair<const char*, sf::Texture*>(path, tex));

        return tex;
    }

    /* Returns a font pointer to be used by texts. */
    sf::Font* Graphics::loadFont(const char* path) {
        /* Tries to find an existing font linked by the path to it */
        std::map<const char*, sf::Font*>::iterator it = fontsMap.begin();
        while (it != fontsMap.end()) {
            if (!strcmp(it->first, path))
                return it->second;
            it++;
        }

        /* If not found, must load it. */
        sf::Font* font = new sf::Font();

        if (!font->loadFromFile(path)) {
            std::cout << "ERROR loading file " << path << std::endl;
            exit(1);
        }

        fontsMap.insert(std::pair<const char*, sf::Font*>(path, font));

        return font;
    }

    sf::RenderWindow* Graphics::getWindow() const {
        return window;
    }

} // namespace Managers