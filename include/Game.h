#pragma once

#include "Entities/Characters/Player.h"
#include "Managers/Graphics.h"

class Game {
private:
    Entities::Characters::Player p1;
    Managers::Graphics graphicManager;
    static Managers::Graphics* pGraphicManager;

public:
    Game();
    ~Game();

    void exec();
};
