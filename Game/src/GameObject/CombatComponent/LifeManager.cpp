#include "LifeManager.h"
#include "GameObject.h"
#include "LifeComponent.h"

void LifeManager::createComponent(GameObject *owner, float life, int team, bool decreases)
{
    components.push_back(new LifeComponent(owner, this, life, decreases, team));
    owner->addComponent(components[components.size()-1]);
}


void LifeManager::updateAll(float dt)
{
    for(std::size_t i= 0 ; i<components.size(); i++)
        ((LifeComponent*)components[i])->update(dt);
}