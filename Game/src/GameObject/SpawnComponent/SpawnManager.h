#pragma once
#include "EnemyFabric.h"
#include "Manager.h"


class SpawnManager : public Manager
{
    private:
        SpawnManager(){};
        EnemyFabric* fabric = new EnemyFabric();
    public:
        ~SpawnManager(){delete fabric;}
        static SpawnManager* getInstance(){
            static SpawnManager only_instance;
            return &only_instance;
        }

        void createComponent(GameObject* owner, float distance, EnemyType type);
        void updateAll(float dt);
        int getNumSpawns(){return components.size();}
};