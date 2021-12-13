#include "GraphicalElements/Animation.h"

namespace GraphicalElements {

    Managers::Graphics* Animation::pGraphicM = Managers::Graphics::getInstance();

    Animation::Animation() :
    body() { }

    Animation::~Animation() { }

    void Animation::render() {
        pGraphicM->render(&body);
    }

} // namespace GraphicalElements
