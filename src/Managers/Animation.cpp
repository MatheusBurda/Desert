#include "Managers/Animation.h"

namespace Managers {

    const float AnimationManager::Animation::switchTime = 0.2;

    Graphics* AnimationManager::pGraphicM = Graphics::getInstance();

    AnimationManager::AnimationManager() :
    body(),
    animationMap(),
    currentID(Animation_ID::walk) {
    }

    AnimationManager::~AnimationManager() {
        std::map<Animation_ID, Animation*>::iterator it;
        for (it = animationMap.begin(); it != animationMap.end(); ++it)
            delete (it->second);

        animationMap.clear();
    }

    void AnimationManager::addNewAnimation(Animation_ID id, const char* path, unsigned int imageCount) {
        
        Animation* tmp = new Animation(path, imageCount);

        if(tmp == NULL){
            std::cout<< "ERROR: Could not create Animation on AnimationManager::addNewAnimation!" << std::endl;
            exit(1);
        }

        animationMap.insert(std::pair<Animation_ID, Animation*>(id, tmp));
        
        sf::IntRect rectSize = tmp->getSize();

        body.setSize(sf::Vector2f(rectSize.width, rectSize.height));
        body.setOrigin(sf::Vector2f(rectSize.width, rectSize.height) / 2.0f);
    }

    void AnimationManager::update(Animation_ID id, bool facingLeft, Math::CoordF position, float dt) {
        if(currentID != id){
            currentID = id;
            animationMap[currentID]->reset();
        }

        animationMap[currentID]->update(dt, facingLeft);

        body.setPosition(sf::Vector2f(position.x, position.y));
        body.setTextureRect(animationMap[currentID]->getSize());
        body.setTexture(animationMap[currentID]->getTexture());
    }

    void AnimationManager::render() {
        pGraphicM->render(&body);
    }

} // namespace Managers
