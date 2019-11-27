#include "WoodComponent.h"
#include "GameObject.h"
#include "RenderComponent.h"
#include "SpawnComponent.h"
#include "GameValues.h"
#include "ProjectileComponent.h"
#include "SpecificSoundEvent.h"
#include <iostream>
#include <sstream>

void WoodComponent::update(float dt)
{
    if(burning)
    {
        life-=(dt*gv::FIRE_DAMMAGE);
    }
    if(life<0.f)
    {

        const void * address = static_cast<const void*>(this);
        std::stringstream ss;
        ss << address;  
        std::string name = ss.str();
        FireSoundEvent * s = ((FireSoundEvent*)SoundSystem::getInstance()->getEvent(name));
        s->stop(); 
        SoundSystem::getInstance()->deleteEvent(s, name);

        SpawnBreakSoundEvent* sb = new SpawnBreakSoundEvent(SoundSystem::getInstance()->getEventInstanceFromName("sbreakdown"));
        sb->setPosition({gameObject->getX(), gameObject->getY(), gameObject->getZ()});
        sb->setVolume(5);
        sb->start();

        delete sb;
        gameObject->setKill(true);
        
    }
}

void WoodComponent::setBurning(bool b){
    burning=b;
    if(gameObject->getComponent<SpawnComponent>() && gameObject->getComponent<SpawnComponent>()->isCuartel())
    {
        if(b)
        {
            gameObject->getComponent<RenderComponent>()->setTexture((char*)"res/tex/Cuartel_Fuego_Color.bmp");
        }else
        {
            gameObject->getComponent<RenderComponent>()->setTexture((char*)"res/tex/Cuartel_SColor.bmp");
        }
    }else{
        if(b)
        {
            gameObject->getComponent<RenderComponent>()->setTexture((char*)"res/tex/Casa_Fuego_Color.bmp");
        }else
        {
            gameObject->getComponent<RenderComponent>()->setTexture((char*)"res/tex/Casa_Color.bmp");
        }
    }
   //  std::cout << "Sonido arranca"<< this <<"\n";
        FireSoundEvent * s = new FireSoundEvent(SoundSystem::getInstance()->getEventInstanceFromName("sburn"));
        const void * address = static_cast<const void*>(this);
        std::stringstream ss;
        ss << address;  
        std::string name = ss.str();
        SoundSystem::getInstance()->saveEvent(s, name); 
        s->setPosition({gameObject->getX(), gameObject->getY(), gameObject->getZ()});
        s->setVolume(5);
        s->start();
   
   ///Hay que borrar el puntero al evento cunndo se pare el sonido 
    

}

void WoodComponent::addBucket()
{
    buckets++;

     const void * address = static_cast<const void*>(this);
        std::stringstream ss;
        ss << address;  
        std::string name = ss.str();

        WaterdropSoundEvent * sw = new WaterdropSoundEvent(SoundSystem::getInstance()->getEventInstanceFromName("waterdrop"));
         
        sw->setPosition({gameObject->getX(), gameObject->getY(), gameObject->getZ()});
        sw->setVolume(15);
        sw->start();

        delete sw;

    if(buckets>=gv::BUCKETS_NEDED){
        burning = false;
        buckets = 0;
        if(gameObject->getComponent<RenderComponent>())
        {
            gameObject->getComponent<RenderComponent>()->setTexture((char*)"res/green.bmp");
        }  

       
        FireSoundEvent * s = ((FireSoundEvent*)SoundSystem::getInstance()->getEvent(name));
        s->stop(); 
        SoundSystem::getInstance()->deleteEvent(s, name);
    }
}


void WoodComponent::dealDamage(ProjectileComponent* projectile)
{
    if(projectile && projectile->getTeam()!=team)
    {
        if(!burning)
            setBurning(true);
        HitSoundEvent * s = new HitSoundEvent(SoundSystem::getInstance()->getEventInstanceFromName("shit"));
        s->setPosition({gameObject->getX(), gameObject->getY(), gameObject->getZ()});
        s->setVolume(5);
        s->start();
        delete s;
        life -= projectile->getDamage();
    }
}