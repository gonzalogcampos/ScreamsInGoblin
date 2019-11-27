#include "KATMesh.h"
#include <../../lib/glm/glm.hpp>
#define GLM_ENABLE_EXPERIMENTAL 
#include "TEntity.h"
#include "TTransform.h"

void KATMesh::setPosition(float x, float y, float z)
{
    TTransform* matrix = (TTransform*)mesh->getFather()->getEntity();
    matrix->identity();
    matrix->translate(-x, y, z);
}


void KATMesh::setRotation(float x, float y, float z)
{
    TTransform* matrix = (TTransform*)mesh->getFather()->getEntity();
    //matrix->identity();
    matrix->rotate(0, 0, 1, -z/57.2958);
    matrix->rotate(0, 1, 0, y/57.2958);
    matrix->rotate(1, 0, 0, x/57.2958);
}


void KATMesh::setVisible(bool b)
{

}

void KATMesh::setTexture(char* s)
{

}

void KATMesh::isMap()
{

}