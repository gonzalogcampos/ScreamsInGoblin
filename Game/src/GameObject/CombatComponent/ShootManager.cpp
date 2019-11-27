#include "ShootManager.h"
#include "ShootComponent.h"
#include "GameObject.h"
#include <cmath>

#define PI 3.14159265


void ShootManager::updateAll(float dt)
{                                                                       //Checks which component has SHOOTED getting the boolean shooted, if true, creates a projectile and 
    for(size_t i=0; i < components.size(); i++)
    {                                                                   //Check vector of ShootComponent
        ShootComponent* shooter = (ShootComponent*) components[i];      //get Component
        if (shooter->update(dt))
        {                                                               //Create gameObject Bullet.
            float x = shooter->getX() + shooter->getDistance() * -cos(-PI/2 + shooter->getRZ()*PI/180);
            float y = shooter->getY() + shooter->getDistance() * -sin(-PI/2 + shooter->getRZ()*PI/180);
            createProjectile(x, y, shooter->getRZ(), shooter->getType(), shooter->getTeam());
        }
    }
}

void ShootManager::createProjectile(float x, float y, float rz, ProjectileType tipo, int team)
{
    fabric->createProjectile(x, y, rz, tipo, team);
}


void ShootManager::createComponent(GameObject *owner, float cadencia, float distance, ProjectileType tipo, int team)
{
    components.push_back(new ShootComponent(owner, this, cadencia, distance, tipo, team));
    owner->addComponent(components[components.size()-1]);
}
