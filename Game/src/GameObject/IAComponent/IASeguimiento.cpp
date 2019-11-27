#include "IASeguimiento.h"
#include "BPhysicComponent.h"
#include "IAComponent.h"
#include "RenderComponent.h"
#include <iostream>
#include <cmath>

const float PI  = 3.14159265359f;

bool IA_Seg_ToPlayer::run()
{
    bool iw = false;

    float d = round(sqrt(pow(main->getX() - owner->getX(),2) + pow(main->getY() - owner->getY(),2)));
     
    
    float rZ = atan2(owner->getY() - main->getY(), owner->getX() - main->getX());
    rZ += PI/2.0;
    rZ = rZ * 180/PI;
    if (rZ < 0)
        rZ += 360;
    if(d< 4.f) {
        owner->getComponent<BPhysicComponent>()->setvMax(0.f);
    }else{
        owner->getComponent<BPhysicComponent>()->setvMax(5.f);
        iw = true;
    }

    owner->getComponent<BPhysicComponent>()->setVelocity(rZ, true);

    IAComponent* iac = owner->getComponent<IAComponent>();
    if(iw != iac->walking)
    {
        iac->walking = iw;
        if(iw)
        {
            owner->getComponent<RenderComponent>()->setAnimation((char*)"res/animations/Soldado/Walk/Walk_Soldier_", 25);
        }else
        {
            owner->getComponent<RenderComponent>()->setMesh((char*)"res/animations/Soldado/Walk/Walk_Soldier_1.obj");            
        }    
    }

    return true;
}

