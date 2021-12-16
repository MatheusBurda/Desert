#pragma once

#include "Entities/Characters/Player.h"
#include "Entities/Obstacles/Platform.h"
#include "GraphicalElements/SingleFrameAnimation.h"
#include "List/EntityList.h"
#include "Managers/Collision.h"
#include "Managers/Graphics.h"
#include "Entities/Characters/Enemies/Snake.h"

#define TICK_RATE 0.0078125

class Game {
private:
    Managers::Graphics* pGraphicManager;
    Entities::Characters::Player* p1;
    GraphicalElements::SingleFrameAnimation background;
    List::EntityList staticEntitiesList;
    List::EntityList movingEntitiesList;
    Managers::Collision collisionManager;
    sf::Clock clock;
    float dt;

public:
    Game();
    ~Game();

    void exec();

    float updateDeltaTime();
};
