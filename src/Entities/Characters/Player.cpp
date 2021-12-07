#include "Entities/Characters/Player.h"
#include "GraphicalElements/Animation.h"

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
            time += dt;
            if (time < 3) {
                sprite.update(GraphicalElements::Animation_ID::walk, true, position, dt);
                position.x = position.x + 200 * dt;
            }

            else if (time < 6)
                sprite.update(GraphicalElements::Animation_ID::idle, true, position, dt);

            else
                sprite.update(GraphicalElements::Animation_ID::attack, true, position, dt);
        }

        void Player::initiallize() {
            sprite.addNewAnimation(GraphicalElements::Animation_ID::idle, "./assets/Mummy/Mummy_idle.png", 4);
            sprite.addNewAnimation(GraphicalElements::Animation_ID::walk, "./assets/Mummy/Mummy_walk.png", 6);
            sprite.addNewAnimation(GraphicalElements::Animation_ID::attack, "./assets/Mummy/Mummy_attack.png", 6);
        }

    }

}