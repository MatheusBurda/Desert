#include "Control/PlayerControl.h"

#include "Entities/Characters/Player.h"

namespace Control {

    PlayerControl::PlayerControl(Entities::Characters::Player* pP) :
    Observer(),
    pPlayer(pP),
    keysPressed(),
    jump("W"),
    left("A"),
    right("D"),
    attack("Space"),
    sprint("Shift") {
        keysPressed.insert(std::pair<std::string, bool>(jump, false));
        keysPressed.insert(std::pair<std::string, bool>(attack, false));
        keysPressed.insert(std::pair<std::string, bool>(sprint, false));
        keysPressed.insert(std::pair<std::string, bool>(right, false));
        keysPressed.insert(std::pair<std::string, bool>(left, false));
    }

    PlayerControl::~PlayerControl() {
        pPlayer = nullptr;
    }

    void PlayerControl::notifyPressed(std::string key) {
        if (pPlayer == nullptr) {
            std::cout << "ERROR: pointer to player nullptr on PlayerControl::notify()." << std::endl;
            exit(7);
        }

        if (key == attack) {
            keysPressed[attack] = true;
            pPlayer->attack();
        }

        else if (key == jump) {
            keysPressed[jump] = true;
            pPlayer->jump();
        }

        else if (key == right) {
            keysPressed[right] = true;
            pPlayer->walk(false);
        }

        else if (key == left) {
            keysPressed[left] = true;
            pPlayer->walk(true);
        }

        else if (key == sprint) {
            keysPressed[sprint] = true;
            pPlayer->setIsSprinting(true);
        }
    }

    void PlayerControl::notifyReleased(std::string key) {
        if (pPlayer == nullptr) {
            std::cout << "ERROR: pointer to player nullptr on PlayerControl::notify()." << std::endl;
            exit(7);
        }

        if(key == attack) {
            keysPressed[attack] = false;
        }

        else if (key == jump) {
            keysPressed[jump] = false;
        }

        else if (key == right) {
            keysPressed[right] = false;
            pPlayer->stopWalking();
        }

        else if (key == left) {
            keysPressed[left] = false;
            pPlayer->stopWalking();
        }

        else if (key == sprint) {
            keysPressed[sprint] = false;
            pPlayer->setIsSprinting(false);
        }
    }

    void PlayerControl::setPlayer(Entities::Characters::Player* p) {
        pPlayer = p;
    }

    void PlayerControl::setKeys(std::string jump, std::string left, std::string right, std::string attack, std::string sprint) {
        this->jump = jump;
        this->left = left;
        this->right = right;
        this->attack = attack;
    }

} // namespace Control