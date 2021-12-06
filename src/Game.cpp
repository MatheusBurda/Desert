#include "Game.h"

using namespace Managers;

Game::Game() :
pGraphicManager(Graphics::getInstance()) ,
p1(Math::CoordF(200.f, 400.f), true){

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
        p1.render();

        pGraphicManager->display();
    }
}