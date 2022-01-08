#include "States/Level.h"

namespace States {

    Level::Level(StateMachine* pSM, Entities::Characters::Player* p1) :
    State(pSM, stateID::playing),
    player(p1),
    staticEntitiesList(),
    movingEntitiesList(),
    collisionManager(&movingEntitiesList, &staticEntitiesList),
    hud(p1),
    pGraphicM(Managers::Graphics::getInstance()) {
        // background.initialize("./assets/Background/Background.png", Math::CoordF(1280 / 2, 720 / 2), Math::CoordF(1280, 720));

        /* Cria plataformas */
        Entities::Entity* tmp;

        for (int i = 0; i < 20; i++) {
            tmp = new Entities::Obstacles::Platform(Math::CoordF(96.f * i, 500.f));
            staticEntitiesList.addEntity(tmp);
        }
       
        /* Coins de teste */
        Entities::Loot::Coin* coin;

        for (int i = 0; i < 20; i++) {
            coin = new Entities::Loot::Coin(Math::CoordF(300.f + 50 * i, 300.f), Math::CoordF(0.f, 0.f));
            movingEntitiesList.addEntity(coin);
        }

        /* Cria inimigos */
        Entities::Characters::Enemies::Snake* snake = new Entities::Characters::Enemies::Snake(Math::CoordF(776.f, 300.f), p1);
        snake->setVelocity(Math::CoordF(0.0f, 0.0f));
        movingEntitiesList.addEntity(snake);

        Entities::Characters::Enemies::Hyena* Hyena = new Entities::Characters::Enemies::Hyena(Math::CoordF(1200.f, 300.f), p1);
        Hyena->setVelocity(Math::CoordF(-300.0f, 0.0f));
        movingEntitiesList.addEntity(Hyena);

        movingEntitiesList.addEntity(p1);
    }
    Level::~Level() {
    }

    void Level::update(const float dt) {
        pGraphicM->centerView(player->getPosition());

        for (unsigned int i = 0; i < movingEntitiesList.getSize(); i++) {
            movingEntitiesList[i]->update(dt);
        }

        collisionManager.collide();

        hud.update(dt);
    }

    void Level::render() {
        // background.render();

        for (unsigned int i = 0; i < staticEntitiesList.getSize(); i++) {
            staticEntitiesList[i]->render();
        }

        for (unsigned int i = 0; i < movingEntitiesList.getSize(); i++) {
            movingEntitiesList[i]->render();
        }

        hud.render();
    }

    void Level::resetState() {
        /* movingEntitiesList.cleanList();
        staticEntitiesList.cleanList(); */
    }

} // namespace States