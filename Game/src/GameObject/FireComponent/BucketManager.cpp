#include "BucketManager.h"
#include "GameObject.h"
#include "BucketComponent.h"


void BucketManager::createComponent(GameObject* owner)
{
    components.push_back(new BucketComponent(owner, this));
    owner->addComponent(components[components.size()-1]);
}