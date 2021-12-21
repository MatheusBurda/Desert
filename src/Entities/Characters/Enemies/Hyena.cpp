#include "Entities/Characters/Enemies/Hyena.h"

#define HYENA_SIZE_X 65
#define HYENA_SIZE_Y 50
#define HYENA_LIFE 50

namespace Entities {

    namespace Characters {

        namespace Enemies {

            Hyena::Hyena(Math::CoordF position, Entities::Characters::Player* pP) :
            Enemy(position, Math::CoordF(HYENA_SIZE_X, HYENA_SIZE_Y), ID::hyena, HYENA_LIFE, pP) {
                initialize();
            }

            Hyena::~Hyena() { }

            void Hyena::update(const float dt) {

                position.x += velocity.x * dt;
                velocity.y += 900.8 * dt;
                position.y += velocity.y * dt;

                updateSprite(dt);
            }

            void Hyena::initialize() {
                sprite.setSwitchTime(0.1f);

                sprite.addNewAnimation(GraphicalElements::Animation_ID::idle, "./assets/Hyena/Hyena_idle.png", 4);
                sprite.addNewAnimation(GraphicalElements::Animation_ID::walk, "./assets/Hyena/Hyena_walk.png", 6);
                sprite.addNewAnimation(GraphicalElements::Animation_ID::attack, "./assets/Hyena/Hyena_attack.png", 6);
            }

            void Hyena::updateSprite(const float dt) {
                // if (canAttack())
                //     sprite.update(GraphicalElements::Animation_ID::attack, isFacingLeft(), position, dt);

                 if (fabs(velocity.x) > 0)
                    sprite.update(GraphicalElements::Animation_ID::walk, isFacingLeft(), position, dt);

                else
                    sprite.update(GraphicalElements::Animation_ID::idle, isFacingLeft(), position, dt);
            }

        } // namespace Enemies

    } // namespace Characters

} // namespace Entities