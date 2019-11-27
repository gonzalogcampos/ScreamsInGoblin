#include "GameManager.h"

//---------------------------------
//        INCLUDE AL DE MANAGERS
//---------------------------------
#include "BPhysicManager.h"
#include "BucketManager.h"
#include "CameraManager.h"
#include "DropperManager.h"
#include "IAManager.h"
#include "InputManager.h"
#include "ItemManager.h"
#include "LifeManager.h"
#include "ProjectileManager.h"
#include "RenderManager.h"
#include "ScoreManager.h"
#include "ShootManager.h"
#include "SpawnManager.h"
#include "StorageManager.h"
#include "WellManager.h"
#include "WoodManager.h"

#include "SoundSystem.h"
#include "GameResource.h"
#include "Render.h"
#include "HUD.h"

void GameManager::initAll()
{
    //GameResource::getInstance();
    //BPhysicManager::getInstance();
    //BucketManager::getInstance();
    //CameraManager::getInstance();
    //DropperManager::getInstance();
    //WoodManager::getInstance();
    //IAManager::getInstance();
    //InputManager::getInstance();
    //ItemManager::getInstance();
    //LifeManager::getInstance();
    //ProjectileManager::getInstance();
    //RenderManager::getInstance();
    //ScoreManager::getInstance();
    //ShootManager::getInstance();
    //SpawnManager::getInstance();
    //StorageManager::getInstance();
    //WellManager::getInstance();

    HUD::getInstance()->init();
}

void GameManager::clear()
{
    GameResource::getInstance()->clear();
    HUD::getInstance()->clear();
    ScoreManager::getInstance()->resetScore();
    SoundSystem::getInstance()->Release();
}

void GameManager::updateAll(float dt)
{
    InputManager::getInstance()->setCursorPosition(Render::getInstance()->getCursorX(), Render::getInstance()->getCursorY());
    HUD::getInstance()->update(dt);
    GameResource::getInstance()->updateAll();
    
    InputManager::getInstance()->updateAll(dt);
    SpawnManager::getInstance()->updateAll(dt);
    IAManager::getInstance()->updateAll(dt);
    BPhysicManager::getInstance()->updateAll(dt);
    ShootManager::getInstance()->updateAll(dt);
    WoodManager::getInstance()->updateAll(dt);
    CameraManager::getInstance()->updateAll(dt);
    LifeManager::getInstance()->updateAll(dt);
    RenderManager::getInstance()->updateAll(dt);
    ItemManager::getInstance()->updateAll(dt);
    SoundSystem::getInstance()->Update();

    //USELESS
    //BucketManager::getInstance()->updateAll(dt);
    //DropperManager::getInstance()->updateAll(dt);
    
    //ProjectileManager::getInstance()->updateAll(dt);
    //ScoreManager::getInstance()->updateAll(dt);
    //StorageManager::getInstance()->updateAll(dt);
    //WellManager::getInstance()->updateAll(dt);
}