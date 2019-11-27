#include "IAGrafos.h"
#include "GameObject.h"
#include "Waypoint.h"
#include "Area.h"
#include "IAComponent.h"
#include "IAManager.h"
#include <cmath>
#include "BPhysicComponent.h"
#include "RenderComponent.h"
#include <iostream>

#define PI 3.1416

bool IA_Graf_Checkarea ::run()
{

   std::vector<Area*> Areas = ((IAManager*)owner->getComponent<IAComponent>()->getManager())->getGPS()->getAreas();
    

    int ai=0; 
    int af=0;
    for (std::size_t i = 0; i< Areas.size(); i++)
    {
        if(Areas[i]->checkinArea(owner->getX(),owner->getY()))
        {
            ai = i;
        }

        if(Areas[i]->checkinArea(main->getX(),main->getY()))
        {

            af = i;
        }

    }

    if(af == ai)
    {
        if(owner->getComponent<IAComponent>()->onRoute){
            owner->getComponent<IAComponent>()->onRoute = false;
           
        }
        
        return false;
    }

   // if(owner->getComponent<IAComponent>()->onRoute)
    //return false;
   

    return true;
}

bool IA_Graf_LaunchGPS::run()
{
    GPS* gps = ((IAManager*)owner->getComponent<IAComponent>()->getManager())->getGPS();

  owner->getComponent<IAComponent>()->route = gps->getWay(owner->getX(),owner->getY(),main->getX(),main->getY());
    
     owner->getComponent<IAComponent>()->onRoute = true;
    
    return true;
}

bool IA_Graf_CheckRuta::run()
{
    if(owner->getComponent<IAComponent>()->onRoute){
   
        return true;
    }

    return false;
}

bool IA_Graf_FollowRuta::run()
{

    std::vector<float> ruta = owner->getComponent<IAComponent>()->route;


    std::vector<float>::iterator iter = ruta.begin();

    if(!owner->getComponent<IAComponent>()->onRoute){
       owner->getComponent<IAComponent>()->onRoute = true;
    }

    float nextX = *iter;

    iter++;

    float nextY = *iter;

    float d = sqrt(pow(nextX - owner->getX(),2) + pow(nextY - owner->getY(), 2));


    float rZ = atan2(owner->getY() - nextY, owner->getX() - nextX);
    rZ += PI/2.0;
    rZ = rZ * 180/PI;
    if (rZ < 0)
        rZ += 360;

    if(fabs(prevD - d) < 0.3F) rZ +=20;
    
    owner->getComponent<BPhysicComponent>()->setVelocity(rZ, true);
    
    IAComponent* iac = owner->getComponent<IAComponent>();
    if(!iac->walking)
    {
        iac->walking = true;
        if(iac->mode == 0)
        {
            owner->getComponent<RenderComponent>()->setAnimation((char*)"res/animations/Soldado/Walk/Walk_Soldier_", 25);
        }else
        {
            owner->getComponent<RenderComponent>()->setAnimation((char*)"res/animations/Aldeana/Walk/Walk_Aldeana_", 24);            
        }
        
    }

    float vel = owner->getComponent<BPhysicComponent>()->getvMax();
    if(vel == 0.f) owner->getComponent<BPhysicComponent>()->setvMax(5.f);
    prevD = d;
    if( ruta.size() > 2)
    {
         distancia = .4F;
    }else{
        if(distancia == .4F)
            distancia = 4.1F;
    }


    if(round(fabs(d)) < distancia  )
    {
        int tam = ruta.size();
        if(tam == 2){
            iter++;
            iter--;
        }
        ruta.erase(iter);
        iter--;
        ruta.erase(iter);
        
        iter = ruta.begin();
    owner->getComponent<IAComponent>()->route = ruta;

    }


    if(ruta.empty()){
        owner->getComponent<IAComponent>()->onRoute = false;
    
    }


    return true;
}



bool IA_Graf_FollowPatrol::run()
{

    std::vector<float> ruta = owner->getComponent<IAComponent>()->currentpatrollingRoute;


    std::vector<float>::iterator iter = ruta.begin();

    float nextX = *iter;

    iter++;

    float nextY = *iter;

    float rZ = atan2(owner->getY() - nextY, owner->getX() - nextX);
    rZ += PI/2.0;
    rZ = rZ * 180/PI;
    if (rZ < 0)
        rZ += 360;


    owner->getComponent<BPhysicComponent>()->setVelocity(rZ, true);

    IAComponent* iac = owner->getComponent<IAComponent>();
    if(!iac->walking)
    {
        iac->walking = true;
        if(iac->mode == 0)
        {
            owner->getComponent<RenderComponent>()->setAnimation((char*)"res/animations/Soldado/Walk/Walk_Soldier_", 25);
        }else
        {
            owner->getComponent<RenderComponent>()->setAnimation((char*)"res/animations/Aldeana/Walk/Walk_Aldeana_", 24);            
        }
        
    }


    float vel = owner->getComponent<BPhysicComponent>()->getvMax();
    if(vel == 0.f) owner->getComponent<BPhysicComponent>()->setvMax(5.f);
    float d = sqrt(pow(nextX - owner->getX(),2) + pow(nextY - owner->getY(), 2));
   

    if(round(fabs(d)) < .6F  )
    {
        int tam = ruta.size();
        if(tam == 2){
            iter++;
            iter--;
        }
        ruta.erase(iter);
        iter--;
        ruta.erase(iter);
        
        iter = ruta.begin();
    owner->getComponent<IAComponent>()->currentpatrollingRoute = ruta;

    }


    if(ruta.empty()){
       
         owner->getComponent<IAComponent>()->currentpatrollingRoute =  owner->getComponent<IAComponent>()->patrollingRoute;

    }


    return true;
}



bool IA_Graf_CheckPatrolling::run()
{

    if(owner->getComponent<IAComponent>()->onPatrol){
   
        return true;
    }

    return false;
}

bool IA_Graf_GoPatrol::run()
{

    owner->getComponent<IAComponent>()->onPatrol = true;
   
        return true;
    
}


bool IA_Graf_LaunchGPSToPatrol::run()
{
    GPS* gps = ((IAManager*)owner->getComponent<IAComponent>()->getManager())->getGPS();

    std::vector<float> ruta = owner->getComponent<IAComponent>()->patrollingRoute;

    std::vector<float>::iterator iter = ruta.begin();

    float nextX = *iter;

    iter++;

    float nextY = *iter;

  owner->getComponent<IAComponent>()->route = gps->getWay(owner->getX(),owner->getY(),nextX,nextY);
    
     owner->getComponent<IAComponent>()->onRoute = true;
     owner->getComponent<IAComponent>()->onPatrol = false;

    
    return true;
}



bool IA_Graf_CheckareaPatrol::run()
{

   std::vector<Area*> Areas = ((IAManager*)owner->getComponent<IAComponent>()->getManager())->getGPS()->getAreas();
    
     std::vector<float> ruta = owner->getComponent<IAComponent>()->patrollingRoute;

    std::vector<float>::iterator iter = ruta.begin();

    float nextX = *iter;

    iter++;

    float nextY = *iter;
    int ai=0; 
    int af=0;
    for (std::size_t i = 0; i< Areas.size(); i++)
    {
        if(Areas[i]->checkinArea(owner->getX(),owner->getY()))
        {
            ai = i;
        }

        if(Areas[i]->checkinArea(nextX,nextY))
        {

            af = i;
        }

    }

    if(af == ai)
    {
        if(owner->getComponent<IAComponent>()->onRoute){
            owner->getComponent<IAComponent>()->onRoute = false;
           
        }
        
        return false;
    }

    if(owner->getComponent<IAComponent>()->onRoute)
        return false;
   

    return true;
}