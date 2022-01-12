#include "WorldGenerator/WorldGenerator.h"

#include "Entities/Characters/Enemies/Hyena.h"
#include "Entities/Characters/Enemies/Snake.h"
#include "Entities/Characters/Player.h"
#include "Entities/Loot/Coin.h"
#include "Entities/Obstacles/Cactus.h"
#include "Entities/Obstacles/Platform.h"
#include "Entities/Obstacles/Quicksand.h"

#include <stdlib.h>
#include <time.h>
#include <vector>

namespace WorldGenerator {

    WorldGenerator::WorldGenerator(List::EntityList* movingEntitiesList, List::EntityList* staticEntitiesList, const unsigned int renderDistance) :
    movingEntitiesList(movingEntitiesList),
    staticEntitiesList(staticEntitiesList),
    renderDistance(renderDistance) {
        srand(time(NULL));

        Math::CoordU screenSize = Managers::Graphics::getInstance()->getWindowSize();

        lowerBound.y = screenSize.y;

        resetToOrigin();
    }

    WorldGenerator::~WorldGenerator() {
    }

    void WorldGenerator::generate(Math::CoordF* lastPosition, Entities::Characters::Player* player) {

        *lastPosition = lastPositionCreated;

        Entities::Entity* tmp;

        sequence = 5;

        bool lastWasQuicksand = false, platWithCoin = false;
        lastPositionCreated.y = -(2.0f + rand() % 2) * PLATFORM_HEIGHT / 3 + lowerBound.y;

        for (int i = 0; i < renderDistance; i++) {
            if (sequence <= 0) {
                sequence = 2 + rand() % 3;
                lastPositionCreated.y = -(2.0f + rand() % 2) * PLATFORM_HEIGHT / 3 + lowerBound.y;
                lastWasQuicksand = rand() % 4 == 0 && !lastWasQuicksand;
                platWithCoin = !lastWasQuicksand && rand() % 2 == 0;
            }

            lastPositionCreated.x += PLATFORM_WIDTH;

            sequence--;

            if (lastWasQuicksand) {
                tmp = new Entities::Obstacles::Quicksand(lastPositionCreated);
                staticEntitiesList->addEntity(static_cast<Entities::Entity*>(tmp));
            } //
            else {
                tmp = new Entities::Obstacles::Platform(lastPositionCreated);
                staticEntitiesList->addEntity(static_cast<Entities::Entity*>(tmp));

                if (platWithCoin) {
                    tmp = new Entities::Loot::Coin(Math::CoordF(lastPositionCreated.x, 0));
                    movingEntitiesList->addEntity(static_cast<Entities::Entity*>(tmp));
                }
                if (rand() % 3 && sequence > 1 && sequence < 4) { // 33.33% of chance of having a cactus on the platform
                    tmp = new Entities::Obstacles::Cactus(Math::CoordF(lastPositionCreated.x + PLATFORM_WIDTH / 2, lastPositionCreated.y - CACTUS_HEIGHT / 2 - PLATFORM_HEIGHT / 2));
                    staticEntitiesList->addEntity(static_cast<Entities::Entity*>(tmp));
                }
            }

            if (rand() % 2) {
                if (rand() % 3) {
                    tmp = new Entities::Characters::Enemies::Snake(Math::CoordF(lastPositionCreated.x, 300), player);
                    movingEntitiesList->addEntity(static_cast<Entities::Entity*>(tmp));
                } //
                else {
                    tmp = new Entities::Characters::Enemies::Hyena(Math::CoordF(lastPositionCreated.x, 300), player);
                    movingEntitiesList->addEntity(static_cast<Entities::Entity*>(tmp));
                }
            }
        }

        clean();
    }

    void WorldGenerator::clean() {
        Entities::Entity* pAux = nullptr;
        for (int i = 0; i < staticEntitiesList->getSize(); i++) {
            pAux = (*staticEntitiesList)[i];
            if (pAux) {
                if (pAux->getPosition().x < (lastPositionCreated.x - 3 * renderDistance * PLATFORM_WIDTH)) {
                    staticEntitiesList->deleteEntity(pAux);
                    i--;
                    if (i < 0)
                        i = -1;
                } else
                    break;
            }
        }
        for (int i = 0; i < movingEntitiesList->getSize(); i++) {
            pAux = (*movingEntitiesList)[i];
            if (pAux) {
                if (pAux->getPosition().x < (lastPositionCreated.x - 3 * renderDistance * PLATFORM_WIDTH)) {
                    movingEntitiesList->deleteEntity(pAux);
                    i--;
                    if (i < 0)
                        i = -1;
                } else
                    break;
            }
        }
    }

    void WorldGenerator::explodeCoins(Math::CoordF position) {
        unsigned int coinQuantity = 3 + rand() % 5;
        Math::CoordF velocity;

        for (int i = 0; i < coinQuantity; i++) {
            velocity.x = rand() % 1000 - 500;
            velocity.y = -300;

            Entities::Loot::Coin* newCoin = new Entities::Loot::Coin(position, velocity);
            movingEntitiesList->addEntity(newCoin);
        }
    }

    void WorldGenerator::setRenderDistance(const unsigned int renderDistance) {
        this->renderDistance = renderDistance;
    }

    void WorldGenerator::resetToOrigin() {
        lastPositionCreated = Math::CoordF(0, 0);
    }

} // namespace WorldGenerator