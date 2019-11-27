#include "NORender.h"
#include "NOMesh.h"
#include "NOCamera.h"
#include "NOHUD.h"
#include "NOMenu.h"
#include "NOSprite.h"

NORender::NORender()
{
}

void NORender::drawAll(float dt)
{
}

bool NORender::run()
{
    loops++;
    if(toClose)
        return false;

    if(loops>200)
        return false;

    return true;
}

void NORender::drop()
{
}

float NORender::getCursorX()
{
    return 0.f;
}

float NORender::getCursorY()
{
    return 0.f;
}

FMesh* NORender::createMesh(char* s)
{
    return new NOMesh();
}

FMesh* NORender::createAnimation(char* s, int n)
{
    return new NOMesh();
}


FCamera* NORender::createCamera()
{
    return new NOCamera();
}

FHUD* NORender::getHUD()
{

    return NOHUD::getInstance();
}

FMenu* NORender::getMenu()
{
    return NOMenu::getInstance();
}

FSprite* NORender::getSprite(char* texture, float x, float y, float sx, float sy, float rot, float r, float g, float b)
{
    return new NOSprite();
}

void NORender::close()
{
    toClose = true;
}