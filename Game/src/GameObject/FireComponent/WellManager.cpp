#include "WellManager.h"
#include "GameObject.h"
#include "WellComponent.h"


void WellManager::createComponent(GameObject* owner)
{
    components.push_back(new WellComponent(owner, this));
    owner->addComponent(components[components.size()-1]);
}

std::vector<Component*> WellManager::getWells()
{
    return components;
}