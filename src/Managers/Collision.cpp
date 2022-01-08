#include "Managers/Collision.h"

#include "Entities/MovingEntity.h"
#include "math.h"

namespace Managers {

    Collision::Collision(List::EntityList* movingEntities, List::EntityList* staticEntities) :
    movingEntities(movingEntities),
    staticEntities(staticEntities) { }

    Collision::~Collision() {
        movingEntities = nullptr;
        staticEntities = nullptr;
    }

    void Collision::collide() {
        Entities::Entity* ent1 = nullptr;
        Entities::Entity* ent2 = nullptr;
        Math::CoordF intersect;
        Math::CoordF centerDistance;
        int i, j;

        /* Collide non-moving entities with moving entities */
        for (i = 0; i < staticEntities->getSize(); i++) {
            for (j = 0; j < movingEntities->getSize(); j++) {
                ent1 = (*staticEntities)[i];
                ent2 = (*movingEntities)[j];

                centerDistance.x = ent2->getPosition().x - ent1->getPosition().x;
                centerDistance.y = ent2->getPosition().y - ent1->getPosition().y;

                intersect.x = fabs(centerDistance.x) - (ent1->getSize().x / 2 + ent2->getSize().x / 2);
                intersect.y = fabs(centerDistance.y) - (ent1->getSize().y / 2 + ent2->getSize().y / 2);

                if (intersect.x < 0.0f && intersect.y < 0.0f) { // Condition to collide...
                    ent2->collide(ent1, intersect);
                }
            }
        }

        /* Collide moving entities with moving entities - diagonally */
        for (i = 0; i < movingEntities->getSize(); i++) {
            for (j = i + 1; j < movingEntities->getSize(); j++) {
                ent1 = (*movingEntities)[i];
                ent2 = (*movingEntities)[j];

                centerDistance.x = ent2->getPosition().x - ent1->getPosition().x;
                centerDistance.y = ent2->getPosition().y - ent1->getPosition().y;

                intersect.x = abs(centerDistance.x) - (ent1->getSize().x / 2 + ent2->getSize().x / 2);
                intersect.y = abs(centerDistance.y) - (ent1->getSize().y / 2 + ent2->getSize().y / 2);

                if (intersect.x < 0.0f && intersect.y < 0.0f) { // Condition to collide...
                    ent2->collide(ent1, intersect);
                    ent1->collide(ent2, intersect);
                }
            }
        }

        clear();
    }

    /* Function to deallocate entities after collision */
    void Collision::clear() {
        Entities::MovingEntity* pAux = nullptr;
        for (int i = 0; i < movingEntities->getSize(); i++) {
            pAux = static_cast<Entities::MovingEntity*>((*movingEntities)[i]);
            if (pAux != nullptr) {
                if (!pAux->isActive()) {
                    movingEntities->deleteEntity(pAux);
                    i--;
                    if (i < 0)
                        i = -1;
                }
            }
        }
    }

} // namespace Managers