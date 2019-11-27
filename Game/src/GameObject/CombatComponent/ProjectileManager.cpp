#include "ProjectileManager.h"
#include "ProjectileComponent.h"
#include "GameObject.h"


void ProjectileManager::createComponent(GameObject *owner, float damage, int team)
{
    components.push_back(new ProjectileComponent(owner, this, damage, team));
    owner->addComponent(components[components.size()-1]);
}


void ProjectileManager::updateAll(float dt)
{
    
}
