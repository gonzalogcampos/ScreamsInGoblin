#include "LifeComponent.h"
#include "GameObject.h"
#include "GameValues.h"

void LifeComponent::looseLife(float d){     //Gets by parametre a int damage from the attacker
    shield -= d;
    if(shield<0.f)
    {
        life += shield; //Sets decreased life
        shield = 0.f;
    }
}

void LifeComponent::addLife(float l){
    life+=l;
}


void LifeComponent::update(float dt)
{
    if(life<=0){
        gameObject->setKill(true);
    }

    if(!decreases)
        return;

    elapsedTime+=dt;
    if(elapsedTime>1.f)
    {
        elapsedTime = 0.f;
        life-=gv::PLAYER_LIFE_DECREASE;
    }
}