#include "GraphicalElements/Hud.h"

#include "Entities/Characters/Player.h"

#include <string>

namespace GraphicalElements {

    Hud::Hud(Entities::Characters::Player* pPlayer) :
    points(Math::CoordF(500, 700), "00000") {
        initialize();
    }

    Hud::~Hud() { }

    void Hud::render() {
        points.render();
    }

    void Hud::update(const float dt) {
        if (pPlayer == nullptr) {
            std::cout << "Pointer to player NULL on Hud::update" << std::endl;
            exit(1);
        }
        updatePlayerPoints();
    }

    void Hud::initialize() {
        points.setTextInfo("00000");
        points.setTextColor(255, 255, 255);
        points.setFontSize(24);
        points.setPosition(Math::CoordF(300, 100));
    }

    void Hud::updatePlayerPoints() {
        int playerPoints = pPlayer->getPlayerPoints();

        // std::cout << playerPoints << std::endl;
        std::string pointsString = std::to_string(playerPoints / 10000);
        playerPoints %= 10000;

        pointsString += std::to_string(playerPoints / 1000);
        playerPoints %= 1000;

        pointsString += std::to_string(playerPoints / 100);
        playerPoints %= 100;

        pointsString += std::to_string(playerPoints / 10);
        playerPoints %= 10;

        pointsString += std::to_string(playerPoints);

        points.setTextInfo(pointsString);
    }

    void centerHud(Math::CoordF position){

    }

} // namespace GraphicalElements
