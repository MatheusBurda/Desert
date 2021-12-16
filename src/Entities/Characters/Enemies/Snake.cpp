#include "Entities/Characters/Enemies/Snake.h"

namespace Entities {

    namespace Characters {

        namespace Enemies {

            Snake::Snake(Math::CoordF position, Entities::Characters::Player* pP) :
            Enemy(position, Math::CoordF(SNAKE_SIZE_X, SNAKE_SIZE_Y), ID::snake, SNAKE_LIFE, pP) {
                initialize();
            }

            Snake::~Snake() { }

            void Snake::update(const float dt) {

                position.x += velocity.x * dt;
                velocity.y += 900.8 * dt;
                position.y += velocity.y * dt;

                updateSprite(dt);
            }

            void Snake::initialize() {
                sprite.addNewAnimation(GraphicalElements::Animation_ID::idle, "./assets/Snake/Snake_idle.png", 4);
                sprite.addNewAnimation(GraphicalElements::Animation_ID::walk, "./assets/Snake/Snake_walk.png", 4);
                sprite.addNewAnimation(GraphicalElements::Animation_ID::attack, "./assets/Snake/Snake_attack.png", 6);
            }

            void Snake::collide(Entity* otherEntity, Math::CoordF intersect) {
                switch (otherEntity->getId()) {
                case ID::platform:
                    moveOnCollision(intersect, otherEntity);
                    break;
                case ID::player:
                    std::cout << "Cobra colidiu com player" << std::endl;
                    break;
                default:
                    break;
                }
            }

            void Snake::updateSprite(const float dt) {
                // if(isAtacking())
                // sprite.update(GraphicalElements::Animation_ID::attack, isFacingLeft(), position, dt);

                if (fabs(velocity.x) > 0)
                    sprite.update(GraphicalElements::Animation_ID::walk, isFacingLeft(), position, dt);

                else
                    sprite.update(GraphicalElements::Animation_ID::idle, isFacingLeft(), position, dt);
            }

        } // namespace Enemies

    } // namespace Characters

} // namespace Entities