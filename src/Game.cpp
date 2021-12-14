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

    Entities::Entity* tmp;
    tmp = new Entities::Obstacles::Platform(Math::CoordF(200.f, 500.f));
    staticEntitiesList.addEntity(tmp);
    tmp = new Entities::Obstacles::Platform(Math::CoordF(296.f, 600.f));
    staticEntitiesList.addEntity(tmp);
    tmp = new Entities::Obstacles::Platform(Math::CoordF(392.f, 600.f));
    staticEntitiesList.addEntity(tmp);
    tmp = new Entities::Obstacles::Platform(Math::CoordF(488.f, 600.f));
    staticEntitiesList.addEntity(tmp);
    tmp = new Entities::Obstacles::Platform(Math::CoordF(584.f, 600.f));
    staticEntitiesList.addEntity(tmp);
    tmp = new Entities::Obstacles::Platform(Math::CoordF(680.f, 600.f));
    staticEntitiesList.addEntity(tmp);
    tmp = new Entities::Obstacles::Platform(Math::CoordF(776.f, 600.f));
    staticEntitiesList.addEntity(tmp);
    tmp = new Entities::Obstacles::Platform(Math::CoordF(872.f, 600.f));
    staticEntitiesList.addEntity(tmp);
    tmp = new Entities::Obstacles::Platform(Math::CoordF(968.f, 600.f));
    staticEntitiesList.addEntity(tmp);
    tmp = new Entities::Obstacles::Platform(Math::CoordF(1064.f, 500.f));
    staticEntitiesList.addEntity(tmp);

    tmp = new Entities::Obstacles::Platform(Math::CoordF(200.f, 500.f));
    staticEntitiesList.addEntity(tmp);
    tmp = new Entities::Obstacles::Platform(Math::CoordF(296.f, 600.f));
    staticEntitiesList.addEntity(tmp);
    tmp = new Entities::Obstacles::Platform(Math::CoordF(392.f, 600.f));
    staticEntitiesList.addEntity(tmp);
    tmp = new Entities::Obstacles::Platform(Math::CoordF(488.f, 600.f));
    staticEntitiesList.addEntity(tmp);
    tmp = new Entities::Obstacles::Platform(Math::CoordF(584.f, 600.f));
    staticEntitiesList.addEntity(tmp);
    tmp = new Entities::Obstacles::Platform(Math::CoordF(680.f, 600.f));
    staticEntitiesList.addEntity(tmp);
    tmp = new Entities::Obstacles::Platform(Math::CoordF(776.f, 600.f));
    staticEntitiesList.addEntity(tmp);
    tmp = new Entities::Obstacles::Platform(Math::CoordF(872.f, 600.f));
    staticEntitiesList.addEntity(tmp);
    tmp = new Entities::Obstacles::Platform(Math::CoordF(968.f, 600.f));
    staticEntitiesList.addEntity(tmp);
    tmp = new Entities::Obstacles::Platform(Math::CoordF(1064.f, 500.f));
    staticEntitiesList.addEntity(tmp);

    tmp = new Entities::Obstacles::Platform(Math::CoordF(200.f, 500.f));
    staticEntitiesList.addEntity(tmp);
    tmp = new Entities::Obstacles::Platform(Math::CoordF(296.f, 600.f));
    staticEntitiesList.addEntity(tmp);
    tmp = new Entities::Obstacles::Platform(Math::CoordF(392.f, 600.f));
    staticEntitiesList.addEntity(tmp);
    tmp = new Entities::Obstacles::Platform(Math::CoordF(488.f, 600.f));
    staticEntitiesList.addEntity(tmp);
    tmp = new Entities::Obstacles::Platform(Math::CoordF(584.f, 600.f));
    staticEntitiesList.addEntity(tmp);
    tmp = new Entities::Obstacles::Platform(Math::CoordF(680.f, 600.f));
    staticEntitiesList.addEntity(tmp);
    tmp = new Entities::Obstacles::Platform(Math::CoordF(776.f, 600.f));
    staticEntitiesList.addEntity(tmp);
    tmp = new Entities::Obstacles::Platform(Math::CoordF(872.f, 600.f));
    staticEntitiesList.addEntity(tmp);
    tmp = new Entities::Obstacles::Platform(Math::CoordF(968.f, 600.f));
    staticEntitiesList.addEntity(tmp);
    tmp = new Entities::Obstacles::Platform(Math::CoordF(1064.f, 500.f));

    staticEntitiesList.addEntity(tmp);
    tmp = new Entities::Obstacles::Platform(Math::CoordF(200.f, 500.f));
    staticEntitiesList.addEntity(tmp);
    tmp = new Entities::Obstacles::Platform(Math::CoordF(296.f, 600.f));
    staticEntitiesList.addEntity(tmp);
    tmp = new Entities::Obstacles::Platform(Math::CoordF(392.f, 600.f));
    staticEntitiesList.addEntity(tmp);
    tmp = new Entities::Obstacles::Platform(Math::CoordF(488.f, 600.f));
    staticEntitiesList.addEntity(tmp);
    tmp = new Entities::Obstacles::Platform(Math::CoordF(584.f, 600.f));
    staticEntitiesList.addEntity(tmp);
    tmp = new Entities::Obstacles::Platform(Math::CoordF(680.f, 600.f));
    staticEntitiesList.addEntity(tmp);
    tmp = new Entities::Obstacles::Platform(Math::CoordF(776.f, 600.f));
    staticEntitiesList.addEntity(tmp);
    tmp = new Entities::Obstacles::Platform(Math::CoordF(872.f, 600.f));
    staticEntitiesList.addEntity(tmp);
    tmp = new Entities::Obstacles::Platform(Math::CoordF(968.f, 600.f));
    staticEntitiesList.addEntity(tmp);
    tmp = new Entities::Obstacles::Platform(Math::CoordF(1064.f, 500.f));
    staticEntitiesList.addEntity(tmp);

    tmp = new Entities::Obstacles::Platform(Math::CoordF(200.f, 500.f));
    staticEntitiesList.addEntity(tmp);
    tmp = new Entities::Obstacles::Platform(Math::CoordF(296.f, 600.f));
    staticEntitiesList.addEntity(tmp);
    tmp = new Entities::Obstacles::Platform(Math::CoordF(392.f, 600.f));
    staticEntitiesList.addEntity(tmp);
    tmp = new Entities::Obstacles::Platform(Math::CoordF(488.f, 600.f));
    staticEntitiesList.addEntity(tmp);
    tmp = new Entities::Obstacles::Platform(Math::CoordF(584.f, 600.f));
    staticEntitiesList.addEntity(tmp);
    tmp = new Entities::Obstacles::Platform(Math::CoordF(680.f, 600.f));
    staticEntitiesList.addEntity(tmp);
    tmp = new Entities::Obstacles::Platform(Math::CoordF(776.f, 600.f));
    staticEntitiesList.addEntity(tmp);
    tmp = new Entities::Obstacles::Platform(Math::CoordF(872.f, 600.f));
    staticEntitiesList.addEntity(tmp);
    tmp = new Entities::Obstacles::Platform(Math::CoordF(968.f, 600.f));
    staticEntitiesList.addEntity(tmp);
    tmp = new Entities::Obstacles::Platform(Math::CoordF(1064.f, 500.f));
    staticEntitiesList.addEntity(tmp);

    movingEntitiesList.addEntity(p1);

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
        collisionManager.collide();
            movingEntitiesList[i]->update(dt);
        }

        /* for (unsigned int i = 0; i < staticEntitiesList.getSize(); i++) {
            staticEntitiesList[i]->update(dt);
        } */


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