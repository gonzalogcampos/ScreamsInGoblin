#include "HUD.h"
#include "GameResource.h"
#include "GameObject.h"
#include "LifeComponent.h"
#include "SpawnManager.h"
#include "ScoreManager.h"
#include "Area.h"
#include "IAManager.h"
#include "IAComponent.h"
#include "Waypoint.h"
#include <SFML/Window.hpp>
#include <ShootComponent.h>



void HUD::update(float dt)
{
    float shield=0.f;
    GameObject* p = GameResource::getInstance()->getPlayer();
    if(p && p->getComponent<LifeComponent>()){
        life = p->getComponent<LifeComponent>()->getLife();
        shield = p->getComponent<LifeComponent>()->getShield();
    }
    
    if(p && p->getComponent<ShootComponent>())
    {
        weapon = (int)p->getComponent<ShootComponent>()->getType();
    }
    score = ScoreManager::getInstance()->getScore();
    numSpawns = SpawnManager::getInstance()->getNumSpawns();

    Render::getInstance()->getHUD()->updateValues(life, shield,1/dt, score, numSpawns, weapon);
}
