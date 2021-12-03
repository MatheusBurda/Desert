#pragma once

#include "Entities/Characters/Player.h"
#include "Managers/Graphics.h"

class Game {
private:
    Managers::Graphics* pGraphicManager;
    Entities::Characters::Player p1;

public:
    Game();
    ~Game();

    void exec();
};
