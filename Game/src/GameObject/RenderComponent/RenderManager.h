#pragma once
#include "RenderComponent.h"
#include <vector>

class Manager;
class RenderManager : public Manager{
    private:
        RenderManager():Manager(){}
        
    public:
        ~RenderManager(){}
        static RenderManager* getInstance(){
            static RenderManager only_instance;
            return &only_instance;
        }

        
        void updateAll(float dt);
        void createComponent(GameObject *owner, char* path);

};