#include "Entities/Characters/Player.h"
#include "Managers/Animation.h"

namespace Entities {

    namespace Characters {

        Player::Player(Math::CoordF position, bool isPlayer1) :
        Entity(position, Math::CoordF(PLAYER_SIZE_X, PLAYER_SIZE_Y), ID::player),
        isPlayer1(isPlayer1) {
            initiallize();
        }

        Player::~Player() { }

        void Player::update(float dt) {
            sprite.update(Managers::Animation_ID::attack, false, position, dt);
        }

        void Player::initiallize() {
            sprite.addNewAnimation(Managers::Animation_ID::idle, "./assets/Mummy/Mummy_idle.png", 4);
            sprite.addNewAnimation(Managers::Animation_ID::walk, "./assets/Mummy/Mummy_walk.png", 6);
            sprite.addNewAnimation(Managers::Animation_ID::attack, "./assets/Mummy/Mummy_attack.png", 6);
        }

    }

}