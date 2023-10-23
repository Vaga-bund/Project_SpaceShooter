#include "GameClearState.h"
#include "AnimatedGraphic.h"
#include "MenuButton.h"
#include "Game.h"

GameClearState* GameClearState::s_pInstance = NULL;
const std::string GameClearState::s_GameClearState = "GameClear";

bool GameClearState::onEnter()
{
	if (!TheTextureManager::Instance()->load("assets/exit.png", "exitbutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/gameclear.png", "gameclear", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/clearbackground1.png", "background1", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/clearbackground2.png", "background2", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	GameObject* background1 = new SDLGameObject(new LoaderParams(0, 0, 640, 480, "background1"));
	GameObject* background2 = new SDLGameObject(new LoaderParams(0, 0, 640, 480, "background2"));
	GameObject* clearbanner = new AnimatedGraphic(new LoaderParams(188, 80, 264, 123, "gameclear"));
	GameObject* button1 = new MenuButton(new LoaderParams(120, 300, 400, 100, "exitbutton"), s_exitFromGame);

	m_gameObjects.push_back(background1);
	m_gameObjects.push_back(background2);
	m_gameObjects.push_back(clearbanner);
	m_gameObjects.push_back(button1);

	std::cout << "entering GameClearState\n";
	 
	return true;
}

void GameClearState::s_exitFromGame() 
{
	std::cout << "GameClear\n";

	TheGame::Instance()->quit();
}