#include "Entities/Characters/Player.h"

#include "GraphicalElements/MultiFrameAnimation.h"

namespace Entities {

    namespace Characters {

        Player::Player(Math::CoordF position, bool isPlayer1) :
        Character(position, Math::CoordF(PLAYER_SIZE_X, PLAYER_SIZE_Y), ID::player, PLAYER_LIFE),
        isPlayer1(isPlayer1) {
            initialize();
            time = 0;
            velocity.x = 0;
        }

        Player::~Player() { }

        void Player::update(float dt) {
            time += dt;

            position.x += velocity.x * dt;
            velocity.y += 9.8 * dt;
            position.y += velocity.y * dt;

            facingLeft = velocity.x >= 0.0f ? true : false;

            if (abs(velocity.x)> 0) {
                sprite.update(GraphicalElements::Animation_ID::walk, isFacingLeft(), position, dt);
            }

            else 
                sprite.update(GraphicalElements::Animation_ID::idle, isFacingLeft(), position, dt);

            // else
                // sprite.update(GraphicalElements::Animation_ID::attack, isFacingLeft(), position, dt);
        }

        void Player::initialize() {
            sprite.addNewAnimation(GraphicalElements::Animation_ID::idle, "./assets/Mummy/Mummy_idle.png", 4);
            sprite.addNewAnimation(GraphicalElements::Animation_ID::walk, "./assets/Mummy/Mummy_walk.png", 6);
            sprite.addNewAnimation(GraphicalElements::Animation_ID::attack, "./assets/Mummy/Mummy_attack.png", 6);
        }

        void Player::collide(Entity* otherEntity, Math::CoordF intersect) {
            switch (otherEntity->getId()) {
            case ID::platform:
                // moveOnCollision(intersect, otherEntity->getPosition());
                moveOnCollision(intersect, otherEntity);
                break;

            default:
                break;
            }
        }

    }

}