#pragma once
#include "Manager.h"

class GameObject;
class WellManager : public Manager{
    private:
        WellManager():Manager(){}
    
    public:
        ~WellManager(){}
        static WellManager* getInstance(){
            static WellManager only_instance;
            return &only_instance;
        }

        void createComponent(GameObject* owner);
        void updateAll(float dt){};
        std::vector<Component*> getWells();
};