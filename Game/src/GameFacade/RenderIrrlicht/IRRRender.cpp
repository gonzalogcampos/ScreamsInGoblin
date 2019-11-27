#include "IRRRender.h"
#include "IRRCamera.h"
#include "IRRMesh.h"
#include "IRRMenu.h"
#include "IRRHUD.h"
#include "IRRSprite.h"
#include "GameValues.h"

IRRRender::IRRRender(){
    //We need to use video::EDT_SOFTWARE!!
    //BUT we only can see the map with EDT:OPENGL!
    device = irr::createDevice( irr::video::EDT_OPENGL, irr::core::dimension2d<irr::u32>(gv::SCR_WIDTH, gv::SCR_HEIGHT), 16,
			false, false, false, 0);

    if (!device)
        return;

    device->setWindowCaption(L"Screams In Goblin");
    
    device->getLogger()->setLogLevel(irr::ELL_ERROR);

    driver = device->getVideoDriver();
    smgr = device->getSceneManager();
    guienv = device->getGUIEnvironment();

    smgr->addLightSceneNode(0, irr::core::vector3df(10,0,-100),
    irr::video::SColorf(1.0f,1.0f,1.0f,1.0f), 1000.0f);
}


void IRRRender::drawAll(float dt)
{
    driver->beginScene(true, true, irr::video::SColor(255,100,100,100));

    smgr->drawAll();
    guienv->drawAll();

    driver->endScene();
}

bool IRRRender::run()
{
    return device->run();
}

void IRRRender::drop()
{
    device->drop();
}


float IRRRender::getCursorX()
{
    if(!map)
        return 0.f;

    irr::scene::ITriangleSelector*  selector=smgr->createTriangleSelector(map->getMesh(), map);
    irr::core::vector3df            outCollisionPoint;
    irr::core::triangle3df          outTriangle;
    irr::scene::ISceneNode*         outNode=nullptr;

    irr::scene::ISceneCollisionManager* colmgr = smgr->getSceneCollisionManager();
    irr::core::line3d<float> raytrace = colmgr->getRayFromScreenCoordinates(device->getCursorControl()->getPosition(), camera);
    colmgr->getCollisionPoint(	raytrace,
                                selector,
                                outCollisionPoint,
                                outTriangle,
                                outNode
                                );

    selector->drop();
    return outCollisionPoint.X;
}

float IRRRender::getCursorY()
{
    if(!map)
        return 0.f;

    irr::scene::ITriangleSelector*  selector=smgr->createTriangleSelector(map->getMesh(), map);
    irr::core::vector3df           outCollisionPoint;
    irr::core::triangle3df          outTriangle;
    irr::scene::ISceneNode*         outNode=nullptr;

    irr::scene::ISceneCollisionManager* colmgr = smgr->getSceneCollisionManager();
    irr::core::line3d<float> raytrace = colmgr->getRayFromScreenCoordinates(device->getCursorControl()->getPosition(), camera);
    colmgr->getCollisionPoint(	raytrace,
                                selector,
                                outCollisionPoint,
                                outTriangle,
                                outNode
                                );

    selector->drop();
    return outCollisionPoint.Y;
}


FMesh* IRRRender::createMesh(char* s)
{
    irr::scene::IMesh* mesh = smgr->getMesh(s); //Gets a mesh
    irr::scene::IMeshSceneNode* node = nullptr;
    if (mesh)
    {
        node = smgr->addMeshSceneNode(mesh);//Adds the mesh to the node
        node->setMaterialFlag(irr::video::EMF_LIGHTING, true);
    }

    return new IRRMesh(node);
}

FCamera* IRRRender::createCamera()
{
    irr::scene::ICameraSceneNode* node = smgr->addCameraSceneNode(0, irr::core::vector3df(0,0,0), irr::core::vector3df(0,0,0));
    camera = node;
    return new IRRCamera(node);
}

irr::video::ITexture* IRRRender::getTexture(char* s)
{
    return driver->getTexture(s);
}


FMenu* IRRRender::getMenu()
{
    return IRRMenu::getInstance();
}

FHUD* IRRRender::getHUD()
{
    return IRRHUD::getInstance();
}

FSprite* IRRRender::getSprite(char* texture, float x, float y, float sx, float sy, float rot, float r, float g, float b)
{
    return new IRRSprite();
}

void IRRRender::close()
{
    //device->close();
}


FMesh* IRRRender::createAnimation(char* s, int n)
{
    irr::scene::IMesh* mesh = smgr->getMesh(s); //Gets a mesh
    irr::scene::IMeshSceneNode* node = nullptr;
    if (mesh)
    {
        node = smgr->addMeshSceneNode(mesh);//Adds the mesh to the node
        node->setMaterialFlag(irr::video::EMF_LIGHTING, true);
    }

    return new IRRMesh(node);
}
