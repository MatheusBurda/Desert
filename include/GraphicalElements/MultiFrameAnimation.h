#pragma once

#include "GraphicalElements/Animation.h"
#include "GraphicalElements/SingleAnimation.h"
#include <map>

namespace GraphicalElements {

    enum Animation_ID {
        walk = 0,
        idle,
        attack,
        run,
        cooldown
    };

    class MultiFrameAnimation : public Animation {
    private:
        std::map<Animation_ID, SingleAnimation*> animationMap;
        Animation_ID currentID;

    public:
        MultiFrameAnimation();

        ~MultiFrameAnimation();

        void addNewAnimation(Animation_ID id, const char* path, unsigned int imageCount, const float switchTime = 0.2f);

        void update(Animation_ID id, bool facingLeft, Math::CoordF position, const float dt);
    };

} // namespace Managers
