#include "GraphicalElements/Animation.h"

namespace GraphicalElements {

    const float Animation::SingleAnimation::switchTime = 0.2;

    Managers::Graphics* Animation::pGraphicM = Managers::Graphics::getInstance();

    Animation::Animation() :
    body(),
    animationMap(),
    currentID(Animation_ID::walk) { 
        body.setScale(sf::Vector2f(3,3));
    }

    Animation::~Animation() {
        std::map<Animation_ID, SingleAnimation*>::iterator it;
        for (it = animationMap.begin(); it != animationMap.end(); ++it)
            delete (it->second);

        animationMap.clear();
    }

    void Animation::addNewAnimation(Animation_ID id, const char* path, unsigned int imageCount) {

        SingleAnimation* tmp = new SingleAnimation(path, imageCount);

        if (tmp == NULL) {
            std::cout << "ERROR: Could not create Animation on Animation::addNewAnimation!" << std::endl;
            exit(1);
        }

        animationMap.insert(std::pair<Animation_ID, SingleAnimation*>(id, tmp));

        sf::IntRect rectSize = tmp->getSize();

        body.setSize(sf::Vector2f(rectSize.width, rectSize.height));
        body.setOrigin(sf::Vector2f(rectSize.width, rectSize.height) / 2.0f);
    }

    void Animation::update(Animation_ID id, bool facingLeft, Math::CoordF position, float dt) {
        if (currentID != id) {
            currentID = id;
            animationMap[currentID]->reset();
        }

        animationMap[currentID]->update(dt, facingLeft);

        body.setPosition(sf::Vector2f(position.x, position.y));
        body.setTextureRect(animationMap[currentID]->getSize());
        body.setTexture(animationMap[currentID]->getTexture());
    }

    void Animation::render() {
        pGraphicM->render(&body);
    }

} 
