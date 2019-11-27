#include "Menu.h"
#include "FSprite.h"
#include "GameValues.h"
#include "SpecificSoundEvent.h"

float HEIGHT_MODEL_SCALE = 1.f;
float WIDTH_MODEL_SCALE = 1.f;

void Menu::down()
{
    if(at<0.2)
        return;

    at = 0.f;

    buttons[focus]->unfocus();
    if(focus >= buttons.size() - 1)
    {
        focus = 0;
    }
    else
    {
        focus++;
    }
      MPulseSoundEvent * amb = new MPulseSoundEvent(SoundSystem::getInstance()->getEventInstanceFromName("mpulse"));  
        amb->start();
        delete amb;
    buttons[focus]->focus();
};

void Menu::up()
{   
    if(at<0.2)
        return;

    at = 0.f;
    buttons[focus]->unfocus();
    if(focus <= 0)
    {
        focus = buttons.size()-1;
    }
    else
    {
        focus--;
    }
    buttons[focus]->focus();
        MPulseSoundEvent * amb = new MPulseSoundEvent(SoundSystem::getInstance()->getEventInstanceFromName("mpulse"));  
        amb->start();
        delete amb;
}

int Menu::click()
{
    if(!buttons.empty() && focus>=0 && focus<buttons.size()){

        MPulseSoundEvent * amb = new MPulseSoundEvent(SoundSystem::getInstance()->getEventInstanceFromName("mpulse"));  
        amb->start();
        delete amb;
        return buttons[focus]->getID();
    }

    return -1;
}

void Menu::clear()
{
    delete background; 
    for(size_t i = 0; i<buttons.size(); i++) 
        delete buttons[i]; 
    
    buttons.clear();
}

void Menu::update(float dt)
{
    //Time
    at+=dt;

    //Scale
    int screenWidth, screenHeight;
    Render::getInstance()->getRender()->getWindowSize(screenWidth, screenHeight);
    HEIGHT_MODEL_SCALE = ((screenHeight * 1.f) / (gv::HEIGHT_MODEL * 1.f));
    WIDTH_MODEL_SCALE = ((screenWidth * 1.f) / (gv::WIDTH_MODEL*1.f));
    
    //Background    
    float width = background->getWidth() * WIDTH_MODEL_SCALE;
    float height = background->getHeight() * HEIGHT_MODEL_SCALE;
    background->setScale(width, height);

    for(size_t i=0; i<buttons.size(); i++)
        buttons[i]->update();
}

void Menu::setBackground(char* b)
{  
    //Background
    background = Render::getInstance()->getRender()->getSprite(b, 0, 0, 100, 100, 0.f, 1.f, 1.f, 1.f);


    float height = gv::HEIGHT_MODEL * HEIGHT_MODEL_SCALE * 1.f;
    float width = gv::WIDTH_MODEL* WIDTH_MODEL_SCALE * 1.f;

    background->setScale(width, height);
}

Button::Button(int id, char* pathnormal, char* pathfocus, float x, float y)
{
    this->id = id;
    this->x = x;
    this->y = y;
    this->pathnormal = pathnormal;
    this->pathfocus = pathfocus;

    sprite = Render::getInstance()->getSprite(pathnormal, x, y, sx, sy, 0.f, 1.f, 1.f, 1.f);

    float xi = x * WIDTH_MODEL_SCALE;
    float yi = y * HEIGHT_MODEL_SCALE;

    sprite->setPosition(xi, yi);

    xi = (sprite->getHeight() + x ) * WIDTH_MODEL_SCALE;
    yi = (sprite->getWidth() + y ) * HEIGHT_MODEL_SCALE;

    sprite->setScale(xi, yi);
}

void Button::focus()
{
    delete sprite;
    sprite = Render::getInstance()->getSprite(pathfocus, x, y, sx, sy, 0.f, 1.f, 1.f, 1.f);
}

void Button::unfocus()
{
    delete sprite;
    sprite = Render::getInstance()->getSprite(pathnormal, x, y, sx, sy, 0.f, 1.f, 1.f, 1.f);
}

void Button::setPosition(float x, float y)
{
    this->x = x;
    this->y = y;

    update();
}

void Button::setColor(float r, float g, float b)
{
    sprite->setColor(r, g, b);
}
void Button::setRotation(float r)
{
    sprite->setRotation(r);
}

void Button::update()
{
    float xi = x * WIDTH_MODEL_SCALE;
    float yi = y * HEIGHT_MODEL_SCALE;

    sprite->setPosition(xi, yi);

    xi = sprite->getWidth() * WIDTH_MODEL_SCALE;
    yi = sprite->getHeight() * HEIGHT_MODEL_SCALE;

    sprite->setScale(xi, yi);
}