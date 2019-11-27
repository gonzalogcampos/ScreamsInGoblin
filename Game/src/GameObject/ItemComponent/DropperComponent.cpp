#include "DropperComponent.h"
#include "GameObject.h"
#include <stdlib.h>
#include "GameValues.h"
#include "DropperManager.h"

DropperComponent::~DropperComponent()
{
    if(DropperManager::getInstance()->getDrop())
        dropItem();
}

void DropperComponent::dropItem()
{
    ItemFabric* fabric = new ItemFabric();
    float p = rand()/(RAND_MAX/(100.f)); 

    if(p<gv::DROP_P_POTION){
        fabric->createItem(gameObject->getX(),
                            gameObject->getY(),
                            gameObject->getZ(),
                            gameObject->getRZ(),
                            POTION);
    }else if(p<gv::DROP_P_AXE){
        fabric->createItem(gameObject->getX(),
                            gameObject->getY(),
                            gameObject->getZ(),
                            gameObject->getRZ(),
                            AXE);
    }else if(p<gv::DROP_P_PEAK){
        fabric->createItem(gameObject->getX(),
                            gameObject->getY(),
                            gameObject->getZ(),
                            gameObject->getRZ(),
                            PEAK);
    }else if(p<gv::DROP_P_CROSSBOW){
        fabric->createItem(gameObject->getX(),
                            gameObject->getY(),
                            gameObject->getZ(),
                            gameObject->getRZ(),
                            CROSSBOW);
    }else if(p<gv::DROP_P_SHIELD){
        fabric->createItem(gameObject->getX(),
                            gameObject->getY(),
                            gameObject->getZ(),
                            gameObject->getRZ(),
                            SHIELD);
    }
    delete fabric;
}