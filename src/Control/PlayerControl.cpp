#include "Control/PlayerControl.h"

#include "Entities/Characters/Player.h"

namespace Control {

    PlayerControl::PlayerControl(Entities::Characters::Player* pP) :
    Observer(),
    pPlayer(pP),
    jump("W"),
    left("A"),
    right("D"),
    attack("Space") { }

    PlayerControl::~PlayerControl() {
        pPlayer = nullptr;
    }

    void PlayerControl::notifyPressed(std::string key) {
        if (pPlayer == nullptr) {
            std::cout << "ERROR: pointer to player nullptr on PlayerControl::notify()." << std::endl;
            exit(7);
        }

        if (key == attack)
            pPlayer->attack();

        if (key == jump)
            pPlayer->jump();

        if (key == right)
            pPlayer->walk(false);

        if (key == left)
            pPlayer->walk(true);
    }

    void PlayerControl::notifyReleased(std::string key) {
        if (pPlayer == nullptr) {
            std::cout << "ERROR: pointer to player nullptr on PlayerControl::notify()." << std::endl;
            exit(7);
        }

        if (key == right || key == left)
            pPlayer->stopWalking();
    }

    void PlayerControl::setPlayer(Entities::Characters::Player* p) {
        pPlayer = p;
    }

    void PlayerControl::setKeys(std::string jump, std::string left, std::string right, std::string attack) {
        this->jump = jump;
        this->left = left;
        this->right = right;
        this->attack = attack;
    }

} // namespace Control