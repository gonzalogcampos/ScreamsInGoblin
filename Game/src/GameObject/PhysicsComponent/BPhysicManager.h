#pragma once
#include "PhysicBullet.h"
#include "Manager.h"
#include <iostream>
class GameObject;
class BPhysicManager : public Manager
{
    private:
        PhysicBullet* physics;
        BPhysicManager(){init();  gContactAddedCallback = this->callbackFunc;}
    public:
        ~BPhysicManager(){delete physics;}

        static BPhysicManager* getInstance(){
            static BPhysicManager only_instance;
            return &only_instance;
        }
        static bool callbackFunc(btManifoldPoint& cp, const btCollisionObjectWrapper* obj1, int id1, int index1, const btCollisionObjectWrapper* obj2, int id2, int index2);
        void createComponent(GameObject* owner, float xsize, float ysize, float zsize, float mass, int physicType);
        void createComponent(GameObject* owner, char* filename);
        void updateAll(float dt);
        void clear();
        void init();
        PhysicBullet* getPhysics(){return physics;}
};