#include "Game.h"

using namespace Managers;

Managers::Graphics* Game::pGraphicManager = NULL;

Game::Game() :
graphicManager() {
    pGraphicManager = &graphicManager;

    exec();
}

Game::~Game() {
}

void Game::exec() {
    while (graphicManager.isWindowOpen()) {
        graphicManager.updateDeltaTime();
        graphicManager.clear();

        /* UPDATE ALL */

        graphicManager.display();
    }
}