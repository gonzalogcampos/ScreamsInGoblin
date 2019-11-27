#pragma once
#include "Manager.h"

class GameObject;
class BucketManager : public Manager{
    private:
        BucketManager():Manager(){}
    
    public:
        ~BucketManager(){}
        static BucketManager* getInstance(){
            static BucketManager only_instance;
            return &only_instance;
        }

        void createComponent(GameObject* owner);
        void updateAll(float dt){};
};