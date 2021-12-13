#include "Entities/Characters/Player.h"
#include "GraphicalElements/MultiFrameAnimation.h"

namespace Entities {

    namespace Characters {

        Player::Player(Math::CoordF position, bool isPlayer1) :
        Entity(position, Math::CoordF(PLAYER_SIZE_X, PLAYER_SIZE_Y), ID::player),
        isPlayer1(isPlayer1) {
            initiallize();
            time = 0;
        }

        Player::~Player() { }

        void Player::update(float dt) {
            GraphicalElements::MultiFrameAnimation* multiSprite = static_cast<GraphicalElements::MultiFrameAnimation*> (sprite);
            time += dt;
            if (time < 3) {
                multiSprite->update(GraphicalElements::Animation_ID::walk, true, position, dt);
                position.x = position.x + 200 * dt;
            }

            else if (time < 6)
                multiSprite->update(GraphicalElements::Animation_ID::idle, true, position, dt);

            else
                multiSprite->update(GraphicalElements::Animation_ID::attack, true, position, dt);
        }

        void Player::initiallize() {
            sprite = new GraphicalElements::MultiFrameAnimation();

            GraphicalElements::MultiFrameAnimation* multiSprite = static_cast<GraphicalElements::MultiFrameAnimation*> (sprite);
            multiSprite->addNewAnimation(GraphicalElements::Animation_ID::idle, "./assets/Mummy/Mummy_idle.png", 4);
            multiSprite->addNewAnimation(GraphicalElements::Animation_ID::walk, "./assets/Mummy/Mummy_walk.png", 6);
            multiSprite->addNewAnimation(GraphicalElements::Animation_ID::attack, "./assets/Mummy/Mummy_attack.png", 6);
        }

    }

}