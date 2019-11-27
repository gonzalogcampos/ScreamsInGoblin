#pragma once
#include "Component.h"
#include "ProjectileFabric.h"

class GameObject;
class ShootComponent : public Component{
    private:
        float           lastShoot;          //Elapsed time since last shoot
        float           cadencia;           //Shoots per second
        ProjectileType  type;               //Kind of bullet o create
        float           distance;           //Distance of the canon
        bool            wantsShoot;
        int team;
    
    public:

        //Constructor
        ShootComponent(GameObject* g, Manager* m, float cadencia, float distance, ProjectileType type, int team = 1):Component(g, m){
            wantsShoot = false;
            lastShoot = 0.f;
            this->cadencia = cadencia;
            this->distance = distance;
            this->type = type;
            this->team  = team;
        }
        ~ShootComponent(){}
        //Getters&&Setters
        float getCadencia(){return cadencia;}
        ProjectileType getType(){return type;}

        void setCadencia(float c){cadencia=c;}
        void setType(ProjectileType t){type = t;}

        //Methods
        void shoot();
        bool update(float dt);
        float getX();
        float getY();
        float getRZ();
        float getDistance(){return distance;}
        int getTeam(){return team;}
};
