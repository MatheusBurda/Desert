#include "Menus/GameOverMenu.h"

#define BACKGROUND_PATH "./assets/Backgrounds/MenuBackground.png"
#define LEADERBOARD_PATH "./saves/Leaderboard.txt"

#include <fstream>
#include <map>

namespace Menus {

    GameOverMenu::GameOverMenu(States::StateMachine* pSM, States::Level* plvl) :
    Menu(),
    State(pSM, States::stateID::gameOver),
    title(Math::CoordF(0, 0), "GAME OVER"),
    points(),
    name(Math::CoordF(0, 0), ""),
    nameLabel(Math::CoordF(0, 0), "Name:"),
    input(),
    pointsToIncrement(0),
    plvl(plvl) {
        Managers::Graphics* GM = Managers::Graphics::getInstance();

        GraphicalElements::Button* bt = NULL;

        bt = new GraphicalElements::Button(Math::CoordF(GM->getWindowSize().x / 2.0f - 200, GM->getWindowSize().y - 100), "PLAY AGAIN");
        bt->select(true);
        vectorOfButtons.push_back(bt);

        bt = new GraphicalElements::Button(Math::CoordF(GM->getWindowSize().x / 2.0f + 200, GM->getWindowSize().y - 100), "MAIN MENU");
        vectorOfButtons.push_back(bt);

        selected = 0;
        max = 1;

        title.setPosition(Math::CoordF(GM->getWindowSize().x / 2.0f, GM->getWindowSize().y / 2 - 200));
        title.setFontSize(100);
        title.setTextAlignment(GraphicalElements::TextAlignment::center);

        points.setPosition(Math::CoordF(GM->getWindowSize().x / 2.0f - 100, GM->getWindowSize().y / 2));
        points.setFontSize(40);
        points.setTextAlignment(GraphicalElements::TextAlignment::center);

        nameLabel.setPosition(Math::CoordF(GM->getWindowSize().x / 2.0f - 200, GM->getWindowSize().y / 2 + 100));
        nameLabel.setFontSize(40);
        nameLabel.setTextAlignment(GraphicalElements::TextAlignment::center);

        name.setPosition(Math::CoordF(GM->getWindowSize().x / 2.0f + nameLabel.getSize().x - 200, GM->getWindowSize().y / 2 + 100 - nameLabel.getSize().y));
        name.setFontSize(40);
        name.setTextAlignment(GraphicalElements::TextAlignment::center);
    }

    GameOverMenu::~GameOverMenu() { }

    void GameOverMenu::update(float dt) {
        name.setTextInfo(input.getString());
        if (pointsToIncrement < plvl->getPlayerPoints())
            pointsToIncrement += 10;
        points.setTextInfo("Points: " + std::to_string(plvl->getPlayerPoints()));
    }

    /* Menu operation to render all it's objects. */
    void GameOverMenu::render() {
        updateView();
        back.render();
        for (it = vectorOfButtons.begin(); it != vectorOfButtons.end(); ++it)
            (*it)->render();

        title.render();
        points.render();
        name.render();
        nameLabel.render();
    }

    void GameOverMenu::exec() {
        if (active) {
            active = false;
            switch (selected) {
            case 0:
                changeState(States::stateID::playing);
                break;
            case 1:
                changeState(States::stateID::mainMenu);
                break;
            default:
                break;
            }

            writeToLeaderboardFile();
        }
    }

    void GameOverMenu::resetState() {
        for (it = vectorOfButtons.begin(); it != vectorOfButtons.end(); ++it)
            (*it)->select(false);
        selected = 0;
        vectorOfButtons[selected]->select(true);
        active = true;
        input.reset();
    }

    void GameOverMenu::writeToLeaderboardFile() {
        unsigned int playerPoints = plvl->getPlayerPoints();

        /* ================================= Reading File ================================= */
        std::ifstream readFile;

        readFile.open(LEADERBOARD_PATH, std::ios::in);

        std::multimap<int, std::string> pointsAndNamesMap;

        if (readFile) {

            unsigned int points;
            std::string name;
            std::string pointsString;

            for (int i = 0; i < 10; i++) {
                std::getline(readFile, pointsString);
                std::getline(readFile, name);
                if (pointsString.length() > 0)
                    pointsAndNamesMap.insert(std::pair<int, std::string>(std::stoi(pointsString), name));
            }

            readFile.close();
        }

        /* ================================= Writing File ================================= */
        if (playerPoints != 0 && input.getString().length() > 1)
            pointsAndNamesMap.insert(std::pair<int, std::string>(playerPoints, input.getString()));

        std::ofstream writeFile;

        writeFile.open(LEADERBOARD_PATH, std::ios::out | std::ios::trunc);

        if (!writeFile) {
            std::cout << "ERROR writing to file on GameOverMenu" << std::endl;
            exit(1);
        }

        while (pointsAndNamesMap.size() > 10)
            pointsAndNamesMap.erase(pointsAndNamesMap.begin());

        for (auto itr = pointsAndNamesMap.rbegin(); itr != pointsAndNamesMap.rend(); ++itr) {
            writeFile << (*itr).first << std::endl;
            writeFile << (*itr).second << std::endl;
        }

        writeFile.close();
    }

}
