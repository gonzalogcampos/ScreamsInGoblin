#include "RenderComponent.h"
#include "GameObject.h"
#include <cmath>
void RenderComponent::update(float dt){

    float sz = 0.f;
    float sr = 0.f;
    this->time += dt;
    if(leviosa){
        sz = - 0.6 + 0.6 * sin(1.8 * this->time); 
    }
    if(rotates){
        sr =500 * this->time;
    }

    node->setPosition(gameObject->getX(),
                        gameObject->getY(),
                        gameObject->getZ() + sz);

    node->setRotation(gameObject->getRX() + sr, 
                        gameObject->getRY(), 
                        gameObject->getRZ());

}



void RenderComponent::setVisible(bool h){
    node->setVisible(h);
}
void RenderComponent::setTexture(char s[]){
    node->setTexture(s);
}

void RenderComponent::isMap()
{
    node->isMap();
}