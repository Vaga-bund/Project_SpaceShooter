#pragma once
#include "GameState.h"

class GameObject;

class GameClearState : public GameState
{
private:
	static void s_exitFromGame();
	static const std::string s_GameClearState;

	GameClearState() {}
	static GameClearState* s_pInstance;

public:
	virtual bool onEnter();
	virtual std::string getStateID() const { return s_GameClearState; }

	static GameClearState* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new GameClearState();
		}
		return s_pInstance;
	}
};