#include "Entities/Characters/Enemies/Hyena.h"

#define HYENA_SIZE_X 60
#define HYENA_SIZE_Y 56
#define HYENA_LIFE 20
#define HYENA_PATH_IDLE "./assets/Hyena/Hyena_idle.png"
#define HYENA_PATH_WALK "./assets/Hyena/Hyena_walk.png"
#define HYENA_PATH_ATTACK "./assets/Hyena/Hyena_attack2.png"
#define HYENA_ATTACK_DISTANCE 30.0f
#define HYENA_FOLLOW_DISTANCE 1000.f
#define HYENA_MAX_VELOCITY_X 300.f
#define HYENA_ACCELERATION 300.f
#define HYENA_DEACCELERATION 100.f
#define HYENA_ATTACK_COOLDOWN 0.3f
#define HYENA_ATTACK_TIME 0.6f
#define HYENA_DAMAGE 5

namespace Entities {

    namespace Characters {

        namespace Enemies {

            Hyena::Hyena(Math::CoordF position, Entities::Characters::Player* pP) :
            Enemy(position, Math::CoordF(HYENA_SIZE_X, HYENA_SIZE_Y), ID::hyena, HYENA_LIFE, pP, HYENA_ATTACK_COOLDOWN, HYENA_ATTACK_TIME) {
                initialize();
                this->acceleration = 0;
                setDamage(HYENA_DAMAGE);
            }

            Hyena::~Hyena() { }

            void Hyena::update(const float dt) {
                Character::incrementAttackTime(dt);

                playerDistance = getPlayerPosition().x - position.x;

                if (fabs(playerDistance) < HYENA_FOLLOW_DISTANCE) {
                    if (playerDistance >= 0) {
                        if (isFacingLeft()) {
                            if (velocity.x < 0)
                                velocity.x += HYENA_DEACCELERATION * dt;
                            else
                                velocity.x = 0;
                        }
                        if (velocity.x < HYENA_MAX_VELOCITY_X)
                            velocity.x += HYENA_ACCELERATION * dt;
                        else
                            velocity.x = HYENA_MAX_VELOCITY_X;
                        setFacingLeft(false);
                    } //
                    else {
                        if (!isFacingLeft()) {
                            if (velocity.x > 0)
                                velocity.x -= HYENA_DEACCELERATION * dt;
                            else
                                velocity.x = 0;
                        }
                        if (velocity.x > -HYENA_MAX_VELOCITY_X)
                            velocity.x -= HYENA_ACCELERATION * dt;
                        else
                            velocity.x = -HYENA_MAX_VELOCITY_X;

                        setFacingLeft(true);
                    }
                } //
                else {
                    velocity.x = 0;
                }

                if (fabs(playerDistance) < HYENA_ATTACK_DISTANCE && Character::canAttack()) {
                    Character::attack();
                }

                velocity.y += GRAVITY * dt;
                position.y += velocity.y * dt;

                position.x += velocity.x * dt;

                updateSprite(dt);
            }

            void Hyena::initialize() {
                sprite.addNewAnimation(GraphicalElements::Animation_ID::idle, "./assets/Hyena/Hyena_idle.png", 4);
                sprite.addNewAnimation(GraphicalElements::Animation_ID::walk, "./assets/Hyena/Hyena_walk.png", 6, 0.1);
                sprite.addNewAnimation(GraphicalElements::Animation_ID::attack, "./assets/Hyena/Hyena_attack.png", 6, 0.1);
            }

            void Hyena::updateSprite(const float dt) {

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
