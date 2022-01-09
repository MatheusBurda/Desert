#include "Entities/Characters/Player.h"

#define PLAYER_SIZE_Y 84.0f
#define PLAYER_SIZE_X 32.0f
#define PLAYER_LIFE 50
#define PLAYER_JUMP_HEIGHT 100.0f
#define PLAYER_ATTACK_COOLDOWN 1.2f
#define PLAYER_VELOCITY 150.f

namespace Entities {

    namespace Characters {

        Player::Player(Math::CoordF position) :
        Character(position, Math::CoordF(PLAYER_SIZE_X, PLAYER_SIZE_Y), ID::player, PLAYER_LIFE, PLAYER_ATTACK_COOLDOWN),
        pControl(this),
        canJump(false),
        isWalking(false),
        points(0) {
            initialize();
            coins = 85;
        }

        Player::~Player() {
        }

        void Player::update(const float dt) {
            Character::incrementAttackTime(dt);

            isWalking ? velocity.x : velocity.x *= 0.9;
            velocity.y += GRAVITY * dt;

            position.x += velocity.x * dt;
            position.y += velocity.y * dt;

            updateSprite(dt);
        }

        void Player::initialize() {
            sprite.addNewAnimation(GraphicalElements::Animation_ID::idle, "./assets/Mummy/Mummy_idle.png", 4);
            sprite.addNewAnimation(GraphicalElements::Animation_ID::walk, "./assets/Mummy/Mummy_walk.png", 6);
            sprite.addNewAnimation(GraphicalElements::Animation_ID::attack, "./assets/Mummy/Mummy_attack.png", 6);
        }

        void Player::collide(Entity* otherEntity, Math::CoordF intersect) {
            switch (otherEntity->getId()) {
            case ID::platform:
                moveOnCollision(intersect, otherEntity);
                canJump = true;
                break;
            case ID::snake: {
                Character* pchar = dynamic_cast<Character*>(otherEntity);
                if (pchar != nullptr) {
                    if (pchar->isAttacking())
                        life -= 5;
                }
                if (isAttacking())
                    points += 100;
                break;
            }
            case ID::hyena: {
                life -= 30;
                Character* pchar = dynamic_cast<Character*>(otherEntity);
                if (pchar != nullptr) {
                    if (pchar->isAttacking())
                        life -= 30;
                }
                if (isAttacking())
                    points += 200;
                break;
            }
            case ID::coin: {
                coins++;
                if (coins >= 100) {
                    coins -= 100;
                    life += 10;
                    if (life > 50)
                        life = 50;
                }
            }
            default:
                break;
            }
        }

        void Player::updateSprite(const float dt) {
            if (isAttacking())
                sprite.update(GraphicalElements::Animation_ID::attack, isFacingLeft(), position, dt);

            else if (isWalking)
                sprite.update(GraphicalElements::Animation_ID::walk, isFacingLeft(), position, dt);

            else
                sprite.update(GraphicalElements::Animation_ID::idle, isFacingLeft(), position, dt);
        }

        void Player::jump() {
            if (canJump) {
                velocity.y = -sqrtf(2.0f * GRAVITY * PLAYER_JUMP_HEIGHT);
                canJump = false;
            }
        }

        void Player::walk(bool toLeft) {
            isWalking = true;
            if (toLeft)
                velocity.x = -PLAYER_VELOCITY;
            else
                velocity.x = PLAYER_VELOCITY;

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

    }

}
