#include "LevelLoader.h"
#include "GameResource.h"
#include "GameObject.h"
#include "RenderManager.h"
#include "RenderComponent.h"
#include "BPhysicManager.h"
#include "BPhysicComponent.h"
#include "SpawnManager.h"
#include "WoodManager.h"
#include "WellManager.h"
#include "InputManager.h"
#include "ShootManager.h"
#include "LifeManager.h"
#include "CameraManager.h"
#include "StorageManager.h"
#include "IAManager.h"
#include "Area.h"
#include "Waypoint.h"
//LEVELS
#include "Level1.h"
#include "Level2.h"
#include "Level3.h"
#include "Level4.h"



//std::vector<Level> levels{level4};
std::vector<Level> levels{level4, level2, level4};

bool LevelLoader::hasNext()
{
    if(next<levels.size())
        return true;

    return false;
}

void LevelLoader::loadLevel()
{
    if(next>=levels.size())
        next = 0;


    Level level = levels[next];
    
    createMap(level.map_obj, level.map_bmp, level.map_bullet);
    createPlayer(level.pla_x, level.pla_y, level.pla_z);
    
    for(std::size_t i = 0; i<level.spawns.size(); i++)
        createSpawn(level.spawns[i].x, level.spawns[i].y, level.spawns[i].r, level.spawns[i].t);

    for(std::size_t i = 0; i<level.wells.size(); i++) 
        createWell(level.wells[i].x, level.wells[i].y, level.wells[i].r);

   for(std::size_t i = 0; i<level.waypoints.size(); i++) 
        addWay(level.waypoints[i].x, level.waypoints[i].y);

   for(std::size_t i = 0; i<level.areas.size(); i++) 
        addArea(level.areas[i].xup, level.areas[i].yup, level.areas[i].xdw, level.areas[i].ydw );
   
   for(std::size_t i = 0; i<level.wayToArea.size(); i++) 
        addWayToArea(level.wayToArea[i].ia, level.wayToArea[i].ib);

    for(std::size_t i = 0; i<level.conexToGraph.size(); i++) 
        addConexToGraph(level.conexToGraph[i].ia, level.conexToGraph[i].ib);

    for(std::size_t i = 0; i<level.patrulla.size(); i++) 
        assignPatrulla(level.patrulla[i].a, level.patrulla[i].p);

    next++;
}







void LevelLoader::createMap(char* obj, char* bmp, char* bullet)
{
    //ADDING A MAP 700 x 700 x 1
    GameObject* map = GameResource::getInstance()->createGameObject(0.f, 0.f, 0.f, 0.f);
    RenderManager::getInstance()->createComponent(map, obj);//Fachada de render y path de obj
    map->getComponent<RenderComponent>()->isMap();
    map->getComponent<RenderComponent>()->setTexture((char*)bmp);//Path de bmp   
    BPhysicManager::getInstance()->createComponent(map, (char*)bullet);
}
void LevelLoader::createPlayer(float x, float y, float z)
{
    //ADDING A PLAYER 1 x 1 x 2
    player = GameResource::getInstance()->createPlayer(x, y, z, 0.f);//Creates a new GO on x, y, z, rz
    RenderManager::getInstance()->createComponent(player, (char*)"res/animations/Goblin/Walk/Walk_Goblin_1.obj");//Fachada de render y path de obj
    BPhysicManager::getInstance()->createComponent(player, .5f, .5f, 1.0f, 100.f, 0);
    player->getComponent<BPhysicComponent>()->setvMax(gv::PLAYER_VELOCITY);
    InputManager::getInstance()->createComponent(player);
    ShootManager::getInstance()->createComponent(player, gv::PLAYER_STRT_CADENCE, 2.f, (ProjectileType)gv::PLAYER_STRT_WEAPON, 2);//Cadencia y Tipo
    LifeManager::getInstance()->createComponent(player, gv::PLAYER_LIFE, 2, true);
    CameraManager::getInstance()->createComponent(player);
    StorageManager::getInstance()->createComponent(player);
    IAManager::getInstance()->setPlayer(player);
    IAManager::getInstance()->init(1);

}


void LevelLoader::createSpawn(float x, float y, float rz, bool type)
{
    GameObject* spawn = GameResource::getInstance()->createGameObject(x, y, -2.58f, -rz);
    
    if(type){
        RenderManager::getInstance()->createComponent(spawn, (char*)"res/obj/CUARTEL.obj");
        SpawnManager::getInstance()->createComponent(spawn, 4.f, ENEMY_1);
    }else{
        RenderManager::getInstance()->createComponent(spawn, (char*)"res/obj/CASA.obj");
        SpawnManager::getInstance()->createComponent(spawn, 4.f, ENEMY_2);
    }
    WoodManager::getInstance()->createComponent(spawn, gv::SPAWN_LIFE);
    BPhysicManager::getInstance()->createComponent(spawn, 3.5f, 3.5f, 3.f, 0.f, 0);
}


void LevelLoader::createWell(float x, float y, float rz)
{
    GameObject* well = GameResource::getInstance()->createGameObject(x, y, -1.f, rz);
    RenderManager::getInstance()->createComponent(well, (char*)"res/obj/POZO.obj");//Fachada de render y path de obj
    WellManager::getInstance()->createComponent(well);
    BPhysicManager::getInstance()->createComponent(well, .5f, .5f, .5f, 0.f, 1);   
}

void LevelLoader::assignPatrulla(float a, std::vector<float> p)
{
    std::vector<Area*> Ar = IAManager::getInstance()->getGPS()->getAreas();

    Ar[a]->addPatrulla(p);
}


void LevelLoader::addWay(float x, float y)
{
    IAManager::getInstance()->getGPS()->addWaypoint(x,y);
}

void LevelLoader::addArea(float xup, float yup, float xdw, float ydw)
{
    IAManager::getInstance()->getGPS()->addArea(xup, yup, xdw, ydw);
}

void LevelLoader::addWayToArea(int a, int w)
{
    IAManager::getInstance()->getGPS()->addWaypointToArea(a,w);
}

void LevelLoader::addConexToGraph(int w1, int w2)
{
    IAManager::getInstance()->getGPS()->addConexionToGraph(w1, w2);
}