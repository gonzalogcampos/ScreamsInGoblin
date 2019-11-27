#include "GameObject.h"
#include "Component.h"
#include <memory>

//Constructor
GameObject::GameObject(float x, float y, float z, float rz){
    this->x     = x;
    this->y     = y;
    this->z     = z;
    this->rx    = 0;
    this->ry    = 0;
    this->rz    = rz;
}

//Destructor
GameObject::~GameObject(){
    for(std::size_t i= 0; i<components.size(); i++)
    {
        delete components[i];
    }
}



//Add component
void GameObject::addComponent(Component* c){
    components.push_back(c);
}
