#include "CameraComponent.h"
#include "CameraManager.h"

//Updates all the components
void CameraManager::updateAll(float dt){
    for(auto* c : components){
        ((CameraComponent*)c)->update(dt);
    }
}

void CameraManager::createComponent(GameObject *owner)
{

    components.push_back(new CameraComponent(owner, this));

    owner->addComponent(components[components.size()-1]);
}
