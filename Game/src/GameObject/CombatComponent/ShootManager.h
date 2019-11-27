#pragma once
#include "ProjectileFabric.h"
#include "Manager.h"

class ShootManager : public Manager{
    private:
        ShootManager():Manager(){fabric = new ProjectileFabric();}
        ProjectileFabric* fabric;

    public:
        ~ShootManager(){delete fabric;}
        
        static ShootManager* getInstance(){
            static ShootManager only_instance;
            return &only_instance;
        }

        void updateAll(float dt);
        void createProjectile(float x, float y, float rz, ProjectileType tipo, int team = 1);
        void createComponent(GameObject *owner, float cadencia, float distance, ProjectileType tipo, int team = 1);
};