#include "InputManager.h"
#include "InputComponent.h"
#include "GameObject.h"



void InputManager::createComponent(GameObject *owner)
{
    components.push_back(new InputComponent(owner, this));
    owner->addComponent(components[components.size()-1]);
}

void InputManager::updateAll(float dt)
{
    for(std::size_t i = 0 ; i<components.size(); i++)
    {
        ((InputComponent*)components[i])->update(cursorX, cursorY); 
    }
}

void InputManager::setCursorPosition(float x, float y)
{
    cursorX=x;
    cursorY=y;
}