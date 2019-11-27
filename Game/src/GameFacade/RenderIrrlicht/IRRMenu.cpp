#include "IRRMenu.h"

void IRRMenu::setMenuBackground(char* t)
{
    env = IRRRender::getInstance()->getGUIEnv();
    irr::video::ITexture* texture = IRRRender::getInstance()->getDriver()->getTexture(t);
    
    float screenWidth = (float)IRRRender::getInstance()->getDriver()->getScreenSize().Width;
    float screenHeight = (float)IRRRender::getInstance()->getDriver()->getScreenSize().Height;

    img = env->addImage(texture ,irr::core::position2d<int>(0,0));
    img->setScaleImage(true);
    img->setMaxSize(irr::core::dimension2du(screenWidth, screenHeight));
    img->setMinSize(irr::core::dimension2du(screenWidth, screenHeight));
}

irr::gui::IGUIButton* IRRMenu::createButton(int x,int y,int xx,int xy, int id){
    irr::gui::IGUIButton* button = env->addButton(irr::core::rect<irr::s32>(x,y,xx,xy), 0, id,  L"New Game");
    button->setImage(IRRRender::getInstance()->getDriver()->getTexture("res/Inicio.png"));
    return button;
}

void IRRMenu::clearBackground()
{
    env->clear();
}