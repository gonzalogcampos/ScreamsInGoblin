#pragma once
#include "Manager.h"

class GameObject;
class StorageManager : public Manager{
    private:
        StorageManager():Manager(){};

    public:
        ~StorageManager(){}
        static StorageManager* getInstance(){
            static StorageManager only_instance;
            return &only_instance;
        }

        void createComponent(GameObject *owner);
        
        void updateAll(float dt);

};