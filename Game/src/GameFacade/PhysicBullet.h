#pragma once 
#include <btBulletDynamicsCommon.h>
#include <btBulletWorldImporter.h>



class PhysicBullet{
    private:
        btBroadphaseInterface*                      _broadphase;
        btDefaultCollisionConfiguration*            _collisionConfiguration;
        btCollisionDispatcher*                      _dispatcher;
        btSequentialImpulseConstraintSolver*        _solver;
        btDynamicsWorld*                            _world;
        btAlignedObjectArray<btCollisionShape*>     _collisionShapes;
        btBulletWorldImporter*                      _fileLoader;
    public:
        PhysicBullet(){init();}
        ~PhysicBullet();

        //static PhysicBullet* getInstance(){
        //    static PhysicBullet only_instance;
        //    return &only_instance;
        //}
    

        void removeRigidBody(btRigidBody* rigidbody);


        btRigidBody* createRigidBody(const btVector3 &TPosition, const btVector3 &TScale, btScalar TMass, int physicType);
        btRigidBody* createFromFile(char* filename);
        void iteration(float d);
        void* rayTest(float x, float y, float z, float rz, float distance = 100.f);
        void* rayTest(float xi, float yi, float zi, float xf, float yf, float zf);
        void init();
        void clear();
};
