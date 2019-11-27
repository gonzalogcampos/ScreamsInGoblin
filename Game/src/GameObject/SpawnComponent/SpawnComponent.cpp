#include "SpawnComponent.h"
#include "GameObject.h"
#include <cmath>
#include "GameValues.h"
const float PI = 3.1416;

SpawnComponent::SpawnComponent(GameObject* owner, Manager* m, float d, EnemyType type) : Component(owner, m)
{
    elapsed = static_cast <float> (rand()) / static_cast <float> (gv::SPAWN_CADENCIA);
    distance = d;
    this->type = type;
}


void SpawnComponent::update(float elapsedTime)
{
    elapsed += elapsedTime;
    if(elapsed>gv::SPAWN_CADENCIA)
    {
        elapsed = 0.f;

        float x = gameObject->getX() - cos(gameObject->getRZ()*PI/180 - PI/2)*distance;
        float y = gameObject->getY() - sin(gameObject->getRZ()*PI/180 - PI/2)*distance;
        float z = gameObject->getZ();
        float rz = gameObject->getRZ();

        EnemyFabric* f = new EnemyFabric();
        f->createEnemy(x, y, z+1.58f, rz, type);
        delete f;
    } 
}

bool SpawnComponent::isCuartel()
{
    if(type == ENEMY_1)
        return true;

    return false;
}
