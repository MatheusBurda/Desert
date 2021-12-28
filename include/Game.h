#pragma once

#include "Entities/Characters/Player.h"
#include "Managers/Events.h"
#include "Managers/Graphics.h"

#include "Entities/Characters/Enemies/Hyena.h"
#include "Entities/Characters/Enemies/Snake.h"
#include "Entities/Obstacles/Platform.h"
#include "GraphicalElements/SingleFrameAnimation.h"
#include "List/EntityList.h"
#include "Managers/Collision.h"
#include "Control/TextInput.h"

#define TICK_RATE 0.0078125

class Game {
private:
    Managers::Graphics* pGraphicManager;
    Managers::Events* pEventManager;
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
};
