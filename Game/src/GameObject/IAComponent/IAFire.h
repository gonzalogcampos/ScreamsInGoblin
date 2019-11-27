#include "Nodo.h"

class GameObject;
class IA_Fire_seefire : public Nodo
{
    public: 
        IA_Fire_seefire(GameObject* o){owner = o;}
        virtual ~IA_Fire_seefire(){}

        bool run() override;
        GameObject * owner;
       
    
};
class IA_Fire_searchWell : public Nodo
{
    public: 
        IA_Fire_searchWell(GameObject* o){owner = o;}
        virtual ~IA_Fire_searchWell(){}

        bool run() override;
        GameObject * owner;
       
    
};

class IA_Fire_GPStoSpawn : public Nodo
{
    public: 
        IA_Fire_GPStoSpawn(GameObject* o){owner = o;}
        virtual ~IA_Fire_GPStoSpawn(){}

        bool run() override;
        GameObject * owner;
       
    
};

class IA_Fire_GPStoWell : public Nodo
{
    public: 
        IA_Fire_GPStoWell(GameObject* o){owner = o;}
        virtual ~IA_Fire_GPStoWell(){}

        bool run() override;
        GameObject * owner;
       
    
};

class IA_Fire_haveWater : public Nodo
{
    public: 
        IA_Fire_haveWater(GameObject* o){owner = o;}
        virtual ~IA_Fire_haveWater(){}

        bool run() override;
        GameObject * owner;
       
    
};

class IA_fire_StillOnFire : public Nodo
{
    public: 
        IA_fire_StillOnFire(GameObject* o){owner = o;}
        virtual ~IA_fire_StillOnFire(){}

        bool run() override;
        GameObject * owner;
       
    
};

class IA_Fire_HaveSpawn : public Nodo
{
    public: 
        IA_Fire_HaveSpawn(GameObject* o){owner = o;}
        virtual ~IA_Fire_HaveSpawn(){}

        bool run() override;
        GameObject * owner;
       
    
};