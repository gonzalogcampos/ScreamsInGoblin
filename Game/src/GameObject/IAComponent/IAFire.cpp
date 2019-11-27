#include "IAFire.h"
#include "BPhysicManager.h"
#include "GameObject.h"
#include "IAComponent.h"
#include "Waypoint.h"
#include "IAManager.h"
#include "WoodComponent.h"
#include "WoodManager.h"
#include "BucketComponent.h"
#include "WellManager.h"
#include "WellComponent.h"



bool IA_Fire_seefire::run()
{
  
  std::vector<Component*> spawns = WoodManager::getInstance()->getSpawns();
  float dfinal = 100000;
  GameObject* spawn;
  for(std::vector<Component*>::iterator iter = spawns.begin(); iter!=spawns.end(); iter++)
  {
          
    if(((WoodComponent*) (*iter))->getBurning())
    {

      GameObject* obj = ((WellComponent*)(*iter))->getGameObject();
      float d = round(sqrt(pow(obj->getX() - owner->getX(),2) + pow(obj->getY() - owner->getY(),2)));
      if(d<dfinal)
      {
         dfinal = d;
         spawn = obj;
        
      }
    }
  }
  if( dfinal != 100000)
  {
        owner->getComponent<IAComponent>()->spawnOnFire = spawn;
        return true;
  }
  return false;
}


bool IA_Fire_searchWell::run()
{
  
  std::vector<Component*> wells = WellManager::getInstance()->getWells();
  float dfinal = 1000000;
  GameObject* well;
  for(std::vector<Component*>::iterator iter = wells.begin(); iter!=wells.end(); iter++)
  {
    GameObject* obj = ((WellComponent*)(*iter))->getGameObject();
    float d = round(sqrt(pow(obj->getX() - owner->getX(),2) + pow(obj->getY() - owner->getY(),2)));
    if(d<dfinal)
    {
       dfinal = d;
       well = obj;
    }
  }

  owner->getComponent<IAComponent>()->pozoObjetivo = well;
  return true;
}



bool IA_Fire_GPStoSpawn::run()
{
    GPS* gps = ((IAManager*)owner->getComponent<IAComponent>()->getManager())->getGPS();
    GameObject* spawn = owner->getComponent<IAComponent>()->spawnOnFire;
std::vector<float> r = gps->getWay(owner->getX(),owner->getY(),spawn->getX(),spawn->getY());
  owner->getComponent<IAComponent>()->route = r;
    
     owner->getComponent<IAComponent>()->onRoute = true;
    
    return true;
}

bool IA_Fire_GPStoWell::run()
{
    GPS* gps = ((IAManager*)owner->getComponent<IAComponent>()->getManager())->getGPS();
    GameObject* well = owner->getComponent<IAComponent>()->pozoObjetivo;

   std::vector<float> ruta = gps->getWay(owner->getX(),owner->getY(),well->getX(),well->getY());

  owner->getComponent<IAComponent>()->route = ruta;
    
     owner->getComponent<IAComponent>()->onRoute = true;
    
    return true;
}

bool IA_Fire_haveWater::run()
{
  if(owner->getComponent<BucketComponent>() && owner->getComponent<BucketComponent>()->getWater())
    return false;
    
  return true;
}

bool IA_fire_StillOnFire::run()
{

  GameObject* spawn =  owner->getComponent<IAComponent>()->spawnOnFire;


  std::vector<Component*> spawns = WoodManager::getInstance()->getSpawns();
  
  bool ok = false;
  for(std::vector<Component*>::iterator iter = spawns.begin(); iter!=spawns.end(); iter++)
  {
    if(((WellComponent*)(*iter))->getGameObject() == spawn) ok= true;
  }
 
  if(ok && owner->getComponent<IAComponent>()->spawnOnFire->getComponent<WoodComponent>()->getBurning())
    return true;

  owner->getComponent<IAComponent>()->onRoute = false;
  owner->getComponent<IAComponent>()->spawnOnFire = nullptr;
    
  return false;
}

bool IA_Fire_HaveSpawn::run()
{

  if( owner->getComponent<IAComponent>()->spawnOnFire) return true;

  return false;
}