#include "PhysicBullet.h"
#include <btBulletWorldImporter.h>
#include "GameValues.h"
#include <iostream>

#define PI 3.141592
bool PhysicBulletWasCleared = false;


PhysicBullet::~PhysicBullet(){clear();}

void PhysicBullet::clear()
{
    PhysicBulletWasCleared = true;
    int i;
	for (i=_world->getNumCollisionObjects()-1; i>=0 ;i--)
	{
		btCollisionObject* obj = _world->getCollisionObjectArray()[i];

		btRigidBody* body = btRigidBody::upcast(obj);
		if (body && body->getMotionState())
		{

			while (body->getNumConstraintRefs())
			{
				btTypedConstraint* constraint = body->getConstraintRef(0);
				_world->removeConstraint(constraint);
				delete constraint;
			}
			delete body->getMotionState();
			_world->removeRigidBody(body);
		} else
		{
			_world->removeCollisionObject( obj );
		}
        if(_fileLoader)
        {
            _fileLoader->deleteAllData();
            delete _fileLoader;
            _fileLoader = nullptr;
        }
		delete obj;
	}

	//delete collision shapes
	for (int j=0;j<_collisionShapes.size();j++)
	{
		btCollisionShape* shape = _collisionShapes[j];
		delete shape;
	}
	_collisionShapes.clear();
    
    delete _broadphase;
    delete _collisionConfiguration;
    delete _dispatcher;
    delete _solver;
    delete _world;
}

void PhysicBullet::removeRigidBody(btRigidBody* rigidbody)
{
    if(PhysicBulletWasCleared)
        return;


    if(rigidbody && rigidbody->getMotionState())
    {
        delete rigidbody->getMotionState();
    }
    for(int i=0; i<_collisionShapes.size();i++)
    {
        if(rigidbody->getCollisionShape()==_collisionShapes[i])
        {
            _collisionShapes.removeAtIndex(i);
            break;
        }
    }
    delete rigidbody->getCollisionShape();


        _world->removeRigidBody(rigidbody);

    delete rigidbody;
}

void PhysicBullet::init()
{
    //Initialize the scene where the physics take part. It defines how collision are going to take part and resolved.

    //btDbvtBroadphase = uses a fast dynamic bounding volume hierarchy based on AABB tree
    //Collision has 2 phases: 1º broad that discards all objects that cannot collide and 
    //2º narrow that creates a list with all the objects that can collide (this method is 
    //slower). DbvtBroadphase is specially used for AABB tree implementation.
    _broadphase = new btDbvtBroadphase();


    //Responsable of the collision management and detection. Contains default setup for memory, collision setup.
    _collisionConfiguration = new btDefaultCollisionConfiguration();
    _dispatcher = new btCollisionDispatcher(_collisionConfiguration);

    //Responsable of the correct interaction, taking into account gravity,
    //game logic supplied forces, collisions, and hinge constraints.
    _solver = new btSequentialImpulseConstraintSolver();

    //Creation of the world and input the configurations
    _world = new btDiscreteDynamicsWorld(_dispatcher, _broadphase, _solver, _collisionConfiguration);

    //Set gravity to physics in y=-9,8
    _world->setGravity(btVector3(0,0,gv::PHYSICS_GRAVITY));
}

btRigidBody* PhysicBullet::createRigidBody(const btVector3 &initPos, const btVector3 &scale, btScalar mass, int physicType)
{
    //Matrix 4x4 for position and rotation
    btTransform transform;
	transform.setIdentity();
	transform.setOrigin(initPos);

    //Used for locate position and rotation of every object in each iteration
    btDefaultMotionState*  motionState = new btDefaultMotionState(transform);

    //We create a collision with box shape with sides 100. Each parametre starts from the center of the shape
    //Afterwards we create a RigidBody that wont modifate its shape after collision. 
    //Body parametres = (mass,motionstate,collisionshape,)
    btCollisionShape*   boxyBox = new btBoxShape(scale);

    btVector3 LocalInertia;                                                                 
    boxyBox->calculateLocalInertia(mass, LocalInertia);

    btRigidBody::btRigidBodyConstructionInfo rbInfo(mass, motionState, boxyBox,LocalInertia);

	btRigidBody* body = new btRigidBody(rbInfo);
    
    //Makes a rigidbody inot kinematic so we can control it
    if(physicType==1)
        body->setCollisionFlags(body->getCollisionFlags()|btCollisionObject::CF_KINEMATIC_OBJECT);

    body->setActivationState( DISABLE_DEACTIVATION );
    
    //Allows to use the pointer and the callback with this object
    body->setCollisionFlags(body->getCollisionFlags() | btCollisionObject::CF_CUSTOM_MATERIAL_CALLBACK);
    
    //Array of shapes in the world
	//Better re-use collision shapes than rigidbodies
    _collisionShapes.push_back(boxyBox);

    //Pointer to the last shape added to de array
    //body->setUserPointer(_collisionShapes[_collisionShapes.size()-1]);
    //We add the body to the world so it can interactuate
    _world->addRigidBody(body);

    
    return body;
}



void PhysicBullet::iteration(float delta)
{
    //Update the objects in the world based on the step parametres of time
    //Parametres = stepSimulation(btScalar timeStep,int maxSubSteps=1,btScalar fixedTimeStep=btScalar(1.)/btScalar(60.));
    //timeStep is the time passed after last simulation.
    _world->stepSimulation(delta*gv::PHYSICS_VELOCITY);

}

void* PhysicBullet::rayTest(float x, float y, float z, float rz, float distance)
{

    float xi = x + 2 * -cos(-PI/2 + rz*PI/180);
    float yi = y + 2 * -sin(-PI/2 + rz*PI/180);
    float zi = z;
    float xf = x + distance * -cos(-PI/2 + rz*PI/180);
    float yf = y + distance * -sin(-PI/2 + rz*PI/180);
    float zf = z;
    btVector3 btRayFrom = btVector3(xi, yi, zi);
    btVector3 btRayTo = btVector3(xf, yf, zf);

    btCollisionWorld::ClosestRayResultCallback rayCallback(btRayFrom,btRayTo);
    _world->rayTest(btRayFrom, btRayTo, rayCallback);
    if(rayCallback.hasHit())
    {
        return rayCallback.m_collisionObject->getUserPointer();
    }
    return NULL;
}

void* PhysicBullet::rayTest(float xi, float yi, float zi, float xf, float yf, float zf)
{
    btVector3 btRayFrom = btVector3(xi, yi, zi);
    btVector3 btRayTo = btVector3(xf, yf, zf);

    btCollisionWorld::ClosestRayResultCallback rayCallback(btRayFrom,btRayTo);
    _world->rayTest(btRayFrom, btRayTo, rayCallback);
    if(rayCallback.hasHit())
    {
        return rayCallback.m_collisionObject->getUserPointer();
    }
    return NULL;
}

btRigidBody* PhysicBullet::createFromFile(char* filename)
{
    btBulletWorldImporter* fileLoader = new btBulletWorldImporter(_world);
    fileLoader->loadFile(filename);
    btCollisionObject* obj = fileLoader->getRigidBodyByIndex(0);
    btRigidBody* rbody = btRigidBody::upcast(obj);
    rbody->getCollisionShape()->setLocalScaling(btVector3(-1, 1, 1));
    _world->setGravity(btVector3(0,0, gv::PHYSICS_GRAVITY));

    _fileLoader = fileLoader;
  
    return rbody;
}