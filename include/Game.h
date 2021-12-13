#pragma once

#include "Entities/Characters/Player.h"
#include "Entities/Obstacles/Platform.h"
#include "GraphicalElements/SingleFrameAnimation.h"
#include "List/EntityList.h"
#include "Managers/Collision.h"
#include "Managers/Graphics.h"

class Game {
private:
    Managers::Graphics* pGraphicManager;
    Entities::Characters::Player* p1;
    GraphicalElements::SingleFrameAnimation background;
    List::EntityList staticEntitiesList;
    List::EntityList movingEntitiesList;
    Managers::Collision collisionManager;

public:
    Game();
    ~Game();

    void exec();
};
