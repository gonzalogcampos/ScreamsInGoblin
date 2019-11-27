#include "ItemManager.h"
#include "ItemComponent.h"
#include "GameObject.h"

void ItemManager::createComponent(GameObject  *owner,ItemTypes type){
    components.push_back(new ItemComponent(owner, this, type));
    owner->addComponent(components[components.size()-1]);
}


void ItemManager::updateAll(float dt)
{
    for(std::size_t i = 0 ; i<components.size(); i++)
    {
        ((ItemComponent*)components[i])->update(dt); 
    }
}

