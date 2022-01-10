#include "Entities/Obstacles/Quicksand.h"

#define QUICKSAND_WIDTH 96.f
#define QUICKSAND_HEIGHT 32.f
#define QUICKSAND_SLOWNESS_MAX 8
#define QUICKSAND_PATH "./assets/Obstacles/Quicksand.png"

#include <stdlib.h>
#include <time.h>

namespace Entities {

    namespace Obstacles {

        Quicksand::Quicksand(Math::CoordF position) :
        StaticEntity(position, Math::CoordF(QUICKSAND_WIDTH, QUICKSAND_HEIGHT), ID::quicksand) {
            initialize();
            srand(time(NULL));
        }

        Quicksand::~Quicksand() { }

        void Quicksand::initialize() {
            sprite.initialize(QUICKSAND_PATH, position, size);
        }

        const float Quicksand::getSlowness() const {
            return (1.0 / (1 + rand() % QUICKSAND_SLOWNESS_MAX));
        }

    } // namespace Obstacles

} // namespace Entities
