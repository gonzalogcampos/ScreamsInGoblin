#pragma once
#include "ItemFabric.h"
#include "Manager.h"

class GameObject;
class ItemManager : public Manager{
    private:
        ItemManager():Manager(){}
    
    public:
        ~ItemManager() {}
        static ItemManager* getInstance(){
            static ItemManager only_instance;
            return &only_instance;
        }
        //DESTRUCTOR
        void createComponent(GameObject *owner, ItemTypes type);
        void updateAll(float dt);

};