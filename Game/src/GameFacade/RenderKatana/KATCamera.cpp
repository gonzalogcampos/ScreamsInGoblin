#include "KATCamera.h"
#include "KATRender.h"
#include "TNode.h"
#include "TCamera.h"
#include <iostream>
#include <cmath>


void KATCamera::setCamera(TNode* n){
    camera = n; 

}


void KATCamera::update(float x, float y, float z, float rx, float ry, float rz, bool ortho)
{
    TTransform* translate = (TTransform*)camera->getFather()->getEntity();
    TTransform* rotate = (TTransform*)camera->getFather()->getFather()->getFather()->getEntity();

    translate->identity();
    rotate->identity();

    float dz = z - rz;
    float dy = y - ry;
    if(!ortho){
        rotate->rotate(0, 0, 1, 3.1416);
        rotate->rotate(1, 0, 0, 3.1416);
        rotate->rotate(1, 0, 0, atan(dy/dz));
    }else{
        rotate->rotate(0, 0, 1, 3.1416);
        rotate->rotate(1, 0, 0, 3.1416);
        float ajust = ry - y;
        y = y +ajust;
    }
    translate->translate(-x, y, z);
    KATRender::getInstance()->setCamera(-x, y, z);
}

void KATCamera::setFOV(float fov)
{
    
}