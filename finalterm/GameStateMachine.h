#pragma once
#include "GameState.h"
#include <vector>

class GameStateMachine
{
public :
	GameState* m_currentState;
	GameState* m_prevState;
	void changeState(GameState* pState);
	void popState();
	void update();
	void render();
};