#include "Component.h"


class ProjectileComponent;
class WoodComponent:public Component
{
    private:
        float life;
        bool burning;
        int buckets;
        int team;
    public:
        WoodComponent(GameObject* owner, Manager* manager, float life, int team = 1):Component(owner, manager)
        {
            this->life = life;
            burning = false;
            buckets=0;
            this->team = team;
        }
        ~WoodComponent(){}


        void setBurning(bool b);
        bool getBurning(){return burning;}
        int getTeam(){return team;}
        void update(float dt);
        void addBucket();
        void dealDamage(ProjectileComponent* projectile);

};