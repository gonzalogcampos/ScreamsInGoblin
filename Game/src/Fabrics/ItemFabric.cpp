#include "ItemFabric.h"
#include "GameObject.h"
#include "RenderManager.h"
#include "BPhysicManager.h"
#include "ItemManager.h"
#include "GameResource.h"

void ItemFabric::createItem(float x, float y, float z, float rz, ItemTypes type)
{
    GameObject* r =  GameResource::getInstance()->createGameObject(x, y, z, rz);
    RenderManager::getInstance()->createComponent(r, item_types[type].mesh);
    r->getComponent<RenderComponent>()->setTexture(item_types[type].texture);
    r->getComponent<RenderComponent>()->isLeviosa();

    BPhysicManager::getInstance()->createComponent(r, .5f, .5f, .5, 10.f, 1);
    ItemManager::getInstance()->createComponent(r, type);
}

