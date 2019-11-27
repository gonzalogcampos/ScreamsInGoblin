#include "KATMenu.h"
#include "KATRender.h"
#include "TSprite.h"
#include <iostream>
void KATMenu::setMenuBackground(char* t)
{
    int window_w, window_h;

    KATRender::getInstance()->getKatana()->getWindowSize(window_w, window_h);

    background = KATRender::getInstance()->getKatana()->createSprite(t);
    background->position = glm::vec2(0, 0);
    background->size = glm::vec2(window_w, window_h);
}

void KATMenu::clearBackground()
{
    KATRender::getInstance()->getKatana()->removeSprite(background);
}

void KATMenu::update()
{
    int window_w, window_h;
    KATRender::getInstance()->getKatana()->getWindowSize(window_w, window_h);
    background->size = glm::vec2(window_w, window_h);
}