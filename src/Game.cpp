#include "Game.h"

using namespace Managers;

Game::Game() :
pGraphicManager(Graphics::getInstance()),
p1(new Entities::Characters::Player(Math::CoordF(200.f, 400.f), true)),
background("./assets/Background/Background.png", Math::CoordF(0.0f, 0.0f), Math::CoordF(1280, 720), 1) {

    list.addEntity(p1);

    exec();
}

Game::~Game() {
}

void Game::exec() {
    float dt;

    while (pGraphicManager->isWindowOpen()) {
        dt = pGraphicManager->updateDeltaTime();
        pGraphicManager->clear();

        background.render();

        for (unsigned int i = 0; i < list.getSize(); i++) {
            list[i]->update(dt);
            list[i]->render();
        }

        pGraphicManager->display();
    }
}