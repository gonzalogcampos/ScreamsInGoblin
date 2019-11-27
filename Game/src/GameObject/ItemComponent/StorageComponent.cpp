#include "StorageComponent.h"
#include "GameObject.h"
#include "ItemComponent.h"
#include "ShootComponent.h"
#include "LifeComponent.h"
#include "GameValues.h"
#include "SpecificSoundEvent.h"


void StorageComponent::itemCatch(ItemComponent* item)
{
    
    if(!item) return;
    
    if(itemType != EMPTY && item->getType() != POTION && item->getType() != SHIELD)
        itemDrop();

    applyEffect(item->getType());

    if(item->getType() != POTION && item->getType() != SHIELD)
        itemType = item->getType();
        
    item->getGameObject()->setKill(true);
}

void StorageComponent::itemDrop()
{
    ItemFabric* fabric = new ItemFabric();
    fabric->createItem(gameObject->getX()-3.f, gameObject->getY()-3.f, gameObject->getZ(), gameObject->getRZ(), itemType);

    this->itemType = EMPTY;

    delete fabric;
}

void StorageComponent::applyEffect(ItemTypes Type)
{ 
    switch (Type)
    {
        case CROSSBOW:
            crossbow();
            break;

        case AXE:
            axe();
            break;

        case POTION:
            potion();
            break;

        case PEAK:
            peak();
            break;

        case SHIELD:
            shield();
            break;
    
        default:
            break;
    }
}


void StorageComponent::potion()
{
    ItemPickSoundEvent* poti = new ItemPickSoundEvent(SoundSystem::getInstance()->getEventInstanceFromName("pickpotion"));
    poti->setPosition({gameObject->getX(), gameObject->getY(), gameObject->getZ()});
    poti->setVolume(5);
    poti->start();
    

    delete poti;
    //it gives you life
    if(gameObject->getComponent<LifeComponent>())
    {
        gameObject->getComponent<LifeComponent>()->addLife(gv::POTION_VALUE);
    }
    
}

void StorageComponent::crossbow()
{
    //makes you shoot faster
    if(gameObject->getComponent<ShootComponent>())
    {
        gameObject->getComponent<ShootComponent>()->setCadencia(gv::CROSSBOW_CADENCE);
        gameObject->getComponent<ShootComponent>()->setType(PARROW);
    }
    
}


void StorageComponent::peak()
{
    //makes you shoot faster
    if(gameObject->getComponent<ShootComponent>())
    {
        gameObject->getComponent<ShootComponent>()->setCadencia(gv::PEAK_CADENCE);
        gameObject->getComponent<ShootComponent>()->setType(PPEAK);
    }
}

void StorageComponent::shield()
{
     ItemPickSoundEvent* shield = new ItemPickSoundEvent(SoundSystem::getInstance()->getEventInstanceFromName("pickshield"));
    shield->setPosition({gameObject->getX(), gameObject->getY(), gameObject->getZ()});
    shield->setVolume(5);
    shield->start();
  
    delete shield;
    //it gives you life shield
    if(gameObject->getComponent<LifeComponent>())
    {
        gameObject->getComponent<LifeComponent>()->setShield(gv::SHIELD_VALUE);
    }
    
}

void StorageComponent::axe()
{
    //makes you shoot faster
    if(gameObject->getComponent<ShootComponent>())
    {
        gameObject->getComponent<ShootComponent>()->setCadencia(gv::AXE_CADENCE);
        gameObject->getComponent<ShootComponent>()->setType(PAXE);
    }
}