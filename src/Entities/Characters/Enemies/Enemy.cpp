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

            void Enemy::receiveDamage(const int damage) {
                life -= damage;
                if (life <= 0) {
                    active = false;
                    if (pPlayer != nullptr) {
                        pPlayer->incrementPoints(points);
                    }
                }
            }

            void Enemy::collide(Entity* otherEntity, Math::CoordF intersect) {
                switch (otherEntity->getId()) {
                case ID::platform: {
                    moveOnCollision(intersect, otherEntity);
                    break;
                }
                case ID::player: {
                    
                    if (pPlayer != nullptr) {
                        Math::CoordF centerDistance;
                        centerDistance.x = otherEntity->getPosition().x - getPosition().x;
                        intersect.x = fabs(centerDistance.x) - ((getSize().x - pPlayer->getSwordDistance() * 2) / 2.0f + otherEntity->getSize().x / 2.0f);

                        if (intersect.x < 0.0f && intersect.y < 0.0f) { // Condition to collide...
                            if (isAttacking())
                                pPlayer->receiveDamage(getDamage());
                        }
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
            }

        } // namespace Enemies

    } // namespace Characters

} // namespace Entities
