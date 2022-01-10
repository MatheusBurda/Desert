#include "Entities/Characters/Enemies/Snake.h"

#define SNAKE_SIZE_X 60
#define SNAKE_SIZE_Y 26
#define SNAKE_LIFE 10
#define SNAKE_PATH_IDLE "./assets/Snake/Snake_idle.png"
#define SNAKE_PATH_WALK "./assets/Snake/Snake_walk.png"
#define SNAKE_PATH_ATTACK "./assets/Snake/Snake_attack.png"
#define SNAKE_ATTACK_DISTANCE 200.0f
#define SNAKE_VELOCITY_X 200.f
#define SNAKE_JUMP_HEIGHT 70.f
#define SNAKE_SWITCHTIME 0.2
#define SNAKE_DAMAGE 10

namespace Entities {

    namespace Characters {

        namespace Enemies {

            Snake::Snake(Math::CoordF position, Entities::Characters::Player* pP) :
            Enemy(position, Math::CoordF(SNAKE_SIZE_X, SNAKE_SIZE_Y), ID::snake, SNAKE_LIFE, pP, 4 * SNAKE_SWITCHTIME, 4 * SNAKE_SWITCHTIME) {
                initialize();
                setDamage(SNAKE_DAMAGE);
            }

            Snake::~Snake() { }

            void Snake::update(const float dt) {

                Character::incrementAttackTime(dt);

                playerDistance = getPlayerPosition().x - position.x;

                MovingEntity::setFacingLeft(playerDistance <= 0);

                if (!Character::isAttacking()) {

                    velocity.x *= 0.1;

                    if (Character::canAttack() && (fabs(playerDistance) < SNAKE_ATTACK_DISTANCE)) {
                        velocity.y = -sqrtf(2.0f * GRAVITY * SNAKE_JUMP_HEIGHT);

                        if (playerDistance < 0)
                            velocity.x = -1 * SNAKE_VELOCITY_X;
                        else
                            velocity.x = SNAKE_VELOCITY_X;

                        Character::attack();
                    }
                }

                velocity.y += GRAVITY * dt;
                position.y += velocity.y * dt;
                position.x += velocity.x * dt;

                updateSprite(dt);
            }

            void Snake::initialize() {
                sprite.addNewAnimation(GraphicalElements::Animation_ID::idle, SNAKE_PATH_IDLE, 4);
                sprite.addNewAnimation(GraphicalElements::Animation_ID::walk, SNAKE_PATH_WALK, 4);
                sprite.addNewAnimation(GraphicalElements::Animation_ID::attack, SNAKE_PATH_ATTACK, 4);
            }

            void Snake::updateSprite(const float dt) {
                if (isAttacking())
                    sprite.update(GraphicalElements::Animation_ID::attack, isFacingLeft(), position, dt);

                else if (fabs(velocity.x) > 0)
                    sprite.update(GraphicalElements::Animation_ID::walk, isFacingLeft(), position, dt);

                else
                    sprite.update(GraphicalElements::Animation_ID::idle, isFacingLeft(), position, dt);
            }

        } // namespace Enemies

    } // namespace Characters

} // namespace Entities