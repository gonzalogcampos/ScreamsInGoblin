#include "SoundSystem.h"
#include "SoundEvent.h"
#include "SoundEngineData.h"
#include "CameraManager.h"
#include "GameObject.h"
#include "GameResource.h"
#include <iostream>

SoundEngineData::SoundEngineData() {
    mpStudioSystem = NULL;
    SoundSystem::ErrorCheck(FMOD::Studio::System::create(&mpStudioSystem));
    SoundSystem::ErrorCheck(mpStudioSystem->initialize(32, FMOD_STUDIO_INIT_LIVEUPDATE, FMOD_INIT_PROFILE_ENABLE, NULL));

    mpSystem = NULL;
    SoundSystem::ErrorCheck(mpStudioSystem->getLowLevelSystem(&mpSystem));
}

SoundEngineData::~SoundEngineData() {
    SoundSystem::ErrorCheck(mpStudioSystem->unloadAll());
    SoundSystem::ErrorCheck(mpStudioSystem->release());
}


void SoundEngineData::Update() {
    std::vector<ChannelMap::iterator> pStoppedChannels;
    for (auto it = mChannels.begin(), itEnd = mChannels.end(); it != itEnd; ++it)
    {
        bool bIsPlaying = false;
        it->second->isPlaying(&bIsPlaying);
        if (!bIsPlaying)
        {
             pStoppedChannels.push_back(it);
        }
    }
    for (auto& it : pStoppedChannels)
    {
         mChannels.erase(it);
    }
    SoundSystem::ErrorCheck(mpStudioSystem->update());
}


