#include "WoodManager.h"
#include "GameObject.h"
#include "WoodComponent.h"

void WoodManager::createComponent(GameObject* owner, float life, int team)
{
    components.push_back(new WoodComponent(owner, this, life, team));
    owner->addComponent(components[components.size()-1]);
}

void WoodManager::updateAll(float dt)
{
    for(std::size_t i = 0; i<components.size(); i++)
    {
        ((WoodComponent*)components[i])->update(dt);
    }
}

 std::vector<Component*> WoodManager::getSpawns()
 {
     return components;
 }