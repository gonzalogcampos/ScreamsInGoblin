#include "Nodo.h"

class GameObject;
class IA_Plan_InSight : public Nodo
{
    public:

    IA_Plan_InSight(GameObject* o, GameObject* m){owner = o; main = m;}
    virtual ~IA_Plan_InSight(){}

    bool run() override;
    GameObject * owner;
    GameObject* main;

};

class IA_Plan_DidICollide : public Nodo
{

    public:

    IA_Plan_DidICollide (GameObject* o){owner = o;}
    virtual ~IA_Plan_DidICollide(){}

    bool run() override;
    GameObject * owner;

};

class IA_Plan_ChangeDirection : public Nodo
{

    public:

    IA_Plan_ChangeDirection (GameObject* o){owner = o;}
    virtual ~IA_Plan_ChangeDirection(){}

    bool run() override;
    GameObject * owner;

};

class IA_Plan_LODSoldier : public Nodo
{

    public:

    IA_Plan_LODSoldier (GameObject* o, GameObject* m){owner = o; main = m;}
    virtual ~IA_Plan_LODSoldier(){}

    bool run() override;
    GameObject * owner;
    GameObject* main;

};

class IA_Plan_LODVillager : public Nodo
{

    public:

    IA_Plan_LODVillager (GameObject* o, GameObject* m){owner = o; main = m;}
    virtual ~IA_Plan_LODVillager(){}

    bool run() override;
    GameObject * owner;
    GameObject* main;

};

