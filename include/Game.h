#pragma once

#include "Entities/Characters/Player.h"

class Game {
private:
    Entities::Characters::Player p1;

public:
    Game();
    ~Game();

    void exec();
};
