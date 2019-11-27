#include "ItemComponent.h"
#include "GameValues.h"
#include "GameObject.h"

void ItemComponent::update(float dt)
{
    life += dt;

    if(life>gv::ITEM_LIFE)
        gameObject->setKill(true);
}