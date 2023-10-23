#pragma once
#include "GameState.h"
#include "SDLGameObject.h"
#include <fstream>
#include <string>
#define ROW 3
#define COL 9

class PlayState : public GameState
{
private:
	static const std::string s_playID;
	PlayState() {};
	static PlayState* s_pInstance;
public:
	static PlayState* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new PlayState();
		}
		return s_pInstance;
	}

	virtual std::string getStateID() const { return s_playID; }
	virtual bool onEnter();
	virtual void update();
	virtual bool onExit();

	void pushObject(GameObject* Object) { m_gameObjects.push_back(Object); }

	bool checkCollision(SDLGameObject* p1, SDLGameObject* p2);
};