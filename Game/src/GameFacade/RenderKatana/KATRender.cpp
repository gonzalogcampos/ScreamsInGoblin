#include "KATRender.h"
#include "KATMesh.h"
#include "KATCamera.h"
#include "KATHUD.h"
#include "KATMenu.h"
#include "KATSprite.h"


KATRender::KATRender() : FRender()
{
    katana = new Katana();
	window = katana->initWindow();
    katana->initRoot();
	katana->initOpenGL();
    scene = katana->getSceneRoot();
    katana->initAnimations();
    katana->createNodeCamera(scene, glm::vec3(0,0,0),glm::vec3(0,0,-1),0.01f,100.0f);
}

void KATRender::drawAll(float dt)
{
    katana->drawAll(dt);
}

bool KATRender::run()
{
    return katana->openWindow(window);
}

void KATRender::drop()
{
    katana->close();
}

float KATRender::getCursorX()
{
    return katana->cursorPosition().x;
}

float KATRender::getCursorY()
{
    return katana->cursorPosition().y;
}

FMesh* KATRender::createMesh(char* s)
{
    KATMesh* r = new KATMesh();
    r->setMesh(katana->createNodeMesh(scene,glm::vec3(0,0,0),s));
    return r;
}

FMesh* KATRender::createAnimation(char* s, int n)
{
    KATMesh* r = new KATMesh();
    r->setMesh(katana->createNodeAnimation(scene,glm::vec3(0,0,0),s, n));
    return r;
}


FCamera* KATRender::createCamera()
{
    KATCamera* camara = new KATCamera();
    camara->setCamera(katana->getNodeCamera());   
    return (FCamera*)camara;
}

FHUD* KATRender::getHUD()
{

    return KATHUD::getInstance();
}

FMenu* KATRender::getMenu()
{
    return KATMenu::getInstance();
}


FSprite* KATRender::getSprite(char* texture, float x, float y, float sx, float sy, float rot, float r, float g, float b)
{
    return new KATSprite(texture, x, y, sx, sy, rot, r, g, b);
}


void KATRender::setCamera(float x,float y,float z)
{
    katana->setCameraPosition(x, y, z);
}


void KATRender::deleteNode(TNode* n)
{
    katana->deleteNodeBranch(n);
}


void KATRender::getWindowSize(int &x, int &y)
{
    katana->getWindowSize(x, y);
}

void KATRender::close()
{
    katana->close();
}