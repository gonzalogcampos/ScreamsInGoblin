#include "StorageManager.h"
#include "StorageComponent.h"
#include "GameObject.h"


void StorageManager::createComponent(GameObject *owner){
    components.push_back(new StorageComponent(owner, this));
    owner->addComponent(components[components.size()-1]);
}


void StorageManager::updateAll(float dt)
{
    
}