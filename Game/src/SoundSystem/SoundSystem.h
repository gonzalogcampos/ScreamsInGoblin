#pragma once
#include "fmod_studio.hpp"
#include "fmod.hpp"
#include <string>
#include <map>
#include <vector>
#include <math.h>
#include "SoundEngineData.h"
#include "SoundEvent.h"


struct Vector3 {
    float x;
    float y;
    float z;
}; 

class SoundEvent;

class SoundSystem {

 private:
         SoundEngineData* soundEngineData;
	    SoundSystem(){soundEngineData = new SoundEngineData();}
 public:
        static SoundSystem* getInstance()
        {
            static SoundSystem only_instance;
            return &only_instance;
        }

    ~SoundSystem(){Shutdown();}
    
    
    void Update();
    void Shutdown();
    void Release();
   static int ErrorCheck(FMOD_RESULT result);
    void Init();
    void LoadBank(const std::string& strBankName, FMOD_STUDIO_LOAD_BANK_FLAGS flags);
    void LoadEvent(const std::string& strEventName, std::string strSearchName);
    void LoadSound(const std::string& strSoundName, bool b3d = true, bool bLooping = false, bool bStream = false);
    void UnLoadSound(const std::string& strSoundName);
    void Set3dListener(const Vector3& Pos);
    int PlaySounds(const std::string& strSoundName, const Vector3& vPos = Vector3{ 0, 0, 0 }, float fVolumedB = 0.0f);
    void PlayEvent(const std::string& strEventName);
    void StopChannel(int nChannelId);
    void StopEvent(const std::string& strEventName, bool bImmediate = false);
    void GetEventParameter(const std::string& strEventName, const std::string& strEventParameter, float* parameter);
    void SetEventParameter(const std::string& strEventName, const std::string& strParameterName, float fValue);
    void StopAllChannels();
    void SetChannel3dPosition(int nChannelId, const Vector3& vPosition);
    void SetChannelVolume(int nChannelId, float fVolumedB);
    bool IsPlaying(int nChannelId) const;
    bool IsEventPlaying(const std::string& strEventName) const;
    float dbToVolume(float db);
    float VolumeTodB(float volume);
    void setVolume(float vol);
    FMOD_VECTOR VectorToFmod(const Vector3& vPosition);
    void saveEvent(SoundEvent* s, const std::string& strEventName);
    SoundEvent* getEvent(const std::string& strEventName);
    FMOD::Studio::EventInstance* getEventInstanceFromName(std::string eventName);
    void deleteEvent(SoundEvent * s, const std::string strEventName);
}; 
