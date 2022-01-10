#include "Entities/Characters/Enemies/Enemy.h"

#include "Entities/Characters/Player.h"

#include "Entities/Obstacles/Quicksand.h"

namespace Entities {

    namespace Characters {

        namespace Enemies {

            Enemy::Enemy(Math::CoordF position, Math::CoordF size, ID id, int life, Entities::Characters::Player* pP, const float atckCooldown, const float attackingTime, const unsigned int points) :
            Character(position, size, id, life, atckCooldown, attackingTime),
            pPlayer(pP),
            points(points) { }

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
                case ID::platform: {
                    moveOnCollision(intersect, otherEntity);
                    break;
                }
                case ID::player: {
                    Character* pchar = dynamic_cast<Character*>(otherEntity);
                    if (pchar != nullptr) {
                        if (isAttacking() && !pchar->isAttacking())
                            pchar->receiveDamage(getDamage());
                    }
                    break;
                }
                case ID::cactus: {
                    moveOnCollision(intersect, otherEntity);
                    break;
                }
                case ID::quicksand: {
                    Entities::Obstacles::Quicksand* pQck = dynamic_cast<Entities::Obstacles::Quicksand*>(otherEntity);
                    moveOnCollision(intersect, otherEntity);
                    velocity *= pQck->getSlowness();
                    break;
                }
                default:
                    break;
                }

                if (life < 0) {
                    active = false;
                    if (pPlayer != nullptr) {
                        pPlayer->incrementPoints(points);
                    }
                }
            }

        } // namespace Enemies

    } // namespace Characters

} // namespace Entities
