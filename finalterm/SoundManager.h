#pragma once
#include <SDL_mixer.h>
#include <string>

class SoundManager
{
private :
	SoundManager() {}
	Mix_Music* music;
	static SoundManager* s_pInstance;
public :
	~SoundManager() {}
	static SoundManager* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new SoundManager();
		}
		return s_pInstance;
	}
	bool loadMusic(std::string fileName);
	void playMusic();
	void clean();
};