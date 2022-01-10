#include "Entities/Obstacles/Cactus.h"

#define CACTUS_WIDTH 32.f
#define CACTUS_HEIGHT 70.f 
#define CACTUS_DAMAGE 5
#define CACTUS_PATH "./assets/Obstacles/Cactus.png"

namespace Entities {

    namespace Obstacles {

        Cactus::Cactus(Math::CoordF position) :
        StaticEntity(position, Math::CoordF(CACTUS_WIDTH, CACTUS_HEIGHT), ID::cactus) {
            initialize();
        }

        Cactus::~Cactus() { }

        void Cactus::initialize() {
            sprite.initialize(CACTUS_PATH, position, size);
        }

        unsigned int Cactus::getDamage() const {
            return CACTUS_DAMAGE;
        }

    } // namespace Obstacles

} // namespace Entities
