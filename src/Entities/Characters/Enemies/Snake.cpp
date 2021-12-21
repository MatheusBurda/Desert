#include "Entities/Characters/Enemies/Snake.h"

#define SNAKE_SIZE_X 60
#define SNAKE_SIZE_Y 26
#define SNAKE_LIFE 50

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
                sprite.setSwitchTime(0.3);
                
                sprite.addNewAnimation(GraphicalElements::Animation_ID::idle, "./assets/Snake/Snake_idle_2.png", 4);
                sprite.addNewAnimation(GraphicalElements::Animation_ID::walk, "./assets/Snake/Snake_walk.png", 4);
                sprite.addNewAnimation(GraphicalElements::Animation_ID::attack, "./assets/Snake/Snake_attack.png", 6);
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