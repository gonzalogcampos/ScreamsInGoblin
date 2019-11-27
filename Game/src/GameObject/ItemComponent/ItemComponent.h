#pragma once
#include "Component.h"
#include "ItemFabric.h"

class GameObject;
class ItemComponent : public Component{
    private:
        ItemTypes Type;
        float life = 0.f;
    public:
        //CONSTRUCTOR
        ItemComponent(GameObject* g, Manager* m, ItemTypes Type) :Component(g, m){
            this->Type = Type;
        }

        //DESTRUCTOR
        ~ItemComponent(){}

        ItemTypes getType(){return Type;}
        void update(float dt);
};