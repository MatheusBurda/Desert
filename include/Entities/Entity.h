#pragma once

#include "../Math/CoordTL.h"

namespace Entities{

    class Entity
    {
    private:
        Math::CoordF position;
        Math::CoordF size;

    public:
        Entity();
        ~Entity();
    };
    
}