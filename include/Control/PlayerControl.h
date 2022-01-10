#pragma once

#include "Control/Observer.h"
#include <map>

namespace Entities::Characters {
    class Player;
}

namespace Control {

    class PlayerControl : public Observer {
    private:
        Entities::Characters::Player* pPlayer;
        std::map<std::string, bool> keysPressed;
        std::string jump;
        std::string left;
        std::string right;
        std::string attack;
        std::string sprint;

    public:
        PlayerControl(Entities::Characters::Player* pP = nullptr);

        ~PlayerControl();

        void notifyPressed(std::string key);

        void notifyReleased(std::string key);

        void setPlayer(Entities::Characters::Player* p);

        void setKeys(std::string jump, std::string left, std::string right, std::string attack, std::string sprint);
    };

} // namespace Control