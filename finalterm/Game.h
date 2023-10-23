#pragma once //컴파일러에게 해당 헤더 파일이 한번만 빌드되도록 한다.
#include "TextureManager.h"
#include "Player.h"
#include "Enemy.h"
#include "InputHandler.h"
#include "GameStateMachine.h"
#include <vector>

class GameStateMachine;

class Game
{
private:
	Game() {}
	static Game* s_pInstance;
	GameStateMachine* m_pGameStateMachine;

	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

	int m_currentFrame;

	std::vector<GameObject*> m_gameObjects;

	bool m_bRunning;
public:
	~Game() {}
	static Game* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new Game();
			return s_pInstance;
		}
		return s_pInstance;
	}
	SDL_Renderer* getRenderer() const { return m_pRenderer; }
	GameStateMachine* getStateMachine()
	{
		return m_pGameStateMachine;
	}

	bool init(const char* title, int xpos, int ypos, int height, int width, int flags);
	void render();
	void update();
	bool running() { return m_bRunning; }
	void handleEvents();
	void clean();
	void quit() { m_bRunning = false; }
};
typedef Game TheGame;