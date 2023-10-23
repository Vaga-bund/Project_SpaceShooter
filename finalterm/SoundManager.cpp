#include "SoundManager.h"

SoundManager* SoundManager::s_pInstance = NULL;

bool SoundManager::loadMusic(std::string fileName)
{
    music = Mix_LoadMUS(fileName.c_str());
    if (music == nullptr)
    {
        return false;
    }

    return true;
}

void SoundManager::playMusic()
{
    if (music == nullptr)
    {
        return;
    }

    Mix_PlayMusic(music, -1);
}

void SoundManager::clean()
{
    Mix_FreeMusic(music);
    music = nullptr;
}
