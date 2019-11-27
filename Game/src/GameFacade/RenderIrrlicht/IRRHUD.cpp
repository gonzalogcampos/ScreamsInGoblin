#include "IRRHUD.h"
#include "GameValues.h"
#include <iostream>


void IRRHUD::init()
{
    //////////////////////////////////////////////////
    //============== GET ENVOIRMERNT =================
    //////////////////////////////////////////////////
    env = IRRRender::getInstance()->getGUIEnv();

    //////////////////////////////////////////////////
    //===============   GET SCALE   ==================
    //////////////////////////////////////////////////

    float screenWidth = (float)IRRRender::getInstance()->getDriver()->getScreenSize().Width;
    float screenHeight = (float)IRRRender::getInstance()->getDriver()->getScreenSize().Height;
    float sh = (float)(screenHeight / 1086.f);
    float sw = (float)(screenWidth / 1930.f);

    //////////////////////////////////////////////////
    //============= GET HUD BACKGROUND ===============
    //////////////////////////////////////////////////

    irr::video::ITexture* texture = IRRRender::getInstance()->getDriver()->getTexture("res/sprites/FondoHUD.png");
    irr::core::dimension2d<irr::u32> original = texture->getOriginalSize();

    float width = (float)original.Width * sw;
    float height = (float)original.Height * sh;

    float x = sw * -6;
    float y = sh * 830.f;

    background = env->addImage(texture ,irr::core::position2d<int>(x,y));
    background->setScaleImage(true);
    background->setMaxSize(irr::core::dimension2du(width, height));
    background->setMinSize(irr::core::dimension2du(width, height));




    //////////////////////////////////////////////////
    //===============   GET HUD LIFE   ===============
    //////////////////////////////////////////////////

    texture = IRRRender::getInstance()->getDriver()->getTexture("res/sprites/VidaHUD.png");
    original = texture->getOriginalSize();
    width = (float)original.Width * sw;
    height = (float)original.Height * sh;
    x = sw * 477.f;
    y = sh * 961.f;
    life = env->addImage(texture ,irr::core::position2d<int>(x, y));
    life->setScaleImage(true);
    life->setMaxSize(irr::core::dimension2du(width, height));
    life->setMinSize(irr::core::dimension2du(width, height));


    //////////////////////////////////////////////////
    //==============   GET HUD SHIELD  ===============
    //////////////////////////////////////////////////

    texture = IRRRender::getInstance()->getDriver()->getTexture("res/sprites/EscudoHUD.png");
    original = texture->getOriginalSize();

    width = (float)original.Width * sw;
    height = (float)original.Height * sh;

    x = sw * 600.f;
    y = sh * 905.f;

    shield = env->addImage(texture ,irr::core::position2d<int>(x, y));
    shield->setScaleImage(true);
    shield->setMaxSize(irr::core::dimension2du(width, height));
    shield->setMinSize(irr::core::dimension2du(width, height));
}


void IRRHUD::updateValues(float life, float shield, float fps, int score, int spawns, int weapon)
{

    float screenWidth = (float)IRRRender::getInstance()->getDriver()->getScreenSize().Width;
    float screenHeight = (float)IRRRender::getInstance()->getDriver()->getScreenSize().Height;
    float sh = (float)(screenHeight / 1086.f);
    float sw = (float)(screenWidth / 1930.f);


    irr::core::dimension2d<irr::u32> original = background->getImage()->getOriginalSize();
    float width = (float)original.Width * sw;
    float height = (float)original.Height * sh;
    float x = sw * -6;
    float y = sh * 830.f;
    background->setRelativePosition(irr::core::rect<irr::s32>(x, y, width+x, height+y));
    background->setMaxSize(irr::core::dimension2du(width, height));
    background->setMinSize(irr::core::dimension2du(width, height));



    original = this->life->getImage()->getOriginalSize();
    width = (float)(original.Width * sw)*(life/gv::PLAYER_LIFE);
    height = (float)original.Height * sh;
    x = sw * 477.f;
    y = sh * 961.f;
    this->life->setRelativePosition(irr::core::rect<irr::s32>(x, y, width+x, height+y));
    this->life->setMaxSize(irr::core::dimension2du(width, height));
    this->life->setMinSize(irr::core::dimension2du(width, height));


    original = this->shield->getImage()->getOriginalSize();
    width = (float)(original.Width * sw)*(shield/gv::SHIELD_VALUE);
    height = (float)original.Height * sh;
    x = sw * 600.f;
    y = sh * 905.f;
    this->shield->setRelativePosition(irr::core::rect<irr::s32>(x, y, width+x, height+y));
    this->shield->setMaxSize(irr::core::dimension2du(width, height));
    this->shield->setMinSize(irr::core::dimension2du(width, height));



    //std::cout<<"========= H U D ==========\n";
    //std::cout<<"  Life: "<<life<<"\n";
    //std::cout<<"  Score: "<<score<<"\n";
    //std::cout<<"  Spawns: "<<spawns<<"\n";
    //std::cout<<"  FPS: "<<fps<<"\n";
    //std::cout<<"==========================\n";
}


void IRRHUD::clear()
{
    env->clear();
}