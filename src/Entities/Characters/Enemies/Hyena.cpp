#include "Entities/Characters/Enemies/Hyena.h"

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
                sprite.addNewAnimation(GraphicalElements::Animation_ID::idle, "./assets/Hyena/Hyena_idle.png", 4);
                sprite.addNewAnimation(GraphicalElements::Animation_ID::walk, "./assets/Hyena/Hyena_walk.png", 6);
                sprite.addNewAnimation(GraphicalElements::Animation_ID::attack, "./assets/Hyena/Hyena_attack.png", 6);
            }

            void Hyena::collide(Entity* otherEntity, Math::CoordF intersect) {
                switch (otherEntity->getId()) {
                case ID::platform:
                    moveOnCollision(intersect, otherEntity);
                    break;
                case ID::player:
                    std::cout << "Heyna colidiu com player" << std::endl;
                    break;
                default:
                    break;
                }
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
