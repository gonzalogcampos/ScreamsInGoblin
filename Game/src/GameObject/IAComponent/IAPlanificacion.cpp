#include "IAPlanificacion.h"
#include <cmath>
#include <ctime> 
#include <cstdlib>
#include "IAComponent.h"
#include "BPhysicComponent.h"
#include "ShootComponent.h"
#include "GameObject.h"
#include "RenderComponent.h"
#include "IAManager.h"
#include "BPhysicManager.h"
#include <iostream>

/*
Salta si el personaje entra a menos de 10 unidades de distancia de portador de la ia

calcula las distancias entre los centros y devuelve true
*/
bool IA_Plan_InSight::run()
{

  //  float dx = main->getX() - owner->getX();
  //  float dy = main->getY() - owner->getY();

// && main==PhysicBullet::getInstance()->rayTest(owner->getX(),owner->getY(), owner->getZ(),owner->getRZ()+1)
       //     && main==PhysicBullet::getInstance()->rayTest(owner->getX(),owner->getY(), owner->getZ(),owner->getRZ()-1)

    //if(fabs(dx) <= 15  && fabs(dy) <= 15){
       // if(main==PhysicBullet::getInstance()->rayTest(owner->getX(),owner->getY(), owner->getZ(),owner->getRZ())
    //      )
     //   {
         //   owner->getComponent<ShootComponent>()->shoot();
        

        //if(owner->getComponent<IAComponent>()->onRoute){
         //   return false;
       // }else{
     ///   return true;
     //   }
      //  }
   // }
    //std::cout << "PERSONAJE PERDIDO!!! \n";
  //  return false;

      float d = round(sqrt(pow(main->getX() - owner->getX(),2) + pow(main->getY() - owner->getY(),2)));
      if(d<15)
      {


            float Ax = owner->getX();
            float Ay = owner->getY();

            float Bx = Ax  -cos((owner->getRZ()-60)*M_PI/180 - M_PI/2) * 30;
            float By = Ay  -sin((owner->getRZ()-60)*M_PI/180 - M_PI/2) * 30;

            float Cx = Ax -cos((owner->getRZ()+60)*M_PI/180 - M_PI/2) * 30;
            float Cy = Ay -sin((owner->getRZ()+60)*M_PI/180 - M_PI/2) * 30;

            float s1 = Cy - Ay;
			float s2 = Cx - Ax;
			float s3 = By - Ay;
			float s4 = main->getY() - Ay;

			float w1 = (Ax * s1 + s4 * s2 - main->getX()* s1) / (s3 * s2 - (Bx-Ax) * s1);
            float w2 = (s4- w1 * s3) / s1;

           if(w1 >= 0 && w2 >= 0 && (w1 + w2) <= 1){
               if(main==BPhysicManager::getInstance()->getPhysics()->rayTest(owner->getX(),owner->getY(), owner->getZ(),main->getX(),main->getY(), main->getZ())){
                owner->getComponent<ShootComponent>()->shoot();
                IAManager::getInstance()->attacking();
                 return true;
               }
            }

               


      }
           return false;

      
}

bool IA_Plan_DidICollide::run()
{

    if(owner->getComponent<IAComponent>()->didIcollide){
        owner->getComponent<IAComponent>()->didIcollide = false;
        return true;
    }

    return false;
}

bool IA_Plan_ChangeDirection::run()
{

    std::srand((unsigned) time(0));
    int i = (rand()%4)+1;
    if(i ==1){
        owner->getComponent<BPhysicComponent>()->moveObject(0,1,0, 0.f, 0.f);
        return true;
    }
      if(i ==2){
        owner->getComponent<BPhysicComponent>()->moveObject(0,-1,0, 0.f, 0.f);
        return true;
    }
      if(i ==3){
        owner->getComponent<BPhysicComponent>()->moveObject(1,0,0, 0.f, 0.f);
        return true;
    }
      if(i ==4){
        owner->getComponent<BPhysicComponent>()->moveObject(-1,0,0, 0.f, 0.f);
        return true;
    }

return false;

}

bool IA_Plan_LODSoldier::run()
{

    float d = round(sqrt(pow(main->getX() - owner->getX(),2) + pow(main->getY() - owner->getY(),2)));

    //std::cout << "Distancia al player " << d <<"\n";
    if(d>60.f)
    {
        return true;
    }else{
        if(d>25)
        {
            owner->getComponent<IAComponent>()->onRoute = false;
            owner->getComponent<IAComponent>()->onPatrol = true;
            return false;

        }
    }
    
    return false;
}

bool IA_Plan_LODVillager::run()
{

    float d = round(sqrt(pow(main->getX() - owner->getX(),2) + pow(main->getY() - owner->getY(),2)));

    //std::cout << "Distancia al player " << d <<"";
    if(d>65.f)
    {
    //std::cout << " lejos y me clavo" <<"\n";

        return true;
    }else{
        if(d>50)
        {
            owner->getComponent<IAComponent>()->onRoute = false;
            owner->getComponent<IAComponent>()->onPatrol = true;
      //      std::cout << " media y deberia moverme" <<"\n";

            return false;

        }


    }
    //std::cout << " hago de to" <<"\n";
    
    return false;
}