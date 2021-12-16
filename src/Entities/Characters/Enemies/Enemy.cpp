#include "Entities/Characters/Enemies/Enemy.h"

#include "Entities/Characters/Player.h"

namespace Entities {

    namespace Characters {

        namespace Enemies {

            Enemy::Enemy(Math::CoordF position, Math::CoordF size, ID id, int life, Entities::Characters::Player* pP) :
            Character(position, size, id, life),
            pPlayer(pP) {
            }

            Enemy::~Enemy() {
                pPlayer = NULL;
            }

            Math::CoordF Enemy::getPlayerPosition(){
                if (pPlayer == NULL) {
                    std::cout << "ERROR: Pointer to Player NULL on Enemy::getPlayerPosition." << std::endl;
                    return;
                }
                return pPlayer->getPosition();
            }

            void Enemy::setpPlayer(Entities::Characters::Player* pP) {
                if (pP == NULL) {
                    std::cout << "ERROR: Pointer to Player NULL on Enemy::setpPlayer." << std::endl;
                    return;
                }
                pPlayer = pP;
            }

        } // namespace Enemies

    } // namespace Characters

} // namespace Entities
