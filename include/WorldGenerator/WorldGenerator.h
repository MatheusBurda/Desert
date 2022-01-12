#pragma once

#include "Entities/Characters/Player.h"
#include "List/EntityList.h"
#include "Math/CoordTL.h"

namespace WorldGenerator {

    class WorldGenerator {
    private:
        Math::CoordF viewPosition;
        List::EntityList* movingEntitiesList;
        List::EntityList* staticEntitiesList;
        unsigned int renderDistance;
        Math::CoordF lowerBound;
        Math::CoordF lastPositionCreated;
        int sequence;

    public:
        WorldGenerator(List::EntityList* movingEntitiesList, List::EntityList* staticEntitiesList, const unsigned int renderDistance = 20);

        ~WorldGenerator();

        void generate(Math::CoordF* viewPosition, Entities::Characters::Player* player);

        void clean();

        void explodeCoins(Math::CoordF position);

        void setRenderDistance();

        void resetToOrigin();
    };

} // namespace WorldGenerator