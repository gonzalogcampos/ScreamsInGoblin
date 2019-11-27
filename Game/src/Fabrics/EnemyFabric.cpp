#include "EnemyFabric.h"
#include "BPhysicComponent.h"
#include "GameResource.h"
#include "RenderManager.h"
#include "BPhysicManager.h"
#include "IAManager.h"
#include "LifeManager.h"
#include "ShootManager.h"
#include "ScoreManager.h"
#include "IAComponent.h"
#include "DropperManager.h"
#include "BucketManager.h"
#include "SpawnManager.h"

GameObject* EnemyFabric::createEnemy(float x, float y, float z, float rz, EnemyType type)
{
    int nsp = SpawnManager::getInstance()->getNumSpawns()*gv::ENEMIES_PER_SPAWN;
    int nen = ScoreManager::getInstance()->getEnemies();
    
    if(nsp <= nen && gv::MIN_ENEMIES<=nen)
        return nullptr;
    

    //ADDING A ENEMY
    GameObject* primero = GameResource::getInstance()->createGameObject(x, y, z, rz);//Creates a new GO on x, y, z, rz
    RenderManager::getInstance()->createComponent(primero, enemytypes[type].mesh);//Fachada de render y path de obj
    primero->getComponent<RenderComponent>()->setAnimation((char*)enemytypes[type].animation, enemytypes[type].numFrames);//Path de bmp
    BPhysicManager::getInstance()->createComponent(primero, .5f, .5f, 1.f, 100.f, 0);
    primero->getComponent<BPhysicComponent>()->setvMax(enemytypes[type].vMax);
    ScoreManager::getInstance()->createComponent(primero, gv::ENEMY_SCORE);
    IAManager::getInstance()->createComponent(primero);
    type == ENEMY_1 ?  primero->getComponent<IAComponent>()->Initialice(0) :  primero->getComponent<IAComponent>()->Initialice(1);
    LifeManager::getInstance()->createComponent(primero, enemytypes[type].life);//Vida
    ShootManager::getInstance()->createComponent(primero, gv::ENEMY_CADENCE, 2.f, (ProjectileType)gv::ENEMY_WEAPON);//Cadencia y Tipo
    DropperManager::getInstance()->createComponent(primero);
    if(type == ENEMY_2) 
        BucketManager::getInstance()->createComponent(primero);
   
    return primero;
}