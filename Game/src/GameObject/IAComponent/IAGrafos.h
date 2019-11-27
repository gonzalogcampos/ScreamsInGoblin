#include "Nodo.h"

class GameObject;
class IA_Graf_Checkarea : public Nodo
{
    public:

    IA_Graf_Checkarea(GameObject* o, GameObject* m){owner = o;main = m;}
    virtual ~IA_Graf_Checkarea(){}

    bool run() override;
    GameObject * owner;
    GameObject * main;
    

};

class IA_Graf_LaunchGPS : public Nodo
{
    public:

    IA_Graf_LaunchGPS(GameObject* o, GameObject* m){owner = o;main = m;}
    virtual ~IA_Graf_LaunchGPS(){}

    bool run() override;
    GameObject * owner;
    GameObject * main;
    

};

class IA_Graf_CheckRuta : public Nodo
{
    public:

    IA_Graf_CheckRuta(GameObject* o){owner = o;}
    virtual ~IA_Graf_CheckRuta(){}

    bool run() override;
    GameObject * owner;    

};

class IA_Graf_FollowRuta : public Nodo
{
    public:

    IA_Graf_FollowRuta(GameObject* o, float dist){owner = o; distancia = dist;}
    virtual ~IA_Graf_FollowRuta(){}

    bool run() override;
    GameObject * owner;    
    float distancia = .5f;
    float prevD = 100.F; 
};


class IA_Graf_FollowPatrol : public Nodo
{
    public:

    IA_Graf_FollowPatrol(GameObject* o){owner = o;}
    virtual ~IA_Graf_FollowPatrol(){}

    bool run() override;
    GameObject * owner;    
};

class IA_Graf_CheckPatrolling : public Nodo
{
    public:

    IA_Graf_CheckPatrolling(GameObject* o){owner = o;}
    virtual ~IA_Graf_CheckPatrolling(){}

    bool run() override;
    GameObject * owner;    

};


class IA_Graf_GoPatrol : public Nodo
{
    public:

    IA_Graf_GoPatrol(GameObject* o){owner = o;}
    virtual ~IA_Graf_GoPatrol(){}

    bool run() override;
    GameObject * owner;    

};

class IA_Graf_LaunchGPSToPatrol : public Nodo
{
    public:

    IA_Graf_LaunchGPSToPatrol(GameObject* o){owner = o;}
    virtual ~IA_Graf_LaunchGPSToPatrol(){}

    bool run() override;
    GameObject * owner;    

};



class IA_Graf_CheckareaPatrol : public Nodo
{
    public:

   IA_Graf_CheckareaPatrol(GameObject* o){owner = o;}
    virtual ~IA_Graf_CheckareaPatrol(){}

    bool run() override;
    GameObject * owner;    

};