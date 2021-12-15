#include "Entities/Characters/Enemies/Enemy.h"

#include "Entities/Characters/Player.h"

namespace Entities {

    namespace Characters {

        namespace Enemies {

            Enemy::Enemy(Math::CoordF position, Math::CoordF size, ID id, int life, Entities::Characters::Player* pP1, Entities::Characters::Player* pP2) :
            Character(position, size, id, life),
            pPlayer1(pP1),
            pPlayer2(pP2){
    
            }

            Enemy::~Enemy() {
            }

        } // namespace Enemies

    } // namespace Characters

} // namespace Entities
