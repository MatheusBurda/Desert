#include "Entities/Loot/Coin.h"

#define COIN_SIZE_WIDTH 30
#define COIN_SIZE_HEIGHT 30
#define COIN_PATH "./assets/etc/Coin.png"

namespace Entities {

    namespace Loot {

        Coin::Coin(Math::CoordF position, Math::CoordF velocity) :
        MovingEntity(position, Math::CoordF(COIN_SIZE_WIDTH, COIN_SIZE_HEIGHT), ID::coin, velocity) {
            initialize();
        }

        Coin::~Coin() {
        }

        void Coin::update(const float dt) {
            velocity.y += GRAVITY * dt;

            position.x += velocity.x * dt;
            position.y += velocity.y * dt;

            updateSprite(dt);
        }

        void Coin::initialize() {
            sprite.addNewAnimation(GraphicalElements::Animation_ID::idle, COIN_PATH, 8);
        }

        void Coin::collide(Entity* otherEntity, Math::CoordF intersect) {
            switch (otherEntity->getId()) {
            case ID::platform: {
                float veloY = -0.5 * velocity.y;
                moveOnCollision(intersect, otherEntity);
                velocity.y = veloY;
                break;
            }
            case ID::player:
                active = false;
                break;
            default:
                break;
            }
        }
        void Coin::updateSprite(const float dt) {
            sprite.update(GraphicalElements::Animation_ID::idle, true, position, dt);
        }

    } // namespace Loot

} // namespace Entities
