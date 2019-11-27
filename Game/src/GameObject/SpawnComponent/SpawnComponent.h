#pragma once
#include "Component.h"
#include "EnemyFabric.h"
#include <cstdlib>

class GameObject;
class SpawnComponent : public Component{
    private:
        float distance;
        float elapsed;
        EnemyType type;
    public:
        SpawnComponent(GameObject* owner, Manager* m, float d, EnemyType type);
        ~SpawnComponent(){};

        void update(float elapsedTime);
        bool isCuartel();
};

