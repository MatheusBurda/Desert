#include "Entities/Characters/Player.h"

#include "Entities/Obstacles/Cactus.h"
#include "Entities/Obstacles/Quicksand.h"

#define PLAYER_SIZE_Y 84.0f
#define PLAYER_SIZE_X 32.0f
#define PLAYER_LIFE 50
#define PLAYER_JUMP_HEIGHT 150.0f
#define PLAYER_ATTACK_COOLDOWN 0.2f
#define PLAYER_DAMAGE_COOLDOWN 1
#define PLAYER_ATTACK_TIME 1.2f
#define PLAYER_ATTACK_DISTANCE 10.0f
#define PLAYER_VELOCITY 150.f
#define PLAYER_DAMAGE 10
#define PLAYER_PATH_IDLE "./assets/Mummy/Mummy_idle.png"
#define PLAYER_PATH_WALK "./assets/Mummy/Mummy_walk.png"
#define PLAYER_PATH_ATTACK "./assets/Mummy/Mummy_attack.png"

namespace Entities {

    namespace Characters {

        Player::Player(Math::CoordF position) :
        Character(position, Math::CoordF(PLAYER_SIZE_X + 2 * PLAYER_ATTACK_DISTANCE, PLAYER_SIZE_Y), ID::player, PLAYER_LIFE, PLAYER_ATTACK_COOLDOWN, PLAYER_ATTACK_TIME),
        pControl(this),
        canJump(false),
        sprinting(false),
        isWalking(false),
        points(0),
        swordDistance(PLAYER_ATTACK_DISTANCE) {
            initialize();
            coins = 0;
            setDamage(PLAYER_DAMAGE);
            damageCooldown = 0;
        }

        Player::~Player() {
        }

        void Player::update(const float dt) {
            Character::incrementAttackTime(dt);

            if (isWalking) {
                if (sprinting)
                    velocity.x = PLAYER_VELOCITY * 1.8;
                else
                    velocity.x = PLAYER_VELOCITY;

                if (facingLeft)
                    velocity.x *= -1;
                velocity.x *= slowness;
            } //
            else
                velocity.x *= 0.5;
            velocity.y += GRAVITY * dt;

            position.x += velocity.x * dt;
            position.y += velocity.y * dt;

            updateSprite(dt);

            damageCooldown += dt;

            if (position.y > 1000)
                active = false;
        }

        void Player::initialize() {
            sprite.addNewAnimation(GraphicalElements::Animation_ID::idle, PLAYER_PATH_IDLE, 4);
            sprite.addNewAnimation(GraphicalElements::Animation_ID::walk, PLAYER_PATH_WALK, 6);
            sprite.addNewAnimation(GraphicalElements::Animation_ID::run, PLAYER_PATH_WALK, 6, 0.1f);
            sprite.addNewAnimation(GraphicalElements::Animation_ID::attack, PLAYER_PATH_ATTACK, 6);
        }

        void Player::collide(Entity* otherEntity, Math::CoordF intersect) {
            if (otherEntity->getId() == ID::snake || otherEntity->getId() == ID::hyena) {
                Character* pchar = dynamic_cast<Character*>(otherEntity);
                if (pchar != nullptr) {
                    if (isAttacking())
                        pchar->receiveDamage(getDamage());
                }
            } //
            else if (otherEntity->getId() == ID::coin) {
                coins++;
                if (coins >= 100) {
                    coins -= 100;
                    life += 10;
                    if (life > 50)
                        life = 50;
                }
            } //
            else {
                Math::CoordF centerDistance;
                centerDistance.x = otherEntity->getPosition().x - getPosition().x;
                intersect.x = fabs(centerDistance.x) - ((getSize().x - PLAYER_ATTACK_DISTANCE * 2) / 2.0f + otherEntity->getSize().x / 2.0f);

                if (intersect.x < 0.0f && intersect.y < 0.0f) { // Condition to collide...

                    moveOnCollision(intersect, otherEntity);
                    switch (otherEntity->getId()) {
                    case ID::platform: {
                        canJump = true;
                        slowness = 1;
                        break;
                    }

                    case ID::cactus: {
                        Entities::Obstacles::Cactus* pCactus = dynamic_cast<Entities::Obstacles::Cactus*>(otherEntity);
                        if (pCactus)
                            receiveDamage(pCactus->getDamage());
                        break;
                    }
                    case ID::quicksand: {
                        canJump = true;
                        Entities::Obstacles::Quicksand* pQck = dynamic_cast<Entities::Obstacles::Quicksand*>(otherEntity);
                        if (pQck)
                            slowness = pQck->getSlowness();
                        break;
                    }
                    default:
                        break;
                    }
                }
            }
            if (life < 0)
                active = false;
        }

        void Player::updateSprite(const float dt) {
            if (isAttacking())
                sprite.update(GraphicalElements::Animation_ID::attack, isFacingLeft(), position, dt);

            else if (isWalking) {
                if (sprinting && slowness == 1)
                    sprite.update(GraphicalElements::Animation_ID::run, isFacingLeft(), position, dt);
                else
                    sprite.update(GraphicalElements::Animation_ID::walk, isFacingLeft(), position, dt);
            }

            else
                sprite.update(GraphicalElements::Animation_ID::idle, isFacingLeft(), position, dt);
        }

        void Player::jump() {
            if (canJump) {
                velocity.y = -sqrtf(2.0f * GRAVITY * PLAYER_JUMP_HEIGHT) * slowness;
                canJump = false;
            }
        }

        void Player::walk(bool toLeft) {
            isWalking = true;
            setFacingLeft(toLeft);
        }

        void Player::stopWalking() {
            isWalking = false;
        }

        unsigned int Player::getPlayerPoints() const {
            return points;
        }

        void Player::incrementPoints(unsigned int points) {
            this->points += points;
        }

        unsigned int Player::getCoins() const {
            return coins;
        }

        void Player::setIsSprinting(const bool option) {
            sprinting = option;
        }

        const float Player::getSwordDistance() const {
            return swordDistance;
        }

        void Player::receiveDamage(const int damage) {
            if (damageCooldown > PLAYER_DAMAGE_COOLDOWN) {
                life -= damage;
                if (life <= 0)
                    active = false;
                damageCooldown = 0;
            }
        }
    }
}
