#include "States/Level.h"

namespace States {

    Level::Level(StateMachine* pSM) :
    State(pSM, stateID::playing),
    staticEntitiesList(),
    movingEntitiesList(),
    collisionManager(&movingEntitiesList, &staticEntitiesList),
    hud(),
    pGraphicM(Managers::Graphics::getInstance()) {
        playerPoints = 0;
        // background.initialize("./assets/Background/Background.png", Math::CoordF(1280 / 2, 720 / 2), Math::CoordF(1280, 720));
        levelEnded = true;
    }
    Level::~Level() {
    }

    void Level::update(const float dt) {
        for (unsigned int i = 0; i < movingEntitiesList.getSize(); i++) {
            movingEntitiesList[i]->update(dt);
        }

        collisionManager.collide();

        pGraphicM->centerView(player->getPosition());
        hud.update(dt);

        if (player->getLife() <= 0) {
            endLevel();
            changeState(States::stateID::gameOver);
        }
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
        if (levelEnded) {

            /* Cria plataformas */
            Entities::Entity* tmp;

            for (int i = 0; i < 20; i++) {
                tmp = new Entities::Obstacles::Platform(Math::CoordF(96.f * i, 500.f));
                staticEntitiesList.addEntity(tmp);
            }

            Entities::Characters::Player* p1 = new Entities::Characters::Player(Math::CoordF(100.f, 300.f));
            movingEntitiesList.addEntity(p1);

            player = p1;

            /* Coins de teste */
            Entities::Loot::Coin* coin;

            for (int i = 0; i < 20; i++) {
                coin = new Entities::Loot::Coin(Math::CoordF(300.f + 55 * i, 300.f), Math::CoordF(0.f, 0.f));
                movingEntitiesList.addEntity(coin);
            }

            /* Cria inimigos */
            Entities::Characters::Enemies::Snake* snake = new Entities::Characters::Enemies::Snake(Math::CoordF(776.f, 300.f), player);
            snake->setVelocity(Math::CoordF(0.0f, 0.0f));
            movingEntitiesList.addEntity(snake);

            snake = new Entities::Characters::Enemies::Snake(Math::CoordF(650.f, 300.f), player);
            snake->setVelocity(Math::CoordF(0.0f, 0.0f));
            movingEntitiesList.addEntity(snake);

            snake = new Entities::Characters::Enemies::Snake(Math::CoordF(550.f, 300.f), player);
            snake->setVelocity(Math::CoordF(0.0f, 0.0f));
            movingEntitiesList.addEntity(snake);

            snake = new Entities::Characters::Enemies::Snake(Math::CoordF(450.f, 300.f), player);
            snake->setVelocity(Math::CoordF(0.0f, 0.0f));
            movingEntitiesList.addEntity(snake);

            Entities::Characters::Enemies::Hyena* Hyena = new Entities::Characters::Enemies::Hyena(Math::CoordF(800.f, 300.f), player);
            Hyena->setVelocity(Math::CoordF(-300.0f, 0.0f));
            movingEntitiesList.addEntity(Hyena);

            hud.setPlayer(p1);
            levelEnded = false;
        }
    }

    void Level::endLevel() {
        playerPoints = player->getPlayerPoints();
        movingEntitiesList.cleanList();
        staticEntitiesList.cleanList();
        levelEnded = true;
    }

    int Level::getPlayerPoints() const {
        return playerPoints;
    }

} // namespace States