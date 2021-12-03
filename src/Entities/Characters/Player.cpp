#include "Entities/Characters/Player.h"

namespace Entities {

    namespace Characters {

        Player::Player(Math::CoordF position, bool isPlayer1) :
        Entity(position, Math::CoordF(PLAYER_SIZE_X, PLAYER_SIZE_Y), ID::player),
        isPlayer1(isPlayer1) { }

        Player::~Player() { }

        void Player::update(float dt) { }

        void Player::initiallize() { 
            exit(1);
        }

    }

}