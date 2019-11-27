#include "CameraComponent.h"
#include "GameValues.h"
#include "CameraManager.h"
#include <cmath>

float hit_time = 0.f;


void CameraComponent::hitCamera()
{
    hit_time = hit_time + gv::CAMERA_HIT_TIME;
}
void CameraComponent::update(float dt)
{
    float h = 0.f;
    if(hit_time<0.f)
    {
        hit_time = 0.f;
    }else if(hit_time!=0.f)
    {
        hit_time=hit_time-dt;
        h = gv::CAMERA_HIT_DISTANCE*sin(2*M_PI*(hit_time/gv::CAMERA_HIT_TIME));
    }
    

    //Actualize the values of x, y, z || If the player doesnt move farther than dMAX, we dont move the camera
    float dx = x - gameObject->getX();
    float dy = y - gameObject->getY();

    //Smooth movement
    float vx = - dx * gv::CAMERA_VELOCITY;
    float vy = - dy * gv::CAMERA_VELOCITY;

    x += vx*dt; 
    y += vy*dt;
    z = gameObject->getZ();

    node->update(x, y-(gv::CAMERA_DY * zoom) + h, z-(gv::CAMERA_DZ * zoom) + h, x, y, z, ortho);

   ((CameraManager*)manager)->setCameraPosition(x, y , z-(gv::CAMERA_DZ * zoom));
}

void CameraComponent::setFOV(float fov)
{
    node->setFOV(fov);
}

void CameraComponent::setZoom(float dt)
{
    zoom += dt;

    if(zoom<gv::CAMERA_MIN_ZOOM)
        zoom = gv::CAMERA_MIN_ZOOM;
    
    if(zoom>gv::CAMERA_MAX_ZOOM)
        zoom = gv::CAMERA_MAX_ZOOM;
}