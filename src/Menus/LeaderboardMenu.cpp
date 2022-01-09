#include "Menus/LeaderboardMenu.h"

#include <fstream>

#define BACKGROUND "./assets/Backgrounds/MainMenuBackground.png"
#define LEADERBOARD_PATH "./saves/Leaderboard.txt"
#define LEADERBOARD_FONT_PATH "./assets/Fonts/MozartNbp-93Ey.ttf"

namespace Menus {

    LeaderboardMenu::LeaderboardMenu(States::StateMachine* pSM) :
    Menu(),
    State(pSM, States::stateID::leaderboard) {
        Managers::Graphics* GM = Managers::Graphics::getInstance();
        GraphicalElements::Button* bt = NULL;

        bt = new GraphicalElements::Button(Math::CoordF(GM->getWindowSize().x / 2.0f, GM->getWindowSize().y - 150), "RETURN");
        bt->select(true);
        vectorOfButtons.push_back(bt);

        max = 0;
    }

    LeaderboardMenu::~LeaderboardMenu() {
    }

    void LeaderboardMenu::update(float dt) {
        active = true;
    }

    /* Menu operation to render all it's objects. */
    void LeaderboardMenu::render() {
        updateView();
        // back.render();
        for (it = vectorOfButtons.begin(); it != vectorOfButtons.end(); ++it)
            (*it)->render();

        for (itr = allPoints.begin(); itr != allPoints.end(); ++itr)
            (*itr)->render();
    }

    void LeaderboardMenu::exec() {
        if (active) {
            active = false;
            changeState(States::stateID::mainMenu);
        }
    }

    void LeaderboardMenu::resetState() {
        vectorOfButtons[0]->select(true);
        for (itr = allPoints.begin(); itr != allPoints.end(); ++itr)
            delete (*itr);
        allPoints.clear();
        buildLeaderboard();
    }

    void LeaderboardMenu::buildLeaderboard() {
        std::ifstream file;

        file.open(LEADERBOARD_PATH, std::ios::binary | std::ios::in);

        if (!file) {
            std::ofstream writeFile(LEADERBOARD_PATH, std::ios::out | std::ios::trunc);
            writeFile.close();
        }

        int points;
        std::string name;
        std::string textString;
        std::string pointsString;

        GraphicalElements::Text* txt;

        for (int i = 0; i < 10; i++) {
            name = "";
            points = 0;
            pointsString = "";

            std::getline(file, pointsString);
            std::getline(file, name);

            textString = std::to_string((i + 1) / 10) + std::to_string((i + 1) % 10) + " - " + name;

            if (pointsString.length() > 0) {

                points = std::stoi(pointsString);

                pointsString = std::to_string(points / 1000000);
                points %= 1000000;

                pointsString += std::to_string(points / 100000);
                points %= 100000;

                pointsString += std::to_string(points / 10000);
                points %= 10000;

                pointsString += std::to_string(points / 1000);
                points %= 1000;

                pointsString += std::to_string(points / 100);
                points %= 100;

                pointsString += std::to_string(points / 10);
                points %= 10;

                pointsString += std::to_string(points);
            }

            while (textString.length() + pointsString.length() < 50) {
                textString += ".";
            }

            txt = new GraphicalElements::Text(Math::CoordF(Managers::Graphics::getInstance()->getWindowSize().x / 2.0f, 100 + 40 * i), textString + pointsString, LEADERBOARD_FONT_PATH);
            txt->setFontSize(48);
            txt->setTextAlignment(GraphicalElements::TextAlignment::center);
            allPoints.push_back(txt);
        }

        file.close();
    }

}