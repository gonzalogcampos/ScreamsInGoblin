#pragma once
#include <vector>
#include "Manager.h"

class GameObject;
class ProjectileManager : public Manager{
    private:
        ProjectileManager():Manager(){}

    public:
        ~ProjectileManager(){}
        static ProjectileManager* getInstance(){
            static ProjectileManager only_instance;
            return &only_instance;
        }

        void createComponent(GameObject* owner, float damage, int team = 1);
        void updateAll(float dt);
};