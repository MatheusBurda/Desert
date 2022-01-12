#include "States/Level.h"

#include "Entities/Obstacles/Platform.h"

namespace States {

    Level::Level(StateMachine* pSM) :
    State(pSM, stateID::playing),
    staticEntitiesList(),
    movingEntitiesList(),
    collisionManager(&movingEntitiesList, &staticEntitiesList, this),
    hud(),
    pGraphicM(Managers::Graphics::getInstance()),
    worldGen(&movingEntitiesList, &staticEntitiesList) {
        playerPoints = 0;
        background.initialize("./assets/Background/Background.png", Math::CoordF(1280 / 2, 720 / 2), Math::CoordF(1280, 720));
        levelEnded = true;
    }
    Level::~Level() {
    }

    void Level::update(const float dt) {
        for (unsigned int i = 0; i < movingEntitiesList.getSize(); i++) {
            movingEntitiesList[i]->update(dt);
        }

        collisionManager.collide();

        pGraphicM->centerView(Math::CoordF(player->getPosition().x, pGraphicM->getWindowSize().y / 2 - PLATFORM_HEIGHT / 2));
        background.update(Math::CoordF(player->getPosition().x, pGraphicM->getWindowSize().y / 2 - PLATFORM_HEIGHT / 2));
        hud.update(dt);

        if (player->getPosition().x >= nextPositionToRender.x)
            worldGen.generate(&nextPositionToRender, player);

        if (!player->isActive()) {
            endLevel();
            changeState(States::stateID::gameOver);
        }
    }

    void Level::render() {

        background.render();

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

            player = new Entities::Characters::Player(Math::CoordF(200.f, 300.f));
            movingEntitiesList.addEntity(player);

            worldGen.resetToOrigin();

            worldGen.generate(&nextPositionToRender, player);

            hud.setPlayer(player);

            levelEnded = false;
        }
        worldGen.setRenderDistance();
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

    void Level::coinBomb(Math::CoordF position) {
        worldGen.explodeCoins(position);
    }

} // namespace States