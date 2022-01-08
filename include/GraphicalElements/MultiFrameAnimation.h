#pragma once

#include "GraphicalElements/Animation.h"
#include "GraphicalElements/SingleAnimation.h"
#include <map>

namespace GraphicalElements {

    enum Animation_ID {
        walk = 0,
        idle = 1,
        attack = 2
    };

    class MultiFrameAnimation : public Animation {
    private:
        std::map<Animation_ID, SingleAnimation*> animationMap;
        Animation_ID currentID;
        float switchTime;

    public:
        MultiFrameAnimation();
        ~MultiFrameAnimation();

        void addNewAnimation(Animation_ID id, const char* path, unsigned int imageCount);
        void update(Animation_ID id, bool facingLeft, Math::CoordF position, const float dt);

        void setSwitchTime(const float switchTime);
    };

} // namespace Managers
