#include "Game.h"

using namespace Managers;

Game::Game() :
pGraphicManager() {
    exec();
}

Game::~Game() {
}

void Game::exec() {
    while (pGraphicManager.isWindowOpen()) {
        pGraphicManager.updateDeltaTime();
        pGraphicManager.clear();

        /* UPDATE ALL */

        pGraphicManager.display();
    }
}