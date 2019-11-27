#include "IRRMesh.h"

//Creation of a mesh node, recives the facade an the path of the mesh
IRRMesh::IRRMesh(irr::scene::IMeshSceneNode* node)
{
    this->node = node;
}

//Changes the position nsertof the node
void IRRMesh::setPosition(float x, float y, float z)
{
    irr::core::vector3df nodePosition = node->getPosition();
    nodePosition.Y = y;
    nodePosition.X = x;
    nodePosition.Z = z;
    node->setPosition(nodePosition);
}

//Changes the rotation of the node only in the z axis
void IRRMesh::setRotation(float x, float y, float z)
{
    node->setRotation(irr::core::vector3df(x, y, z));
}

//Chages the visibility of the node to b
void IRRMesh::setVisible(bool b)
{
    node->setVisible(b);
}

//Changes the texture of the node to the new path
void IRRMesh::setTexture(char* s)
{
   node->setMaterialTexture( 0, IRRRender::getInstance()->getTexture(s) );
}

void IRRMesh::isMap()
{
    IRRRender::getInstance()->isMap(node);
}