#include "KATHUD.h"
#include "KATRender.h"
#include "GameValues.h"
#include <iostream>

void KATHUD::init()
{

    //////////////////////////////////////////////////
    //===============   GET SCALE   ==================
    //////////////////////////////////////////////////
    int screenWidth, screenHeight;
    KATRender::getInstance()->getKatana()->getWindowSize(screenWidth, screenHeight);
    float sh = (float)(screenHeight / 1086.f);
    float sw = (float)(screenWidth / 1930.f);
    float width, height, x, y;

    //////////////////////////////////////////////////
    //===============   GET HUD BACK   ===============
    //////////////////////////////////////////////////

    background = KATRender::getInstance()->getKatana()->createSprite((char*)"res/sprites/hud/FondoHUD.png");

    width = background->getWidth() * sw * 1.f;
    height = background->getHeight() * sh * 1.f;
    x = sw * -6;
    y = sh * 830.f;

    background->position = glm::vec2(x, y);
    background->size = glm::vec2(width, height);


    //////////////////////////////////////////////////
    //===============   GET HUD LIFE   ===============
    //////////////////////////////////////////////////

    life = KATRender::getInstance()->getKatana()->createSprite((char*)"res/sprites/hud/VidaHUD.png");

    width   = life->getWidth() * sw * 1.f;
    height  = life->getHeight() * sh * 1.f;
    x = sw * 477.f;
    y = sh * 961.f;

    life->position = glm::vec2(x, y);
    life->size = glm::vec2(width, height);

    //////////////////////////////////////////////////
    //===============   GET HUD SHIELD   =============
    //////////////////////////////////////////////////

    shield = KATRender::getInstance()->getKatana()->createSprite((char*)"res/sprites/hud/EscudoHUD.png");
    
    width   = shield->getWidth() * sw * 1.f;
    height  = shield->getHeight() * sh * 1.f;
    x = sw * 600.f;
    y = sh * 905.f;
    shield->position = glm::vec2(x, y);
    shield->size = glm::vec2(width, height);

    //////////////////////////////////////////////////
    //===============   GET HUD WEAPON   =============
    //////////////////////////////////////////////////

    weapon = KATRender::getInstance()->getKatana()->createSprite((char*)"res/sprites/hud/PicoHUD.png");
    
    width   = weapon->getWidth() * sw * 1.f;
    height  = weapon->getHeight() * sh * 1.f;
    x = sw * 1795.f;
    y = sh * 970.f;
    weapon->position = glm::vec2(x, y);
    weapon->size = glm::vec2(width, height);
}

void KATHUD::clear()
{
    KATRender::getInstance()->getKatana()->removeSprite(background);
    KATRender::getInstance()->getKatana()->removeSprite(life);
    KATRender::getInstance()->getKatana()->removeSprite(shield);
    KATRender::getInstance()->getKatana()->removeSprite(weapon);

}

void KATHUD::updateValues(float life, float shield, float fps, int score, int spawns, int weapon)
{
    int screenWidth, screenHeight;
    KATRender::getInstance()->getKatana()->getWindowSize(screenWidth, screenHeight);
    float sh = (float)(screenHeight / 1086.f);
    float sw = (float)(screenWidth / 1930.f);


    float width     = (float)background->getWidth() * sw;
    float height    = (float)background->getHeight() * sh;
    float x = sw * -6;
    float y = sh * 830.f;
    background->position = glm::vec2(x, y);
    background->size = glm::vec2(width, height);


    width = (float)(this->life->getWidth() * sw)*(life/gv::PLAYER_LIFE);
    height = (float)this->life->getHeight() * sh;
    x = sw * 477.f;
    y = sh * 961.f;

    this->life->position = glm::vec2(x, y);
    this->life->size = glm::vec2(width, height);

    width   = (float)(this->shield->getWidth() * sw)*(shield/gv::SHIELD_VALUE);
    height  = this->shield->getHeight() * sh * 1.f;
    x = sw * 600.f;
    y = sh * 905.f;
    this->shield->position = glm::vec2(x, y);
    this->shield->size = glm::vec2(width, height);

    if(weapon != weaponType)
    {
        weaponType = weapon;
        KATRender::getInstance()->getKatana()->removeSprite(this->weapon);

        if(weaponType == 0){
            this->weapon = KATRender::getInstance()->getKatana()->createSprite((char*)"res/sprites/hud/BallestaHUD.png");
        }else if(weaponType == 1){
            this->weapon = KATRender::getInstance()->getKatana()->createSprite((char*)"res/sprites/hud/HachaHUD.png");
        }else{
            this->weapon = KATRender::getInstance()->getKatana()->createSprite((char*)"res/sprites/hud/PicoHUD.png");
        }
    }

    width   = this->weapon->getWidth() * sw * 1.f;
    height  = this->weapon->getHeight() * sh * 1.f;
    x = sw * 1795.f;
    y = sh * 970.f;
    this->weapon->position = glm::vec2(x, y);
    this->weapon->size = glm::vec2(width, height);

    //std::cout<<"========= H U D ==========\n";
    //std::cout<<"  Life: "<<life<<"\n";
    //std::cout<<"  Score: "<<score<<"\n";
    //std::cout<<"  Spawns: "<<spawns<<"\n";
    //std::cout<<"  FPS: "<<fps<<"\n";
    //std::cout<<"==========================\n";
}