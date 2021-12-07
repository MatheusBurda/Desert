#include "Game.h"

using namespace Managers;

Game::Game() :
pGraphicManager(Graphics::getInstance()) ,
p1(Math::CoordF(200.f, 400.f), true),
background("./assets/Background/Background.png", Math::CoordF(0.0f, 0.0f), Math::CoordF(1280,720), 1){

    exec();
}

Game::~Game() {
}

void Game::exec() {
    float dt;

    while (pGraphicManager->isWindowOpen()) {
        dt = pGraphicManager->updateDeltaTime();
        pGraphicManager->clear();

        /* UPDATE ALL */
        p1.update(dt);
        /* Render ALL*/
        background.render();
        p1.render();

        pGraphicManager->display();
    }
}