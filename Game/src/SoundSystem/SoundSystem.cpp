#include "SoundSystem.h"
#include "SoundEvent.h"
#include "SoundEngineData.h"
#include "CameraManager.h"
#include "GameObject.h"
#include "GameResource.h"
#include <iostream>

  
void SoundSystem::Init()
{
    SoundSystem::LoadBank("res/media/Master Bank.bank", FMOD_STUDIO_LOAD_BANK_NORMAL);
    SoundSystem::LoadBank("res/media/Master Bank.strings.bank", FMOD_STUDIO_LOAD_BANK_NORMAL);

    SoundSystem::LoadBank("res/media/Shoot.bank", FMOD_STUDIO_LOAD_BANK_NORMAL);
    SoundSystem::LoadBank("res/media/Goblin.bank", FMOD_STUDIO_LOAD_BANK_NORMAL);
    SoundSystem::LoadBank("res/media/Fondo.bank", FMOD_STUDIO_LOAD_BANK_NORMAL);
    SoundSystem::LoadBank("res/media/Spawn.bank", FMOD_STUDIO_LOAD_BANK_NORMAL);
    SoundSystem::LoadBank("res/media/Water.bank", FMOD_STUDIO_LOAD_BANK_NORMAL);
    SoundSystem::LoadBank("res/media/Picks.bank", FMOD_STUDIO_LOAD_BANK_NORMAL);
    SoundSystem::LoadBank("res/media/Enemy.bank", FMOD_STUDIO_LOAD_BANK_NORMAL);
    SoundSystem::LoadBank("res/media/Menu.bank", FMOD_STUDIO_LOAD_BANK_NORMAL);




  
    SoundSystem::LoadEvent("event:/s_hit", "shit");
    SoundSystem::LoadEvent("event:/s_burn", "sburn");
    SoundSystem::LoadEvent("event:/s_breakdown", "sbreakdown");


    
    SoundSystem::LoadEvent("event:/g_hacha", "ghacha");
    SoundSystem::LoadEvent("event:/g_pico", "gpico");
    SoundSystem::LoadEvent("event:/g_ballesta", "gballesta");

    SoundSystem::LoadEvent("event:/e_pico", "epico");


    SoundSystem::LoadEvent("event:/ambiente", "ambiente");
    SoundSystem::LoadEvent("event:/musica", "musica");
    SoundSystem::LoadEvent("event:/menu_musica", "menumusica");
    SoundSystem::LoadEvent("event:/heartbeat", "latido");



    SoundSystem::LoadEvent("event:/g_waterget", "waterget");
    SoundSystem::LoadEvent("event:/g_waterdrop", "waterdrop");


    SoundSystem::LoadEvent("event:/pocion_coger", "pickpotion");
    SoundSystem::LoadEvent("event:/escudo_coger", "pickshield");


    SoundSystem::LoadEvent("event:/e_muerte", "emuerte");
    SoundSystem::LoadEvent("event:/e_hit", "ehit");


    SoundSystem::LoadEvent("event:/m_pulse", "mpulse");
    SoundSystem::LoadEvent("event:/m_start", "mstart");
    SoundSystem::LoadEvent("event:/m_select", "mselect");

}
void SoundSystem::Update() {
    CameraManager* ca = CameraManager::getInstance();
    //GameObject* pt = GameResource::getInstance()->getPlayer();
    Vector3 v3 = {ca->getCX(),ca->getCY(),1.f};
    //Vector3 v3 = {pt->getX(),pt->getY(),pt->getZ()};

    SoundSystem::Set3dListener( v3);
    soundEngineData->Update();

}


void SoundSystem::LoadSound(const std::string& strSoundName, bool b3d, bool bLooping, bool bStream)
{
    auto tFoundIt = soundEngineData->mSounds.find(strSoundName);
    if (tFoundIt != soundEngineData->mSounds.end())
        return;

    FMOD_MODE eMode = FMOD_DEFAULT;
    eMode |= b3d ? FMOD_3D : FMOD_2D;
    eMode |= bLooping ? FMOD_LOOP_NORMAL : FMOD_LOOP_OFF;
    eMode |= bStream ? FMOD_CREATESTREAM : FMOD_CREATECOMPRESSEDSAMPLE;

    FMOD::Sound* pSound = nullptr;
    SoundSystem::ErrorCheck(soundEngineData->mpSystem->createSound(strSoundName.c_str(), eMode, nullptr, &pSound));
    if (pSound){
        soundEngineData->mSounds[strSoundName] = pSound;
    }

}  



void SoundSystem::UnLoadSound(const std::string& strSoundName)
{
    auto tFoundIt = soundEngineData->mSounds.find(strSoundName);
    if (tFoundIt == soundEngineData->mSounds.end())
        return;

    SoundSystem::ErrorCheck(tFoundIt->second->release());
    soundEngineData->mSounds.erase(tFoundIt);
}


int SoundSystem::PlaySounds(const std::string& strSoundName, const Vector3& vPosition, float fVolumedB)
{
    int nChannelId = soundEngineData->mnNextChannelId++;
    auto tFoundIt = soundEngineData->mSounds.find(strSoundName);
    if (tFoundIt == soundEngineData->mSounds.end())
    {
        LoadSound(strSoundName);
        tFoundIt = soundEngineData->mSounds.find(strSoundName);
        if (tFoundIt == soundEngineData->mSounds.end())
        {
            return nChannelId;
        }
    }
    FMOD::Channel* pChannel = nullptr;
    SoundSystem::ErrorCheck(soundEngineData->mpSystem->playSound(tFoundIt->second, nullptr, true, &pChannel));
    if (pChannel)
    {
        FMOD_MODE currMode;
        tFoundIt->second->getMode(&currMode);
        if (currMode & FMOD_3D){
            FMOD_VECTOR position = VectorToFmod(vPosition);
            SoundSystem::ErrorCheck(pChannel->set3DAttributes(&position, nullptr));
        }
        SoundSystem::ErrorCheck(pChannel->setVolume(dbToVolume(fVolumedB)));
        SoundSystem::ErrorCheck(pChannel->setPaused(false));
        soundEngineData->mChannels[nChannelId] = pChannel;
    }
    return nChannelId;
}


void SoundSystem::SetChannel3dPosition(int nChannelId, const Vector3& vPosition)
{
    auto tFoundIt = soundEngineData->mChannels.find(nChannelId);
    if (tFoundIt == soundEngineData->mChannels.end())
        return;

    FMOD_VECTOR position = VectorToFmod(vPosition);
    SoundSystem::ErrorCheck(tFoundIt->second->set3DAttributes(&position, NULL));
}

void SoundSystem::SetChannelVolume(int nChannelId, float fVolumedB)
{
    auto tFoundIt = soundEngineData->mChannels.find(nChannelId);
    if (tFoundIt == soundEngineData->mChannels.end())
        return;

    SoundSystem::ErrorCheck(tFoundIt->second->setVolume(dbToVolume(fVolumedB)));
}


void SoundSystem::LoadBank(const std::string& strBankName, FMOD_STUDIO_LOAD_BANK_FLAGS flags) {
    auto tFoundIt = soundEngineData->mBanks.find(strBankName);
    if (tFoundIt != soundEngineData->mBanks.end())
        return;
    FMOD::Studio::Bank* pBank;
    SoundSystem::ErrorCheck(soundEngineData->mpStudioSystem->loadBankFile(strBankName.c_str(), flags, &pBank));
    if (pBank) {
        soundEngineData->mBanks[strBankName] = pBank;
            // std::cout << "good bank \n";

    }
}



void SoundSystem::LoadEvent(const std::string& strEventName, std::string strSearchName) {
    auto tFoundit = soundEngineData->mEvents.find(strSearchName);
    if (tFoundit != soundEngineData->mEvents.end())
        return;
            // std::cout << "good 1 \n";

    FMOD::Studio::EventDescription* pEventDescription = NULL;
    SoundSystem::ErrorCheck(soundEngineData->mpStudioSystem->getEvent(strEventName.c_str(), &pEventDescription));
    if (pEventDescription){
            // std::cout << "good 2 \n";

        FMOD::Studio::EventInstance* pEventInstance = NULL;
        SoundSystem::ErrorCheck(pEventDescription->createInstance(&pEventInstance));
        if (pEventInstance){
            soundEngineData->mEvents[strSearchName] = pEventInstance;
            soundEngineData->mEventsDescriptions[strSearchName] = pEventDescription;

           

           //  std::cout << "good 3 \n";

        }
    }
}


void SoundSystem::PlayEvent(const std::string &strEventName) {
    auto tFoundit = soundEngineData->mEvents.find(strEventName);
    if (tFoundit == soundEngineData->mEvents.end()){
        LoadEvent("event:/" + strEventName, strEventName);
        tFoundit = soundEngineData->mEvents.find(strEventName);
        if (tFoundit == soundEngineData->mEvents.end())
            return;
    }
    tFoundit->second->start();
    //std::cout << "PLAY \n";
}


void SoundSystem::StopEvent(const std::string &strEventName, bool bImmediate) {
    auto tFoundIt = soundEngineData->mEvents.find(strEventName);
    if (tFoundIt == soundEngineData->mEvents.end())
        return;

    FMOD_STUDIO_STOP_MODE eMode;
    eMode = bImmediate ? FMOD_STUDIO_STOP_IMMEDIATE : FMOD_STUDIO_STOP_ALLOWFADEOUT;
    SoundSystem::ErrorCheck(tFoundIt->second->stop(eMode));
}

bool SoundSystem::IsEventPlaying(const std::string &strEventName) const {
    auto tFoundIt = soundEngineData->mEvents.find(strEventName);
    if (tFoundIt == soundEngineData->mEvents.end())
        return false;

    FMOD_STUDIO_PLAYBACK_STATE* state = NULL;
    tFoundIt->second->getPlaybackState(state);
    if ( *state == FMOD_STUDIO_PLAYBACK_PLAYING) {
        return true;
    }
    return false;
}


void SoundSystem::GetEventParameter(const std::string &strEventName, const std::string &strParameterName, float* parameter) {
    auto tFoundIt = soundEngineData->mEvents.find(strEventName);
    if (tFoundIt == soundEngineData->mEvents.end())
        return;

    FMOD::Studio::ParameterInstance* pParameter = NULL;
    SoundSystem::ErrorCheck(tFoundIt->second->getParameter(strParameterName.c_str(), &pParameter));
    SoundSystem::ErrorCheck(pParameter->getValue(parameter));
}

void SoundSystem::SetEventParameter(const std::string &strEventName, const std::string &strParameterName, float fValue) {
    auto tFoundIt = soundEngineData->mEvents.find(strEventName);
    if (tFoundIt == soundEngineData->mEvents.end())
        return;

    FMOD::Studio::ParameterInstance* pParameter = NULL;
    SoundSystem::ErrorCheck(tFoundIt->second->getParameter(strParameterName.c_str(), &pParameter));
    SoundSystem::ErrorCheck(pParameter->setValue(fValue));
}


FMOD_VECTOR SoundSystem::VectorToFmod(const Vector3& vPosition){
    FMOD_VECTOR fVec;
    fVec.x = vPosition.x;
    fVec.y = vPosition.y;
    fVec.z = vPosition.z;
    return fVec;
}

float  SoundSystem::dbToVolume(float dB)
{
    return powf(10.0f, 0.05f * dB);
}

float  SoundSystem::VolumeTodB(float volume)
{
    return 20.0f * log10f(volume);
}


int SoundSystem::ErrorCheck(FMOD_RESULT result) {
    if (result != FMOD_OK){
        std::cout << "FMOD ERROR " << result << std::endl;
        return 1;
    }
    // std::cout << "FMOD all good" << std::endl;
    return 0;
}

void SoundSystem::Shutdown() {
    Release();
    delete soundEngineData;
} 

void SoundSystem::Release(){


    //mapa Descriptions 
    for(std::map<std::string, FMOD::Studio::EventDescription*>::iterator it = soundEngineData->mEventsDescriptions.begin(); it != soundEngineData->mEventsDescriptions.end(); it++)
    {
        it->second->releaseAllInstances();
       // delete it->second;

    }
   // soundEngineData->mEventsDescriptions.clear();

    //mapa Instancias 
  /*  for(std::map<std::string, FMOD::Studio::EventInstance*>::iterator it = soundEngineData->mEvents.begin(); it != soundEngineData->mEvents.end(); it++)
    {
       delete it->second;

    }*/
    soundEngineData->mEvents.clear();


    //mapa SoundEvents 
    for(std::map<std::string, SoundEvent* >::iterator it = soundEngineData->mSoundEvents.begin(); it != soundEngineData->mSoundEvents.end(); it++)
    {
       delete it->second;
       

    }
    soundEngineData->mSoundEvents.clear();
    

}


void SoundSystem::setVolume(float vol)
{
  //  SoundSystem::ErrorCheck(soundEngineData->mpStudioSystem->setVolume(vol);

  //no encuentro una forma de hacerlo
}

void SoundSystem::Set3dListener(const Vector3& Pos)
{
   

    FMOD_VECTOR pos = VectorToFmod(Pos);
    FMOD_VECTOR vel = VectorToFmod({0,0,0});
    FMOD_VECTOR forw = VectorToFmod({0,1,0});
    FMOD_VECTOR up = VectorToFmod({0,0,-1});

        FMOD_3D_ATTRIBUTES att = {pos, vel, forw, up} ;
     
        
        soundEngineData->mpStudioSystem->setListenerAttributes(0,&att);
}

FMOD::Studio::EventInstance* SoundSystem::getEventInstanceFromName(std::string eventName)
{
   auto eventDes = soundEngineData->mEventsDescriptions.find(eventName);
   // if (!tFoundIt == soundEngineData->mEvents.end())
        FMOD::Studio::EventInstance* pEventInstance = NULL;

        SoundSystem::ErrorCheck(eventDes->second->createInstance(&pEventInstance));


   
        return pEventInstance;
    
}

void SoundSystem::saveEvent(SoundEvent * s, const std::string& strEventName)
{
    auto tFoundIt = soundEngineData->mSoundEvents.find(strEventName);
    if (tFoundIt != soundEngineData->mSoundEvents.end())
        return;
    soundEngineData->mSoundEvents[strEventName] = s;

}

SoundEvent* SoundSystem::getEvent(const std::string& strEventName)
{
     auto tFoundIt = soundEngineData->mSoundEvents.find(strEventName);

     return tFoundIt->second;
}

void SoundSystem::deleteEvent(SoundEvent* s, const std::string strEventName)
{
    auto tFoundIt = soundEngineData->mSoundEvents.find(strEventName);
    if (tFoundIt == soundEngineData->mSoundEvents.end())
        return;

    soundEngineData->mSoundEvents.erase(tFoundIt);
    delete s;
}

