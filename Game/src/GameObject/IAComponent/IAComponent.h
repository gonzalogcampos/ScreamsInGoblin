#pragma once
#include <map>
#include "Component.h"

class GameObject;
class Waypoint;
class Nodo;
class Grafo;
class IAComponent : public Component
{

    public:

    IAComponent(GameObject * owner, Manager * m, GameObject* main): Component(owner, m), main(main)
    {
      
        setPatrollingRoute(owner);
    }
    ~IAComponent(){Clear();}

    void Initialice(int mode);
    void run();
    void Clear();
    void setPatrollingRoute(GameObject* owner);

  
    std::map<std::string,Nodo*> mapa;

    GameObject* main;

    bool didIcollide = false;
    bool onRoute = false;
    bool onPatrol = false;
    bool walking = true;
    int mode;

    std::vector<float> route;
    std::vector<float> patrollingRoute;
    std::vector<float> currentpatrollingRoute;



    GameObject* spawnOnFire;
    GameObject* pozoObjetivo;

};