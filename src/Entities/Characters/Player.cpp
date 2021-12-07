#include "Entities/Characters/Player.h"
#include "GraphicalElements/Animation.h"

namespace Entities {

    namespace Characters {

        Player::Player(Math::CoordF position, bool isPlayer1) :
        Entity(position, Math::CoordF(PLAYER_SIZE_X, PLAYER_SIZE_Y), ID::player),
        isPlayer1(isPlayer1) {
            initiallize();
        }

        Player::~Player() { }

        void Player::update(float dt) {
            sprite.update(GraphicalElements::Animation_ID::walk, true, position, dt);
            position.x = position.x + 300 * dt;
        }

        void Player::initiallize() {
            /* sprite.addNewAnimation(GraphicalElements::Animation_ID::idle, "./assets/Mummy/Mummy_idle.png", 4);
            sprite.addNewAnimation(GraphicalElements::Animation_ID::walk, "./assets/Mummy/Mummy_walk.png", 6);
            sprite.addNewAnimation(GraphicalElements::Animation_ID::attack, "./assets/Mummy/Mummy_attack.png", 6); */
            /* sprite.addNewAnimation(GraphicalElements::Animation_ID::idle, "./assets/Snake/Snake_idle.png", 4);
            sprite.addNewAnimation(GraphicalElements::Animation_ID::walk, "./assets/Snake/Snake_walk.png", 4);
            sprite.addNewAnimation(GraphicalElements::Animation_ID::attack, "./assets/Snake/Snake_attack.png", 6); */
            sprite.addNewAnimation(GraphicalElements::Animation_ID::idle, "./assets/Hyena/Hyena_idle.png", 4);
            sprite.addNewAnimation(GraphicalElements::Animation_ID::walk, "./assets/Hyena/Hyena_walk.png", 6);
            sprite.addNewAnimation(GraphicalElements::Animation_ID::attack, "./assets/Hyena/Hyena_attack.png", 6);
        }

    }

}