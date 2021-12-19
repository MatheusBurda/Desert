#include "Game.h"

using namespace Managers;

Game::Game() :
pGraphicManager(Graphics::getInstance()),
p1(new Entities::Characters::Player(Math::CoordF(200.f, 400.f), true)),
background(),
staticEntitiesList(),
movingEntitiesList(),
collisionManager(&movingEntitiesList, &staticEntitiesList) {

    background.initialize("./assets/Background/Background.png", Math::CoordF(1280 / 2, 720 / 2), Math::CoordF(1280, 720));

    clock.restart();
    dt = 0;

    movingEntitiesList.addEntity(p1);

    /* Cria plataformas */

    Entities::Entity* tmp;

    for (int i = 0; i < 20; i++) {
        tmp = new Entities::Obstacles::Platform(Math::CoordF(96.f * i, 500.f));
        staticEntitiesList.addEntity(tmp);
    }

    /* Cria inimigos */
    Entities::Characters::Enemies::Snake* snake = new Entities::Characters::Enemies::Snake(Math::CoordF(776.f, 300.f), p1);
    snake->setVelocity(Math::CoordF(0.0f, 0.0f));
    movingEntitiesList.addEntity(snake);

    Entities::Characters::Enemies::Hyena* Hyena = new Entities::Characters::Enemies::Hyena(Math::CoordF(1200.f, 300.f), p1);
    Hyena->setVelocity(Math::CoordF(-300.0f, 0.0f));
    movingEntitiesList.addEntity(Hyena);

    exec();
}

Game::~Game() {
}

void Game::exec() {
    float dt;

    while (pGraphicManager->isWindowOpen()) {
        dt = updateDeltaTime();
        pGraphicManager->clear();

        background.render();

        for (unsigned int i = 0; i < movingEntitiesList.getSize(); i++) {
            movingEntitiesList[i]->update(dt);
        }

        collisionManager.collide();

        for (unsigned int i = 0; i < staticEntitiesList.getSize(); i++) {
            staticEntitiesList[i]->render();
        }

        for (unsigned int i = 0; i < movingEntitiesList.getSize(); i++) {
            movingEntitiesList[i]->render();
        }

        pGraphicManager->display();
    }
}

/* Update the dt timer */
float Game::updateDeltaTime() {
    if (dt < TICK_RATE) {
        dt += clock.getElapsedTime().asSeconds();
        clock.restart();
        return 0.0f;
    }

    dt -= TICK_RATE;

    return TICK_RATE;
}