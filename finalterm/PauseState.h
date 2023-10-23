#pragma once
#include "GameState.h"

class PauseState : public GameState
{
private:
	static void s_pauseToMain();
	static void s_resumePlay();
	static const std::string s_pauseID;

	PauseState() {};
	static PauseState* s_pInstance;
public:
	static PauseState* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new PauseState();
		}
		return s_pInstance;
	}
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_pauseID; }
};