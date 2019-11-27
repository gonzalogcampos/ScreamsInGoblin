#include "ShootComponent.h"
#include "GameObject.h"

void ShootComponent::shoot(){   //If the elapsed time is more
    if(lastShoot>cadencia){   //than the cadence it shoots and restarts lastShoot
        lastShoot = 0.f;
        wantsShoot = true;
    }  
}

bool ShootComponent::update(float dt){  //Ads the elapsed time to las shoot
    lastShoot+=dt;                      //returns the shoot and puts it on false
    if(wantsShoot){
        wantsShoot = false;
        return true;
    }
    return false;
}


float ShootComponent::getX(){return gameObject->getX();}

float ShootComponent::getY(){
    return gameObject->getY();
}

float ShootComponent::getRZ(){
    return gameObject->getRZ();
}