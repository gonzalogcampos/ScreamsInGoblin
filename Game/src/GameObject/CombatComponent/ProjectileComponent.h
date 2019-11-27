#pragma once
#include "Component.h"

class GameObject;
class LifeComponent;
class ProjectileComponent : public Component{
     private:
        float damage;
        int team;
    public:
        //Constructor
        ProjectileComponent(GameObject* g, Manager* m, float damage,  int team):Component(g, m){
            this->damage = damage;
            this->team = team;
        }
        ~ProjectileComponent(){}

        //Setter&Getter
        float getDamage()         {return damage;}
        void setDamage(float d)   {damage = d;}
        int getTeam(){return team;}

        //Methods
        void dealDamage(LifeComponent* l);
};
