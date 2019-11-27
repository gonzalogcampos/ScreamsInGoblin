#include "KATSprite.h"
#include "TSprite.h"


KATSprite::KATSprite(char* texture, float x, float y, float sx, float sy, float rot, float r, float g, float b)
{
    sprite = KATRender::getInstance()->getKatana()->createSprite(texture); 
    sprite->position = glm::vec2(x, y);
    sprite->size = glm::vec2(sx, sy);
    sprite->rotation = rot;
    sprite->color = glm::vec3(r, g, b);
}

void KATSprite::setPosition(float x, float y)
{
    sprite->position = glm::vec2(x, y);
}

void KATSprite::setScale(float x, float y)
{
    sprite->size = glm::vec2(x, y);
}

void KATSprite::setColor(float r, float g, float b)
{
    sprite->color = glm::vec3(r, g, b);
}

void KATSprite::setRotation(float r)
{
    sprite->rotation = r;
}

void KATSprite::setTexture(char* t)
{
    sprite->setTexture(t);
}