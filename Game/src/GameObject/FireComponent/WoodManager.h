#pragma once
#include "Manager.h"

class GameObject;
class WoodManager : public Manager{
    private:
        WoodManager():Manager(){}
    
    public:
        ~WoodManager(){}
        static WoodManager* getInstance(){
            static WoodManager only_instance;
            return &only_instance;
        }

        void createComponent(GameObject* owner, float life, int team = 1);
        void updateAll(float dt);
         std::vector<Component*> getSpawns();
};