#include "DropperManager.h"
#include "GameObject.h"
#include "DropperComponent.h"


void DropperManager::createComponent(GameObject* owner)
{
    drop = true;
    components.push_back(new DropperComponent(owner, this));
    owner->addComponent(components[components.size()-1]);
}