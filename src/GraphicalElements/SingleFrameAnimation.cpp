#include "GraphicalElements/SingleFrameAnimation.h"

#include "Managers/Graphics.h"

namespace GraphicalElements {

    SingleFrameAnimation::SingleFrameAnimation(const char* path, Math::CoordF position, Math::CoordF size){
        texture = Managers::Graphics::getInstance()->loadTexture(path);

        
    }

    SingleFrameAnimation::~SingleFrameAnimation(){

    }
    
    void SingleFrameAnimation::update(Math::CoordF position){

    }

    void SingleFrameAnimation::render(){

    }


} // namespace GraphicalElements
