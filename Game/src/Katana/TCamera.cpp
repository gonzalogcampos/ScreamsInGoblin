#include "TCamera.h"
#include "TEntity.h"
#include <iostream>
#include "../../lib/glm/glm.hpp"
#define GLM_ENABLE_EXPERIMENTAL 
TCamera::TCamera()
{
    left=2.f;
    right=2.f;
    top=1.f;
    bot=2.f;
    near=0.1f;
    far=10000.f;
    zoom = 45.0;
    
    projectionMatrix() = glm::perspective(glm::radians(zoom), (float)16 / (float)9, near, far);

    
}

void TCamera::switchProyection(bool ortho)
{
    //else when perspective==false==parallel
    if(!ortho)
    {
        //glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT,n,f) FOR THE FUTURE
     projectionMatrix() = glm::perspective(glm::radians(zoom), (float)16 / (float)9, near, far);
        
    }
    else
    {
        projectionMatrix() = glm::ortho(-20.f, 20.f, -10.f, 10.f, -10.f, 15.f);
    }
}
