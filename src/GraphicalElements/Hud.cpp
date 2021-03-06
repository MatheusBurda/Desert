#include "GraphicalElements/Hud.h"

#include "Entities/Characters/Player.h"

#include <string>

namespace GraphicalElements {

    Hud::Hud(Entities::Characters::Player* pPlayer) :
    Ent(),
    points(),
    pPlayer(pPlayer),
    pGraphicM(Managers::Graphics::getInstance()),
    coin(),
    coinsText() {
        allHeart = new GraphicalElements::Heart[5];

        initialize();
    }

    Hud::~Hud() {
        // delete (allHeart);
    }

    void Hud::render() {
        points.render();
        for (int i = 0; i < 5; i++)
            allHeart[i].render();
        coin.render();
        coinsText.render();
    }

    void Hud::update(const float dt) {
        updatePlayerPoints();

        position = pGraphicM->getTopLeftPosition();
        points.setPosition(Math::CoordF(position.x + 5, position.y));

        updateHearts();

        updateCoins(dt);
    }

    void Hud::initialize() {
        points.setTextInfo("000000");
        points.setTextColor(255, 255, 255);
        points.setFontSize(30);
    }

    void Hud::updatePlayerPoints() {
        if (pPlayer == nullptr) {
            std::cout << "Pointer to player NULL on Hud::updatePlayerPoints" << std::endl;
            exit(1);
        }

        int playerPoints = pPlayer->getPlayerPoints();

        std::string pointsString = std::to_string(playerPoints / 1000000);
        playerPoints %= 1000000;

        pointsString += std::to_string(playerPoints / 100000);
        playerPoints %= 100000;

        pointsString += std::to_string(playerPoints / 10000);
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

    void Hud::updateHearts() {
        int playerHealth = pPlayer->getLife();

        for (int i = 0; i < 5; i++) {
            if (playerHealth / 10 >= 1) {
                allHeart[i].update(HeartID::full, Math::CoordF(position.x + 5 + 1 * i + HEART_SIZE_X * i, position.y + points.getSize().y + 17));
                playerHealth -= 10;
            }

            else if (playerHealth % 10 == 5) {
                allHeart[i].update(HeartID::half, Math::CoordF(position.x + 5 + 1 * i + HEART_SIZE_X * i, position.y + points.getSize().y + 17));
                playerHealth -= 5;
            }

            else {
                allHeart[i].update(HeartID::empty, Math::CoordF(position.x + 5 + 1 * i + HEART_SIZE_X * i, position.y + points.getSize().y + 17));
            }
        }
    }

    void Hud::updateCoins(const float dt) {
        coin.update(Math::CoordF(position.x + 5, position.y + points.getSize().y + 17 + HEART_SIZE_Y), dt);

        coinsText.setPosition(Math::CoordF(position.x + 35, position.y + points.getSize().y + 17 + HEART_SIZE_Y));

        std::string coinsString = "x";

        unsigned int coins = pPlayer->getCoins();

        coinsString += std::to_string(coins);

        coinsText.setTextInfo(coinsString);
    }

    void Hud::setPlayer(Entities::Characters::Player* pPlayer){
        this->pPlayer = pPlayer;
    }

} // namespace GraphicalElements
