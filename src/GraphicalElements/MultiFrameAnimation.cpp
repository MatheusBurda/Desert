#include "GraphicalElements/MultiFrameAnimation.h"

namespace GraphicalElements {

    const float MultiFrameAnimation::SingleAnimation::switchTime = 0.2;

    MultiFrameAnimation::MultiFrameAnimation() :
    animationMap(),
    currentID(Animation_ID::idle) { }

    MultiFrameAnimation::~MultiFrameAnimation() {
        std::map<Animation_ID, SingleAnimation*>::iterator it;
        for (it = animationMap.begin(); it != animationMap.end(); ++it)
            delete (it->second);

        animationMap.clear();
    }

    void MultiFrameAnimation::addNewAnimation(Animation_ID id, const char* path, unsigned int imageCount) {

        SingleAnimation* tmp = new SingleAnimation(path, imageCount);

        if (tmp == NULL) {
            std::cout << "ERROR: Could not create Animation on MultiFrameAnimation::addNewAnimation!" << std::endl;
            exit(1);
        }

        animationMap.insert(std::pair<Animation_ID, SingleAnimation*>(id, tmp));

        sf::IntRect rectSize = tmp->getSize();

        body.setSize(sf::Vector2f(rectSize.width, rectSize.height));
        body.setOrigin(sf::Vector2f(rectSize.width, rectSize.height) / 2.0f);
    }

    void MultiFrameAnimation::update(Animation_ID id, bool facingLeft, Math::CoordF position, float dt) {
        if (currentID != id) {
            currentID = id;
            animationMap[currentID]->reset();
        }

        animationMap[currentID]->update(dt, facingLeft);

        body.setPosition(sf::Vector2f(position.x, position.y));
        body.setTextureRect(animationMap[currentID]->getSize());
        body.setTexture(animationMap[currentID]->getTexture());
    }

}
