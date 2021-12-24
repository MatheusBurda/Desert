#pragma once

#include "Control/Observer.h"

namespace Entities {
    namespace Characters {
        class Player;
    }
}

namespace Control {

    class PlayerControl : public Observer {
    private:
        Entities::Characters::Player* pPlayer;
        std::string jump;
        std::string left;
        std::string right;
        std::string attack;

    public:
        PlayerControl(Entities::Characters::Player* pP = NULL);

        ~PlayerControl();

        void notifyPressed(std::string key);

        void notifyReleased(std::string key);

        void setPlayer(Entities::Characters::Player* p);

        void setKeys(std::string jump, std::string left, std::string right, std::string attack);
    };

} // namespace Control