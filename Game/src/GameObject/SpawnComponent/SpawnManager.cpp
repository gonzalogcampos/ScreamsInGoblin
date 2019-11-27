#include "SpawnManager.h"
#include "GameObject.h"
#include "SpawnComponent.h"


void SpawnManager::createComponent(GameObject* owner, float distance, EnemyType type)
{
    components.push_back(new SpawnComponent(owner, this, distance, type));
    owner->addComponent(components[components.size() - 1]);
}

void SpawnManager::updateAll(float dt)
{
    for(std::size_t i = 0; i<components.size(); i++)
    {
        ((SpawnComponent*)components[i])->update(dt);
    }
}
