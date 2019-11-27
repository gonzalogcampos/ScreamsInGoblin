#include "BPhysicComponent.h"
#define PI 3.14159265

BPhysicComponent::BPhysicComponent(GameObject* owner, Manager* manager, float xsize, float ysize, float zsize, float mass, int physicType) : Component(owner, manager)
{
    btVector3 position = btVector3(owner->getX(), owner->getY(), owner->getZ());
    btVector3 size = btVector3(xsize, ysize, zsize);

    rbody = BPhysicManager::getInstance()->getPhysics()->createRigidBody(position, size, mass, physicType);

    btTransform tr = rbody->getCenterOfMassTransform();
    btQuaternion quat;
    quat.setEulerZYX(owner->getRZ()*PI/180,owner->getRY()*PI/180, owner->getRX()*PI/180); //or quat.setEulerZYX depending on the ordering you want
    tr.setRotation(quat);

    rbody->setCenterOfMassTransform(tr);

    rbody->setUserPointer((void *)(gameObject));
}

BPhysicComponent::BPhysicComponent(GameObject* owner, Manager* manager, char* filename) : Component(owner, manager)
{
    rbody = BPhysicManager::getInstance()->getPhysics()->createFromFile(filename);

    //---------------- Esta Parte esta por valorar-------------
        btTransform tr = rbody->getCenterOfMassTransform();
        btQuaternion quat;
        quat.setEulerZYX(owner->getRZ()*PI/180,owner->getRY()*PI/180, owner->getRX()*PI/180); //or quat.setEulerZYX depending on the ordering you want
        tr.setRotation(quat);
        rbody->setCenterOfMassTransform(tr);

    rbody->setUserPointer((void *)(gameObject));
}

void BPhysicComponent::update()
{
    btVector3 Point = rbody->getCenterOfMassPosition();
    gameObject->setX(Point[0]);
    gameObject->setY(Point[1]);
    gameObject->setZ(Point[2]);

    btQuaternion mRotation;
    btTransform mTransform;
    mTransform = rbody->getCenterOfMassTransform();
    mRotation = mTransform.getRotation();
    btScalar yawZ, pitchY, rollX;
    mRotation.getEulerZYX(yawZ, pitchY, rollX);
    
	
    gameObject->setRX(rollX*180/PI);
    gameObject->setRY(pitchY*180/PI);
    gameObject->setRZ(yawZ*180/PI);

}

void BPhysicComponent::moveObject(float x, float y, float z, float tx, float ty)
{
    
    float vX, vY;
    if(x<0)
        vX = -1;
    else if(x==0)
        vX = 0;
    else if(x>0)
        vX = 1;

    if(y<0)
        vY = -1;
    else if(y==0)
        vY = 0;
    else if(y>0)
        vY = 1;


    //Comprobar vMax
    float length = sqrt(pow(vX, 2) + pow(vY, 2));
    if(length!=0.f){
        vX = (vX/length)*vMax;
        vY = (vY/length)*vMax;
    }else{
        vX=0.f;
        vY=0.f;
    }

    float rZ = atan2(gameObject->getY() - ty, gameObject->getX() - tx);
    rZ += PI/2.0;
    rZ = rZ * 180/PI;
    if (rZ < 0)
        rZ += 360;
    rbody->setLinearVelocity(btVector3(vX, vY, z));

    btTransform tr = rbody->getCenterOfMassTransform();
    btQuaternion quat;
    quat.setEulerZYX(rZ*PI/180,0, 0); //or quat.setEulerZYX depending on the ordering you want
    tr.setRotation(quat);

    rbody->setCenterOfMassTransform(tr);

}


void BPhysicComponent::setVelocity(float x, float y, float z)
{
    rbody->setLinearVelocity( btVector3(x, y, z) );
}


void BPhysicComponent::setVelocity(float rz, bool adRot)
{

    float x = vMax * (- cos(rz*PI/180 - PI/2));
    float y = vMax * (- sin(rz*PI/180 - PI/2)); 

    rbody->setLinearVelocity( btVector3(x, y, 0) );
    
    if( adRot)
    {
        btTransform tr = rbody->getCenterOfMassTransform();
        btQuaternion quat;
        quat.setEulerZYX(rz*PI/180,0, 0); //or quat.setEulerZYX depending on the ordering you want
        tr.setRotation(quat);
        rbody->setCenterOfMassTransform(tr);
    }
}