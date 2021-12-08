#pragma once

#include "Entities/Characters/Player.h"
#include "GraphicalElements/SingleFrameAnimation.h"
#include "Managers/Graphics.h"
#include "List/EntityList.h"


class Game {
private:
    Managers::Graphics* pGraphicManager;
    Entities::Characters::Player* p1;
    GraphicalElements::SingleFrameAnimation background;
    List::EntityList list;

public:
    Game();
    ~Game();

    void exec();
};
