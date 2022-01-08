#include "Entities/Characters/Enemies/Enemy.h"

#include "Entities/Characters/Player.h"

namespace Entities {

    namespace Characters {

        namespace Enemies {

            Enemy::Enemy(Math::CoordF position, Math::CoordF size, ID id, int life, Entities::Characters::Player* pP, const float atckCooldown) :
            Character(position, size, id, life, atckCooldown),
            pPlayer(pP) {
            }

            Enemy::~Enemy() {
                pPlayer = nullptr;
            }

            Math::CoordF Enemy::getPlayerPosition() {
                if (pPlayer == nullptr) {
                    std::cout << "ERROR: Pointer to Player nullptr on Enemy::getPlayerPosition." << std::endl;
                    exit(1);
                }
                return pPlayer->getPosition();
            }

            void Enemy::setpPlayer(Entities::Characters::Player* pP) {
                if (pP == nullptr) {
                    std::cout << "ERROR: Pointer to Player nullptr on Enemy::setpPlayer." << std::endl;
                    return;
                }
                pPlayer = pP;
            }

            void Enemy::collide(Entity* otherEntity, Math::CoordF intersect) {
                switch (otherEntity->getId()) {
                case ID::platform:
                    moveOnCollision(intersect, otherEntity);
                    break;
                case ID::player:
                    //std::cout << "Inimigo colidiu com player" << std::endl;
                    active = false;
                    break;
                default:
                    break;
                }
            }

        } // namespace Enemies

    } // namespace Characters

} // namespace Entities
