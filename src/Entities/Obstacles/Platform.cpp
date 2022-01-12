#include "Entities/Obstacles/Platform.h"

#define PLATFORM_PATH "./assets/Obstacles/Platform.png"

namespace Entities {

    namespace Obstacles {

        Platform::Platform(Math::CoordF position) :
        StaticEntity(position, Math::CoordF(PLATFORM_WIDTH, PLATFORM_HEIGHT), ID::platform) {
            initialize();
        }

        Platform::~Platform() {
        }

        void Platform::update(const float dt) {
            sprite.update(position);
        }

        void Platform::initialize() {
            sprite.initialize(PLATFORM_PATH, position, Math::CoordF(PLATFORM_WIDTH, PLATFORM_HEIGHT));
        }

        void Platform::collide(Entity* otherEntity, Math::CoordF intersect) { }

    } // namespace Obstacles

} // namespace Entities
